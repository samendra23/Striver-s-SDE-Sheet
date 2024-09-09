vector<int> majorityElement(vector<int> &nums)
// {
//     unordered_map<int, int> mpp;
//     vector<int> ans;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         mpp[nums[i]]++;
//         if (mpp[nums[i]] == (nums.size() / 3) + 1)
//         {
//             ans.push_back(nums[i]);
//         }
//     }

//     return ans;
// }