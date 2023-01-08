#include <bits/stdc++.h>
using namespace std;
#define LEN 100010

// 初期化
vector<pair<string, int> > q(LEN);
int head, tail = 0; 

void enqueue(pair<string, int> p){
    if(head == (tail + 1) % LEN) return;
    q.at(tail) = p;
    tail = (tail + 1) % LEN;
}

pair<string, int> dequeue(){
    if(head  == tail) return pair<string, int>("error", 0);
    pair<string, int> x = q.at(head);
    head = (head + 1) % LEN;
    return x;
}


int main() {
    int n = 0, q = 0;
    cin >> n >> q;

    for(int i = 0; i < n; i++){
       string name;
       int time;
       cin >> name >> time;
       enqueue(make_pair(name, time)); 
    } 

    int sumTime = 0;
    while(head != tail){
        pair<string, int> u = dequeue();
        if(u.second <= q){
            sumTime += u.second;
            cout << u.first << " " << sumTime << endl;
        } else {
            sumTime += q;
            enqueue(make_pair(u.first, u.second - q));
        }
    }
}