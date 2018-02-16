#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
int main() {
    ifstream input("smallsort.in");
    int n;
    input >> n;
    int arr[n];
    for (int i=0;i < n;i++){
        input >> arr[i];
        for (int j = i - 1; j >= 0; j--){
            if (arr[j+1] < arr[j]){
                int t = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = t;
            }
        }
    }
    ofstream output("smallsort.out");
    for (int h=0; h < n; h++){
        output << arr[h] << " ";
    }
    return 0;
}