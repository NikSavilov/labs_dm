#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream cin("stack.in");
    ofstream cout("stack.out");
    int n;
    cin >> n;
    vector <int> stack;
    string z;
    int m;
    for (int i = 0; i < n; ++i){
        cin >> z;
        if (z == "+"){
            cin >> m;
            stack.push_back(m);
        }
        else if (z == "-"){
            cout << stack[stack.size()-1] << endl;
            stack.pop_back();
        }
    }


    return 0;
}