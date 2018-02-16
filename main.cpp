#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("sortland.in");
    int n;
    input >> n;
    double salary[n], id[n];
    for (int h=0;h<n;h++){
        input >> salary[h];
        id[h]=h+1;
    }
    for (int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(salary[j]<salary[j+1]){
                int t = salary[j];
                salary[j] = salary[j+1];
                salary[j+1] = t;
                t = id[j];
                id[j] = id[j+1];
                id[j+1] = t;
            }
        }
    }
    ofstream output("sortland.out");
    output << id[n-1] << " " << id[n/2] << " " << id[0];
    return 0;
}