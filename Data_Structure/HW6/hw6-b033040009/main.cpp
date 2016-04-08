/*
Author：蔡宜勳 B033040009
Date：Dec. 7, 2015
Purpose:給予一串數字，找出所有出現次數為奇數之數字
*/

#include <iostream>

using namespace std;

class TreeNode  //Tree的節點
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
        TreeNode *root;                 //Tree的Root
        Tree();                         //Constructor
        ~Tree();                        //Destructor
        void Infix(TreeNode *current);                  //infix traversal 印出節點的Data
        void Infix_l(TreeNode *current);                //infix traversal 印出節點的leftchild
        void Infix_r(TreeNode *current);                //infix traversal 印出節點的rightchild
        TreeNode* Search(Tree *tree, int target);       //搜尋樹內target數值 並傳回其位置
        TreeNode* Get_parent(Tree *tree, int target);   //取得樹內某個數值的節點的parent
        void Insert(Tree *tree, int num);               //將數值insert進BST內，假若已經存在該數值，則delete
        void Delete(Tree *tree, int num);               //刪除某個數值的節點

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

void Tree::Infix(TreeNode *current){
    if(current != NULL){
        Infix(current->leftChild);
        if(current->data != NULL)
            cout << current->data << " ";
        Infix(current->rightChild);
    }
    return;
}

void Tree::Infix_l(TreeNode *current){
    if(current != NULL){
        Infix_l(current->leftChild);
        if(current->data != NULL)
        {
            if(current->leftChild == NULL)
                cout << "0 ";
            else
                cout << current->leftChild->data << " ";
        }
        Infix_l(current->rightChild);
    }
    return;
}

void Tree::Infix_r(TreeNode *current){
    if(current != NULL){
        Infix_r(current->leftChild);
        if(current->data != NULL)
        {
            if(current->rightChild == NULL)
                cout << "0 ";
            else
                cout << current->rightChild->data << " ";
        }
        Infix_r(current->rightChild);
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
    newnode->leftChild = newnode->rightChild = NULL;


    if(Search(tree, num))              //判斷欲insert的數值是否已經存在於樹內，假若存在則delete
    {
        Delete(tree, num);
        //cout << "delete" << endl;
    }


    else
    {
        if(tree->root == NULL)      //插入數值到root的情況
        {
            tree->root = newnode;
            //cout << "root - insert" << endl;
        }


        while(current != NULL)      //走到要insert數值的節點位置
        {
            prev = current;
            if(newnode->data < current->data)
                current = current->leftChild;
            else
                current = current->rightChild;
        }

        if(newnode->data < prev->data)  //insert到leftchild的情況
        {
            prev->leftChild = newnode;
            //cout << "insert left " << newnode->data << endl;
        }

        else                            //insert到rightchild的情況
        {
            prev->rightChild = newnode;
            //cout << "insert right " << newnode->data << endl;
        }
    }
}



void Tree::Delete(Tree *tree, int num){
    TreeNode *deletenode = Search(tree, num);
    TreeNode *parent = Get_parent(tree, num);


    //節點為Leaf Node (包括只有root的情況)
    if(deletenode->leftChild == NULL && deletenode->rightChild == NULL){
        if(deletenode == tree->root)    //二元樹只有樹根,且刪除樹根
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
        //欲刪除的nonleaf node只有一個son：直接將該node刪除，並將它的son直接往上連接
        if(deletenode->leftChild != NULL && deletenode->rightChild == NULL) //只有左son
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

        else if(deletenode->leftChild == NULL && deletenode->rightChild != NULL)  //只有右son
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

        //欲刪除的nonleaf node有兩個son：假設欲刪除的node為p，則找p的right subtree中，最靠左的node q（即p之inorder successor），
        //將q直接放置於p之位置，而將q的son（q只會有right son）向上連接起來即可
        else
        {
            TreeNode *q = deletenode->rightChild;
            TreeNode *prev;
            while(q->leftChild != NULL)
            {
                prev = q;
                q = q->leftChild;
            }

            if(deletenode->leftChild != q)          //一般情況
            q->leftChild = deletenode->leftChild;
            else                                    //假若inorder successor就是delete目標節點的leftchild的情況
            q->leftChild = NULL;                    //inorder successor將不會有leftchild
            q->rightChild = deletenode->rightChild;



            if(q->rightChild != NULL)
                prev->leftChild = q->rightChild;

            if(deletenode == tree->root)
                root = q;
        }
    }

}



int main()
{
    int n;
    Tree tree;
    while(cin >> n)
    {
        if(n == -1)
        break;
        tree.Insert(&tree, n);
    }

    cout << "node: ";
    tree.Infix(tree.root);
    cout << endl;
    cout << "left: ";
    tree.Infix_l(tree.root);
    cout << endl;
    cout << "right: ";
    tree.Infix_r(tree.root);
    cout << endl;
}


