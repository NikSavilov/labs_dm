#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("sortland.in");
    int n;
    input >> n;
    double salary[n], id[n];
    // Filling two related arrays
    for (int h=0;h<n;h++){
        input >> salary[h];
        id[h]=h+1;
    }
    for (int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(salary[j]<salary[j+1]){
                salary[j] += salary[j+1];
                salary[j+1] = salary[j] - salary[j+1];
                salary[j] = salary[j] - salary[j+1];
                id[j] += id[j+1];
                id[j+1] = id[j] - id[j+1];
                id[j] = id[j] - id[j+1];
            }
        }
    }
    input.close();
    ofstream output("sortland.out");
    output << id[n-1] << " " << id[n/2] << " " << id[0];
    output.close();
    return 0;
}