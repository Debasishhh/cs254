#include <iostream>
#include <fstream>
#include <random>

using namespace std;
const int N = 1e3;

int main()
{
    // random number generator engine
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1e5);

    // Open file for writing
    std::ofstream outputFile("input.txt");

    if (!outputFile.is_open())
    {
        std::cerr << "Error on opeing file." << std::endl;
        return 1;
    }

    // Generate and write random integers to the file
    for (int i = 0; i < N; ++i)
    {
        int randomNum = dis(gen)%1000;
        outputFile << randomNum;

        if (i < N - 1)
        {
            outputFile << ' ';
        }
    }

    // Close the file
    outputFile.close();

    cout << "Random integers have been stored in input.txt." << endl;

    return 0;
}
