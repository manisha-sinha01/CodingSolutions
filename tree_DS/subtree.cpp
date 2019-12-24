/* O(n2) solution for checking subtree of one tree in another tree
    Check if a binary tree is subtree of another binary tree | Set 1
    Given two binary trees, check if the first tree is subtree of the second one. 
    A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T. 
    The subtree corresponding to the root node is the entire tree; the subtree corresponding to 
    any other node is called a proper subtree.
    This includes full traversal of both the trees , hence 
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* right;
        Node* left;
};

Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

bool isIdentical(Node* T, Node* S){
    
    if( T == NULL && S == NULL )
        return true;
    if( T == NULL || S == NULL )
        return false;
    return ( T->data == S->data ||
            isIdentical(T->left,S->left) ||
            isIdentical(T->right,S->right));
    
}

bool isSubtree(Node* T, Node* S)
{
    if(T == NULL)
        return false;
    
    if(S == NULL)
        return true;
    
    if(isIdentical(T,S))
        return true;

    return (isSubtree(T->left,S) || isSubtree(T->right,S));

}

int main(){

    //TREE 1  
    /* Construct the following tree  
            26  
            / \  
        10 3  
        / \ \  
    4 6 3  
    \  
        30  
    */
    Node *T = newNode(26);  
    T->right         = newNode(3);  
    T->right->right = newNode(3);  
    T->left         = newNode(10);  
    T->left->left     = newNode(4);  
    T->left->left->right = newNode(30);  
    T->left->right     = newNode(6);  
  
    // TREE 2  
    /* Construct the following tree  
        10  
        / \  
    4 6  
    \  
        30  
    */
    Node *S = newNode(10);  
    S->right     = newNode(6);  
    S->left     = newNode(4);  
    S->left->right = newNode(30); 

    if(isSubtree(T,S))
    {
        cout << "A subtree exists" << endl;
    }else
    {
        cout << "No subtree exists" << endl;
    }
    return 0;
}



