#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX], R[MAX];
int cnt;

void merge(vector<int> &s, int n, int left, int mid, int right) {
    int leftSide = mid - left;
    int rightSide = right - mid;
    for(int i = 0; i < leftSide; i++) L[i] = s[left+i];
    for(int i = 0; i < rightSide; i++) R[i] = s[mid+i];
    L[leftSide] = R[rightSide] = SENTINEL;
    int i= 0, j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(L[i] <= R[j]){
            s[k] = L[i++];
        } else {
            s[k] = R[j++];
        }
    }
}

void mergeSort(vector<int> &s, int n, int left, int right) {
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(s, n, left, mid);
        mergeSort(s, n, mid, right);
        merge(s, n, left, mid, right);
    }
}


int main(void){
    int n;
    cin >> n;
    vector<int> s(MAX);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    
    cnt = 0;
    mergeSort(s, n, 0, n);
    
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << s[i];
    }
    cout << endl;
    cout << cnt << endl;
    
    return 0;
}
