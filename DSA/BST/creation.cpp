#include<iostream>
using namespace std;
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
Node* insertinbst(Node*& root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertinbst(root->right,d);
    }
    else{
        root->left=insertinbst(root->left,d);
    }
    return root;
}
void takeinput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertinbst(root,data);
    }
}
int main(){
    Node* root=NULL;
    cout<<"enter the data to create BST";
    takeinput(root);
    return 0;
}