#include <iostream>
#include <vector>

using namespace std;

int BubbleSort(int A[], int N){
    bool flag = true;
    int count = 0;
    while(flag){
        flag = false;
        for(int j = N - 1; j > 0; j--){
            if(A[j] < A[j - 1]){
                swap(A[j], A[j - 1]);
                flag = true;
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;

    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];

    int ans = BubbleSort(A, N);

    for(int i = 0; i < N; i++){
            if(i > 0) cout << " ";
            cout << A[i];
    }

    cout << endl;

    cout << ans << endl;
    return 0;
    
}