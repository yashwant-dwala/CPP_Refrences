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
}
vector<vector<int>> get_N_M_Mat(){
    int N,M;
    cin>>N;
    cin>>M;
    vector<vector<int>> v;
    for(int i=0;i<N;i++){
        vector<int> a;
        for(int j=0;j<M;j++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        v.push_back(a);
    }
    return v;
}

//////////////////////  TEMPLATE END /////////////////////////////////


vector<vector<int>> sortedMatrix(vector<vector<int>> v) {
    vector<int> temp;
    for(auto i : v)
        temp.insert(temp.end(), i.begin(), i.end());
        sort(temp.begin(), temp.end());

    int counter = 0;
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            v[i][j] = temp[counter++];
        }
    }
    return v;
}
vector<vector<int>> rotateMatrix90(vector<vector<int>> M,int n){
	
	//only square matrix

	vector<vector<int>> a=M;
	for(int i=0;i<n;i++){
    	for (int j = 0; j < n; j++)
    	{
   			a[i][j]=M[n-1-j][i];
    	}
	  }
	return a;
}
void printCommonElements(vector<vector<int>> maT, int m,int n)
{
	// m==rows ,n==columns//
	
    unordered_map<int, int> mp;
    for (int j = 0; j < n; j++)
        mp[maT[0][j]] = 1;

    for (int i = 1; i < m; i++){
        for (int j = 0; j < n; j++){
            if (mp[maT[i][j]] == i)
            {
                mp[maT[i][j]] = i +1;
                if (i==m-1 && mp[maT[i][j]]==m)
                  cout << maT[i][j] << " ";
            }
        }
    }
    cout<<endl;
}

//////////////////////////////////////////////////

int main(){
    vector<vector<int>> v =get_N_M_Mat();
    print_mat(v);
    v=rotateMatrix90(v,3);
    print_mat(v);
    printCommonElements(v,3,3);

    
    return 0;
}