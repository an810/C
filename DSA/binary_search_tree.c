 #include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int key;
    struct Node* left, *right, *parent;
}TreeNode;

TreeNode* create_node(int Newkey)
{
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->key = Newkey;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

TreeNode* search(TreeNode* root, int target)
{
    if (!root) return root;
    else if (target < root->key) return search(root->left, target);
    else return search(root->right, target);
}

TreeNode* find_min(TreeNode* root, int target)
{
    if (!root) return root;
    else if (target < root->key) return find_min(root->left, target);
    else return root;
}

TreeNode* find_max(TreeNode* root, int target)
{
    if (!root) return root;
    else if (target > root->key) return find_max(root->right, target);
    else return root;
}



int main()
{
    
    return 0;
}