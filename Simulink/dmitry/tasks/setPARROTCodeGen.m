function setPARROTCodeGen()
% SETPARROTCODEGEN This function sets the appropriate settings
% for code generation for the controller. This is a private function, not
% meant to be used directly.

% Copyright 2017-2018 The MathWorks, Inc.

% Check that the support package is installed
if isParrotSupportPkgInstalled
    % Check if the flight control system model and its children are open
    modelList = {'flightControlSystem','flightController','stateEstimator',...
        'conversionYUV'};
    
    for k = 1:length(modelList)
        % check if model is open/loaded
        isFCSLoaded = bdIsLoaded(modelList{k});
        if ~isFCSLoaded
            % if not load model
            load_system(modelList{k});
        end
        % check if model is dirty
        isDirty = bdIsDirty(modelList{k});

        % Set the hardware target toolchain
        switch evalin('base','model')
            case 'Mambo'
                set_param(modelList{k},'HardwareBoard','PARROT Mambo',...
                        'MatFileLogging','on');
            case 'RollingSpider'
                set_param(modelList{k},'HardwareBoard','PARROT Rolling Spider',...
                        'MatFileLogging','on');
        end
        
        % Set image processing settings - It only applies to the
        % flightControlSystem model
        if k==1
            set_param([modelList{k} '/Image Processing System'],'InitFcn',...
                'codertarget.parrot.internal.ipSubsystemCallback(gcb);');
            set_param([modelList{k} '/Image Data'],'InitFcn',...
                'codertarget.parrot.internal.inportCallback(gcb);');
            lines = find_system(modelList{k},'SearchDepth','1','findall','on','Type','Line','Name','Y1UY2V');
            lineStruct = get(lines);
            set(lineStruct.Handle, 'StorageClass', 'ImportedExternPointer');
            line = get(lineStruct.Handle);
            line.CoderInfo.Alias = 'imRGB';
        end

        % Only save if model is not dirty prior to updates in functions
        if ~isDirty
           save_system(modelList{k});
        end
        
        % Only close if model is not opened
        if ~isFCSLoaded
            bdclose(modelList{k});
        end
    end 
    
    % Bus definitions dependent on target choice
    asbBusDefinitionCommand(1); 
    asbBusDefinitionSensors(1);
    
else
    warning(message('aeroblks_demos_quad:asbquadcopter:supportPkgNotInstalled'));
end
