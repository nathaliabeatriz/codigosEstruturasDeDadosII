#include<bits/stdc++.h>
using namespace std;

void merge(int v[], int s, int m, int e){
    int tmp[(e-s) + 1];
    int i = s, j = m+1, k = 0;
    while(i <= m && j <= e){
        tmp[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
    }

    while(i <= m){
        tmp[k++] = v[i++];
    }
    while(j <= e){
        tmp[k++] = v[j++];
    }
    for(i = s, k=0; i<=e; i++, k++){
        v[i] = tmp[k];
    }
}

void mergeSort(int v[], int s, int e){
    //enquanto inicio for menor que o fim
    //ramificação da árvores - divisão
    if(s < e){
        int m = (s+e)/2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}

int main(){
    
    return 0;
}
