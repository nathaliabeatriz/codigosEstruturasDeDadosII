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
        prefixo(root);
        cout << "\n";
    }

    void prefixo(Node *aux){
        if(aux == NULL) return;
        if(aux != root) cout << " ";
        cout << aux->value;
        prefixo(aux->left);
        prefixo(aux->right);
    }

    void infixo(){
        int cont = 0;
        infixo(root, cont);
        cout << "\n";
    }

    void infixo(Node *aux, int &cont){
        if(aux == NULL) return;
        infixo(aux->left, cont);
        if(cont > 0) cout << " ";
        cont++;
        cout << aux->value;
        infixo(aux->right, cont);
    }

    void posfixo(){
        int cont = 0;
        posfixo(root, cont);
        cout << "\n";
    }

    void posfixo(Node *aux, int &cont){
        if(aux == NULL) return;
        posfixo(aux->left, cont);
        posfixo(aux->right, cont);
        if(cont > 0) cout << " ";
        cout << aux->value;
        cont++;
    }

    void remove(int value) {
        if (!empty() && root->value == value) {

            if (root->g() == 0) {
                delete(root);
                root = NULL;
            } else if (root->g() == 1) {
                Node *toDel = root;
                if (root->left != NULL) {
                    root = root->left;
                } else {
                    root = root->right;
                }
                delete(toDel);
            } else {
                Node *toDel = root;
                Node* aux2 = root->left;
                Node *temp = aux2;
                while (aux2->right != NULL) {
                    temp = aux2;
                    aux2 = aux2->right;
                }
                aux2->right = root->right;

                if(temp != aux2){
                    aux2->left = root->left;
                    temp->right = NULL;
                }
                root = aux2;
                delete(toDel);
            }
            return;
        }

        Node* aux = root;
        Node* toDel = root;

        while (toDel != NULL) {
            if (toDel->value == value) {
                if (toDel->g() == 0) {
                    if (value > aux->value) {
                        aux->right = NULL;
                    } else {
                        aux->left = NULL;
                    }
                    delete(toDel);

                } else if (toDel->g() == 1) {
                    Node* toMove;
                    if (toDel->left != NULL) {
                        toMove = toDel->left;
                    } else {
                        toMove = toDel->right;
                    }
                    if (value > aux->value) {
                        aux->right = toMove;
                    } else {
                        aux->left = toMove;
                    }
                    delete(toDel);
                    
                } else {
                    Node* aux2 = toDel->left;
                    while (aux2->right != NULL) {
                        aux2 = aux2->right;
                    }

                    aux2->right = toDel->right;

                    if (value > aux->value) {
                        aux->right = toDel->left;
                    } else {
                        aux->left = toDel->left;
                    }
                    delete(toDel);
                }
                return;

            } else if (value < toDel->value) {
                aux = toDel;
                toDel = toDel->left;
            } else {
                aux = toDel;
                toDel = toDel->right;
            }
        }
    }

};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string op;
    Tree t;
    while(getline(cin, op)){
        if(op == "INFIXA"){
            t.infixo();
        } else if(op == "PREFIXA"){
            t.prefixo();
        } else if(op == "POSFIXA"){
            t.posfixo();
        } else{
            string num = "";
            for(int i=2; i<op.size(); i++){
                num += op[i];
            }
            if(op[0] == 'I'){
                t.insert(stoi(num));
            } else if(op[0] == 'R'){
                t.remove(stoi(num));
            } else if(op[0] == 'P'){
                if(t.search(stoi(num))){
                    cout << num << " existe\n";
                } else{
                    cout << num << " nao existe\n";
                }
            }
        }
    }
    return 0;
}
