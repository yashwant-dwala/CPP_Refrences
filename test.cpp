#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds;

//////////////////   TEMPLATE START ///////////////////////
// Policy based data structure 
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ll long long int
#define pii pair<ll,ll>
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define vi vector<ll>
#define vii vector<pii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define eb emplace_back
#define yes cout<<"YES"<<endl; return;
#define no cout<<"NO"<<endl; return;
#define flus fflush(stdout);
#define gin(x) cerr<<#x<<" : "<<x<<" ";
#define fin cerr<<endl;
#define F first //key of un_map (item.first)
#define S second //value of un_map (item.second)
#define np next_permutation
#define inf 1e18
#define mod 1000000007
#define N 200009
#define PI 3.14159265358979323846
#define NO_OF_CHARS 256
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
#define maxpq priority_queue<ll> 
//////////////////////  TEMPLATE END /////////////////////////////////

bool cmp(string &x, string &y){
	if(x.length()<y.length())
		return x<y;
	return y<x;
}
// string reachTheEnd(vector<string> g, int maxTime){
// 	int n =g.size();
// 	int time=0;
// 	int l=0,bot=0;
// 	string ans="No";
// 	while(l<n&&bot<n){
// 		if(l==n-1&&bot==n-1) return ans;

// 		cout<<"Enter "<<time<<endl;
// 		if(time>=maxTime and (l<n-1||bot<n-1)) return ans;
  	
//     	if(g[bot][l+1]!='#'&&l<n-1){
//         	time++; l++;
//       	}
//       	if(g[bot+1][l]!='#'&&bot<n-1){
//           time++; bot++;
//       	}
//      	if(g[bot+1][l]=='#'&&g[bot][l+1]=='#'){
//        		time--;
//           	if(g[bot-1][l]!='#'&& bot>0){
//             	bot--;
//           	}
//           	else{
//             	if(l>0){
//                 	l--;          
//               	}
// 	        }
// 		}
// 	ans="Yes";
// 	return ans;
// }


  // this is the main function now
void solve(){
	// s.substr(index,length);
	// next_permutation(s.begin(),s.end());
	// sort(a,a+n);    OR  sort(a.begin(),a.end());
	int *p;
	int ar[11]={1,3,-5,8,-9,-2,6,7,6,-8,9};
	sort(ar,ar+11);
	int x=90;
	p=ar;
											
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t t1=clock();
	int t;
	cin>>t;
	t=1;
	while(t--){
		solve();
	}
	cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}

