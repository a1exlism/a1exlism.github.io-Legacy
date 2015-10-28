内容:正弦波 三角波 脉冲 方波


% 正弦波 sin
fs = 2400;	%采样频率
N = 1000;
n = 0:N-1;
t = n/fs;
f1 = 50;	%频率
xn = sin(2 * pi * f1 *t);
figure(1)	%控制图像
plot(t,xn);

%% 三角波 tri 
fs = 10000;
t = -1:1/fs:1;
w = 0.4;
x = tripuls(t,w);
plot(t,x);