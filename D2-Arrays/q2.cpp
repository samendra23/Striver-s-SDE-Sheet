//Merge Overlapping Sub-intervals
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n*logn) + O(2*n); SC = O(n)
// vector<vector<int>> merge(vector<vector<int>>& v) {
//     int n = v.size();
//     sort(v.begin(), v.end());
//     vector<vector<int>> res;

//     for(int i=0; i<n; i++){
//         int start = v[i][0];
//         int end = v[i][1];
//         if(!res.empty() && end <= res.back()[1]){
//             continue;
//         }
//         for(int j=i+1; j<n; j++){
//             if(v[j][0] <= end){
//                 end = max(end, v[j][1]);
//             }
//             else{
//                 break;
//             }
//         }
//         res.push_back({start, end});
//     }
//     return res;
// }

//Optimal -- TC = O(n*n); SC = O(n*n)


int main() {
    vector<vector<int>> intervals = {{2,3},{2,2},{3,3},{1,3},{5,7},{2,2},{4,6}};    
    vector<vector<int>> mergedIntervals = merge(intervals);
    
    cout << "Merged Intervals:" << endl;
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    
    return 0;
}