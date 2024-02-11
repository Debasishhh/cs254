#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Q1. Consider a matrix, where each cell contains either a ’0’ or a ’1’; any cell containing a ’1’
 is called a filled cell. Two cells are said to be connected if they are adjacent to each other
 horizontally, vertically, or diagonally. If one or more filled cells are connected, they form a
 region. find the size of the largest region
*/

int dfs(vector<vector<int>> &matrix, int row, int col, int rows, int cols)
{
    if (row < 0 || col < 0 || row >= rows || col >= cols || matrix[row][col] == 0)
        return 0;
    matrix[row][col] = 0;
    int size = 1;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            size += dfs(matrix, row + i, col + j, rows, cols);
        }
    }
    return size;
}

int largestRegionSize(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    int maxRegionSize = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] == 1)
            {
                int regionSize = dfs(matrix, i, j, rows, cols);
                maxRegionSize = max(maxRegionSize, regionSize);
            }
        }
    }
    return maxRegionSize;
}

int main()
{
    // freopen("intput.txt", "r", stdin);
    vector<vector<int>> matrix = {
        {1, 0, 0, 1, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {1, 0, 0, 0, 1}};

    int largestSize = largestRegionSize(matrix);
    cout << "Size of the largest region: " << largestSize << endl;

    return 0;
}
