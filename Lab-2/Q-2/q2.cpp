#include <bits/stdc++.h>
using namespace std;

/*
2. You are given an array A of n elements, where the first m (≤ n) elements are sorted and
the remaining (n − m) elements are also sorted. However, the array A may not be sorted.
(a) Write down an in-place merge algorithm to sort A.
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
int main()
{
    int x;
    vector<int> a, b;

    ifstream aa("../aa.txt");
    while (aa >> x)
        a.push_back(x);

    sort(a.begin(), a.end());
    aa.close();

    ifstream bb("../bb.txt");
    while (bb >> x)
        b.push_back(x);

    sort(b.begin(), b.end());
    bb.close();

    vector<int> c;

    for (int y : a)
        c.push_back(y);
    for (int y : b)
        c.push_back(y);

    int n = c.size();
    int m = a.size();

    merge(c, 0, m - 1, n - 1);

    ofstream outputFile("output.txt");

    for (int y : c)
        outputFile << y << " ";

    outputFile.close();

    cout << "output of sorted array c generated in output.txt";
    /*
    Analysis of complexity:

    in the merge function while loop iterates constant time operations n-m times where n is size of merged array and m is size of first array. so time complexity is O(n);

    since no additional space is created except variables, space complexity is O(1);
    */

    return 0;
}