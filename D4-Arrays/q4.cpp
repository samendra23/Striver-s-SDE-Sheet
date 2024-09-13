//Longest subarray with sum 0
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^3); SC = O(1)
// int getLongestZeroSumSubarrayLength(vector<int>& a) {
//     int maxLen = 0;
//     for(int i=0; i<a.size(); i++){
//         for(int j=i; j<a.size(); j++){
//             int sum = 0;
//             for(int k=i; k<=j; k++){
//                 sum += a[k];
//             }
// 			if(sum == 0) maxLen = max(maxLen, j-i+1);
//         }
//     }

//     return maxLen;
// }

//Better -- TC = O(n^2); SC = O(1)
// int getLongestZeroSumSubarrayLength(vector<int>& a) {
//     int maxLen = 0;
//     for(int i=0; i<a.size(); i++){
// 		int sum = 0;
//         for(int j=i; j<a.size(); j++){
// 			sum += a[j];
// 			if(sum == 0) maxLen = max(maxLen, j-i+1);
//         }
//     }

//     return maxLen;
// }

//Optimal -- TC = O(n); SC = O(n)
int getLongestZeroSumSubarrayLength(vector<int>& a) {
    int maxLen = 0;
	unordered_map<int, int> mpp;
	int sum = 0;
    for(int i=0; i<a.size(); i++){
		sum += a[i];
		if(sum == 0){
			maxLen = i + 1;
		}
		else if(mpp.find(sum) != mpp.end()){
			maxLen = max(maxLen, i-mpp[sum]);
		}
		else{
			mpp[sum] = i;
		} 
    }
    return maxLen;
}

//Main
int main() {
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << getLongestZeroSumSubarrayLength(a) << endl;

    return 0;
}