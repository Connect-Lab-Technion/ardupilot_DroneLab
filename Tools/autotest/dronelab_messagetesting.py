import time                     # Import time module to add delays
from pymavlink import mavutil   # Import mavutil from pymavlink to access the MAVLink protocol  
import sys                      # Import sys module to access command line arguments
import scipy.io                 # Import scipy.io to save the message as a .mat file
import datetime                 # Import datetime to get the current date and time
from pymavlink.dialects.v20 import droneLab as mavlink2 # Import the custom dialect

class DroneLabMessageTesting:
    def __init__(self):
        # Create a MAVLink connection to the autopilot. Make sure the custom dialect is used.
        self.master = mavutil.mavlink_connection('/dev/serial/by-id/usb-ArduPilot_BETAFPV-F405_33004E001750315154353020-if00', dialect='droneLab')
        self.current_mode = 0

        # Create a .mat file to save the received message
        current_datetime = datetime.datetime.now()
        current_datetime_str = current_datetime.strftime("%Y-%m-%d_%H-%M-%S")
        self.matfile = 'lab_to_dashboard_message_' + current_datetime_str + '.mat'

        # Variables to track autopilot states
        self.autopilot_alive_flag = False
        self.lab_mode_active_flag = False
        self.buttom_pressed_flag = False

        # Timers 
        self.time_last_hearbeat = 0
        self.time_last_lab_to_dashboard = 0

        # Register the callback for incoming lab messages    
        self.master.mav.set_callback(self.handle_message)


    # Function to handle incoming MAVLink messages
    def handle_message(self, msg):
        
        msg_type = msg.get_type()

        if msg_type == 'HEARTBEAT': 
            self.time_last_hearbeat = time.time()
            self.autopilot_alive_flag = True

            self.current_mode = msg.custom_mode
            if self.current_mode == 99:
                self.lab_mode_active_flag = True
            else:
                self.lab_mode_active_flag = False

        elif msg_type == 'LAB_TO_DASHBOARD': 
            self.time_last_lab_to_dashboard = time.time()
            
            # Save the message as a .mat matlab workspace file 
            scipy.io.savemat(self.matfile , {'msg': msg})   
            print("Received:", msg)


    # Function to run the main loop
    def run(self):
        print("Running...")
        while True:
            try: 
                # Wait for a message to be received
                msg = self.master.recv_msg()

                # Record the time when the message is received 
                current_time = time.time()

                # Check if the autopilot is alive
                if abs(current_time - self.time_last_hearbeat) > 5:
                    self.autopilot_alive_flag = False

                # Check if the lab mode is active
                if abs(current_time - self.time_last_lab_to_dashboard) > 5:
                    self.lab_mode_active_flag = False

                # If the autopilot is ready and not in lab mode, send a mode change command
                if self.autopilot_alive_flag:
                    if not self.lab_mode_active_flag:
                        self.master.mav.command_long_send(
                            self.master.target_system, self.master.target_component,
                            mavutil.mavlink.MAV_CMD_DO_SET_MODE, 0,
                            mavutil.mavlink.MAV_MODE_FLAG_CUSTOM_MODE_ENABLED, 99, 0, 0, 0, 0, 0)
                        print("Mode change command sent.")
                        time.sleep(0.1) # An extra delay to avoid sending the command too frequently
                else:
                    continue # Skip the rest of the loop
                
                # Send a LAB_FROM_DASHBOARD message to the autopilot
                ref_x = 1
                ref_y = 2
                ref_z = 3
                ref_yaw = 4
                ref_pitch = 5
                ref_roll = 6
                power = 7

                if self.lab_mode_active_flag:
                    self.master.mav.lab_from_dashboard_send(ref_x, ref_y, ref_z, ref_yaw, ref_pitch, ref_roll, power)

                time.sleep(0.001)  # Adjust sleep duration as needed
                
            except KeyboardInterrupt:
                print("Exiting...")
                break

if __name__ == "__main__":
    # Create an instance of the DroneLabMessageTesting class and run it
    drone_lab = DroneLabMessageTesting()
    drone_lab.run()
