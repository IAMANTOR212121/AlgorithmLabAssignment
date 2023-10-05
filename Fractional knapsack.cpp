#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
    double valuePerWeight;

    Item(int w, int v) : weight(w), value(v) {
        valuePerWeight = static_cast<double>(value) / weight;
    }
};

bool compareItems(const Item& item1, const Item& item2) {
    return item1.valuePerWeight > item2.valuePerWeight;
}

double fractionalKnapsack(std::vector<Item>& items, int capacity) {
    std::sort(items.begin(), items.end(), compareItems);

    double maxTotalValue = 0.0;
    double currentWeight = 0.0;

    for (const Item& item : items) {
        if (currentWeight + item.weight <= capacity) {
            // Take the whole item if it fits
            maxTotalValue += item.value;
            currentWeight += item.weight;
        } else {
            // Take a fraction of the item
            double remainingCapacity = capacity - currentWeight;
            maxTotalValue += remainingCapacity * item.valuePerWeight;
            break;  // We've filled the knapsack to its capacity
        }
    }

    return maxTotalValue;
}

int main() {
    std::vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };
    int capacity = 50;

    double maxTotalValue = fractionalKnapsack(items, capacity);

    std::cout << "Maximum total value: " << maxTotalValue << std::endl;

    return 0;
}
