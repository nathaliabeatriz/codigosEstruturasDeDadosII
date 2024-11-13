#include <bits/stdc++.h>

using namespace std;

struct Competidor{
    int id, qtdRes, pen;

    Competidor(){
        id = qtdRes = pen = 0;
    }
};

void merge(Competidor v[], int s, int m, int e){
    Competidor tmp[(e-s) + 1];
    int i = s, j = m+1, k = 0;
    while(i <= m && j <= e){
        if(v[i].qtdRes > v[j].qtdRes){
            tmp[k++] = v[i++];
        }
        else if(v[i].qtdRes < v[j].qtdRes){
            tmp[k++] = v[j++];
        }
        else if(v[i].qtdRes == v[j].qtdRes){
            if(v[i].pen <= v[j].pen){
                tmp[k++] = v[i++];
            } else if(v[i].pen > v[j].pen){
                tmp[k++] = v[j++];
            }
        }
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

void mergeSort(Competidor v[], int s, int e){
    if(s < e){
        int m = (s+e)/2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}

int main(){
    int n, m;

    cin >> n >> m;

    Competidor v[n+1];

    while(m--){
        int c, minutos, t, p=20;
        char q;

        cin >> c >> q >> minutos >> t;
        t--;
        v[c].id = c;
        v[c].qtdRes++;
        v[c].pen += (t*p) + minutos;
    }

    for(int i = 1; i <= n; i++){
        if(v[i].id == 0){
            v[i].id = i;
        }
    }
    mergeSort(v, 1, n);

    for(int i=1; i<n+1; i++){
        cout << v[i].id << " " << v[i].qtdRes << " " << v[i].pen << "\n";
    }
}
