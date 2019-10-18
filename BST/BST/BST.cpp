#include"BST.h"

int TreeNode::GetKey() {
	return key;
}

string TreeNode::GetElement() {
	return element;
}

TreeNode* BST::Search(int key)
{
	TreeNode *current = root;
	while (current != NULL && current->key != key) {
		if (key < current->key) {
			current = current->leftchild;
		}
		else{
			current = current->rightchild;
		}
	}
	return current;
}

void BST::InsertBST(int key, string element) {
	TreeNode *NewNode = new TreeNode(key, element);
	TreeNode *pioneer = root;
	TreeNode *candidate = 0;
	while (pioneer != NULL) {
		candidate = pioneer;
		if (NewNode->key < pioneer->key) {
			pioneer = pioneer->leftchild;
		}
		else {
			pioneer = pioneer->rightchild;
		}
	}

	NewNode->parent = candidate;

	if (candidate == NULL) {
		this->root = NewNode;
	}
	else if (NewNode->key < candidate->key) {
		candidate->leftchild = NewNode;
	}
	else {
		candidate->rightchild = NewNode;
	}
}

TreeNode* BST::leftmost(TreeNode *current)
{
	while (current->leftchild != NULL)
	{
		current = current->leftchild;
	}
	return current;
}

TreeNode* BST::Successor(TreeNode *current)
{
	if (current->rightchild != NULL)
	{
		return leftmost(current->rightchild);
	}

	TreeNode *successor = current->parent;
	while (successor != NULL && current == successor->rightchild)
	{
		current = successor;
		successor = current->parent;
	}
	return successor;
}

void BST::InorderPrint()
{
	TreeNode *current = leftmost(root);

	while (current)
	{
		cout << current->element <<"("<<current->key<<")"<<"  ";
		current = Successor(current);
	}
}

void BST::Levelorder()
{
	queue<TreeNode*> q;
	q.push(this->root);

	while (!q.empty())
	{
		TreeNode *current = q.front();
		q.pop();
		//cout << current->element << " ";
		cout << current->element << "(" << current->key << ")" << "  ";
		if (current->leftchild != NULL)
		{
			q.push(current->leftchild);     //q.push(current->leftchild);
		}									//q.push(current->rightchild);

		if (current->rightchild != NULL)
		{
			q.push(current->rightchild);
		}
	}

}

void BST::DeleteBST(int key) {
	TreeNode *DeadNode = Search(key);
	if (DeadNode == NULL) {
		cout << "Not found!!\n";
		return;
	}

	TreeNode *x = 0;		//child of real Deleted Node
	TreeNode *y = 0;		//Deleted Node
	//--------------------------------------------------------------------------------------------------------------------------//
	if (DeadNode->leftchild == NULL || DeadNode->rightchild == NULL) {					
		y = DeadNode;							
	}
	else {
		y = Successor(DeadNode);
	}
	//--------------------------------------------------------------------------------------------------------------------------//
	if (y->leftchild != NULL) {
		x = y->leftchild;
	}
	else {
		x = y->rightchild;
	}
	//--------------------------------------------------------------------------------------------------------------------------//
	if (x != NULL) {
		x->parent = y->parent;
	}

	if (y->parent == NULL) {
		x = this->root;
	}
	else if(y == y->parent->leftchild){
		y->parent->leftchild = x;
	}
	else {
		y->parent->rightchild = x;
	}
	
	if (y->key != DeadNode->key) {
		DeadNode->element = y->element;
		DeadNode->key = y->key;
	}

	delete y;
	y = 0;
}