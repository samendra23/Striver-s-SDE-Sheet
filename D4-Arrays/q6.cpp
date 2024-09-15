//
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n^3); SC = O(n)
int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
        return 0;

    int maxi = 1;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            unordered_set<int> st;
            int cnt = 0;
            for (int k = i; k <= j; k++)
            {
                if (st.find(s[k]) != st.end())
                {
                    break;
                }
                else
                {
                    st.insert(s[k]);
                    cnt++;
                }
            }
            maxi = max(maxi, cnt);
        }
    }
    return maxi;
}

//Better -- TC = O(); SC = O()


//Optimal -- TC = O(); SC = O()


//Main
int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is " << 
  lengthOfLongestSubstring(str);
  return 0;
}