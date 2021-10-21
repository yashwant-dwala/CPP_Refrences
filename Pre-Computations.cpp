#include<bits/stdc++.h>
using namespace std;

//////////////////   TEMPLATE START ///////////////////////

#define ll long long int
#define F first
#define S second
#define rep(i,Start,End) for(int i=Start;i<End;i++)

void print(){
	cout<<endl;
}
template <typename T,typename... Types>
void print(T var1,Types... var2){
	cout<<var1<<" ";
	print(var2...);
}
void print_vec(vector<int> a){
	for(auto i:a){
		cout<<i<<" ";
	}
	cout<<endl;
}
vector<int> get_vector(int n){
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	return v;
}

//////////////////////  TEMPLATE END /////////////////////////////////
//  Max size of arr : 10^7, HASHING IS POSSIBLE Below this range only

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

int main(){
	int n;
	cin>>n;
	vector<int> v=get_vector(n);
	rep(i,0,n) print(Factorial(v[i]));
	return 0;
}