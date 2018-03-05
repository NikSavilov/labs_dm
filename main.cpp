#include <iostream>
#include <fstream>
#include <vector>

#define VEC vector
#define PB push_back

using namespace std;

void mergeSort(VEC <int> &a, int L, int R, long long &ans) {
    if (R - L < 2) return;
    mergeSort(a, L, L + (R - L) / 2, ans);
    mergeSort(a, L + (R - L) / 2, R, ans);
    VEC <int> tmp;
    int Lf = L, Rf = L + (R - L) / 2;
    int Ls = Rf, Rs = R;
    while (tmp.size() < R - L) {
        if (Lf >= Rf || (a[Ls] < a[Lf] && Ls < R)) {
            tmp.PB(a[Ls]);
            Ls++;
            ans += L + (R - L) / 2 - Lf;
        } else {
            tmp.PB(a[Lf]);
            Lf++;
        }
    }
    for (int i = L; i < R; ++i) {
        a[i] = tmp[i - L];
    }
}

int main() {
    int n;
    long long ans = 0;

    ifstream cin("inversions.in");
    ofstream cout("inversions.out");

    cin >> n;
    if (n == 0 || n == 1) {
        cout << 0;
        return 0;
    }
    VEC <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    mergeSort(a, 0, a.size(), ans);
    cout << ans;
    return 0;
}