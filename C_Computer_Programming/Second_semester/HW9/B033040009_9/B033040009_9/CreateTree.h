#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct node
{
    char data;
    struct node *left,*right;
}Node;

bool isop(char c)
{
	return c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='('||c==')';
}

class toTree
{
private:
	string prefix;
	vector<Node*> Stack;
public:
	toTree()
	{
		prefix = "";
		Stack.resize(10);
	}
	
	Node* maketree(string s)
	{
		int j=0;
		for(int i=0;i<(int)s.size();i++)
		{
			if(isop(s[i]))
			{
				Node *ptr = new Node;
				ptr->data = s[i];
				ptr->right = Stack[--j];
				Stack[j] = nullptr;
				ptr->left = Stack[--j];
				Stack[j] = nullptr;
				Stack[j++] = ptr;
			}
			else
			{
				Node *ptr = new Node;
				ptr->data = s[i];
				ptr->left = ptr->right = nullptr;
				Stack[j++] = ptr;
			}
		}
		return Stack[--j];
	}

	void PreOrder(Node *root) 
	{ 
		if ( root != nullptr ) 
		{ 
			prefix += root->data;
			PreOrder(root->left);   
			PreOrder(root->right);   
		}
	}

	string getPrefix()
	{
		return prefix;
	}
};