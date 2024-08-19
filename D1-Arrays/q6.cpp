//Stock Buy and Sell
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(N*N); SC = O(1)
int maxProfit(vector<int>& arr){
    int profit = 0;
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            profit = max(profit, arr[j]-arr[i]);
        }
    }
    return profit;
}


//Optimal -- TC = O(n); SC = O(1)
// int maxProfit(vector<int>& arr){
//     int min = INT_MAX;
//     int profit = 0;
//     for(int i=0; i<arr.size(); i++){
//         if(arr[i]<min){
//             min=arr[i];
//         }
//         profit = max(profit, arr[i]-min);
//     }
//     return profit;
// }

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}