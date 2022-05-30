#include<bits/stdc++.h>
# include "Template.cpp"
using namespace std;

/////////////////////////// H E A P ////////////////////////////////
void max_heapify(int a[],int n,int i){ //max heap;
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n and a[largest]<a[l]) largest=l;
	if(r<n and a[largest]<a[r]) largest=r;
	if(largest!=i){
		swap(a[largest],a[i]);
		max_heapify(a,n,largest);
	}
}
void min_heapify(int a[],int n,int i){
	int smallest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n and a[l]<a[smallest]) smallest=l;
	if(r<n and a[r]<a[smallest]) smallest=r;
	if(smallest!=i){
		swap(a[i],a[smallest]);
		min_heapify(a,n,smallest);
	}
}

void BuildHeap(int a[],int n){
	int N=(n/2) - 1; // because rest gonna be auto sorted
	for(int i=N;i>=0;i--){
		min_heapify(a,n,i);
	}
}
void heapSort(int a[],int n){
	priority_queue<int> p;
	for(int i=0;i<n;i++) p.push(a[i]);
	int i=0;
	while(p.empty()!=1){
		a[i++]=p.top();
		p.pop();
	}
}
void maxOfWindow(int a[],int n,int k){
	priority_queue<int> p;
	int i=0,j=0;
	while(j<n){
		p.push(a[j]);
		if(j-i+1<k){
			j++;
		}
		else{
			print(p.top());
			if(p.top()==a[i]) p.pop();
			i++;
			j++;
		}
	}
}

void Kth_Smallest_Largest_Ele(int a[],int n,int k){
	priority_queue<int> p; // max heap
	minHeap Mh; // min heap
	for(int i=0;i<n;i++){
		Mh.push(a[i]);
		p.push(a[i]);
		if(Mh.size()>k)Mh.pop();
		if(p.size()>k) p.pop();
	}
	print(k,"th Smallest: ",p.top()); // Kth Smallest
	print(k,"th Largest: ",Mh.top()); // Kth Largest
}

int maxSumContegiousSubArr(int a[],int n,int k){// not all negative
	int mSum=INT_MIN,wsum=0;
	minHeap p;
	for(int i=0;i<n;i++){
		wsum+=a[i];
		if(wsum<0) wsum=0; 
		if(mSum<wsum)mSum=wsum;
		p.push(wsum);
		if(p.size()>k) p.pop();
	}
	return p.top();
}

/////////////////   reorganizeString ////////////////////
#define pic pair<int,char>
void store(string &s,priority_queue<pic> &p){
	while(p.size()>0){
        pic tp1,tp2={-1,-1};
        tp1=p.top();
        p.pop();
       	if(!p.empty()){ 
       		tp2=p.top();
        	p.pop();
    	}
   		s+=tp1.second;
   		if(tp2.first>0)s+=tp2.second;
        if(tp1.first>1)p.push({tp1.first-1,tp1.second});
        if(tp2.first>1)p.push({tp2.first-1,tp2.second});
    }
}
string reorganizeString(string s) {
    priority_queue<pic> p;
    string ans="";
    unordered_map<char,int> m;
    for(auto x:s){
        m[x]++;
    }
    for(auto x:m) p.push({x.second,x.first});
    store(ans,p);
    for(int i=1;i<ans.size();i++){
        if(ans[i]==ans[i-1]) return "";
    } 
    return ans;
}

///////// Find Smallest Range IN All Sorted List of Arr size k ///////////////
struct three{
	int val,r,c;
};
struct compare{
	bool operator()(three a,three b){
		return a.val>b.val;
	}
};
int findMax(priority_queue<three,vector<three>,compare> p){
	int Max=p.top().val;
	while(!p.empty()){
		if(p.top().val>Max) Max=p.top().val;
		p.pop();
	}
	return Max;
}
pair<int,int> findSmallestRange(int a[][4],int N,int k){
	priority_queue<three,vector<three>,compare> p; //minHeap
	for(int i=0;i<k;i++) p.push({a[i][0],i,0});
	int m=0,M=0;	
	while(p.top().c<k-2){
		three x=p.top();
		p.pop();
		m=x.val;
		three nextMin=x;
		if(x.c+1<N) nextMin={a[x.r][x.c+1],x.r,x.c+1};
		if(m<nextMin.val) m=nextMin.val; 
		M=findMax(p);	
	}
	return {m,M};
}
////////////////  min Sum of 2 no made by array elements////////////
void sameLen(string &a,string &b){
    string temp = "";
    ll n=a.size()-b.size();
    if(n<0) n=0-n;
    for(ll i=0;i<n;i++) temp+="0";
    if(a.size()<b.size()) a=temp+a;
    else b=temp+b;
}
void removeZeros(string &s){
    int x=0;
    while(s[x]=='0') x++;
    s=s.substr(x);
}
string add(string a,string b){
    sameLen(a,b);
    int n=a.size();
    string res="";
    int carry=0;
    for(int i=n-1;i>=0;i--){
        int x=(int)(a[i]-48);
        int y=(int)(b[i]-48);
        int sum=x+y+carry;
        int l=sum%10;
        int c=sum/10;
        res=to_string(l)+res;
        carry=c;
    }
    res=to_string(carry)+res;
    removeZeros(res);
    return res;
}
string minSumFrom_Arr(int a[], int n) {
    priority_queue<int,vector<int>,greater<int>> p;
    for(int i=0;i<n;i++){
        p.push(a[i]);
    }
    string x="",y="";
    while(p.size()>1){
        x+=to_string(p.top());
        p.pop();
        y+=to_string(p.top());
        p.pop();
    }
    while(!p.empty()){
        x+=to_string(p.top());
        p.pop();
    }
    return add(x,y);
}

/////////////////////////////////////////////////////////////////////////////////
void Solve(){
	int n=6;
	int a[n]={6, 8, 4, 5, 2, 3};
	// get_arr(a,n);
	print(minSumFrom_Arr(a,n));
	// 604
}