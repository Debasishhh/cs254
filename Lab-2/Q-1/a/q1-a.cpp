#include <bits/stdc++.h>
using namespace std;

/*
Given two sorted arrays of A and B of m and n elements, respectively,
(a) Construct a sorted array C by merging A and B.
*/

void merge(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int m = a.size(), n = b.size();
    int i = 0, j = 0, k = 0;
    while (k < m + n)
    {
        if (j == n || a[i] <= b[j])
        {
            c[k] = a[i];
            i++, k++;
        }
        else if (i == m || b[j] <= a[i])
        {
            c[k] = b[j];
            j++, k++;
        }
    }
}

int main()
{
    int x;
    vector<int> a, b;

    ifstream aa("../../aa.txt");
    while (aa >> x)
        a.push_back(x);
    sort(a.begin(), a.end());
    aa.close();

    ifstream bb("../../bb.txt");
    while (bb >> x)
        b.push_back(x);
    sort(b.begin(), b.end());
    bb.close();

    int m = a.size(), n = b.size();
    vector<int> c(m + n);

    merge(a, b, c);

    ofstream outputFile("output.txt");

    for (int y : c)
    {
        outputFile << y << " ";
    }

    outputFile.close();

    cout << "output of sorted array c generated in output.txt" << endl;

    /*
    Analysis of complexity:

    no of elements in array a is 'm' and in b is 'n'. As the while loop iterates constant time operations m+n times in merge function, time complexity is O(m+n);
    
    The merged array is created of size m+n. So space complexity is O(m+n);
    */

    return 0;
}