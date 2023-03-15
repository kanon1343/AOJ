#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define SENTINEL 2000000000

struct Card {
    char suit;
    int value;
};

struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(struct Card A[], int n, int left, int mid, int right) {
    int leftSide = mid - left;
    int rightSide = right - mid;
    for(int i = 0; i < leftSide; i++) L[i] = A[left+i];
    for(int i = 0; i < rightSide; i++) R[i] = A[mid+i];
    L[leftSide].value = R[rightSide].value = SENTINEL;
    int i= 0, j = 0;
    for(int k = left; k < right; k++){
        if(L[i].value <= R[j].value){
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(struct Card A[], int n, int left, int right) {
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int partition(struct Card B[], int p, int r) {
    struct Card x; 
    x = B[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(B[j].value <= x.value){
            i++;
            swap(B[i], B[j]);
        }
    }
    swap(B[i+1], B[r]);
    return i+1;
}

void quickSort(struct Card B[], int p, int r) {
    if(p < r){
        int i = partition(B, p, r);
        quickSort(B, p, i-1);
        quickSort(B, i+1, r);
    }
}

int main(void){
    struct Card A[MAX], B[MAX];
    int n, v;
    cin >> n;
    
    char S;
    for(int i = 0; i < n; i++){
        cin >> S >> v;
        A[i].suit = B[i].suit = S;
        A[i].value = B[i].value = v;
    }
    
    mergeSort(A, n, 0, n);
    quickSort(B, 0, n-1);
    
    bool Flag = true;
    for(int i = 0; i < n; i++){
        if(A[i].suit != B[i].suit){
            Flag = false;
        }
    }
    if(Flag) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    for(int i = 0; i < n; i++){
        cout << B[i].suit << " " << B[i].value << endl;
    }
    return 0;
}
