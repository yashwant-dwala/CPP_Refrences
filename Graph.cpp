#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;

// 6 6										1 
// 1 2									  / 
// 2 3   INPUT For Graph Beside			2       5
// 2 4								  /   \   /							
// 3 4								 3  _   4  _  6
// 4 5
// 4 6

//////////////////// G R A P H S //////////////////////////////////

class Graph
{
	public:
		Graph* G;
		int N ,E;
		int timer = 0; 
		vector<int> *adj;
		vector<int> vis;
		vector<int> dist;
		vector<int> lowtime;
		vector<int> intime;
		bool directed=false;

		Graph(bool d){
			cin>>N>>E;
			directed = d;
			timer=0;
			this->adj = new vector<int> [N+1];
			vis = vector<int> (N+1,0);
			dist = vector<int> (N+1,0);
			intime = vector<int> (N+1,0);
			lowtime = vector<int> (N+1,INT_MAX);
		};
		~Graph(){ };

		void ClearGraph(){
			timer=0;
			vis = vector<int> (N+1,0);
			dist = vector<int> (N+1,0);
			intime = vector<int> (N+1,0);
			lowtime = vector<int> (N+1,INT_MAX);
		}
		void BuildGraph(){
			for(int i=0;i<N+1;i++)	adj[i].clear();
			int e = E;
			while(e--){
				int a,b;
				cin>>a>>b;
				adj[a].push_back(b);
				if(directed==false)	adj[b].push_back(a);
			}
		};
		void DFS(int v){
			vis[v]=1;
			print(v);
			for(int child: adj[v]){
				if(vis[child]==0) DFS(child);
			}
		};
		void BFS(int v){    // mostly for distance finding
			queue<int> q;
			q.push(v);
			vis[v]=1,dist[v]=0;
			while(!q.empty()){
				int curr=q.front(); q.pop();
				for(int ch: adj[curr])
					if(vis[ch]==0)
						q.push(ch),	vis[ch]=1, dist[ch]=dist[curr]+1;		 
			}
			print_vec(dist);
		};
		bool dfsUndirected_Cycle(int v,int par){
			vis[v]=1;
			for(int ch:adj[v]){ // order important //
				if(vis[ch]==0){
					if(dfsUndirected_Cycle(ch,v)==1) return 1;
				}
				else {
					if(ch!=par) return 1;
				}
			}
			return false;
		};
		bool dfsDirected_Cycle(int v){
			vis[v]=1;
			for(int ch:adj[v]){
				if(vis[ch]==0 and dfsDirected_Cycle(ch)) return 1;
				else if(vis[ch]==1) return 1;	
			}
			vis[v]=2;
			return false;
		};
		void detectCycle(){
			for(int i=1;i<=N;i++){
				if(directed==false){
					if(vis[i]==0 and dfsUndirected_Cycle(i,-1)) {
						print("yes it is Cyclic.");
						return;
					}				
				}
				else{
					if(vis[i]==0 and dfsDirected_Cycle(i)) {
						print("yes it is Cyclic.");
						return;
					}
				} 
			}		
			print("No, it is not Cyclic.");
		};
		void Print_Bridges_Dfs(int n,int p){
		    vis[n] = 1;
		    intime[n]=lowtime[n]= timer++;
		    for(int ch:adj[n]){
		        if(ch==p) continue;
		        else if(vis[ch]==1){
		            //back - edge reduce lowtime
		            lowtime[n] = min(lowtime[n],intime[ch]);
		        }
		        else{
		            // forward edge
		            Print_Bridges_Dfs(ch,n);
		            if(lowtime[ch]>intime[n]){
		                //bridge
		                print("bridge :", n,ch);
		            }
		            lowtime[n] = min(lowtime[n],lowtime[ch]);
		        }
		    }
		};
};

///////////////////////////////////////////////////

/////////////////  Steps by Knight /////////
// (X,Y) to target (Tx,Ty), steps = ??
// 1 based indexing
// ek do dhai :-) , all 8 possible cases :_)
void minStepToReachTarget(int x,int y,int Tx,int Ty,int BoardSize){ //BFS
	int n=BoardSize;
	int board[n+1][n+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			board[i][j]=0;
	if(x==Tx and y==Ty) return;
	queue<pair<int,int>> q;
	q.push({x,y});
	
	while(!q.empty()){
		pair<int,int> p=q.front(); q.pop();
		int i=p.first,j=p.second;
		if(i==Tx and j==Ty) break;
		if(i+2<=n and j+1<=n and board[i+2][j+1]==0){
			q.push({i+2,j+1});
			board[i+2][j+1]=board[i][j]+1;			
		} 
		if(i+2<=n and j-1>=0 and board[i+2][j-1]==0){
			q.push({i+2,j-1});
			board[i+2][j-1]=board[i][j]+1;
		}
		if(i-2>=0 and j+1<=n and board[i-2][j+1]==0){
			q.push({i-2,j+1});
			board[i-2][j+1]=board[i][j]+1;
		}
		if(i-2>=0 and j-1>=0 and board[i-2][j-1]==0){
			q.push({i-2,j-1});
			board[i-2][j-1]=board[i][j]+1;
		}
		if(i+1<=n and j+2<=n and board[i+1][j+2]==0){
			q.push({i+1,j+2});
			board[i+1][j+2]=board[i][j]+1;
		}
		if(i+1<=n and j-2>=0 and board[i+1][j-2]==0){
			q.push({i+1,j-2});
			board[i+1][j-2]=board[i][j]+1;
		}
		if(i-1>=0 and j+2<=n and board[i-1][j+2]==0){
			q.push({i-1,j+2});
			board[i-1][j+2]=board[i][j]+1;
		}
		if(i-1>=0 and j-2>=0 and board[i-1][j-2]==0){
			q.push({i-1,j-2});
			board[i-1][j-2]=board[i][j]+1;
		}	
	}
	print(board[Tx][Ty]);
}

///////////// floodFill ////////
// given r,c,newColor= 1,1,2
//  1  1  1          2 2 2
//  1 *1  0   ==>    2 2 0
//  1  0  1          2 0 1
void dfsFill(vector<vector<int>> &img, int newColor, int source,int i,int j){
	static int n=img.size();
	static int m=img[0].size();
	if(i>=n or i<0 or j>=m or j<0) return ; 
	else if(img[i][j]!=source) return; //extra sure for index

	img[i][j]=newColor;

	dfsFill(img,newColor,source,i-1,j);
	dfsFill(img,newColor,source,i+1,j);
	dfsFill(img,newColor,source,i,j-1);
	dfsFill(img,newColor,source,i,j+1);
}
void floodFill(vector<vector<int>> &img,int r,int c,int newColor){
	int source=img[r][c];
	if(source==newColor) return;
	dfsFill(img,newColor,source,r,c);
	print_mat(img);
}
///////////////////////////////////////


void Solve(){
	Graph G = Graph(false);
	G.BuildGraph();
	print("DFS :");
	G.DFS(1);
	G.ClearGraph();
	print("BFS (1 based indexed): ");
	G.BFS(1);
	G.ClearGraph();
	G.detectCycle();
	G.ClearGraph();
	G.Print_Bridges_Dfs(1,-1);

}