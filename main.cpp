#include <fstream>
#include <stack>
using namespace std;

int make(int a, int b, char c){
    switch (c){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        default: return 0;
    }
}

int main() {
    ifstream cin("postfix.in");
    ofstream cout("postfix.out");
    int a,b;
    char c;
    stack <int> s;
    while(cin >> c){
        if (c!=' '){
            if (c >= '0' and c<='9'){
                s.push(c - '0');
            }
            else {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(make(b,a,c));
            }
        }
    }
    cout << s.top();
    return 0;
}