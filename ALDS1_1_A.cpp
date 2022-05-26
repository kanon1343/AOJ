#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(int A[], int N){
    for(int i = 0; i < N; i++){
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        for(int k = 0; k < N; k++){
            if(k > 0) cout << " ";
            cout << A[k];
        }
        cout << endl;
    }   
}


int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];

    InsertionSort(A, N);

    return 0;
}