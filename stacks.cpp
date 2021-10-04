#include<bits/stdc++.h>
using namespace std;

//////////////////   TEMPLATE START ///////////////////////
#define ll long long int
#define F first
#define S second

void print_arr(vector<int> a){
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

int precedence(char c){
	if(c=='^')
		return 2;
	if(c=='*'||c=='/')
		return 1;
	if(c=='+'||c=='-')
		return 0;
	return -1;
}

///////////////////  NEXT GREATER/SMALLER RIGHT  ////////////////////////////

vector<int> NGR(vector<int> a,int n){
	stack<int> st;
	vector<int> v;
	for(int i=n-1;i>=0;i--){
		if(st.empty()) v.push_back(-1);
		else if(st.top()>a[i]) v.push_back(st.top());
		else if(st.top()<=a[i]){
			while(!st.empty()&& st.top()<a[i]){
				st.pop();
			}
			if(st.empty()) v.push_back(-1);
			else v.push_back(st.top());
		}
		st.push(a[i]);
	}
	reverse(v.begin(),v.end());
	return v;
}
vector <int> NGL(vector<int> a,int n){
	vector<int> v;
	stack<int> st;
	for(int i=0;i<n;i++){
		if(st.empty()) v.push_back(-1);
		else if(st.top()>a[i])
			v.push_back(st.top());
		else if(st.top()<=a[i]){
			while(!st.empty()&&st.top()<=a[i]){
				st.pop();
			}
			if(st.empty()) v.push_back(-1);
			else v.push_back(st.top());
		}
		st.push(a[i]);
	}
	return v;
}
vector<int> NSR(vector<int> a,int n){
	stack<int> st;
	vector<int> v;
	for(int i=n-1;i>=0;i--){
		if(st.empty()) v.push_back(-1);
		else if(st.top()<a[i]) v.push_back(st.top());
		else if(st.top()>=a[i]){
			while(!st.empty()&& st.top()>=a[i]){
				st.pop();
			}
			if(st.empty()) v.push_back(-1);
			else v.push_back(st.top());
		}
		st.push(a[i]);
	}
	reverse(v.begin(),v.end());
	return v;
}
vector<int> NSL(vector<int> a,int n){
	vector<int> v;
	stack<int> st;
	for(int i=0;i<n;i++){
		if(st.empty()) v.push_back(-1);
		else if(st.top()<a[i]) v.push_back(st.top());
		else if(st.top()>=a[i]){
			while(!st.empty()&&st.top()>=a[i])
				st.pop();
			if(st.empty()) v.push_back(-1);
			else v.push_back(st.top());
		}
		st.push(a[i]);
	}
	return v;
}
vector<int> NGL_index(vector<int> a,int n){
	vector<int> v;
	stack<pair<int,int>> st;
	for(int i=0;i<n;i++){
		if(st.empty()) v.push_back(-1);
		else if(st.top().first>a[i])
			v.push_back(st.top().second);
		else if(st.top().first<=a[i]){
			while(!st.empty()&&st.top().first<=a[i]){
				st.pop();
			}
			if(st.empty()) v.push_back(-1);
			else v.push_back(st.top().second);
		}
		st.push({a[i],i});
	}
	return v;
}
vector<int> NSL_index(vector<int> a,int n){
	vector<int> v;
	stack<pair<int,int>> st;
	for(int i=0;i<n;i++){
		if(st.empty()) v.push_back(-1);
		else if(st.top().first<a[i]) v.push_back(st.top().second);
		else if(st.top().first>=a[i]){
			while(!st.empty()&&st.top().first>=a[i])
				st.pop();
			if(st.empty()) v.push_back(-1);
			else v.push_back(st.top().second);
		}
		st.push({a[i],i});
	}
	return v;
}
vector<int> NSR_index(vector<int> a,int n){
	vector<int> v;
	stack<pair<int,int>> st;
	for(int i=n-1;i>=0;i--){
		if(st.empty()) v.push_back(n);
		else if(st.top().first<a[i]) v.push_back(st.top().second);
		else if(st.top().first>=a[i]){
			while(!st.empty()&&st.top().first>=a[i])
				st.pop();
			if(st.empty()) v.push_back(n);
			else v.push_back(st.top().second);
		}
		st.push({a[i],i});
	}
	reverse(v.begin(),v.end());
	return v;
}

///////////// MIN VALUE STOCK IN A CONTINIOUS ROW ///////////////// 

void stock_spair(vector<int> a,int n){
	vector<int> v=NGL_index(a,n);
	for(int i=0;i<n;i++)
		v[i]=i-v[i];
	print_arr(v);
}

///////////////   MAX AREA HISTOGRAM  //////////////////

int Histogram(vector<int> a,int n){
	vector<int> NSL=NSL_index(a,n);
	vector<int> NSR=NSR_index(a,n);
	vector<int> W;
	for(int i=0;i<n;i++){
		W.push_back(NSR[i]-NSL[i]-1);
	}
	vector<int> area;
	for(int i=0;i<n;i++){
		area.push_back(W[i]*a[i]);
	}
	int m=INT_MIN;
	for(auto i:area){
		if(i>m)
			m=i;
	}
	return m;
}

////////////  MAX AREA RECTANGLE IN MATRIX /////////////////////

int Max_React_Area_Matrix(vector<vector<int>> a,int n){
	vector<vector<int>> v;
	v.push_back(a[0]);
	for(int i=1;i<n;i++){
		vector<int> z;
		for(int j=0;j<n;j++){
			int x=a[i][j]+v[i-1][j];
			if(a[i][j]!=0)	z.push_back(x);
			else z.push_back(0);
		}
		v.push_back(z);
	}
	int Areas[n];
	for(int i=0;i<n;i++){
		Areas[i]=Histogram(v[i],n);
	}
	int m=INT_MIN;
	for(auto i:Areas){
		if(i>m){
			m=i;
		}
	}
	return m;
}

///////////////  REDUNDENT BRACES IN EXPRESSION /////////////////

// Stack Reversal reccursion
stack<int> rev(stack<int> st){
	if(st.empty()) return st;
	int temp=st.top();
	st.pop();
	st=rev(st);
	return st;
}

bool isOperator(char x){
	return (x=='*'||x=='+'||x=='-'||x=='/');
}

// main function
bool redundent(string a){
	stack<char> st;
	for(auto x:a){
		if(x!=')'){
			st.push(x);
		}
		else{
			bool found=0;
			while(!st.empty()&&st.top()!='('){
				char t=st.top();
				st.pop();
				if(isOperator(t)) found=1;
			}
			if(found) st.pop();
			else return 1;
		}
	}
	return 0;
}
vector<int> nsr(vector<int> a, int n){
	vector<int> v;
	stack<int> st;
	for(int i=n-1;i>=0;i--){
		if(st.empty()) v.push_back(-1);
		else if(a[i]>st.top()) v.push_back(st.top());
		else if(a[i]<=st.top()){
			while(!st.empty()&&a[i]<=st.top()){
				st.pop();
			}
			if(st.empty()) v.push_back(-1);
			else v.push_back(st.top());
		} 
		st.push(a[i]);
	}	
	reverse(v.begin(),v.end());
	return v;
}


////////////////////////////////////////////////////////

int main() {
	vector<int> a={4, 8, 5, 2, 25};
	// a.erase(a.begin()+2);
	string s="((d-b))";
	// cout<<redundent(s);
	a=nsr(a,5);
	print_arr(a);
	

	return 0;
}