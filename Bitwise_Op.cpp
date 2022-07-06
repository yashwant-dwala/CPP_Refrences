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

//............Count Total Setbits in NUMBERS from 1 to N
int minPowerOf2TillN(long long N){
        int i=0;
        while(1<<i<=N) i++;
        return i-1;
}
int countBits(int A){
    if(A==0) return 0;
    int x=minPowerOf2TillN(A);
    long long bitsTillN=x*(1<<x-1);    // (2^(x-1))*x
    
    // if A=7 , x= 2 ,  bitsTillN = 0,1,2,3 == 4
    // bitsMoreInFront 4,5,6,7
    // 1 00 
    // 1 01      =>  7-4 +1 =3+1 =4
    // 1 10
    // 1 11
    long long bitsMoreInFront = A-(1<<x) +1;
    long long rest = countBits(A-(1<<x)); // 7-4 = 3
    return (bitsTillN+bitsMoreInFront+rest)%1000000007;
}

//////////////////////////


void Solve(){
	int n=15;
	// for(int i=0;i<4;i++){
	// 	print(getBit(n,i));
	// }
	// print(UpdateBit(n,1,1));
	// print(setBit(n,1));
	print(countBits(n));
}


// check, number(n) is power of 2 ?
// yes if n & (n-1) == 0   (4&3 --> 100 & 011)