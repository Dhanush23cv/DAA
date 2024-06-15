#include <stdio.h>

// Structure to represent an item with weight and value
struct Item {
    int weight;
    int value;
};

// Function to sort items based on value/weight ratio
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)items[j].value / items[j].weight;
            double ratio2 = (double)items[j + 1].value / items[j + 1].weight;
            if (ratio1 < ratio2) {
                // Swap items[j] and items[j+1]
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Function to perform the Fractional Knapsack algorithm
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    sortItems(items, n);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // If the item can be fully included
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // If the item cannot be fully included, include fractional part
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break; // Knapsack is full
        }
    }

    return totalValue;
}

// Driver code
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in the knapsack = %.2lf\n", maxValue);

    return 0;
}
