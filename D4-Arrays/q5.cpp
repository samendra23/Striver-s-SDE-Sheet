//
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^3); SC = O(1)
// int subarraysWithSumK(vector < int > a, int target) {
//     int cnt = 0;
//     for(int i=0; i<a.size(); i++){
//         for(int j=i; j<a.size(); j++){
//             int xorr = 0;
//             for(int k=i; k<=j; k++){
//                 xorr = xorr^a[k];
//             }
//             if(xorr == target) cnt++;
//         }
//     }
//     return cnt;
// }

//Better -- TC = O(n^2); SC = O(1)
// int subarraysWithSumK(vector < int > a, int target) {
//     int cnt = 0;
//     for(int i=0; i<a.size(); i++){
//         int xorr = 0;
//         for(int j=i; j<a.size(); j++){
//             xorr = xorr^a[j];
//             if(xorr == target) cnt++;
//         }
//     }
//     return cnt;
// }

//Optimal -- TC = O(n); SC = O(n)
int subarraysWithSumK(vector < int > a, int target) {
    // Write your code here
    int cnt = 0;
    int xorr = 0;

    //x = XR^k
    unordered_map<int, int> mpp; //mpp[x] = [count]
    mpp[xorr]++; //{0,1} map creates it as 0 and then adds 1
    for(int i=0; i<a.size(); i++){
        xorr = xorr^a[i];
        int x = xorr^target;
        cnt += mpp[x]; //if x doesn't exist, map returns 0
        mpp[xorr]++; //if xorr doesn't exist, map creates it
    }
    return cnt;
}

//Main
int main(){
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithSumK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}