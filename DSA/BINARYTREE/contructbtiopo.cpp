
class Solution {
void createmapping(vector<int>&in,map<int,int>& nodetoindex,int n){
    for(int i=0;i<n;i++){
        nodetoindex[in[i]]=i;
    }
}
TreeNode* solve(vector<int>& in, vector<int>& post,int &index,int inorst,int inorend,int n,map<int,int>& nodetoindex){
    if(index<0 || inorst>inorend){
        return NULL;
    }
    int ele=post[index--];
    TreeNode* root=new TreeNode(ele);
    int posi=nodetoindex[ele];
    root->right=solve(in,post,index,posi+1,inorend,n,nodetoindex);
    root->left=solve(in,post,index,inorst,posi-1,n,nodetoindex);
    return root;
}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderindex=postorder.size()-1;
        int n=postorder.size();
        map<int,int>nodetoindex;
        createmapping(inorder,nodetoindex,n);
        TreeNode* ans=solve(inorder,postorder,postorderindex,0,n-1,n,nodetoindex);
        return ans;      
    }
};