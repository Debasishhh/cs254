#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*
3. Given an integer array nums and an integer k, return the kth largest element in the array.
(Note that it is the kth largest element in the sorted order, not the k
th distinct element.)
Example:
input: nums = [3, 2, 1, 5, 6, 4], k = 2
output: 5
*/

int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            swap(arr[i], arr[j]); 
            i++; 
        } 
    } 
    swap(arr[i], arr[r]); 
    return i; 
} 

int kthSmallest(int arr[], int l, int r, int k) 
{ 

    if (k > 0 && k <= r - l + 1) { 
        int index = partition(arr, l, r); 
        if (index - l == k - 1) 
            return arr[index]; 
        if (index - l > k - 1)  
            return kthSmallest(arr, l, index - 1, k); 
        return kthSmallest(arr, index + 1, r, k - index + l - 1); 
    } 
    return INT_MAX; 
} 

int main(){
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"kth largest element is: "<<kthSmallest(arr,0,n-1,n-k+1);
    return 0;

    /*
    Analysis:
    in this algorithm the size of the array reduces as we consider left or right part of array according to index and k. so this reduces complexity from nlogn of quicksort to O(n). but worst case is still O(n^2).
    space complexity is O(1) as no extra space is used. 
    */
}
  