#include<stdio.h>
#include<windows.h>
#include<conio.h>
int date,month,year,option,number,total1=0,total2=0,total3=0,total4=0,total5=0;
char ch;
float time;

void park_details;
{
    FILE *details;
    details= fopen("Park_Info.txt","r");
    
}

void menu()
{
    FILE *menu;
    menu= fopen("Park_Menu.txt","r");
    if(menu==NULL)
    {
        printf("FILE DOES NOT EXIST!!!!");
    }
    else {
        while(!feof(menu))
        {
            ch=fgetc(menu);
            printf("%c", ch);
        }
    }
}

int main(){
   system("CLS");
   system("color 0A");
   
   FILE *details;
   details= fopen("Park_Info.txt","a");

   printf("\n Enter TODAYS DATE FOR CONTINUE ");
   printf("\n\tENTER DATE: ");
   scanf("%d", &date);
   printf("\n\tENTER MONTH: ");
   scanf("%d", &month);
   printf("\n\tENTER YEAR: ");
   scanf("%d", &year);

   fprintf(details, "\n\nDATE: %d-%d-%d", date, month, year);
   fprintf(details, "\n----------------");
   system("CLS");

   while(1)
   {
      menu();
      printf("\n ENTER AN OPTION: ");
      scanf("%d",& option);
      FILE *details;
      details= fopen("Park_Info.txt","a");

      switch(option)
      {
         case 1:
         printf(" ENTER TIME: ");
         scanf("%f",& time);
         printf(" ENTER REGISTRATION NUMBER: ");
         scanf("%d", &number);

        total1+=100;
        
        fprintf(details, "BUS %f %d", time, number);
        printf(" SUCCESSFULLY ADDED!!!!");
        getch();
        system("CLS");
        break;

        case 2:
         printf(" ENTER TIME: ");
         scanf("%f",& time);
         printf(" ENTER REGISTRATION NUMBER: ");
         scanf("%d", &number);

         total2+=80;
         fprintf(details, "TRUCK %f %d", time, number);
         printf(" SUCCESSFULLY ADDED!!!!");
         getch();
         system("CLS");
         break;

         case 3:
         printf(" ENTER TIME: ");
         scanf("%f",& time);
         printf(" ENTER REGISTRATION NUMBER: ");
         scanf("%d", &number);

         total3+=70;
         fprintf(details, "PRIVATE CAR %f %d", time, number);
         printf(" SUCCESSFULLY ADDED!!!!");
         getch();
         system("CLS");
         break;

         case 4:
         printf(" ENTER TIME: ");
         scanf("%f",& time);
         printf(" ENTER REGISTRATION NUMBER: ");
         scanf("%d", &number);

         total4+=60;
         fprintf(details, "MOTOR CYCLE %f %d", time, number);
         printf(" SUCCESSFULLY ADDED!!!!");
         getch();
         system("CLS");
         break;

         case 5:
         printf(" ENTER TIME: ");
         scanf("%f",& time);
         printf(" ENTER REGISTRATION NUMBER: ");
         scanf("%d", &number);

         total5+=40;
         fprintf(details, "BY CYCLE %f %d", time, number);
         printf(" SUCCESSFULLY ADDED!!!!");
         getch();
         system("CLS");
         break;

         

      }
   }

}