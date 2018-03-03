#include <iostream>
#include <fstream>
#include <iomanip>
void MergeSort(int &arr,)
using namespace std;
int main() {
    ifstream input("race.in");
    int n;
    input >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        input >> arr[i];
    }

    input.close();
    output.close();
    return 0;
}