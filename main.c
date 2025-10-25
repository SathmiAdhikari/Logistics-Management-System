#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30

void displayMenu();

int main()
{
    int choice01,choice02=0;
    char cityNames[MAX_CITIES][50]= {"Colombo","Kandy","Galle","Jaffna"};
    int cityCount=4;

    displayMenu();

    printf("\nEnter your choice : ");
    scanf("%d",&choice01);

 return 0;
}
void displayMenu ()
{
    printf("--------Main Menu-------\n");
    printf("1) City Management\n");
    printf("2) Distance Management\n");
    printf("3) Delivery Request\n");
    printf("4) Find Least Cost Route\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
}
