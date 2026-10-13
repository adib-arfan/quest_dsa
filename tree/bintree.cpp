#include <bits/stdc++.h>
using namespace std;

class node
{
    public:

    int data;
    node *left , *right;

    node(int x) : data(x)
    {
        left = right = nullptr;
    }
};

    node* create()
    {
        int x;
        cin >> x;
        
        if(x == -1)
           return nullptr;

        node* new_node =  new node(x);
        

        new_node->left = create();
        new_node->right = create();

        return new_node;
    }


    void preorder(node* root)
    {
        if(root == nullptr)
           return;

        cout <<  root->data << " ";

        preorder(root->left);
        preorder(root->right);
    }


    void inorder(node* root)
    {
         if(root == nullptr)
           return;

        inorder(root->left);
        cout <<  root->data << " ";
        inorder(root->right);

    }



    
    void postorder(node* root)
    {
         if(root == nullptr)
           return;

        postorder(root->left);
        
        postorder(root->right);
        cout <<  root->data << " ";

    }

int main()
{
    node* root;

    root = create();

    preorder(root);
    
    cout << "\n\n";

    inorder(root);

    cout << "\n\n";

    postorder(root);
    
}


