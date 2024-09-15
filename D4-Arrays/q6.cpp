//Length of Longest Substring without any Repeating Character
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^3); SC = O(n)
// int lengthOfLongestSubstring(string s)
// {
//     if (s.length() == 0)
//         return 0;

//     int maxi = 1;
//     for (int i = 0; i < s.length(); i++)
//     {
//         for (int j = i + 1; j < s.length(); j++)
//         {
//             unordered_set<int> st;
//             int cnt = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 if (st.find(s[k]) != st.end())
//                 {
//                     break;
//                 }
//                 else
//                 {
//                     st.insert(s[k]);
//                     cnt++;
//                 }
//             }
//             maxi = max(maxi, cnt);
//         }
//     }
//     return maxi;
// }

//Better -- TC = O(n^2); SC = O(n)
int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
        return 0;

    int maxi = 1;
    for (int i = 0; i < s.length(); i++)
    {
        unordered_set<int> st;
        int cnt = 0;
        for (int j = i; j < s.length(); j++)
        {
            if (st.find(s[j]) != st.end())
            {
                break;
            }
            else
            {
                st.insert(s[j]);
                cnt++;
            }
        }
        maxi = max(maxi, cnt);
    }
    return maxi;
}

//Optimal -- TC = O(); SC = O()


//Main
int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is " << 
  lengthOfLongestSubstring(str);
  return 0;
}