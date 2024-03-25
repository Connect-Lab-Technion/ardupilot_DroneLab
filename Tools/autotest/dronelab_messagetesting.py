import time                     # Import time module to add delays
from pymavlink import mavutil   # Import mavutil from pymavlink to access the MAVLink protocol  
import sys                      # Import sys module to access command line arguments
import scipy.io                 # Import scipy.io to save the message as a .mat file

from pymavlink.dialects.v20 import droneLab as mavlink2 # Import the custom dialect

## Abstract
# This script is used to test the communication between the autopilot and the dashboard.
# It sends a LAB_FROM_DASHBOARD message to the autopilot and saves the received LAB_TO_DASHBOARD message as a .mat file.
# The script also monitors the autopilot's readiness and switches the autopilot to custom mode 99 if it is not already in that mode.
# The script is intended to be run on the autopilot's companion computer.

# Create a MAVLink connection to the autopilot. Make sure the custom dialect is used.
master = mavutil.mavlink_connection('/dev/serial/by-id/usb-ArduPilot_BETAFPV-F405_33004E001750315154353020-if00', dialect='droneLab')

# Function to handle incoming MAVLink messages
def handle_lab_to_dashboard_message(msg):
    if msg.get_msgId() == 9902:  # Check if the message ID is 9902 (LAB_TO_DASHBOARD)
        # Save the message as a .mat matlab workspace file 
        scipy.io.savemat('lab_to_dashboard_message.mat', {'msg': msg})   
        print("Received:", msg)

# Register the callback for incoming lab messages    
master.mav.set_callback(handle_lab_to_dashboard_message)


# Variables to track autopilot states
autopilot_ready_flag = False
lab_mode_active_flag = False
buttom_pressed_flag = False


# Main loop
while True:
    try:
        # Wait for a message to be received
        msg = master.recv_msg()

        # Check if the received message is a HEARTBEAT message - aka the autopilot is ready.
        # also check if the autopilot is in custom mode 99 - aka the lab mode
        if msg is not None and msg.get_type() == 'HEARTBEAT':
            # Autopilot is ready
            autopilot_ready_flag = True
            print("Drone is ready.")

            # Check if the autopilot is in custom mode 99
            if not lab_mode_active_flag and msg.custom_mode == 99:
                print("Autopilot is in custom mode.")
                lab_mode_active_flag = True

        # Continuously send mode change command only if the autopilot is ready and not in custom mode 99
        if autopilot_ready_flag and not lab_mode_active_flag:
            master.mav.command_long_send(
                master.target_system, master.target_component,
                mavutil.mavlink.MAV_CMD_DO_SET_MODE, 0,
                mavutil.mavlink.MAV_MODE_FLAG_CUSTOM_MODE_ENABLED, 99, 0, 0, 0, 0, 0)
            print("Mode change command sent.")
            time.sleep(0.1) # An extra delay to avoid sending the command too frequently


        # Send a LAB_FROM_DASHBOARD message to the autopilot
        ref_x = 1
        ref_y = 2
        ref_z = 3
        ref_yaw = 4
        ref_pitch = 5
        ref_roll = 6
        power = 7

        if lab_mode_active_flag:
            master.mav.lab_from_dashboard_send(ref_x, ref_y, ref_z, ref_yaw, ref_pitch, ref_roll, power)
        

        time.sleep(0.001)  # Adjust sleep duration as needed
    except KeyboardInterrupt:
        print("Exiting...")
        break