#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define FUEL_PRICE 310
void displayMenu();
void displayCityManagement();
void addCities (char cityNames[MAX_CITIES][50],int *cityCount);
void renameCities(char cityNames[MAX_CITIES][50],int cityCount);
void removeCities(char cityNames[MAX_CITIES][50],int *cityCount);
void displayDistanceManagement();
void initializeDistanceArray(int distance[MAX_CITIES][MAX_CITIES]);
void enterDistance(char cityNames[MAX_CITIES][50],int *cityCount,int distance[MAX_CITIES][MAX_CITIES]);
void distanceTable(char cityNames[MAX_CITIES][50],int *cityCount,int distance[MAX_CITIES][MAX_CITIES]);
void displayVehicleOptions(char vehicleNames[3][10],int vehicleCapacity[3],
                           int vehicleRate[3], int vehicleSpeed[3],  int vehicleEfficiency[3]);
int selectVehicleType(char vehicleNames[3][10],int vehicleCapacity[3],int weight);
void displayDeliverySummary(char *source, char *destination, int distanceBetween, int weight,
                            char *vehicleNames, float deliveryCost, float deliveryTime,
                            float fuelUsed, float fuelCost, float operationalCost,
                            float profit, float customerCharge);
void calculateDeliveryCost(int source, int destination, int weight, int distanceBetween,
                           char cityNames[MAX_CITIES][50], int distance[MAX_CITIES][MAX_CITIES],
                           char vehicleNames[3][10], int vehicleRate[3], int vehicleSpeed[3],
                           int vehicleEfficiency[3], int vehicleType);
void printDeliveryOder(char cityNames[MAX_CITIES][50], int *cityCount,
                       int distance[MAX_CITIES][MAX_CITIES],
                       char vehicleNames[3][10], int vehicleCapacity[3],
                       int vehicleRate[3], int vehicleSpeed[3], int vehicleEfficiency[3]);

int main()
{
    int choice01,choice02,choice03=0;
    char cityNames[MAX_CITIES][50]= {"Colombo","Kandy","Galle","Jaffna"};
    int cityCount=4;
    int distance[MAX_CITIES][MAX_CITIES];
    initializeDistanceArray(distance);
    char vehicleNames[3][10]={"Van","Truck","Lorry"};
    int vehicleCapacity[3]= {1000,5000,10000};
    int vehicleRate[3]= {30,40,80};
    int vehicleSpeed[3]= {60,50,45};
    int vehicleEfficiency[3]= {12,6,4};
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
            {
                displayDistanceManagement();
                printf("\nEnter your choice : ");
                scanf("%d",&choice03);
                switch(choice03)
                {
                case 1:
                    enterDistance(cityNames,&cityCount,distance);
                    break;
                case 2:
                    distanceTable(cityNames,&cityCount,distance);
                    break;
                case 3:
                    break;
                default:
                    printf("\nInvalid choice!\n");
                    break;
                }
            }
            while(choice03!=3);
            break;
        case 3:
            printDeliveryOder(cityNames, &cityCount, distance, vehicleNames,
                              vehicleCapacity, vehicleRate, vehicleSpeed, vehicleEfficiency);

            break;
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
    for(i=0; i<MAX_CITIES; i++)
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
void distanceTable(char cityNames[MAX_CITIES][50],int *cityCount,int distance[MAX_CITIES][MAX_CITIES])
{
    printf("\n----------------Distance  Table(km)-------------\n");
    printf("           ");

    int i=0,j=0;
    for(i=0; i<*cityCount; i++)
    {
        printf("%-10.8s",cityNames[i]);
    }
    printf("\n");

    for(i=0; i<*cityCount; i++)
    {
        printf("------------");
    }
    printf("\n");

    for(i=0; i<*cityCount; i++)
    {
        printf("%d) %-10s",i+1,cityNames[i]);
        for(j=0; j<*cityCount; j++)
        {
            if(distance[i][j] == -1)
            {
                printf("%-11s","N/A");
            }
            else
            {
                printf("%-11d",distance[i][j]);
            }
        }
        printf("\n");
    }
}
void displayVehicleOptions(char vehicleNames[3][10],int vehicleCapacity[3],
                           int vehicleRate[3], int vehicleSpeed[3],  int vehicleEfficiency[3])

{
    printf("\n--------------------------------Vehicle Types----------------------------\n");
    printf("| Type     | Capacity   | Rate per km   | Avg Speed   | Fuel Efficiency   |\n");
    printf("---------------------------------------------------------------------------\n");
    printf("|          | (kg)       | (LKR)         | (km/h)      | (km/l)            |\n");

    for(int i = 0; i < 3; i++)
    {
        printf("|%d) %-6s | %-10d | %-13d | %-11d | %-17d |\n",i+1,
               vehicleNames[i],
               vehicleCapacity[i],
               vehicleRate[i],
               vehicleSpeed[i],
               vehicleEfficiency[i]);
    }
}
int selectVehicleType(char vehicleNames[3][10],int vehicleCapacity[3],int weight)
{
    int choice;
    do
    {
        printf("\nSelect vehicle type:");
        scanf("%d",&choice);

        while(choice < 1 || choice > 3)
        {
            printf("Invalid choice! Please enter 1, 2, or 3: ");
            scanf("%d",&choice);
        }

        if(vehicleCapacity[choice-1]<weight)
        {
            printf("Weight exceed vehicle capacity,Choose another vehicle\n");
        }
    }
    while(vehicleCapacity[choice-1]<weight);
    printf("Vehicle   : %s\n",vehicleNames[choice-1]);
    return choice-1;
}
void displayDeliverySummary(char *source, char *destination, int distanceBetween, int weight,
                            char *vehicleNames, float deliveryCost, float deliveryTime,
                            float fuelUsed, float fuelCost, float operationalCost,
                            float profit, float customerCharge)
{

    printf("----------------Delivery Cost Estimation----------------------\n");
    printf("\n------------------------------------------------------------\n");
    printf("From    : %s\n", source);
    printf("To      : %s\n", destination);
    printf("Distance: %d km\n", distanceBetween);
    printf("Vehicle : %s\n", vehicleNames);
    printf("Weight  : %d kg\n", weight);
    printf("------------------------------------------------------------\n");
    printf("Base Delivery Cost: %.2f LKR\n", deliveryCost);
    printf("Fuel Used         : %.2f L\n", fuelUsed);
    printf("Fuel Cost         : %.2f LKR\n", fuelCost);
    printf("Operational Cost  : %.2f LKR\n",operationalCost);
    printf("Profit (25%%)     : %.2f LKR\n", profit);
    printf("Customer Charge   : %.2f LKR\n", customerCharge);
    printf("Estimated Time    : %.2f hours\n", deliveryTime);
    printf("------------------------------------------------------------\n");
}
void calculateDeliveryCost(int source, int destination, int weight, int distanceBetween,
                           char cityNames[MAX_CITIES][50], int distance[MAX_CITIES][MAX_CITIES],
                           char vehicleNames[3][10], int vehicleRate[3], int vehicleSpeed[3],
                           int vehicleEfficiency[3], int vehicleType)
{
    int D = distance[source-1][destination-1];

    if(D == -1)
    {
        printf("No route available between %s and %s\n",cityNames[source-1],cityNames[destination-1]);
        return;
    }
    int R = vehicleRate[vehicleType];
    int S = vehicleSpeed[vehicleType];
    int E = vehicleEfficiency[vehicleType];
    int F = FUEL_PRICE;

    float W = (float)weight;
    float deliveryCost = D*R*(1+ W/10000.0);
    float deliveryTime = (float)D/S;
    float fuelUsed = (float)D/E;
    float fuelCost = fuelUsed*F;
    float operationalCost = deliveryCost+fuelCost;
    float profit = deliveryCost*0.25;
    float customerCharge = operationalCost+profit;

    displayDeliverySummary(cityNames[source-1], cityNames[destination-1], D, weight,
                           vehicleNames[vehicleType], deliveryCost, deliveryTime,
                           fuelUsed, fuelCost, operationalCost, profit, customerCharge);
}
void printDeliveryOder(char cityNames[MAX_CITIES][50], int *cityCount,
                       int distance[MAX_CITIES][MAX_CITIES],
                       char vehicleNames[3][10], int vehicleCapacity[3],
                       int vehicleRate[3], int vehicleSpeed[3], int vehicleEfficiency[3])

{
    int source, destination, weight;
    printf("\n----City List---");
    int i;
    for (i=0; i<*cityCount; i++)
    {
        printf("\n%d) %s ",i+1,cityNames[i]);
    }
    printf("\nEnter source city: ");
    scanf("%d",&source);
    printf("Enter destination city: ");
    scanf("%d",&destination);

    if(source == destination)
    {
        printf("Source and destination cannot be the same\n");
        return;
    }
    printf("Enter package weight (kg): ");
    scanf("%d",&weight);

    if(weight<=0)
    {
        printf("Weight should be a positive number\n");
        return;
    }

    displayVehicleOptions(vehicleNames, vehicleCapacity, vehicleRate, vehicleSpeed, vehicleEfficiency);

    int vehicleType = selectVehicleType(vehicleNames, vehicleCapacity, weight);

    calculateDeliveryCost(source, destination, weight, distance[source-1][destination-1],
                          cityNames, distance, vehicleNames, vehicleRate,
                          vehicleSpeed, vehicleEfficiency, vehicleType);

}
