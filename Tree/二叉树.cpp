#include <bits/stdc++.h>
using namespace std;

// 二叉树的节点结构
typedef struct treeNode {
    int data;
    struct treeNode* leftNode;
    struct treeNode* rightNode;
    // 构造函数
    treeNode(int value) : data(value), leftNode(nullptr), rightNode(nullptr) {}
}treeNode;

// 插入节点到二叉树
treeNode* createTree(vector<int> nums, int index) {
    int n = nums.size();
    if(nums[index] == '#' || index >= n){
        return NULL;
    }
    treeNode* root = new treeNode(nums[index]);
    root->leftNode = createTree(nums, index * 2);
    root->rightNode = createTree(nums, index * 2  + 1);
    return root;
}

void preOrderTraversal(treeNode* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->leftNode);
    preOrderTraversal(root->rightNode);
}

void inOrderTraversal(treeNode* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->leftNode);
    cout << root->data << " ";
    inOrderTraversal(root->rightNode);
}

void backOrderTraversal(treeNode* root){
    if(root == NULL){
        return;
    }
    backOrderTraversal(root->leftNode);
    backOrderTraversal(root->rightNode);
    cout << root->data << " ";
}


int main() {
    vector<int> nums = {'#', 1, 2, 3, -1, 4, -1, 5}; // 示例数组，-1 表示空节点

    // 构建二叉树
    treeNode* root = createTree(nums, 1);

    // 中序遍历打印二叉树
    cout << "pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "back-order traversal: ";
    backOrderTraversal(root);
    cout << endl;

    return 0;
}