#include<iostream>
using namespace std;

int partition(int v[], int s, int e){
    int pivot = v[e];
    int i = s - 1;

    for(int j=s; j< e; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[e]);
    return i + 1; 
}

void quickSort(int v[], int s, int e){
    if(s < e){
        int p = partition(v, s, e);
        quickSort(v, s, p-1);
        quickSort(v, p+1, e);
    }
}

void imprimir(int v[], int n){
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main(){
    int v[] = {3, 1, 4, 2, 5, 7, 6, 3};
    quickSort(v, 0, 7);
    imprimir(v, 8);
    return 0;
}
