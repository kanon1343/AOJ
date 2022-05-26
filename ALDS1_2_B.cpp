#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int SelectionSort(int A[], int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[minj] > A[j]) minj = j;
        }
        if(i != minj){
            swap(A[i], A[minj]);
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;

    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];

    int ans = SelectionSort(A, N);

    for(int i = 0; i < N; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}