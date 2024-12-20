#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *left, *right;
    Node(){
        left = NULL;
        right = NULL;
    }
    Node(int _value){
        value = _value;
        left = NULL;
        right = NULL;
    }
    int g(){
        int g = 0;
        if(left != NULL) g++;
        if(right != NULL) g++;
        return g;
    }
};

struct Tree{
    Node *root;
    Tree(){
        root = NULL;
    }
    bool empty(){
        return root == NULL;
    }

    void insert(int value){
        if(empty()){
            root = new Node(value);
            return;
        }
        insert(root, value);
    }

    void insert(Node *aux, int value){
        if(value < aux->value){
            if(aux->left == NULL){
                aux->left = new Node(value);
                return;
            }
            insert(aux->left, value);
        } else if(value > aux->value){
            if(aux->right == NULL){
                aux->right = new Node(value);
                return;
            }
            insert(aux->right, value);
        }
    }

    Node* search(int value){
        Node *aux = root;
        while(aux != NULL){
            if(value == aux->value){
                return aux;
            } else if(value < aux->value){
                aux = aux->left;
            } else if(value > aux->value){
                aux = aux->right;
            }
        }
        return NULL;
    }

    int altura(int value){
        Node* no = search(value);
        if(no == NULL) return -1;
        Node* aux = no;
        int altLeft = 0, altRight;
        while(aux->left != NULL){
            altLeft++;
            aux = aux->left;
        }
        aux = no;
        while(aux->right != NULL){
            altRight++;
            aux = aux->right;
        }

        return min(altLeft, altRight);
    }

};

int main(){
    Tree t;
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        t.insert(num);
    }
    int x;
    cin >> x;

    cout << t.altura(x) << "\n";
}


