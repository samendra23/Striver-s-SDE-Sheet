//Find the duplicate in an array of N+1 integers
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n*logn) + O(n); SC = O(1)
// int findDuplicate(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     int ans;
//     for(int i=0; i<nums.size(); i++){
//         if(nums[i]==nums[i+1]){
//             ans = nums[i];
//             break;
//         }
//     }
//     return ans;
// }

//Optimal -- TC = O(n*logn) + O(n); SC = O(n)
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int freq[n] = {0};
    int ans;

    for(int i=0; i<n; i++){
        if(freq[nums[i]] == 0){
            freq[nums[i]]++;
        }
        else{
            ans = nums[i];
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> arr;
    arr = {1, 3, 4, 2, 2};
    cout << "The duplicate element is " << findDuplicate(arr) << endl;
}