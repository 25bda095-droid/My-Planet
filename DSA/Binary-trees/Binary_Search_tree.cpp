// In binary search tree for every node its left side should be smaller then the node and right side should be greater than node

#include <iostream>
using namespace std;
#include <queue>
#include <stack>

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

Node* InsertIntoBST(Node* root,int d){  //time complexity is O(log(n))
    //base case
    if(root==NULL){
        root = new Node(d);
        return root;
    }
    if (d == root->data) {
    return root;   // ignore duplicate
    }

    //for right part
    if(d > root->data){
        root -> right = InsertIntoBST(root->right,d);
    }

    // for left part
    if(d < root -> data){
        root ->left = InsertIntoBST(root->left,d);
    }

    return root;


}

void takeinput(Node* &root){ //time complexity is O(n)
    int data;
    cin>>data;

    while(data!=-1){
        root = InsertIntoBST(root,data);
        cin >> data;
    }
}

void levelordertraversal(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){//old level is completely traversed
            cout << endl;

            if(!q.empty())// q still has some child nodes
                q.push(NULL);
        }
        else{
            cout << temp->data << " ";

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
}


void preorder(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";//N
    preorder(root->left);//L
    preorder(root->right);//R
}
//inorder---LNR(leftnode(go left),middlenode,rightnode(go right))
void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);//L
    cout<<root->data<<" ";//N
    inorder(root->right);//R
}

// postorder-- LRN(left side,rightside, middle node)
void postorder(Node* root){
    if(root==NULL) return;
    
    postorder(root->left);//L
    postorder(root->right);//R
    cout<<root->data<<" ";//N
}


Node* minvalue(Node* root){
    Node* temp = root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* maxvalue(Node* root){
    Node* temp = root;

    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

Node* DeleteFromBST(Node* root, int val){
    //basecase
    if(root==NULL) return root;

    if(root->data==val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2child
        if(root->left!=NULL && root->right!=NULL){
            
        }
    }
    else if(root->data>val){
        root->left=DeleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right=DeleteFromBST(root->right,val);
        return root;
    }

}

int main(){
    Node* root=NULL;

    cout<<"Enter the data to create BST"<<endl;
    takeinput(root);

    cout<<"printing the BST"<<endl;
    levelordertraversal(root);

    cout<<"printing the preorder"<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Printing the postorder"<<endl;
    postorder(root);
    cout<<endl;

    cout<<"printing the inorder"<<endl;
    inorder(root);
    cout<<endl;

    return 0;

    cout<<"MIN Value is"<<minvalue(root)<<endl;
    cout<<"MAX Value is"<<maxvalue(root)<<endl;
    

}
