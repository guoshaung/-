#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
struct air_set //座位信息（用飞机型号算
{
	int set_1;//1级座位数量，下同 
	int price_1;//1级座位价格，下同 
	int set_2;
	int price_2;
	int set_3; 
	int price_3;
};
struct air_set_inf//座位使用信息 
{
	int set1;//1级座位使用数量 
	int set2;
	int set3;
};
struct air_inf //记录飞机型号用来计算座位和票价  
{
	char air_mod[3];//飞机型号 
	struct air_set set;//座位信息（用飞机型号算  
	struct air_set_inf setinf;//座位使用信息 
};
struct off_land_pla //起降地点 
{
	char off_air[10];//起飞机场 
	char land_air[10];//降落机场 
	char off_dep[10];//起飞城市 
	char land_dep[10];//降落城市 
};
struct air_time//航班时间 
{
	int off_day;//起飞日 
	int off_time;//起飞时间 
	int fly_time;//飞行时间 
};
struct user_inf//订票用户的信息 
{
	int name;//用户名字 
	int num;//订票数量 
	int set;//几级座位 
	struct user_inf *next;
};
struct wait_inf//候补用户的信息 
{
	int name;//用户名字 
	int num;//订票数量 
	int set;//几级座位 
	struct user_inf *next;
};

struct fl_inf //航班信息 
{
	char fli_num[6];//航班号（限制6位 
	struct air_inf ainf;//飞机信息 
	struct off_land_pla pla;//起降地点 
	struct air_time time;//航班时间信息 
	struct user_inf uinf;//订票用户的信息
	struct wait_inf winf;//候补用户的信息
	struct fl_inf *next;
};

//void FlaiNumSeach(struct fl_inf *p,char *ch)//航班号查询 (应当可以直接转到订票 
//{
//	struct fl_inf *i;
//	for(i=p->next;strcmp(i->fli_num,ch)!=0&&i;i=i->next);
//	if(i)
//	{
//		printf("航班%s信息如下",ch);
//		printf("由%s城市的%s起飞至%s城市的%s降落\n",i->pla.off_dep,i->pla.off_air,i->pla.land_dep,i->pla.land_air);
//		printf("预计起飞时间为%d日的%d，预计路程花费%d\n",i->time.fly_time,i->time.off_time,i->time.fly_time);
//		printf("机型为%s\n",i->ainf.air_mod);
//		printf("剩余一级座位数量:%d",i->ainf.set.set_1-i->ainf.setinf.set1);
//		printf("剩余二级座位数量:%d",i->ainf.set.set_2-i->ainf.setinf.set2);
//		printf("剩余三级座位数量:%d",i->ainf.set.set_3-i->ainf.setinf.set3);
//		printf("一级座位候补预约人数为%d",);//调用计算候补人数函数 
//		printf("二级座位候补预约人数为%d",);//调用计算候补人数函数 
//		printf("三级座位候补预约人数为%d",);//调用计算候补人数函数 
//		
//	}
//	else
//	{
//		printf("无此航班记录，建议重新查询") 
//	}
//}

void FlaiSeach(struct fl_inf *p)//航班查询 
{
	int choice;
	while (1)
	{
		printf(">>>>>>>>欢迎来到航空查询系统<<<<<<<<\n");
		printf("||选项1：查询航班号        ||\n");
		printf("||选项2：查询目的地        ||\n");
		printf("||选项3：查询航班时间      ||\n");
		printf("||选项0：退出              ||\n");
		printf("||请输入您的选择：         ||\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				{
					printf("请输入查询的航班号"); 
					char ch[6];
					scanf("%s",ch);
//					FlaiNumSeach(p,ch);				
				}

				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 0:
				
				return ;
		}
	}
}


void FlaiPlaSeach(struct fl_inf *p,char *ch)//航班地点查询(应当可以直接转到订票 
{
}

void FlaiTimeSeach(struct fl_inf *p,int time)//航班时间查询 (应当可以直接转到订票 
{
}

void BookAir(struct fl_inf *p,char *ch)//通过航班号订阅 
{	
}



int main()
{
	struct fl_inf phead,*p=&phead;
	struct user_inf uhead,*u=&uhead; 
//	inif(p);
//	iniu(u);
	int choice;
	while (1)
	{
		printf(">>>>>>>>欢迎来到航空订票系统<<<<<<<<\n");
		printf("||选项1：查询航班        ||\n");
		printf("||选项2：预约航班        ||\n");
		printf("||选项3：订票系统        ||\n");
		printf("||选项4：改退票系统      ||\n");
		printf("||选项5：修改航班信息    ||\n");
		printf("||选项6: 航空公司添加航班||\n");
		printf("||选项7: 航空公司删除航班||\n");
		printf("||选项0：退出            ||\n");
		printf("||请输入您的选择：       ||\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				FlaiSeach(p);
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 0:
				return 0;
		}
	}
	return 0;
}

