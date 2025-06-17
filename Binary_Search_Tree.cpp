#pragma once

#include <iostream>

using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* Left;
    TreeNode* Right;

    TreeNode(int = 0);

};

TreeNode :: TreeNode(int x){
    data = x;
    Left = nullptr;
    Right = nullptr;
}

class BinarySearchTree{
    private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode*, int);
    TreeNode* findNode(TreeNode*, int);
    TreeNode* deleteNode(TreeNode*, int);

    TreeNode* findMaxLeftTree(TreeNode*);
    TreeNode* findMinRightTree(TreeNode*);
    int countLeave(TreeNode*);
    int countNode(TreeNode*);

    void preOrder(TreeNode*);
    void inOrder(TreeNode*);
    void postOrder(TreeNode*);

    public:

    BinarySearchTree();

    void insert(int);
    bool find(int);
    void eraser(int);
    void count();
    void print();

};

TreeNode* BinarySearchTree :: insertNode(TreeNode* node, int x){
    
    if(node == nullptr){
        return new TreeNode(x);
    }
    
    if(node->data < x){
        node->Right = insertNode(node->Right, x);
    }else if(node->data > x){
        node->Left = insertNode(node->Left, x);
    }
    
    return node;
}

BinarySearchTree :: BinarySearchTree(){
    root = nullptr;
}

void BinarySearchTree :: insert(int x){
    root = insertNode(root, x);
}

void BinarySearchTree :: preOrder(TreeNode* node){

    if(node != nullptr){
        cout << node->data << ' ';

        preOrder(node->Left);
        preOrder(node->Right);
    }

}

void BinarySearchTree :: inOrder(TreeNode* node){

    if(node != nullptr){
        inOrder(node->Left);

        cout << node->data << ' ';

        inOrder(node->Right);
    }

}

void BinarySearchTree :: postOrder(TreeNode* node){

    if(node != nullptr){
        postOrder(node->Left);
        postOrder(node->Right);

        cout << node->data << ' ';
    }

}

void BinarySearchTree :: print(){

    // preOrder(root);
    // inOrder(root);
     postOrder(root);

}

bool BinarySearchTree :: find(int x){

    TreeNode* tmp = findNode(root, x);
    if(tmp == nullptr)  return false;
    return true;

}

TreeNode* BinarySearchTree :: findNode(TreeNode* node, int x){

    if(node == nullptr) return nullptr;
    if(node->data == x) return node;

    if(x < node->data)  return findNode(node->Left, x);
    else if(x > node->data) return findNode(node->Right, x);
    return nullptr;
}

TreeNode* BinarySearchTree :: findMaxLeftTree(TreeNode* node){

    while(node != nullptr && node->Right != nullptr){
        node = node->Right;
    }
    return node;

}

TreeNode* BinarySearchTree :: findMinRightTree(TreeNode* node){

    while(node != nullptr && node->Left != nullptr){
        node = node->Left;
    }
    return node;

}

TreeNode* BinarySearchTree :: deleteNode(TreeNode* node, int x){

    if(node == nullptr) return nullptr;

    if(x < node->data){
        node->Left = deleteNode(node->Left, x);
    }else if(x > node->data){
        node->Right = deleteNode(node->Right, x);
    }else{
        if(node->Left == nullptr && node->Right == nullptr){
            delete node;
            return nullptr;
        }

        if(node->Left == nullptr){
            TreeNode* NodeRight = node->Right;
            delete node;
            return NodeRight;
        }
        if(node->Right == nullptr){
            TreeNode* NodeLeft = node->Left;
            delete node;
            return NodeLeft;
        }

        // // Thay bang node lon nhat ben trai
        // TreeNode* MaxLeft = findMaxLeftTree(node->Left);
        // node->data = MaxLeft->data;
        // node->Left = deleteNode(node->Left, node->data);

        // // Thay bang node be nhat ben phai
        TreeNode* MinRight = findMinRightTree(node->Right);
        node->data = MinRight->data;
        node->Right = deleteNode(node->Right, node->data);
    }
    return node;

}

void BinarySearchTree :: eraser(int x){

    root = deleteNode(root, x);

}

int BinarySearchTree :: countLeave(TreeNode* node){

    if(node->Left == nullptr && node->Right == nullptr) return 1;
    return countLeave(node->Left) + countLeave(node->Right);

}

int BinarySearchTree :: countNode(TreeNode* node){

    if(node == nullptr) return 0;
    return 1 + countNode(node->Left) + countNode(node->Right);

}

void BinarySearchTree :: count(){

    cout << "\nCount (Leave: 1 || Node: 2)\n";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        cout << countLeave(root);
        break;
    
    default:
        cout << countNode(root);
        break;
    }
}