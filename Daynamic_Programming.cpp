#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;

//////////................  K N A P S A C K  ...............////////
// for DP recursive + memoization

					// item (w1)
		// w1<=W(acceptable) 	w1>W (rejectable)
		// take		leave			leave
		// -weight	n-1				n-1
		// n-1 

const int n=1e3,W=1e5;
int DP[n+1][W+1];
int O_1_Knapsack(int val[],int wt[],int n,int W){
	if(n==0 or W==0) return 0;
	if(DP[n][W]!=-1) return DP[n][W];
	if(wt[n-1]<=W) return DP[n][W]=max(val[n-1]+O_1_Knapsack(val,wt,n-1,W-wt[n-1]),
		O_1_Knapsack(val,wt,n-1,W));
	else return DP[n][W]=O_1_Knapsack(val,wt,n-1,W);
}

// TOP-DOWN APPROACH........
int O_1_Knapsack_TD(int val[],int wt[],int n,int W){
	int t[n+1][W+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			if(i==0 or j==0) t[i][j]=0; // initialization
			if(wt[i-1]<=j) 
				t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
			else t[i][j]=t[i-1][j];
		}
	}
	return t[n][W];
}

bool subset_sum(vector<int> A,int B){
	int n=A.size();
    int dp[n+1][B+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=B;j++){
            if(j==0 )
                dp[i][j]=1;
            else if(i==0) dp[i][j]=0;
            else if(A[i-1]<=j) dp[i][j]=dp[i-1][j-A[i-1]] or dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][B];
}

int count_Subset_sum(vector<int> A,int B){
	int n=A.size();
	int dp[n+1][B+1];
	for (int i = 0; i <=n; i++){
		for (int j = 0; j <= B; j++){
			if(j==0) dp[i][j]=1;
			else if(i==0) dp[i][j]=0;
			else if(A[i-1]<=j) dp[i][j]= dp[i-1][j-A[i-1]] + dp[i-1][j];
			else dp[i][j]=dp[i-1][j];
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n][B];
}
bool Equal_Sum_Partition(vector<int> A){
	int n=A.size(),sum=0;
	for(auto x:A) sum+=x;
	if(sum%2!=0) return 0;
	else if(subset_sum(A,sum/2)) return 1;
	return 0;
}
int Min_Subset_Sum_with_Diff(vector<int> A){
	int n=A.size(),range=0;
	for(auto x:A) range+=x;
	int dp[n+1][range+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=range;j++){
            if(j==0 )
                dp[i][j]=1;
            else if(i==0) dp[i][j]=0;
            else if(A[i-1]<=j) dp[i][j]=dp[i-1][j-A[i-1]] or dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> v;
    for(int i=0;i<=range/2;i++)
    	if(dp[n][i]==1) v.push_back(i);
    int mn=INT_MAX;
    for(auto x:v) mn=min(mn,range-2*x);
    return mn;
}

int count_Subset_with_given_sum_differene(vector<int> A,int D){ //target sum
	int n=A.size();
	int s1,range=0;
	for(auto x:A) range+=x;
	s1=(D+range)/2;
	return count_Subset_sum(A,s1);
}

// unbounded Knapsack
int min_No_Coins( vector<int> coins,int sum){
	int n=coins.size();
	int dp[n+1][sum+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0) dp[i][j] = INT_MAX-1;
			else if(j==0) dp[i][j]=0;
			else if(i==1 and j%coins[0]==0) dp[i][j]=j/coins[0];
			else if(coins[i-1]<=j) dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];
}

//////////// ..........................................................







///////........ L O N G E S T  C O M M A N  S U B S E Q U E N C E ........//////////

//  s1="abcdgh" s2="abedfhr"  ------ LCS = "abdh" 


// I M P O R T A N T
// Shortest common superstring
// Occurances_of_substr_a_in_b
// Count_Pallindromic_Substrs




// Reccursion + memoization
int L[n+1][W+1];
int LCS(string a,string b,int n,int m){
	if(n==0 or m==0) return L[n][m]=0;
	if(L[n][m]!=-1) return L[n][m];
	if(a[n-1]==b[n-1]){
		return L[n][m]=1+LCS(a,b,n-1,m-1);
	}
	return L[n][m]=max(LCS(a,b,n-1,m),LCS(a,b,n,m-1));
}
// Top-Down LCS                              
int LCS_T(string a,string b,int n,int m){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){					// U S E  T H I S  O N L Y
		for(int j=0;j<=m;j++){
			if(i==0 or j==0) dp[i][j]=0;
			else if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
}
int LC_Substr(string a,string b,int n,int m){
	int t[n+1][m+1];
	int M=INT_MIN;
	memset(t,0,sizeof(t));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 or j==0) t[i][j]=0;
			else if(a[i-1]==b[j-1] ) t[i][j]=1+t[i-1][j-1];
			else t[i][j]=0;
			M=max(M,t[i][j]);
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	return M;
}
string print_LCS(string a,string b,int n,int m){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 or j==0) dp[i][j]=0;
			else if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	int i=n,j=m;
	string s="";
	while(i>0 and j>0){
		if(a[i-1]==b[j-1]) {
			s+=a[i-1];
			i--;j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1])	i--;
			else j--;
		}
	}
	reverse(s.begin(),s.end());
	return s;
}

int SC_SuperSequence(string a,string b,int n,int m){
	return n+m - LCS_T(a,b,n,m);
}
string print_SC_SuperSequence(string a,string b,int n,int m){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 or j==0) dp[i][j]=0;
			else if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int i=n,j=m; 
	string s="";
	while(i>0 and j>0){
		if(a[i-1]==b[j-1]){
			s+=a[i-1];
			i--;
			j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1]){
				s+=a[i-1];
				i--;
			}
			else{
				s+=b[j-1];
				j--;
			}
		}
	}
	while(i>0){ s+=a[i-1]; i--;}
	while(j>0){ s+=b[j-1]; j--;}
	reverse(s.begin(),s.end());
	return s;
}

pair<int,int> min_Ins_Del_to_make_a_to_b(string a,string b,int n,int m){
	int ins= b.length()-LCS(a,b,n,m);
	int del= a.length()-LCS(a,b,n,m);
	pair<int,int> x={ins,del};
	return x;
}
int Largest_Rep_Subsequence(string a,int n){
	int t[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 or j==0) t[i][j]=0;
			else if(a[i-1]==a[j-1] and i!=j) t[i][j]=1+t[i-1][j-1];
			else t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	return t[n][n];
}
int Longest_Subseq_of_a_that_is_substr_in_b(string a,string b,int n,int m){
	string x=print_LCS(a,b,n,m);
	return LC_Substr(x,b,x.size(),m);
}
bool Sequen_Pattern_Matcing(string a,string b,int n,int m){
	return (min(n,m)==LCS_T(a,b,n,m));
}

int Occurances_of_substr_a_in_b(string a,string b,int n,int m){

	// yet to find ..................................................
	
	return 0;
}
int Longest_Palindromic_Subseq(string a,int n){
	string b=a;
	reverse(b.begin(),b.end());
	return LCS_T(a,b,n,n);
}
int Longest_Palindromic_Substr(string a,int n){
	string b=a;
	reverse(b.begin(),b.end());
	return LC_Substr(a,b,n,n);
}
int Count_Pallindromic_Substrs(string a,int n){

	// yet to find ..................................................
	
	return 0;
}
int Min_NO_Del_to_make_Palindrome(string a,int n){

	//........  I N S E R T I O N   I S   S A M E 
	
	string b=a;
	reverse(b.begin(),b.end());
	int l=LCS_T(a,b,n,n);
	return n-l;
}
string prefix(vector<string> A){
	string a=A[0],b=A[1];
    string s=print_LCS(a,b,a.size(),b.size());
    for(int i=2;i<A.size();i++){
        s=print_LCS(s,A[i],s.size(),A[i].size());
    }
    return s;
}

//////////// ..........................................................







///////........ M A T R I X  C H A I N  M U L T I P L I C A T I O N ......//////////

// given arr = {40,20,10,30} matricies
// size M1 = arr[0]xarr[1]; {40x20}
// return min cost = min # of multiplication
// cost of M(a x b) x M(b x c) = a x b x c 

int mt[1001][1001];

// Reccursive + Memoization 
int MCM(vector<int> a,int i,int j){ // call 'MCM(a,1,n-1)'  in main()
	if(i>=j) return mt[i][j]=0;
	if(mt[i][j]!=-1) return mt[i][j];
	int ans=INT_MAX;
	for(int k=i; k<=j-1;k++){ // find call and k-loop visely
		int temp = MCM(a,i,k)+MCM(a,k+1,j)+ a[i-1]*a[k]*a[j];
		ans=min(ans,temp);
	}
	return mt[i][j]=ans;
} 

int print_MCM(vector<int>,int i,int j){
	return 0;
}
unordered_map<string,int> m;
bool scrambled_string(string a,string b){
    print(a,b);
    if(a==b) return 1;
    if(a.size()<=1) return 0;
    if(m.find(a+":"+b)!=m.end()) return m[a+":"+b];
    for(int k=1;k<a.size();k++){
        bool cond1 = scrambled_string(a.substr(0,k),b.substr(0,k)) and scrambled_string(a.substr(k,a.size()-k),b.substr(k,b.size()-k));
        bool cond2 = scrambled_string(a.substr(0,k),b.substr(a.size()-k,k)) and scrambled_string(a.substr(k,a.size()-k),b.substr(0,b.size()-k));
        if(cond1 || cond2) {
            return m[a+":"+b]=1; break;
        }
    }
    return m[a+":"+b]=0;
}

void Solve(){
	// only in function() not global
	memset(DP,-1,sizeof(DP));  // knapsack
	memset(L,-1,sizeof(L));	  // LCS
	memset(mt,-1,sizeof(mt)); // MCM
	// vector<int> a = get_vector(2);
	// int n=a.size();
	// print(MCM(a,1,n-1));

}
// for(int i=0;i<=n;i++){
// 	for(int j=0;j<=m;j++){
// 		cout<<mt[i][j]<<" ";
// 	}
// 	cout<<endl;
// }



///////////...................   E X T R A S .................../////////////////////
bool Wildcard_Regex_Match(string a,string b){
    if(a==b) return 1;
    int n=a.size(),m=b.size();
    bool t[n+1][m+1];
    memset(t,0,sizeof(t));
    t[0][0]=1;
    for(int i=1;i<=m;i++){
        t[0][i]=1;  //*************
        for(int j=1;j<=i;j++){
            if(b[j-1]!='*'){
                t[0][i]=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1] or b[j-1]=='?') t[i][j]=t[i-1][j-1];
            else if(b[j-1]=='*') t[i][j]= t[i-1][j] or t[i][j-1]; 
            else t[i][j]=0;
        }
    }
    return t[n][m];
}