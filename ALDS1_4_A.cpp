#include <bits/stdc++.h>
using namespace std;

int search(int key, int S[], int n) {
    S[n] = key;
    int i = 0;
    while(S[i] != key){
        i++;
    }
    return i != n;
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
        if(search(T, S, n)) ans++;
    }
    cout << ans << endl;
}
