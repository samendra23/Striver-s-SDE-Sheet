//Rotate Matrix/Image by 90 degrees
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n*n); SC = O(n*n)
// vector<vector<int>> rotate(vector<vector<int>>& matrix) {
//     int n=matrix.size();
//     vector<vector<int>> res(matrix);
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             // res[j][n-1-i]=matrix[i][j]; //for clock-wise
//             res[i][j]=matrix[j][n-1-i]; //for anti clock-wise
//         }
//     }
//     return res;
// }

// int main(){
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };
//     auto ans = rotate(matrix);
//     for(auto i: ans){
//         for(auto j: i){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

//Optimal -- TC = O(n*n); SC = O(n*n)
void rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    // Transposing
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reversing
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n / 2; j++){
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}

int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotate(matrix);

    for (const auto &row : matrix){
        for (int val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}