#include<bits/stdc++.h>
using namespace std;

bool comparar(string s1, string s2){
    int n = min(s1.size(), s2.size());
    for(int i=0; i<n; i++){
        if(s1[i] > s2[i]){
            return true;
        }
        else if(s2[i] > s1[i]){
            return false;
        }
    }

    if(s1.size() < s2.size()) return false;
    else return true;
}


void merge(vector<string>&v, int s, int m, int e){
    vector<string>tmp((e-s) + 1);
    int i = s, j = m+1, k = 0;
    while(i <= m && j <= e){
        tmp[k++] = (comparar(v[i], v[j])) ? v[j++] : v[i++];
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

void mergeSort(vector<string>&v, int s, int e){
    if(s < e){
        int m = (s+e)/2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}

bool buscaBinaria(vector<string>&v, int n, string x) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (v[m] == x) {
            return true;
        } else if (comparar(v[m], x)) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return false;
}


int main(){
    int n;
    cin >> n;
    vector<string>v;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    mergeSort(v, 0, n-1);

    int m;
    cin >> m;
    int cont = 0;
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        if(buscaBinaria(v, n, s)) cont++;
    }

    cout << cont << "\n";
}
