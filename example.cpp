#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;

///////////////////////////////////////////////////////////////////////////
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
void solve1(){
	int n; cin>>n;
	int a[100005];
	int pos[100005];
	int next[100005];
	for(int i=0;i<n;i++) cin>>a[i+1];
	for(int i=0;i<=n;i++) pos[i]=n+1;

	for(int i=n;i>=0;i++){
		next[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	int x=0,y=0,ans=0;
	for(int i=1;i<=n;i++){
		if(a[x]==a[i]){
			ans+=(a[y]!=a[i]);
			y=i;
		}
		else if(a[y]==a[i]){
			ans+=(a[x]!=a[i]);
			x=i;
		}
		else if(next[x]<next[y]){
			ans+=(a[x]!=a[i]);
			x=i;
		}
		else{
			ans+=(a[y]!=a[i]);
			y=i;
		}
	}

	cout<<ans<<endl;
	
	
}
void solve(){
	int t;
	cin>>t;
	while(t--){
		solve1();
	}
}

