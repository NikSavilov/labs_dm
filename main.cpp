#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
struct Runner {
    int number;
    string name, country;
};
void quicksort(Runner *arr, int first, int last)
{
    int mid;
    Runner tmp;
    int f=first, l=last;
    mid = arr[(f+l) / 2].number; //вычисление опорного элемента
    do
    {
        while (arr[f].number<mid) f++;
        while (arr[l].number>mid) l--;
        if (f<=l) //перестановка элементов
        {
            tmp = arr[f];
            arr[f] = arr[l];
            arr[l] = tmp;
            f++;
            l--;
        }
    } while (f <= l);

    if (first<l) quicksort(arr, first, l);
    if (f<last) quicksort(arr, f, last);
}

int main() {
    ifstream input("race.in");
    int n;
    input >> n;
    Runner arr[n];
    for (int i=1; i < n+1; i++){
        input >> arr[i].country >> arr[i].name;
        arr[i].number = i;
    }
    int count = n;
    string cur_country = arr[1].country, next_country = cur_country;
    while (count !=0) {
        cout << "=== " + cur_country + " ==="<< endl;
        for (int i = 1; i < n+1; i++){
            if (arr[i].country != ""){
                if (arr[i].country == cur_country){
                    cout << arr[i].name << endl;
                    count--;
                    arr[i].country = "";
                }
                else if (next_country == cur_country){
                    next_country = arr[i].country;
                }
            }
        }
        cur_country = next_country;
    }
    input.close();
    ofstream output("race.out");
    output.close();
    return 0;
}