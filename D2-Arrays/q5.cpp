//Reverse Pairs
//Number of reverse pairs in an array can be defined as the number of pairs of ‘i’, ‘j’ such that ‘i’ < ‘j’ and ‘A[i]’ > 2 * ‘A[j]’.

#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^2); SC = O(1)
// vector<int> findMissingRepeatingNumbers(vector < int > a) {
//     int n = a.size(); // size of the array
//     int repeating = -1, missing = -1;

//     //Find the repeating and missing number:
//     for (int i = 1; i <= n; i++) {
//         //Count the occurrences:
//         int cnt = 0;
//         for (int j = 0; j < n; j++) {
//             if (a[j] == i) cnt++;
//         }

//         if (cnt == 2) repeating = i;
//         else if (cnt == 0) missing = i;

//         if (repeating != -1 && missing != -1)
//             break;
//     }
//     return {repeating, missing};
// }

//Better -- TC = O(2*n); SC = O(n)
// vector<int> findMissingRepeatingNumbers(vector < int > a) {
//     int n = a.size(); // size of the array
//     int hash[n + 1] = {0}; // hash array

//     //update the hash array:
//     for (int i = 0; i < n; i++) {
//         hash[a[i]]++;
//     }

//     //Find the repeating and missing number:
//     int repeating = -1, missing = -1;
//     for (int i = 1; i <= n; i++) {
//         if (hash[i] == 2) repeating = i;
//         else if (hash[i] == 0) missing = i;

//         if (repeating != -1 && missing != -1)
//             break;
//     }
//     return {repeating, missing};
// }

//Optimal -- TC = O(n); SC = O(1)
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    long long n = a.size();
    //S - Sn
    //S2 - Sn2
    //x -> repeating
    //y -> missing
    long long Sn = n*(n+1)/2;
    long long Sn2 = n*(n+1)*(2*n+1)/6;

    long long S = 0, S2 = 0;
    for(int i=0; i<n; i++){
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    long long e1 = S - Sn; //x-y
    long long e2 = S2 - Sn2;
    long long e3 = e2/e1; //x+y

    long long repeating = (e1 + e3)/2;
    long long missing = repeating - e1;

    return {(int)repeating, (int)missing};
}

//Main
int main(){
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}