#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node *left, *right;
    Node() {
        left = NULL;
        right = NULL;
    }
    Node(int _value) {
        value = _value;
        left = NULL;
        right = NULL;
    }
    int g() {
        int g = 0;
        if (left != NULL) g++;
        if (right != NULL) g++;
        return g;
    }
};

struct Tree {
    Node *root;
    Tree() {
        root = NULL;
    }
    bool empty() {
        return root == NULL;
    }


    void insert(int value) {
        if (empty()) {
            root = new Node(value);
            return;
        }
        insert(root, value);
    }

    void insert(Node *aux, int value) {
        if (value < aux->value) {
            if (aux->left == NULL) {
                aux->left = new Node(value);
                return;
            }
            insert(aux->left, value);
        } else if (value > aux->value) {
            if (aux->right == NULL) {
                aux->right = new Node(value);
                return;
            }
            insert(aux->right, value);
        }
    }

    bool search(int value) {
        Node *aux = root;
        while (aux != NULL) {
            if (value == aux->value) {
                return true;
            } else if (value < aux->value) {
                aux = aux->left;
            } else if (value > aux->value) {
                aux = aux->right;
            }
        }
        return false;
    }

    void prefixo(){
        cout << "Pre.:";
        prefixo(root);
        cout << "\n";
    }

    void prefixo(Node *aux){
        if(aux == NULL) return;
        cout << " ";
        cout << aux->value;
        prefixo(aux->left);
        prefixo(aux->right);
    }

    void infixo(){
        cout << "In..:";
        infixo(root);
        cout << "\n";
    }

    void infixo(Node *aux){
        if(aux == NULL) return;
        infixo(aux->left);
        cout << " ";
        cout << aux->value;
        infixo(aux->right);
    }

    void posfixo(){
        cout << "Post:";
        posfixo(root);
        cout << "\n\n";
    }

    void posfixo(Node *aux){
        if(aux == NULL) return;
        posfixo(aux->left);
        posfixo(aux->right);
        cout << " ";
        cout << aux->value;
    }

};

int main() {
    int c;
    cin >> c;
    for(int i = 1; i<=c; i++){
        Tree t;
        int n;
        cin >> n;
        for(int j=0; j<n; j++){
            int aux;
            cin >> aux;
            t.insert(aux);
        }
        cout << "Case " << i << ":\n";
        t.prefixo();
        t.infixo();
        t.posfixo();
    }
    return 0;
}
