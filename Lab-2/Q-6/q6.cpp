#include <bits/stdc++.h>
using namespace std;

/*
6. Implement a Quick sort algorithm, where the pivot element is almost the median of the
array
*/

void median_of_3(vector<int> &a, int l, int r)
{
    int m = (l + r) / 2;
    if (a[r] < a[l])
        swap(a[l], a[r]);
    if (a[m] < a[l])
        swap(a[m], a[l]);
    if (a[r] < a[m])
        swap(a[r], a[m]);
    swap(a[m], a[r - 1]);
}

int partition(vector<int> &a, int l, int r)
{
    median_of_3(a, l, r);
    int x = a[r - 1];
    int i = l - 1, j = r;
    for (int j = l; j < r - 1; ++j)
        if (a[j] < x)
            swap(a[++i], a[j]);
    swap(a[i + 1], a[r - 1]);
    return i + 1;
}

void quicksort(vector<int> &a, int l, int r)
{
    if (r > l)
    {
        int p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
    }
}

int main()
{
    int x;
    vector<int> a;

    ifstream aa("../aa.txt");

    while (aa >> x)
        a.push_back(x);

    aa.close();

    int n = a.size();

    quicksort(a, 0, n - 1);

    ofstream outputFile("output.txt");

    for (int x : a)
        outputFile << x << ' ';

    outputFile.close();

    cout << "sorted array stored in ouput.txt";

    /*
    Analysis of complexity:
    the median_of_3 function runs in constant time complexity. the rest of the algorithm is same as that of quicksort. so here also the recursive relation is T(n)=2T(n/2)+O(n) and thus time complexity is O(nlogn);

    average space complexity is O(logn) due to recursion stack
    */
}