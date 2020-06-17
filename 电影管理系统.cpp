#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <windows.h>
#include <conio.h>
#define SIZE 4
#define KEY 0x86
typedef struct film
{
	int number;
	char film_name[20];
	char release_data[20];                    /*��ӳʱ��*/
	float grade;                                /*����*/
	char protagonist_name[20];               /*���˹�����*/
	int box_office;                            /*Ʊ��*/
	int fares;                                 /*Ʊ��*/ 
	int amount;
	struct film* next; 
}*list1;
typedef struct Vip 
{
	char name[20],phone[20];
	float score; 
	int num;           
	struct Vip* next;
}*list2;
typedef struct Adm
{
	char name[20],password[20];
	struct Adm* next;
}*list3;
void enter0();                           /*��½����*/
void Vis_window();                      /*�οͽ���*/
void Adm_window();                     /*����Ա����*/
void Adm_add();                        /*����Ա¼��*/
void Adm_change();                     /*����Ա�޸�*/ 
void Adm_load();                      /*����Ա��¼ 1*/  
void Adm_manage();                  /*����Ա������� 2*/  
void Film_add();                        /*��Ӱ����*/
void Film_find();                       /*��Ӱ��ѯ*/
void Film_buy();                        /*��ӰƱ����*/
void Film_change();                   /*��Ӱ��Ϣ����*/ 
void Sale_window();
//void Vip_enter();                     /*��Ա��Ϣ¼��*/ 
//int Vip_stat();                       /*��Ա��ͳ��*/ 
//void Vip_find();                      /*��Ա��Ϣ��ѯ */
void Pro_bar() 
{
	system("cls");
	char arr[50] = {'\0'};
	const char *p = "|/-\\";
	memset(arr,0,sizeof(arr));
	int n = 50,i = 0;
	while(i<=n)
	{
		arr[i]= '=';
		printf("\t\t\t\t[%-50s][%d%%][%c]\r",arr,i*2,p[i%4]);
		fflush(stdout);
		i++;
		usleep(20000);
    }
	printf("\n");
}
void enter0()
{
	Pro_bar();
	system("cls");
	int num;
	char name[20];
	printf("\t\t\t\t **************************************************\n");
	printf("\t\t\t\t **************  ��ӭ������Ӱ���ֲ�   *************\n");
	printf("\n");
	printf("\t\t\t\t **************     ����������      ***************\n");
	printf("\n");
	printf("\t\t\t\t *************     1.����Ա����      **************\n");
	printf("\n");
	printf("\t\t\t\t *************      2.�οͽ���      ***************\n");
	printf("\n");
	printf("\t\t\t\t *****************    3.�˳�   ********************\n");
	printf("\t\t\t\t **************************************************\n");
	printf("\t\t\t\t ");
	scanf("%d",&num);
	switch (num)
	{
		case 1:
			Adm_window();
			break;
		case 2:
			Vis_window();
			break;
		case 3:
			Pro_bar(); 
			system("cls");
			exit(0);
			break;
		default :
		    printf("\t\t\t\t  δ�����壬����������ص�ǰ\n");
			system("cls"); 
			enter0();
    }
} 
void Vis_window()
{
	system("cls");
	int num;
	char name[20];
	printf("\t\t\t\t **************************************************\n");
	printf("\t\t\t\t ****************    ��Ӱ�߽���    ****************\n");
	printf("\n");
	printf("\t\t\t\t *****************   1.���ҵ�Ӱ   *****************\n");
	printf("\n");
	printf("\t\t\t\t ****************   2.�����ӰƱ   ****************\n");
	printf("\n");
	printf("\t\t\t\t *****************   3.�����ϲ�  ******************\n"); 
	printf("\n");
	printf("\t\t\t\t **************************************************\n");
	printf("\t\t\t\t ");
	scanf("%d",&num);
	switch (num)
	{
		case 1:
			Film_find();
			break;
		case 2:
			Sale_window();
			break;
		case 3:
			enter0();
			break;
		default:
			printf("\t\t\t\t  δ�����壬����������ص�ǰ\n");
			system("cls"); 
			enter0();
	}
}
void Adm_window()
{
	system("cls");
	int num;
	char name[20];
	printf("\t\t\t\t **************************************************\n");
	printf("\t\t\t\t ****************    ����Ա����    ****************\n");
	printf("\n");
	printf("\t\t\t\t *****************  1.����Ա¼��  *****************\n");
	printf("\n");
	printf("\t\t\t\t ****************   2.����Ա�޸�  *****************\n");
	printf("\n");
	printf("\t\t\t\t ****************   3.����Ա��¼  *****************\n"); 
	printf("\n");
	printf("\t\t\t\t ****************   4.������һ��   ****************\n");
	printf("\n");
	printf("\t\t\t\t **************************************************\n");
	printf("\t\t\t\t ");
	scanf("%d",&num);
	switch (num)
	{
		case 1:
			Adm_add(); 
			break;
		case 2:
			Adm_change();  
			break;
		case 3:
			Adm_load();
			break;
		case 4:
			enter0();
			break;
		default:
			printf("\t\t\t\t  δ�����壬����������ص�ǰ\n");
			system("cls"); 
			enter0();
	}
}
void Adm_add()
{
	system("cls");
	FILE *fp;
	int i,j=0,m;
	char name[20],name0[20],password[20],password0[20];
	fp = fopen("Adm_list.txt","r");
	if(fp == NULL)
	{
		j=1;
		fp = fopen("Adm_list.txt","a");
	} 
	fclose(fp);
	printf("\t\t\t\t  �������Ա��:");
	scanf("%s",name);
	if(j==0);
	{
		fp = fopen("Adm_list.txt","r");
		while(!feof(fp))
		{
			fscanf(fp," %s %s\n",name0,password0);
			{
				if (!strcmp(name0,name))
				{
					printf("\t\t\t\t  �Ѵ��ڸù���Ա�������ظ�¼�룡\n");
					printf("\t\t\t\t  ����������ϲ㣡");
					getch();
					fclose(fp);
					enter0(); 
				}
			}
		}
	}
	fp = fopen("Adm_list.txt","a");
	printf("\t\t\t\t  ��������:"); 
	for(i=0; ;i++)
	{
		m=0;
		password0[i]=getch();
		if(password0[i]=='\r')
		{
			password0[i]='\0';
			break;
		}
		if(password0[i]=='\b')
		{
			m=1;
			password0[i]='\0';
			password0[i-1]='\0';
			i = i-2;
			printf("\b \b");
		}
		if(m==0) printf("*");
	}
	printf("\n\t\t\t\t  ���ٴ���������:");
	for(i=0; ;i++)
	{
		m=0;
		password[i]=getch();
		if(password[i]=='\r')
		{
			password[i]='\0';
			break;
		}
		if(password[i]=='\b')
		{
			m=1;
			password[i]='\0';
			password[i-1]='\0';
			i = i-2;
			printf("\b \b");
		}
		if(m==0) printf("*");
	}
	if(!strcmp(password0,password))
	{
		for (i=0;i<strlen(password);i++)
		{
			password0[i] = password[i]^KEY;
			
		}
		fprintf(fp," %s %s\n",name,password0);
		printf("\n\t\t\t\t  ¼��ɹ����밴����������ϲ㣡");
	}
	else
	{
		printf("\n\t\t\t\t  ¼��ʧ�ܣ����벻һ�£��밴����������ϲ�:");		
	}
	getch(); 
	fclose(fp);
	enter0(); 
}
void Film_manage()
{
	system("cls");
	int x1;
	printf("\t\t\t\t  ****************��Ӱ�������**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ***********     1.��Ӱ���   *************\n");
	printf("\n");
	printf("\t\t\t\t  ***********     2.��Ӱ��ѯ   *************\n");
	printf("\n");
	printf("\t\t\t\t  ***********     3.��Ӱ�޸�   *************\n");
	printf("\n");
	printf("\t\t\t\t  ***********    4.��ӰƱ����   ************\n");
	printf("\n");
	printf("\t\t\t\t  **************    4.�˳�    **************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	scanf("%d",&x1);
	switch (x1)
	{
		case 1:
			Film_add();
			break;
		case 2:
			Film_find();
			break;
		case 3:
			Film_change();
			break;
		//case 4:
			//Film_buy();
			//break;
		case 4:
			enter0();
			break; 
		default :
		    printf("\t\t\t\t  δ�����壬������������ϲ�\n") ;
		    getch();
			system("cls"); 
			Film_manage();
	}
} 
void Adm_load()                     
{
	system("cls");
	FILE *fp;
	char name[20],name0[20],password[20],password0[20];
	int flag = 0,i,j;
	fp = fopen("Adm_list.txt","r");
	if (fp == NULL)
	{
		printf("\t\t\t\t  ��δ��������Ա�������������¼��.");
		Adm_add();
	 } 
	printf("\t\t\t\t  �����¼����Ա����:");
	scanf("%s",name0);
	while(!feof(fp))
	{
		fscanf(fp, " %s %s\n",name,password);
		if (!strcmp(name,name0))
		{
			flag = 1;
			printf("\t\t\t\t  ��������:");
			for(i=0; ;i++)
			{
				j=0;
				password0[i]=getch();
				if(password0[i]=='\r')
				{
					password0[i]='\0';
					break;
				}
				if(password0[i]=='\b')
				{
					j=1;
					password0[i]='\0';
					password0[i-1]='\0';
					i = i-2;
					printf("\b \b");
				}
				if(j==0) printf("*");
			}
			for(i=0;i<strlen(password);i++)
			{
				password[i] = password[i]^KEY;
			}
			if(!strcmp(password,password0))
			{
				Film_manage();                           
			}
			else
			{
				printf("\n\t\t\t\t  �����������������ϲ�:");
				getch(); 
				enter0();
				break;
			}
		}
	}
	if (flag==0)
	{
		printf("\t\t\t\t  �ù���Աδ¼�룬�밴����������ϲ㣡");
		getch();
		enter0(); 
	}
}
void Adm_change() 
{
	system("cls");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ***************����Ա�޸Ľ���*************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  *************   1.����Աɾ��   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **************   2.�����޸�   ************\n");
	printf("\n");
	printf("\t\t\t\t  **************   3.�����ϲ�   ************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	int q;
	scanf("%d",&q); 
	system("cls");
	FILE *fp;
	list3 head,p1,p2;
	char i,name[20],password[20];
	int j,l=0,m;
	fp = fopen("Adm_list.txt","r");
	if(fp==NULL)
	{
		printf("\t\t\t\t  �����ڹ���Ա��\n\t\t\t\t  �밴����������ϲ�");
		getch();
		enter0(); 
	}
	p1 = head = (list3)malloc(sizeof(struct Adm));
	p1->next = NULL;
	while(!feof(fp))
	{
		fscanf(fp," %s %s\n",p2->name,p2->password);
		p2 = (list3)malloc(sizeof(struct Adm));
		p1->next=p2;
		p2->next=NULL;
		p1=p2;		
	}
	fclose(fp);
	if (q==1) 
	{
		fp = fopen("Adm_list.txt","w");
		p2 = head->next;
		printf("\t\t\t\t  Ҫ���ĵĹ���Ա����Ϊ:");
		scanf("%s",name);
		while(p2)
		{
			m=0;
			if(!strcmp(p2->name,name))
			{
				l=1;
				printf("\t\t\t\t  �Ƿ�ɾ���ù���Ա��\n");
				printf("\t\t\t\t  �س�ɾ������������أ�");
				i=getch();
				if (i==13)
				{
					m=1;
					p1 = p2;
					p2 = p2->next;
					free(p1);
				}
			}
			fprintf(fp," %s %s\n",p2->name,p2->password);
			p2 = p2->next;
		}
		fclose(fp);
	}
	else if(q==2)
	{
		fp = fopen("Adm_list.txt","w");
		p2 = head->next;
		printf("\t\t\t\t  Ҫ���ĵĹ���Ա����Ϊ:");
		scanf("%s",name);
		while(p2)
		{
			l=1;
			printf("\n\t\t\t\t  ���ڸù���Ա���������뽫����ԭ����");
			for(j=0; ;j++)
			{
				password[j]=getch();
				if(password[j]=='\r')
				{
				password[j]='\0';
				break;
				}
				printf("*");
				fprintf(fp," %s %s\n",p2->name,p2->password);
				p2 = p2->next;
			}
			fclose(fp);
		}
	}
	else if(q==3)
	{
		enter0();
	}
	if(l==0)
	{
		printf("\n\t\t\t\t  �ù���Աδ��¼�룡\n\t\t\t\t  ����������ϲ�"); 
		getch();
		enter0();
	}
	printf("\n\t\t\t\t  ������ɣ�����������ϲ㣡");
	getch();
	enter0();
}
void Sale_system() 
{
	system("cls");
	int x4;
	printf("\t\t\t\t  ****************���۹������**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ***********    1.ʹ�ü�¼     ************\n");
	printf("\n");
	printf("\t\t\t\t  ***********  2.���۲�Ʒ����    ***********\n");
	printf("\n");
	printf("\t\t\t\t  ***********    3.�����ϲ�    *************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	scanf("%d",&x4);
	switch (x4)
	{
		case 1:
			//Use_history();
			break;
		case 2:
			//Data_sort();
			break;
		case 3:
			Adm_manage();
			break;
		default :
		    printf("\n\t\t\t\t  δ�����壬������������ϲ�\n") ;
		    getch();
			system("cls"); 
			Adm_manage();
	}
}
void Adm_manage()
{
	system("cls");
	int x1;
	printf("\t\t\t\t  **************����Ա�������***************\n");
	printf("\n");
	printf("\t\t\t\t  *******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ************     1.��Ӱ����     ***********\n");
	printf("\n");
	printf("\t\t\t\t  ************     2.��Ա����     ***********\n");
	printf("\n");
	printf("\t\t\t\t  ************     3.����ϵͳ     ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********       4.�����ϲ�     ***********\n");
	printf("\n");
	printf("\t\t\t\t  *******************************************\n");
	printf("\t\t\t\t  ") ;
	scanf("%d",&x1);
	switch (x1)
	{
		case 1:
			Film_manage();
			break;
		case 2:
			//Vip_manage();
			break;
		case 3:
			Sale_system();
			break;
		case 4:
			enter0();
			break;
		default :
		    printf("\t\t\t\t  δ�����壬������������ϲ�\n") ;
		    getch();
			system("cls"); 
			Adm_manage();
	}
}
void Sale_window()
{
	system("cls");
	//Sale_list();
	FILE *fp1,*fp2;
	char key[20],j,film_name[20],data[20];
	int many,i,num,flag=0,amount;
	float money;
	list1 head,p1,p2;
	fp1 = fopen("film_list.txt","r");
	if(fp1 == NULL)
	{
		printf("\n\t\t\t\t  ���޵�Ӱ�����ۣ���������أ�");
		getch();
		Sale_system(); 
	}
	fp2 = fopen("Sale_history.txt","a");
	p1 = head = (list1)malloc(sizeof(struct film));
	head->next = NULL;
	while (!feof(fp1))
	{
		p2 = (list1)malloc(sizeof(struct film));
		fscanf(fp1," %d %d %s %s %s %d\n",&p2->number,&p2->fares,&p2->protagonist_name,&p2->release_data,&p2->film_name);
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
	}
	fclose(fp1);
	printf("\t\t\t\t  �����������Ӱ��š�Ʊ�ۡ����˹����ֻ���ӳ���ڣ���Ҳ�������Ӱ���ֻ����˹����ֹؼ��֣�");
	scanf("%s",key);
	p2 = head->next;
	while(p2)
	{
		flag = 0;
		if(!strcmp(p2->film_name,key) || !strcmp(p2->film_name,key) || !strcmp(p2->protagonist_name,key) ||strstr(p2->protagonist_name,key)||atoi(key) == p2->number)
		{
			fp1 = fopen("film_list.txt","w"); 
			break;
		}
		else
		{
			flag = 1;
		}
		p2 = p2->next;	
	}
	if(flag == 1)
	{
		printf("\t\t\t\t  ���޴˷�װ���ͣ��������������������");
		getch();
		Sale_window(); 
	}
	p2 = head->next;
	while(p2)
	{
		i=0;
		if(!strcmp(p2->film_name,key) || !strcmp(p2->protagonist_name,key) || strstr(p2->film_name,key) ||atoi(key) == p2->number)
		{
			printf("\t\t\t\t  �õ�Ӱ��ϢΪ��\n\t\t\t\t  ���      ����		���˹�����      ��Ӱ����      Ʊ��\n");
			printf("\t\t\t\t  %-10d%-15s%-10s%-10s%-10%-10d\n",&p2->number,&p2->release_data,&p2->protagonist_name,&p2->film_name,&p2->fares,&amount);
			printf("\t\t\t\t  �Ƿ���\n\t\t\t\t  �س�������������������ñ�š����ơ�Ʊ�ۻ����ڵĵ�Ӱ!\n");
			j = getch();
			if(j==13)		
			{
				i=1;
				printf("\t\t\t\t  ���빺��������");
				scanf("%d",&many);
				p2->amount = p2->amount-many;
				while(p2->amount<0)
				{
					printf("\t\t\t\t  ��治�㣬����ٹ�������");
					p2->amount = p2->amount+many;
					scanf("%d",&many);
					if(p2->amount-many<0)
					{
						printf("\t\t\t\t  ������˼���õ�ӰƱ���ޡ�\n\t\t\t\t  �������ϲ㣡");
						getch();
						Sale_window(); 
						break;
					}
					p2->amount = p2->amount-many;
				}
				money = many*p2->fares; 
				fprintf(fp2," %d %s %s %s %s %.2f %d\n",p2->number,p2->film_name,p2->protagonist_name,p2->release_data,money,many);	
				printf("\t\t\t\t  �Ƿ�ʹ�û�Ա���л��֣�\n\t\t\t\t  �س�ʹ�ã����������.");
				j = getch();
				{
					if(j==13)
					{
						printf("\n\t\t\t\t  ����绰���룺"); 
						scanf("%s",key);
						//Vip_use(key,money);
					}
				} 		
			}		 
		}
		fprintf(fp1," %d %s %s %d %.2f %d\n",p2->number,p2->film_name,p2->protagonist_name,p2->release_data,p2->fares,p2->grade,p2->amount);
		if(p2->next==NULL)
		{
			printf("\n\t\t\t\t  ������ϣ��޸��������Ϣ��\n\n\t\t\t\t  �س����½��й�����������أ�\n\t\t\t\t  "); 
		}
		p2 = p2->next;	
	}
	fclose(fp1);
	fclose(fp2);
	j = getch();
	if(j==13)
	{
		Sale_window();
	} 
	//Vis_window();
}
int Film_stat()
{
	FILE *fp;
	fp = fopen("Film_list.txt","r");
	char Film_name[20],release_data[20],protagonist_name[20];
	int fares,sum=0,number;
	float grade;
	while(!feof(fp))
	{
		fscanf(fp," %d %d %s %s %s %d",&number,&fares,&protagonist_name,&release_data,&Film_name,&sum);
		sum++;
	} 
	fclose(fp);
	return sum;
} 
void Film_add()
{
	system("cls");
	FILE *fp;
	char i=13;
	int n; 
	list1 head,p1,p2;
	p1 = head = (list1)malloc(sizeof(struct film));
	head->next = NULL;
	fp = fopen("Film_list.txt","a");
	n = Film_stat();
	printf("\t\t\t\t  �밴�����¸�ʽ¼���Ӱ��Ϣ��\n");
	while(i==13)
	{
		p2 = (list1)malloc(sizeof(struct film));
		printf("\t\t\t\t   ����     ��ӳʱ��     ����     ���˹�     Ʊ��\n\t\t\t\t  ");
		scanf("%s %s %s %s %f %d",&p2->film_name,&p2->release_data,&p2->grade,&p2->protagonist_name,&p2->fares);
		p2->number = n;
		p1->next = p2;
		p2->next = NULL;
		p1 = p2; 
		printf("\t\t\t\t  �Ƿ��������?�س��������룬����������ϲ㣡\n");
		i=getch();
		n++;
	}
	p2 = head->next;
	while(p2)
	{
		fprintf(fp," %d %s %s %s %s %f %d\n",p2->number,p2->film_name,p2->release_data,p2->grade,p2->protagonist_name,p2->fares);
		p2 = p2->next;
	}
	fclose(fp);
	Film_manage(); 
}
void Film_find()
{
	system("cls");
	FILE *fp;
	list1 head,p1,p2;
    char key1[20];
	p1 = head = (list1)malloc(sizeof(struct film));
	head->next = NULL;
	fp = fopen("Film_list.txt","r");
	if (fp == NULL )
	{
		printf("\t\t\t\t  �޵�ӰĿ¼���밴��������أ�");
		getch(); 
		Film_manage();
	}
	while(!feof(fp))
	{
		p2 = (list1)malloc(sizeof(struct film));
		fscanf(fp," %d %s %s %f %s %d\n",&p2->number,p2->film_name,p2->release_data,p2->grade,p2->protagonist_name,p2->fares);
		p1->next=p2;
		p2->next=NULL;
		p1=p2;
	}
	fclose(fp);
	printf("\t\t\t\t  �����ѯ��������ѡ�� ���� ���˹� Ʊ�� ʱ����߹ؼ���\n\t\t\t\t  ");
	scanf("%s",key1);
	Film_manage(); 
} 
void Film_change()
{
	system("cls");
	printf("\t\t\t\t  *****************��Ӱ�޸Ľ���**************\n");
	printf("\n");
	printf("\t\t\t\t  *******************************************\n"); 
	printf("\n");
	printf("\t\t\t\t  ***********     1����Ӱɾ��     ***********\n");
	printf("\n"); 
	printf("\t\t\t\t  **********    2����Ӱ�����޸�     *********\n");
	printf("\n");
	printf("\t\t\t\t  ***********     3�������ϲ�     ***********\n");
	printf("\n");
	printf("\t\t\t\t  *******************************************\n"); 
	printf("\n");
	int x,y,m,l;
	scanf("%d",&x); 
	system("cls");
	FILE *fp;
	fp = fopen("Film_list.txt","r");
	list1 head,p1,p2;
	char i,key[20],fares;
	p1 = head = (list1)malloc(sizeof(struct film));
	head->next = NULL;	
	while(!feof(fp))
	{
		p2 = (list1)malloc(sizeof(struct film));
		fscanf(fp," %d %f %s %s %s %d",&p2->number,&p2->grade,&p2->film_name,&p2->protagonist_name,&p2->release_data,&p2->fares);
		p1->next=p2;
		p2->next=NULL;
		p1=p2;
	}	
	if (x==1) 
	{
		fp = fopen("Film_list.txt","w");
		p2 = head->next;
		printf("\t\t\t\t  Ҫ���ĵĵ�Ӱ����Ϊ:");
		printf("\t\t\t\t  �����ϲ���������Ϣ \n�س������ϲ㣬�����������");
		i = getch();
		if (i==13) 
		Film_manage();
		scanf("%s",key);
		while(p2)
		{
			m=0;
			if(!strcmp(p2->film_name,key))
			{
				l=1;
				printf("\t\t\t\t  �Ƿ�ɾ���õ�Ӱ�����Ϣ��\n");
				printf("\t\t\t\t  �س�ɾ�����밴��������أ�");
				i=getch();
				if (i==13)
				{
					m=1;
					p1 = p2;
					p2 = p2->next;
					free(p1);
				}
			}
			fprintf(fp," %d %d %s %s %s %d",p2->number,p2->fares,p2->protagonist_name,p2->release_data,p2->film_name);
			p2 = p2->next;
		}
		fclose(fp);
	}
	else if(x==2)
	{
		fp = fopen("Film_list.txt","w");
		p2 = head->next;
		printf("\t\t\t\t  Ҫ���ĵĵ�Ӱ����Ϊ:");
		printf("\t\t\t\t  ������������Ϣ���ȷ����ϲ���ң�\n�س������ϲ㣬�����������");
		i = getch();
		if (i==13) Film_manage();
		scanf("%s",key);
		while(p2)
		{
			if(!strcmp(p2->film_name,key))
			{
				l=1;
				printf("\t\t\t\t  Ŀǰ�õ�Ӱ��ϢΪ��\n");
				printf("\t\t\t\t    ���    Ʊ��    ���˹�����     ����     ��Ӱ����\n");
				printf("\t\t\t\t    %-10d %-10d %-10s %-10s %-10s %-10d\n",p2->number,p2->fares,p2->protagonist_name,p2->release_data,p2->film_name);
				printf("\n\t\t\t\t  ���ڸõ�Ӱ�����������ĵ���Ŀ���\n");
				printf("\t\t\t\t  ps:���� �۸�ֻ���������֣�����ֻ��������������\n");
				printf("\t\t\t\t  �ɸ���Ŀ��1.Ʊ�� 2.���˹����� 3.���� 4.��Ӱ����\n");
				scanf("%d",&y);
				printf("\t\t\t\t  ����ĺ����ݣ�");
				scanf("%s",key);
				switch(y)
				{
					case 1:
						y = atoi(key);
						printf("\t\t\t\t  ���ݱ仯Ϊ%d -> %d",p2->fares,y);
						p2->fares = y;
						break;
					case 2:
						printf("\t\t\t\t  ���ݱ仯Ϊ%s -> %s",p2->protagonist_name,key);
						strcpy(p2->protagonist_name,key);
						break;
					case 3:
						printf("\t\t\t\t  ���ݱ仯Ϊ%s -> %s",p2->release_data,key);
						strcpy(p2->release_data,key);
						break;
					case 4:
						printf("\t\t\t\t  ���ݱ仯Ϊ%s -> %s",p2->film_name,key);
						strcpy(p2->film_name,key);
						break;
					default :
					    printf("\t\t\t\t  δ�����壬������������ϲ�\n") ;
					    getch();
						system("cls"); 
						Film_manage();						 
				}
			}
			fprintf(fp," %d %d %s %s %s %d",p2->number,p2->fares,p2->protagonist_name,p2->release_data,p2->film_name);
			p2 = p2->next;
		}
		fclose(fp);
	}
	else if(x==3)
	{
		Film_manage(); 		
	}
	else if(x!=1 && x!=2 && x!=3)
	{
		printf("\t\t\t\t  ����δ�����壬��������أ�");
		getch();
		Film_manage(); 
	}
	if(l==0)
	{
		printf("\t\t\t\t  �õ�Ӱδ��¼�룡\n\t\t\t\t  ����������ϲ�"); 
		getch();
		Film_manage();
	}
	printf("\t\t\t\t  ������ɣ�����������ϲ㣡");
	getch();
	Film_manage();
} 
main()
{ 
	system("color 3F");
	enter0();
}

