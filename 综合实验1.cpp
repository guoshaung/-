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

//void FlaiNumSeach(struct fl_inf *p,char *ch)//����Ų�ѯ (Ӧ������ֱ��ת����Ʊ 
//{
//	struct fl_inf *i;
//	for(i=p->next;strcmp(i->fli_num,ch)!=0&&i;i=i->next);
//	if(i)
//	{
//		printf("����%s��Ϣ����",ch);
//		printf("��%s���е�%s�����%s���е�%s����\n",i->pla.off_dep,i->pla.off_air,i->pla.land_dep,i->pla.land_air);
//		printf("Ԥ�����ʱ��Ϊ%d�յ�%d��Ԥ��·�̻���%d\n",i->time.fly_time,i->time.off_time,i->time.fly_time);
//		printf("����Ϊ%s\n",i->ainf.air_mod);
//		printf("ʣ��һ����λ����:%d",i->ainf.set.set_1-i->ainf.setinf.set1);
//		printf("ʣ�������λ����:%d",i->ainf.set.set_2-i->ainf.setinf.set2);
//		printf("ʣ��������λ����:%d",i->ainf.set.set_3-i->ainf.setinf.set3);
//		printf("һ����λ��ԤԼ����Ϊ%d",);//���ü������������ 
//		printf("������λ��ԤԼ����Ϊ%d",);//���ü������������ 
//		printf("������λ��ԤԼ����Ϊ%d",);//���ü������������ 
//		
//	}
//	else
//	{
//		printf("�޴˺����¼���������²�ѯ") 
//	}
//}

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


void FlaiPlaSeach(struct fl_inf *p,char *ch)//����ص��ѯ(Ӧ������ֱ��ת����Ʊ 
{
}

void FlaiTimeSeach(struct fl_inf *p,int time)//����ʱ���ѯ (Ӧ������ֱ��ת����Ʊ 
{
}

void BookAir(struct fl_inf *p,char *ch)//ͨ������Ŷ��� 
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
		printf(">>>>>>>>��ӭ�������ն�Ʊϵͳ<<<<<<<<\n");
		printf("||ѡ��1����ѯ����        ||\n");
		printf("||ѡ��2��ԤԼ����        ||\n");
		printf("||ѡ��3����Ʊϵͳ        ||\n");
		printf("||ѡ��4������Ʊϵͳ      ||\n");
		printf("||ѡ��5���޸ĺ�����Ϣ    ||\n");
		printf("||ѡ��6: ���չ�˾��Ӻ���||\n");
		printf("||ѡ��7: ���չ�˾ɾ������||\n");
		printf("||ѡ��0���˳�            ||\n");
		printf("||����������ѡ��       ||\n");
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

