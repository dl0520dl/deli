#include <bits/stdc++.h>
using namespace std;

typedef struct Thread{
	int data;
	Thread* left_child;
	Thread* right_child;
	int Ltag = 0;
	int Rtag = 0;
}Node;

Node* pre;

//中序线索化

void inorderThreadTree(Node* node)
{
	if(node == NULL){
		return;
	}
	inorderThreadTree(node->left_child);
	if(node->left_child == NULL){
		node->Ltag = 1;
		node->left_child = pre;
	}
	if(pre != NULL && pre->right_child == NULL ){
		pre->Rtag = 1;
		pre->right_child = node;
	}
    pre = node;
    inorderThreadTree(node->right_child);
}

//前序线索化

void prevorderThreadTree(Node* node)
{
    if(node == NULL){
        return;
    }
    if(node->left_child == NULL){
        node->Ltag = 1;
        node->left_child = pre;
    }
    if(pre != NULL && pre->right_child == NULL){
        pre->Rtag = 1;
        pre->right_child = node;
    }
    pre = node;
    if(node->Ltag == 0){
        prevorderThreadTree(node->left_child);
    }
    if(node->Rtag == 0){
        prevorderThreadTree(node->right_child);
    }
}

//后序线索化

void backorderThreadTree(Node* node)
{
    if(node == NULL){
        return;
    }
    prevorderThreadTree(node->left_child);
    prevorderThreadTree(node->right_child);
    if(node->left_child == NULL){
        node->Ltag = 1;
        node->left_child = pre;
    }
    if(pre->right_child == NULL){
        pre->Rtag = 1;
        pre->right_child = node;
    }
    pre = node;
}

//中序遍历
void inorderTraverse(Node* root)
{
    if(root == NULL){
        return;
    }
    Node* temp = root;
    while(temp != NULL && temp->Ltag == 0){
        temp = temp->left_child;
    }
    while(temp != NULL)
    {
        cout << temp->data << " ";
        if(temp->right_child != NULL && temp->Rtag == 0){
            temp = temp->right_child;
            while(temp->left_child != NULL && temp->Ltag == 0){
                temp = temp->left_child;
            }
        }else{
            temp = temp->right_child;
        }
    }
    cout << endl;
}

//前序遍历
void prevorderTraverse(Node* root)
{
    if(root == NULL){
        return;
    }
    Node* temp = root;
    while(temp != NULL)
    {
       while(temp->Ltag == 0){
        cout << temp->data << " ";
        temp = temp->left_child;
       }
       if(temp != NULL){
        cout << temp->data << " ";
        temp = temp->right_child;
       }
    }
    cout << endl;
}

//递归构建二叉树

Node* createTree(vector<int> nums, int index)
{
    int n = nums.size();
    if(nums[index] == '#'){
        return NULL;
    }
    Node* root = new Node;
    root->data = nums[index];
    if(index * 2 < n){
       root->left_child = createTree(nums, index * 2);
    }else{
        root->left_child = NULL;
    }
    if(index * 2 + 1 < n){
        root->right_child = createTree(nums, index * 2 + 1);
    }else{
        root->right_child = NULL;
    }
    return root;
}

//主函数

int main()
{
    vector<int> nums = { '#', 1, 3, 2, 6, 7, 8, 9};	//从下标为1开始存储数据
	//中序线索化（递归）
	pre = NULL;
	Node *root1 = createTree(nums, 1);
	inorderThreadTree(root1);
	cout << "中序线索化结果：";
	inorderTraverse(root1);
	
	//前序线索化
	pre = NULL;
	Node *root2 = createTree(nums, 1);
	prevorderThreadTree(root2);
	cout << "前序线索化结果：";
	prevorderTraverse(root2);
}