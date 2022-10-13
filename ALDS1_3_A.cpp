#include<bits/stdc++.h>
using namespace std;

int top = 0;
int S[110];

void push(int x){
    S[top] = x;
    top++;
}

int pop(){
    top--;
    return S[top];
}

int main() {
    string str;
    
    while (cin >> str){
        if(str == "+") {
            int a = pop();
            int b = pop();
            push(a + b);
        } else if(str == "-"){
            int a = pop();
            int b = pop();
            push(b - a);
        }else if(str == "*"){
            int a = pop();
            int b = pop();
            push(a * b);
        } else {
            int a = atoi(str.c_str());
            push(a);
        }
    }
    int sum = pop();

    cout << sum << endl;

    return 0;
}