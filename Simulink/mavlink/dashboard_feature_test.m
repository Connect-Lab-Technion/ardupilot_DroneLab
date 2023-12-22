%% 
clear
clc
fprintf("****** Mavlink testing ground ******\n\n")

% WELCOME! 
% The following script is used to test integration features for the
% simulink dashboard. Fearures extracted from here: 
%     https://www.mathworks.com/help/releases/R2022b/uav/mavlink-support.html

%% mavlinkio
% https://www.mathworks.com/help/releases/R2022b/uav/ref/mavlinkio.html
mavlink = mavlinkio("common.xml"); 
connect(mavlink,"UDP");
client = mavlinkclient(mavlink,1,1)
listClients(mavlink)
listConnections(mavlink)
listTopics(mavlink) 



