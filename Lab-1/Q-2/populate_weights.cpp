#include <iostream>
#include <fstream>
#include <random>

using namespace std;

const int N = 10000;
int main() {
    //random number generator engine
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1e2); 

    // Open a file for writing
    ofstream weights("weights.txt");

    if (!weights.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        int randomNum = dis(gen);
        weights << randomNum;

        // Add space as separator, except for the last number
        if (i < N - 1) {
            weights << ' ';
        }
    }

    // Close the file
    weights.close();

    cout << "Random integers have been stored in weights.txt." << endl;

    return 0;
}
