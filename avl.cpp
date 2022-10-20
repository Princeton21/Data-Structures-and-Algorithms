#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    int height;
} *root;

int height(struct Node *node) {
    if(node == NULL)
        return 0;
    return node -> height;
}

struct Node * createNode(int value) {
    struct Node *tmp = (struct Node *) malloc(sizeof(struct Node));
    tmp -> data = value;
    tmp -> left = NULL;
    tmp -> right = NULL;
    tmp -> height = 1;
    return tmp;
}

int balanceFactor(struct Node *node) {
    if(node == NULL) {
        return 0;
    }
    return (height(node -> left) - height(node -> right));
}

int max(int a, int b) {
    return (a > b)? a : b;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x -> right;
    struct Node *z = y -> left;
    y -> left = x;
    x -> right = z;
    x -> height = max(height(x -> left), height(x -> right));
    y -> height = max(height(y -> right), height(y -> right));
    return y;
}

struct Node *rightRotate(struct Node *x) {
    struct Node *y = x -> left;
    struct Node *z = y -> right;
    y -> right = x;
    x -> left = z;
    y -> height = max(height(y -> right), height(y -> right));
    x -> height = max(height(x -> left), height(x -> right));
    return y;
}

struct Node *insert(struct Node *root, int value) {
    if(root == NULL)
        return createNode(value);
    
    if(value < root -> data) 
        root -> left = insert(root -> left, value);
    else if(value > root -> data) 
        root -> right = insert(root -> right, value);
    else {
        return root;
    }

    root -> height = max(height(root -> left), height(root -> right));
    int balance = balanceFactor(root);

    if(balance > 1 && value < root -> left -> data) 
        return rightRotate(root);
    if(balance < -1 && value > root -> right -> data)
        return leftRotate(root);
    if(balance > 1 && value > root -> left -> data) {
        root -> left = leftRotate(root -> data);
        return rightRotate(root);
    }
    if(balance < -1 && value < root -> right -> data) {
        root -> right = rightRotate(root -> right);
        return leftRotate(root);
    }
    return root;
}

struct Node *minValueNode(struct Node *root) {
    struct Node *q = root;
    while(q != NULL && q -> left != NULL) {
        q = q -> left;
    }
    return q;
}

struct Node *del(struct Node *root, int value) {
    if(root == NULL) 
        return root;
    if(value < root -> data)
        root -> left = del(root -> left, value);
    else if(value > root -> data)
        root -> right = del(root -> data, value);
    else {
        if(root -> left == NULL) {
            struct Node *tmp = root -> left;
            free(root);
            return tmp;
        } else if(root -> right == NULL) {
            struct Node *tmp = root -> left;
            free(root);
            return tmp;
        }
        struct Node *tmp = minValueNode(root -> right);
        root -> data = tmp -> data;
        root -> right = del(root -> right, tmp -> data);
    }

    root -> height = max(height(root -> left), height(root -> right));
    int balance = balanceFactor(root);

    if(balance > 1 && value < root -> left -> data) 
        return rightRotate(root);
    if(balance < -1 && value > root -> right -> data)
        return leftRotate(root);
    if(balance > 1 && value > root -> left -> data) {
        root -> left = leftRotate(root -> data);
        return rightRotate(root);
    }
    if(balance < -1 && value < root -> right -> data) {
        root -> right = rightRotate(root -> right);
        return leftRotate(root);
    }
    return root;
}

void inorder(struct Node *root) {
    if(root != NULL) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

void postorder(struct Node *root) {
    if(root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}

void preorder(struct Node *root) {
    if(root != NULL) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}
