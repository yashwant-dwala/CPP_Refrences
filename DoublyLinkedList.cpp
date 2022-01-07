#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;

/////////////////////  Linked list Boiler ////////////////////////

struct Node {
	int data;
	Node* prev;
	Node* next;
	Node(int data){
		this->data=data;
		next =NULL;
		prev=NULL;
	}
};
struct DLL{
	struct Node* head=NULL;
	DLL() {head=NULL;}

	void push(int data){
		// in front 
		Node* temp=new Node(data);
		if(head==NULL) { 
			head=temp;
			return;
		}
		temp->next =head;
		head->prev=temp;
		head=temp;
	}
	void display(){
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	void reverse(){
		Node* curr=head->next;
		Node* left=head;
		Node* right=NULL;

		head->next=NULL;
		head->prev=curr;
		
		while(curr->next){
			right=curr->next;
			curr->next=left;
			curr->prev=right;
			left=curr;
			curr=right;
		}
		curr->next=left;
		curr->prev=NULL;
		head=curr;
	}
	void get_Nodes(){
		int n;
		cin>>n;
		while(n--){
			int x;
			cin>>x;
			push(x);
		}
		reverse();
	}
};
Node* Reverse(Node* head){
	Node* curr=head->next;
	Node* left=head;
	Node* right=NULL;

	head->next=NULL;
	head->prev=curr;
	
	while(curr->next){
		right=curr->next;
		curr->next=left;
		curr->prev=right;
		left=curr;
		curr=right;
	}
	curr->next=left;
	curr->prev=NULL;
	head=curr;
	return head;
}
void show(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
///////////////////////////////////////////

// Find triplet with sum = k, in doubly linked list
void findPairSum_K(Node* head,int k,Node* third, set<int> &s){
	Node *l=head,*r=head;
	while(r->next){
		r=r->next;
	}
	while(l!=r){
		int x=l->data+r->data;
		if(x==k&&l!=third&&r!=third) {
			if(!s.count(l->data)&&!s.count(r->data)&&!s.count(third->data))
				print(third->data,l->data,r->data);
			s.insert(l->data);
			s.insert(r->data);
			s.insert(third->data);
		}
		if(x>k){
			r=r->prev;
		}
		else{
			l=l->next;
		}
	}
}
void findTripletSum_K(Node* head,int k){
	Node* temp=head;
	set<int> s;
	while(temp){
		findPairSum_K(head,abs(k-temp->data),temp,s);
		temp=temp->next;
	}
}

// sort k sorted DLL (ele at most k away from their positions)
struct compare{
	bool operator()(Node* first,Node* second){
		return first->data>=second->data;
	}
};
void k_Sorted(Node* head,int k){ // error last case enter NULL first ele removed
	if(head==NULL) return;
	Node* newHead=NULL,*curr=head;
	priority_queue<Node*, vector<Node*>, compare> pq; // min heap (top small) syntax 
	int i=k+1;
	while(i--&&curr){
		pq.push(curr);
		curr=curr->next;
	}
	while(!pq.empty()){
		if(newHead==NULL){
			newHead=pq.top();
			newHead->prev=NULL;
			head=newHead;
		}
		else{
			newHead->next=pq.top();
			newHead->next->prev=newHead;
			newHead=newHead->next;
			newHead->next=NULL;
		}
		pq.pop();
		if(curr!=NULL){
			pq.push(curr);
			curr=curr->next;	
		}
	}
	newHead=NULL;
}
//  rotate N times anti-clock 

void rotate_N(Node* &head,int N){
	Node* t1=head,*t2=head;
	int n=0;
	Node* temp=head;
	while(temp){
		n++;
		temp=temp->next;
	}
	if(N==n) return;
	if(N>n) N-=n;
	while(abs(N--)){
		t1=t1->next;
	}
	t1->prev->next=NULL;
	t1->prev=NULL;
	head=t1;
	while(t1->next){
		t1=t1->next;
	}
	t1->next=t2;
	t2->prev=t1;
}

// Reverse a doubly linked list in groups of K size 

Node* K_reverse(Node* head , int k){
	if(head==NULL|| k==1) return head;
	Node* tend=head,*tstart=head;
	Node* thead=head;
	int i=k-1;
	while(i--&&tend->next){
		tend=tend->next;
	}
	if(tend->next==NULL) return Reverse(thead);
	tstart=tend->next;
	tend->next=NULL;
	tstart->prev=NULL;
	thead=Reverse(thead);
	tend=thead;
	while(tend->next) tend=tend->next;
	tend->next=tstart;
	tstart->prev=tend;
	show(thead);
	tend->next=K_reverse(tend->next,k);
	return thead;
}

//////////////////////////

void Solve(){
	DLL l;
	l.get_Nodes();
	k_Sorted(l.head,3);
	l.display();
}