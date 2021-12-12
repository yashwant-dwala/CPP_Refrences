#include<bits/stdc++.h>
using namespace std;

//////////////////   TEMPLATE START ///////////////////////
#define ll long long int
#define F first
#define S second
#define rep(i,st,end) for(int i=st;i<end;i++)

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
int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact = fact * i;
    return fact;
}
int countDistinctPermutations(string str)
{
    int length = str.length();
 
    int freq[26];
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < length; i++)
        if (str[i] >= 'a')
            freq[str[i] - 'a']++;
 

    int fact = 1;
    for (int i = 0; i < 26; i++)
        fact = fact * factorial(freq[i]);
 
    return factorial(length) / fact;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
	    map<int, int> F;
	    long long int ans=1;
	    int mod7 = 1e9+7;

	    for(int i:v)F[i]++;
	    
	    for(auto p:F){
	        int f=p.second;
	        ans*=(f+1);
	        ans%=mod7;
	    }
		ans--;
		cout<<ans<<endl;


	}
	
	return 0;
}

