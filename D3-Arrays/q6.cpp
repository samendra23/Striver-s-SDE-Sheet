//Unique Paths
#include<bits/stdc++.h>
using namespace std;

//Brute (Using Recursion) -- TC = O(n*n); SC = O(1)
int countPairs(vector<int> &a, int n){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(a[i] > 2 * a[j]) cnt++;
        }
    }
    return cnt;
}

//Better (Using DP) -- TC = O(n*m); SC = O(n*m)


//Optimal (Using Combinatorics/Combination) -- TC = O(n-1) or O(m-1); SC = O(1)


int main(){
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = countPairs(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}