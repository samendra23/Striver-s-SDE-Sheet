//SEarch in a 2D matrix
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n*m); SC = O(1)
bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row = mat.size();
        int col = mat[0].size();

        for(int i=0; i<col; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j] == target){
                    return true;
                    break;
                }
            }
        }

        return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}