class Solution {
TreeNode* createparentmap(TreeNode* root,int target,map<TreeNode* ,TreeNode* >&nodetoparent){
    TreeNode* res=NULL;
    queue<TreeNode* >q;
    q.push(root);
    nodetoparent[root]=NULL;
    while(!q.empty()){
        TreeNode* front=q.front();
        q.pop();
        if(front->val==target){
            res=front;
        }
        if(front->left){
            nodetoparent[front->left]=front;
            q.push(front->left);
        }
        if(front->right){
            nodetoparent[front->right]=front;
            q.push(front->right);
        }
    }
    return res;
}
int burntree(TreeNode* root,map<TreeNode* ,TreeNode*>& nodetoparent){
    map<TreeNode*,bool>visited;
    queue<TreeNode*>q;
    q.push(root);
    visited[root]=true;
    int ans=0;
    while(!q.empty()){
        bool flag=0;
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* front=q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                q.push(front->left);
                visited[front->left]=true;
                flag=1;
            }
            if(front->right && !visited[front->right]){
                q.push(front->right);
                visited[front->right]=true;
                flag=1;
            }
            if(nodetoparent[front] && !visited[nodetoparent[front]]){
                q.push(nodetoparent[front]);
                visited[nodetoparent[front]]=true;
                flag=1;
            }
        }
        if(flag==1){
            ans++;
        }
    }
    return ans;
}
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode* ,TreeNode* >nodetoparent;
        TreeNode* targetnode=createparentmap(root,start,nodetoparent);
        return  burntree(targetnode,nodetoparent);    
    }
};