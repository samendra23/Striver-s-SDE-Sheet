//Majority Element that occurs > n/3 times
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n*n); SC = O(1)
vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
}

//Better -- TC = O(n); SC = O(n)
// vector<int> majorityElement(vector<int> &nums)
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

//Optimal


int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}