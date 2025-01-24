#include <iostream>

using namespace std;

void inputArray(float a[][300], int &m, int &n){
    cin >> m >> n;
    for (int i{0}; i<m; ++i){
        for (int j{0}; j<n; ++j){
            cin >> a[i][j];
        }
    }
}
void outputArray(float a[][300], int m, int n){
    for (int i{0}; i<m; ++i){
        for (int j{0}; j<n; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m,n,i,k;
    float a[300][300];
    float b[300][300];
    float c[300][300];
    inputArray(a,m,n);
    inputArray(b,i,k);
    for (int i{0}; i<m; ++i){
        for (int j{0}; j<k; ++j){
            c[i][j]=0;
            for (int h{0}; h<n; ++h){
                c[i][j]+= a[i][h]*b[h][j];
            }
        }
    }
    outputArray(c,m,k);
}
