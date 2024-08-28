//Merge Two Sorted Arrays without Extra Space
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n+m)+O(n+m); SC = O(n+m)
// void merge(long long arr1[], long long arr2[], int n, int m) {

//     long long arr3[n + m];
//     int left = 0;
//     int right = 0;

//     int index = 0;

//     while (left < n && right < m) {
//         if (arr1[left] <= arr2[right]) {
//             arr3[index] = arr1[left];
//             left++, index++;
//         }
//         else {
//             arr3[index] = arr2[right];
//             right++, index++;
//         }
//     }

//     // If right pointer reaches the end:
//     while (left < n) {
//         arr3[index++] = arr1[left++];
//     }

//     // If left pointer reaches the end:
//     while (right < m) {
//         arr3[index++] = arr2[right++];
//     }

//     // Fill back the elements from arr3[]
//     // to arr1[] and arr2[]:
//     for (int i = 0; i < n + m; i++) {
//         if (i < n) arr1[i] = arr3[i];
//         else arr2[i - n] = arr3[i];
//     }
// }

//Optimal 1 -- TC = O(min(n,m)) + O(nlogn) + O(mlogm); SC = O(1)
void merge(long long a[], long long b[], int n, int m){	
    int i = n-1, j = 0;
	while(i>=0 && j<m){
		if(a[i] > b[j]){
			swap(a[i--], b[j++]);
		}
		else{
			break;
		}
	}
	sort(a, a+n);
	sort(b, b+m);
}

//Optimal 2 -- TC = O(min(n,m)) + O(nlogn) + O(mlogm); SC = O(1)

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}

//leetcode - Merge Arrays into the First Array -- TC = O(n+m); SC = O(1)
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m-1, j = n-1, k = m+n-1;
//         while(i>=0 && j>=0){
//             if(nums1[i] > nums2[j]){
//                 nums1[k]=nums1[i];
//                 i--;
//                 k--;
//             }
//             else{
//                 nums1[k] = nums2[j];
//                 j--;
//                 k--;
//             }
//         }
//         while(j>=0){
//             nums1[k]=nums2[j];
//             j--;
//             k--;
//         }
//     }
// };