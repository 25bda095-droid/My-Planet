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

// first way to build tree
Node* buildtree(Node* root) {
    int data;
    cout<<"Enter the Data:"<<endl;
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

void levelordertraversal(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;

            if(!q.empty())
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
void reverselevelordertraversal(Node* root){
   if(root == NULL) return;
   stack<int> st;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;

            if(!q.empty())
                q.push(NULL);
        }
        else{
            st.push(temp->data);

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
//preorder--NLR(middle node then left node(go left) then right node(go right))
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

//level order traversal for building tree 2nd way
void buildfromlevelorder(Node* &root){
    queue<Node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        cout<<"Enter value of left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
            temp -> left = new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter value of right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1){
            temp -> right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}


int main(){
    Node* root=NULL;
    // root=buildtree(root);
    // cout<<"preoder is"<<endl;
    // preorder(root);
    // // cout<<endl;//1 3 5 7 11 17 -1 -1 -1 -1 -1 -1
    // cout<<"level order traversal is"<<endl;
    // levelordertraversal(root);
    // reverselevelordertraversal(root);
    // cout<<"inorder traversal is"<<endl;
    // inorder(root);
    // cout<<"preorder traversal is"<<endl;
    // preorder(root);
    // cout<<"postorder traversal is"<<endl;
    // postorder(root);
    buildfromlevelorder(root);
    levelordertraversal(root);
}