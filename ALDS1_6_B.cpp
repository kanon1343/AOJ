#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int A[MAX];

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(A[j] <= x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

int main(void){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int par = partition(A, 0, n-1);
    
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        if(par == i) cout << "[";
        cout << A[i];
        if(par == i) cout << "]";
    }
    cout << endl;
}
