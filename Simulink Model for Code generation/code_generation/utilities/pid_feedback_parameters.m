% Script that defines parameters for this project

%   Copyright 2012 The MathWorks, Inc.

%% Specify control system sample time
T_sample_control = 1e-3;

%% PID parameter setup 
% We would like the parameters of the PID controller to appear as a
% tunable structure in the generated code. To do this, we must first create
% a bus object - this configures the parameter typedef struct. Then we can
% create a parameter object which makes use of the bus object and defines
% default parameter values.

% Load bus object ready for parameter structure
pid_param_type;

% Create PID controller parameter object
pid = Simulink.Parameter;
pid.Value = Simulink.Bus.createMATLABStruct( 'pid_param' );
pid.Value.P = 2;
pid.Value.I = 22;
pid.Value.D = 0.05;
pid.Value.N = 1000;
pid.RTWInfo.StorageClass = 'SimulinkGlobal';
pid.DataType = 'Bus: pid_param';


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% MV, set some useful parameter for the plant
b =3.5066e-06;


J = 3.2284e-06;


K = 0.0274;


L = 2.7500e-06;


R = 4;
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
