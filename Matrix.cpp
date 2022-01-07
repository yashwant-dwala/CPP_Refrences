#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;

//////////////////////////////////////////////////////////////

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