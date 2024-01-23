//������������Ҳ�ж���������


#include <bits/stdc++.h>
using namespace std;

// �������Ľڵ�ṹ
typedef struct treeNode {
    int data;
    struct treeNode* leftNode;
    struct treeNode* rightNode;
    // ���캯��
    treeNode(int value) : data(value), leftNode(nullptr), rightNode(nullptr) {}
}treeNode;

// ����ڵ㵽������

treeNode* insert(treeNode* root, int value){
    if(root == NULL){
        return new treeNode(value);
    }
    if(root->data > value){
        root->leftNode = insert(root->leftNode, value);
    }
    else{
        root->rightNode = insert(root->rightNode, value);
    }
    return root;
}

treeNode* createTree(vector<int> nums) {
    if(nums.size() == 0){
        return NULL;
    }
    treeNode* root = NULL;
    for(int i = 0; i < nums.size(); i++){
        root = insert(root, nums[i]);
    }
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
    vector<int> nums = {3, 1, 2, 4, 6, 4, -1, 5}; // ʾ�����飬-1 ��ʾ�սڵ�

    // ����������
    treeNode* root = createTree(nums);

    // ���������ӡ������
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