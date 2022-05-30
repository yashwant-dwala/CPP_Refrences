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
#define LENGTH 1000001

struct Graph
{											
	int node;								
	int edge;								
	vector<int> *adj;						
	Graph(int n,int e){					 
		node=n; 										  
		edge=e;								
		this->adj= new vector<int> [n+1];
	}
};

////////////// Global variables
int N,E;
Graph* G; 
int vis[LENGTH]; // 0 since global
int dist[LENGTH];


void BuildGraph(int n,int e,bool directed){
	N=n; E=e;
	G= new Graph(n,e);
	for(int i=0;i<N+1;i++)	G->adj[i].clear();
	while(e--){
		int a,b;
		cin>>a>>b;
		G->adj[a].push_back(b);
		if(directed==false)	G->adj[b].push_back(a);
	}
}

void DFS(int v){
	vis[v]=1;
	print(v);
	for(int child: G->adj[v]){
		if(vis[child]==0) DFS(child);
	}
}

void BFS(int v){    // mostly for distance finding
	queue<int> q;
	q.push(v);
	vis[v]=1,dist[v]=0;
	while(!q.empty()){
		int curr=q.front(); q.pop();
		print(curr,dist[curr]);
		for(int ch: G->adj[curr])
			if(vis[ch]==0)
				q.push(ch),	vis[ch]=1, dist[ch]=dist[curr]+1;		 
	}
}
bool dfsUndirected_Cycle(int v,int par){
	vis[v]=1;
	for(int ch:G->adj[v]){ // order important //
		if(vis[ch]==0){
			if(dfsUndirected_Cycle(ch,v)==1) return 1;
		}
		else {
			if(ch!=par) return 1;
		}
	}
	return false;
}
bool dfsDirected_Cycle(int v){
	vis[v]=1;
	for(int ch:G->adj[v]){
		if(vis[ch]==0){
			if(dfsDirected_Cycle(ch)==1) return 1;
		}else{
			if(vis[ch]==1) return 1;	
		} 
	}
	vis[v]=2;
	return false;
}
bool detectCycle(bool directed){
	for(int i=0;i<G->node+1;i++){
		if(directed==false){
			if(vis[i]==0 and dfsUndirected_Cycle(i,-1)) return 1;				
		}
		else{
			if(vis[i]==0 and dfsDirected_Cycle(i)) return 1;
		} 
	}		
	return 0;
}

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
	// cin>>N>>E;
	// BuildGraph(N,E,false);
	// print(detectCycle(false));

	// int X=1,Y=3,Tx=3,Ty=1,n=3; 
	// minStepToReachTarget(X,Y,Tx,Ty,n);

	vector<vector<int>> grid;
	grid=get_N_M_Mat();
	int r=0,c=0,newColor=2;
	floodFill(grid,r,c,newColor);
}