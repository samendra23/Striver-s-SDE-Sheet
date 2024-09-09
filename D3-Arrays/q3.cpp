//Majority Element that occurs > n/2 times
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n*n); SC = O(1)
// int majorityElement(vector<int> v) {
//     //size of the given array:
//     int n = v.size();

//     for (int i = 0; i < n; i++) {
//         //selected element is v[i]
//         int cnt = 0;
//         for (int j = 0; j < n; j++) {
//             // counting the frequency of v[i]
//             if (v[j] == v[i]) {
//                 cnt++;
//             }
//         }

//         // check if frquency is greater than n/2:
//         if (cnt > (n / 2))
//             return v[i];
//     }
//     return -1;
// }

//Better -- TC = O(n*log(n)) + O(n); SC = O(n)
//1. Striver
// int majorityElement(vector<int> v) {

//     //size of the given array:
//     int n = v.size();

//     //declaring a map:
//     map<int, int> mpp;

//     //storing the elements with its occurnce:
//     for (int i = 0; i < n; i++) {
//         mpp[v[i]]++;
//     }

//     //searching for the majority element:
//     for (auto it : mpp) {
//         if (it.second > (n / 2)) {
//             return it.first;
//         }
//     }
//     return -1;
// }

//2. Mine
//TC = O(n); SC = O(n)
int majorityElement(vector<int> &v)
{
    unordered_map<int, int> mpp;
    int num = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if (mpp.find(v[i]) != mpp.end())
        {
            mpp[v[i]]++;
            if (mpp[v[i]] > (v.size() / 2))
            {
                num = v[i];
                break;
            }
        }
        else
        {
            mpp[v[i]] = 1;
        }
    }
    return num;
}

//Optimal -- TC = O(log(n*m)); SC = O(1)


int main(){
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}