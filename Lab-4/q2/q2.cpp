#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
2. Given two sorted arrays nums1 and nums2 of size m and n, respectively;
return the median of the two sorted arrays.
Example:
input: nums1 = [1, 3], nums2 = [2]
output: 2.00000
*/


double medina(vector<ll> &nums1, vector<ll> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();

    if (n1 > n2)
        return medina(nums2, nums1);

    int n = n1 + n2;
    int left = (n1 + n2 + 1) / 2;
    int low = 0, high = n1;

    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 < n2)
            r2 = nums2[mid2];
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }

    return 0;
}
int main()
{
    vector<ll> v1, v2;
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++)
    {
        ll q;
        cin >> q;
        v1.push_back(q);
    }
    ll m;
    cin >> m;
    for(ll i = 0; i < m; i++)
    {
        ll q;
        cin >> q;
        v2.push_back(q);
    }
    double ans = medina(v1, v2);
    cout << ans << endl;
    return 0;
    /*
    samplel input:
    4
    1 2 2 3
    3 
    1 4 5
    output:2

    Analysis:
    in this algorithm binary search is used on smaller of the 2 arrays, so time complexity is O(min(logm,logn)).
    as no extra space is used, space complexity is O(1).
    */
}