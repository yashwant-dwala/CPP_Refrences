#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007


/////// ........  NO PRINTING ONLY RETURNS VALUES....................

///////  ........ H E L P E R  F U N C T I O N S ........... ////////// 

vector<vector<ll>> nCrdp(101,vector<ll> (101,-1));
// 	n C r
ll combination(ll n,ll r){
    if(r>n) return 0;
    if(n<=1 or r==0 or r==n) return 1;
    if(r==1 or n-r==1) return n;

    if(nCrdp[n][r] != -1) return nCrdp[n][r];
    ll ans = combination(n-1,r-1)%mod + combination(n-1,r)%mod ;
    return nCrdp[n][r] = (ans)%mod;
}
//....faster
ll combination(int n,int r){
    int C[r+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%mod;
    }
    return C[r];
}
// .................................
// P O W E R
ll power(ll a, ll b) {
a %= mod;
ll ans = 1;
while (b) {
    if (b & 1) ans = (a * ans) % mod;
    a = (a * a) % mod;
    b /= 2;
}
return ans % mod;
}
// .............................


////////////////......................................