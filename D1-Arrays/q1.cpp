//Set Matrix Zeroes
//Brute -- TC = O((n*m)*(n+m))+O(n*m); SC = O(1)
class Solution {
public:
    void markrow(vector<vector<int>>& mat, int row, int col, int i) {
        for(int j = 0; j < col; j++) {
            if(mat[i][j] != 0) {
                mat[i][j] = -1;
            }
        }
    }

    void markcol(vector<vector<int>>& mat, int row, int col, int j) {
        for(int i = 0; i < row; i++) {  // Corrected from `col` to `row`
            if(mat[i][j] != 0) {
                mat[i][j] = -1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(mat[i][j] == 0) {
                    markrow(mat, row, col, i);
                    markcol(mat, row, col, j);
                }
            }
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(mat[i][j] == -1) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};

//Better -- TC = O(n*m)+O(n*m) = O(2*(n*m)); SC = O(n+m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<int> rarr(row, 0);
        vector<int> carr(col, 0);

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(mat[i][j] == 0) {
                    rarr[i]=1;
                    carr[j]=1;
                }
            }
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(rarr[i]==1 || carr[j]==1) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};

//Optimal -- TC = O(2*(n*m)); SC = O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int col0 = 1;
        int row = mat.size();
        int col = mat[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    if (j != 0) {
                        mat[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < col; j++) {
            if (mat[0][0] == 0) {
                mat[0][j] = 0;
            }
        }

        for (int i = 0; i < row; i++) {
            if (col0 == 0) {
                mat[i][0] = 0;
            }
        }
    }
};
