#include <bits/stdc++.h>
class node{
    public:
    int data;
    int i;
    int j;
    node(int a,int row,int col){
        data=a;
        i=row;
        j=col;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data >b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*,vector<node*>,compare>minheap;
    for(int i=0;i<k;i++){
        node* temp=new node(kArrays[i][0],i,0);
        minheap.push(temp);
    }
    vector<int>ans;
    while(minheap.size()>0){
        node* tmp=minheap.top();
        ans.push_back(tmp->data);
        minheap.pop();
        int i=tmp->i;
        int j=tmp->j;
        if(j+1 < kArrays[i].size()){
            node* next=new node(kArrays[i][j+1],i,j+1);
            minheap.push(next);
        }
    }
    return ans;
}
