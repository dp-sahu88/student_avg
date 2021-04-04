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
    float dm,toc,cn;
    };

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void  input_std(struct student *std,int *std_count,int *siz_count){
        char ch='y';
        while (ch=='y'||ch=='Y'){

        printf("\n Enter the roll no. of the student : ");
        scanf("%d",&std[*std_count].std_roll);
        printf("\n Enter the name of the student : ");
        fflush(stdin);
        scanf("%[^\n]%*c",std[*std_count].std_name);
        printf("\n Marks in DM : ");
        scanf("%f",&std[*std_count].dm);
        printf("\n Marks in TOC : ");
        scanf("%f",&std[*std_count].toc);
        printf("\n Marks in CN : ");
        scanf("%f",&std[*std_count++].cn);
        if (*std_count==(*siz_count-1)){
                std=realloc( std ,(*siz_count += 10)*sizeof(struct student));
        }
        printf("\n To enter more student data enter 'y':");
        fflush(stdin);
        scanf("%c",&ch);
        }
 }

 // output_std() definition
 void output_std(struct student *std,int std_count){

        float total_dm=0,total_toc=0,total_cn=0,total_avg=0;
        printf("Roll|Name\t\t    |DM   |TOC  |CN   |avg\n");

          for (int i =0;i<=(std_count+1);++i){
            gotoxy(0,1+(i*2));
            printf("%3d|",std[std_count].std_roll);
            gotoxy(6,1+(i*2));
            printf("%s",std[std_count].std_name);
            gotoxy(28,1+(i*2));
            printf("|%0.2f",std[std_count].dm);
            gotoxy(34,1+(i*2));
            printf("|%0.2f",std[std_count].toc);
            gotoxy(40,1+(i*2));
            printf("|%0.2f",std[std_count].cn);
            gotoxy(46,1+(i*2));
            printf("|%0.2f/3",std[std_count].dm+std[std_count].toc+std[std_count].cn);
            printf("\n_____________________________________________________");
            total_dm+=std[std_count].dm,total_toc+=std[std_count].toc,total_cn+=std[std_count].cn;
            total_dm+=std[std_count].dm,total_toc+=std[std_count].toc,total_cn+=std[std_count].cn;
            total_dm+=std[std_count].dm,total_toc+=std[std_count].toc,total_cn+=std[std_count].cn;
          }

  }



int main(){

    //variable declaration
      int std_count=0,siz_count=20;
      char check;
    //declaration of std pointer dynamically
      struct student *std=(struct student*)malloc(siz_count*sizeof(struct student));

repeat:
      fflush(stdin);
      printf("\n\aEnter the choice...");
      printf("\n'i' to insert new data");
      printf("\n'v' to view data");
      printf("\n'q' to quit\n:");
      scanf("%C",&check);
      switch(check){
        case 'i':
            // calling the input_std function to take input from user
            input_std(std,&std_count,&siz_count);

            goto repeat;
        case 'v':
            system("cls");
            output_std(std,std_count);
            goto repeat;
        case 'q':
             return 0;
        default:
            goto repeat;


      }


return 0;
}
