clear
clc
buildVars = struct();
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
%    6. Flashing the binary onto the flight controller. 
% 
% Created by: Joseph Attias (josephattias@campus.technion.ac.il)
% Created on: Nov 9, 2023

%% The project files should reflect the project folder name 
buildVars.projectdir = pwd;
buildVars.projectdirslashes = regexp(buildVars.projectdir,"/","end");
buildVars.projectname = buildVars.projectdir(buildVars.projectdirslashes(end)+1:end);
fprintf("*** Custom controller name: "+buildVars.projectname+" ***\n")

%% Generate code with supporting files
SCHED_LOOP_RATE = 50; % https://ardupilot.org/dev/docs/copter-adding-custom-controller.html#preparing-your-simulink-model-for-code-generation 

run(buildVars.projectname+"_script")
try slbuild(buildVars.projectname+"_model")
catch 
    error("Code did not generate properly")
end

%% Archive the past library folder 
buildVars.currentDateTime = string(datetime("now","Format","MMM-dd-uuuu_HHmmss"));
% TODO Check to see if the code is any different. Something like a checksum
% hash comparison. 

try movefile("../../libraries/AC_Simulink","../libraries/AC_Simulink_"+buildVars.currentDateTime);
    fprintf("\n*** Past AC_Simulink archived at: "+ ... 
        buildVars.projectdir(buildVars.projectdirslashes(end-1)+1:buildVars.projectdirslashes(end))+ ... 
        "libraries/AC_Simulink_"+buildVars.currentDateTime+" ***\n")
catch 
    fprintf("\n*** AC_Simulink does not yet exsist. Skipping archive. ***\n")
end

%% Move files to library folder
unzip(buildVars.projectname+"_model.zip",buildVars.projectname+"_code")
copyfile(buildVars.projectname+"_code/"+buildVars.projectname+"/"+buildVars.projectname+"_model_ert_rtw","../../libraries/AC_Simulink/");
fprintf("*** Generated code is located here: "+ ...
    "../../libraries/AC_Simulink/" + buildVars.projectname +".h"+...
    " ***\n")

%% Modify code files with standard name 
% Read the content of the header file
buildVars.file_path = "../../libraries/AC_CustomControl/AC_CustomControl_Simulink.h";
buildVars.file_content = fileread(buildVars.file_path);

% Find the name of the old model to be replaced
buildVars.old_model_regexp = "\w*(?=_model\.h>)";
buildVars.existing_string_start = regexp(buildVars.file_content,buildVars.old_model_regexp,"start");
buildVars.existing_string_end   = regexp(buildVars.file_content,buildVars.old_model_regexp,"end");
buildVars.old_model_name = buildVars.file_content(buildVars.existing_string_start:buildVars.existing_string_end);

if ~strcmp(buildVars.old_model_name,buildVars.projectname)
    fprintf("\n*** New project name: cleaning build system. Expect longer build ***\n");
    system("../../waf clean");
end

buildVars.new_model_name = buildVars.projectname;

% Perform the replacement
buildVars.modified_content = strrep(buildVars.file_content, buildVars.old_model_name, buildVars.new_model_name);

% Write the modified content back to the file
buildVars.fid = fopen(buildVars.file_path, 'w');
fprintf(buildVars.fid, '%s', buildVars.modified_content);
fclose(buildVars.fid);


%% compile 
cd('../..');
fprintf("\n*** Configuring source code for flight controller ***\n")
system('./waf configure --board BETAFPV-F405');
fprintf("\n*** Building ArduCopter source code ***\n")
system('./waf copter -j8');

%% upload command
fprintf("\n*** Uploading to flight controller ***\n")
system('./waf copter --upload')

cd(buildVars.projectdir);
