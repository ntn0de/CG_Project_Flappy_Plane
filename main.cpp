#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<mmsystem.h>
#include<dos.h>

#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
using namespace std;
int splash()
{
    PlaySound(TEXT("splash.wav"),NULL,SND_ASYNC);
    int x = 150, y = 100,i=40,j=60;
        settextstyle(4, HORIZ_DIR, 3);
        outtextxy(x, y, "ORIGAMI PLANE");
        settextstyle(4, HORIZ_DIR, 3);
        outtextxy(x-100, y+250, "Press Any Key To Start Playing");
    line(50+i,110+j,500+i,200+j-50);
    line(50+i,110+j,100+i,150+j);
    line(100+i,150+j,100+i,155+j);
    line(100+i,150+j,500+i,200+j-50);
    line(100+i,155+j,500+i,200+j-50);
    line(100+i,155+j,40+i,220+j);
    line(40+i,220+j,500+i,200+j-50);
    line(100+i,210+j,100+i,240+j);
    line(100+i,240+j,500+i,200+j-50);
    setfillstyle(1,DARKGRAY);//grey color
    floodfill(320,205,WHITE);
    setfillstyle(1,7);//grey color
    floodfill(320,240,WHITE);
    setfillstyle(1,15);//grey color
    floodfill(320,250,WHITE);
    settextstyle(4, HORIZ_DIR, 4);
    while(!kbhit())
    {
    for(int a=0;a<=440;a++)
    {
        if(kbhit()==1)
            {   getch();
                return 0;
            }
        for(int b=0;b<=a;b++)
        {
        if(kbhit()==1)
            {   getch();
                return 0;
            }
        outtextxy(10,0+b,"*");
        outtextxy(600,440-b,"*");
            }
        outtextxy(10,0+a,"*");
        outtextxy(600,440-a,"*");
            }
    }
    getch();
    cleardevice();
    return 0;
}

int countdown()
{
    char a[10];
    for(int i=3;i>=0;i--)
        {
                if(kbhit())
                {
                return 0;
                }
                    delay(1000);
                    sprintf(a,"%d",i);
                    settextstyle(1, HORIZ_DIR, 3);
                    outtextxy(300,350,a);
                if(i==0)
                    exit(0);
        }
        return 0;
}

int fail()
{
    PlaySound(TEXT("fall.wav"),NULL,SND_ASYNC);
    int x = 1, y = getmaxy()/2, font=0;
    settextstyle(font, HORIZ_DIR, 3);
    outtextxy(x, y-10, "You crashed the Plane !!!!!");
    settextstyle(font, HORIZ_DIR, 2);
    outtextxy(x+100, y+20, "Press any key to restart");
    countdown();
    getch();
    return 0;
}

int main()
{

    int highscore=0,highscore2=0;
int gd=DETECT,gm,i=0,y=0,s=0,t=0,j=0,l=0,r=0,c=0,test1=100,test2=100,del=30;
initgraph(&gd,&gm,"C:\\tc\\bgi");
    splash();
    cleardevice();
    PlaySound(TEXT("Wind.wav"),NULL,SND_LOOP|SND_ASYNC);
    	cleardevice();
	for(y=0;y<=ScreenHeight;y=y+5)
{
	delay(del);
	cleardevice();
	setbkcolor(LIGHTBLUE);
	setcolor(WHITE);

        if(kbhit())
        {
            delay(del);
            for(c=12;c>0;c--)
            {

            int v=c;
            y=y-v;
            v=v/2;
            }
            getch();
            fflush (stdin);
        }
            line(40,46+y,40,60+y);//line1
            line(40,60+y,100,60+y);//line2
            line(40,40+y,100,60+y);//line3

            line(40,38+y,40,32+y);
            line(40,38+y,100,60+y);
            line(40,32+y,55,36+y);
            line(55,36+y,100,60+y);

            line(40,40+y,30,43+y);
            line(30,43+y,100,60+y);

            setfillstyle(1,7);//grey color
            floodfill(50,50+y,WHITE);
            setfillstyle(1,WHITE);
            floodfill(35,42+y,WHITE);
            floodfill(47,36+y,WHITE);

             setfillstyle(8,GREEN);
                         bar(0,460,ScreenWidth,470);//ground
             setfillstyle(1,GREEN);
                         bar(0,465,ScreenWidth,470);//ground


            setfillstyle(1,BROWN);

            bar(0,470,ScreenWidth,700);//ground bar
            s=600-i;//collision 1 ounter
            r=1000-l;//collision 2 counter
            t=60+y;//plane height
            bar(600-i,0,650-i,test1);                     //
            bar(600-i,test1+150,650-i,ScreenHeight);          //collosion 1
            i=i+9;
                                            //
            bar(1000-l,0,1050-l,test2);                     //
            bar(1000-l,test2+150,1050-l,ScreenHeight);             //collision 2
            l=l+9;

                                    if(s==60)
                                    {
                                j=j+1;
                                if(j%2==0)
                                del=del-2;
                                   }
                            char ch[50];
                            settextstyle(3, HORIZ_DIR, 2);
                            sprintf(ch,"score %d",j);
                             outtextxy(500,0,ch);
                                if(j>highscore)
                                    highscore++;
                             sprintf(ch,"Highscore %d",highscore);
                             outtextxy(100,0,ch);


                                             //
            if((s<=100 && s>=30) && ((t-10)<=(test1) || t>=(test1+149)||y<-30||y>=400))
                {
                                    if(highscore>highscore2)
                             {
                                    highscore2=highscore;
                                    settextstyle(3, HORIZ_DIR, 3);
                                    outtextxy(200,getmaxy()/2-50,"NEW HIGHSCORE !!!!");
                             }
                fail();

                i=0,y=0,s=0,t=0,j=0,l=0,r=0,c=0,test1=100,test2=100,del=30;
                    PlaySound(TEXT("Wind.wav"),NULL,SND_LOOP|SND_ASYNC);
                }
                if((r<=100 && r>=30) && ((t-10)<=(test2) || t>=(test2+149)))
                {
                    if(highscore>highscore2)
                             {
                                    highscore2=highscore;
                                    settextstyle(3, HORIZ_DIR, 3);
                                    outtextxy(200,getmaxy()/2-50,"NEW HIGHSCORE !!!!");
                             }
                 fail();
                i=0,y=0,s=0,t=0,j=0,l=0,r=0,c=0,test1=100,test2=100,del=30;
                    PlaySound(TEXT("Wind.wav"),NULL,SND_LOOP|SND_ASYNC);
                }
                if(s<(-400))
                {
                                i=0;
                                l=0;
                                j=j+1;
                                test1=rand() %250+ 50;
                                test2=rand() %250+ 50;
                                                                if(j%2==0)
                                del=del-2;
                }

  }


getch();
}


