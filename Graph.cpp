#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;

#define all(x) x.begin(),x.end()

// 8 7										1 
// 1 2									  / 
// 2 3   INPUT For Graph Beside			2       5     7 _  8
// 2 4								  /   \   /							
// 3 4								 3  _   4  _  6
// 4 5
// 4 6
// 7 8

//////////////////// G R A P H S //////////////////////////////////

class Graph
{
	public:
		int N, E, timer;
		bool directed,isCyclic;
		vector<int> *adj;
		vector<int> vis;
		vector<int> dist;
		vector<int> lowtime;
		vector<int> intime;
		vector<int> show;
		stack<int> topo_Stack;

		Graph(bool d = false){
			cin>>N>>E;
			directed = d, isCyclic=false;
			timer=0;
			this->adj = new vector<int> [N+1];

			int e = E;
			while(e--){
				int a,b;
				cin>>a>>b;
				adj[a].push_back(b);
				if(directed==false)	adj[b].push_back(a);
			}

			vis = vector<int> (N+1,0);
			dist = vector<int> (N+1,0);
			intime = vector<int> (N+1,0);
			lowtime = vector<int> (N+1,INT_MAX);
		};
		~Graph(){ };

		void ClearGraph(){
			show.clear();
			timer=0;
			vis = vector<int> (N+1,0);
			dist = vector<int> (N+1,0);
			intime = vector<int> (N+1,0);
			lowtime = vector<int> (N+1,INT_MAX);
		}
		bool dfs(int v,int par = -1,bool topSorting = false){
			vis[v]=1;
			if(topSorting==false) show.push_back(v);
			for(int ch: adj[v]){
				if(directed == false){
					if(vis[ch]==0 and dfs(ch,v,topSorting)==1) isCyclic = 1;
					else if(ch!=par) isCyclic = 1;
				}
				else if(directed == true){
					if(vis[ch]==0 and dfs(ch,par,topSorting)) isCyclic = 1;
					else if(vis[ch]==1) isCyclic = 1;
				}
			}
			if(topSorting and directed) topo_Stack.push(v);
			if(directed) vis[v]=2;
			return isCyclic;
		}
		void DFS(){
			for(int i=0;i<N;i++){
				if(vis[i]==0) dfs(i,-1);
			}
			print_vec(show);
		};
		void BFS(){    // mostly for distance finding
			int v = 1;
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
		void detectCycle(){
			for(int i=1;i<=N;i++){
				if(vis[i]==0 and dfs(i,-1)) {
					print("Cyclic: yes");
					return;
				}				
			}		
			print("Cyclic: No");
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
		void TopSort(){
			for(int i=0;i<N;i++){
				if(vis[i]==0) dfs(i,-1,true);
			}
			while(!topo_Stack.empty()){
				show.push_back(topo_Stack.top());
				topo_Stack.pop();
			}
			cout<<"TopSort: "; print_vec(show);
		};
	// K O S A R A J U   s c c 
	// 	void dfs_SCC(int n,vector<int> Adj[]){
	// 	    vis[n] =1;
	// 	    for(int ch:Adj[n]){
	// 	        if(vis[ch]==0) dfs_SCC(ch,Adj);
	// 	    }
	// 	};
	// 	void SCC_Count(){
	//     // fill topoSort-Stack 
	//     for(int i=1;i<N+1;i++) 
	//     	if(vis[i]==0) dfs(i,-1,true);
	    
	//     //transpose Graph
	//     vector<int> Adj[N+1];
	//     for(int i=1;i<N+1;i++){
	//         for(int b:adj[i]) Adj[b].push_back(i);
	//     }
	    
	//     // find scc using topSort-stack
	//     int scc =0;
	//     ClearGraph();
	//     while(!topo_Stack.empty()){
	//         if(vis[topo_Stack.top()]==0) {
	//             dfs_SCC(topo_Stack.top(),Adj);
	//             scc++;
	//         } 
	//         topo_Stack.pop();
	//     }
	    
	//     print("SCC_Count: ",scc);
	// };
};

///////////////////////////////////////////////////


void Solve(){
	print("1-based indexing!");
	Graph G = Graph(true);
	cout<<"DFS: ";
	G.DFS();
	G.ClearGraph();
	cout<<"BFS: ";
	G.BFS();
	G.ClearGraph();
	G.detectCycle();
	G.ClearGraph();
	G.Print_Bridges_Dfs(1,-1);
	G.ClearGraph();
	G.TopSort();
	// G.ClearGraph();
	// G.SCC_Count();

}