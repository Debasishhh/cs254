#include<bits/stdc++.h>
using namespace std;

int maxCrossingSum(vector<int>v, int l, int h, int m){
    int sum=0;
    int leftSum=INT_MIN;
    for(int i=m;i>=l;i--){
        sum+=v[i];
        leftSum=max(leftSum,sum);
    }
    sum=0;
    int rightSum=INT_MIN;
    for(int i=m;i<=h;i++){
        sum+=v[i];
        rightSum=max(rightSum,sum);
    }
    return max(leftSum,max(rightSum, leftSum+rightSum-v[m]));
}

int MaxSumOfSubarray(vector<int>a,int l, int h){
    if(l>h) return INT_MIN;
    if(l==h) return a[l];
    int mid=(l+h)/2;
    return max(maxCrossingSum(a,l,h,mid),(MaxSumOfSubarray(a,l,mid-1),MaxSumOfSubarray(a,mid+1,h)));
}

int main(){
   
    ifstream arrFile("input.txt");
    vector<int> arr;
    if (!arrFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }
    int x;
    while (arrFile >> x) arr.push_back(x);
    arrFile.close();
    int n=arr.size();
    int result = MaxSumOfSubarray(arr,0,n-1);

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }
    outputFile <<"Maximum subarray sum: "<< result << endl;
    outputFile.close();
    cout << "Data has been written to output.txt." << endl;

    return 0;
    /*
    Analysis of complexity:
    Here we divide the problem to find max subarray into 2 parts. T(n)=2T(n/2)+O(n); as maxcrossingsum function takes O(n) time.
    by master's theorem, T(n)=O(nlogn)
    */
}