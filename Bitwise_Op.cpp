#include<bits/stdc++.h>
using namespace std;

//////////////////   TEMPLATE START ///////////////////////

#define ll long long int
#define F first
#define S second
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
vector<int> get_vector(int n){
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	return v;
}

//////////////////////  TEMPLATE END /////////////////////////////////


				  // Rshift ,  Lshift ,  OR  ,   AND , (1's Compliment) , XOR

// BITWISE OPERATORS:   >>  ,    <<   ,  (|)  ,   (&)  ,      (~)       , (^) 


// pos  3 2 1 0
// n=5  0 1 0 1
// n=7  0 1 1 1


int getBit(int n,int pos){
	return (n & (1<<pos))!=0;   // (n=5) 0101 ,(pos=2) return (0101 & 0100) == 1;
}

int setBit(int n,int pos){
	return (n | (1<<pos));  // (n=5) 0101, (pos=1) return (0101 | 0010) ==0111; (n=7)
}

int ClearBit(int n,int pos){  // n=5, pos=2
	int mask = ~(1<<pos);     // ~(0100) = 1011
	return (n & mask);		  // 0101 & 1011 = 0001 
}

int UpdateBit(int n,int pos,int value){   // n=5, pos=1, value=1
	int mask = ~(1<<pos);				  // 1101
	n = n & mask;						  // 0101 & 1101 = 0101
	return (n | (value<<pos));			  // 0101 | 0010 = 0111 (7)
}

//////////////////////////


void recu(char ip[]){
	// cout<<ip[0];
	recu(ip+1);
	if(ip[0]=='\0') return;
	// if(ip[2]!='\0'&&ip[1]!='\0'&&ip[0]=='p'&&ip[1]=='i'){
	// 	ip[0]='3';ip[1]='.';
	// 	shift(ip+2);
	// 	shift(ip+3);
	// 	char x=ip[2],y=ip[3];
	// 	char* a= shift(ip+2);
	// 	for(int i=0;*(a+i)!='\0';i++){
	// 		cout<<*(a+i);
	// 	}
	// 	// ip[2]='1';ip[3]='4';

	// 	recu(ip+4);
	// }
	// else{
	// 	recu(ip+1);
	// }
}


int main(){
	// int n=5;
	// for(int i=0;i<4;i++){
	// 	print(getBit(n,i));
	// }
	// print(UpdateBit(n,1,1));
	// print(setBit(n,1));

	cout<<"hello"<<endl;

	char ip[50]= {'x','p','i','x','y','z'};
	recu(ip);
	for(int i=0;ip[i]!='\0';i++){
		cout<<ip[i];
	}
	cout<<endl;
	return 0;
}