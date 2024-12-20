#include<iostream>
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

    bool search(int value){
        Node *aux = root;
        while(aux != NULL){
            if(value == aux->value){
                return true;
            } else if(value < aux->value){
                aux = aux->left;
            } else if(value > aux->value){
                aux = aux->right;
            }
        }
        return false;
    }

    void inOrder(){
        inOrder(root);
        cout << "\n";
    }

    void inOrder(Node *aux){
        if(aux == NULL) return;
        inOrder(aux->left);
        cout << aux->value << " ";
        inOrder(aux->right);
    }

    void remove(int value){
        if(empty()) return;
        if(value == root->value){
            if(root->g() == 0){
                delete(root);
                root = NULL;

            } else if(root->g() == 1){
                Node* toDel = root;
                if(root->left != NULL){
                    root = root->left;
                } else{
                    root = root->right;
                }
                delete(toDel);

            } else{
                Node* toDel = root;
                Node* aux = root->left;
                while(aux->right != NULL){
                    aux = aux->right;
                }
                aux->right = root->right;
                root = root->left;
                delete(toDel);
            }
            return;
        }

        Node *noPai = root, *toDel = root;

        while(toDel != NULL){
            if(value == toDel->value){
                if(toDel->g() == 0){
                    if(value < noPai->value){
                        noPai->left = NULL;
                    } else{
                        noPai->right = NULL;
                    }
                    delete(toDel);

                } else if(toDel->g() == 1){
                    Node *toMove;
                    if(toDel->left != NULL){
                        toMove = toDel->left;
                    } else{
                        toMove = toDel->right;
                    }
                    if(value < noPai->value){
                        noPai->left = toMove;
                    } else{
                        noPai->right = toMove;
                    }
                    delete(toDel);

                } else{
                    Node *aux = toDel->left;
                    while(aux->right != NULL){
                        aux = aux->right;
                    }
                    aux->right = toDel->right;
                    if(value < noPai->value){
                        noPai->left = toDel->left;
                    } else{
                        noPai->right = toDel->left;
                    }
                    delete(toDel);
                }
                return;

            } else if(value > toDel->value){
                noPai = toDel;
                toDel = toDel->right;
            } else{
                noPai = toDel;
                toDel = toDel->left;
            }
        }
    }
};

int main(){
    Tree t;
    t.insert(3);
    t.insert(8);
    t.insert(10);
    t.insert(5);
    t.insert(6);
    t.inOrder();
    t.remove(8);
    t.inOrder();
}
//https://www.cs.usfca.edu/~galles/visualization/BST.html
