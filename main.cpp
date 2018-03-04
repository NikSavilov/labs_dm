#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int count=0;
void merge(int arr[], int left, int mid, int right)
{
    int LenL = mid - left + 1;
    int LenR =  right - mid;
    int L[LenL], R[LenR];
    for (int i = 0; i < LenL; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < LenR; j++)
        R[j] = arr[mid + 1 + j];
    int Lpointer = 0;
    int Rpointer = 0;
    int pos = left;
    while (Lpointer < LenL && Rpointer < LenR)
    {
        if (L[Lpointer] > R[Rpointer])
        {
            arr[pos] = L[Lpointer];
            Lpointer++;
            count++;
        }
        else
        {
            arr[pos] = R[Rpointer];
            Rpointer++;
        }
        pos++;
    }
    while (Lpointer < LenL)
    {
        arr[pos] = L[Lpointer];
        Lpointer++;
        pos++;
        count++;
    }
    while (Rpointer < LenR)
    {
        arr[pos] = R[Rpointer];
        Rpointer++;
        pos++;
    }
}
void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main() {
    ifstream input("inversions.in");
    int n;
    input >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        input >> arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;
    MergeSort(arr,0,n-1);
    for (int i=0;i<10;i++){
        cout << arr[i] << ' ';
    }
    cout << count;
    input.close();
    //output.close();
    return 0;
}