#include<bits/stdc++.h> 
using namespace std; 
  
class Node  
{  
    public: 
    int key;  
    Node *lc;  
    Node *rc;  
    int height;  
};  
int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}   
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
Node* newNode(int key)  
{  
    Node* node = new Node(); 
    node->key = key;  
    node->lc = NULL;  
    node->rc = NULL;  
    node->height = 1;
    return(node);  
}  
 
Node *rcRotate(Node *y)  
{  
    Node *x = y->lc;  
    Node *T2 = x->rc;  
  
    x->rc = y;  
    y->lc = T2;  
  
    y->height = max(height(y->lc), height(y->rc)) + 1;  
    x->height = max(height(x->lc), height(x->rc)) + 1;  
  
    return x;  
}  
    
Node *leftRotate(Node *x)  
{  
    Node *y = x->rc;  
    Node *T2 = y->lc;  
  
    y->lc = x;  
    x->rc = T2;  
  
    x->height = max(height(x->lc),height(x->rc)) + 1;  
    y->height = max(height(y->lc),height(y->rc)) + 1;  
  
    return y;  
}  
  
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->lc) - height(N->rc);  
}  
 
Node* insert(Node* node, int key)  
{  
    if (node == NULL)  
        return(newNode(key));  
  
    if (key < node->key)  
        node->lc = insert(node->lc, key);  
    else if (key > node->key)  
        node->rc = insert(node->rc, key);  
    else   
        return node;  
  
    node->height = 1 + max(height(node->lc),height(node->rc));  

    int balance = getBalance(node);   
  
    if (balance > 1 && key < node->lc->key)  
        return rcRotate(node);  
  
    if (balance < -1 && key > node->rc->key)  
        return leftRotate(node);  
  
    if (balance > 1 && key > node->lc->key)  
    {  
        node->lc = leftRotate(node->lc);  
        return rcRotate(node);  
    }  
  
    if (balance < -1 && key < node->rc->key)  
    {  
        node->rc = rcRotate(node->rc);  
        return leftRotate(node);  
    }  
  
    return node;  
}  
void inorder(Node *root)  
{  
    if(root != NULL)  
    {  
        inorder(root->lc); 
        cout << root->key << " "; 
        inorder(root->rc);  
    }  
}  
  
int main()  
{  
    Node *root = NULL;  

    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
    cout << "Inorder traversal of the "
            "constructed AVL tree is \n";  
    inorder(root);  
      
    return 0;  
}  
  