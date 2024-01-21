#include <bits/stdc++.h>
using namespace std;

int main()
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1e5);
    const int numRandomNumbers = 100000;
    ofstream aa("aa.txt");
    // random no generator

    if (!aa.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < numRandomNumbers; ++i)
    {
        int randomNum = dis(gen);
        aa << randomNum;

        if (i < numRandomNumbers - 1)
        {
            aa << ' ';
        }
    }

    aa.close();
    cout << "Random integers array b has been generated as aa.txt." << endl;

    return 0;
}