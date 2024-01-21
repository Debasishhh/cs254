#include <bits/stdc++.h>
using namespace std;

/*
4. Obtain the median element from an unsorted array.
*/

int partition(vector<int> &a, int l, int r)
{
    int x = a[r];
    int i = l - 1;
    for (int j = l; j < r; ++j)
        if (a[j] < x)
            swap(a[++i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}

int quickselect(vector<int> &a, int l, int r, int k)
{
    if (r > l)
    {
        int p = partition(a, l, r);
        if (k < p)
            return quickselect(a, l, p - 1, k);
        if (k > p)
            return quickselect(a, p + 1, r, k);
        if (k == p)
            return a[k];
    }
    if (l == k)
        return a[l];
    if (r == k)
        return a[r];
    return INT_MAX;
}

int main()
{
    int t;
    vector<int> a;

    ifstream aa("../aa.txt");
    while (aa >> t)
        a.push_back(t);
    aa.close();
    int n = a.size();

    int x = quickselect(a, 0, n - 1, (n - 1) / 2);
    int y = quickselect(a, 0, n - 1, n / 2);

    ofstream outputFile("output.txt");

    outputFile << (x + y) / 2 << "\n";

    outputFile.close();

    cout << "median of array stored in output.txt";

    return 0;

    /*
    Analysis of complexity:
    partition function takes linear time and splits array into 2. in worst case array would be divided into unequal halves. we get the recurrence relation T(n)=T(n/2)+O(n)
    so time complexity is O(n).
    (worst case time complexity will still be O(n^2) but using randomised quicksort leads to O(n))

    space complexity is due to recursion stack which will be O(n) (worst case) and O(logn) (average case)
    */
}