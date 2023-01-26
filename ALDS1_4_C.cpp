#include <bits/stdc++.h>
using namespace std;
#define M 1046527
#define NIL (-1)
#define L 14

vector<string> H(M);

// 文字から数値に変換
int getChar(char ch){
    switch(ch){
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return 0;  
    }
}

// 文字列から数値へ変換してkeyを作成
long long getKey(string str) {
    long long sum = 0, p = 1, i;
    for(i = 0; i < str.length(); i++){
        sum += p * (getChar(str[i]));
        p *= 5;
    }
    return sum;
}

int h1(int key) {
    return key % M;
}

int h2(int key) {
    return 1 + (key % (M - 1));
}

int insert(string str) {
    long long key, i, h;
    key = getKey(str);
    for(i = 0;;i++){
        h = (h1(key) + i * h2(key)) % M;
        if(str == H[h]) return 1;
        else if(H[h] == "") {
            H.at(h) = str;
            return 0;
        }
    }
    return 0;
}


int find(string str) {
    long long key, i, h;
    key = getKey(str);
    for(i = 0;; i++){
        h = (h1(key) + i * h2(key)) % M;
        if(str == H[h]) return 1;
        else if(H[h] == "") return 0;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    string com, str;
    for(int i = 0; i < n; i++){
        cin >> com >> str;
        
        if(com[0] == 'i'){
            insert(str);
        } else {
            if(find(str)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}