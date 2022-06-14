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
// .................................


////////////////......................................