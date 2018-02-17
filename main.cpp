#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("aplusb.in");
    long int first_num, second_num;
    input >> first_num >> second_num;
    input.close();
    long sum = first_num + second_num;
    ofstream output("aplusb.out");
    output << sum;
    output.close();
    return 0;
}