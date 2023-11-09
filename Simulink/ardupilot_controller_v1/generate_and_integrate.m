clear

%% The project files should reflect the project folder name 
projectdir = pwd;
projectdirslashes = regexp(projectdir,"/","end");
projectname = projectdir(projectdirslashes(end)+1:end);

%% Generate code with supporting files
run(projectname+"_variables")
try slbuild(projectname+"_model")
catch error("Code did not generate properly")
end

%% Archive the past library folder 
currentDateTime = string(datetime("now","Format","MMM-dd-uuuu_HHmmss"));

try movefile("../../libraries/AC_Simulink","../libraries/AC_Simulink_"+currentDateTime);
    fprintf("Past AC_Simulink archived at: "+ ... 
        projectdir(projectdirslashes(end-1)+1:projectdirslashes(end))+ ... 
        "libraries/AC_Simulink_"+currentDateTime+"\n")
catch 
    fprintf("AC_Simulink does not yet exsist. Skipping archive.\n")
end

%% Unzip the code package and move files to library folder
unzip(projectname+"_model.zip",projectname+"_code")
copyfile(projectname+"_code/"+projectname+"/"+projectname+"_model_ert_rtw","../../libraries/AC_Simulink/");

%% Modify code files with standard name 
% TODO
