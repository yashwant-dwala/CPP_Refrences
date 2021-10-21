#include<bits/stdc++.h>
using namespace std;

//////////////////   TEMPLATE START ///////////////////////

#define ll long long int
#define F first
#define S second

const int N=1e7+10; // 10^7
ll arr[N];
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

int Weighted_Profit_Maximization(vector<pair<int,int>> time,vector<int> p,int n){
	unordered_map<int,int> EndProfit,u;
	EndProfit[0]=0;
	for(int i=0;i<n;i++) u[time[i].F]=p[i];
	sort(time.begin(),time.end());
	int ans=0;
	rep(i,0,n){
		for(auto x:EndProfit){
			print(x.F,x.S);
			if(x.F<=time[i].F){
				EndProfit[x.F+time[i].S]=x.S+u[time[i].F];
				ans=max(ans,x.S+u[time[i].F]);
			}
		}
		cout<<endl;
	}
	// for(auto x:EndProfit) print(x.F,x.S);
	return ans;

}
int maxSum_SubArr_MaxLen_KADANES(vector<int> a){
	int Curr=0,Max=0,st=0,ed=0;
	for(auto x:a){
		Curr+=x;
		Max=max(Max,Curr);
		if(Curr<0) Curr=0;
		if(st==0&&Curr>=0)st=x;
		else if(Curr==Max&&st!=0) ed=x;
		print(Curr,Max,x,"||",st,ed);
	}
	return Max;
}
int findSubarray_withSum_0(vector<int> a, int n ) {
	int Min=0,Max=0,sum=0;
	for(auto x:a){
		if(x<0) Min+=x;
		else Max+=x;
		sum=Max+Min;
		print(Max,Min,sum,x);
	}
	return sum;
   }
//////////////////////////

int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> time={{1,9},{3,6},{6,9},{9,100}};
	vector<int> Profit=get_vector(n);
	// cout<<Weighted_Profit_Maximization(time,Profit,n);
	// cout<<maxSum_SubArr_MaxLen_KADANES(Profit);
	cout<<findSubarray_withSum_0(Profit,n);
	return 0;
}