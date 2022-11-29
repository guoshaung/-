#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
struct air_set //��λ��Ϣ���÷ɻ��ͺ���
{
	int set_1;//1����λ��������ͬ 
	int price_1;//1����λ�۸���ͬ 
	int set_2;
	int price_2;
	int set_3; 
	int price_3;
};
struct air_set_inf//��λʹ����Ϣ 
{
	int set1;//1����λʹ������ 
	int set2;
	int set3;
};
struct air_inf //��¼�ɻ��ͺ�����������λ��Ʊ��  
{
	char air_mod[3];//�ɻ��ͺ� 
	struct air_set set;//��λ��Ϣ���÷ɻ��ͺ���  
	struct air_set_inf setinf;//��λʹ����Ϣ 
};
struct off_land_pla //�𽵵ص� 
{
	char off_air[10];//��ɻ��� 
	char land_air[10];//������� 
	char off_dep[10];//��ɳ��� 
	char land_dep[10];//������� 
};
struct air_time//����ʱ�� 
{
	int off_day;//����� 
	int off_time;//���ʱ�� 
	int fly_time;//����ʱ�� 
};
struct user_inf//��Ʊ�û�����Ϣ 
{
	int name;//�û����� 
	int num;//��Ʊ���� 
	int set;//������λ 
	struct user_inf *next;
};
struct wait_inf//���û�����Ϣ 
{
	int name;//�û����� 
	int num;//��Ʊ���� 
	int set;//������λ 
	struct user_inf *next;
};

struct fl_inf //������Ϣ 
{
	char fli_num[6];//����ţ�����6λ 
	struct air_inf ainf;//�ɻ���Ϣ 
	struct off_land_pla pla;//�𽵵ص� 
	struct air_time time;//����ʱ����Ϣ 
	struct user_inf uinf;//��Ʊ�û�����Ϣ
	struct wait_inf winf;//���û�����Ϣ
	struct fl_inf *next;
};

void FlaiNumSeach(struct fl_inf *p,char *ch)//����Ų�ѯ (Ӧ������ֱ��ת����Ʊ 
{
	struct fl_inf *i;
	for(i=p->next;strcmp(i->fli_num,ch)!=0&&i;i=i->next);//�ҵ���ͬ����Ż�ͷͣ�� 
	if(i)//������ǵ�ͷͣ����˵���д˺��� 
	{
		printf("����%s��Ϣ����\n",ch);
		printf("��%s���е�%s�����%s���е�%s����\n",i->pla.off_dep,i->pla.off_air,i->pla.land_dep,i->pla.land_air);
		printf("Ԥ�����ʱ��Ϊ%d�յ�%d��Ԥ��·�̻���%d\n",i->time.fly_time,i->time.off_time,i->time.fly_time);
		printf("����Ϊ%s\n",i->ainf.air_mod);
		printf("ʣ��һ����λ����:%d",i->ainf.set.set_1-i->ainf.setinf.set1);
		printf("ʣ�������λ����:%d",i->ainf.set.set_2-i->ainf.setinf.set2);
		printf("ʣ��������λ����:%d",i->ainf.set.set_3-i->ainf.setinf.set3);
		printf("һ����λ��ԤԼ����Ϊ%d");//���ü������������ 
		printf("������λ��ԤԼ����Ϊ%d");//���ü������������ 
		printf("������λ��ԤԼ����Ϊ%d");//���ü������������ 
		printf("\n");
	}
	else
	{
		printf("�޴˺����¼���������²�ѯ\n");
	}
}

void FlaiPlaSeach(struct fl_inf *p,char *ch)//����ص��ѯ(Ӧ������ֱ��ת����Ʊ 
{
}

void BookAir(struct fl_inf *p,char *ch)//ͨ������Ŷ�Ʊ 
{	
}

void FlaiSeach(struct fl_inf *p)//�����ѯ 
{
	int choice;
	while (1)
	{
		printf(">>>>>>>>��ӭ�������ղ�ѯϵͳ<<<<<<<<\n");
		printf("||ѡ��1����ѯ�����        ||\n");
		printf("||ѡ��2����ѯĿ�ĵ�        ||\n");
		printf("||ѡ��3����ѯ����ʱ��      ||\n");
		printf("||ѡ��0���˳�              ||\n");
		printf("||����������ѡ��         ||\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				{
					printf("�������ѯ�ĺ����"); 
					char ch[6];
					scanf("%s",ch);
					FlaiNumSeach(p,ch);				
				}

				break;
			case 2:
				{
					printf("�������ѯ�ĵص�"); 
					char ch[10];
					scanf("%s",ch);
					FlaiPlaSeach(p,ch);				
				}				
				break;
			case 3:
				{
					printf("�������ѯ��ʱ��"); //��ʱ��û�����ô��ʱ��Ρ�����Ҫ����д�� 
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
			printf("����%s��Ϣ����\n",p->fli_num);
			printf("��%s���е�%s�����%s���е�%s����\n",p->pla.off_dep,p->pla.off_air,p->pla.land_dep,p->pla.land_air);
			printf("Ԥ�����ʱ��Ϊ%d�յ�%d��Ԥ��·�̻���%d\n",p->time.fly_time,p->time.off_time,p->time.fly_time);
			printf("����Ϊ%s\n",p->ainf.air_mod);
			printf("ʣ��һ����λ����:%d",p->ainf.set.set_1-p->ainf.setinf.set1);
			printf("ʣ�������λ����:%d",p->ainf.set.set_2-p->ainf.setinf.set2);
			printf("ʣ��������λ����:%d",p->ainf.set.set_3-p->ainf.setinf.set3);
			printf("һ����λ��ԤԼ����Ϊ%d");//���ü������������ 
			printf("������λ��ԤԼ����Ϊ%d");//���ü������������ 
			printf("������λ��ԤԼ����Ϊ%d");//���ü������������ 	
}

void Delete_air(struct fl_inf *p,char arr[])//ɾ����Ҫ����� 
{
	int index=-1;//һ����־λ�����ڼ���ͷ��� 
	struct fl_inf *q=p;
	while(q->next->fli_num!=NULL)
	{
		
		if(!strcmp(q->fli_num,arr)&&index==-1)//��ȷ���0,�������� 
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

void Insert_air(struct fl_inf *p)//��Ӻ�����Ϣ����Ҫ����������Ϣ 
{
	struct fl_inf q;
	printf("���������������:\n");
	char num[6];
	for(int i=0;i<6;i++)
	scanf("%c",num[i]);
	strcpy(q.fli_num,num);
	printf("������ɻ���Ϣ��\n");
	char num1[3];
	for(int i=0;i<3;i++)
	scanf("%c",num1[i]);
	strcpy(q.ainf.air_mod,num1);
	printf("�������𽵵ص㣺\n");
	char num2[10],num3[10],num4[10],num5[10];
	scanf("%s%s%s%s",num2,num3,num4,num5);
	strcpy(q.pla.land_air,num2);
	strcpy(q.pla.land_dep,num3);
	strcpy(q.pla.off_air,num4);
	strcpy(q.pla.off_dep,num5);
	printf("�����뺽��ʱ����Ϣ��\n");
	int i,j,k;
	scanf("%d%d%d",&i,&j,&k);
	q.time.fly_time=i;q.time.off_day=j;q.time.off_time=k;
//	printf("�����붩Ʊ�û���Ϣ��\n");
//	printf("��������û���Ϣ��\n");
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
	fp=fopen("D:\\������\\������Ϣ.text","w+");
	if (fp == NULL) {
		printf("�򿪷�������");
		exit(0);
	}//���ļ�
	while (!feof(fp)) {
		fscanf(fp, "%s", p->ainf);
		fscanf(fp, "%s", books[i].brief);
		
		
	}
}
int main()
{
	
	struct fl_inf phead,*p=&phead;
	inif(p);//��ʼ��������Ϣ 
	int choice;
	while (1)
	{
		printf(">>>>>>>>��ӭ�������ն�Ʊϵͳ<<<<<<<<\n");
		printf("||ѡ��1����ѯ����        ||\n");
		printf("||ѡ��2����Ʊϵͳ        ||\n");
		printf("||ѡ��3������Ʊϵͳ      ||\n");
		printf("||ѡ��4���޸ĺ�����Ϣ    ||\n");
		printf("||ѡ��5: ���չ�˾��Ӻ���||\n");
		printf("||ѡ��6: ���չ�˾ɾ������||\n");
		printf("||ѡ��0���˳�            ||\n");
		printf("||����������ѡ��       ||\n");
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


