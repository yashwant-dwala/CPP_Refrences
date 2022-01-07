#include<bits/stdc++.h>
#include "Template.cpp"
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
string FirstNonRepeating(string a){
   int count[26]={0};
   queue<char> q;
   string ans="";
   for(auto x:a){
       q.push(x);
       count[x-'a']++;
       if(!q.empty()&&count[q.front()-'a']==1) ans+=q.front();
       else if(count[q.front()-'a']>1) { 
           while(!q.empty()&&count[q.front()-'a']>1)
             q.pop();
           if(!q.empty()) ans+=q.front();
           else ans+='#';
       }
   }
   return ans;
}

void Solve(){
	queue<int> q;
	q.push(5);
	q.push(0);
	q.push(9);
	q.push(7);
	q.push(5);
}
