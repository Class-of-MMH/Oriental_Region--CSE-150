#include<stdio.h>
#include<windows.h>
int date,month,year,option;
char ch;

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
      printf("ENTER AN OPTION: ");
      scanf("%d",& option);
      FILE *details;
      details= fopen("Park_Info.txt","a");

      
   }

}