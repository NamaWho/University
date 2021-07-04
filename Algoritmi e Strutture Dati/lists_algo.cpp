int nodes (Node* tree){
	if (!tree) return 0;
	return 1 + nodes(tree->left)  + nodes(tree->right);
}

int leaves (Node* tree){
	if (!tree) return 0;
	if (!tree->left && !tree->right) return 1;
	return leaves(tree->left) + leaves(tree->right);
}

Node* findNode (int label, Node* tree){
	if (!tree) return NULL;
	if (tree->label == label) return tree;
	Node* found = findNode(label, tree->left);
	if (found) return found;
	return findNode(label, tree->right);
}

void deleteTree (Node* &tree){
	if (tree){
		deleteTree(tree->left);
		deleteTree(tree->right);
		delete tree;
		tree = NULL;
	}
}

int insert(Node* &root, int labelSon, int labelFather, char c){
	if (!root){
		root = new Node;
		root->label = labelSon;
		root->left=root->right=NULL;
	}
	Node* a = findNode(labelFather, root);
	if(!a) return 0;
	if (c == 'l' and !a->left) {
		a->left = new Node;
		a->left->label = labelSon;
		a->left-left = a->left->right = NULL;
		return 1;
	}
	if (c=='r' and !a->right){
		a->right = new Node;
		a->right->label = labelSon;
		a->right->left=a->right->right=NULL;
		return 1;
	}
	return 0;
}
