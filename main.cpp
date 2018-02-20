#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void quicksort(int *arr, int first, int last)
{
    int mid, count;
    int f=first, l=last;
    mid = arr[f]; //вычисление опорного элемента
    while (f <= l){
        for(int h = f;;h++){
            if (arr[h] >= mid){
                f = h;
                break;
            }
        }
        for(int h = l;;h--){
            if (arr[h] <= mid){
                l = h;
                break;
            }
        }
        if (f<l+1) //перестановка элементов
        {
            count=arr[f];
            arr[f]=arr[l];
            arr[l]=count;
            f++;
            l--;
        }
    } ;

    if (first<l) quicksort(arr, first, l);
    if (f<last) quicksort(arr, f, last);
}
int main() {
    ifstream input("sort.in");
    int n;
    input >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        input >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    ofstream output("sort.out");
    for (int i=0;i<n;i++){
        output << arr[i] << " ";
    }
    return 0;
}