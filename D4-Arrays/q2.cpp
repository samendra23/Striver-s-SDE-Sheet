//4 Sum
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^4); SC = O(2*no. of quadruplets)
// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     int n = nums.size();
//     set<vector<int>> st;

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             for (int k = j + 1; k < n; k++) {
//                 for (int l = k + 1; l < n; l++) {
//                     long long sum = nums[i] + nums[j];
//                     sum += nums[k];
//                     sum += nums[l];

//                     if (sum == target) {
//                         vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

//Better -- TC = O(n^3 * log(no. of elements in set))); SC = O(2 * no. of quadruplets)
vector<vector<int>> fourSum(vector<int>& arr, int target) {
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<int> hash;
            for (int k = j + 1; k < n; k++) {
                int fourth = target - (arr[i] + arr[j] + arr[k]);
                if(hash.find(fourth) != hash.end()){
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hash.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//Optimal -- TC = O(); SC = O()


//Main
int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}