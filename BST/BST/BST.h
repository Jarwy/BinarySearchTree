#include<iostream>
#include<queue>
#include<string>
using namespace std;

class TreeNode {
private:
	TreeNode *parent;
	TreeNode *leftchild;
	TreeNode *rightchild;
	int key;
	string element;

public:
	TreeNode() { parent = 0; leftchild = 0; rightchild = 0; key = 0; element = ""; };
	TreeNode(int x, string str) {parent = 0; leftchild = 0;
								 rightchild = 0; key = x; element = str;};
	int GetKey();
	string GetElement();

	friend class BST;
};

class BST {
private:
	TreeNode *root;

public:
	BST() { root = 0; };

	TreeNode* Search(int key);
	void InsertBST(int key, string element);

	TreeNode* leftmost(TreeNode *current);
	TreeNode* Successor(TreeNode *current);
	void InorderPrint();

	void Levelorder();

	void DeleteBST(int key);
};