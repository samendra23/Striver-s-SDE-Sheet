//Longest Consecutive Sequence in an Array
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^2); SC = O(1)
// bool linearSearch(vector<int> &a, int num){
//     for(int i=0; i<a.size(); i++){
//         if(a[i] == num){
//             return true;
//         }
//     }
//     return false;
// }

// int longestSuccessiveElements(vector<int>&a) {
//     int longest = 0;
//     for(int i=0; i<a.size(); i++){
//         int x = a[i];
//         int cnt = 1;
//         while(linearSearch(a, x+1) == true){
//             x = x+1;
//             cnt++;
//         }
//         longest = max(longest, cnt);
//     }
//     return longest;
// }

//Better -- TC = O(n*nlogn); SC = O(1)
// int longestConsecutive(vector<int> &a){
//     if (a.size() == 0)
//         return 0;
//     sort(a.begin(), a.end());
//     int longest = 0;
//     int cnt = 1;
//     for (int i = 1; i < a.size(); i++){
//         if (a[i] == a[i - 1] + 1)
//             cnt++;
//         else if (a[i] != a[i - 1]){
//             longest = max(longest, cnt);
//             cnt = 1;
//         }
//     }
//     longest = max(longest, cnt);
//     return longest;
// }

//Optimal -- TC = O(3*n); SC = O(n)
int longestSuccessiveElements(vector<int>&a) {
    if (a.size() == 0) return 0;

    unordered_set<int> st;
    for(int i=0; i<a.size(); i++){
        st.insert(a[i]);
    }

    int longest = 1;
    int cnt = 1;
    for(auto it: st){
        if (st.find(it - 1) == st.end()) { // if it is starting elem, its previous doesn't exist
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){ //if next element exists
                x = x+1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

//Main
int main(){
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}