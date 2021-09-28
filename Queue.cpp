#include<bits/stdc++.h>
using namespace std;

void print_Q(queue<int> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}
vector<string> get_Sq_Mat(){
	int N;
	cin>>N;
	vector<string> v;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		v.push_back(s);
	}
	return v;
}


stack<int> reverseStack(stack<int> q){
	stack<int> s;
	while(!q.empty()){
		s.push(q.top());
		q.pop();
	}
	return s;
}
queue<int> Interleave(queue<int> q){
	stack<int> s1,s2;
	int n=q.size(),Start,End;
	int i=0;
	while(!q.empty()){
		if(i>0&&i<n-1){
			if(i<n/2){
				s1.push(q.front());
				q.pop();
			}else{
				s2.push(q.front());
				q.pop();
			}
		}
		else {
			if(i==0){ Start=q.front(); q.pop(); }
			else{End=q.front(); q.pop();}
		}
		i++;
	}
	s1=reverseStack(s1);
	s2=reverseStack(s2);
	q.push(Start);
	i=1;
	while(i<=n-2){
		if(i%2==0){
			q.push(s1.top());
			s1.pop();
		}
		else {
			q.push(s2.top());
			s2.pop();
		}
		i++;
	}
	q.push(End);
	return q;
}
string reachTheEnd(vector<string> g, int maxTime){
	int n =g.size();
	int time=0;
	int l=0,bot=0;
	string ans="No";
	while(l<n&&bot<n){
		if(l==n-1&&bot==n-1) return ans;

		cout<<"Enter "<<time<<endl;
		if(time>=maxTime and (l<n-1||bot<n-1)) return ans;
  	
    	if(g[bot][l+1]!='#'&&l<n-1){
        	time++; l++;
      	}
      	if(g[bot+1][l]!='#'&&bot<n-1){
          time++; bot++;
      	}
     	if(g[bot+1][l]=='#'&&g[bot][l+1]=='#'){
       		time--;
          	if(g[bot-1][l]!='#'&& bot>0){
            	bot--;
          	}
          	else{
            	if(l>0){
                	l--;          
              	}
	        }
		}
	ans="Yes";
	return ans;
}

int main(){
	queue<int> q;
	q.push(5);
	q.push(0);
	q.push(9);
	q.push(7);
	q.push(5);
	vector<string> v=get_Sq_Mat();
	cout<<reachTheEnd(v,3);
	// cout<<reachTheEnd(v,4);
	cout<<reachTheEnd(v,2);
	cout<<reachTheEnd(v,6);

	return 0;

}
