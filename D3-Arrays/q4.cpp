//Majority Element that occurs > n/3 times
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n*n); SC = O(1)
// vector<int> majorityElement(vector<int> v) {
//     int n = v.size(); //size of the array
//     vector<int> ls; // list of answers

//     for (int i = 0; i < n; i++) {
//         //selected element is v[i]:
//         // Checking if v[i] is not already
//         // a part of the answer:
//         if (ls.size() == 0 || ls[0] != v[i]) {
//             int cnt = 0;
//             for (int j = 0; j < n; j++) {
//                 // counting the frequency of v[i]
//                 if (v[j] == v[i]) {
//                     cnt++;
//                 }
//             }

//             // check if frquency is greater than n/3:
//             if (cnt > (n / 3))
//                 ls.push_back(v[i]);
//         }

//         if (ls.size() == 2) break;
//     }

//     return ls;
// }

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

//Optimal -- TC = O(n) + O(n); SC = O(1)
vector<int> majorityElement(vector<int> &v)
{
    int el1 = 0, el2 = 0, cnt1 = 0, cnt2 = 0;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != v[i])
        {
            el1 = v[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0 && el1 != v[i])
        {
            el2 = v[i];
            cnt2 = 1;
        }
        else if (el1 == v[i])
            cnt1++;
        else if (el2 == v[i])
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ans;
    cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == el1)
            cnt1++;
        else if (v[i] == el2)
            cnt2++;
    }

    int mini = int(n / 3) + 1;

    if (cnt1 >= mini)
        ans.push_back(el1);
    if (cnt2 >= mini)
        ans.push_back(el2);

    return ans;
}

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