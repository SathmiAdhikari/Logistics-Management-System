#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
void displayMenu();
void displayCityManagement();
void addCities (char cityNames[MAX_CITIES][50],int *cityCount);
void renameCities(char cityNames[MAX_CITIES][50],int cityCount);
void removeCities(char cityNames[MAX_CITIES][50],int *cityCount);
void displayDistanceManagement();
void initializeDistanceArray(int distance[MAX_CITIES][MAX_CITIES]);
void enterDistance(char cityNames[MAX_CITIES][50],int *cityCount,int distance[MAX_CITIES][MAX_CITIES]);

int main()
{
    int choice01,choice02,choice03=0;
    char cityNames[MAX_CITIES][50]= {"Colombo","Kandy","Galle","Jaffna"};
    int cityCount=4;
    int distance[MAX_CITIES][MAX_CITIES];
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
                    addCities(cityNames,&cityCount);
                    break;
                case 2:
                    renameCities(cityNames,cityCount);
                    break;
                case 3:
                    removeCities(cityNames,&cityCount);
                    break;
                case 4:
                    break;
                default:
                    printf("\nInvalid choice!\n");
                    break;
                }
            }
            while(choice02!=4);
        case 2:
            do
            {   initializeDistanceArray(distance);
                displayDistanceManagement();
                printf("\nEnter your choice : ");
                scanf("%d",&choice03);
                switch(choice03)
                {
                case 1:
                     enterDistance(cityNames,&cityCount,distance);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    printf("\nInvalid choice!\n");
                    break;
                }
            }
            while(choice03!=3);
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
void addCities (char cityNames[MAX_CITIES][50],int *cityCount)
{
    printf("\nEnter 'S' to stop\n");
    int i=0;
    for (i=*cityCount; i<MAX_CITIES; i++)
    {
        (*cityCount)++;
        if(cityCount==MAX_CITIES)
        {
            printf("Maximum city limit reached.\n");
        }
        printf("\nEnter New City Name : ");
        scanf(" %[^\n]", cityNames[i]);

        if (strcmp(cityNames[i], "S") == 0||strcmp(cityNames[i], "s") == 0)
        {
            (*cityCount)--;
            cityNames[i][0] = '\0';
            break;
        }
        else
        {
            int j=0;
            for(j=0; j<i; j++)
            {
                if (strcmp(cityNames[j], cityNames[i]) == 0)
                {
                    printf("Already in the system\n");
                    i--;
                    (*cityCount)--;
                }
            }
        }
    }

    printf("\n--Updated List--");
    for (i=0; i<*cityCount; i++)
    {
        printf("\n%d) %s ",i+1,cityNames[i]);
    }
}
void renameCities(char cityNames[MAX_CITIES][50],int cityCount)
{
    char newName[50];
    int i=0;
    for (i=0; i<cityCount; i++)
    {
        printf("\n%d) %s ",i+1,cityNames[i]);
    }
    int index;
    printf("\nEnter city index to rename: ");
    scanf("%d", &index);
    if(index<1 || index > cityCount)
    {
        printf("Invalid index\n");
    }
    else
    {
        printf("\nEnter the new city name : ");
        scanf(" %[^\n]",newName);
        strcpy(cityNames[index-1],newName);
        printf("City renamed successfully!\n");
    }
    printf("\n----Updated List---");
    for (i=0; i<cityCount; i++)
    {
        printf("\n%d) %s ",i+1,cityNames[i]);
    }

    return;

}
void removeCities(char cityNames[MAX_CITIES][50],int *cityCount)
{
    printf("\n----City List---");
    int i;
    for (i=0; i<*cityCount; i++)
    {
        printf("\n%d) %s ",i+1,cityNames[i]);
    }

    int removeCityId;
    printf("\nEnter city index to remove: ");
    scanf("%d",&removeCityId);

    if(removeCityId<1 || removeCityId > cityCount)
    {
        printf("Invalid index\n");
        return;
    }
    if (removeCityId<*cityCount)
    {
        for(int i = removeCityId-1; i<*cityCount-1; i++)
        {
            strcpy(cityNames[i], cityNames[i + 1]);
        }
        printf("City removed successfully!\n");
        (*cityCount)--;
        printf("\n----Updated List---");
        for (i=0; i<*cityCount; i++)
        {
            printf("\n%d) %s ",i+1,cityNames[i]);
        }
    }
}
void displayDistanceManagement()
{
    printf("\n\n---Distance Management---\n");
    printf("1) Enter Distance between cities\n");
    printf("2) Display distance table\n");
    printf("3) Back to main menu\n");
}
void initializeDistanceArray(int distance[MAX_CITIES][MAX_CITIES])
{
    int i,j=0;
    for(i=0;i<MAX_CITIES;i++)
    {
        for(j=0; j<MAX_CITIES; j++)
        {
            if(i==j)
            {
                distance[i][j] = 0;
            }
            else
            {
                distance[i][j] = -1;
            }
        }
    }
}
void enterDistance(char cityNames[MAX_CITIES][50],int *cityCount,int distance[MAX_CITIES][MAX_CITIES])
{
    int i,j=0;
    printf("\nAvailable Cities:\n");
    for (i=0; i<*cityCount; i++)
    {
        printf("\n%d) %s ",i+1,cityNames[i]);
    }

    int cityIndex01,cityIndex02,distanceBetween;
    printf("\nEnter first city: ");
    scanf("%d",&cityIndex01);
    printf("Enter second city: ");
    scanf("%d",&cityIndex02);
    printf("Distance between them in km :");
    scanf("%d",&distanceBetween);

    if(cityIndex01 < 1 || cityIndex01 > *cityCount ||
            cityIndex02 < 1 || cityIndex02 > *cityCount)
    {
        printf("Invalid city numbers\n");
        return;
    }

    if(distanceBetween<0)
    {
        printf("Distance cannot be negative\n");
        return;
    }
    if(distanceBetween == 0)
    {
        printf("Distance cannot be zero for different cities\n");
        return;
    }

    int idx1 = cityIndex01 - 1;
    int idx2 = cityIndex02 - 1;

    distance[idx1][idx2] = distanceBetween;
    distance[idx2][idx1] = distanceBetween;

    printf("\nDistance between %s and %s set to %d km\n",cityNames[idx1],cityNames[idx2],distanceBetween);

}
