#include <bits/stdc++.h>

using namespace std;
int main(void){
    int n;
   
    cin >> n;
    
    vector<int> R(n);
    for(int i = 0; i < n; i++){
        cin >> R.at(i);
    }
    
    int maxv = R.at(1) - R.at(0);
    int minv = R.at(0);
    
    for(int i = 1; i < n; i++){
        if(maxv < R.at(i) - minv){
            maxv = R.at(i) - minv;
        } else if(minv > R.at(i)){
            minv = R.at(i);
        }
    }
    
    cout << maxv << endl;
}