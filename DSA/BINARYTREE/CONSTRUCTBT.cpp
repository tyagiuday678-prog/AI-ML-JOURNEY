
class Solution {
int fposition(vector<int>& inorder,int k,int n){
    for(int i=0;i<n;i++){
        if(inorder[i]==k){
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int n,int inorsta,int inorend){
    if(index>=n || inorsta > inorend){
        return NULL;
    }
    int ele=preorder[index++];
    TreeNode* root=new TreeNode(ele);
    int posi=fposition(inorder,ele,n);
    root->left=solve(preorder,inorder,index,n,inorsta,posi-1);
    root->right=solve(preorder,inorder,index,n,posi+1,inorend);
    return root;   
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex=0;
        int n=preorder.size();
        TreeNode* ans=solve(preorder,inorder,preindex,n,0,n-1);
        return ans;     
    }
};