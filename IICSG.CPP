#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
char gameover;
const int width=60;
const int height=14;
int x,y;
int fruitx,fruity;
int score,tailx[100],taily[100];
int ntail=0;
enum edirection{stop=0,left,right,up,down};
edirection dir;
void setting()
{
  gameover=0;
  dir=stop;
  x=width/2;
  y=height/2;
  fruitx=rand()%height;
  fruity=rand()%width;
  score=0;
}
void design()
{
  clrscr();
  for(int i=0;i<width+2;i++)
  cout<<"#";
  cout<<endl;
  for(int p=0;p<height;p++)
  {
    for(int j=0;j<width;j++)
     {
       if(j==0)
       cout<<"#";
       if(p==y&&j==x)
	 cout<<"O";
       else if(p==fruity&&j==fruitx)
	 cout<<"@";
       else
       {
	  char print=0;
	  for(int k=0;k<ntail;k++)
	 {
	   if(tailx[k]==j&&taily[k]==p)
	     {
	       cout<<"o";
	       print=1;
	     }
	 }
	 if(!print)
	 cout<<" ";
     }
      if(j==width-1)
       cout<<"#";
     }
     cout<<endl;
  }
  for(int m=0;m<width+2;m++)
   cout<<"#";
  cout<<endl;
  cout<<"score:"<<score<<endl;
}
void input()
{
  while(kbhit())
  {
    switch(getch())
    {
      case'a':
      dir=left;
      break;
      case'd':
      dir=right;
      break;
      case'w':
      dir=up;
      break;
      case's':
      dir=down;
      break;
      case'x':
      gameover=1;
      break;
    }
  }
}
void logic()
{
  int prevx=tailx[0];
  int prevy=taily[0];
  int prev2x,prev2y;
  tailx[0]=x;
  taily[0]=y;
  for(int i=1;i<ntail;i++)
  {
   prev2x=tailx[i];
   prev2y=taily[1];
   tailx[i]=prevx;
   taily[i]=prevy;
   prevx=prev2x;
   prevy=prev2y;
  }
 switch(dir)
 {
   case left:
   x--;
   break;
   case right:
   x++;
   break;
   case up:
   y--;
   break;
   case down:
   y++;
   break;
   default:break;
 }
if(x>=width)
x=0;
else if(x<0)
x=width-1;
if(y>=height)
y=0;
else if(y<0)
y=height-1;
for(int l=0;l<ntail;l++)
if(tailx[l]==x&&taily[l]==y)
gameover=1;
if(x==fruitx&&y==fruity)
 {
   score+=10;
   fruitx=rand()%width;
   fruity=rand()%height;
   cout<<"o";
   ntail++;
 }
}
void main()
{
  char start='o';
  int s;
  clrscr();
  cout<<"instruction \n for left a \n for right d \n for up w \n for down s to start o ";
  cin>>start;
  if(start=='o')
  {
    clrscr();
    setting();
    design();
    while(!gameover)
    {
       design();
       input();
       logic();
       delay(150);
     }
  }
  cout<<"gameover!";
  cout<<"score:"<<score;

  getch();
}
