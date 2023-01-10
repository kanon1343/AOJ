#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int key, int S[], int n) {
    int left = 0;
    int right = n;
    int mid = n / 2;
    while(left < right){
        mid = (left + right) / 2;
        if(S[mid] == key){
            return true;
        } else if(S[mid] > key){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main(void){
    int n;
    cin >> n;
    int S[n];
    for(int i = 0; i < n; i++){
        cin >> S[i];
    }
    
    int q;
    cin >> q;
    int T;
    int ans = 0;
    for(int i = 0; i < q; i++){
        cin >> T;
        if(binarySearch(T, S, n)) ans++;
    }
    cout << ans << endl;
}
