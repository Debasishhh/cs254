#include <iostream>
#include <fstream>
#include <random>

using namespace std;

const int N = 10000;

int main()
{
    // random number generator engine
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1e5);

    // Open a file for writing
    std::ofstream values("values.txt");

    if (!values.is_open())
    {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    for (int i = 0; i < N; ++i)
    {
        int randomNum = dis(gen);
        values << randomNum;

        // Add space as separator, except for the last number
        if (i < N - 1)
        {
            values << ' ';
        }
    }

    // Close the file
    values.close();

    cout << "Random integers have been stored in values.txt." << endl;

    return 0;
}
