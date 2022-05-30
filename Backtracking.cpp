#include <bits/stdc++.h>
#include "Template.cpp"
using namespace std;

//////////////////////////  B A C K T R A C K I N G //////////////////////

////////////  RAT IN MAZE  POSSIBLE PATHS /////////////
// UP ,Down ,Left ,Right : (U ,D ,L ,R)

int vis[4][4];
void RIM_All_possible_paths(int i,int j,string s,vector<vector<int>> &maze,int n){
	// when boundries or Blocked or already stepped
	if(i<0 or j<0 or i>=n or j>=n or maze[i][j]==0 or vis[i][j]==1)	return;  
	// hit the end point
	if(i==j and i==n-1) {
		print(s);
		return;
	}
	//stepped
	vis[i][j]=1;
	// go to all directions
	RIM_All_possible_paths(i,j-1,s+"L",maze,n);
	RIM_All_possible_paths(i,j+1,s+"R",maze,n);
	RIM_All_possible_paths(i-1,j,s+"U",maze,n);
	RIM_All_possible_paths(i+1,j,s+"D",maze,n);
	// cleared for next path detection
	vis[i][j]=0;
}

void printPossiblePaths(vector<vector<int>> &maze,int n){
	// start 0 0  // end n-1,n-1;
	if(maze[0][0]==0 or maze[n-1][n-1]==0) {
		print("Not Possible!"); return;
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) 
			vis[i][j]=0;

	string s="";
	RIM_All_possible_paths(0,0,s,maze,n);
}





/////////////////////////////////

void Solve(){
	int n=4;
	vector<vector<int>> maze;
	maze=get_N_M_Mat();
	printPossiblePaths(maze,n);
	
}
