//Maximm subarray sum (Kadane's algorithm)
#include <bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n*3); SC = O(1)
// int maxSubarraySum(int arr[], int n) {
//     int maxi = INT_MIN; // maximum sum

//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             // subarray = arr[i.....j]
//             int sum = 0;

//             //add all the elements of subarray:
//             for (int k = i; k <= j; k++) {
//                 sum += arr[k];
//             }

//             maxi = max(maxi, sum);
//         }
//     }

//     return maxi;
// }

//Better -- TC = O(n*2); SC = O(1)
// int maxSubarraySum(int arr[], int n){
//     int maxi = INT_MIN; // maximum sum
//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum += arr[j];
//             maxi = max(maxi, sum);
//         }
//     }
//     return maxi;
// }

//Optimal -- TC = O(n); SC = O(1)
int maxSubarraySum(int arr[], int n){
    int maxi = INT_MIN;
    int sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum>maxi){
            maxi = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    return maxi;
}

//leetcode
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        long long maxi = LONG_MIN;
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum = sum + arr[i];
            if(sum>maxi){
                maxi=sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}