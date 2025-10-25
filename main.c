#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
void displayMenu();
void displayCityManagement();

int main()
{
    int choice01,choice02=0;
    char cityNames[MAX_CITIES][50]= {"Colombo","Kandy","Galle","Jaffna"};
    int cityCount=4;
    do
    {
        displayMenu();
        printf("\nEnter your choice : ");
        scanf("%d",&choice01);
        switch(choice01)
        {
        case 1 :
            do
            {
                displayCityManagement();
                printf("\nEnter your choice : ");
                scanf("%d",&choice02);
                switch(choice02)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    break;
                }
            }
            while(choice02!=4);
        }
    }
    while (choice01!=6);

    return 0;
}

void displayMenu ()
{
    printf("\n--------Main Menu-------\n");
    printf("1) City Management\n");
    printf("2) Distance Management\n");
    printf("3) Delivery Request\n");
    printf("4) Find Least Cost Route\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
}
void displayCityManagement()
{
    printf("\n\n---City Management---\n");
    printf("1) Add a new city\n");
    printf("2) Rename a city\n");
    printf("3) Remove a city\n");
    printf("4) Back to main menu\n");
}
