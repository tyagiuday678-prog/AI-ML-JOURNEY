class node{
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<node*, vector<node*>, compare> minheap;

        int k = nums.size();

        // Insert first element of every list
        for(int i = 0; i < k; i++){
            int ele = nums[i][0];

            mini = min(mini, ele);
            maxi = max(maxi, ele);

            minheap.push(new node(ele, i, 0));
        }

        int start = mini;
        int end = maxi;

        while(!minheap.empty()){

            node* temp = minheap.top();
            minheap.pop();

            mini = temp->data;

            // Update answer range
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }

            // Move to next element in same row
            if(temp->col + 1 < nums[temp->row].size()){

                int nextElement = nums[temp->row][temp->col + 1];

                maxi = max(maxi, nextElement);

                minheap.push(
                    new node(nextElement,
                             temp->row,
                             temp->col + 1)
                );
            }
            else{
                break;
            }
        }

        return {start, end};
    }
};