int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
        return 0;

    int maxi = 1;
    unordered_map<int, int> mpp;
    int l = 0, r = 0;

    while (r < s.length())
    {
        if (mpp.find(s[r]) != mpp.end())
        {
            l = max(l, mpp[s[r]] + 1);
        }
        mpp[s[r]] = r;
        r++;
        maxi = max(maxi, r - l);
    }
    return maxi;
}