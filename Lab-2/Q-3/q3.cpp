#include <bits/stdc++.h>
using namespace std;

/*
3. Use the above merging algorithm to sort an unsorted array.
*/

void merge(vector<int> &a, int l, int m, int r)
{
    int i = l;
    int j = m + 1;

    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
            i++;
        else
        {
            int temp = a[j];
            for (int k = j; k > i; k--)
                a[k] = a[k - 1];
            a[i] = temp;
            i++, j++, m++;
        }
    }
}

void mergeSort(vector<int> &a, int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
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

    mergeSort(a, 0, n - 1);

    ofstream outputFile("output.txt");

    for (int x : a)
        outputFile << x << ' ';

    outputFile.close();

    cout<<"merged array stored in output.txt"<<endl;
    /*
    Analysis of complexity:
        mergesort function splits the array into 2 and recursively calls itself. merge function takes O(n^2) time. so, T(n)=2*T(n/2)+O(n^2)
        hence time complexity is O(n^2 * logn)

        since mergesort uses recursion and no additional space is used(except variables), space complexity is due to recursion stack. the height of the recursion tree is logn.
        hence space complexity is logn.
    */

    return 0;
}