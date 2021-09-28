#include<bits/stdc++.h>
using namespace std;

//////////////////   TEMPLATE START ///////////////////////
#define ll long long int
#define F first
#define S second

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

int maxWindowSUM_K(vector<int> &a,int n,int k){
	int msum=0,wsum=0;
	for(int i=0;i<k;i++){
		wsum+=a[i];
	}
	msum=wsum;
	int end=k;
	for(int i=0;end<n;i++){
		wsum+=a[end]-a[i];
		end++;
		if(wsum>=msum)	msum=wsum;
	}
	return msum;
}

///////////////////  FIXED WINDOW SIZE ///////////////////

////////////////  Max Sum Window ////////////////

int maxSumWindowK_Size(vector<int> a,int n,int k){
	int msum=INT_MIN,wsum=0,i=0,j=0;
	while(j<n){
		wsum+=a[j];
		if(j-i+1<k) j++; 
		else if((j-i+1)==k){
			if(msum<wsum)
				msum=wsum;
			wsum-=a[i]; i++;j++;		
		}
	}
	return msum;
}

//////////// 1st NEGATIVE OF WINDOW /////////////////////

vector<int> First_negative_k_size(vector<int> a,int n,int k){
	vector<int> v;
	queue<int> q;
	int i=0,j=0;
	while(j<n){
		if(a[j]<0) q.push(a[j]);	
		if(j-i+1<k) j++;
		else if(j-i+1==k){
			if(!q.empty()) v.push_back(q.front());
			else v.push_back(0);
			if(!q.empty()&&q.front()==a[i]) q.pop();
			i++;j++;
		}
	}
	return v;
}

///////////// OCCURANCE OF ANAGRAMS ///////////////////

int OccOf_Anagrams(string s,string p){
	int n=s.size();
	int ans=0,i=0,j=0;
	unordered_map<char,int> u;
	int count=0;
	for(auto x:p){
		u[x]++;
	}
	int k=p.length();
	while(j<n){
		if(u.find(s[j])) u[s[j]]--;
		if(j-i+1<k) j++;
		else if(j-i+1==k){
			cout<<s[j]<<","<<count<<endl;
			if(count==k) ans++;
			if(u[s[i]]>0) u[s[i]]--;
			i++;j++;
		}
		// else if(j-i+1>k){
		// 	if(u[s[i]]>0) u[s[i]]--;
		// 	i++;
		// }
	}
	return ans;
}

int main(){
	vector<int> v={12, -1, -7, 8, -15, 30, 16, 28};
	string s="tomatattopaxt";
	string p="tta";
	cout<<OccOf_Anagrams(s,p)<<endl;

	
	return 0;
}