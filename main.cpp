#include <fstream>
using namespace std;

int main() {
    ifstream cin("isheap.in");
    ofstream cout("isheap.out");
    int n, i = 0, flag = 0;
    cin >> n;
    int a[n];
    for (int o = 0; o < n; o++)
        cin >> a[o];
    while (i * 2 + 2 < n) {
        if (a[i] > a[i * 2 + 1] || a[i] > a[(i * 2 + 2 < n) ? i * 2 + 2: i * 2 + 1]) {
            flag = 1;
            break;
        }
        i++;
    }

    if (flag == 1) cout << "NO";
    else cout << "yes";
    return 0;
}