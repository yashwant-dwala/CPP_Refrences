#include<bits/stdc++.h>
using namespace std;

//////////////////   TEMPLATE START ///////////////////////
#define ll long long int
#define F first
#define S second

void print(){
	cout<<endl;
}
template <typename T,typename... Types>
void print(T var1,Types... var2){
	cout<<var1<<" ";
	print(var2...);
}

vector<int> get_vector(){
	int N;
	cin>>N;
	vector<int> v;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	return v;
}
void print_vec(vector<int> a){
	for(auto i:a){
		cout<<i<<" ";
	}
	cout<<endl;
}
void print_mat(vector<vector<int>> m){
	int N=m.size();
	int M=m[0].size();
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			cout<<m[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

//////////////////////  TEMPLATE END /////////////////////////////////

// Searching in an array where adjacent differ by at most k

int Search_Diff_k(vector<int> a,int l,int r,int k,int x){
	while(l<=r){
		if(a[l]==x) return l;
		l+=max(1,abs((a[l]-x)/k));
	}
	return -1;
}


//////////////////////////////////////////////

int main(){
	vector<int> v=get_vector();
	int x=50;
	int l=0,r=v.size()-1;
	cout<<Search_Diff_k(v,l,r,20,x);

	return 0;
}