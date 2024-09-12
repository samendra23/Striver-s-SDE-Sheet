//Longest Consecutive Sequence in an Array
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(); SC = O()
//1. Mine
int longestSuccessiveElements(vector<int>& a) {
    // Sort the array
    sort(a.begin(), a.end());

    int maxi = 1; // Initialize the maximum length to 1
    int cnt = 1;  // To track the current consecutive sequence

    for (int i = 1; i < a.size(); i++) {
        if (a[i] == a[i - 1] + 1) {
            // If consecutive, increase count
            cnt++;
        } else if (a[i] != a[i - 1]) {
            // Reset count if not consecutive, and it's not a duplicate
            maxi = max(maxi, cnt);
            cnt = 1;
        }
    }

    // Compare the last sequence count
    maxi = max(maxi, cnt);

    return maxi;
}

//Better -- TC = O(); SC = O()


//Optimal -- TC = O(); SC = O()


//Main
int main(){
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}