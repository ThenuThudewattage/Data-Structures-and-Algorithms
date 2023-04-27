#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

struct node* newnode(int item){
    struct node* nodeTo = (struct node*)malloc(sizeof(struct node));
    nodeTo->key = item;
    nodeTo->left = NULL;
    nodeTo->right = NULL;
    return nodeTo;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL)
    return;
  traverseInOrder(root -> left);
  cout << root -> key << " ";
  traverseInOrder(root -> right);
}

// Insert a node
struct node *insertnode(struct node *node, int key) {
    if (node == NULL){
      return newnode(key);
    }    
    if (key < node->key)
        node->left = insertnode(node->left, key);
    else
        node->right = insertnode(node->right, key);
 
    return node;
};

struct node* findMin(struct node* node){ //to find the minimum valued leaf
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current; 
}
 
// Deleting a node
struct node *deletenode(struct node *root, int key) {
    if (root == NULL) //for basic base case conditions
        return root;
 
    if (root->key > key) {
        root->left = deletenode(root->left, key);
        return root;
    }
    else if (root->key < key) {
        root->right = deletenode(root->right, key);
        return root;
    }

    if (root->left == NULL) {
        node* nodeTo = root->right;
        delete root;
        return nodeTo;
    }
    else if (root->right == NULL) {
        node* nodeTo = root->left;
        delete root;
        return nodeTo;
    }
    else {
        node* preParent = root;
        node* pre = root->right;
        findMin(pre);
        if (preParent != root)
            preParent->left = pre->right;
        else
            preParent->right = pre->right;

        root->key = pre->key;
        delete pre;
        return root;
    }
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertnode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deletenode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}