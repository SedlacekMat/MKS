clear all
close all

%% input
tempData = csvread("ntc.csv");
res = tempData(:,2);
temp = tempData(:,1);

for i=1:length(res)
adc(i) = res(i)*1e3/(res(i)*1e3+1e4)*2^10;
end

plot(adc,temp,'o')

%% polynom

polyboi = polyfit(adc,temp,10);
adcPoly = 0:1023;
tempPoly = round(polyval(polyboi,adcPoly), 1);

hold on 
plot(adcPoly, tempPoly, 'r')

%% output

dlmwrite('data.dlm',tempPoly*10,',');