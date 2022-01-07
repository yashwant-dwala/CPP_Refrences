#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;


//////////////////////////////////////////////////////

//  Merge Sort 

void merge(int left,int mid ,int right, int a[],int n){
	int n1 = mid-left+1;
	int n2 = right-mid; // because start with mid +1
	int A[n1],B[n2];
	for(int i=0;i<n1;i++){
		A[i]=a[left+i];
	}
	for(int i=0;i<n2;i++){
		B[i]= a[mid+1+i];
	}
	int i=0,j=0,k=left;
	while(i<n1 and j <n2){
		if(A[i]<=B[j]){
			a[k++]=A[i++];
		}
		else if(B[j]<A[i]){
			a[k++]=B[j++];
		} 
	}
	while(i<n1) a[k++]=A[i++];
	while(j<n2) a[k++]=B[j++];
}
void mergeSort(int left,int right, int a[],int n){
	int mid= (left+right)/2;
	if(left>=right){
		return;
	}
	mergeSort(left,mid,a,n);
	mergeSort(mid+1,right,a,n);
	merge(left , mid ,right, a,n);
	
}

// Quick sort 
int partrtion(vector<int> &v,int l,int r){
	int i=l,j=r; // returns correct value of pivot (always left)
	int pivot=l;
	while(i<j){
		do{
			i++;
		}while(v[i]<v[pivot]);
		do{
			j--;
		}while(v[j]>v[pivot]);
		if(i<j) swap(v[i],v[j]);
	}
	swap(v[pivot],v[j]);
	return j;
}

void quickSort(vector<int> &v,int l,int r){
	if(l>=r) return;
	int m = partrtion(v,l,r);
	quickSort(v,l,m);
	quickSort(v,m+1,r);
}

// Searching in an array where adjacent differ by at most k

int Search_Diff_k(vector<int> a,int l,int r,int k,int x){
	while(l<=r){
		if(a[l]==x) return l;
		l+=max(1,abs((a[l]-x)/k));
	}
	return -1;
}

// Weighted job Scheduling Problem 

struct Job
{
    int start, finish, profit;
};
bool jobComparator(Job s1,Job s2){
	return s1.finish<s2.finish;
}
int findMaxProfit(Job a[],int n){
	sort(a,a+n,jobComparator);
	int ans[n];
	rep(i,0,n){
		ans[i]=a[i].profit;
	}
	int j=0,i=0;
	while(i<n&&j<n){
		if(a[j].finish<=a[i].start&&i>0&&j<i){
			ans[i]+=a[j].profit;
		}
		j++;
		if(j>=n) { j=0;i++;}
	}
	rep(i,0,n) print(a[i].start,a[i].finish,a[i].profit);
	rep(i,0,n) print(ans[i]);
	sort(ans,ans+n);
	return ans[n-1];
}

//Counting number of trailing Zeros in a factorial of a nNumber
int Count_Zeros_InFactorial(int n){
	if(n<0) return -1;
	int count=0;
	for (int i = 5; n / i >= 1; i *= 5)
		count += n / i;
	return count;
}
// min number whoose fact contain n trailing zeros
int findNum(int n)
{
    if (n==1)
        return 5;
    int l=0;
    int r=n*5;
    while(l<r){
        int m=(l+r)>>1;
        if(Count_Zeros_InFactorial(m)>=n) r=m;
        else l=m+1;
    }
    return l;
}


//////////////////////////////////////////////

// Double helix
void doubleHelix(){
	while(true){
		int n;
		cin>>n;
		if(n==0) break;
		else{
			int a[n];
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			int m;
			cin>>m;
			int b[m];
			for(int i=0;i<m;i++){
				cin>>b[i];
			}
			int ans=0;
			int s1=0,s2=0,i=0,j=0;
			while(i<n and j<m){
				if(a[i]<b[j]) s1+=a[i++];
				else if(b[j]<a[i]) s2+=b[j++];
				else{
					ans=ans+max(s1,s2)+a[i];
					i++;
					j++;
					s1=s2=0;
				}
			}
			while(i<n)	s1+=a[i++];
			while(j<m) s2+=b[j++];
			ans+=max(s1,s2);
			cout<<ans<<endl;
		}
	}
}


void Solve(){
	
	

}