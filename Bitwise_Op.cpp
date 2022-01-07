#include<bits/stdc++.h>
#include "Template.cpp"
using namespace std;

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


void solve(){
	int n=5;
	for(int i=0;i<4;i++){
		print(getBit(n,i));
	}
	print(UpdateBit(n,1,1));
	print(setBit(n,1));
}