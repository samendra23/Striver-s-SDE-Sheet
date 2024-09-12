//3 Sum
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^3 * log(no. of unique triplets)); SC = O(2 * no. of unique triplets)
// vector<vector<int>> triplet(int n, vector<int> &arr) {
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             for (int k = j + 1; k < n; k++) {
//                 if (arr[i] + arr[j] + arr[k] == 0) {
//                     vector<int> temp = {arr[i], arr[j], arr[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }

//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

//Better -- TC = O(n^2 * log(no. of unique triplets)); SC = O(2 * no. of unique triplets) + O(n)
vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;
    
    for (int i = 0; i < n; i++) {
        set<int> hash;
        for (int j = i + 1; j < n; j++) {
            int third = -(arr[i] + arr[j]);
            if(hash.find(third) != hash.end()){
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hash.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//Optimal -- TC = O(); SC = O()


//Main
int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}