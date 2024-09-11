//2sum
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^2); SC = O(1)
// vector<int> twoSum(vector<int> &nums, int target){
//     int n = nums.size();
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){
//             if (nums[i] + nums[j] == target){
//                 return {i, j};
//             }
//         }
//     }
//     return {0};
// }

//Better (Using Hashing) -- TC = O(n) or O(n^2) in worst case for unordered_map; SC = O(n)
// vector<int> twoSum(vector<int> &nums, int target){
//     int n = nums.size();
//     unordered_map<int, int> mpp;
//     for (int i = 0; i < n; i++){
//         if (mpp.find(target - nums[i]) != mpp.end()){
//             return {mpp[target - nums[i]], i};
//         }
//         else{
//             mpp.insert({nums[i], i});
//         }
//     }
//     return {0};
// }

//Optimal (Using 2-pointer approach) -- TC = O(n) + O(n*logn); SC = O(1)
vector<int> twoSum(vector<int> &nums, int target){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0, j = n - 1;
    while (i < j){
        int sum = nums[i] + nums[j];
        if (sum == target)
            return {i, j};
        else if (sum < target)
            i++;
        else
            j--;
    }
    return {0};
}

//Main
int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(arr, target);
    for(auto it: ans){
        cout<<arr[it]<<" ";
    }
    return 0;
}