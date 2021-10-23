#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};

void helper(Node* root, int& k){
    if(root==NULL){
        return;
    }
    else{
        helper(root->left, k);
        helper(root->right, k);
        k+=root->key;
    }
}

int sumBT(Node* root){
    int sum=0;
    helper(root, sum);
    return sum;
}