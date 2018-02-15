#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("aplusbb.in");
    double first_num, second_num;
    input >> first_num >> second_num;
    input.close();

    double res = first_num + second_num * second_num;

    FILE * output = fopen("aplusbb.out","w");

    int rounded = res;
    if (res - rounded == 0){
        fprintf(output,"%d",rounded);
    }
    else
        fprintf(output,"%f",res);

    return 0;
}