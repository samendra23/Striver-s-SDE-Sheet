//
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^3); SC = O(1)
int subarraysWithSumK(vector < int > a, int target) {
    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        for(int j=i; j<a.size(); j++){
            int xorr = 0;
            for(int k=i; k<=j; k++){
                xorr = xorr^a[k];
            }
            if(xorr == target) cnt++;
        }
    }
    return cnt;
}

//Better -- TC = O(); SC = O()


//Optimal -- TC = O(); SC = O()


//Main
int main(){
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithSumK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}