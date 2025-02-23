#include<bits/stdc++.h>

using namespace std;
const string tt = "Test\n";

void merge_part(vector<int> &a, int l, int m, int r){
    vector<int> tmp;
    int i{l}, j{m + 1};

    while(i <= m && j <= r){
        if(a[i]<a[j]) tmp.push_back(a[i++]);
        else tmp.push_back(a[j++]);
    }

    while(i <= m) tmp.push_back(a[i++]);
    while(j <= r) tmp.push_back(a[j++]);

    for(int m{0}; m < tmp.size(); ++m){
        a[l + m] = tmp[m];
    }
}

void merge_sort(vector<int> &a, int l, int r){
    if( l >= r ) return ;
    int m = (l + r) / 2;

    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);

    merge_part(a, l, m, r);
}

int main(){

    vector<int> a;
    int n;  cin >> n;

    for(int i{0}; i < n; ++i){
        int tmp;    cin >> tmp;
        a.push_back(tmp);
    }

    merge_sort(a, 0, n-1);

    for(int i{0}; i < n; ++i){
        cout << a[i] << ' ';
    }

    return 0;
}
