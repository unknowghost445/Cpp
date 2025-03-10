#include <bits/stdc++.h>
using namespace std;
#define ll long long

const string tt{"test\n"};
const string sp{" "};
vector<string>factorial;

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
    //reverse(arr, arr+A+B);
    int n=A+B+1;
    while(arr[n]==0){--n; }//cout <<n<<tt;}
    //cout << arr[0];
    for(int i{0}; i<=n; ++i){
        s =  (char)(arr[i]+'0') + s;
        //cout << tt;
    }
    return s;
}
void create(){
    factorial.push_back("1");
    for(int i{1}; i<=1000; ++i){
        string tmp;
        tmp = BigMul(factorial[i-1],to_string(i));
        factorial.push_back(tmp);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    create();
    int n;
    cin >> n;
    int tmp;
    for(int i{0}; i<n; ++i){
        cin >> tmp;
        cout << factorial[tmp] << endl;
    }
    return 0;
}
