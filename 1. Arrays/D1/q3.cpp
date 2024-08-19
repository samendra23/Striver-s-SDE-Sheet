//Next permutation
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(N!*N); SC = O(1)

//Better -- inbuilt STL function
// int main() {
//     int arr[] = {2,3,5,4,1,0,0};
    
//     next_permutation(arr,arr+7);//using in-built function of C++
    
//     cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<" "<<arr[6];
    
//     return 0;
// }

//Optimal -- TC = O(N)+O(N)+O(N) = O(3N); SC = O(1)
vector<int> nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int ind = -1;
    for(int i=n-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(nums.begin(), nums.end());
        return nums;
    }
    else{
        for(int i=n-1; i>ind; i--){
            if(nums[i]>nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1, nums.end());
        return nums;
    }
}

int main(){
    vector<int> nums = {2,3,5,4,1,0,0};
    vector<int> res = nextPermutation(nums);
    for(auto i: res){
        cout<<i<<" ";
    }
    return 0;
}