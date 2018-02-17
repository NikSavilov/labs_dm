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
    // Pushback at end, from previous to first swapping while num is less then neighbour
    for (int i=0;i < n;i++){
        input >> arr[i];
        for (int j = i - 1; j >= 0; j--){
            if (arr[j+1] < arr[j]){
                arr[j+1] += arr[j];
                arr[j] = arr[j+1] - arr[j];
                arr[j+1] = arr[j+1] - arr[j];
            }
        }
    }
    input.close();
    ofstream output("smallsort.out");
    for (int h=0; h < n; h++){
        output << arr[h] << " ";
    }
    output.close();
    return 0;
}