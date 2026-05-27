pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1;
    int succ = -1;

    TreeNode* temp = root;

    // Find key and keep track of pred/succ
    while (temp != NULL && temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // If key not found
    if (temp == NULL)
    {
        return {pred, succ};
    }

    // Find predecessor
    TreeNode* lefttree = temp->left;
    while (lefttree != NULL)
    {
        pred = lefttree->data;
        lefttree = lefttree->right;
    }

    // Find successor
    TreeNode* righttree = temp->right;
    while (righttree != NULL)
    {
        succ = righttree->data;
        righttree = righttree->left;
    }

    return {pred, succ};
}