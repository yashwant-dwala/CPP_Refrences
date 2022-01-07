#include<bits/stdc++.h>
using namespace std;

/////////////////////  Linked list Boiler ////////////////////////

struct Node {
	int data;
	Node* next;
	Node(int data){
		this->data=data;
		next =NULL;
	}
};
struct linkedList{
	struct Node* head=NULL;
	linkedList() {head=NULL;}
	void reverse(){
		Node* start = head;
		Node* left=NULL;
		Node* right;
		while(start!=NULL){
			right=start->next;
			start->next=left;
			left=start;
			start=right;
			
		}
		head=left;
	}
	void push(int data){
		// in front 
		Node* temp=new Node(data);
		temp->next =head;
		head=temp;
	}
	void pop(){

	}
	void display(){
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}

};
///////////////////////////////////////////

//////////////////   TEMPLATE START ///////////////////////

#define ll long long int

const int N=1e7+10; // 10^7
ll arr[N];
#define rep(i,Start,End) for(int i=Start;i<End;i++)

void print(){
	cout<<endl;
}
template <typename T,typename... Types>
void print(T var1,Types... var2){
	cout<<var1<<" ";
	print(var2...);
}
void print_vec(vector<int> a){
	for(auto i:a){
		cout<<i<<" ";
	}
	cout<<endl;
}
// recursive print
void recDisplay(Node* head){
	Node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	delete temp;
}
// recursive reverse
Node* recReverse(Node* head){
	if(head==NULL or head->next==NULL) return head;
	
	Node* rest=recReverse(head->next);
	head->next->next=head;
	head->next=NULL;

	return rest;

}
Node* get_Nodes(linkedList l){
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		l.push(x);
	}
	l.head=recReverse(l.head);
	return l.head;
}
Node* makeCircular(Node* head){
	Node* t=head;
	while(t->next){
		t=t->next;
	}
	t->next=head;
	return head;
}
//////////////////////  TEMPLATE END /////////////////////////////////


// k-elements reversed at a time 
Node* Kreverse (Node* head, int k)
{ 
    Node* left=NULL;
    Node* right;
    Node* start=head;
    int i=1;
    while(i<=k && start!=NULL){
    	i++;
    	right=start->next;
    	start->next=left;
    	left=start;
    	start=right;
    }
    if(right!=NULL)  // head will always point to starting ele for every call
    	head->next=Kreverse(right,k);

    return left;
}
Node* removeDuplictes(Node* head){
	Node *curr=head;
	if(head==NULL) return head;
	while(curr->next!=NULL){
		if(curr->data==curr->next->data){
			curr->next=curr->next->next;
		}
		else curr=curr->next;
	}
	return head;
}
//keeps only first occurences
Node* removeDuplictes_Unsorted2(Node* head){
	Node* st=head;
	unordered_map<int,int> u;
	while(st->next){
		u[st->data]++;
		if(u[st->next->data]>=1){
			st->next=st->next->next;								
		}
		else {
			st=st->next;
		} 
	}
	return head;
}
// loop detection
bool detectLoop(Node* head)
{
    Node* x=head;
    Node* y=head;
    while(y!=NULL&&y->next!=NULL){
        x=x->next;
        y=y->next->next;
        if(y==x) return 1;
    }
    return 0;
}

// loop remove
void deleteLoop(Node* head){
	Node* x=head;
    Node* y=head;
    while(y!=NULL&&y->next!=NULL){
        x=x->next;
        y=y->next->next;
        if(y==x) {
        	x=head;
        	if(y!=x){
        		while(y->next!=x->next){
        			y=y->next;
        			x=x->next;
        		}	
        	}
        	else {
        		while(y->next!=x) y=y->next;
        	}
        	y->next=NULL;
        }
    }
}
// Move last to first 
Node* moveFirst(Node* head){
	Node *curr=head,*left;
	while(curr->next!=NULL){
		left=curr;
		curr=curr->next;
	}
	left->next=NULL;
	curr->next=head;
	head=curr;
	return head;
}
// Add 1 to a number represented as linked list
bool addCarry(Node* head){
	if(head==NULL) return true;
	if(addCarry(head->next)){
		if(head->data==9){
			head->data=0;
			return true;
		}
		else head->data++;
	}
	return false;
}
Node* addOne(Node *head) 
{ 
    if(addCarry(head)){
    	Node* temp=new Node(1);
    	temp->next=head;
    	head=temp;
    }
    return head; 
}

// add to lists node wise representing intgers
int addTwoEqualList(Node* a,Node* b){
	if(a==NULL) return 0;
	int c= addTwoEqualList(a->next,b->next);
	int ones= (a->data+b->data+c)%10;
	int tens=(a->data+b->data+c)/10;
	b->data=ones;
	return tens;
}
Node* addTwoLists( Node* first,  Node* second)
{
    int f=1,s=1;
    Node *F=first,*S=second;
    while(F->next!=NULL||S->next!=NULL){
        if(F->next){
            f++;
            F=F->next;
        }
        if(S->next){
            s++;   
            S=S->next;
        }
    }
    // 0 padding in shorter one
    if(f<s){
    	Node* st=new Node(0);
    	S=st;
    	Node* last;
    	while(s-f-1){
    		s--;
    		last =new Node(0);
    		S->next=last;
    		S=last;
    	}
    	S->next=first;
    	first=st;   
    }
    else{
    	Node* st=new Node(0);
    	F=st;
    	Node* last;
    	while(f-s-1){
    		f--;
    		last = new Node(0);
    		F->next=last;
    		F=last;
    	}
    	F->next=second;
    	second=st;
    }
    int ca = addTwoEqualList(first,second);
    if(ca!=0){
    	Node* st=new Node(ca);
	    st->next=second;
	    second=st;
    }
   return second;
}

// intersection list of two sorted lists
Node* findIntersectionList(Node* a, Node* b)
{
    Node* n=NULL;
    Node* prev=NULL;
    while(a&&b){
        if(a->data<b->data){
            a=a->next;
        }
        else if(a->data>b->data){
            b=b->next;
        }
        else{
            Node* temp=new Node(a->data);
            if(n==NULL){
                n=temp;
            }
            else{
                prev->next=temp;
            }
            prev=temp;
            a=a->next;
            b=b->next;
        }
    }
    return n;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* a, Node* b)
{
    // make loop
    Node* t=a;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=a;
    // loop detection
    Node *f=b;
    Node *s=b;
    Node *ans;
    while(s->next&&f->next){
        ans=s;
        s=s->next;
        f=f->next->next;
        if(f==s){
           s=b;
           if(s!=f){
           	while(f->next!=s->next){
           		f=f->next;
           		s=s->next;
           	}
           }
           else{
           	while(f->next!=s) f=f->next;
           }
           if(f->next==a) return -1;
           return f->next->data;
        }
    }
    return -1;
}

// make Y shape b/w two list;
void Y_shape(Node* a,Node* b){
	Node* temp = new Node(42);
	Node* x=a;
	while(x->next!=NULL){
		x=x->next;
	}
	x->next=temp;
	x=b;
	while(x->next!=NULL){
		x=x->next;
	}
	x->next=temp;
	// adding new value at end;
	temp=new Node(41);
	x=b;
	while(x->next!=NULL){
		x=x->next;
	}
	x->next=temp;
}

// merge sort
Node* merge(Node* a,Node *b){
	if(a==NULL) return b;
	if(b==NULL) return a;
	Node* result;
	if(a->data<b->data){
		result=a;
		result->next=merge(a->next,b);
	} 
	else{
		result=b;
		result->next=merge(a,b->next);
	}
	return result;
}
void split(Node* &a,Node* &b,Node* head){
	a=head;
	Node* s=head;
	Node* f=head->next;
	while(f!=NULL&&f->next!=NULL){
		s=s->next;
		f=f->next->next;
	}
	b=s->next;
	s->next=NULL;
	recDisplay(a);
	recDisplay(b);
}
void mergeSort(Node* &head){
	Node* h=head;
	Node* a;
	Node* b;
	if(head==NULL||head->next==NULL) return;
	split(a,b,h);
	mergeSort(b);
	mergeSort(a);
	head=merge(a,b);
}

// Quick sort
void partetion(Node* &l,Node* &r,Node* &head,int pivot){
	Node* lp=l;
	Node* rp=r;
	Node* p=head;
	pivot-=1;
	while(pivot--){
		p=p->next;
	}
	print("p ",p->data);
	Node* t=head;
	Node* prev;
	while(t!=NULL){
		print(t->data);
		if(t->data<=p->data&&t!=p){
			print("l ",t->data);
			prev=t;
			t=t->next;
			prev->next=NULL;
			lp=lp->next;
			lp->next=prev;
			
		}
		else{
			print("r ",t->data);
			prev=t;
			t=t->next;
			prev->next=NULL;
			rp=rp->next;
			rp->next=prev;
		}
		
	}
	lp=l;
	while(lp){
		lp=lp->next;
	}
	lp=p;
	p->next=NULL;
	lp->next=r;

	cout<<"left : "; recDisplay(l);
	cout<<"mid : "; recDisplay(p);
	cout<<"right : "; recDisplay(r);
}
void QuickSort(Node* &head){
	Node* a=new Node(-1);
	Node* b=new Node(-1);
	if(head==NULL||head->next==NULL) return;
	partetion(a,b,head,3);
	QuickSort(a);
	QuickSort(b);
}
// Delete ele from a Circular List.
Node* removeEleCircular(Node* head,int k){
	// 1 ele error
	if(head==NULL||(head->data==k&&head->next==NULL)) return NULL;
	if(head->data==k) return head->next;
	Node* curr=head,*left=head;
	while(curr->data!=k&&curr){
		left=curr;
		curr=curr->next;
	}
	left->next=curr->next;
	delete curr;
	return head;
}

// multiply 2 Nos as linked list
// large so return modulo 10^9 +7;
ll multiplyTwoListNumbers(Node* a,Node* b){
	Node* t=a;
	ll mod=1000000000+7;
	ll x=0,y=0;
	while(t){
		x= x*10 + t->data;
		t=t->next;
	}
	t=b;
	while(t){
		y= y*10 + t->data;
		t=t->next;
	}
	
	return (x*y)%mod;
}

// First non-repeating character in a stream
string FirstNonRepeating(Node* head){
	string s="";
	vector<int> v(26,0);
	Node* temp=head;
	list<int> l;
	while(temp){
		l.push_back(temp->data);
		v[temp->data]++;
		while(v[l.front()]!=1){
			l.pop_front();
		}
		l.empty()?s+='#':s+=to_string(l.front());
		temp=temp->next; 
	}
	return s;
}

//////////////////////////

int main(){
	linkedList l;
	linkedList L;
	l.head=get_Nodes(l);
	print(FirstNonRepeating(l.head));
	// l.display();
	return 0;
}