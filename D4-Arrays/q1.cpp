//2sum
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^2); SC = O(1)
vector<int> twoSum(vector<int> &nums, int target)
{
    int l = nums.size();
    int i, j;
    for (i = 0; i < l; i++)
    {
        for (j = i + 1; j < l; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                // break;
                return {i, j};
            }
        }
    }
    return {};
}

//Better -- TC = O(); SC = O()


//Optimal -- TC = O(); SC = O()


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