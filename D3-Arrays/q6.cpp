//Reverse Pairs
//Number of reverse pairs in an array can be defined as the number of pairs of ‘i’, ‘j’ such that ‘i’ < ‘j’ and ‘A[i]’ > 2 * ‘A[j]’.

#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^2); SC = O(1)
// int reversePairs(vector<int> &a, int n){
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         for(int j = i+1; j<n; j++){
//             if(a[i] > 2 * a[j]) cnt++;
//         }
//     }
//     return cnt;
// }

//Optimal -- TC = O(); SC = O(n)
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int l, int mid, int r){
    int cnt = 0;
    int right = mid + 1;
    for(int i=l; i<=mid; i++){
        while(right<=r && arr[i] > 2*arr[right]){
            right++;
        }
        cnt += right - (mid + 1);
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int reversePairs(vector<int> &a, int n){
    return mergeSort(a, 0, n-1);
}

//Main
int main(){
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = reversePairs(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}