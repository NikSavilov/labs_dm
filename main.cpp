#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
int move(int i, int j, int i_cur, int j_cur, int sum, int *max_sum, int **table){

}
int main() {
    int i,j;
    ifstream input("turtle.in");
    input >> i >> j;
    int **table = new int*[i+1];
    for (int oi = 0; oi < i + 1; oi++) {
        table[oi] = new int[j + 1];
        for (int k = 0; k < j + 1; k++){
            table[oi][k] = 0;
        }
    }
    for (int oi = i; oi > 0; oi--){
        for (int oj = 1; oj <= j; oj++){
            input >> table[oi][oj];
        }
    }
    for (int oi = 1; oi <= i; oi++){
        for (int oj = 1; oj <= j; oj++){
            table[oi][oj] += (table[oi-1][oj] > table[oi][oj-1] ? table[oi-1][oj] : table[oi][oj-1]);
        }
    }
    ofstream output("turtle.out");
    output << table[i][j];
    return 0;
}