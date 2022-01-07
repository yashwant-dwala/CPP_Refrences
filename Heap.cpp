#include<bits/stdc++.h>
# include "Template.cpp"
using namespace std;

/////////////////////////// H E A P ////////////////////////////////

void heapify(int a[],int n,int i){
	 int largest=i;
	 int l=2*i+1;
	 int r=2*i+2;
	 if(l<n and a[largest]<a[l]) largest=l;
	 if(r<n and a[largest]<a[r]) largest=r;
	 if(largest!=i){
	 	swap(a[largest],a[i]);
	 	heapify(a,n,largest);
	 }
}

void BuildHeap(int a[],int n){
	int N=(n/2) - 1; // because rest gonna be auto sorted
	for(int i=N;i>=0;i--){
		heapify(a,n,i);
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

void Solve(){
	int n=9,k=3;
	int a[n];
	get_arr(a,n);
	maxOfWindow(a,n,k);

}