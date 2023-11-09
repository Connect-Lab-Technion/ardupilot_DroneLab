clear
clc
fprintf("****** GENERATE | INTEGRATE | BUILDERATE ******\n\n")

% WELCOME! 
% The following script is designed to automate the process between
% designing a controller in simulink and flashing the flight controller.
% The high level processes include: 
%    1. Generating the controller code from the simulink model and
%       workspace variables. 
%    2. Automatically archiving past generated code.
%    3. Moving the generated code from the current directory to the source
%       code library.
%    4. Changing the name of the header file of the CustomControl_Simulink
%       wrapper to that of the generated code. 
%    5. Compiling the source code into a flashable binary. 
%    TODO 6. Flashing the binary onto the flight controller. 
% 
% Created by: Joseph Attias (josephattias@campus.technion.ac.il)
% Created on: Nov 9, 2023

%% The project files should reflect the project folder name 
projectdir = pwd;
projectdirslashes = regexp(projectdir,"/","end");
projectname = projectdir(projectdirslashes(end)+1:end);
fprintf("*** Custom controller name: "+projectname+" ***\n")

%% Generate code with supporting files
run(projectname+"_variables")
try slbuild(projectname+"_model")
catch error("Code did not generate properly")
end

%% Archive the past library folder 
currentDateTime = string(datetime("now","Format","MMM-dd-uuuu_HHmmss"));
% TODO Check to see if the code is any different. Something like a checksum hash comparison. 
% Or use the response string from code-generation: 
    % "0 of 1 models built (1 models already up to date)"

try movefile("../../libraries/AC_Simulink","../libraries/AC_Simulink_"+currentDateTime);
    fprintf("\n*** Past AC_Simulink archived at: "+ ... 
        projectdir(projectdirslashes(end-1)+1:projectdirslashes(end))+ ... 
        "libraries/AC_Simulink_"+currentDateTime+" ***\n")
catch 
    fprintf("\n*** AC_Simulink does not yet exsist. Skipping archive. ***\n")
end

%% Move files to library folder
unzip(projectname+"_model.zip",projectname+"_code")
copyfile(projectname+"_code/"+projectname+"/"+projectname+"_model_ert_rtw","../../libraries/AC_Simulink/");
fprintf("*** Generated code is located here: "+ ...
    "../../libraries/AC_Simulink/" + projectname +".h"+...
    " ***\n")

%% Modify code files with standard name 
% Read the content of the header file
file_path = "../../libraries/AC_CustomControl/AC_CustomControl_Simulink.h";
file_content = fileread(file_path);

% Find the name of the old model to be replaced
old_model_regexp = "\w*(?=_model\.h>)";
existing_string_start = regexp(file_content,old_model_regexp,"start");
existing_string_end   = regexp(file_content,old_model_regexp,"end");
old_model_name = file_content(existing_string_start:existing_string_end);

new_model_name = projectname;

% Perform the replacement
modified_content = strrep(file_content, old_model_name, new_model_name);

% Write the modified content back to the file
fid = fopen(file_path, 'w');
fprintf(fid, '%s', modified_content);
fclose(fid);


%% compile 
cd('../..');
fprintf("\n*** Configuring source code for flight controller ***\n")
system('./waf configure');
fprintf("\n*** Building ArduCopter source code ***\n")
system('./waf copter');
cd(projectdir);

%% upload command
% TODO 

