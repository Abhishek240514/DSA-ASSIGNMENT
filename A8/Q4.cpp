#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int d){ data=d; left=right=NULL; }
};

bool isBSTUtil(Node* root, long long minv, long long maxv){
    if(!root) return true;
    if(root->data <= minv || root->data >= maxv) return false;
    return isBSTUtil(root->left, minv, root->data) &&
           isBSTUtil(root->right, root->data, maxv);
}

bool isBST(Node* root){
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    if(isBST(root)) cout << "YES";
    else cout << "NO";
}
