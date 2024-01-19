#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int option, number, total1 = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0, total = 0;
char ch;
int totalVehicle = 0;
#define MAX_VEHICLE_CAPACITY 5
#define MAX_LINE 2024
#define FILENAME_SIZE 1024

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

void remove_entry()
{
    FILE *file, *temp;
    char filename[FILENAME_SIZE];
    char temp_filename[FILENAME_SIZE];
    char buffer[MAX_LINE];
    int del_id = 0;

    printf(" ENTER FILE NAME: ");
    scanf("%s", filename);
    strcpy(temp_filename, "temp__");
    strcat(temp_filename, filename);

    printf(" ENTER THE REGISTRATION NUMBER YOU WANT TO DELETE: ");
    scanf("%d", &del_id);

    file = fopen(filename, "r");
    temp = fopen(temp_filename, "w");

    if (file == NULL || temp == NULL)
    {
        printf("ERROR FILE NOT FOUND\n");
        return;
    }

    int current_id = 0;
    int found = 0;

    while (fgets(buffer, MAX_LINE, file) != NULL)
    {
        sscanf(buffer, "%d", &current_id);

        if (current_id == del_id)
        {
            found = 1;
        }
        else
        {
            fputs(buffer, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove(filename);
    rename(temp_filename, filename);

    if (found)
    {
        printf("ENTRY WITH REGISTRATION NUMBER %d IS DELETED SUCCESSFULLY.\n", del_id);
    }
    else
    {
        printf("ENTRY WITH REGISTRATION NUMBER %d NOT FOUND.\n", del_id);
    }
}

void update_entry()
{
    FILE *file;
    char filename[FILENAME_SIZE];
    char buffer[MAX_LINE];
    char replace[MAX_LINE];
    int replace_id = 0;

    printf(" ENTER FILE NAME: ");
    scanf("%s", filename);
    getchar();

    printf(" ENTER THE REGISTRATION NUMBER YOU WANT TO UPDATE: ");
    scanf("%d", &replace_id);

    fflush(stdin);

    printf(" ENTER NEW LINE: ");
    fgets(replace, MAX_LINE, stdin);

    file = fopen(filename, "r+");

    if (file == NULL)
    {
        printf(" ERROR OPENING FILE.\n");
        return;
    }

    bool keep_reading = true;
    int current_id = 0;

    while (fgets(buffer, MAX_LINE, file) != NULL)
    {
        if (sscanf(buffer, "%d", &current_id) == 1 && current_id == replace_id)
        {
            fseek(file, -strlen(buffer), SEEK_CUR);
            fputs(replace, file);
            break;
        }
    }

    fclose(file);

    printf(" ENTRY WITH REGISTRATION NUMBER %d IS UPDATED SUCCESSFULLY.\n", replace_id);
}

int main()
{
    system("CLS");
    system("color 0A");

    FILE *details;
    details = fopen("Park_Info.txt", "a");

    time_t current_time = time(NULL);

    char date[20];
    strftime(date, 20, "%d-%m-%Y", localtime(&current_time));
    fprintf(details, "\n\nDATE: %s", date);
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
            system("CLS");
            remove_entry();
            printf("\n\n\n\t\t\tPRESS ANY KEY TO RETURN BACK TO THE MAIN MENU...");
            getch();
            system("CLS");
            break;
            
        case 11:
            system("CLS");
            update_entry();
            printf("\n\n\n\t\t\tPRESS ANY KEY TO RETURN BACK TO THE MAIN MENU...");
            getch();
            system("CLS");
            break;
            
        case 12:
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
