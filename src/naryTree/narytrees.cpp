#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode {
	int data;
	vector<TreeNode *> children;
} TreeNode;

TreeNode *getNewNode(int data)
{
	TreeNode *newNode = new TreeNode();
	newNode->data = data;
	return newNode;
}

void addChild(TreeNode *parent, int data)
{
	TreeNode *newNode = getNewNode(data);
	parent->children.push_back(newNode);
}

void printTree(TreeNode *root)
{
	if (root == nullptr)
		return;
	cout << root->data << endl;
	for (size_t i = 0; i < root->children.size(); i++) {
	    printTree(root->children.at(i));
	}
}

int main()
{
	TreeNode *root = getNewNode(6);
	addChild(root, 7);
	addChild(root, 9);
	addChild(root, 420);
	// at() does bound checking!
	addChild(root->children.at(0), 45);
	addChild(root->children.at(0), 45);
	addChild(root->children.at(2), 45);
	printTree(root);
}
