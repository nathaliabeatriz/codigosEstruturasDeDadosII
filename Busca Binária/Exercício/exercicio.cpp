#include<bits/stdc++.h>
using namespace std;

void procurarStrings(vector<string>v, string s, int pos, int &iList, int &fList){
    int i = pos - 1;
    int n = s.size();
    while(i >= 0){
        string comp = "";
        for(int j=0; j<n; j++){
            comp += v[i][j];
        }
        if(comp == s) iList = i;
        else break;
        i--;
    }

    i = pos+1;
    while(i < (int) v.size()){
        string comp = "";
        for(int j=0; j<n; j++){
            comp += v[i][j];
        }
        if(comp == s) fList = i;
        else break;
        i++;
    }
}

pair<int, int> buscaBinaria(vector<string>v, string x){
    int n = v.size();
    int tamX = x.size();
    int i = 0, f = n - 1;
    int indiceV = 0, indiceX = 0, inicioLista, fimLista;
    while(i <= f){
        int m = (i+f)/2;
        if(v[m][indiceV] == x[indiceX]){
            indiceV++;
            indiceX++;
            if(indiceX >= tamX){
                inicioLista = m;
                fimLista = m;
                procurarStrings(v, x, m, inicioLista, fimLista);
                return {inicioLista, fimLista};
            }
        }
        else if(v[m][indiceV] > x[indiceX]){
            indiceV = indiceX = 0;
            f = m-1;
        }
        else if(v[m][indiceV] < x[indiceX]){
            indiceV = indiceX = 0;
            i = m+1;
        }
    }
    return {-1, -1};
}

int main(){
    ifstream infile;
    infile.open("nomes.txt");
    vector<string>nomes;
    string s;
    while(getline(infile, s)){
        for(int i=0; i< (int)s.size(); i++){
            s[i] = tolower(s[i]);;
        }
        nomes.push_back(s);
    }

    string pesq;
    cin >> pesq;

    for(int i=0; i<=(int)pesq.size(); i++){
        pesq[i] = tolower(pesq[i]);
    }

    pair<int, int> pos;
    pos = buscaBinaria(nomes, pesq);

    if(pos.first == -1 && pos.second == -1){
        cout << "Nenhum resultado encontrado\n";
        return 0;
    }

    for(int i=pos.first; i<=pos.second; i++){
        for(int j=0; j<(int)nomes[i].size(); j++){
            if(j==0 || nomes[i][j-1] == ' '){
                nomes[i][j] = toupper(nomes[i][j]);
            }
        }
        cout << nomes[i] << "\n";
    }
}