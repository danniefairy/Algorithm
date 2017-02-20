position=[-330 -430 -410];%百公里
v=[150  170 50];%百公里/小時(200~400)
t=0.01;
while (((position(1)~=0) || (position(2)~=0)|| (position(3)~=0))&&(position(1)<=500) && (position(2)<=500) && (position(3)<=500))%(position(1)~=0) || (position(2)~=0)
    r=sqrt(position(1).^2+position(2).^2+position(3).^2);
    if r<=1
        break;
    end
    a=40000/r/r;
    ax=a*(0-position(1))/r;
    ay=a*(0-position(2))/r; 
    az=a*(0-position(3))/r; 
    vx=v(1)+ax*t*1000;
    vy=v(2)+ay*t*1000;
    vz=v(3)+az*t*1000;
    v(1)=vx;
    v(2)=vy;
    v(3)=vz;
    position(1)=position(1)+vx*t;
    position(2)=position(2)+vy*t;
    position(3)=position(3)+vz*t;
    plot3( position(1), position(2), position(3),'o')
    plot3(0,0,0,'xr')
    plot3(500,500,500,'x',-500,500,500,'x',500,-500,500,'x',500,500,-500,'x')
    plot3(-500,-500,500,'x',-500,500,-500,'x',500,-500,-500,'x',-500,-500,-500,'x')
    hold on;
    grid on;
    rotate3d on;
    pause(0.00001);

end