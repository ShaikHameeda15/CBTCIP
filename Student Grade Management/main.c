#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Student{
    int rno;
    char name[30];
        struct subject{
        char subjectName[20];
        int grade;
            }sub[3];
    int total;
    float average;

    }Student;

void addStudent(){
    char askAdd;
    Student *s;
    FILE *fp;
    int num, i,j;

    cls();
    do{
     cls();

    printf("\n\n\t\t\t\t***************************************************************");
    printf("\n\t\t\t\t\t\tA D D  S T U D E N T / S");
    printf("\n\t\t\t\t***************************************************************");
    printf("\n\t\t\t\tHow many students you want to record? \t");
    scanf("%d", &num);

    s = (Student*)calloc(num, sizeof(Student));

    fp= fopen("records.txt", "a");

    if(fp == NULL)
        {fp = fopen("Services.txt", "w"); }
        for (i=0; i<num; i++){
        s[i].total = 0;
        s[i].average = 0;

        printf("\n\t\t\t\tEnter ID number : \t");
        scanf("%d", &s[i]);
        fflush(stdin);

        printf("\n\t\t\t\tEnter name :\t ");
        scanf("%[^\n]s",s[i].name);

        if  (isdigit(&s[i].name))
        {
            printf("error");
        }
        else{
            printf("\n\n\t\t\t\t***************************************************************");
            printf("\n\t\t\t\tSubject1 = MATHEMATICS\tSubject2= PHYSICS\tSubject3=CHEMISTRY");
            printf("\n\t\t\t\t***************************************************************");

        for(j=0;j<3;j++){
            printf("\n\t\t\t\tEnter grade in Subject%d : \t", j+1);
            scanf("%d", &s[i].sub[j].grade);
            s[i].total+= s[i].sub[j].grade;
            }

            s[i].average=s[i].total/3.0;

            fwrite (&s[i], sizeof(Student),1,fp);
            }}

            do{
                printf("\n\n\n\t\t\t\tAdd another stududent/s? (Y/N)? : \t");
                scanf(" %c", &askAdd);
                cls();
                askAdd=toupper(askAdd);
                if(askAdd!='Y'&&askAdd!='N')
                    printf("\n\n\n\t\t\t\t***************************************************************");
                    printf("\n\t\t\t\t\t\tI n v a l i d   r e s p o n s e!");
                    printf("\n\t\t\t\t***************************************************************");



        }while(askAdd!='Y'&&askAdd!='N');
        }while(askAdd=='Y');


    fclose(fp);


    }

void openRecords(){
    Student s1;
    FILE *fp;
    int j;
    cls();
  fp=fopen("records.txt", "r");
    printf("\n\t\t\t\t***************************************************************");
    printf("\n\t\t\t\t\tL I S T   O F   S T U D E N T ' S   R E C O R D S");
    printf("\n\t\t\t\t***************************************************************");
    printf("\n\t\t\t\tID NO.\tNAME\t\tMATHEMATICS   PHYSICS   CHEMISTRY\t AVERAGE");
    printf("\n\t\t\t\t================================================================");


    //while loop
    while (fread(&s1, sizeof(Student),1,fp))
    {
    printf("\n\t\t\t\t%-5d\t%-20s",s1.rno,s1.name );

        for (j=0; j<3; j++){
        printf("%4d\t", s1.sub[j].grade);}
        printf("%7.2f",s1.average);
    }

    printf("\n\n\n\t\t\t\t\t\t      Press any key to go back to Mainmenu.......");
    getch();

    fclose(fp);

}
void editRecords(){

    Student s1;
    FILE *fp,*fp1;
    int j, rno, found=0;
    char askEdit;

    do{
    fp=fopen("records.txt","r");
    fp1=fopen("newrecords.txt","w");


    cls();

    //Printing the screen layout
    printf("\n\n\n\t\t\t\t***************************************************************");
    printf("\n\t\t\t\t  E D I T   L I S T   O F   S T U D E N T ' S   R E C O R D S");
    printf("\n\t\t\t\t***************************************************************");

    printf("\n\n\n\t\t\t\tEnter ID number to edit:  ");
    scanf("%d", &rno);

    while(fread(&s1, sizeof (Student),1,fp))
    {
    if (s1.rno==rno){
    s1.total =0;
    s1.average=0;
    found=1;
    fflush(stdin);
    printf("\n\n\n\t\t\t\tEnter NEW name : ");
    scanf("%[^\n]s",s1.name);
     for(j=0;j<3;j++)
        {
        printf("\n\n\n\t\t\t\tEnter NEW grade in Subject%d : ", j+1);
        scanf("%d", &s1.sub[j].grade);
        s1.total+= s1.sub[j].grade;
        }
        s1.average=s1.total/3.0;
    }
        fwrite(&s1,sizeof (Student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (found){
        fp1= fopen("newrecords.txt","r");
        fp = fopen("records.txt","w");

        while(fread(&s1,sizeof(Student),1,fp1)){
            fwrite(&s1,sizeof(Student),1,fp);}

        fclose(fp);
        fclose(fp1);
        cls();
        printf("\n\n\n\t\t\t\t***************************************************************");
       printf("\n\t\t\t\t\t\tRecord successfully updated!");
       printf("\n\t\t\t\t***************************************************************");
       getch();
    }
    else
        cls();
    cls();
       printf("\n\n\n\t\t\t\t***************************************************************");
       printf("\n\t\t\t\t\t\tCheck your ID number....");
       printf("\n\t\t\t\t***************************************************************");


        do{
            printf("\n\n\n\t\t\t\tEdit stududent's record? (Y/N)? : \t");
            scanf(" %c", &askEdit);
            cls();
            askEdit=toupper(askEdit);
            if(askEdit!='Y'&&askEdit!='N')
                printf("\n\n\n\t\t\t\t***************************************************************");
                printf("\n\t\t\t\t\t\tI n v a l i d   r e s p o n s e!");
                printf("\n\t\t\t\t***************************************************************");




        }while(askEdit!='Y'&&askEdit!='N');
        }while(askEdit=='Y');





         }





void deleteRecord(){
Student s1;
FILE *fp,*fp1;
int j, rno, found=0;
char askDelete;
do{
    fp=fopen("records.txt","r");
    fp1=fopen("newrecords.txt","w");


    cls();

    printf("\n\n\n\t\t\t\t***************************************************************");
    printf("\n\t\t\t\t  D E L E T E   L I S T   O F   S T U D E N T ' S   R E C O R D S");
    printf("\n\t\t\t\t***************************************************************");

    printf("\n\n\n\t\t\t\tEnter ID number to delete:  ");
    scanf("%d", &rno);


    while(fread(&s1, sizeof (Student),1,fp))
    {
    if (s1.rno==rno){

    found=1;
    }
    else
        fwrite(&s1,sizeof (Student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (found){
        fp1= fopen("newrecords.txt","r");
        fp = fopen("records.txt","w");

        while(fread(&s1,sizeof(Student),1,fp1)){
            fwrite(&s1,sizeof(Student),1,fp);}

        fclose(fp);
        fclose(fp1);


        cls();
        printf("\n\n\n\t\t\t\t***************************************************************");
       printf("\n\t\t\t\t\t\tRecord successfully deleted!");
       printf("\n\t\t\t\t***************************************************************");
       getch();
       cls();
    }
    else
        cls();
       printf("\n\n\n\n\t\t\t\t***************************************************************");
        printf("\n\t\t\t\t\t\tCheck your ID number....");
       printf("\n\t\t\t\t***************************************************************");



  do{
            printf("\n\n\n\t\t\t\tDelete student's record? (Y/N)? : \t");
            scanf(" %c", &askDelete);
            cls();
            askDelete=toupper(askDelete);
            if(askDelete!='Y'&&askDelete!='N')
                printf("\n\n\n\t\t\t\t***************************************************************");
                printf("\n\t\t\t\t\t\tI n v a l i d   r e s p o n s e!");
                printf("\n\t\t\t\t***************************************************************");




        }while(askDelete!='Y'&&askDelete!='N');
        }while(askDelete=='Y');


         }

void fileRecord(){
Student *s, s1;
FILE *fp, *fp2;
int i,j;

cls();
fp= fopen("records.txt", "r");
fseek(fp,0,SEEK_END);
int n= ftell(fp)/sizeof(Student);
s=(Student*)calloc(n,sizeof(Student));

rewind(fp);
for(i=0;i<n;i++)
    fread(&s[i], sizeof(Student),1,fp);
fclose(fp);
    for (i=0;i<n; i++){
        for(j=i+1;j<n; j++){
            if(s[i].total<s[j].total){
                s1=s[i];
                s[i]=s[j];
                s[j]=s1;
        }
    }
}
fp2=fopen("finalrecords.txt","w");
fp=fopen("records.txt","w+");

    printf("\n\t\t\t\t***************************************************************");
    printf("\n\t\t\t\tL I S T   O F   S T U D E N T ' S   R E C O R D S   I N   F I L E ");
    printf("\n\t\t\t\t***************************************************************");
    printf("\n\t\t\t\tID NO.\tNAME\t\tMATHEMATICS   PHYSICS   CHEMISTRY\t AVERAGE");
    printf("\n\t\t\t\t================================================================");


    fprintf(fp2,"\n\t\t***************************************************************");
    fprintf(fp2,"\n\t\tL I S T   O F   S T U D E N T ' S   R E C O R D S   I N   F I L E ");
    fprintf(fp2,"\n\t\t***************************************************************");
    fprintf(fp2,"\n\t\tID NO.\tNAME\t\tMATHEMATICS   PHYSICS   CHEMISTRY\t AVERAGE");
    fprintf(fp2,"\n\t\t================================================================");





    for (i=0; i<n;i++){
    printf("\n\t\t\t\t%-5d\t%-20s",s[i].rno,s[i].name);

    fprintf(fp2, "\n\t\t%-5d\t%s\t\t", s[i].rno,s[i].name);

        for (j=0;j<3;j++){
           printf("%4d\t",s[i].sub[j].grade);
     fprintf(fp2, " %d\t ",s[i].sub[j].grade);

           }
        printf("%7.2f",s[i].average);
    fprintf(fp2, "\t%7.2f", s[i].average);
    fprintf(fp2, "\n");

         fwrite(&s[i],sizeof(Student),1,fp);

        }
    fclose(fp);

        fclose(fp2);
        printf("\n\n\n\n\t\t\t\tPress any key to go back to Mainmenu.......");
 getch();

}
void cls(){
    system("cls");
}

int main()
{   system("COLOR F2");
    cls();
    int mainmenu;


    printf("\n\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t*************************************************************");

        printf("\n\n\t\t\t\t\t\t""STUDENT GRADE MANAGEMENT"" ");

        printf("\n\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tPress any key........");
        getch();

cls();

    do{ cls();

        printf("\n\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t*************************************************************");
        printf("\n\n\t\t\t\t\t\t\tM A I N  M E N U\n");
        printf("\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t1.) \tADD STUDENT\n");
        printf("\n\t\t\t\t2.) \tOPEN RECORDS\n");
        printf("\n\t\t\t\t3.) \tEDIT RECORDS\n");
        printf("\n\t\t\t\t4.) \tDELETE RECORDS\n");
        printf("\n\t\t\t\t5.) \tFILE RECORD\n");
        printf("\n\t\t\t\t6.) \tEXIT \n");
        printf("\n\n\t\t\t\tEnter a number: \t");
        scanf("%d", &mainmenu);

        switch(mainmenu){
            case 1:
                addStudent();
                break;
            case 2:
                openRecords();
                break;
            case 3:
                editRecords();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                fileRecord();
                break;
            case 6:
                exit(1);
            default:
                printf("\n\t\t\t\tInput must be from 1-6 only!");
                getch();
                break;
        }
    }while(mainmenu !=0);

}
