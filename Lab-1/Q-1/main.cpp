#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int x;
    int max1 = INT_MIN, max2 = INT_MIN;

    while (inputFile >> x)
    {
        if (x > max1)
        {
            max2 = max1;
            max1 = x;
        }
        else if (x > max2)
            max2 = x;
    }

    inputFile.close();

    ofstream outputFile("output.txt");
    if (!outputFile.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }
    outputFile << max1 + max2 << endl;
    outputFile.close();
    cout << "answer in output.txt." << endl;

    return 0;
}