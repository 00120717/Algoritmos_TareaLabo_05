#include <stdio.h>
#include <stdlib.h>
struct node{int key;
struct node *left, *right;};
// A utility function to create a new BST node
struct node *newNode(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}



/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key){
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);
	/* Otherwise, recur down the tree */
	if (key < node->key)
	node->left = insert(node->left, key);
	else if (key > node->key)
	node->right = insert(node->right, key);
	/* return the (unchanged) node pointer */
	return node;
}


// A utility function to do inorder traversal of BST
void inorder(struct node *root){

	if (root != NULL){
	inorder(root->left);
	printf("%d \n", root->key);
	inorder(root->right);
}
}

// A utility function to do preorder traversal of BST
void preorder(struct node *root){

	if (root != NULL){
	printf("%d \n", root->key);
	preorder(root->left);
	preorder(root->right);

	}
}

/*************  TAREA LABO 5****************/
// A utility function to do postorder traversal of BST
void postorder(struct node *root){

	if (root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d \n", root->key);
}
}

//Funcion Borrar
struct node* borrar(struct node* nodo, int dato){

	if(nodo->key == dato ){
		if(nodo->right == NULL && nodo->left == NULL){
		struct node* temp = nodo;
		free(temp);
		return NULL;
	}
	if(nodo->right == NULL && nodo->left!=NULL){
		struct node* temp = nodo->left;
		free(nodo);
		return temp;
	}
	if(nodo->right != NULL && nodo->left==NULL){
		struct node* temp = nodo->right;
		free(nodo);
		return temp;
	}
	if(nodo->right != NULL && nodo->left!=NULL){
		struct node* templ = nodo->left;
		struct node* tempr = nodo->right;
		
		if(templ->key>tempr->key){
			templ->right = nodo->right;
			free(nodo);
			return templ;
		}else{
			tempr->left = nodo->left;
			free(nodo);
			return tempr;
		}	
	}
	}

	if(dato < nodo->key)
		nodo->left = borrar(nodo->left,dato);

	else if(dato>nodo->key)
		nodo->right = borrar(nodo->right,dato);

	return nodo;
}


int main(){
	/* Let us create following BST
	50
	/ \
	30 70
	/ \ / \
	20 40 60 80
	*/
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	// print inoder traversal of the BST
	printf("InOrder\n");
	inorder(root);
	printf("\n");
	printf("PreOrder\n");
	preorder(root);
	printf("\n");
	printf("PostOrder\n");
	postorder(root);
	printf("\n Eliminando dato (30)\n");	
	
	borrar(root,30);
	printf("\nInOrder\n");
	preorder(root);
	return 0;


}
