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

void swap_Sort(vector<int> &a,int n){

}

//////////////////////////

int main(){
	vector<int> v=get_vector();
	int n=v.size();
	swap_Sort(v,n);
	print_vec(v);
	return 0;
}