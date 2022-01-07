#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;

////////////////// BOILER PLATE FOR BTREE //////////////
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x){
		data=x;
		left=NULL;
		right=NULL;
	}
};

Node* Insert(Node* Root,int x){
	if(Root==NULL) {
		Node* temp=new Node(x);
		return temp;
	}
	if(x<=Root->data) Root->left=Insert(Root->left,x);
	else Root->right=Insert(Root->right,x);
	return Root;
}
Node* get_Nodes(Node* root){
	int n; cin>>n;
	while(n--){
		int x; cin>>x;
		root=Insert(root,x);
	}
	return root;
}
void allOrder(Node* root){ //DFS
	vector<int> pre,in,post;
	stack<pair<Node*,int>> s;
	s.push({root,1});
	while(!s.empty()){
		switch(s.top().second){
			case 1: // pre.push, state++, left->
				pre.push_back(s.top().first->data);
				s.top().second++;
				if(s.top().first->left) s.push({s.top().first->left,1});
				break;
			case 2: // in.push, state++, right->
				in.push_back(s.top().first->data);
				s.top().second++;
				if(s.top().first->right) s.push({s.top().first->right,1});
				break;
			case 3: // post.push, pop()
				post.push_back(s.top().first->data);
				s.pop();
				break;
		}	
	}
	cout<<"Pre: "; print_vec(pre); 
	cout<<"In: "; print_vec(in);
	cout<<"Post: "; print_vec(post);
}
void InOrderTraversal(Node* root){
	if(!root) return;
	InOrderTraversal(root->left);
	cout<<root->data<<" ";
	InOrderTraversal(root->right);
}
void LevelOrderTraversal(Node* root){ // BFS or levelOrder { Space: O(n) }
	vector<int> v;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        v.push_back(q.front()->data);
        if(q.front()->left!=NULL) q.push(q.front()->left);
        if(q.front()->right!=NULL) q.push(q.front()->right);
        q.pop();
    }
    print_vec(v);
}
void reverseLevelOrder(Node *root)
{
    vector<int> v;
    stack<int> s;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        s.push(q.front()->data);
        if(q.front()->right) q.push(q.front()->right);
        if(q.front()->left) q.push(q.front()->left);
        q.pop();
    }
    while(!s.empty()){
    	v.push_back(s.top());
    	s.pop();
    }
    print_vec(v);
}
int height(Node* root){
	if(root==NULL) return 0;
	return 1+max(height(root->left),height(root->right));
}
int diaNode(Node* root){
	// longest distaance b/w any 2 nodes including that
    if (root==NULL) return 0;
    return (1+height(root->left)+height(root->right));
}
int diameter(Node* root) {
	// longest distaance b/w any 2 nodes
    if(root==NULL) return 0;
    int x=max(diaNode(root->left),diaNode(root->right));
    return max(x,diaNode(root));
}
Node* createMirrorTree(Node* root){
	if(!root){
		return NULL;
	}
	Node* copy=new Node(root->data);
	copy->left=createMirrorTree(root->left);
	copy->right=createMirrorTree(root->right);
	return copy;
}

vector<int> leftView(Node* root){  // levelOrder with condition
	vector<int> v;
	if(!root) return v;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		int Lev_size = q.size();
		v.push_back(q.front()->data);
		while(Lev_size--){
			Node* temp=q.front();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
			q.pop();
		}
	}
	return v;
}

vector<int> rightView(Node *root){  // itrative
    vector<int> v;
    if(!root) return v;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        v.push_back(q.back()->data);
        while(s--){
            Node* t=q.front();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            q.pop();
        }
    }
    return v;
}
int maxLevel=0;
void RightView(Node* root,int level){ // reccursive
	// initial level > maxLevel
	if(root==NULL) return;
	if(maxLevel<level){
		maxLevel=level;
		cout<<root->data<<" ";
	}
	RightView(root->right,level+1);
	RightView(root->left,level+1);
}
vector<int> topView(Node* root){
	// default map is arranged in asscending order of key (left to right)
	vector<int> v;
	if(!root) return v;
	map<int,int> m; // {height, Node_value}
	queue<pair<int,Node*>> q; // {height,Node}
	q.push({0,root});
	while(!q.empty()){
	    Node* t=q.front().second;
	    if(m[q.front().first]==0) m[q.front().first]=t->data;
	    if(t->left) q.push({q.front().first-1,t->left});
	    if(t->right) q.push({q.front().first+1,t->right});
	    q.pop();
	}
	for(auto x: m) v.push_back(x.second);
	return v; 
}
vector<int> bottomView(Node* root){
	vector<int> v;
	if(!root) return v;
	map<int,int> m; // {height, Node_value}
	queue<pair<int,Node*>> q; // {height,Node}
	q.push({0,root});
	while(!q.empty()){
	    Node* t=q.front().second;
	    m[q.front().first]=t->data;
	    if(t->left) q.push({q.front().first-1,t->left});
	    if(t->right) q.push({q.front().first+1,t->right});
	    q.pop();
	}
	for(auto x: m) v.push_back(x.second);
	return v; 
}

void diagonalTraversal(Node* root){
	vector<int> v;
	if(!root) return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* t=q.front();
		while(t!=NULL){
			v.push_back(t->data);
			if(t->left) q.push(t->left);
			t=t->right;
		}		
		q.pop();
	}
	print_vec(v);
}
pair<string,string> breaking_L_R_subTree(string s){
	if(s.size()<=3) return {s,""};
	string l="(",r="";
	stack<char> st;
	st.push(s[0]);
	int i=1;
	while(!st.empty()){
		l+=s[i];
		if(s[i]=='(') st.push(s[i]);
		else if(s[i]==')') st.pop();
		i++;
	}
	r=s.substr(i);
	return {l,r};
}
Node* extractRootNode(string s){
	Node* t=NULL;
	if(s[0]=='('&&s.size()>2) t=new Node((int)(s[1]-48));
	if(s[0]!='('&& s[0]!= ')'&& s.size()>=2) t=new Node((int)(s[0]-48));
	return t;
}
Node* treeFromString(Node* root,string s){
	if(s=="" or s==")" ) return root;
	if( s.size()<=3 ) return extractRootNode(s);
	root=new Node((int)(s[0]-48));
	pair<string,string> p=breaking_L_R_subTree((s.substr(1)));
	root->left=extractRootNode(p.first);
	root->right=extractRootNode(p.second);
	root->left=treeFromString(root->left,p.first.substr(1));
	root->right=treeFromString(root->right,p.second.substr(1));
	return root;
}

// DLL from Btree
void InQueue(Node* root,queue<Node*> &q){
    if(root==NULL) return;
    InQueue(root->left,q);
    q.push(root);
    InQueue(root->right,q);
}
Node * bToDLL(Node *root)
{
    queue<Node*> q;
    InQueue(root,q);
    Node* head=q.front();
    head->left=NULL;
    Node* t=head;
    q.pop();
    while(!q.empty()){
        t->right=q.front();
        q.front()->left=t;
        t=q.front();
        q.pop();
    }
    t->right=NULL;
    return head;
}

// Transform to Sum Tree
int sum(Node* root){
    if(!root)  return 0;  
    int x= sum(root->left);
    int y= sum(root->right);
    int z=root->data;
    root->data=x+y;
    return root->data+z;
}
void toSumTree(Node *root)
{
    sum(root);
}

// Tree from Inorder and PreOrder Traversal :
int idx=0;
unordered_map<int,int> m;
Node* Tree(int in[],int pre[],int l,int r){
    if(l>r) return NULL;
    Node* root=new Node(pre[idx++]);
    if(l==r) return root;
    int mid=m[root->data];
    root->left=Tree(in,pre,l,mid-1);
    root->right=Tree(in,pre,mid+1,r);
    return root;
}
Node* buildTree(int in[],int pre[], int n)
{
    idx=0;
    m.clear();
    for(int i=0;i,i<n;i++) m[in[i]]=i;
    return Tree(in,pre,0,n-1);
} 

//Minimum SWAP required to convert Btree to BST
// tree is arr. where root=i, root->left=2*i+1, root->right= 2*i+2;
void inFromPre(vector<int> p,int n,int i,vector<int> &v){
	if(i>=n) return;
	inFromPre(p,n,2*i+1,v);
	v.push_back(p[i]);
	inFromPre(p,n,2*i+2,v);
}
int minSwapToSortArr(vector<int> v,int n){
	vector<pair<int,int>> sv;
	for(int i=0;i<n;i++){
		sv.push_back({v[i],i});
	}
	sort(sv.begin(),sv.end());
	int count=0;
	for(int i=0;i<n;i++){
		if(i!=sv[i].second){ // index not same 
			count++;
			swap(sv[i],sv[sv[i].second]); // on ith pos, on pos of ith.second
			i--; // check again replaced one
		}
	}
	return count;
}
int minSwap(vector<int> tree,int n){
	vector<int> in;
	inFromPre(tree,n,0,in);
	return minSwapToSortArr(in,n);
}

// Convert to Mirror Tree

void Mirror(Node* root,Node* &mirror){
	if(root==NULL) {
		mirror=NULL;
		return;
	}
	mirror=new Node(root->data);
	Mirror(root->left,mirror->right);
	Mirror(root->right,mirror->left);
}

// find LargestSum SubTree
int sums(Node* root,vector<int> &v){
	if(!root) return 0;
	int sum=root->data;
	sum+=sums(root->left,v);
	sum+=sums(root->right,v);
	v.push_back(sum);
	return sum;
}
int largestSumSubtree(Node* root){
	vector<int> v;
	sums(root,v);
	print_vec(v);
	sort(v.begin(),v.end());
	return *max_element(v.begin(),v.end());
}
// largest sum of node (not adjacent ones)
unordered_map<Node*,int> dp; // DP memoization
int getMaxSumFromNodes(Node* root){    //          O(n)
	// simple inclue or exclude then --> max of both
	if(root==NULL) return 0;
	if(dp[root]) return dp[root];

	int inc=root->data;
	if(root->left){
		inc+=getMaxSumFromNodes(root->left->left);
		inc+=getMaxSumFromNodes(root->left->right);
	}
	if(root->right){
		inc+=getMaxSumFromNodes(root->right->left);
		inc+=getMaxSumFromNodes(root->right->right);
	}

	int exc=getMaxSumFromNodes(root->left) + getMaxSumFromNodes(root->right);

	dp[root]=max(inc,exc);
	return dp[root];
}

// print all k sum paths 
void printPath(Node* root,vector<int> &path,int k){
	if(!root) return;
	path.push_back(root->data);
	printPath(root->left,path,k);
	printPath(root->right,path,k);
	int sum=0;
	for(int i=path.size()-1;i>=0;i--){
		sum+=path[i];
		if(sum==k){
			for(int j=i;j<path.size();j++)
				cout<<path[j]<<" ";
			cout<<endl;
		}
	}
	path.pop_back();

}
void KsumPaths(Node* root,int k){
	vector<int> path;
	printPath(root,path,k);
}

// least comman ancestor
// if we send only one correct int then works as find()
Node* lca(Node* root,int a,int b){
 	if(root==NULL) return NULL;
 	if(root->data==a or root->data==b) return root;

 	Node* x=lca(root->left,a,b);
 	Node* y=lca(root->right,a,b);
 	if(x and y) return root;
 	if(x) return x;
 	if(y) return y;
 	return NULL;
}

// kth ansecstor 
Node* findParent(Node* root,Node* child){
	if(root==NULL) return NULL;
	if(root->left==child or root->right==child) return root;
	Node* x=findParent(root->left,child);
	Node* y=findParent(root->right,child);
	if(x) return x;
	if(y) return y;
	return NULL;
}
Node* find(Node* root,int k){
	if(root==NULL) return NULL;
	if(root->data==k) return root;
	Node* x= find(root->left,k);
	Node* y=find(root->right,k);
	if(x) return x;
	if(y) return y;
	return NULL;
}
void kthAncestor(Node* root,int k,int value){
	Node* t=find(root,value);
	while(k--){
		t=findParent(root,t);
	}
	if(t==NULL) print(-1);
	else print(t->data);
}

// print all duplicate subtrees
unordered_map<string,int> subtree;
string sub(Node* root){
    if(root==NULL) return "";
    string s=sub(root->left); 
    s+=to_string(root->data);
    s+=sub(root->right);
    subtree[s]++;
    if(subtree[s]>1 and subtree[s]<3) allOrder(root);
    return s;
}
void allDuplicate(Node* root){
	sub(root);
}
////////////////////////  BST ////////////////////////////////

// searching in BST
Node* search(Node* root ,int key){
	if(root==NULL) return NULL;
	if(root->data==key) return root;
	else if(root->data>key) return search(root->left,key);
	else return search(root->right,key);
}
// delete node
void deleteLeaf(Node* &root,int k){
	if(root==NULL) return;
	if(root->data==k) root=NULL;
	else if(root->data>k)  deleteLeaf(root->left,k);
	else  deleteLeaf(root->right,k);
}
void deleteSingleChild(Node* root,int k){
	if(root==NULL) return;
	if(root->left and root->left->data==k){
		root->left=(root->left->left)?root->left->left:root->left->right;
		return;
	}
	if(root->right and root->right->data==k){
		root->right=(root->right->right)?root->right->right:root->right->left;
		return;
	}
	if(root->data>k) deleteSingleChild(root->left,k);
	else deleteSingleChild(root->right,k);
}
void delBothChild(Node* root,int k){
	if(root==NULL) return;
	print(root->data);
	if(root->left and root->left->data==k){
		Node* l=root->left->left;
		root->left=root->left->right;
		Node* t=root->left;
		while(t->left){
			t=t->left;
		}
		t->left=l;
		return;
	}
	if(root->right and root->right->data==k){
		Node* l=root->right->left;
		root->right=root->right->right;
		Node* t=root->right;
		while(t->left){
			t=t->left;
		}
		t->left=l;
		return;
	}
	if(root->data>k) delBothChild(root->left,k);
	else delBothChild(root->right,k);
}
void deleteNode(Node* root,int k){
	Node* t=find(root,k);
	if(t->left and t->right) delBothChild(root,k);
	else if(!t->left and !t->right) deleteLeaf(root,k);
	else deleteSingleChild(root,k);
}
//  find Inorder Predecessor and Successor of a node
Node* InPre(Node* root){ //one left -> extreme right
	root= root->left;
	while(root->right) root=root->right;
	return root;
}
Node* InSuc(Node* root){ // ont right -> extreme left
	root=root->right;
	while(root->left) root=root->left;
	return root;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int k)
{
    if(root==NULL) return;
    if(root->data==k){ // not leaf node
    	if(root->left) pre=InPre(root);
    	if(root->right) suc=InSuc(root);
    	return ;
    }
    if(root->data<k){
    	pre=root;
    	findPreSuc(root->right,pre,suc,k);
    }
    else if(root->data>k){
    	suc=root;
    	findPreSuc(root->left,pre,suc,k);
    }  
}

/// convert Normal BST -> Balanced BST
void fill(Node* root,vector<Node*> &v){
	if(!root) return;
	fill(root->left,v);
	v.push_back(root);
	fill(root->right,v);
}
static bool cmp(Node* a,Node* b){
	return a->data<b->data;
}
Node* makeTreeFromINORDER(vector<Node*> v,int l,int r){
	if(l>r) return NULL;
	int mid=(l+r)/2;
	v[mid]->left=makeTreeFromINORDER(v,l,mid-1);
	v[mid]->right=makeTreeFromINORDER(v,mid+1,r);
	return v[mid];
}
Node* Convert(Node* root){
	vector<Node*> v;
	fill(root,v);
	sort(v.begin(),v.end(),cmp);
	int l=0;
	int r=v.size()-1;
	return makeTreeFromINORDER(v,l,r);
}
// Merge 2 BST
Node* merge(Node* a,Node* b){
	vector<Node*> v;
	fill(a,v);
	fill(b,v);
	sort(v.begin(),v.end(),cmp);
	return makeTreeFromINORDER(v,0,v.size()-1);
}
// kth largest Element in BST
int kthLargest(Node* root,int k){
	if(root==NULL) return 0;
	if(root->right) return kthLargest(root->right,k);
	return kthLargest(root->left,k);
	return 0;
}

// median of BST in O(n) time and O(1) space
int len(Node* root){
	if(root==NULL) return 0;
	return 1+len(root->left)+len(root->right);
} 
int x=0;
void forOdd(Node* root,int n,int &ans){
	if(root==NULL) return;
	forOdd(root->left,n,ans);
	x++;
	if(x==(n+1)/2) {ans = root->data; return;}
	forOdd(root->right,n,ans);
}
void forEven(Node* root,int n,int &sum){
	if(root==NULL) return;
	forEven(root->left,n,sum);
	x++;
	if(x==n/2) {sum+=root->data; }
	if(x==(n+2)/2){sum+=root->data; return;}
	forEven(root->right,n,sum);
}
int median(Node* root){
	int n=0,ans=0;
	n=len(root);
	if(n%2==0){
		forEven(root,n,ans);
		ans/=2;
	}
	else {
		forOdd(root,n,ans);
	}
	return ans;
}
// replace with Least Greater to Right ( LGR ) 
vector<int> LGR(vector<int> v,int n){
	Node* root=NULL;
	vector<int> a(n,-1); 
	for(int i=n-1;i>=0;i--){
		Node *suc=NULL,*pre=NULL;
		root=Insert(root,v[i]);
		findPreSuc(root,pre,suc,v[i]);
		a[i]=suc?suc->data:-1;
	}
	return a;
}
// find all conflicting intervels {start, end}
// create interval tree ; 
void findConflictingIntervels(vector<pair<int,int>> v,int n){
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			int s1=v[j].first;
			int s2=v[i].first;
			int e1=v[j].second;
			int e2=v[i].second;
			if(s1<e2 and s2<e1) print(s2,e2,"Conflicts with",s1,e1);
		}
	}
}

// find if tree has dead End 
void fillLeaf(Node* root,vector<int> &v){
	if(root==NULL) return;
	fillLeaf(root->left,v);
	if(root->left==NULL and root->right==NULL) v.push_back(root->data);
	fillLeaf(root->right,v);
}
bool isDeadEnd(Node* root){
	vector<int> v;
	fillLeaf(root,v);
	for(auto x:v){
		Node* pre=NULL,*suc=NULL;
		findPreSuc(root,pre,suc,x);
		if(pre and suc){
			if(x-1==pre->data and suc->data==x+1) return 1;
		}
		else if(x==1 and suc->data==2)return 1;
	}
	return 0;
}
////////////////////////////////////////////////////



//////////////////////////

void solve(){
	Node* root=NULL;
	root=get_Nodes(root);
	allOrder(root);
	cout<<endl;
}
