//Pow(x,n)
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n); SC = O(1)
// double myPow(double x, int n)
// {
//     double res = 1;
//     for (int i = 0; i < abs(n); i++)
//     {
//         res = res * x;
//     }
//     if (n < 0)
//     {
//         return 1 / res;
//     }
//     else
//     {
//         return res;
//     }
// }

//Optimal -- TC = O(log(n)); SC = O(1)
double myPow(double x, int n)
{
    double res = 1;
    long long nn = abs(n);
    while (nn)
    {
        if (nn % 2 == 0)
        {
            x = x * x;
            nn = nn / 2;
        }
        else
        {
            res = res * x;
            nn = nn - 1;
        }
    }

    if (n < 0)
        res = 1 / res;
    return res;
}

int main(){
    cout<<myPow(2,10)<<endl;
}