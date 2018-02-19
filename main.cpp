#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void quicksort(int *arr, int first, int last)
{
    int mid, count;
    int f=first, l=last;
    mid=arr[(f+l) / 2]; //вычисление опорного элемента
    do
    {
        while (arr[f]<mid) f++;
        while (arr[l]>mid) l--;
        if (f<=l) //перестановка элементов
        {
            count=arr[f];
            arr[f]=arr[l];
            arr[l]=count;
            f++;
            l--;
        }
    } while (f <= l);

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
    input.close();
    ofstream output("sort.out");
    output.close();
    return 0;
}