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

    void imprimir(){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            cout << q.front()->value;
            if(q.front()->left != NULL) q.push(q.front()->left);
            if(q.front()->right != NULL) q.push(q.front()->right);
            q.pop();
            if(q.empty()) cout << "\n\n";
            else cout << " ";
        }
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
        t.imprimir();
    }
    return 0;
}
