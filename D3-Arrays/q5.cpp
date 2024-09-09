//Unique Paths
#include<bits/stdc++.h>
using namespace std;

//Brute (Using Recursion) -- TC = O(2^(m+n)) - exponential; SC = O(m+n) - too high
// int countPaths(int i, int j, int m, int n)
// {
//     if (i == m - 1 && j == n - 1)
//         return 1;
//     else if (i > m || j > n)
//         return 0;
//     else
//         return countPaths(i + 1, j, m, n) + countPaths(i, j + 1, m, n);
// }

// int uniquePaths(int m, int n)
// {
//     return countPaths(0, 0, m, n);
// }

//Better (Using DP) -- TC = O(n*m); SC = O(n*m)
// int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
// {
//     if (i == m - 1 && j == n - 1)
//         return 1;
//     else if (i >= m || j >= n)
//         return 0;

//     if (dp[i][j] != -1)
//         return dp[i][j];
//     else
//         return dp[i][j] = countPaths(i + 1, j, m, n, dp) + countPaths(i, j + 1, m, n, dp);
// }

// int uniquePaths(int m, int n)
// {
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     return countPaths(0, 0, m, n, dp);
// }

//Optimal (Using Combinatorics/Combination) -- TC = O(n-1) or O(m-1); SC = O(1)
int uniquePaths(int m, int n)
{
    // we calculate NCr
    int N = m + n - 2;
    int r = n - 1;
    double res = 1;

    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;
    }

    return int(res);
}

int main(){
    int totalCount= uniquePaths(3,7);
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}