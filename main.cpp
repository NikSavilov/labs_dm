#include <fstream>
#include <stack>
using namespace std;

void clean(stack<char> &s) {
    while (!s.empty())
        s.pop();
}

bool sovp(char c, char h) {
    if (c == ')')
        return h == '(';
    return h == '[';
}

int main() {
    ifstream cin("brackets.in");
    ofstream cout("brackets.out");
    string str;
    stack<char> s;
    while (cin >> str) {
        clean(s);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
            } else if (sovp(str[i], (!s.empty()) ? s.top() : str[i] )) {
                s.pop();
            } else {
                s.push(str[i]);
                break;
            }
        }
        if (s.size() == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}