//Search in a 2D matrix
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n*m); SC = O(1)
// bool searchMatrix(vector<vector<int>>& mat, int target) {
//         int row = mat.size();
//         int col = mat[0].size();

//         for(int i=0; i<col; i++){
//             for(int j=0; j<col; j++){
//                 if(mat[i][j] == target){
//                     return true;
//                     break;
//                 }
//             }
//         }

//         return false;
// }

//Better -- TC = O(n*log(m)); SC = O(1)
//1. Mine - recursive
// bool binary_search(vector<vector<int>>& mat, int l, int r, int target, int row){
//     if(l > r){
//         return false;
//     }

//     int mid = l + (r - l)/2;
//     if(target == mat[row][mid]){
//         return true;
//     }
//     else if(target < mat[row][mid]){
//         return binary_search(mat, l, mid-1, target, row);
//     }
//     else{
//         return binary_search(mat, mid+1, r, target, row);
//     }
// }

// bool searchMatrix(vector<vector<int>>& mat, int target) {
//         int row = mat.size();
//         int col = mat[0].size();

//         for(int i=0; i<row; i++){
//             if(target == mat[i][0] || target == mat[i][col-1]){
//                 return true;
//             }
//             else if(target > mat[i][0] && target < mat[i][col-1]){
//                 //binary search
//                 return binary_search(mat, 0, col, target,row);
//             }
//         }

//         return false;
// }

//2. Striver -- iterative - FASTER THAN RECURSIVE
// bool binary_search(vector<int>& nums, int target) {
//     int n = nums.size(); //size of the array
//     int low = 0, high = n - 1;

//     // Perform the steps:
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (nums[mid] == target) return true;
//         else if (target > nums[mid]) low = mid + 1;
//         else high = mid - 1;
//     }
//     return false;
// }

// bool searchMatrix(vector<vector<int>>& mat, int target) {
//         int row = mat.size();
//         int col = mat[0].size();

//         for(int i=0; i<row; i++){
//             if(target == mat[i][0] || target == mat[i][col-1]){
//                 return true;
//             }
//             else if(target > mat[i][0] && target < mat[i][col-1]){
//                 //binary search
//                 return binary_search(mat[i], target);
//             }
//         }

//         return false;
// }

//Optimal -- TC = O(log(n*m)); SC = O(1)
//1. Mine
// bool binary_search_row(vector<int>& nums, int target) {
//     int n = nums.size(); //size of the array
//     int low = 0, high = n - 1;

//     // Perform the steps:
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (nums[mid] == target) return true;
//         else if (target > nums[mid]) low = mid + 1;
//         else high = mid - 1;
//     }
//     return false;
// }

// int binary_search_col(vector<vector<int>>& mat, int target) {
//     int row = mat.size();
//     int col = mat[0].size();
//     int low = 0, high = row - 1;

//     // Perform the steps:
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (mat[mid][0] <= target && mat[mid][col-1] >= target) return mid;
//         else if (target > mat[mid][0]) low = mid + 1;
//         else high = mid - 1;
//     }
//     return -1;
// }

// bool searchMatrix(vector<vector<int>>& mat, int target) {
//     if (mat.empty() || mat[0].empty()) {
//         return false;
//     }

//         int target_row = binary_search_col(mat, target);
//         if (target_row == -1) {
//         return false;
//     }
    
//         return binary_search_row(mat[target_row], target);
// }

//2. Striver
bool searchMatrix(vector<vector<int>> &mat, int target){
    int row = mat.size();
    int col = mat[0].size();
    int l = 0, r = row * col - 1;

    while (l <= r){
        int mid = (l + r) / 2;
        int val = mat[mid / col][mid % col];
        if (val == target)
            return true;
        else if (target < val)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}