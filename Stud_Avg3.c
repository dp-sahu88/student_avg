//Author:DEADPOOL
//User@DEADPOOL
//Device name:LAPTOP-MGJPSU5N
//***************************
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
 //defining the student structure
    struct student {
    int std_roll;
    char std_name[40];
    float dm,toc,cn,avg;
    };
// isDuplicate checks the redundant data in roll no and returns 1 if redundancy found
int isDuplicate(struct student *std,int std_count,int new_roll){
    int i;
    if (std_count==0)
        return 0;
    for (i=0;i<std_count;i++){
        if (std[i].std_roll==new_roll ){
            return 1;
        }
    }
    return 0;
}

//isinteger() checks whether the entered data is an integer or not
int isinteger(char s[40]){
    int i;
    for (i=0;s[i]!='\0';i++)
        if (isdigit(s[i])==0)
            return 0;
    return 1;
}

//gotoxy() is a inbuilt function for turbo compiler but here I am going to define this explicitly .. because I'm using gcc compiler by GNU
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// this swap function will use to sort records according to roll no  or may be for other use ..

void swap (struct student *x,struct student *y){
    struct student z;
    z=(*x);
    *x=(*y);
    *y=z;
}
// this std_input function use to take records as input , all the required conditional check for record  is also done in here
void std_input(struct student *stdt,int std_count){

    //required variable declaration
    char str[40];
    int integer,flag,d_flag=0;

    //roll no. input
    roll:
        printf("\n\aEnter the roll no. of the student : ");
        system("color 7");
        fflush(stdin);
        scanf("%s",str);
        flag=isinteger(str);
        if (flag==1){
            integer= atoi(str);
            d_flag=0;
            d_flag=isDuplicate(stdt,std_count,integer);
            if (d_flag==1){
                printf("\n You have already entered this data..\n");
                goto roll;
            }
            stdt[std_count].std_roll=integer;
        }

        else{
           goto roll;
        }

        //name input
        printf("\n\a Enter the name of the student : ");
        system("color 2");
        fflush(stdin);
        scanf("%[^\n]%*c",stdt[std_count].std_name);

        //input for marks
        //input for DM
    dm:
        printf("\n\a Marks in DM : ");
        system("color 4");
        scanf("%s",str);
        flag=isinteger(str);
        if (flag==1){
            integer= atoi(str);
            if (integer>100)
                goto dm;
            stdt[std_count].dm=integer;
        }
        else
           goto dm;


        //input for TOC
    toc:
        printf("\n\a Marks in TOC : ");
        system("color 6");
        scanf("%s",str);
        flag=isinteger(str);
        if (flag==1){
            integer= atoi(str);
            if (integer>100)
                goto toc;
            stdt[std_count].toc=integer;
        }
        else
           goto toc;

        //input for CN
    cn:
        printf("\n\a Marks in CN : ");
        system("color 1");
        scanf("%s",str);
        flag=isinteger(str);
        if (flag==1){
            integer= atoi(str);
            if (integer>100)
                goto cn;
            stdt[std_count].cn=integer;
        }
        else
           goto cn;

        //stores the average mark of each student in the corresponding structure instance
        stdt[std_count].avg = stdt[std_count].dm+stdt[std_count].toc+stdt[std_count].cn/3;



        system("cls");
}


 // output_std() definition
 void std_output(struct student *std,int std_count){

        //variable declaration
        float total_dm=0,total_toc=0,total_cn=0,total_avg=0,total,total_tot=0;
        int i;
        //creating table
        system("color 5");
        printf("Roll|NAME__________________________|DM_______|TOC______|CN_______|TOTAL_______|AVERAGE_____|\n");//attributes

        //print all the records

        for (i =0;i<=(std_count-1);++i){
            gotoxy(0,1+(i*2));
            printf("%3d ",std[i].std_roll);
            gotoxy(4,1+(i*2));
            printf("|%s",std[i].std_name);
            gotoxy(35,1+(i*2));
            printf("|%0.2f",std[i].dm);
            gotoxy(45,1+(i*2));
            printf("|%0.2f",std[i].toc);
            gotoxy(55,1+(i*2));
            printf("|%0.2f",std[i].cn);
            total=std[i].dm+std[i].toc+std[i].cn;
            gotoxy(65,1+(i*2));
            printf("|%0.2f",total);
            gotoxy(78,1+(i*2));
            printf("|%0.2f/3 ",total);
            gotoxy(91,1+(i*2));
            printf("|");
            printf("\n____|______________________________|_________|_________|_________|____________|____________|");
            total_dm+=std[i].dm;
            total_cn+=std[i].cn;
            total_toc+=std[i].toc;
            total_tot+=total;
            total_avg+=std[i].avg;


          }
          // print total values
            printf("\n Total");
            gotoxy(35,1+(i*2));
            printf("|%0.2f",total_dm);
            gotoxy(45,1+(i*2));
            printf("|%0.2f",total_toc);
            gotoxy(55,1+(i*2));
            printf("|%0.2f",total_cn);
            gotoxy(65,1+(i*2));
            printf("|%0.2f",total_tot);
            gotoxy(78,1+(i*2));
            printf("|%0.2f",total_avg);
            gotoxy(91,1+(i*2));
            printf("|");
            printf("\n___________________________________|_________|_________|_________|____________|____________|");
            //print average values
            printf("\n Average");
            gotoxy(35,3+(i*2));
            printf("|%0.2f/%d",total_dm,std_count);
            gotoxy(45,3+(i*2));
            printf("|%0.2f/%d",total_toc,std_count);
            gotoxy(55,3+(i*2));
            printf("|%0.2f/%d",total_cn,std_count);
            gotoxy(65,3+(i*2));
            printf("|%0.2f/%d",total_tot,std_count);
            gotoxy(78,3+(i*2));
            printf("|%0.2f/%d",total_avg,std_count);
            gotoxy(91,3+(i*2));
            printf("|");
            printf("\n___________________________________|_________|_________|_________|____________|____________|");

        getch();
        system("cls");
  }


  //sorting function to sort according to roll no.
  void srtng(struct student *std,int std_count ){
      int i,j;

     if (std_count<=1)//if only one record entered
        return;
     //else
      for (i=0;i<(std_count-1);i++)
        for (j=i+1;j<std_count;j++)
           if (std[i].std_roll>std[j].std_roll)
              swap(&std[i],&std[j]);


  }




int main(){
    //variable declaration
    char ch='i',str[10];
    int num_student,std_count=0,flag,integer;
    system("color 1");// changing the font color

    //number of student predicted taking as input
 n_student:
    printf("\n\a  Enter the number of student in the class:");
    scanf("%s",str);
        flag=isinteger(str);
        if (flag==1){
            integer= atoi(str);
            num_student=integer;
        }
        else
           goto n_student;

    //declaring stdt structure array dynamically ti store student record
    struct student *stdt=(struct student*)malloc(num_student*sizeof(struct student));

//show option
choice:
    system("color 3");
    printf("\n  'i' to insert new data");
    printf("\n  'v' to view the data");
    printf("\n  'q' to quit ");
    printf("\n\a  Enter your choice : ");
    fflush(stdin);
    scanf("%c",&ch);
//what to do ?
   switch(ch)
   {
        case 'i':
            std_input(stdt,std_count);
            std_count++;
            srtng(stdt,std_count);
            if (std_count==num_student){
                printf("\n\a Further insertion of record will over write other data....\n Do you want to increase the limit  ?(y/n): ");
                fflush(stdin);
                scanf("%c",&ch);
                if (ch=='y'||ch=='Y'){

                Realloc_memory:
                    printf("\nHow much record you'r going to store:  ");
                    fflush(stdin);
                    scanf("%s",str);
                    flag=isinteger(str);
                    if (flag==1){
                        integer= atoi(str);
                        num_student+=integer;
                        stdt = realloc( stdt ,num_student*sizeof(struct student));
                        printf("\nNow you can store upto %d records\nPress any key to continue...",num_student);
                        getch();
                        system("cls");

                    }
                    else
                        goto Realloc_memory;
                }

            }
            goto choice;
        case 'v':
            system("cls");
            std_output(stdt,std_count);
            goto choice;
        case 'q':
            return 0;
        default:
            printf("\n invalid option !");
            goto choice;
    };

return 0;
}
