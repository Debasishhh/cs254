#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
1. Given an array of integers A[ ], if i < j and A[i] > A[j] then the pair (i, j) is
called the inversion of an array A[ ]. Write a program to find the total counts
of inversion in an array A[ ].
Example:
input: A[ ] = {3, 2, 1}
output: 3
*/

int merge(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv = 0;

    if (right > left)
    {
        mid = (right + left) / 2;

        inv += mergeSort(arr, temp, left, mid);
        inv += mergeSort(arr, temp, mid + 1, right);

        inv += merge(arr, temp, left, mid + 1, right);
    }
    return inv;
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid, k = left, inv = 0;

    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv += (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int temp[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = mergeSort(arr, temp, 0, n - 1);
    cout << ans;
    return 0;

    /*
    sample input:
    11
    1 5 2 3 1 2 3 4 1 4 5
    output:16

    Analysis:
    since we are using divide and conquer algorithm to count inversions in each of the 2 subarrays and so on, T(n)=2T(n/2)+O(n). so time complexity is O(nlogn).
    we are using auxillary space of O(n) i.e. the temporary array created

    */
}
