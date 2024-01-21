#include <bits/stdc++.h>
using namespace std;

/*
5. Given An unsorted array, find the first and the second minima from the array. Analyze the
complexity.
*/
// analysis is at the end of the code..

int main()
{
    int x;
    vector<int> a;

    ifstream aa("../aa.txt");
    while (aa >> x)
        a.push_back(x);
    aa.close();
    int n = a.size();

    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] < min1)
        {
            min2 = min1;
            min1 = a[i];
            continue;
        }
        if (a[i] < min2)
            min2 = a[i];
    }

    ofstream outputFile("output.txt");

    outputFile << "First minima : " << min1 << "\n";
    outputFile << "Second minima : " << min2 << "\n";

    cout<<"first and second minima stored in ouput.txt"<<endl;

    return 0;

    /*
    Analysis of complexity:

    Since the array of size n is iterated once, time complexity is O(n);

    since no additional space is used except variables it requires constant space complexity O(1);

    */
}