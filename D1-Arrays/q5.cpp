//Sort array of 0's, 1's and 2's OR Sort colours(Dutch National Flag algo.)
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(N*logN); SC = O(1) - Using a sorting algorithm
// int main(){
//     int n = 6;
//     vector<int> arr = {0, 2, 1, 2, 0, 1};
//     sort(arr.begin(), arr.end());
//     cout << "After sorting:" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

//Better -- TC = O(N)+O(N) = O(2N); SC = O(1)
// void sortArray(vector<int>& arr){
//     int n = arr.size();
//     int cnt0=0, cnt1=0, cnt2=0;
//     for(int i=0; i<n; i++){
//         if(arr[i]==0) cnt0++;
//         else if(arr[i]==1) cnt1++;
//         else cnt2++;
//     }
//     for(int i=0; i<cnt0; i++){
//         arr[i]=0;
//     }
//     for(int i=cnt0; i<cnt0+cnt1; i++){
//         arr[i]=1;
//     }
//     for(int i=cnt0+cnt1; i<n; i++){
//         arr[i]=2;
//     }
// }

// int main(){
//     int n = 6;
//     vector<int> arr = {0, 2, 1, 2, 0, 1};
//     sortArray(arr);
//     cout << "After sorting:" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

//Optimal -- TC = O(N); SC = O(1) - DNF(Dutch National Flag) Algorithm
void sortArray(vector<int>& arr){
    int low = 0, mid = 0, high = arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}