#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("aplusbb.in");
    long long first_num, second_num;
    input >> first_num >> second_num;
    input.close();
    long long res = first_num + (second_num * second_num);
    ofstream output("aplusbb.out");
    output << res;
    output.close();
    return 0;
}