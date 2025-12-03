#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int d){ data=d; left=right=NULL; }
};

Node* insertNode(Node* root, int x){
    if(!root) return new Node(x);
    if(x < root->data) root->left = insertNode(root->left, x);
    else root->right = insertNode(root->right, x);
    return root;
}

Node* searchRec(Node* root, int key){
    if(!root || root->data == key) return root;
    if(key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchNonRec(Node* root, int key){
    while(root){
        if(root->data == key) return root;
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Node* findMin(Node* root){
    while(root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root){
    while(root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x){
    if(x->right) return findMin(x->right);
    Node* succ = NULL;
    while(root){
        if(x->data < root->data){
            succ = root;
            root = root->left;
        } else if(x->data > root->data){
            root = root->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x){
    if(x->left) return findMax(x->left);
    Node* pred = NULL;
    while(root){
        if(x->data > root->data){
            pred = root;
            root = root->right;
        } else if(x->data < root->data){
            root = root->left;
        } else break;
    }
    return pred;
}

int main(){
    Node* root = NULL;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        root = insertNode(root, x);
    }
    
    int key;
    cin >> key;
    Node* s1 = searchRec(root, key);
    Node* s2 = searchNonRec(root, key);

    Node* mn = findMin(root);
    Node* mx = findMax(root);

    Node* succ = inorderSuccessor(root, s1);
    Node* pred = inorderPredecessor(root, s1);

    if(s1) cout << s1->data << endl; else cout << -1 << endl;
    if(s2) cout << s2->data << endl; else cout << -1 << endl;

    cout << mn->data << endl;
    cout << mx->data << endl;

    if(succ) cout << succ->data << endl; else cout << -1 << endl;
    if(pred) cout << pred->data << endl; else cout << -1 << endl;
}
