%% Yaw Angle Complementary Filter

w_c_yaw = 55; % [rad/s]
Filter_yaw_estim_cont = tf([1], [1 w_c_yaw]);
[num_yaw_cont, den_yaw_cont] = tfdata(Filter_yaw_estim_cont, 'v');

Ts = 1/SCHED_LOOP_RATE;   % Flight Control System sample rate
Filter_yaw_estim_disc = c2d(Filter_yaw_estim_cont, Ts); % discretization with sample time Ts
[num_yaw_disc, den_yaw_disc] = tfdata(Filter_yaw_estim_disc, 'v');
