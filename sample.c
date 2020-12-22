#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<errno.h>
#include<unistd.h>

struct User
{
	char name[25];
	char blood_group[3];
	char gender;
	char phone_number[10];
	char add[100];
};//Donor,Donee



void AddDonor();
void DoneeDetails();
void SearchDonor(char blood_group[3]);
void DisplayDetails(int line);
void DeleteRecord(int line);
int CheckPhoneNumber(char num[10]);

int main()
{
	system("cls");
	system("color 4e");
	int opt;
	char blood_group[3];
	printf("\n\t\t\t=======================================");
	printf("\n\t\t\t=======================================");
	printf("\n\t\t\t|  WELCOME TO PLASMA DONATING SYSTEM  |");
	printf("\n\t\t\t=======================================");
	printf("\n\t\t\t=======================================");
	printf("\n\n");
	//System(clr);
	printf("\n\t\t                          *");
	printf("\n\t\t                         ***");
	printf("\n\t\t                        *****");
	printf("\n\t\t                       *******");
	printf("\n\t\t                      *********");
	printf("\n\t\t                     ***********");
	printf("\n\t\t                    *************");
	printf("\n\t\t                   ***************");
	printf("\n\t\t                  *****************");
	printf("\n\t\t                   ***************");
	printf("\n\t\t                    *************");
	printf("\n\t\t                     ***********");
	printf("\n\t\t                       *******\n");
	system("pause");
	system("cls");
	system("color 2e");
	printf("\t\tAre u a Donor or Donee?\n\t\tIf Donor enter 1 or If Donee enter 2 : ");
	scanf("\t\t%d",&opt);
	system("pause");
	system("cls");
	system("color 3e");
	if(opt==1)
	{
		char ans[3],c,check;
		int wgt;
		printf("\n\n");
		printf("\n\n\n\t\tPlease answer some Elgibilty Questions :-\n");
		printf("\n\n\t\tIs your age is between 18 to 65 years?\n\t\tEnter y-yes / n-no :");
		scanf(" %c",&ans[0]);
		printf("\n\t\tAre you a woman or men?\n\t\tEnter w-women / m-men : ");
		scanf(" %c",&check);
		if(toupper(check)=='W')
		{
			char c;
			printf("\n\t\tIf you are married, do you have kids or you are pregnant? (Enter n-no if you are unmarried)\n\t\tEnter y-yes / n-no : ");
			scanf(" %c",&c);
			if(toupper(c)=='Y')
			{
				goto line1;
			}
			ans[1]='y';
		}
		if(toupper(check)=='M')
		{
			ans[1]='y';
		}
		printf("\n\t\tDid you tested -ve for the virus atleast 14 days from now? \n\t\tEnter y-yes / n-no : ");
		scanf(" %c",&ans[2]);
		printf("\n\t\tEnter your weight in kgs : ");
		scanf("%d",&wgt);
		int val=1;
		for( int i=0;i<3;i++)
		{
			if(ans[i]=='y')
				continue;
			else
				val=0;
				break;
		}
		if(val==1 && wgt>=55)
		{
			
			//AddDonor
			printf("\n\n\t\t*****************************************");
			printf("\n\t\t| YOU ARE ELIGIBLE TO DONATE PLASMA!!!! |");
			printf("\n\t\t*****************************************\n");
			system("pause");
			system("cls");
			system("color 4e");
			printf("\n\t\tENTER YOUR DETAILS :-\n\n");
			AddDonor();
			printf("\n\n\n\n\n\t\t=======================================================");
			printf("\n\t\t---------------THANK YOU FOR REGISTERING---------------");
			printf("\n\t\t=======================================================");
			
		}
		else
		{
			line1:printf("\n\t\t-----------------------------------------------------");
			printf("\n\t\t-----------------------------------------------------");
			printf("\n\t\t| SORRY, YOU ARE NOT ELIGIBLE FOR DONATING PLASMA!! |");
			printf("\n\t\t-----------------------------------------------------");
			printf("\n\t\t-----------------------------------------------------");
		}
	}	
	else if(opt==2)
	{
		DoneeDetails();
	}
	return 0;
}



void AddDonor()
{
	struct User d;
	FILE *fptr=fopen("Donor.txt","a");
	fflush(stdin);
	printf("\n\t\tYOUR BLOOD GROUP(Eg : AB+) : ");
	gets(d.blood_group);
	/*char bg[3];
	strcpy(bg,d.blood_group);
	
	while(strupr(bg)!="O+" || strupr(bg)!="O-" || strupr(bg)!="A+" || strupr(bg)!="A-" || strupr(bg)!="B+" || strupr(bg)!="B-" || strupr(bg)!="AB+" || strupr(bg)!="AB-")
	{
		if(strupr(bg)=="O+" || strupr(bg)=="O-" || strupr(bg)=="A+" || strupr(bg)=="A-" || strupr(bg)=="B+" || strupr(bg)=="B-" || strupr(bg)=="AB+" || strupr(bg)=="AB-")
		{
			break;
		}
		printf("first----%s...",strupr(bg));
		printf("\n\t\tYOUR BLOOD GROUP(Eg : AB+) : ");
		gets(d.blood_group);
		strcpy(bg,d.blood_group);
		printf("second----%s...",strupr(bg));
	}*/
	if(strlen(d.blood_group)==3)
		fprintf(fptr,"%c%c%c ",toupper(d.blood_group[0]),toupper(d.blood_group[1]),d.blood_group[2]);
	else if(strlen(d.blood_group)==2)
		fprintf(fptr,"%c%c  ",toupper(d.blood_group[0]),d.blood_group[1]);
	
	printf("\n\t\tYOUR FULLNAME : ");
	gets(d.name);
	fprintf(fptr,"%s ",d.name);
	for(int i=1;i<=25-strlen(d.name);i++)
	{
		fprintf(fptr," ");
	}
	printf("\n\t\tYOUR GENDER(M-Male or F-Female) : ");
	scanf("%c",&(d.gender));
	/*while(toupper(d.gender)!='M' || toupper(d.gender)!='F')
	{
		printf("\n\t\tYOUR GENDER(M-Male or F-Female) : ");
		scanf("%c",&(d.gender));
	}*/
	fprintf(fptr,"%c ",d.gender);
	fflush(stdin);
	printf("\n\t\tYOUR ADDRESS : ");
	gets(d.add);
	fprintf(fptr,"%s ",d.add);
	for(int i=0;i<100-strlen(d.add);i++)
	{
		fprintf(fptr," ");
	}
	line:printf("\n\t\tYOUR PHONE NUMBER : ");
	fflush(stdin);
	scanf("%s",d.phone_number);
	if(CheckPhoneNumber(d.phone_number))
		fprintf(fptr,"%s\n",d.phone_number);
	else
	{
		printf("\t\tENTER CORRECT PHONE NUMBER!!!!");
		goto line;
	}
	fclose(fptr);
}

int CheckPhoneNumber(char num[10])
{
	//printf("Yes");
	if(strlen(num)!=10)
	{
		return 0;
	}
	int i=0;
	while(i<10)
	{
		if(isdigit(num[i]))
		{
			i++;
			continue;
		}
		else
			return 0;
		
	}
	if(num[0]=='9' || num[0]=='8' || num[0]=='7' || num[0]=='6')
	{
		return 1;
	}
	return 0;
}


void DoneeDetails()
{
	struct User d;
	FILE *fptr=fopen("Donee.txt","a");
	fflush(stdin);
	printf("\n\t\tENTER YOUR DETAILS :-\n");
	printf("\n\t\tYOUR BLOOD GROUP(Eg : AB+) : ");
	gets(d.blood_group);
	/*char bg[3];
	bg[0]=toupper(d.blood_group[0]);
	bg[1]=toupper(d.blood_group[1]);
	bg[2]=toupper(d.blood_group[2]);
	while(bg!="O+" || bg!="O-" || bg!="A+" || bg!="A-" || bg!="B+" || bg!="B-" || bg!="AB+" || bg!="AB-")
	{
		printf("\n\t\tYOUR BLOOD GROUP(Eg : AB+) : ");
		gets(d.blood_group);
		char bg[3];
		bg[0]=toupper(d.blood_group[0]);
		bg[1]=toupper(d.blood_group[1]);
		bg[2]=toupper(d.blood_group[2]);
	}*/

	if(strlen(d.blood_group)==3)
		fprintf(fptr,"%c%c%c ",toupper(d.blood_group[0]),toupper(d.blood_group[1]),d.blood_group[2]);
	else if(strlen(d.blood_group)==2)
		fprintf(fptr,"%c%c  ",toupper(d.blood_group[0]),d.blood_group[1]);
	
	printf("\n\t\tYOUR FULLNAME : ");
	gets(d.name);
	fprintf(fptr,"%s ",d.name);
	for(int i=1;i<=25-strlen(d.name);i++)
	{
		fprintf(fptr," ");
	}
	printf("\n\t\tYOUR GENDER(M-Male or F-Female) : ");
	scanf("%c",&(d.gender));
	/*while(toupper(d.gender)!='M' || toupper(d.gender)!='F')
	{
		printf("\n\t\tYOUR GENDER(M-Male or F-Female) : ");
		scanf("%c",&(d.gender));
	}*/

	fprintf(fptr,"%c ",d.gender);
	fflush(stdin);
	printf("\n\t\tYOUR ADDRESS : ");
	gets(d.add);
	fprintf(fptr,"%s\n",d.add);
	for(int i=0;i<100-strlen(d.add);i++)
	{
		fprintf(fptr," ");
	}
	line:printf("\n\t\tYOUR PHONE NUMBER : ");
	fflush(stdin);
	scanf("%s",d.phone_number);
	if(CheckPhoneNumber(d.phone_number))
		fprintf(fptr,"%s\n",d.phone_number);
	else
	{
		printf("\t\tEnter correct phone number!!!!\n");
		goto line;
	}
	fclose(fptr);
	SearchDonor(d.blood_group);
	//return d.blood_group;
}
	
void SearchDonor(char blood_group[3])
{
	system("pause");
	system("cls");
	system("color 6e");
	FILE *fptr=fopen("Donor.txt","r");
	char str[2],ch,c;
	int line=1;
	while((ch=getc(fptr))!=EOF)
	{
		
		fscanf(fptr,"%s",str);
		if(ch=='O' && str[0]=='-')
		{
			printf("\n\t\tFOUND THE MATCH!!!");
			printf("\n\n\t\tDETAILS : \n");
			DisplayDetails(line);
			break;
		}
		else if(ch=='O' && str[0]=='+')
		{
			if(blood_group[1]=='+' || blood_group[2]=='+')
			{
				printf("\n\t\tFOUND THE MATCH!!!");
				printf("\n\n\t\tDETAILS : \n");
				DisplayDetails(line);
				break;
			}
		}
		else if(ch=='A' && str[0]=='-')
		{
			if(blood_group[0]=='A')
			{
				printf("\n\t\tFOUND THE MATCH!!!");
				printf("\n\n\t\tDETAILS : \n");
				DisplayDetails(line);
				break;
			}
		}
		else if(ch=='A' && str[0]=='+')
		{
			if((blood_group[1]=='+' || blood_group[2]=='+') && blood_group[0]=='A' )
			{
				printf("\n\t\tFOUND THE MATCH!!!");
				printf("\n\n\t\tDETAILS : \n");
				DisplayDetails(line);
				break;
			}
		}
		else if(ch=='B' && str[0]=='-')
		{
			if(blood_group=="B+" || blood_group=="AB+" || blood_group=="AB-" || blood_group=="B-")
			{
				printf("\n\t\tFOUND THE MATCH!!!");
				printf("\n\n\t\tDETAILS : \n");
				DisplayDetails(line);
				break;
			}
		}
		else if(ch=='B' && str[0]=='+')
		{
			if(blood_group=="AB+" || blood_group=="B+")
			{
				printf("\n\t\tFOUND THE MATCH!!!");
				printf("\n\n\t\tDETAILS : \n");
				DisplayDetails(line);
				break;
			}
		}
		else if(ch=='A' && str=="B-")
		{
			if(blood_group=="AB+" || blood_group=="AB-")
			{
				printf("\n\t\tFOUND THE MATCH!!!");
				printf("\n\n\t\tDETAILS : \n");
				DisplayDetails(line);
				break;
			}
		}
		else if(ch=='A' && str=="B+")
		{
			if(blood_group=="AB+")
			{
				printf("\n\t\tFOUND THE MATCH!!!");
				printf("\n\n\t\tDETAILS : \n");
				DisplayDetails(line);
				break;
			}
		}
		c=getc(fptr);
		while(c!='\n')
		{
			if(c==EOF)
				break;
			c=getc(fptr);
		}
		line++;
		if(c==EOF)
			break;
	}
	if(ch==EOF || c==EOF)
	{
		printf("\n\n\t\t=============================");
		printf("\n\t\tSORRY MATCH NOT FOUND :( !!!!");
		printf("\n\t\t============================="); 
	}
	fclose(fptr);
}


void DisplayDetails(int line)
{
	FILE *fptr=fopen("Donor.txt","r");
	char blood_group[3],name[25],gender,phone_number[10],add[50];
	int test=1;
	char ch,c;
	while((ch=getc(fptr))!=EOF)
	{
		if(test==line)
		{
			int i=1;
			printf("\n\t\tBLOOD GROUP : ");
			do{
				printf("%c",ch);
				ch=getc(fptr);
				i++;
			}while(i<=3);
			//ch=getc(fptr);
			printf("\n\t\tNAME : ");
			for(int i=0;i<25;i++)
			{
				ch=getc(fptr);
				printf("%c",ch);
			}
			ch=getc(fptr);
			ch=getc(fptr);
			printf("\n\t\tGENDER : %c",ch);
			ch=getc(fptr);
			printf("\n\t\tADDRESS : ");
			for(int i=0;i<100;i++)
			{
				ch=getc(fptr);
				printf("%c",ch);
			}
			ch=getc(fptr);
			printf("\n\t\tPHONE NUMBER : ");
			for(int i=0;i<10;i++)
			{
				ch=getc(fptr);
				printf("%c",ch);
			}
			DeleteRecord(line);
			break;
		}
		c=getc(fptr);
		while(c!='\n' && c!='\0')
		{
			c=getc(fptr);
		}
		test++;
	}
	fclose(fptr);
}
	
void DeleteRecord(int line)
{
	char c;
	int temp=1;
	FILE *fptr1=fopen("Donor.txt","r");
	FILE *fptr2=fopen("Temp.txt","w");
	c=getc(fptr1);
	if(line==1)
	{
		while(c!='\n')
		{
			c=getc(fptr1);
		}
		while((c=getc(fptr1))!=EOF)
		{
			putc(c,fptr2);
		}
	}
	else
	{
		
		if(temp!=line)
		{
			putc(c,fptr2);
		}		
		while(c!=EOF)
		{
			c=getc(fptr1);
			if(c=='\n')
			{
				temp++;
				
			}
			if(temp!=line)
			{
				putc(c,fptr2);
			}
		}
	}
	fclose(fptr1);
	fclose(fptr2);
	remove("Donor.txt");
	rename("temp.txt", "Donor.txt");
	printf("\n\t\tRECORD DELETED");
}	
				
