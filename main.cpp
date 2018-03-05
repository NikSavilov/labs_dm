#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream cin("antiqs.in");
    ofstream cout("antiqs.out");
    int n, m, A, B, C;
    cin >> n >> m >> A >> B >> C;
    vector <int> myvector(n);
    cin >> myvector[0];
    cin >> myvector[1];
    for (int i=2;i<n;i++){
        int tmp = A * myvector[i-2] + B * myvector[i-1] + C;
        myvector.push_back(tmp);
    }
    nth_element(myvector.begin(), myvector.begin() + m, myvector.end());

    return 0;
}