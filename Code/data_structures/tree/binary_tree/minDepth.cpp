#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};


//O(1) space and O(n) time
void recur(Node* root, int depth, int& minD){
    if(root == NULL){
        if(minD == -1){
            minD = depth;
        }
        else{
            minD = min(minD, depth);
        }
        return;
    }
    depth++;
    recur(root->left, depth, minD);
    recur(root->right, depth, minD);
}

int minDepthRecur(Node *root) {
    int minD = -1;
    int depth = 0;
    recur(root,depth,minD);
    return minD;    
}


//Iterative Solution with O(n) space and O(n) time (handling each node only once)
int minDepthIter(Node *root) {
    queue<Node*> q;
    int minD=INT_MAX;
    q.push(root);
    int depth = 1;
    while(!q.empty()){
        int s = q.size();
        while(s--){
            Node* front = q.front();
            q.pop();
            if(front->left==NULL and front->right==NULL){
                minD = min(minD, depth);
            }
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        depth++;
    }
    return minD;
}