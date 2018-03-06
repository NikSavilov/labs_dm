#include <iostream>
#include <fstream>
#include <vector>

#define VEC vector
#define PB push_back

using namespace std;

int order_stat(VEC<int> &a, int k) {
    int l = 1, r = a.size()-1;
    while (1) {
        if (r <= l + 1) {
            // текущая часть состоит из 1 или 2 элементов -
            //   легко можем найти ответ
            if (r == l + 1 && a[r] < a[l])
                swap(a[l], a[r]);
            return a[k];
        }

        // упорядочиваем a[l], a[l+1], a[r]
        unsigned mid = ((l + r) >> 1);
        swap(a[mid], a[l + 1]);
        if (a[l] > a[r])
            swap(a[l], a[r]);
        if (a[l + 1] > a[r])
            swap(a[l + 1], a[r]);
        if (a[l] > a[l + 1])
            swap(a[l], a[l + 1]);

        // выполняем разделение
        // барьером является a[l+1], т.е. медиана среди a[l], a[l+1], a[r]
        unsigned
                i = l + 1,
                j = r;
        const int
                cur = a[l + 1];
        for (;;) {
            while (a[++i] < cur);
            while (a[--j] > cur);
            if (i > j)
                break;
            swap(a[i], a[j]);
        }

        // вставляем барьер
        a[l + 1] = a[j];
        a[j] = cur;

        // продолжаем работать в той части,
        //   которая должна содержать искомый элемент
        if (j >= k)
            r = j - 1;
        if (j <= k)
            l = i;
    }
}
int main() {
    ifstream cin("kth.in");
    ofstream cout("kth.out");

    int a, b, c, n, k;
    cin >> n >> k;
    VEC<int> num(n+1);
    cin >> a >> b >> c >> num[1] >> num[2];
    for (int i = 3; i <= n; ++i) {
        num[i] = a * num[i - 2] + b * num[i - 1] + c;
    }

    cout << order_stat(num, k);

    return 0;