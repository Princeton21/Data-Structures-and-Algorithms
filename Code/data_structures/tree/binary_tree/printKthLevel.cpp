#include <bits/stdc++.h>
using namespace std;
 

struct Node {
    int key;
    Node* left, *right;
};

//Recusive Solution no extra space
void recur(Node* root, int k, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }
    if(level == k){
        ans.push_back(root->key);
        return;
    }
    recur(root->left, k, ans, level+1);
    recur(root->right, k, ans, level+1);
}

vector<int> printKthLevelRecur(Node* root, int k){
    vector<int> ans;
    recur(root, k, ans,0);
    return ans;
}


//Iterative Solution with O(n) space and O(n) time (handling each node only once)
vector<int> printKthLevelIter(Node* root, int k){
    queue<Node*> q;
    if(root) q.push(root);
    int level=0;
    vector<int> atK;
    while (!q.empty()){
        int s = q.size();
        while(s--){
            Node* front = q.front();
            q.pop();
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        level++;
        if(level==k){
            while(!q.empty()){
                atK.push_back(q.front()->key);
                q.pop();
            }
        }
    }
    return atK;
}
