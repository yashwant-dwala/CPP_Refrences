#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;



//////////////////////////////////////////////////////////////

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
//not complete yet /////
vector<int> findAnagrams(string s,string p){
	vector<int> v;
	int n=s.size();
	int ans=0,i=0,j=0;
	unordered_map<char,int> u,w;
	unordered_map<char,bool> check;
	int count=0;
	for(auto x:p){
		u[x]++;
		check[x]=1;
	}
	int k=p.length();
	while(j<n){
		if(u[s[j]]>0&&check[s[j]]==true) count++;
		if(j-i+1<k) j++;
		else if(j-i+1==k){
			if(count==k) {ans++; v.push_back(i);}
			if(u[s[i]]>0) count--; 
			i++;j++;
		}
		else if(j-i+1>k){
			if(u[s[i]]>0) count--; 
			i++;
		}
	}
	return v;
}

/////////////  MAX'S OF ALL SUBARRAY OF SIZE K //////////////

vector<int> MaximumsOf_All_Sub_Size_K(vector<int> a,int k){
	int n=a.size();
	vector<int> v;
	deque<int> q;
	int i=0,j=0;
	while(j<n){
		while(!q.empty()&&q.back()<a[j]) q.pop_back();
		q.push_back(a[j]);
		if(j-i+1<k) j++;
		else if(j-i+1==k){
			v.push_back(q.front());
			if(q.front()==a[i]) q.pop_front();
			i++;j++;
		}
	}
	return v;
}

vector<int> MinimumsOf_All_Sub_Size_K(vector<int> a,int k){
	int n=a.size();
	vector<int> v;
	deque<int> q;
	int i=0,j=0;
	while(j<n){
		while(!q.empty()&&a[j]<q.back()) q.pop_back();
		q.push_back(a[j]);
		if(j-i+1<k) j++;
		else if(j-i+1==k){
			v.push_back(q.front());
			if(q.front()==a[i]) q.pop_front();
			i++;j++;
		}
	}
	return v;
}


void Solve(){
	vector<int> v={2, 5, -1, 7, -3, -1, -2};
	string s="tatmxatmtx";
	string p="mta";
	v=findAnagrams(s,p);
	print_vec(v);
}