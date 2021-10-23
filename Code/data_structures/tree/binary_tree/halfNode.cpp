#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};



void recur(Node* root, vector<int>& v){
    if(!root->left and !root->right){
        v.push_back(root->key);
        return;
    }
    if(root->left and root->right){
        recur(root->left,v);
        v.push_back(root->key);
        recur(root->right,v);
    }
    else if(root->left){
        root=root->left;
        recur(root, v);
    }
    else if(root->right){
        root=root->right;
        recur(root, v);
    }
}
vector<int> removeHalfNodes(Node *root){
   vector<int> v;
   recur(root,v);
   return v;
   
}