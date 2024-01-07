#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int date, month, year, option, number, total1 = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0, total = 0;
char ch;
float time;
int totalVehicle = 0;
#define MAX_VEHICLE_CAPACITY 5

void car()
{
    FILE *car;
    car = fopen("Car_Image.txt", "r");
    if (car == NULL)
    {
        printf("FILE DOES NOT EXIST!!!!");
    }
    else
    {
        while (!feof(car))
        {
            ch = fgetc(car);
            printf("%c", ch);
        }
    }
}

void park_details()
{
    FILE *details;
    details = fopen("Park_Info.txt", "r");
    if (details == NULL)
    {
        printf("FILE DOES NOT EXIST!!!!");
    }
    else
    {
        while (!feof(details))
        {
            ch = fgetc(details);
            printf("%c", ch);
        }
    }
}

void menu()
{
    FILE *menu;
    menu = fopen("Park_Menu.txt", "r");
    if (menu == NULL)
    {
        printf("FILE DOES NOT EXIST!!!!");
    }
    else
    {
        while (!feof(menu))
        {
            ch = fgetc(menu);
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

void vehicle_capacity()
{
    printf("\n\t\t  VEHICLE CAPACITY INFORMATION  ");
    printf("\n\t----------------------------------");
    printf("\n\tTOTAL VEHICLES ENTERED: %d", totalVehicle);
    printf("\n\tSLOTS AVAILABLE: %d", MAX_VEHICLE_CAPACITY - totalVehicle);

    if (totalVehicle >= MAX_VEHICLE_CAPACITY)
    {
        printf("\n\n\t NO SLOTS AVAILABLE. \n\n\t PRESS ANY KEY TO BACK TO MAIN MENU.....");
        getch();
        system("CLS");
    }
    else
    {
        printf("\n\n\n\t\tPRESS ANY KEY TO RETURN BACK TO THE MAIN MENU...");
        getch();
        system("CLS");
    }
}

int main()
{
    system("CLS");
    system("color 0A");

    FILE *details;
    details = fopen("Park_Info.txt", "a");

    printf("\n ENTER TODAYS DATE FOR CONTINUE ");
    printf("\n\tENTER DATE: ");
    scanf("%d", &date);
    printf("\n\tENTER MONTH: ");
    scanf("%d", &month);
    printf("\n\tENTER YEAR: ");
    scanf("%d", &year);

    fprintf(details, "\n\nDATE: %d-%d-%d", date, month, year);
    fprintf(details, "\n----------------\n");
    system("CLS");

    while (1)
    {
        car();
        menu();
        printf("\n ENTER AN OPTION: ");
        scanf("%d", &option);

        int hours, minutes;
        char ampm[3];
        char timeInput[20];

        if (totalVehicle >= 5 && (option >= 1 && option <= 5))
        {
            printf("\n\n\t NO SLOTS AVAILABLE. PRESS ANY KEY TO BACK TO MAIN MENU.....\n\n");
            getch();
            system("CLS");
            continue;
        }

        if (option >= 1 && option <= 5)
        {
            totalVehicle++;
        }

        switch (option)
        {

        case 1:
            printf(" ENTER TIME (HH.MM AM/PM): ");
            scanf("%s", timeInput);

            if (sscanf(timeInput, "%d.%d %2s", &hours, &minutes, ampm) != 3)
            {
                printf(" INVALID TIME FORMAT. PLEASE USE HH.MM AM/PM FORMAT. ");
                getch();
                system("CLS");
                break;
            }

            if ((strcmp(ampm, "AM") != 0) && (strcmp(ampm, "PM") != 0))
            {
                printf(" INVALID AM/PM INDICATOR. PLEASE USE AM OR PM. ");
                getch();
                system("CLS");
                break;
            }

            printf(" ENTER REGISTRATION NUMBER: ");
            scanf("%d", &number);

            total1 += 100;

            fprintf(details, "\t\tBUS\t\t\t%d.%02d %s\t\t%d\t\t100\n", hours, minutes, ampm, number);
            printf(" SUCCESSFULLY ADDED!!!!");
            getch();
            system("CLS");
            break;

        case 2:
            printf(" ENTER TIME (HH.MM AM/PM): ");
            scanf("%s", timeInput);

            if (sscanf(timeInput, "%d.%d %2s", &hours, &minutes, ampm) != 3)
            {
                printf(" INVALID TIME FORMAT. PLEASE USE HH.MM AM/PM FORMAT. ");
                getch();
                system("CLS");
                break;
            }

            if ((strcmp(ampm, "AM") != 0) && (strcmp(ampm, "PM") != 0))
            {
                printf(" INVALID AM/PM INDICATOR. PLEASE USE AM OR PM. ");
                getch();
                system("CLS");
                break;
            }

            printf(" ENTER REGISTRATION NUMBER: ");
            scanf("%d", &number);

            total2 += 80;

            fprintf(details, "\t\tTRUCK      \t\t%d.%02d %s\t\t%d\t\t80\n", hours, minutes, ampm, number);
            printf(" SUCCESSFULLY ADDED!!!!");
            getch();
            system("CLS");
            break;

        case 3:

            printf(" ENTER TIME (HH.MM AM/PM): ");
            scanf("%s", timeInput);

            if (sscanf(timeInput, "%d.%d %2s", &hours, &minutes, ampm) != 3)
            {
                printf(" INVALID TIME FORMAT. PLEASE USE HH.MM AM/PM FORMAT. ");
                getch();
                system("CLS");
                break;
            }

            if ((strcmp(ampm, "AM") != 0) && (strcmp(ampm, "PM") != 0))
            {
                printf(" INVALID AM/PM INDICATOR. PLEASE USE AM OR PM. ");
                getch();
                system("CLS");
                break;
            }

            printf(" ENTER REGISTRATION NUMBER: ");
            scanf("%d", &number);

            total3 += 70;
            fprintf(details, "\t\tPRIVATE CAR\t\t%d.%02d %s\t\t%d\t\t70\n", hours, minutes, ampm, number);
            printf(" SUCCESSFULLY ADDED!!!!");
            getch();
            system("CLS");
            break;

        case 4:
            printf(" ENTER TIME (HH.MM AM/PM): ");
            scanf("%s", timeInput);

            if (sscanf(timeInput, "%d.%d %2s", &hours, &minutes, ampm) != 3)
            {
                printf(" INVALID TIME FORMAT. PLEASE USE HH.MM AM/PM FORMAT. ");
                getch();
                system("CLS");
                break;
            }

            if ((strcmp(ampm, "AM") != 0) && (strcmp(ampm, "PM") != 0))
            {
                printf(" INVALID AM/PM INDICATOR. PLEASE USE AM OR PM. ");
                getch();
                system("CLS");
                break;
            }

            printf(" ENTER REGISTRATION NUMBER: ");
            scanf("%d", &number);

            total4 += 60;
            fprintf(details, "\t\tMOTOR CYCLE\t\t%d.%02d %s\t\t%d\t\t60\n", hours, minutes, ampm, number);
            printf(" SUCCESSFULLY ADDED!!!!");
            getch();
            system("CLS");
            break;

        case 5:
            printf(" ENTER TIME (HH.MM AM/PM): ");
            scanf("%s", timeInput);

            if (sscanf(timeInput, "%d.%d %2s", &hours, &minutes, ampm) != 3)
            {
                printf(" INVALID TIME FORMAT. PLEASE USE HH.MM AM/PM FORMAT. ");
                getch();
                system("CLS");
                break;
            }

            if ((strcmp(ampm, "AM") != 0) && (strcmp(ampm, "PM") != 0))
            {
                printf(" INVALID AM/PM INDICATOR. PLEASE USE AM OR PM. ");
                getch();
                system("CLS");
                break;
            }

            printf(" ENTER REGISTRATION NUMBER: ");
            scanf("%d", &number);

            total5 += 40;
            fprintf(details, "\t\tBY CYCLE\t\t%d.%02d %s\t\t%d\t\t40\n", hours, minutes, ampm, number);
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
            system("CLS");
            vehicle_capacity();
            break;
        
        case 8:
            search_vehicle();
            printf("\n\n\n\t\t\tPRESS ANY KEY TO RETURN BACK TO THE MAIN MENU...");
            getch();
            system("CLS");
            break;

        case 9:
            total = total1 + total2 + total3 + total4 + total5;
            printf("\n\t TOTAL REVENUE = %d\n", total);
            fprintf(details, "\t\t\t\t\t\t\t\t\t\t\t TOTAL = %d", total);
            fprintf(details, "\n..........................................\n");
            printf("\n\n\n\t\t\tPRESS ANY KEY TO RETURN BACK TO MAIN MENU.....");
            getch();
            system("CLS");
            break;

        case 10:
            printf("\n\n\t\t....EXITING THE PROGRAM....\n\n");
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

    fclose(details);
    return 0;
}
