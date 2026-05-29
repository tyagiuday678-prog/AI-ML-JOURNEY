void inorder(TreeNode *root,vector<int> & in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int>p;
    vector<int>q;
    inorder(root1,p);
    inorder(root2,q);
    vector<int>s;
    int i=0;
    int j=0;
    while((i<p.size()) && (j<q.size())){
        if(p[i]<q[j]){
            s.push_back(p[i]);
            i++;
        }
        else{
            s.push_back(q[j]);
            j++;
        }
    }
    while(i<p.size()){
        s.push_back(p[i]);
        i++;
    }
    while(j<q.size()){
        s.push_back(q[j]);
        j++;
    }
    return s;
}