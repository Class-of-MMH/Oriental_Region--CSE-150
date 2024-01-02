#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
int date,month,year,option,number,total1=0,total2=0,total3=0,total4=0,total5=0,total=0;
char ch;
float time;

void car()
{
  FILE *car;
  car=fopen("Car_Image.txt","r");
  if(car==NULL)
  {
    printf("FILE DOES NOT EXIST!!!!");
  }
  else {
    while(!feof(car))
    {
        ch=fgetc(car);
        printf("%c", ch);
    }
  }
}

void park_details()
{
    FILE *details;
    details= fopen("Park_Info.txt","r");
    if(details==NULL)
    {
        printf("FILE DOES NOT EXIST!!!!");
    }
    else {
        while(!feof(details))
        {
            ch=fgetc(details);
            printf("%c", ch);
        }
    }
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

void search_vehicle()
{
    FILE *details;
    details = fopen("Park_Info.txt", "r");
    if (details == NULL)
    {
        printf(" FILE DOES NOT EXIST!!!!");
        return;
    }

    int searchNumber;
    printf(" ENTER THE REGISTRATION NUMBER TO SEARCH : ");
    scanf("%d", &searchNumber);

    int found = 0;
    while (!feof(details))
    {
        fscanf(details, "%*s %*s %*s %*s %f %d", &time, &number);

        if (number == searchNumber)
        {
            found = 1;
            printf(" VEHICLE FOUND!\n");
            printf(" TIME: %.2f\n", time);
            printf(" REGISTRATION NUMBER: %d\n", number);
            break;
        }
    }

    if (!found)
    {
        printf(" VEHICLE NOT FOUND!\n");
    }

    fclose(details);
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
   fprintf(details, "\n----------------\n");
   system("CLS");

   while(1)
   {
      car();
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
        
        fprintf(details, "\t\tBUS\t\t\t%.2f\t\t%d\t\t100\n", time, number);
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
         fprintf(details, "\t\tTRUCK      \t\t%.2f\t\t%d\t\t80\n", time, number);
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
         fprintf(details, "\t\tPRIVATE CAR\t\t%.2f\t\t%d\t\t70\n", time, number);
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
         fprintf(details, "\t\tMOTOR CYCLE\t\t%.2f\t\t%d\t\t60\n", time, number);
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
         fprintf(details, "\t\tBY CYCLE\t\t%.2f\t\t%d\t\t40\n", time, number);
         printf(" SUCCESSFULLY ADDED!!!!");
         getch();
         system("CLS");
         break;

         case 6:
         system("CLS");
         park_details();
         printf("\n\n\n\t\t\tPRESS ANY KEY TO RETURN BACK TO THE MAIN MENU...");
         getch();
         system("CLS");
         break;
        
         case 7:
          search_vehicle();
          printf("\n\n\n\t\t\tPRESS ANY KEY TO RETURN BACK TO THE MAIN MENU...");
          getch();
          system("CLS");
          break;
        
         case 8:
         total=total1+total2+total3+total4+total5;
         fprintf(details, "\t\t\t\t\t\t\t\t\t\t\t TOTAL = %d",total);
         fprintf(details,"\n..........................................\n");
         
         fclose(details);
         exit(0);
         break;

         default:
         printf("INVALID INPUT!!!");
         getch();
         printf("\n\n\n\t\t\tPRESS ANY KEY TO BACK TO MAIN MENU.....");
         system("CLS");
         break;
        
      }

   }

    return 0;

}
