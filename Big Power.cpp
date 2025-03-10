#include <bits/stdc++.h>

using namespace std;
#define ll long long

const string tt{"test\n"};
const string sp{" "};

string BigMul(string a, string b){

    string s="\0";

    if(b.size()>a.size()) swap(a,b);

    int A = a.size(), B = b.size();

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int arr[A+B+1];

    for(int i{0}; i<=A+B+1; ++i){
        arr[i]=0;
    }

    for(int i{0}; i<B; ++i){
        for(int j{0}; j<A; ++j){
            arr[j+i] += ((a[j]-'0')*(b[i]-'0'));
            arr[i+j+1] += (arr[i+j]/10);
            arr[i+j]%=10;
        }
    }

    int n=A+B+1;

    while(arr[n]==0){--n; }
    for(int i{0}; i<=n; ++i){
        s =  (char)(arr[i]+'0') + s;
    }

    return s;
}

string power(string a, int b){

    if(b==1) return a;

    string tmp = a;
    string mul = BigMul(a,a);

    if(b&1) return BigMul(power(mul,b/2),tmp);
    return power(mul,b/2);

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    int b;
    cin >> a >> b;
    cout << power(a,b);

    return 0;
}
