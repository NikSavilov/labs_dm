#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ifstream cin("antiqs.in");
    ofstream cout("antiqs.out");
    long n;
    cin >> n;
    long mas[n];
    for (int i=1;i<=n;i++){
        
    }
    long pivot = (n - 1) / 2, num = n;
    for (long i=0; i<n; i++){
        mas[pivot] = num;
        pivot += pow(-1,i) * (i+1);
        num--;
    }
    for (long i =0;i<n;i++){
        cout << mas[i] << " ";
    }
    return 0;
}