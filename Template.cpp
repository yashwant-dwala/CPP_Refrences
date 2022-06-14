#include<bits/stdc++.h>
#include "Helper_Functions.cpp"
using namespace std;

// Solve == main now
// typeid(variable).name() gives data type

//////////////////   TEMPLATE START ///////////////////////
#define ll long long
#define F first
#define S second
#define mod 1000000007
#define rep(i,st,en) for(ll i=st;i<en;i++)

// type(x).name();
#define typeVector_i "St6vectorIiSaIiEE" // string hai
#define typeString "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE"
#define typePair_i_i "St4pairIiiE" 
#define typeUnordered_map_i_i "St13unordered_mapIiiSt4hashIiESt8equal_toIiESaISt4pairIKiiEEE"
#define typeMap_i_i "St3mapIiiSt4lessIiESaISt4pairIKiiEEE"

#define minHeap priority_queue<int,vector<int>,greater<int>>

// main Function
void Solve();

////////////////////////  printing purpose /////////////////////////
void print(){
	cout<<endl;
}
template <typename T,typename... Types> 
void print(T var1,Types... var2){
	cout<<var1<<" ";
	print(var2...);
}
template<typename T> void print_arr(T a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
template<typename T> void print_vec(vector<T> a){
	for(auto i:a){
		cout<<i<<" ";
	}
	cout<<endl;
}
template<class T1,class T2> void print_Pair(pair<T1,T2> var1){
	print(var1.first,var1.second);
}
template<typename T,typename T1> void print_map(map<T,T1> a){
	for(auto i:a){
		print(i.first,i.second);
	}
	cout<<endl;
}
template<typename T,typename T1> void print_Umap(unordered_map<T,T1> a){
	for(auto i:a){
		print(i.first,i.second);
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
///////////////.......................................


//////////////////////// Take Inputs ///////////////////////////
vector<int> get_vec(int N){
    vector<int> v;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    return v;
}
template<class T> vector<T> get_vector(T type){
	int N;
	cin>>N;
	vector<T> v;
	for(int i=0;i<N;i++){
		T x;
		cin>>x;
		v.push_back(x);
	}
	return v;
}
template<class T> void get_arr(T a[],int N){
	for(int i=0;i<N;i++){
		T x;
		cin>>x;
		a[i]=x;
	}
}
vector<vector<int>> get_N_M_Mat(){
    int N,M;
    cin>>N;
    cin>>M;
    vector<vector<int>> v;
    for(int i=0;i<N;i++){
        vector<int> a;
        for(int j=0;j<M;j++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        v.push_back(a);
    }
    return v;
}
//////////...................................


////////////////// Data Variables /////////////////





//////////////////////  TEMPLATE END /////////////////////////////////



//////////////////////////


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t t1=clock();
	int t=1;
	while(t--){
		Solve();
	}
	cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}