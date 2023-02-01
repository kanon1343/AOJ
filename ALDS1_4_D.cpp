#include<bits/stdc++.h>
using namespace std;

long long n, k;
vector<int> w;

int check(long long p) {
    int i = 0;
    for(int j = 0; j < k; j++){
        long long s = 0;
        while(s + w[i] <= p){
            s += w[i];
            i++;
            if(i == n){
                return n;
            }
        }
    }
    return i;
}


int main() {
    cin >> n >> k;
    w.resize(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    
    long long left = 0, right = 100000 * 100000;
    long long mid = 0;
    while(right > left){
        mid = (left + right) / 2;
        long long v = check(mid);
        if(v == n){
            right = mid; 
        } else {
            left = mid + 1;
        }
    }

    cout << right << endl;
    return 0;
}

