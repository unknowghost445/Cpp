#include <bits/stdc++.h>
using namespace std;

int prime[200002];

void sang(){
    prime[0]=prime[1]=0;
    for(int i{2}; i<=200000; ++i){
        prime[i]=1;
    }
    for(int i{2}; i<=447; ++i){
        if(prime[i]){
            for(int j{i*i}; j<=200000; j+=i){
                prime[j]=0;
            }
        }
    }
}

int main(){
    sang();
    int a,b;
    cin >> a >> b;
    for(int i{a}; i<=b; ++i){
        if(prime[i]) cout << i << endl;
    }
}
