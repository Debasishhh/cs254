
/*
Q1.You are given a set of items, each with a weight and a value. You need to determine which
 items to include in the collection so that the total weight is less than or equal to a given
 limit while maximizing the total cost.
 Example:
 Input: item = [i1,i2,i3,i4,i5];
 weights = [2, 5, 7, 3, 1];
 values = [10, 20, 15, 7, 5];
 Weight Limit = 10
 Output: [i1,i2,i4], with total cost 37
 (a) Design a solution using a greedy approach.
 (b) Check if your greedy algorithm can always provide the optimal solution.
 (c) If not, design an optimal solution strategy
*/
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value, weight;
    // Constructor
    Item(int value, int weight) : value(value), weight(weight) {}
};

// Comparison function to sort items by value/weight ratio
bool cmp(const Item &a, const Item &b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main()
{
    int n, WeightLimit;
    cin >> n >> WeightLimit;
    vector<Item> items;
    for (int i = 0; i < n; i++)
    {
        int value, weight;
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }

    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), cmp);

    int totalValue = 0;
    for (const auto &item : items)
    {
        if (WeightLimit >= item.weight)
        {
            WeightLimit -= item.weight;
            totalValue += item.value;
        }
        else
        {
            break;
        }
    }

    cout << "Total value: " << totalValue << endl;
    return 0;

    /*
    Time complexity:
        O(nlogn);
    */
}