#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int cnt = 0;

void insertionSort(int *A, int n, int g){
    for(int i=g; i<n; ++i){
        int v = A[i];
        int j = i-g;
        while ((j >= 0) && (A[j] > v)){
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int* A, int n){
    cnt = 0;
    int m = 1;
    vector<int> G;
    G.push_back(1);
    while(3*G[m-1]+1 <= n){
        G.push_back(3*G[m-1]+1);
        m++;
    }

    cout << m << endl;
    for(int i=G.size()-1;i>=0; --i){
        cout << G[i];
        if (i != 0){
            cout << " ";
        }
    }
    cout << endl;

    for(int i = G.size()-1; i >= 0; --i){
        insertionSort(A, n, G[i]);
    }
}

int main(void){
    int n;
    cin >> n;
    int *A = new int[n];
    for(int i=0; i<n; ++i){
        cin >> A[i];
    }
    shellSort(A, n);
    cout << cnt << endl;
    for(int i=0; i<n; ++i){
        cout << A[i] << endl;
    }

    return 0;
}