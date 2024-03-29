#include<iostream>

using namespace std;

struct node
{
	int key;
	node *left, *right ; 
};
//finding the height of the binary search tree  
int FindHeight(struct node* root)
{
	if (root ==NULL)
		return 0;
	//return -1 if you want to find the no. of edges node no. of the node in the tree 
	return max(FindHeight(root->right), FindHeight(root->left))+1;
		
	
}
//how to create new node 
struct node *newNode(int item)
{
	 node *temp = new node;
	 temp ->key = item;
	 temp ->left = temp->right = NULL;
	 return temp;
	 
}


//how to insert value in node in binary tree 
struct node *insert(struct node * node , int key)
{
	if (node == NULL)
		return newNode(key);
		
	if (key>node->key)
		node->right = insert(node->right, key);
	else if (key<node->key)
		node->left = insert(node->left, key);
	else
		cout<<"node already present in the tree "<<endl;
		
	return node;
}

//to traverse the tree inorder way
void inorder(struct node *root)
{
	if (root != NULL)
	 {
	 	inorder(root->left);
	 	cout<<root->key<<endl;
	 	inorder(root->right);
	 	
	 }

	 
}
struct node * findMin(struct node * temp)
{
	struct node *current = temp;
	while(current->left != NULL)
		current = current->left;
		
	return current;
}

struct node * Delete(struct node* root, int key)
{
	if (root == NULL)return root;
	else if (key<root->key) root->left = Delete(root->left , key);
	else if (key<root->key ) root->right = Delete(root->right, key);
	
	else //key value founded .
	{
		if (root->left == NULL && root->right == NULL)
		{
				delete root; 
		    	root = NULL;
		}
		
		
		else if (root->left == NULL){
			struct node *temp = root ;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL){
			struct node *temp = root;
			root = root->left ;
			delete temp;
		}
		
		else
		{
			struct node *temp = findMin(root->right);
			//struct node *temp = findMax(root->left);
	
			root->key = temp->key;
			root->right = Delete(root->right, temp->key);
			
		}
	}
	return root; 
}

struct node *search(struct node*  root, int key)
{
	if(root == NULL || root->key==key)
		return  root;
	
	else if (root->key>key)
		return search(root->left, key);
	

	return search(root->right, key);
}
int main()
{
	struct node *root = NULL;
	int val;
	while(true)
	{   cout<<"enter a value"<<endl;
		cin>>val;
			if (val == 0000 )
			break;
		
		root = insert(root, val);
		
	
	}
	inorder(root);
//	int key;
//	cout<<"enter the key value to delete from the tree"<<endl;
//	cin>>key;
//	
//	Delete(root,key);
//	cout<<"After deletion "<<endl;
//	inorder(root);
//	cout<<"enter the search value"<<endl;
//	int s;
//	cin>>s;
//	cout<<search(root, s);

  cout<<"Height of the tree is : "<< FindHeight(root);
	return 0;
}

