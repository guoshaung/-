/*C����ʵ�ּ򵥵ĺ������ϵͳ�������ļ���*/
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<assert.h>

#define PERSON_MAXNUM 100
#define PERSONNOTICKET_MAX 10
#define MAX_SIZE 10
int _size = 0;
int _person_size = 0;
int _personnoticket_size = 0;

//���庽����Ϣ�ṹ��
typedef struct plane
{
    char ID[10];
    char Start_Place[10];
    char End_Place[10];
    float price;
    int Buy_num;
    int Max_num;
    char time[20];
}Plane;

//����˿���Ϣ�ṹ��
typedef struct Person
{
    int AirPlane_Num;
    char person_name[20];

}Person;




void home(Plane* p,Person* person, Person* person_noticket);//��ʼҳ��
void InitAirPlane(Plane** p);//��ʼ��������Ϣ�ڴ�
void InputAirPlane(Plane* p);//���뺽����Ϣ
void CheckAirPlane(Plane* p);//�鿴������Ϣ
void DelAirPlane(Plane* p);//ɾ��������Ϣ
void CheckAirPlaneOrder(Plane* p,Person* person);//�鿴���ඩ��
void PrintPerson(Plane* p, Person* person, int i);//��ӡ����˿�
void InitPerson(Person** person);//��ʼ���˿���Ϣ�ڴ�
void BookAirPlane(Plane* p, Person* person,Person* person_noticket);//Ԥ������
int CheckPerson(Plane* p, Person* person);//�鿴�˿Ͷ�����Ϣ
void ChangeAirPlane(Plane* p, Person* person);//��ǩ
void ReturnTicket(Plane* p, Person* person);//��Ʊ
void PrintPerson(Plane* p, Person* person, int i);
void CheckPersonNoTicket(Plane* p, Person* person_noticket);//�鿴������
///

void home(Plane* p, Person* person, Person* person_noticket)
{
    int a, i, j;
    printf("\n*****************************��ӭ����ɻ�Ʊ��ϵͳ*****************************\n");
    printf("\n*************���ã�����Ҫȷ��������ݣ�Ʊ����Ա�밴 1 ���ÿ��밴 0 ***********\n");
    printf("��ѡ��");
    scanf("%d", &a);
    //���������Ա����
    if (a == 1)
        do{
            printf("\n****************** 1.���뺽����Ϣ *******************\n");
            printf("\n****************** 2.ɾ��������Ϣ *******************\n");
            printf("\n****************** 3.���������Ϣ *******************\n");
            printf("\n****************** 4.���Ŀǰ�Ѷ�Ʊ��Ϣ *************\n");
            printf("\n****************** 5.�鿴������ *******************\n");
            printf("\n****************** 0.�˳�        ********************\n");
            printf("��ѡ��");
            scanf("%d", &i);
            switch (i)
            {
                case 0: break;
                case 1:InputAirPlane(p);break;
                case 2:DelAirPlane(p);break;
                case 3:CheckAirPlane(p);break;
                case 4:CheckAirPlaneOrder(p, person); break;
                case 5:CheckPersonNoTicket(p, person_noticket); break;
                default:
                    printf("�������\n");
                    break;
            }
        } while (i != 0);
    //�˿Ͳ���
    if (a == 0)
        do{

            printf("\n*********************** 1.��Ʊ **********************\n");
            printf("\n*********************** 2.��ǩ **********************\n");
            printf("\n*********************** 3.��Ʊ **********************\n");
            printf("\n*********************** 4.���������Ϣ **************\n");
            printf("\n*********************** 5.��ѯ���˶�Ʊ��Ϣ **********\n");
            printf("\n*********************** 0.�˳� **********************\n");
            printf("��ѡ��");
            scanf("%d", &j);
            switch (j)
            {
                case 0:break;
                case 1:BookAirPlane(p, person,person_noticket);break;
                case 2:ChangeAirPlane(p, person);break;
                case 3:ReturnTicket(p, person);break;
                case 4:CheckAirPlane(p);break;
                case 5:CheckPerson(p, person); break;
            }
        } while (j != 0);
}

//��ʼ��
void InitAirPlane(Plane** p)
{
    assert(p);

    //����ռ�
    *p = (Plane*)malloc(sizeof(Plane)*MAX_SIZE);
    if (NULL == *p)
    {
        printf("���ٿռ�ʧ�ܣ�\n");
        return;
    }
    (*p)->Buy_num = 0;
}
//���뺽����Ϣ
void InputAirPlane(Plane* p)
{
    if (_size <= MAX_SIZE)
    {
        printf("�����ţ�%d\n", _size);
        printf("���뺽��ID:");
        scanf("%s", (p+_size)->ID);
        printf("����ʼ���أ�");
        scanf("%s", (p + _size)->Start_Place);
        printf("����Ŀ�ĵأ�");
        scanf("%s", (p + _size)->End_Place);
        printf("���뺽�����ʱ�䣺");
        scanf("%s", (p + _size)->time);
        printf("����۸�");
        scanf("%f", &(p + _size)->price);
        printf("���뺽��ɳ������������");
        scanf("%d", &(p + _size)->Max_num);
        do
        {
            printf("Ŀǰ������Ʊ������");
            scanf("%d", &(p + _size)->Buy_num);
            if ((p + _size)->Buy_num > (p + _size)->Max_num)
            {
                printf("������������Ʊ��������\n");
                printf("���������룡\n\n");
            }
        } while ((p + _size)->Buy_num > (p + _size)->Max_num);
        _size++;
        printf("��Ӻ�����Ϣ��ɣ�\n\n");
    }
    else
    {
        printf("�ڴ�������\n");
        return;
    }
}

//���������Ϣ
void CheckAirPlane(Plane* p)
{
    int i = 0;
    printf("Ŀǰ���۵ĺ�����Ϣ��\n\n");
    for (i = 0; i < _size; i++)
    {
        printf("�����ţ�%d\n", i);
        printf("ID:%s\n", (p+i)->ID);
        printf("ʼ���أ�%s\n", (p + i)->Start_Place);
        printf("Ŀ�ĵ�:%s\n", (p + i)->End_Place);
        printf("���ʱ�䣺%s\n", (p + i)->time);
        printf("��Ʊ�۸�%2f\n", (p + i)->price);
        printf("ʣ���Ʊ��%d\n", ((p + i)->Max_num - (p + i)->Buy_num) );
        printf("\n");
    }
}

//ɾ��������Ϣ
void DelAirPlane(Plane* p)
{
    int j = 0;
    int i = -1;
    assert(p);
    printf("������Ҫɾ���ĺ����ţ�");
    scanf("%d", &i);
    for (j = i; j < _size; j++)
    {
        strcpy((p + j)->ID, (p + j + 1)->ID);
        strcpy((p + j)->Start_Place, (p + j + 1)->Start_Place);
        strcpy((p + j)->End_Place, (p + j)->End_Place);
        strcpy((p + j)->time, (p + j + 1)->time);
        (p + j)->price = (p + j + 1)->price;
        (p + j)->Max_num = (p + j + 1)->Max_num;
        (p + j)->Buy_num = (p + j + 1)->Buy_num;
    }
    _size--;
}

//��ʼ����Ʊ��Ϣ
void InitPerson(Person** person)
{
    assert(person);
    *person = (Person*)malloc(sizeof(Person)*PERSON_MAXNUM);
    if (NULL == *person)
    {
        printf("���ٿռ�ʧ�ܣ�\n");
        return;
    }
}

//��Ʊ
void BookAirPlane(Plane* p, Person* person, Person* person_noticket)
{
    int i = -1;
    CheckAirPlane(p);
    printf("��ѡ����ҪԤ���ĺ����ţ�");
    scanf("%d", &i);
    if ((p + i)->Max_num == (p + i)->Buy_num)
    {
        printf("�Բ��𣬸ú����Ʊ�����꣡\n");
        printf("�������������������ǽ�������ӽ�����������");
        scanf("%s", (person_noticket+_personnoticket_size)->person_name);
        (person_noticket + _personnoticket_size)->AirPlane_Num = i;
        _personnoticket_size++;
        printf("��Ӻ������ɹ���\n\n");
        return;
    }
    else
    {
        if (_person_size > PERSON_MAXNUM)
        {
            printf("�洢�������㣡\n");
            return;
        }
        printf("������������");
        scanf("%s", (person + _person_size)->person_name);
        (person + _person_size)->AirPlane_Num = i;
        _person_size++;
        (p + i)->Buy_num++;
        printf("Ԥ���ɹ���\n");
    }

}

//�鿴���˶�Ʊ��Ϣ
int CheckPerson(Plane* p, Person* person)
{
    int flag = 0;
    int i = 0;
    char _name[20] = { 0 };
    printf("����������������");
    scanf("%s", &_name);
    printf("���ĸ��˶�Ʊ��Ϣ��\n\n");
    for (i = 0; i < _person_size; i++)
    {
        if (0 == strcmp(_name, (person + i)->person_name))
        {
            flag = 1;
            printf("������ţ�%d\n", i);
            printf("������%s\n", (person + i)->person_name);
            printf("�����ţ�%d\n", (person + i)->AirPlane_Num);
            printf("����ID:%s\n", (p + (person + i)->AirPlane_Num)->ID);
            printf("ʼ���أ�%s\n", (p + (person + i)->AirPlane_Num)->Start_Place);
            printf("Ŀ�ĵأ�%s\n", (p + (person + i)->AirPlane_Num)->End_Place);
            printf("���ʱ��:%s\n", (p + (person + i)->AirPlane_Num)->time);
            printf("��Ʊ�۸�%f\n", (p + (person + i)->AirPlane_Num)->price);
            printf("\n");
        }
    }
    if (0 == flag)
    {
        printf("δ�ҵ��ó˿Ͷ�Ʊ��Ϣ��\n");
        return 0;
    }
    return 1;
}

//��ǩ
void ChangeAirPlane(Plane* p, Person* person)
{
    int i = -1;
    int j = -1;
    if (0 == CheckPerson(p, person))
    {
        return;
    }
    printf("������Ҫ��ǩ�Ķ�����ţ�");
    printf("\n");
    scanf("%d", &i);
    (p + i)->Buy_num--;
    CheckAirPlane(p);
    do
    {
        printf("������Ҫ��ǩ�ĺ����ţ�");
        scanf("%d", &j);
        if ((p + j)->Buy_num >= (p + j)->Max_num)
        {
            printf("�ôκ�������Ա��������ѡ��\n");
        }
    } while ((p + j)->Buy_num >= (p + j)->Max_num);
    (person + i)->AirPlane_Num = j;
    (p + j)->Buy_num++;
    printf("��ǩ�ɹ���\n\n");
}


//ɾ������
void ReturnTicket(Plane* p, Person* person)
{
    int i = -1;
    int j = 0;
    CheckPerson(p, person);
    printf("������Ҫɾ���Ķ�����ţ�");
    scanf("%d", &i);
    for (j = i; j < _person_size; j++)
    {
        (person + j)->AirPlane_Num = (person + j + 1)->AirPlane_Num;
        strcpy((person + j)->person_name, (person + j + 1)->person_name);
    }
    printf("��Ʊ�ɹ���\n");
}


//�鿴Ŀǰ��Ʊ��Ϣ
void CheckAirPlaneOrder(Plane* p, Person* person)
{
    int i = -1;
    for (i = 0; i < _size; i++)
    {
        printf("�����ţ�%d\n", i);
        printf("ID:%s\n", (p + i)->ID);
        printf("ʼ���أ�%s\n", (p + i)->Start_Place);
        printf("Ŀ�ĵ�:%s\n", (p + i)->End_Place);
        printf("���ʱ�䣺%s\n", (p + i)->time);
        printf("��Ʊ�۸�%2f\n", (p + i)->price);
        printf("ʣ���Ʊ��%d\n", ((p + i)->Max_num - (p + i)->Buy_num));
        printf("��Ʊ����Ϣ��"); PrintPerson(p,person, i);
    }
}
void PrintPerson(Plane* p, Person* person,int i)
{
    int ticket_num = 0;
    int j = 0;
    for (j = 0; j < _person_size; j++)
    {
        if ((person + j)->AirPlane_Num == i)
        {
            printf("%s ,", (person + j)->person_name);
            ticket_num++;
        }
    }
    printf("\n\n");
}

//��������ʼ��
void InitPersonNoTicket(Person** person_noticket)
{
    assert(person_noticket);
    *person_noticket = (Person*)malloc(sizeof(Person)*PERSONNOTICKET_MAX);
    if (NULL == *person_noticket)
    {
        printf("���ٿռ�ʧ�ܣ�\n");
        return;
    }
}

//�鿴������
void CheckPersonNoTicket(Plane* p, Person* person_noticket)
{
    int i = 0;
    printf("��������\n\n");
    if (0 == _personnoticket_size)
    {
        printf("������Ϊ�գ�\n\n");
        return;
    }
    for (i = 0; i < _personnoticket_size; i++)
    {
        printf("������%s\n", (person_noticket + i)->person_name);
        printf("����Ҫ�����ţ�%d\n", (person_noticket + i)->AirPlane_Num);
        printf("����ID:%s\n", (p + ((person_noticket + i)->AirPlane_Num))->ID);
        printf("ʼ���أ�%s\n", ((p + ((person_noticket + i)->AirPlane_Num))->Start_Place));
        printf("Ŀ�ĵأ�%s\n", (p + ((person_noticket + i)->AirPlane_Num))->End_Place);
    }
}
//������
int main()
{
    Plane* p=NULL;
    Person* person=NULL;
    Person* person_noticket = NULL;
    InitPersonNoTicket(&person_noticket);
    InitAirPlane(&p);
    InitPerson(&person);
    while (1)
    {
        home(p, person, person_noticket);
    }
    system("pause");
    return 0;
}
