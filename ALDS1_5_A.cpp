#include <bits/stdc++.h>
using namespace std;

vector<int> A;

bool solve(int i, int m, int n) {
    if(i == n){
        if(m == 0){
            return true;
        } else {
            return false;
        }
    }
    if(solve(i+1, m, n)) return true; 
    if(solve(i+1, m - A[i], n)) return true;
    return false;
}

int main(void){
    int n;
    scanf("%d", &n);
    A.resize(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    int q;
    scanf("%d", &q);
    int m;
    for(int i = 0; i < q; i++){
        scanf("%d", &m);
        if(solve(0, m, n)){
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;    
}