/*O(n) solution for checking subtree of one tree in another tree
    Check if a binary tree is subtree of another binary tree | Set 1
    Given two binary trees, check if the first tree is subtree of the second one. 
    A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T. 
    The subtree corresponding to the root node is the entire tree; the subtree corresponding to 
    any other node is called a proper subtree.
    This includes using preorder/postorder and inorder to check if there
    exist a substring of the subtree in the main tree. If exists then true
    else false 
*/
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void storeInorder(Node* root, char* arr, int &i){
    if(root == NULL)
    {
        arr[i++] = '*';
        return;
    }
    storeInorder(root->left, arr,i);
    arr[i++] = root->data;
    storeInorder(root->right, arr,i);
}

void storePreOrder(Node* root, char* arr, int &i){
    if(root == NULL)
    {
        arr[i++] = '*';
        return;
    }
    arr[i++] = root->data;
    storeInorder(root->left, arr,i);
    storeInorder(root->right, arr,i);
}

bool isSubtree(Node* T, Node* S)
{
    if(T == NULL && S == NULL)
        return true;
    
    if(T == NULL || S == NULL)
        return false;
    
    char inOrT[MAX], inPrT[MAX], inOrS[MAX], inPrS[MAX];
    int m=0,n=0;
    storeInorder(T, inOrT, m);
    storeInorder(S, inOrS, n);
    inOrT[m] = '\0';
    inOrS[n] = '\0';

    if(strstr(inOrT,inOrS) == NULL)
        return false;

    m=0,n=0;
    storePreOrder(T, inPrT, m);
    storePreOrder(S, inPrS, n);
    inPrT[m] = '\0';
    inPrS[n] = '\0';

    if(strstr(inPrT,inPrS) == NULL)
        return false;
    return true;
}

int main(){

    Node* T = newNode('a'); 
    T->left = newNode('b'); 
    T->right = newNode('d'); 
    T->left->left = newNode('c'); 
    T->right->right = newNode('e'); 
  
    Node* S = newNode('a'); 
    S->left = newNode('b'); 
    S->left->left = newNode('c'); 
    S->right = newNode('d');

    if(isSubtree(T,S))
    {
        cout << "A subtree exists" << endl;
    }else
    {
        cout << "No subtree exists" << endl;
    }
    return 0;
    
}
