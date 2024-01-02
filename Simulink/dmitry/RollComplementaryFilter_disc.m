%% Roll Angle Complementary Filter

w_c_roll = 0.3; % [rad/s]
Filter_roll_estim_cont = tf([1], [1 w_c_roll]);
[num_roll_cont, den_roll_cont] = tfdata(Filter_roll_estim_cont, 'v');

Ts = 1/SCHED_LOOP_RATE;   % Flight Control System sample rate
Filter_roll_estim_disc = c2d(Filter_roll_estim_cont, Ts); % discretization with sample time Ts
[num_roll_disc, den_roll_disc] = tfdata(Filter_roll_estim_disc, 'v');
