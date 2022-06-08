#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;

////////// B_S Ascending and Dscending order /////////////////
// order agnostic search

int B_Search_Both_Order(vector<int> a,int l,int r,int x){
	bool sort_order;
	if(a.size()>1) 
		sort_order=a[0]<a[1];  // true if ascending
	else{
		if(a[0]==x) return 0;
		else return -1;
	}
	while(l<=r){
		int mid=l+(r-l)/2;  // overflow of int 
		if(a[mid]==x)  return mid;
		else if(a[mid]>x){
			if(sort_order) r=mid-1;
			else l=mid+1;
		} 
		else {
			if(sort_order) l=mid+1;
			else r=mid-1;
		}
	}
	return -1;
}
///////////////  FIRST AND LAST OCCURANCE  //////////////
int Search_First(vector<int> a,int l,int r,int x){
    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2; 
        if(a[mid]==x){
        	ans=mid;
        	r=mid-1;
        }
        else if(a[mid]>x)
            r=mid-1;
        else
            l=mid+1;
    }
    return ans;
}
int Search_Last(vector<int> a,int l,int r,int x){
	int ans=-1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]==x){
			ans=mid;
			l=mid+1;
		}
		else if(a[mid]>x) r=mid-1;
		else l=mid+1;
	}
	return ans;
}

///////////// COUNTS OF NO IN SORTED ARRAY  /////////////

int Count(vector<int> a,int l,int r,int x){
	return Search_Last(a,l,r,x)-Search_First(a,l,r,x)+1;
}

////////////// ROTATION COUNT /////////////////////

int Rot_Count(vector<int> a,int l,int r,int n){
	// pivot or smallest of arr
    int n=v.size();
    int l=0,r=n-1;
    while(l<r){
        int m=(l+r)/2;
        if(v[m]<v[r]) r=m; // left half is promising
        else l=m+1; // right half is promising
    }
    // r==l
    return r;
}

///////////////////  Search of ele in Rotated Sort Arr  ///////////////

int B_S_Rot_Sort(vector<int> a,int l,int r,int x){
	int n=a.size();
	int br=Rot_Count(a,l,r,n);
	int z=B_Search_Both_Order(a,0,br-1,x);
	int y=B_Search_Both_Order(a,br,n-1,x);
	return max(z,y);
}

////////////// Search in Nearly Sorted Arr  ////////////////

// actual sorted no at (i) is at (i-1) or (i) or (i+1) pos

int B_S_Nearly_Sort(vector<int> a,int l,int r,int x){
	while(l<=r){
		int mid=l+(r-l)/2;
		if(mid<=r&&mid>=l&&a[mid]==x) return mid;
		else if(mid-1>=l && a[mid-1]==x) return mid-1;
		else if(mid+1<=r && a[mid+1]==x) return mid+1;
		else if(a[mid]>x) r=mid-2;
		else l=mid+2;
	}
	return -1;
}

///////////////  Floor of element ///////////////////

int Floor(vector<int> a,int l,int r,int x){
	int ans=-1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]==x) return mid;
		else if(a[mid]>x) r=mid-1;
		else {
			ans=mid;
			l=mid+1;
		}
	}
	return ans;
}

///////////////// Next Alphabet  //////////////////

char Ceil(vector<char> a,int l,int r,char x){
	char ans='0';
	while(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]==x) return a[mid];
		else if(a[mid]>x){
			ans=a[mid];
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}

/////////////// B_S in Infinite Sorted Arr /////////////////

int B_S_Inf_Arr(vector<int> a,int x){
	int l=0,r=1;
	while(x>a[r]){
		l=r;
		r*=2;
	}
	return B_Search_Both_Order(a,l,r,x);
}

///////////////  First '1' in Binary Sorted Infinite Arr ////////////////

int First_1_Binary_Arr_INF(vector<int> a){
	int l=0,r=1;
	while(a[r]<1){
		l=r;
		r*=2;
	}
	return Search_First(a,l,r,1);
}

////////  Min Diff Element in Sorted Arr /////////////////

int Min_Diff_Ele_Sort_Arr(vector<int> a, int l,int r,int x){
	int diff=INT_MAX,ans=-1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(abs(a[mid]-x)==0) return a[mid];
		else if(abs(a[mid]-x)<diff){
			diff=abs(a[mid]-x);
			ans=a[mid];
		}
		else if(abs(a[mid]-x)>diff&&a[mid]>x) r=mid-1;
		else l=mid+1;
	}
	return ans;
}

//////////////// Peak Element UNSORTED ARR **(IMP)** ////////////////

int Peak_Ele(vector<int> a,int l,int r){
	while(l<=r){
		int m=l+(r-l)/2;
		if((m==0&&a[m]>a[m+1])||(m==a.size()-1&&a[m]>a[m-1])) return m;
		else if(m>0&&m<a.size()-1){
			if(a[m]>a[m-1]&&a[m]>a[m+1]) return m;
			else if(a[m]<a[m-1]) r=m-1;
			else l=m+1;
		}
	}
	return -1;
}

//////////// Bitonic Arr Max Ele  /////////////////////////

int Peak_Ele_Bitonic(vector<int> a,int l,int r){
	while(l<=r){
		int m=l+(r-l)/2;
		if(a[m]>a[m-1]&&a[m]>a[m+1]) return m;
		else if(a[m]<a[m-1]) r=m-1;
		else l=m+1;
	}
	return -1;
}

///////////// Search Ele in Bitonic Arr ////////////////

			//Error Serarch last Ele 

int Search_Ele_Bitonic(vector<int> a,int l,int r,int x){
	int y=Peak_Ele_Bitonic(a,l,r);
	return max(B_Search_Both_Order(a,l,y,x),B_Search_Both_Order(a,y,r,x));
}

//////// Allocate Min No. Of Max Pages Books ///////////////////
bool isValid(int mid,int child,vector<int> a){
	int student=1,sum=0;
	for(auto x:a){
		sum+=x;
		if(sum>mid){
			student++;
			sum=x;
		}
		if(student>child) return false;
	}
	return true;
}
int Allocate_Min_MaxNoPages(vector<int> a,int childs){
	int n=a.size();
	int low=0,high=0,ans=-1;
	if(childs>a.size()) return ans;
	for(int i=0;i<n;i++){
		if(low<a[i])low=a[i];
		high+=a[i];
	}
	while(low<=high){
		int mid=low+(high-low)/2;
		if(isValid(mid,childs,a)){ ans=mid; high=mid-1;}
		else low=mid+1;
	}
	return ans;
}

//////////////////////////////////////////////

void solve(){
	vector<int> v=get_vector();
	int k=5;
	cout<<Allocate_Min_MaxNoPages(v,k);
}