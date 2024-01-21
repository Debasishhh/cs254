#include <bits/stdc++.h>
using namespace std;

/*
Given two sorted arrays of A and B of m and n elements, respectively,
(b) Construct a sorted array C for A ∪ B.
*/

void union_array(vector<int> &a, vector<int> &b, int m, int n, vector<int> &c)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            c.push_back(a[i++]);
        else if (b[j] < a[i])
            c.push_back(b[j++]);
        else
        {
            c.push_back(b[j++]);
            i++;
        }
    }

    while (i < m && a[i] == a[i - 1])
        i++;
    while (i < m)
        c.push_back(a[i++]);

    while (j < n && b[j] == b[j - 1])
        j++;
    while (j < n)
        c.push_back(b[j++]);
}

int main()
{
    int x;
    vector<int> a, b;

    ifstream aa("../../aa.txt");

    while (aa >> x)
        a.push_back(x);

    sort(a.begin(), a.end());

    unique(a.begin(), a.end());

    aa.close();

    ifstream bb("../../bb.txt");

    while (bb >> x)
        b.push_back(x);

    sort(b.begin(), b.end());

    unique(b.begin(), b.end());

    bb.close();

    int m = a.size();
    int n = b.size();

    vector<int> ans;

    union_array(a, b, m, n, ans);

    ofstream outputFile("output.txt");

    for (int y : ans)
        outputFile << y << ' ';

    outputFile.close();

    cout << "output of sorted array c generated in output.txt";

    /*
    Analysis of complexity:

    No of elements in array a is 'm' and in b is 'n'. As the while loop iterates constant time operations m+n times in union_array function, time complexity is O(m+n);

    The union vector ans is created of size m+n. So space complexity is O(m+n);
    */

    return 0;
}