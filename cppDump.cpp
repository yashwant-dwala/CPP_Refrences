sort(ar,ar+11);//automatic
swap(a,b);//automatic
__gcd(a,b); //automatic
next_permutation(s.begin(),s.end());
s.substr(index,length);


int maxSum_SubArr_MaxLen_KADANES(vector<int> a){
    int Curr=0,Max=0,st=0,ed=0;
    for(auto x:a){
        Curr+=x;
        Max=max(Max,Curr);
        if(Curr<0) Curr=0;
        if(st==0&&Curr>=0)st=x;
        else if(Curr==Max&&st!=0) ed=x;
    }
    return Max;
}

int findSubarray_withSum_0(vector<int> a, int n ) {
    int Min=0,Max=0,sum=0;
    for(auto x:a){
        if(x<0) Min+=x;
        else Max+=x;
        sum=Max+Min;
        print(Max,Min,sum,x);
    }
    return sum;
}

int minJumps(int arr[], int n){
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    int maxReach = arr[0];
    int i = 1,jump = 1,step = arr[0];
	    for (i = 1; i < n; i++) {
	        if (i == n - 1)
	            return jump;
	        maxReach = (maxReach > i + arr[i]) ? maxReach : i + arr[i];
	        step--;

	        if (step == 0) {
	            jump++;
	            if (i >= maxReach)
	                return -1;
	            step = maxReach - i;
	        }
	    }
	    return -1;
    }
int findDuplicate(std::vector<int> nums){
	int n = nums.size();
    int a[n],ans=0;
    for(int i =0;i<n;i++){
        a[i]=0;
        cout<<a[i]<<",";
    }
    cout<<" ---- "<<endl;
    for(int i=0;i<n;i++){
        a[nums[i]]++;
        if(a[nums[i]]>1){
            ans=nums[i];
        }
        cout<<a[i]<<",";
    }
    cout<<" ---- "<<endl;
    return ans;
} 

void alternativeOrder(int a[],int n){
	int k=0;
	int po[n],ne[n];
	int i=0,j=0;
	while(k<n){
		if(a[k]<0){
			ne[j]=a[k]; j++;
		}
		else if (a[k]>0){
			po[i]=a[k]; i++;
		}
		k++;
	}
	int l=0,r=0;
	for(k=0;k<n;k++){
		if(k==0){
			if(i>0){
			a[k]=ne[l];l++;
			}else{
			a[k]=po[r];r++;}
		}
		else if(k>0){
			if(k%2==0){
				if(l<j){
					a[k]=ne[l];
					l++;
				}
				else{
					a[k]=po[r];
				r++;
				}
				// negative
			}
			else{
				if (r<i)
				{
					a[k]=po[r];
				r++;
				}
				else{
					a[k]=ne[l];
					l++;
				}
				//posetive
			}
		}

	}


bool find3Numbers(int A[], int n, int X)
    {
        int l=0,r=0;
        sort(A,A+n);
        for(int i=0;i<n;i++){
            if(A[i]<X &&A[i+1]>X)
            {
                r=i;
                break;
            }
                       //  (x+y+z) = X 
        }
        int m = (r%2==0)?r/2:(r/2)+1; 
        while(l<m||r>m){
            if(A[l]+A[m]+A[r]==X)
            return true;
            else if(A[l]+A[m]+A[r]<=X){
                l++;
            }
            else if(A[l]+A[m]+A[r]>=X){
                r--;
            }
            else if(A[l]+A[m]+A[r]<=X &&l==m-1)
            r--;
            else if(A[l]+A[m]+A[r]>=X && r==m+1)
            l++;
            else if(l==m-1&&r==m+1&&A[l]+A[m]+A[r]!=X)
            return false;
        }
        return false;
    }


def subArrayExists(self,arr,n):
    ##Your code here
    #Return true or false
    sum=0
    A=set()
    for i in range(n):
        sum+=arr[i]
        if sum==0 or sum in A:    // with sum = 0
            return True
        A.add(sum)
    return False


void printdigitsOfNumber(int n){
    int r=0;
    while(n>0){
        r=n%10;
        n=(n-r)/10;
        cout<<"rem "<<r<<",no: "<<n<<endl;
    }
}
void duplicatesCount(string s){
    // Convert to LOWERCASE
    for_each(s.begin(), s.end(), [](char & c) {
        c = tolower(c);
    });

    unordered_map<char,int> u;
    for(char x='a';x<='z';x++)
        u[x]=0;
    char x='a';
    while(x<='z'){
        for(int i=0;i<s.size();i++){
            if(x==s[i])
                u[x]++;
        }
        x++;
    }

    // important remember this //
    for(auto x:u){
        if(x.second>1)
            cout<<x.first<<" is "<<x.second<<" times,"<<endl;
    }
    cout<<endl;

}

string countAndSay(int n) {
// n only from 1 to 30;
// Sequence : 1, 11, 21, 1211, 111221, ...
if(n==1) return "1";
if(n==2) return "11";
  
string s="11";

for(int i=3;i<=n;i++){
    string t="";
    s=s+"&";//delimeter to traverse complete
    int count=1;
     
    for(int j=1;j<s.length();j++){
         if(s[j]!=s[j-1]){
             t+=to_string(count);
             t+=s[j-1];
             count=1;
         }
         else 
             count++;
    }
    s=t;
  }

  return s;
}
void printSubsequence(string input, string output)
{
    if (input.empty()) {
        cout << output << endl;
        return;
    }
    printSubsequence(input.substr(1), output + input[0]);
    printSubsequence(input.substr(1), output);
}
vector<string>find_permutations(string s){
  vector<string> v;
  sort(s.begin(),s.end());//for being LEXICOGRAPHIC (dictionary order)
  do{
      v.push_back(s);
  }while(next_permutation(s.begin(),s.end()));
    return v;
}
vector<vector<int>> z;
void Permute(vector<int>& v, int idx){
    if(idx==v.size()){
        z.push_back(v);
        // for(auto i:v)
        // cout<<i<<" ";
        // cout<<endl;
        return;
    }
    for(int i=idx;i<v.size();i++){
        swap(v[i],v[idx]);
        Permute(v,idx+1);
        swap(v[i],v[idx]);
    }
    return;
}
void Rabin_Karp_ALGO(string t,string s){
    int  a[t.length()]={0};
    int x=-1,k=-1;
    bool done=1;
    while(done){
        x=t.find(s);
        if(x>t.length()||x<0){
            done=0;
            break;
        }
        a[++k]=x;
        t.replace(x,1,"Z"); 
    }
    if(k==-1)
        cout<<"Not Found!"<<endl;
    for(int i=0;i<=k;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}