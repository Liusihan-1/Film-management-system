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
	char release_data[20];                    /*上映时间*/
	float grade;                                /*评分*/
	char protagonist_name[20];               /*主人公名字*/
	int box_office;                            /*票房*/
	int fares;                                 /*票价*/ 
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
void enter0();                           /*登陆界面*/
void Vis_window();                      /*游客界面*/
void Adm_window();                     /*管理员界面*/
void Adm_add();                        /*管理员录入*/
void Adm_change();                     /*管理员修改*/ 
void Adm_load();                      /*管理员登录 1*/  
void Adm_manage();                  /*管理员管理界面 2*/  
void Film_add();                        /*电影增添*/
void Film_find();                       /*电影查询*/
void Film_buy();                        /*电影票购买*/
void Film_change();                   /*电影信息更改*/ 
void Sale_window();
//void Vip_enter();                     /*会员信息录入*/ 
//int Vip_stat();                       /*会员数统计*/ 
//void Vip_find();                      /*会员信息查询 */
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
	printf("\t\t\t\t **************  欢迎来到电影俱乐部   *************\n");
	printf("\n");
	printf("\t\t\t\t **************     程序主界面      ***************\n");
	printf("\n");
	printf("\t\t\t\t *************     1.管理员界面      **************\n");
	printf("\n");
	printf("\t\t\t\t *************      2.游客界面      ***************\n");
	printf("\n");
	printf("\t\t\t\t *****************    3.退出   ********************\n");
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
		    printf("\t\t\t\t  未被定义，按任意键返回当前\n");
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
	printf("\t\t\t\t ****************    观影者界面    ****************\n");
	printf("\n");
	printf("\t\t\t\t *****************   1.查找电影   *****************\n");
	printf("\n");
	printf("\t\t\t\t ****************   2.购买电影票   ****************\n");
	printf("\n");
	printf("\t\t\t\t *****************   3.返回上层  ******************\n"); 
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
			printf("\t\t\t\t  未被定义，按任意键返回当前\n");
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
	printf("\t\t\t\t ****************    管理员界面    ****************\n");
	printf("\n");
	printf("\t\t\t\t *****************  1.管理员录入  *****************\n");
	printf("\n");
	printf("\t\t\t\t ****************   2.管理员修改  *****************\n");
	printf("\n");
	printf("\t\t\t\t ****************   3.管理员登录  *****************\n"); 
	printf("\n");
	printf("\t\t\t\t ****************   4.返回上一层   ****************\n");
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
			printf("\t\t\t\t  未被定义，按任意键返回当前\n");
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
	printf("\t\t\t\t  输入管理员名:");
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
					printf("\t\t\t\t  已存在该管理员，无需重复录入！\n");
					printf("\t\t\t\t  任意键返回上层！");
					getch();
					fclose(fp);
					enter0(); 
				}
			}
		}
	}
	fp = fopen("Adm_list.txt","a");
	printf("\t\t\t\t  输入密码:"); 
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
	printf("\n\t\t\t\t  请再次输入密码:");
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
		printf("\n\t\t\t\t  录入成功，请按任意键返回上层！");
	}
	else
	{
		printf("\n\t\t\t\t  录入失败，密码不一致，请按任意键返回上层:");		
	}
	getch(); 
	fclose(fp);
	enter0(); 
}
void Film_manage()
{
	system("cls");
	int x1;
	printf("\t\t\t\t  ****************电影管理界面**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ***********     1.电影添加   *************\n");
	printf("\n");
	printf("\t\t\t\t  ***********     2.电影查询   *************\n");
	printf("\n");
	printf("\t\t\t\t  ***********     3.电影修改   *************\n");
	printf("\n");
	printf("\t\t\t\t  ***********    4.电影票购买   ************\n");
	printf("\n");
	printf("\t\t\t\t  **************    4.退出    **************\n");
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
		    printf("\t\t\t\t  未被定义，按任意键返回上层\n") ;
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
		printf("\t\t\t\t  尚未创建管理员，任意键创建并录入.");
		Adm_add();
	 } 
	printf("\t\t\t\t  输入登录管理员名称:");
	scanf("%s",name0);
	while(!feof(fp))
	{
		fscanf(fp, " %s %s\n",name,password);
		if (!strcmp(name,name0))
		{
			flag = 1;
			printf("\t\t\t\t  输入密码:");
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
				printf("\n\t\t\t\t  密码错误，任意键返回上层:");
				getch(); 
				enter0();
				break;
			}
		}
	}
	if (flag==0)
	{
		printf("\t\t\t\t  该管理员未录入，请按任意键返回上层！");
		getch();
		enter0(); 
	}
}
void Adm_change() 
{
	system("cls");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ***************管理员修改界面*************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  *************   1.管理员删除   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **************   2.密码修改   ************\n");
	printf("\n");
	printf("\t\t\t\t  **************   3.返回上层   ************\n");
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
		printf("\t\t\t\t  不存在管理员！\n\t\t\t\t  请按任意键返回上层");
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
		printf("\t\t\t\t  要更改的管理员姓名为:");
		scanf("%s",name);
		while(p2)
		{
			m=0;
			if(!strcmp(p2->name,name))
			{
				l=1;
				printf("\t\t\t\t  是否删除该管理员？\n");
				printf("\t\t\t\t  回车删除，任意键返回！");
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
		printf("\t\t\t\t  要更改的管理员姓名为:");
		scanf("%s",name);
		while(p2)
		{
			l=1;
			printf("\n\t\t\t\t  存在该管理员，继续输入将覆盖原密码");
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
		printf("\n\t\t\t\t  该管理员未被录入！\n\t\t\t\t  任意键返回上层"); 
		getch();
		enter0();
	}
	printf("\n\t\t\t\t  操作完成，任意键返回上层！");
	getch();
	enter0();
}
void Sale_system() 
{
	system("cls");
	int x4;
	printf("\t\t\t\t  ****************销售管理界面**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ***********    1.使用记录     ************\n");
	printf("\n");
	printf("\t\t\t\t  ***********  2.销售产品排序    ***********\n");
	printf("\n");
	printf("\t\t\t\t  ***********    3.返回上层    *************\n");
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
		    printf("\n\t\t\t\t  未被定义，按任意键返回上层\n") ;
		    getch();
			system("cls"); 
			Adm_manage();
	}
}
void Adm_manage()
{
	system("cls");
	int x1;
	printf("\t\t\t\t  **************管理员管理界面***************\n");
	printf("\n");
	printf("\t\t\t\t  *******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ************     1.电影管理     ***********\n");
	printf("\n");
	printf("\t\t\t\t  ************     2.会员管理     ***********\n");
	printf("\n");
	printf("\t\t\t\t  ************     3.售卖系统     ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********       4.返回上层     ***********\n");
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
		    printf("\t\t\t\t  未被定义，按任意键返回上层\n") ;
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
		printf("\n\t\t\t\t  暂无电影可销售，任意键返回！");
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
	printf("\t\t\t\t  输入欲购买电影编号、票价、主人公名字或上映日期：（也可输入电影名字或主人公名字关键字）");
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
		printf("\t\t\t\t  查无此服装类型，请重新输入查找条件：");
		getch();
		Sale_window(); 
	}
	p2 = head->next;
	while(p2)
	{
		i=0;
		if(!strcmp(p2->film_name,key) || !strcmp(p2->protagonist_name,key) || strstr(p2->film_name,key) ||atoi(key) == p2->number)
		{
			printf("\t\t\t\t  该电影信息为：\n\t\t\t\t  编号      日期		主人公名字      电影名字      票价\n");
			printf("\t\t\t\t  %-10d%-15s%-10s%-10s%-10%-10d\n",&p2->number,&p2->release_data,&p2->protagonist_name,&p2->film_name,&p2->fares,&amount);
			printf("\t\t\t\t  是否购买？\n\t\t\t\t  回车购买，任意键继续检索该编号、名称、票价或日期的电影!\n");
			j = getch();
			if(j==13)		
			{
				i=1;
				printf("\t\t\t\t  输入购买数量：");
				scanf("%d",&many);
				p2->amount = p2->amount-many;
				while(p2->amount<0)
				{
					printf("\t\t\t\t  库存不足，请减少购买数量");
					p2->amount = p2->amount+many;
					scanf("%d",&many);
					if(p2->amount-many<0)
					{
						printf("\t\t\t\t  不好意思，该电影票暂无。\n\t\t\t\t  将返回上层！");
						getch();
						Sale_window(); 
						break;
					}
					p2->amount = p2->amount-many;
				}
				money = many*p2->fares; 
				fprintf(fp2," %d %s %s %s %s %.2f %d\n",p2->number,p2->film_name,p2->protagonist_name,p2->release_data,money,many);	
				printf("\t\t\t\t  是否使用会员进行积分？\n\t\t\t\t  回车使用，任意键跳过.");
				j = getch();
				{
					if(j==13)
					{
						printf("\n\t\t\t\t  输入电话号码："); 
						scanf("%s",key);
						//Vip_use(key,money);
					}
				} 		
			}		 
		}
		fprintf(fp1," %d %s %s %d %.2f %d\n",p2->number,p2->film_name,p2->protagonist_name,p2->release_data,p2->fares,p2->grade,p2->amount);
		if(p2->next==NULL)
		{
			printf("\n\t\t\t\t  检索完毕，无更多相关信息，\n\n\t\t\t\t  回车重新进行购买，任意键返回！\n\t\t\t\t  "); 
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
	printf("\t\t\t\t  请按照以下格式录入电影信息：\n");
	while(i==13)
	{
		p2 = (list1)malloc(sizeof(struct film));
		printf("\t\t\t\t   名称     上映时间     评分     主人公     票价\n\t\t\t\t  ");
		scanf("%s %s %s %s %f %d",&p2->film_name,&p2->release_data,&p2->grade,&p2->protagonist_name,&p2->fares);
		p2->number = n;
		p1->next = p2;
		p2->next = NULL;
		p1 = p2; 
		printf("\t\t\t\t  是否继续输入?回车继续输入，任意键返回上层！\n");
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
		printf("\t\t\t\t  无电影目录，请按任意键返回！");
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
	printf("\t\t\t\t  输入查询条件，可选择 名字 主人公 票价 时间或者关键字\n\t\t\t\t  ");
	scanf("%s",key1);
	Film_manage(); 
} 
void Film_change()
{
	system("cls");
	printf("\t\t\t\t  *****************电影修改界面**************\n");
	printf("\n");
	printf("\t\t\t\t  *******************************************\n"); 
	printf("\n");
	printf("\t\t\t\t  ***********     1、电影删除     ***********\n");
	printf("\n"); 
	printf("\t\t\t\t  **********    2、电影数据修改     *********\n");
	printf("\n");
	printf("\t\t\t\t  ***********     3、返回上层     ***********\n");
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
		printf("\t\t\t\t  要更改的电影名称为:");
		printf("\t\t\t\t  返回上层查找相关信息 \n回车返回上层，任意键继续！");
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
				printf("\t\t\t\t  是否删除该电影相关信息？\n");
				printf("\t\t\t\t  回车删除，请按任意键返回！");
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
		printf("\t\t\t\t  要更改的电影名称为:");
		printf("\t\t\t\t  如果遗忘相关信息可先返回上层查找！\n回车返回上层，任意键继续！");
		i = getch();
		if (i==13) Film_manage();
		scanf("%s",key);
		while(p2)
		{
			if(!strcmp(p2->film_name,key))
			{
				l=1;
				printf("\t\t\t\t  目前该电影信息为：\n");
				printf("\t\t\t\t    编号    票价    主人公名字     日期     电影名称\n");
				printf("\t\t\t\t    %-10d %-10d %-10s %-10s %-10s %-10d\n",p2->number,p2->fares,p2->protagonist_name,p2->release_data,p2->film_name);
				printf("\n\t\t\t\t  存在该电影，输入欲更改的条目编号\n");
				printf("\t\t\t\t  ps:其中 价格只能输入数字，总数只能输入整形数字\n");
				printf("\t\t\t\t  可改条目有1.票价 2.主人公名字 3.日期 4.电影名称\n");
				scanf("%d",&y);
				printf("\t\t\t\t  输入改后数据：");
				scanf("%s",key);
				switch(y)
				{
					case 1:
						y = atoi(key);
						printf("\t\t\t\t  数据变化为%d -> %d",p2->fares,y);
						p2->fares = y;
						break;
					case 2:
						printf("\t\t\t\t  数据变化为%s -> %s",p2->protagonist_name,key);
						strcpy(p2->protagonist_name,key);
						break;
					case 3:
						printf("\t\t\t\t  数据变化为%s -> %s",p2->release_data,key);
						strcpy(p2->release_data,key);
						break;
					case 4:
						printf("\t\t\t\t  数据变化为%s -> %s",p2->film_name,key);
						strcpy(p2->film_name,key);
						break;
					default :
					    printf("\t\t\t\t  未被定义，按任意键返回上层\n") ;
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
		printf("\t\t\t\t  操作未被定义，任意键返回！");
		getch();
		Film_manage(); 
	}
	if(l==0)
	{
		printf("\t\t\t\t  该电影未被录入！\n\t\t\t\t  任意键返回上层"); 
		getch();
		Film_manage();
	}
	printf("\t\t\t\t  操作完成，任意键返回上层！");
	getch();
	Film_manage();
} 
main()
{ 
	system("color 3F");
	enter0();
}

