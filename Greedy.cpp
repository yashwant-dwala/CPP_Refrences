#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;

/////////////////////////////// GREEDY /////////////////////////////////

//Function to find the maximum profit and the number of jobs done.
struct Job { 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
static bool cmp(Job a,Job b){
    return a.profit>b.profit; //GREEDY
}
vector<int> JobScheduling(Job a[], int n) 
{ 
    // Maximum profit sort descending order
   sort(a,a+n,cmp);
   
   int day=0,profit=0;
   bool done[n]={0}; //schedule them
   
   for(int i=0;i<n;i++){
       for(int j=min(n,a[i].dead-1);j>=0;j--){
           if(done[j]==false){
               day++;
               profit+=a[i].profit;
               done[j]=true;
               break;
           }
       }
   } 
   return {day,profit};
}
  
///     hoffman Codes
struct Node{
    int freq;
    Node* left, * right;
    Node(int i){
        left=right=NULL;
        freq=i;
    }
};
static bool comp(Node* a,Node* b){
    return a->freq<b->freq;
}
void Search(Node* root,vector<string> &v,string s){
    if(root==NULL) return;
    Search(root->left,v,s+"0");
    print(root->freq,s);
    if(root->left==NULL and root->right==NULL){
         v.push_back(s);
    }
    Search(root->right,v,s+"1");
}
vector<string> huffmanCodes(string S,vector<int> f,int n)
{
    vector<Node*> v;
    for(int i=0;i<n;i++){
        Node* x=new Node(f[i]);
        v.push_back(x);
    }
    while(v.size()!=1){
        sort(v.begin(),v.end(),comp);
        Node* a=v[0];
        Node* b=v[1];
        Node* res=new Node(a->freq+b->freq);
        v.erase(v.begin());
        v.erase(v.begin());
        res->left=a;
        res->right=b;
        v.push_back(res);
    }
    vector<string> s;
    Search(v[0],s,"");
    return s;
}     


//////////////////////////

void Solve(){
	vector<int> v;
	string s="qwertyuiopasdfghjklzxcvbn";
	v=get_vector(1); //type required
	vector<string> y=huffmanCodes(s,v,v.size());
	print_vec(y);
}

// 0000 0001 00100 001010 001011 0011 0100 0101 0110 0111 1000 100100 100101 10011 1010 1011 1100 1101 11100 11101 111100 1111010 11110110 11110111 11111 
// 0000 0001 00100 001010 001011 0011 0100 0101 0110 0111 1000 100100 100101 10011 1010 1011 1100 11010 11011 1110 111100 1111010 11110110 11110111 11111