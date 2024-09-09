int majorityElement(vector<int> &v)
// {
//     unordered_map<int, int> mpp;
//     int num = v[0];
//     for (int i = 0; i < v.size(); i++)
//     {
//         if (mpp.find(v[i]) != mpp.end())
//         {
//             mpp[v[i]]++;
//             if (mpp[v[i]] > (v.size() / 2))
//             {
//                 num = v[i];
//                 break;
//             }
//         }
//         else
//         {
//             mpp[v[i]] = 1;
//         }
//     }
//     return num;
// }