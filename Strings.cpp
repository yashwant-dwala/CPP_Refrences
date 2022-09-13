#include <bits/stdc++.h>
#include "Template.cpp"
using namespace std;


void kmp_Rabincarp(string t,string p){
    vector<int> arr(p.size(),0); // prefix - suffix

    int i=0,j=1;
    while(j<p.size()){
        if(p[i]==p[j]){
            arr[j] = i+1;
            i++; j++;
        }
        else if(i==0) {
            arr[j] = 0;
            i++; j++;
        }
        else if(p[i]!=p[j]){
            i = arr[--i];
        }
    }
    print("prefix - suffix array : ");
    print_vec(arr);

    // Matching
    i = 0, j = 0;

    int k =0; // start-index
    while(i<t.size()){
        if(t[i]==p[j]){
            i++; j++;
        }
        else if(j==0) {
            i++;
            k = i;
        }
        else if(t[i]!=p[j]){
            j = arr[--j];
            k = i-j;
        }
        if(j==p.size()){
            print("found",k);
            j=0;
        }
    }
    print("not Found");
}


void Solve(){
    string text = "abcfabcabygxahcbcabcabycabghabcaby", patt = "abcaby";
    kmp_Rabincarp(text,patt);    
}