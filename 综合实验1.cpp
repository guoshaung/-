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

void FlaiNumSeach(struct fl_inf *p,char *ch)//航班号查询 (应当可以直接转到订票 
{
	struct fl_inf *i;
	for(i=p->next;strcmp(i->fli_num,ch)!=0&&i;i=i->next);//找到相同航班号或到头停下 
	if(i)//如果不是到头停下则说明有此航班 
	{
		printf("航班%s信息如下\n",ch);
		printf("由%s城市的%s起飞至%s城市的%s降落\n",i->pla.off_dep,i->pla.off_air,i->pla.land_dep,i->pla.land_air);
		printf("预计起飞时间为%d日的%d，预计路程花费%d\n",i->time.fly_time,i->time.off_time,i->time.fly_time);
		printf("机型为%s\n",i->ainf.air_mod);
		printf("剩余一级座位数量:%d",i->ainf.set.set_1-i->ainf.setinf.set1);
		printf("剩余二级座位数量:%d",i->ainf.set.set_2-i->ainf.setinf.set2);
		printf("剩余三级座位数量:%d",i->ainf.set.set_3-i->ainf.setinf.set3);
		printf("一级座位候补预约人数为%d");//调用计算候补人数函数 
		printf("二级座位候补预约人数为%d");//调用计算候补人数函数 
		printf("三级座位候补预约人数为%d");//调用计算候补人数函数 
		printf("\n");
	}
	else
	{
		printf("无此航班记录，建议重新查询\n");
	}
}

void FlaiPlaSeach(struct fl_inf *p,char *ch)//航班地点查询(应当可以直接转到订票 
{
}

void BookAir(struct fl_inf *p,char *ch)//通过航班号订票 
{	
}

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
					FlaiNumSeach(p,ch);				
				}

				break;
			case 2:
				{
					printf("请输入查询的地点"); 
					char ch[10];
					scanf("%s",ch);
					FlaiPlaSeach(p,ch);				
				}				
				break;
			case 3:
				{
					printf("请输入查询的时间"); //暂时还没想好怎么查时间段。。。要不不写？ 
					char ch[6];
					scanf("%s",ch);
					FlaiNumSeach(p,ch);				
				}				
				break;
			case 0:
				
				return ;
		}
	}
}
//void read(char arr[])
//{int i=0;
//	while((a=getchar())!='\0')
//	{
//		arr[i]=a;
//         i++;
//	}
//}
void DisPlay(struct fl_inf *p)
{
			printf("航班%s信息如下\n",p->fli_num);
			printf("由%s城市的%s起飞至%s城市的%s降落\n",p->pla.off_dep,p->pla.off_air,p->pla.land_dep,p->pla.land_air);
			printf("预计起飞时间为%d日的%d，预计路程花费%d\n",p->time.fly_time,p->time.off_time,p->time.fly_time);
			printf("机型为%s\n",p->ainf.air_mod);
			printf("剩余一级座位数量:%d",p->ainf.set.set_1-p->ainf.setinf.set1);
			printf("剩余二级座位数量:%d",p->ainf.set.set_2-p->ainf.setinf.set2);
			printf("剩余三级座位数量:%d",p->ainf.set.set_3-p->ainf.setinf.set3);
			printf("一级座位候补预约人数为%d");//调用计算候补人数函数 
			printf("二级座位候补预约人数为%d");//调用计算候补人数函数 
			printf("三级座位候补预约人数为%d");//调用计算候补人数函数 	
}

void Delete_air(struct fl_inf *p,char arr[])//删除需要航班号 
{
	int index=-1;//一个标志位，用于检验头结点 
	struct fl_inf *q=p;
	while(q->next->fli_num!=NULL)
	{
		
		if(!strcmp(q->fli_num,arr)&&index==-1)//相等返回0,单独讨论 
		{
			p=p->next;
			return ;
		 } 
		 
		 if(!strcmp(q->next->fli_num,arr))
		 {
		 q->next=q->next->next;
		 return ;
		 }
		 else
		 {
		 	q=q->next;
		 	index=1;
		 }
	}
	return ;
}

void Insert_air(struct fl_inf *p)//添加航班信息，需要完整输入信息 
{
	struct fl_inf q;
	printf("请输入新增航班号:\n");
	char num[6];
	for(int i=0;i<6;i++)
	scanf("%c",num[i]);
	strcpy(q.fli_num,num);
	printf("请输入飞机信息：\n");
	char num1[3];
	for(int i=0;i<3;i++)
	scanf("%c",num1[i]);
	strcpy(q.ainf.air_mod,num1);
	printf("请输入起降地点：\n");
	char num2[10],num3[10],num4[10],num5[10];
	scanf("%s%s%s%s",num2,num3,num4,num5);
	strcpy(q.pla.land_air,num2);
	strcpy(q.pla.land_dep,num3);
	strcpy(q.pla.off_air,num4);
	strcpy(q.pla.off_dep,num5);
	printf("请输入航班时间信息：\n");
	int i,j,k;
	scanf("%d%d%d",&i,&j,&k);
	q.time.fly_time=i;q.time.off_day=j;q.time.off_time=k;
//	printf("请输入订票用户信息：\n");
//	printf("请输入候补用户信息：\n");
	struct fl_inf *fp=p;
	for(int i=0;fp->next!=NULL;fp=fp->next);
	fp->next=&q;
}

int getNextLinePos(FILE *fp) {
	char ch;
	ch = fgetc(fp);
	while (ch != EOF) {
		ch = fgetc(fp);
		if (ch == '\n') {
			break;
		}
	}
}



void inif(struct fl_inf *p)
{
	FILE *fp;
	fp=fopen("D:\\新桌面\\航班信息.text","w+");
	if (fp == NULL) {
		printf("打开发生错误");
		exit(0);
	}//打开文件
	while (!feof(fp)) {
		fscanf(fp, "%s", p->ainf);
		fscanf(fp, "%s", books[i].brief);
		
		
	}
}
int main()
{
	
	struct fl_inf phead,*p=&phead;
	inif(p);//初始化航班信息 
	int choice;
	while (1)
	{
		printf(">>>>>>>>欢迎来到航空订票系统<<<<<<<<\n");
		printf("||选项1：查询航班        ||\n");
		printf("||选项2：订票系统        ||\n");
		printf("||选项3：改退票系统      ||\n");
		printf("||选项4：修改航班信息    ||\n");
		printf("||选项5: 航空公司添加航班||\n");
		printf("||选项6: 航空公司删除航班||\n");
		printf("||选项0：退出            ||\n");
		printf("||请输入您的选择：       ||\n");
		scanf("%d", &choice);
		system("cls");
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
			case 5:
				
				break;
			case 6:
				
				break;
			
			case 0:
				return 0;
		}
	}
	return 0;
}


