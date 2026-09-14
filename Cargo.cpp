#include <stdio.h>

struct Item {
    int id;
    float weight;
    float profit;
    float ratio;
    float fraction;
};

void sortItems(struct Item items[], int n) 
{
    int i, j;
    struct Item temp;
    for (i = 0; i < n - 1; i++) 
	{
        for (j = i + 1; j < n; j++)
		{
            if (items[i].ratio < items[j].ratio) 
			{
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() 
{
    struct Item items[100];
    int n, i;
    float capacity;
    float remaining;
    float totalProfit = 0;

    printf("CARGO LOADING OPTIMIZER\n");
    printf("Fractional Knapsack Algorithm\n");

    printf("\nEnter number of items: ");
    scanf("%d", &n);

    printf("Enter vehicle capacity: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++) 
	{
        items[i].id = i + 1;

        printf("\nEnter details for Item %d\n", items[i].id);

        printf("Weight: ");
        scanf("%f", &items[i].weight);

        printf("Profit/Value: ");
        scanf("%f", &items[i].profit);

        items[i].ratio = items[i].profit / items[i].weight;
        items[i].fraction = 0;
    }

    sortItems(items, n);
    remaining = capacity;

    for (i = 0; i < n; i++) 
	{
        if (remaining == 0)
            break;
        if (items[i].weight <= remaining)
	 	{
            items[i].fraction = 1.0;
            remaining -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else 
		{
            items[i].fraction = remaining / items[i].weight;
            totalProfit += items[i].profit * items[i].fraction;
            remaining = 0;
        }
    }

    printf("\nITEMS BY PROFIT/WEIGHT RATIO\n");

    printf("\n%-8s %-12s %-12s %-15s\n",
           "Item", "Weight", "Profit", "Ratio");

    for (i = 0; i < n; i++) 
	{
        printf("%-8d %-12.2f %-12.2f %-15.2f\n",
               items[i].id,
               items[i].weight,
               items[i].profit,
               items[i].ratio);
    }

    printf("\nLOADING PLAN\n");

    printf("\n%-8s %-12s %-15s %-15s\n",
           "Item", "Weight", "Fraction", "Profit Taken");

    float usedWeight = 0;

    for (i = 0; i < n; i++) 
	{
        if (items[i].fraction > 0) 
		{
            float profitTaken = items[i].profit * items[i].fraction;
            float weightTaken = items[i].weight * items[i].fraction;
            usedWeight += weightTaken;
            printf("%-8d %-12.2f %-15.2f %-15.2f\n",items[i].id,weightTaken,items[i].fraction,profitTaken);
        }
    }
    printf("\nVehicle Capacity : %.2f\n", capacity);
    printf("Weight Used      : %.2f\n", usedWeight);
    printf("Remaining Space  : %.2f\n", capacity - usedWeight);
    printf("Maximum Profit   : %.2f\n", totalProfit);
    return 0;
}
