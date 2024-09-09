//Majority Element that occurs > n/3 times
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n*n); SC = O(1)


//Better -- TC = O(n*log(n)) + O(n); SC = O(n)


//Optimal -- TC = O(n) + O(n); SC = O(1)
vector<int> majorityElement(vector<int> &nums){
    unordered_map<int, int> mpp;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++){
        mpp[nums[i]]++;
    }

    for (auto i : mpp){
        if (i.second > nums.size() / 3)
        {
            ans.push_back(i.first);
        }
    }

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