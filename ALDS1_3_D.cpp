#include <bits/stdc++.h>
using namespace std;

int main(void){
    stack<int> S1;
    stack<pair<int, int> > S2;
    
    char input; //入力
    int sum = 0; //合計
    
    for(int i = 0; cin >> input; i++){
        if(input == '\\'){
            S1.push(i);
        } else if(input == '/' && S1.size() > 0){
            int index = S1.top();
            S1.pop();
            int sub = i - index; // できた水たまりのかけら
            sum += sub;
            
            int s = sub; // 水たまり結合用
            while(S2.size() > 0 && S2.top().first > index){
                s += S2.top().second;
                S2.pop();
            }
            S2.push(make_pair(index, s));
        }
    }
    
    vector<int> ans;
    cout << sum << endl;
    cout << S2.size();
    
    while(S2.size() > 0){
        ans.push_back(S2.top().second);
        S2.pop();
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}
