#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
struct Runner {
    string name, country;
    int number;
};
void quicksort_a(Runner *arr, int first, int last) {
    string mid;
    Runner tmp;
    int f=first, l=last;
    mid = arr[(f+l) / 2].country; //вычисление опорного элемента
    do
    {
        while (arr[f].country<mid) f++;
        while (arr[l].country>mid) l--;
        if (f<=l) //перестановка элементов
        {
            tmp = arr[f];
            arr[f] = arr[l];
            arr[l] = tmp;
            f++;
            l--;
        }
    } while (f <= l);

    if (first<l) quicksort_a(arr, first, l);
    if (f<last) quicksort_a(arr, f, last);
}
void quicksort(Runner *arr, int first, int last) {
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
    int n, number = 0;
    input >> n;
    Runner arr[n];
    for (int i=0; i < n; i++){
        input >> arr[i].country >> arr[i].name;
        arr[i].number = number;
        number++;
    }
    quicksort_a(arr,0,n-1);
    string current_country = arr[0].country, next_country = " ";
    int st=0,en=0;
    for (int h=0;;){
        while (arr[en+1].country == current_country) {
            en++;
        }
        quicksort(arr,st,en);
        st = en + 1;
        en++;
        if(en==n){
            break;
        }
        current_country = arr[en].country;
    }
    ofstream output("race.out");
    for (int i=0; i < n; i++){
        current_country = arr[i].country;
        if (next_country != current_country){
            output << "=== " << current_country << " ===" << endl;
            next_country = current_country;
        }
        output << arr[i].name << endl;
    }
    input.close();
    output.close();
    return 0;
}