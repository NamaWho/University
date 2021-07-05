//bintree di ricerca (solo funzioni differenti)

node* findnode(int x,node* tree){ //logn o n (albero degenere) ATTENZIONE: in media logn
    if (!tree)return nullptr;
    if (tree->info==x)return tree;
    if (x<tree->info)return findnode(x,tree->left);
    return findnode(x,tree->right);
}

void insertnode(int x,node* &tree){ //logn
    if (!tree){
        tree=new node;
        tree->right=tree->left= nullptr;
        tree->info=x;
    }
    if (x<tree->info)insertnode(x,tree->left);
    if (x>tree->info)insertnode(x,tree->right);
}

void deleteMin(node* &tree, int &min){
    if (tree->left)deleteMin(tree->left,min);
    else{
        min=tree->info; //salvo informazione
        node* aux=tree;
        tree=tree->right; //connetto il padre col sottoalbero destro del min
        delete aux;
    }
}

void deletenode(int x,node* &tree){ //logn
    if (tree){
        if (x<tree->info){
		deletenode(x,tree->left); 
		return;
	}
        if (x>tree->info){
		deletenode(x,tree->right);
		return;
	}
        if (!tree->left){
		node* aux=tree; 
		tree=tree->right;
		delete aux; 
		return;
	}
        if (!tree->right){
		node* aux=tree; 
		tree=tree->left;
		delete aux; return;
	}
        deleteMin(tree->right,tree->info);
    }
}

