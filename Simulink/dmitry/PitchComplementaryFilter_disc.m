%% Pitch Angle Complementary Filter

w_c_pitch = 0.3; % [rad/s]
Filter_pitch_estim_cont = tf([1], [1 w_c_pitch]);
[num_pitch_cont, den_pitch_cont] = tfdata(Filter_pitch_estim_cont, 'v');

Ts = 1/SCHED_LOOP_RATE;   % Flight Control System sample rate
Filter_pitch_estim_disc = c2d(Filter_pitch_estim_cont, Ts); % discretization with sample time Ts
[num_pitch_disc, den_pitch_disc] = tfdata(Filter_pitch_estim_disc, 'v');
