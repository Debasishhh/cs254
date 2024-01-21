#include <bits/stdc++.h>
using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1e5);
    const int numRandomNumbers = 100000;
    ofstream bb("bb.txt");
    // random no generator

    if (!bb.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < numRandomNumbers; ++i)
    {
        int randomNum = dis(gen);
        bb << randomNum;

        if (i < numRandomNumbers - 1)
        {
            bb << ' ';
        }
    }

    bb.close();
    
    cout << "Random integers array b has been generated as bb.txt." << endl;

    return 0;
}