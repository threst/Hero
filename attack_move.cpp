#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<iostream>
#define width 640//画布宽
#define height 480//画布
using namespace std;

IMAGE bg,Rhero[8],Rheroym[8],Lhero[8],Lheroym[8];
IMAGE attack_1[8],attackym_1[8];//攻击1
IMAGE attack_2[13],attack_2[13];//攻击2


void init()
{
		/************初始化************/
		initgraph(width,height);
		char Rbuff[512],Rbuffym[512];//定义存右边移动的图片
		char Lbuff[512],Lbuffym[512];//定义存左边移动的图片
		char attack_1_buff[512],attack_1_buffym[512];//定义存attck1的图片名的数组
		char attack_2_buff[512],attack_2_buffym[512];//定义存attack2的图片名的数组
		int i=0;

		//加载背景
		loadimage(&bg,_T("bg\\bg_3.jpg"),width,height,true);



		/*******************初始化walk**************/
		//加载图片
		for(i=0;i<=6;i++)
		{
			memset(Rbuff,0,512);
			memset(Lbuff,0,512);
			//朝右
			sprintf(Rbuff,_T("walk\\IMG0000%d.bmp"),i);
			loadimage(&Rhero[i],Rbuff,0,0,true);
			//朝左
			sprintf(Lbuff,_T("walk\\%d.bmp"),i);
			loadimage(&Lhero[i],Lbuff,0,0,true);


		}
		//加载掩码图
		for(i=0;i<=6;i++)
		{
			memset(Rbuffym,0,512);
			memset(Lbuffym,0,512);
			sprintf(Rbuffym,_T("walk\\IMG0000%d_ym.bmp"),i);
			loadimage(&Rheroym[i],Rbuffym,0,0,true);
			sprintf(Lbuffym,_T("walk\\%d_ym.bmp"),i);
			loadimage(&Lheroym[i],Lbuffym,0,0,true);
		}


		/**************************攻击attack初始化*****************/
		//加载图片

		/*********attack1******/
		for(i=0;i<=6;i++)
		{
			memset(attack_1_buff,0,512);
			sprintf(attack_1_buff,_T("attack1\\IMG0000%d.bmp"),i);
			loadimage(&attack[i],attack_1_buff,0,0,true);
		}

		//加载掩码图
		for(i=0;i<=6;i++)
		{
			memset(attack_buffym,0,512);
			sprintf(attack_buffym,_T("attack1\\IMG0000%d_ym.bmp"),i);
			loadimage(&attackym[i],attack_buffym,0,0,true);
		}
		
		/*************attack2***************/
		for(i=0;i<=13;i++)
		{
			memset(attack1_buff,0,512);
			sprintf(attack1_buff,_T("attack2\\IMG0000%d.bmp"),i);
			loadimage(&attack[i],attack1_buff,0,0,true);
		}
		//加载掩码图
		for(i=0;i<=13;i++)
		{
			memset(attack_buffym,0,512);
			sprintf(attack_buffym,_T("attack2\\IMG0000%d_ym.bmp"),i);
			loadimage(&attackym[i],attack_buffym,0,0,true);
		}
}

























void show()
{
		int x=200,y=300;//初始化位置
		int count=0;
		char ch;
		int dire;//朝向判断
		while(ch != 27)
		{
			ch = getch();
			switch(ch)
			{
			case 'a'://左移
				for(count=0;count<=6;count++)
				{
					putimage(0,0,&bg);
					putimage(x,y,&Lheroym[count],SRCAND);
					putimage(x,y,&Lhero[count],SRCPAINT);
					x-=10;
					Sleep(10);
					dire=0;//0为左移
				}
				break;
			case 'd'://右移
				for(count=0;count<=6;count++)
				{
					putimage(0,0,&bg);
					putimage(x,y,&Rheroym[count],SRCAND);
					putimage(x,y,&Rhero[count],SRCPAINT);
					x+=10;
					Sleep(10);
					dire=1;//1为右移
				}
				break;
			case 'w'://上移
				for(count=0;count<=6;count++)
				{	
					putimage(0,0,&bg);
					if(dire==0)
					{
						putimage(x,y,&Lheroym[count],SRCAND);
						putimage(x,y,&Lhero[count],SRCPAINT);
					}
					else
					{
						putimage(x,y,&Rheroym[count],SRCAND);
						putimage(x,y,&Rhero[count],SRCPAINT);
					}
					y-=10;
					Sleep(10);
				}
				break;
			case 's'://下移
				for(count=0;count<=6;count++)
				{	
					putimage(0,0,&bg);
					if(dire==0)
					{
						putimage(x,y,&Lheroym[count],SRCAND);
						putimage(x,y,&Lhero[count],SRCPAINT);
					}
					else
					{
						putimage(x,y,&Rheroym[count],SRCAND);
						putimage(x,y,&Rhero[count],SRCPAINT);
					}
					y+=10;
					Sleep(10);
				}
				break;
			case 'j'://攻击
				for(count=0;count<=13;count++)
				{
						putimage(0,0,&bg);
						putimage(x,y,&attackym[count],SRCAND);
						putimage(x,y,&attack[count],SRCPAINT);
						x-=10;
						Sleep(10);
				}
				break;

			}
		};
}









int main()
{			

	init();
	show();
	return 0;
}