#include <iostream.h>
#include <conio.h>
#include <graphics.h>
int xl,yl,xh,yh,poly[100],n;
void left_clip(){
int temp[100],i,j=0,count=0,x1,y1,x2,y2;
for(i=0;i<2*n;i+=2){
x1 = poly[i];
y1 = poly[i+1];
x2 = poly[i+2];
y2 = poly[i+3];
if(x1<xl && x2<xl){
//both points outside. Do not store any vertices
}else if(x1>xl && x2>xl){
//both points inside. Store second vertex
temp[j] = x2;
temp[j+1] = y2;
j+=2;
count++;
}else if(x1<xl && x2>xl){
//outside to inside. Store intersection n second vertex
int x=xl;
int y= y1 + (xl-x1)*(float)(y2-y1)/(x2-x1);
temp[j]=x;
temp[j+1]=y;
temp[j+2]=x2;
temp[j+3]=y2;
j+=4;
count+=2;
}else{
//inside to outside. Store intersection only
int x=xl;
int y= y1 + (xl-x1)*(float)(y2-y1)/(x2-x1);
temp[j] = x;
temp[j+1] = y;
j+=2;
count++;
}
}
n=count;
//store 1st vertex as last
temp[j]=temp[0];
temp[j+1]=temp[1];

for(i=0;i<2*(n+1);i++)
poly[i]=temp[i];
}
void right_clip(){
int temp[100],i,j=0,count=0,x1,y1,x2,y2;
for(i=0;i<2*n;i+=2){
x1 = poly[i];
y1 = poly[i+1];
x2 = poly[i+2];
y2 = poly[i+3];
if(x1>xh && x2>xh){
//both points outside. Do not store any vertices
}else if(x1<xh && x2<xh){
//both points inside. Store second vertex
temp[j] = x2;
temp[j+1] = y2;
j+=2;
count++;
}else if(x1>xh && x2<xh){
//outside to inside. Store intersection n second vertex
int x=xh;
int y= y1 + (xh-x1)*(float)(y2-y1)/(x2-x1);
temp[j]=x;
temp[j+1]=y;
temp[j+2]=x2;
temp[j+3]=y2;
j+=4;
count+=2;
}else{
//inside to outside. Store intersection only
int x=xh;
int y= y1 + (xh-x1)*(float)(y2-y1)/(x2-x1);
temp[j] = x;
temp[j+1] = y;
j+=2;
count++;
}
}
n=count;
//store 1st vertex as last
temp[j]=temp[0];
temp[j+1]=temp[1];

for(i=0;i<2*(n+1);i++)
poly[i]=temp[i];
}
void bottom_clip(){
int temp[100],i,j=0,count=0,x1,y1,x2,y2;
for(i=0;i<2*n;i+=2){
x1 = poly[i];
y1 = poly[i+1];
x2 = poly[i+2];
y2 = poly[i+3];
if(y1>yl && y2>yl){
//both points outside. Do not store any vertices
}else if(y1<yl && y2<yl){
//both points inside. Store second vertex
temp[j] = x2;
temp[j+1] = y2;
j+=2;
count++;
}else if(y1>yl && y2<yl){
//outside to inside. Store intersection n second vertex
int x= x1 + (yl-y1)/((float)(y2-y1)/(x2-x1));
int y= yl;
temp[j]=x;
temp[j+1]=y;
temp[j+2]=x2;
temp[j+3]=y2;
j+=4;
count+=2;
}else{
//inside to outside. Store intersection only
int x= x1 + (yl-y1)/((float)(y2-y1)/(x2-x1));
int y= yl;
temp[j] = x;
temp[j+1] = y;
j+=2;
count++;
}
}
n=count;
//store 1st vertex as last
temp[j]=temp[0];
temp[j+1]=temp[1];

for(i=0;i<2*(n+1);i++)
poly[i]=temp[i];
}
void top_clip(){
int temp[100],i,j=0,count=0,x1,y1,x2,y2;
for(i=0;i<2*n;i+=2){
x1 = poly[i];
y1 = poly[i+1];
x2 = poly[i+2];
y2 = poly[i+3];
if(y1<yh && y2<yh){
//both points outside. Do not store any vertices
}else if(y1>yh && y2>yh){
//both points inside. Store second vertex
temp[j] = x2;
temp[j+1] = y2;
j+=2;
count++;
}else if(y1<yh && y2>yh){
//outside to inside. Store intersection n second vertex
int x= x1 + (yh-y1)/((float)(y2-y1)/(x2-x1));
int y= yh;
temp[j]=x;
temp[j+1]=y;
temp[j+2]=x2;
temp[j+3]=y2;
j+=4;
count+=2;
}else{
//inside to outside. Store intersection only
int x= x1 + (yh-y1)/((float)(y2-y1)/(x2-x1));
int y= yh;
temp[j] = x;
temp[j+1] = y;
j+=2;
count++;
}
}
n=count;
//store 1st vertex as last
temp[j]=temp[0];
temp[j+1]=temp[1];

for(i=0;i<2*(n+1);i++)
poly[i]=temp[i];
}
void main(){
int gdriver = DETECT,gmode;
initgraph(&gdriver,&gmode,”C:\TC\BGI”);
int i;
setcolor(BLUE);
cout<<“Enter bottom left and top right co-ordinates of window: “;
cin>>xl>>yl>>xh>>yh;
rectangle(xl,yl,xh,yh);
cout<<“Enter the no. of vertices: “;
cin>>n;
for(i=0;i<2*n;i+=2){
cout<<“Enter co-ordinates of vertex “<<(i/2+1)<<“: “;
cin>>poly[i]>>poly[i+1];
}
//store 1st vertex as last
poly[2*n] = poly[0];
poly[2*n+1] = poly[1];
drawpoly(n+1,poly);
getch();

left_clip();
right_clip();
bottom_clip();
top_clip();
cout<<“After clipping:”;
setcolor(WHITE);
drawpoly(n+1,poly);

getch();
closegraph();
}
