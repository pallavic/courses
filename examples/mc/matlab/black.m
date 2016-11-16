function black

disp(' ')

S = 1.0;
K = 1.0;
vol = 0.2;
T = 10;

n = 100000;
k = 10;

price = call(S,K,vol,T);
[mc_int_price mc_int_error] = mc_int_call(S,K,vol,T,n);
[mc_sim_price mc_sim_error] = mc_sim_call(S,K,vol,T,n,k);

disp('Call')
disp(['Analytical Price     = ' num2str(price)])
disp(['MC Integration Price = ' num2str(mc_int_price) ' +- ' num2str(mc_int_error) ' , CL = ' num2str(abs(mc_int_price-price)/mc_int_error)])
disp(['MC Simulation Price  = ' num2str(mc_sim_price) ' +- ' num2str(mc_sim_error) ' , CL = ' num2str(abs(mc_sim_price-price)/mc_sim_error)])

end

function price = call(S,K,vol,T)

std = sqrt(T)*vol;
d1 = log(S/K)/std + std/2;
d2 = d1 - std;
price = S .* normcdf(d1) - K * normcdf(d2);

end

function [price,error] = mc_int_call(S,K,vol,T,n)

u = unifrnd(0,1,n,1);
e = log(S) - vol^2*T/2;
s = sqrt(T)*vol;
sample = max(exp(norminv(u,e,s))-K,0);
price = mean(sample);
error = std(sample)/sqrt(n);

end

function [price,error] = mc_sim_call(S,K,vol,T,n,k)

z = normrnd(0,1,n,k);

dt = T/k;

logS = repmat(log(S),n,1);
logS = [logS, -vol^2/2*dt + z*vol*sqrt(dt)];
logS = cumsum(logS,2);

sample = max(exp(logS(:,end))-K,0);

price = mean(sample);
error = std(sample)/sqrt(n);

end
