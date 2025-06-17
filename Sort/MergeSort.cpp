#pragma once
#include <bits/stdc++.h>
using namespace std;

void MergePart(vector<int>& arr, int l, int m, int r){
    vector<int> tmp;
    int i = l, j = m + 1;

    while(i <= m && j <= r){
        if(arr[i] < arr[j]){
            tmp.push_back(arr[i++]);
        }else{
            tmp.push_back(arr[j++]);
        }
    }

    while(i <= m){
        tmp.push_back(arr[i++]);
    }
    while(j <= r){
        tmp.push_back(arr[j++]);
    }

    for(int h = 0; h < tmp.size(); ++h){
        arr[h + l] = tmp[h];
    }
}

void MergetSort(vector<int>& arr, int l, int r){
    if(r <= l){
        return ;
    }

    int m = l + (r - l) / 2; 

    MergetSort(arr, l, m);
    MergetSort(arr, m + 1, r);

    MergePart(arr, l, m, r);

}
