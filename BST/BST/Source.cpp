#include"BST.h"

int main() {
	//cout << "OK\n";
	BST T;
	T.InsertBST(8, "�t�P�H");
	T.InsertBST(1000, "����");
	T.InsertBST(2, "�J�L");
	T.InsertBST(513, "��J");

	cout << "Inorder Traversl:\n";
	T.InorderPrint(); 
	cout << "\n\n";
	cout << "Levelorder Traversl:\n";
	T.Levelorder();
	cout << "\n\n";
	cout << "Delete 8:\n";
	T.DeleteBST(8);
	T.InorderPrint();
	cout << "\n\n";

	TreeNode *target = T.Search(8);
	if (target != NULL) {
		cout << "Target is " << target->GetElement() << "(" << target->GetKey() << ")";
		cout << "\n\n";
	}
	else {
		cout << "Target isn't exsit.\n\n";
	}

	target = T.Search(1000);
	if (target != NULL) {
		cout << "Target is " << target->GetElement() << "(" << target->GetKey() << ")";
		cout << "\n\n";
	}
	else {
		cout << "Target isn't exsit.\n\n";
	}
	system("pause");
	return 0;
}