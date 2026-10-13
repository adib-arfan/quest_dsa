#include<bits/stdc++.h>
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

node* insert(node *root , int val)
{
    if(root == nullptr)
      return new node(val);

    if(val < root->data)
    {
        root->left = insert(root->left , val);
    }

    else
    {
        root->right = insert(root->right , val);
    }

    return root;  
}


 void inorder(node* root)
    {
         if(root == nullptr)
           return;

        inorder(root->left);
        cout <<  root->data << " ";
        inorder(root->right);

    }


    bool search(node* root , int key)
    {
        if(root == nullptr)
           return false;

        else if(root->data == key)
           return true;
           
        else if(root->data > key)
           return search(root->left , key);
        else 
           return search(root->right , key);
    }


   
  node* get_inorder_successor(node* root)
  {
    while(root != nullptr && root->left != nullptr)
        root = root->left ;

    return root;
  }


  node* delete_node(node *root , int key)
  {
      if(root == nullptr)
       return nullptr;


      if(key < root->data)
         root->left = delete_node(root->left , key);
      else if(key > root->data)
         root->right = delete_node(root->right , key);

      else
      {
        if(root->right == nullptr)
          {
            node* temp = root->left;
            delete root;
            return temp;
          }

        else if(root->left == nullptr)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        node* inorder_successor = get_inorder_successor(root->right);
        root->data = inorder_successor->data;


        root->right = delete_node(root , inorder_successor->data);

      }

      return root;
  }


  vector<int> tree2vector(node *root)
  {
      queue<node*> q;
      vector<int> ara;

      q.push(root);

      while(!q.empty())
      {
        node* temp ;

        temp = q.front();
        q.pop();

        ara.push_back(temp->data);

        if(temp->left)
           q.push(temp->left);
        if(temp->right)
           q.push(temp->right);
      }

      return ara;
  }





int main()
{

    node* root = nullptr;
    vector<int> ara = {3 , 2, 1, 5, 6, 4};

    vector<int> arrayRep;



    for(int v : ara)
    {
       root = insert(root , v);
    }



    arrayRep = tree2vector(root);

    for(int v : arrayRep)
       cout << v  << " ";


    inorder(root);
     
    cout << "\n\n\n";
      
    if(search(root , 7))
       cout << "7 is in the tree\n";
    else 
       cout << "7 is not in the tree\n";


       root = delete_node(root , 4);

       inorder(root);
}

