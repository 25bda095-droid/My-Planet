//Tree is a non linear data structure and one node can be connected to multiple nodes
//binary tree each node has less than or equal to 2 child
// the tree top node is root node
//just after that connected nodes is child and root node is parent
//siblings--same parent nodes
//ancestors--nodes all uper sny nodes
//descendents--all noes down a current node
//leaf node--- Node that has no child
//Node root is level zero.......
#include <iostream>
using namespace std;
#include <queue>

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildtree(Node* root) {
    int data;
    cout<<"Enter the Data:";
    cin >> data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}

void preorder(Node* root){

    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root=NULL;
    root=buildtree(root);
    preorder(root);
}