function circle4(x,y,room)
px=1.1/720;
x=x/px;
y=y/px;
room=room/px;
%d=0.34;
d=0.35/px;
r = d/2;
px = x-r;
py = y-r;
plot(x,y,'g+', 'MarkerSize', 20)
rectangle('Position',[px py d d],'Curvature',[1,1],'LineWidth',2,'edgecolor','g');
rectangle('Position',[0 0 room(1) room(2)])
daspect([1,1,1])
xlim([-0.1 room(1)+0.1]);
ylim([-0.1 room(2)+0.1]);
end



