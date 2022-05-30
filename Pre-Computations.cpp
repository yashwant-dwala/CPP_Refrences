#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;

//////////////////////////////////////////////////////////////////////////

////......... C O N C E P T .........

//     A = B + C * N   if ( B, C < N )
//     A % N = B
//     A / N = C
//...................................

//  Max size of arr : 10^7, HASHING IS POSSIBLE Below this range only

// because of this some ans are required modulo 10^9 + 7 
// which is best for 2^64 bit no

const int N=1e7+10; // 10^7 (1 SECOND) se thoda jada +10
ll Fact[N];


ll Factorial(ll X){
	Fact[0]=1;
	int i;
	rep(i,1,N) Fact[i]=i*Fact[i-1];
	return Fact[X];
}

// Prefix Sum arr = arr having A[i] as sum till i'th index from start.
// eg: A[6] : { 9 10 6 19 12 }   & Pf_Sum[6] : { 9 19 25 44 56 }
// NOTE - indexing start from '1'

// Use- eg: A[6]={0};  from index 2 to 5 add 3  A[6] = {0 0 3 3 3 3}
// But we keep track as : temp[6] = {0 0 +3 0 0 0 -3}
// for retrive A, calculate prefix sum Arr : pf[6] ={0 0 3 3 3 3 0}



//////////////////////////

void Solve(){
	vector<int> v=get_vector();
	int n=v.size();
	rep(i,0,n) print(Factorial(v[i]));
}