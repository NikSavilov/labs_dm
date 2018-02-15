#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("aplusb.in");
    if (!input.is_open()){
        exit(1);
    }
    long int first_num, second_num;
    input >> first_num >> second_num;
    input.close();

    long res = first_num + second_num * second_num;

    ofstream output("aplusb.out");
    if (!output.is_open()){
        exit(2);
    }
    output << res;
    output.close();
    return 0;
}