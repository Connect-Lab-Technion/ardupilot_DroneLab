Ts = 1/SCHED_LOOP_RATE;   % Flight Control System sample rate

F = tf([15^2], [1 2*sqrt(2)/2*15 15^2]);
F_discr = c2d(F, Ts);

s = tf('s');

KDz = 1.06*0.33;
zDz = 1/0.33;

% Controller (causal)
KDz = KDz*1.0;
zDz = zDz*1.0;
%Cz_causal = KDz*(s/((1/(zDz*20))*s + 1) + zDz);
%Cz_causal_discr = c2d(Cz_causal, Ts);
Cz_2DOF_causal = KDz*(s + zDz);
%Cz_2DOF_causal_discr = c2d(Cz_2DOF_causal, Ts);


KDtheta = 0.00065*2.86*0.76;
zDtheta = 1/0.76;

% Controller (causal)
KDtheta = KDtheta*1.4;
zDtheta = zDtheta*1.0;
Ctheta_causal = KDtheta*(s/((1/(zDtheta*40))*s + 1) + zDtheta)*(1+0.62*s)/s;
Ctheta_causal_discr = c2d(Ctheta_causal, Ts);
Ctheta_2DOF_causal = (KDtheta*1.4)*(s + (zDtheta*7));
%Ctheta_2DOF_causal_discr = c2d(Ctheta_causal, Ts);
Ctheta_2DOF_inegral_causal=(1+0.62*s)/s; 
Ctheta_2DOF_inegral_causal_discr=c2d(Ctheta_2DOF_inegral_causal, Ts);


KDphi = 0.00065*1.67*0.76;
zDphi = 1/0.76;

% Controller (causal)
KDphi = KDphi*1.0;
zDphi = zDphi*1.0;
Cphi_causal = KDphi*(s/((1/(zDphi*50))*s + 1) + zDphi)*(1+0.84*s)/s;
Cphi_causal_discr = c2d(Cphi_causal, Ts);
Cphi_2DOF_causal = (KDphi*1.4)*(s + (zDphi*7));
%Cphi_2DOF_causal_discr = c2d(Cphi_causal, Ts);
Cphi_2DOF_inegral_causal=(1+0.84*s)/s; 
Cphi_2DOF_inegral_causal_discr=c2d(Cphi_2DOF_inegral_causal, Ts);


KDpsi = 0.0013*0.44;
zDpsi = 1/0.44;

% Controller (causal)
KDpsi = KDpsi*1.0*0.8;
zDpsi = zDpsi*1.0*1.0;
Cpsi_causal = KDpsi*(s/((1/(zDpsi*20))*s + 1) + zDpsi);
Cpsi_causal_discr = c2d(Cpsi_causal, Ts);
Cpsi_2DOF_causal = (KDpsi*1.3)*(s + (zDpsi*2));
%Cpsi_2DOF_causal_discr = c2d(Cpsi_2DOF_causal, Ts);

% Estimators
PitchComplementaryFilter_disc;
RollComplementaryFilter_disc;
YawComplementaryFilter_disc;
