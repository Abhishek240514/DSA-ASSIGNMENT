#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void preorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<endl;
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
}
int main(){
    return 0;
}