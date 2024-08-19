//Pascal's Triangle - 3 Variations
#include <bits/stdc++.h>
using namespace std;

//1. Given R and C, tell element at R row and place C
//Brute -- TC = O(R-1)+O(C-1)+O(R-C); SC = O(1)
// int elem(int r, int c){
//     int rfac = 1;
//     int cfac = 1;
//     int rcfac = 1;
//     for(int i = 1; i <= r; i++){
//         rfac = rfac*i;
//     }
//     for(int i = 1; i <= c; i++){
//         cfac = cfac*i;
//     }
//     for(int i=1; i<=(r-c); i++){
//         rcfac = rcfac*i;
//     }
//     return rfac/(cfac*rcfac);
// }

//Better -- TC = O(C); SC = O(1)
// int elem(int r, int c){
//     long long res = 1;
//     for(int i=0; i<c; i++){
//         res = res*(r-i)/(i+1);
//     }
//     return res;
// }

// int main(){
//     int r=5, c=3;
//     cout<<elem(r-1,c-1);
// }

//2. Print Nth row
//Brute -- TC = O(R*C); SC = O(1)
// int elem(int r, int c){
//     long long res = 1;
//     for(int i=0; i<c; i++){
//         res = res*(r-i)/(i+1);
//     }
//     return res;
// }

// void pascalRow(int n){
//     for(int c=1; c<=n; c++){
//         cout<<elem(n-1, c-1)<<" ";
//     }
// }

//Beter -- TC = O(n); SC = O(1)
// void pascalRow(int n){
//     int ans = 1;
//     cout<<ans<<" ";
//     for(int c=1; c<n; c++){
//         ans = ans*(n-c)/c;
//         cout<<ans<<" ";
//     }
// }

// int main(){
//     int n = 5;
//     pascalRow(n);
// }

//3. Given N, print entire triangle
//Brute -- TC = O(n*n*r) ~ O(n^3); SC = O(1)
// int nCr(int row, int col){
//     long long res=1;
//     for(int i=0; i<col; i++){
//         res=res*(row-i);
//         res=res/(i+1);
//     }
//     return (int)(res);
// }

// vector<vector<int>> pascalTriangle(int N) {
//     // Write your code here.
//     vector<vector<int>> ans;
//     for(int row=1; row<=N; row++){
//         vector<int> temp;
//         for(int col=1; col<=row; col++){
//             temp.push_back(nCr(row-1, col-1));
//         }
//         ans.push_back(temp);
//     }
//     return ans;
// }

//Better -- TC = O(n*n); SC = O(1)
vector<int> pascalRow(int n){
    int ans = 1;
    vector<int> ansRow;
    ansRow.push_back(ans);
    for(int c=1; c<n; c++){
        ans = ans*(n-c)/c;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int N) {
    // Write your code here.
    vector<vector<int>> ans;
    for(int row=1; row<=N; row++){
        vector<int> temp = pascalRow(row);
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    int n=5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}