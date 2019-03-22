#include<iostream>
using namespace std;

class Node
{	
	public:	
		int data;
		Node* left;//pointers to point left child
		Node* right;//pointers to point right child
		
		//default constructor
		Node(int value)
		{
			left=NULL;//initializing the value to null
			right=NULL;//initializing the value to null
			data=value;
		}
};

class BiST
	{	
	public:	
		Node* root;
		//default constructor
		BiST()
		{
			root=NULL;
		}
		
		//insert()
		void insert(int value)
		{
			insert2(root,value);
		}
		void insert2(Node* curr, int value)
		{
			//base case 
			if(root==NULL)
			{
				root = new Node(value);
			}
			//else compare the data
			else if(value<curr->data)
			{
				//If left is null, insert it.
				if(curr->left==NULL) curr->left = new Node(value); 
				//else move left by calling insert2 by recursion
				else insert2(curr->left, value);
			}
			else{
				//If right is null, insert it.
				if(curr->right==NULL) curr->right = new Node(value); 
				//else move right by calling insert2 by recursion
				else insert2(curr->right, value);
			}
		}
		
		//display()
		void display(){
			cout<<"printing traversal in inorder";
			cout<<endl;
    		display2(root);
    		cout<<endl<<endl;
		    cout<<"printing traversal in preorder";
		    cout<<endl;
		    display3(root);
		    cout<<endl<<endl;
			cout<<"printing traversal in postorder";
			cout<<endl;
		    display4(root);
			cout<<endl<<endl;	
		}
		//inorder 
		void display2(Node* curr){
			//Base condition
			if(curr==NULL) return;
			//display left
			display2(curr->left);
			//Display current
			cout << curr->data <<",";
			//display right
			display2(curr->right);
		}
		//preorder
		void display3(Node* curr){
			//Base condition
			if(curr==NULL) return;
			//Display current
			cout << curr->data <<",";
			//display left
			display3(curr->left);
			//display right
			display3(curr->right);
		}
		//postorder
		void display4(Node* curr){
			//Base condition
			if(curr==NULL) return;
			//display left
			display4(curr->left);
			//display right
			display4(curr->right);
			//Display current
			cout << curr->data <<",";
		}
		
		void displayfancy()
		{
			displayfancy2(root,0);
		}
		
		void displayfancy2 (Node* curr,int spaces)
		{
			// to get the right end value
			if (curr==NULL) return;
			//display right
			displayfancy2(curr->right,spaces+1);
			//inceraese number of spaces
			for(int i=0;i<5*spaces;i++)
			{
				cout<<" ";
			}
			//print req spaces
			//display curr
			cout<<curr->data<<endl;
			//display left
			displayfancy2(curr->left,spaces+1);
			
			/*sample output
					16
				14
					12
			10
					8
				6
					4
			*/
		}
		
		//search()
		Node* search(int value)
		{
			search2(value, root);
		}
		Node* search2(int value, Node* curr)
		{
			//match
			if(value==curr->data) return curr;
			//smaller
			else if(value<curr->data) return search2(value,curr->left);
			//larger
			else if(value>curr->data) return search2(value,curr->right);
			//not found
			else{
				return NULL;
			}
		}

};

int main(){
	BiST b1;
	
	b1.insert(10);
	b1.insert(14);
	b1.insert(6);
	b1.insert(4);
	b1.insert(8);
	b1.insert(12);
	b1.insert(16);
	
	b1.display();
	
	b1.displayfancy();
	
	if(b1.search(10) != NULL){
        cout << endl << b1.search(10)->data << " found." << endl;
    }
    
    
	return 0;
}