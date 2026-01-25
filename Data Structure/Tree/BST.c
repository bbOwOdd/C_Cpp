#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

TreeNode *createNode(int v);
TreeNode* insert(TreeNode *root, int v);
TreeNode *findMax(TreeNode *root);
TreeNode *findMin(TreeNode *root);
void preorder(TreeNode *root);
void inorder(TreeNode *root);
void postorder(TreeNode *root);
int findNodes(TreeNode *root);
int depth(TreeNode *root);

int main(){
    TreeNode *root = NULL;

    return 0;
}

TreeNode *createNode(int v){
    TreeNode *newNode = (TreeNode*)malloac(sizeof(TreeNode));
    newNode->data = v;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode *root, int v){
    if(root == NULL) root = createNode(v);
    else if(v < root->data) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
}

void preorder(TreeNode *root){
    if(root){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }  
}

void inorder(TreeNode *root){
    if(root){       
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    } 
}

void postorder(TreeNode *root){
    if(root){
        inorder(root->left);
        inorder(root->right);
        printf("%d ", root->data);
    } 
}

TreeNode *findMin(TreeNode *root){
    if(root == NULL) return NULL;
    else if(root->left != NULL) return findMin(root->left);
    return root;
}

TreeNode *findMax(TreeNode *root){
    if(root == NULL) return NULL;
    else if(root->right != NULL) return findMax(root->right);
    return root;
}

int findNodes(TreeNode *root){
    if(root == NULL) return NULL;
    return 1 + findNodes(root->left) + findNodes(root->right);
}

int depth(TreeNode *root){
    if(root == NULL) return NULL;
    int l = depth(root->left), r = depth(root->right);
    return 1 + MAX(l, r);
}
