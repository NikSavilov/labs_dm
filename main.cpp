#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream input("kth.in");
    int n, k, A, B, C;
    input >> n >> k;
    input >> A >> B >> C;
    vector<int> myVector(10);
    input >> myVector[0];
    input >> myVector[1];
    for (int h = 2; h < n; h++){
        myVector[h] = A * myVector[h-2] + B * myVector[h-1] + C;
    }
    nth_element (myVector.begin(), myVector.begin() + k - 1, myVector.end());
    for (int h = 0; h < n; h++){
        cout << myVector[h] << " ";
    }
    return 0;
}