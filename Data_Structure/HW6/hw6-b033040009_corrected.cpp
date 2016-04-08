/*
Author�G���y�� B033040009
Date�GDec. 7, 2015
Purpose:�����@��Ʀr�A��X�Ҧ��X�{���Ƭ��_�Ƥ��Ʀr
*/

#include <iostream>

using namespace std;
int count = 0;
class TreeNode  //Tree���`�I
{
    public:
    int data;
    TreeNode *leftChild;
    TreeNode *rightChild;

    private:
};

class Tree
{
    public:
        TreeNode *root;                 //Tree��Root
        Tree();                         //Constructor
        ~Tree();                        //Destructor
        int Node_count(TreeNode *current);				///�p��Tree���`�@���X��Node 
        void Infix(TreeNode *current, int count);                  //infix traversal �L�X�`�I��Data
        void Infix_l(TreeNode *current, int count);                //infix traversal �L�X�`�I��leftchild
        void Infix_r(TreeNode *current, int count);                //infix traversal �L�X�`�I��rightchild
        TreeNode* Search(Tree *tree, int target);       //�j�M��target�ƭ� �öǦ^���m
        TreeNode* Get_parent(Tree *tree, int target);   //���o�𤺬Y�ӼƭȪ��`�I��parent
        void Insert(Tree *tree, int num);               //�N�ƭ�insert�iBST���A���Y�w�g�s�b�ӼƭȡA�hdelete
        void Delete(Tree *tree, int num);               //�R���Y�ӼƭȪ��`�I

    private:

};

Tree::Tree()
{
    root = new TreeNode;
    root->data = NULL;
    root->leftChild = NULL;
    root->rightChild = NULL;
}

Tree::~Tree(){}

TreeNode* Tree::Search(Tree *tree, int target)
{
    TreeNode *current = tree->root;

    while(current != NULL){
        if(target < current->data)
            current = current->leftChild;
        else if(target > current->data)
            current = current->rightChild;
        else
            return current;
    }
    return NULL;
}

int Tree::Node_count(TreeNode *current){
	if(current != NULL){
        Node_count(current->leftChild);
        if(current->data != NULL)
            ++count;
        Node_count(current->rightChild);
    }
    return count;
}		

void Tree::Infix(TreeNode *current, int count){
    if(current != NULL){
        Infix(current->leftChild, count);
        if(current->data != NULL && count > 1){
        	cout << current->data << " ";
        	count--;
        }
        else if(current->data != NULL && count <= 1)
        	cout << current->data;
        Infix(current->rightChild, count);
    }
    return;
}

void Tree::Infix_l(TreeNode *current, int count){
    if(current != NULL){
        Infix_l(current->leftChild, count);
        if(current->data != NULL  && count > 1)
        {
            if(current->leftChild == NULL)
                cout << "0 ";
            else
                cout << current->leftChild->data << " ";
            count--;
        }
        else if(current->data != NULL && count <= 1)
        {
        	if(current->leftChild == NULL)
                cout << "0 ";
            else
                cout << current->leftChild->data;
        }
        Infix_l(current->rightChild, count);
    }
    return;
}

void Tree::Infix_r(TreeNode *current, int count){
    if(current != NULL){
        /*
		Infix_r(current->leftChild);
        if(current->data != NULL)
        {
            if(current->rightChild == NULL)
                cout << "0 ";
            else
                cout << current->rightChild->data << " ";
        }
        Infix_r(current->rightChild);*/
        Infix_r(current->leftChild, count);
        if(current->data != NULL  && count > 1)
        {
            if(current->rightChild == NULL)
                cout << "0 ";
            else
                cout << current->rightChild->data << " ";
            count--;
        }
        else if(current->data != NULL && count <= 1)
        {
        	if(current->rightChild == NULL)
                cout << "0 ";
            else
                cout << current->rightChild->data;
        }
        Infix_l(current->rightChild, count);
    }
    return;
}


TreeNode* Tree::Get_parent(Tree *tree, int target){
    TreeNode *current = tree->root;
    TreeNode *prev = NULL;

    while(current != NULL && current->data != target){
        prev = current;
        if(target < current->data)
            current = current->leftChild;
        else if(target > current->data)
            current = current->rightChild;
    }
    return prev;
}

void Tree::Insert(Tree *tree, int num)
{
    TreeNode *current, *prev;
    current = tree->root;
    
    TreeNode *newnode = new TreeNode;
    newnode->data = num;
    newnode->leftChild = NULL;
	newnode->rightChild = NULL;

    if(Search(tree, num))              //�P�_��insert���ƭȬO�_�w�g�s�b��𤺡A���Y�s�b�hdelete
    {
        Delete(tree, num);
        //cout << "delete" << endl;
    }


    else
    {
        if(tree->root->data == NULL)      //���J�ƭȨ�root�����p
        {
            tree->root = newnode;
            //cout << "root - insert" << endl;
        }


        while(current != NULL)      //����ninsert�ƭȪ��`�I��m
        {
            prev = current;
            if(num < current->data)
                current = current->leftChild;
            else
                current = current->rightChild;
        }

        if(newnode->data < prev->data)  //insert��leftchild�����p
        {
            prev->leftChild = newnode;
            cout << "insert left " << newnode->data << endl;
        }

        else                            //insert��rightchild�����p
        {
            prev->rightChild = newnode;
            cout << "insert right " << newnode->data << endl;
        }
    }
}



void Tree::Delete(Tree *tree, int num){
    TreeNode *deletenode = Search(tree, num);
    TreeNode *parent = Get_parent(tree, num);


    //�`�I��Leaf Node (�]�A�u��root�����p)
    if(deletenode->leftChild == NULL && deletenode->rightChild == NULL){
        if(deletenode == tree->root)    //�G����u�����,�B�R�����
            tree->root->data = NULL;

        else{
            if(num < parent->data)
                parent->leftChild = NULL;
            else
                parent->rightChild = NULL;
            delete deletenode;
        }
    }

    else{
        //���R����nonleaf node�u���@��son�G�����N��node�R���A�ñN����son�������W�s��
        if(deletenode->leftChild != NULL && deletenode->rightChild == NULL) //�u����son
        {
            if(num < parent->data)
            {
                parent->leftChild = deletenode->leftChild;
            }

            else
            {
                parent->rightChild = deletenode->leftChild;
            }

            delete deletenode;
        }

        else if(deletenode->leftChild == NULL && deletenode->rightChild != NULL)  //�u���kson
        {
            if(num < parent->data)
            {
                parent->leftChild = deletenode->rightChild;
            }

            else
            {
                parent->rightChild = deletenode->rightChild;
            }

            delete deletenode;
        }

        //���R����nonleaf node�����son�G���]���R����node��p�A�h��p��right subtree���A�̾a����node q�]�Yp��inorder successor�^�A
        //�Nq������m��p����m�A�ӱNq��son�]q�u�|��right son�^�V�W�s���_�ӧY�i
        else
        {
            TreeNode *q = deletenode->rightChild;
            TreeNode *prev;
            while(q->leftChild != NULL)
            {
                prev = q;
                q = q->leftChild;
            }

            if(deletenode->leftChild != q)          //�@�뱡�p
            q->leftChild = deletenode->leftChild;
            else                                    //���Yinorder successor�N�Odelete�ؼи`�I��leftchild�����p
            q->leftChild = NULL;                    //inorder successor�N���|��leftchild
            q->rightChild = deletenode->rightChild;



            if(q->rightChild != NULL)
                prev->leftChild = q->rightChild;

            if(deletenode == tree->root)
                root = q;
                
            delete deletenode;
        }
    }

}



int main()
{
	
    int n;
    while(cin >> n)
	{
		count = 0;
		Tree tree;
	    tree.Insert(&tree, n);
		while(cin >> n)
	    {
	        if(n == -1)
	        break;
	        tree.Insert(&tree, n);
	    }
		
	    //cout << "node: ";
	    //tree.Node_count(tree.root);
		//cout << "Node_count :" << count << endl; 
		//cout << tree.root->data << " " << tree.root->leftChild->data << " " << tree.root->rightChild->data << " " <<  tree.root->rightChild->rightChild->data;  
	    tree.Infix(tree.root, 10);
	    //cout << tree.root->leftChild->data;
	    /*
	    cout << tree.root->data << endl;
		cout <<tree.root->rightChild->data<< endl;
		cout << tree.root->rightChild->leftChild->data<< endl;
		cout << tree.root->rightChild->rightChild->data<< endl;
		cout << tree.root->rightChild->rightChild->leftChild->data<< endl;
		cout << tree.root->rightChild->rightChild->leftChild->rightChild->data<< endl;
		cout << endl;
		*/
	    /*
		cout << "left: ";
	    tree.Infix_l(tree.root, 5);
	    cout << endl;
	    cout << "right: ";
	    tree.Infix_r(tree.root, 5);
	    cout << endl;
	    cout << endl;*/
	}
    system("PAUSE");
}


