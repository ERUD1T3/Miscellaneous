%Electric potential
pi = 3.14;
Eo = 8.854*10^(-12);
k = 1/(4*pi*Eo); %coefficient of the electric potential
q1 = 6*10^(-10);
q2 = 8*10^(-10);
q3 = -4*10^(-10);

d = -.25:.01:.25; %change the sample size to see a wider field
%y = -.25:.05:.25
[x,y] = meshgrid(d);

%radial distances
r1 = sqrt((.1-x).^2 + (.3-y).^2);
r2 = sqrt((-.3-x).^2 + (-y).^2);
r3 = sqrt((-x).^2 + (-.3-y).^2);
%expression of electric potential
V = k.*((q1./r1) + (q2./r2) + (q3./r3));
%V2 = k*((q1./r1) + (q2./r2) + (q3./r3))

%plot of electric potential
%plot(V);
surf(x,y,V);
xlabel('radial distance'), ylabel('Electric potential'), legend('V(r(x,y))');
colormap(jet) %to set the color of the graph red-blue
%axis([-.25 .25 -.25 .25]);


