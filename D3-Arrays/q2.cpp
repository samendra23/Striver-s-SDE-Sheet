//Pow(x,n)
#include<bits/stdc++.h>
using namespace std;

//Brute -- TC = O(n); SC = O(1)
double myPow(double x, int n)
{
    double res = 1;
    for (int i = 0; i < abs(n); i++)
    {
        res = res * x;
    }
    if (n < 0)
    {
        return 1 / res;
    }
    else
    {
        return res;
    }
}

//Better -- TC = O(n*log(m)); SC = O(1)


//Optimal -- TC = O(log(n*m)); SC = O(1)


int main(){
    cout<<myPow(2,10)<<endl;
}