//Rotate Matrix/Image by 90
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n*n); SC = O(n*n)
vector<vector<int>> rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>> res(matrix);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            res[j][n-1-i]=matrix[i][j];
        }
    }
    return res;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    auto ans = rotate(matrix);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}