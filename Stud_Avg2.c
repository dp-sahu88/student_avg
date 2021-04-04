//Author:DEADPOOL
//User@DEADPOOL
//Device name:LAPTOP-MGJPSU5N
//***************************
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
 //defining the student structure
    struct student {
    int std_roll;
    char std_name[40];
    float dm,toc,cn,avg;
    };


void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void std_input(struct student *stdt,int std_count){

        printf("\n\a Enter the roll no. of the student : ");
        scanf("%d",&stdt[std_count].std_roll);
        printf("\n\a Enter the name of the student : ");
        fflush(stdin);
        scanf("%[^\n]%*c",stdt[std_count].std_name);
        printf("\n\a Marks in DM : ");
        scanf("%f",&stdt[std_count].dm);
        printf("\n\a Marks in TOC : ");
        scanf("%f",&stdt[std_count].toc);
        printf("\n\a Marks in CN : ");
        scanf("%f",&stdt[std_count].cn);
        stdt[std_count].avg = stdt[std_count].dm+stdt[std_count].toc+stdt[std_count].cn/3;
}


 // output_std() definition
 void std_output(struct student *std,int std_count){

        float total_dm=0,total_toc=0,total_cn=0,total_avg=0,total,total_tot=0;
        int i;


        printf("Roll|NAME__________________________|DM_______|TOC______|CN_______|TOTAL_______|AVERAGE_____|\n");


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
  }


int main(){
    //variable declaration
    char ch='i';
    int num_student,std_count=0;
    printf("\n\a  Enter the number of student in the class:");
    scanf("%d",&num_student);
    struct student *stdt=(struct student*)malloc(num_student*sizeof(struct student));

//show option
choice:
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
