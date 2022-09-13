#include<bits/stdc++.h>
#include "template.cpp"
using namespace std;

//......
/////............. D I J K S T R A  ...............//////////
//Function to find the shortest distance of all the vertices 
//from the source vertex S.  (SSSP)
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dis(V,INT_MAX);
    dis[S] =0;
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
    q.push({0,S});
    while(!q.empty()){
        int curr = q.top().second;
        int curr_d = q.top().first; q.pop();
        for(auto edge:adj[curr]){
            if(dis[edge[0]]> curr_d+edge[1]){
                dis[edge[0]] = curr_d+edge[1];
                q.push({dis[edge[0]],edge[0]});
            }
        }
    }
    return dis;
}

/////// ............ T O P O L O G I C A L  S O R T   ...............//////
// only for directed acyclic

vector<int> vis;
void dfsTopo(int n,vector<int> adj[],stack<int> &s){
    vis[n] = 1;
    for(int ch:adj[n]){
        if(vis[ch]==0){
            dfsTopo(ch,adj,s);
        }
    }
    s.push(n);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vis = vector<int> (V,0);
    stack<int> s;
    for(int i=0;i<V;i++){
        if(vis[i]==0) dfsT(i,adj,s);
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    for(auto x : ans) cout<<x<<" ";
    return ans;
}

/////............... K R U S K A L .............. /////////
// find (MST)
vector<int> par; // par[i]=i 
vector<int> r; // 0  rank

int findPar(int a){
    if(par[a]==a) return a;
    return par[a] = findPar(par[a]); // path compression
}

void Union(int a,int b){
    b=par[b]; 
    a=par[a];
    if(r[a]<r[b]){
        par[a]=b;
    }
    else if(r[b]<r[a]) par[b]=a;
    else{
        par[b] =a;
        r[a]++;
    }
}
struct edge{
    int a;
    int b;
    int w;
    edge(int A,int B,int W){
        a=A; b=B; w=W;
    }
};
bool comp(edge a,edge b){
    return a.w<b.w;
}
int Kruskal(int n,vector<pair<int,int>> adj[],int e){
    int sum = 0;
    vector<edge> Ed;
    int t[n][n];
    memset(t,0,sizeof(t));
    for(int i=0;i<n;i++){
        for(auto ch: adj[i]){
            if(t[i][ch.first]==0){
                Ed.push_back(edge(i,ch.first,ch.second));
                t[i][ch.first]=t[ch.first][i]=1;            
            }
        }
    }
    sort(Ed.begin(),Ed.end(),comp);
    r.clear();
    par = vector<int> (n,0);
    r = vector<int> (n,0);
    for(int i=0;i<n;i++) par[i]=i;
    for(auto x:Ed){
        if(findPar(x.a)!=findPar(x.b)){
            sum += x.w;
            Union(x.a,x.b);
        }
    }
    return sum;
}

////// .............. P R I M S ............... ////////
// find  (MST)
bool cmp(vector<int> a,vector<int> b){
    return a[1]<b[1];
}
int PRIMS(int V, vector<vector<int>> adj[])
{
    int sum=0;
    // {wt,vert}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<bool> inMST(V,false);
    q.push({0,0});
    while(!q.empty()){
        int curr_wt = q.top().first;
        int curr = q.top().second;
        q.pop();
        if(inMST[curr]==true) continue; // this fucking line makes a big difference
        sum+=curr_wt;
        inMST[curr] = true;
        for(auto edge:adj[curr]){
            if(inMST[edge[0]]==false){
                q.push({edge[1],edge[0]});
            }
        }
    }
    return sum;
}
/// .................. B E L L M A N  F O R D  ............./////

/// for negative weight CYCLE DETECTION in DIRECTED graph
// edges : {0,1,-1},{1,2,-2},{2,1,-3}    (SSSP)
bool isNegativeWeightCycle(int n, vector<vector<int>> edges){
   vector<int> dis(n,INT_MAX);
   dis[0] = 0;  // must do 0 
   for(int i=0;i<n-1;i++){
       for(auto e:edges){
           if(dis[e[0]]!=INT_MAX and dis[e[1]] > dis[e[0]] + e[2] ) dis[e[1]] = dis[e[0]] + e[2];
       }
   }
   for(auto e:edges){
       if(dis[e[0]]!= INT_MAX and dis[e[1]]>dis[e[0]]+e[2]) return 1;
   }
   return 0;
}

////////............ F L O Y D  W A R S H E L L ............ //////
// ALL PAIR SHORTEST PATH
// TIME = O(V^3)
// SPACE = O(V^2)
void shortest_distance(vector<vector<int>>&adj_MAT){
    int n = adj.size();
    int m = adj[0].size();
    int k = 0;
    while(k<n){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // include vertex k , not include vertex k
                if(adj_MAT[i][k]==INT_MAX or adj_MAT[k][j]==INT_MAX) continue;
                else adj_MAT[i][j] = min(adj_MAT[i][j],adj_MAT[i][k]+adj_MAT[k][j]);
            }
        }
        k++;
    }
}

///// ................ K O S A R A J U ' S ..........////
// FOR SCC count
void dfs(int n,vector<int> adj[]){
    vis[n] =1;
    for(int ch:adj[n]){
        if(vis[ch]==0) dfs(ch,adj);
    }
}
int kosaraju(int V, vector<int> adj[])
{
    // fill topoSort-Stack 
    stack<int> s;
    vis = vector<int> (V,0);
    for(int i=0;i<V;i++) if(vis[i]==0) dfsTopo(i,adj,s);
    
    //transpose Graph
    vector<int> Adj[V];
    for(int i=0;i<V;i++){
        for(int b:adj[i]) Adj[b].push_back(i);
    }
    
    // find scc using topSort-stack
    int scc =0;
    vis = vector<int> (V,0);
    while(!s.empty()){
        if(vis[s.top()]==0) {
            dfs(s.top(),Adj);
            scc++;
        } 
        s.pop();
    }
    
    return scc;
}



void Solve(){

}