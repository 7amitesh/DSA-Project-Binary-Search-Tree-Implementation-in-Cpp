#include <iostream>

using namespace std;

#define endl '\n'

struct Node
{
    int val;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *newNode(int val)
{
    struct Node *root = new Node;
    root->val = val;
    root->right = NULL;
    root->left = NULL;
    return root;
}

// Function to insert a value into the BST
struct Node *insert(Node *root, int insertVal)
{
    if (root == NULL)
    {
        return newNode(insertVal);
    }
    if (root->val > insertVal)
    {
        root->left = insert(root->left, insertVal);
    }
    else if (root->val < insertVal)
    {
        root->right = insert(root->right, insertVal);
    }
    return root;
}

// Function to search for a value in the BST
bool search(Node *root, int searchVal)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->val == searchVal)
    {
        return true;
    }
    else if (root->val > searchVal)
    {
        return search(root->left, searchVal);
    }
    else
    {
        return search(root->right, searchVal);
    }
}

// Function to delete a node from the BST
struct Node *deleteNode(Node *root, int deleteVal)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val > deleteVal)
    {
        root->left = deleteNode(root->left, deleteVal);
    }
    else if (root->val < deleteVal)
    {
        root->right = deleteNode(root->right, deleteVal);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *parent = root;
        Node *y = root->right;
        while (y->left != NULL)
        {
            parent = y;
            y = y->left;
        }

        root->val = y->val;

        if (parent->left == y)
        {
            parent->left = y->right;
        }
        else
        {
            parent->right = y->right;
        }

        delete y;
    }
    return root;
}

// Inorder traversal of the BST
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

// Preorder traversal of the BST
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal of the BST
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}

// Free the memory allocated for the BST
void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
   // cout << "Enter the number of nodes "<<endl;
    cin >> n;

    struct Node *root = NULL;

    //cout << "Enter the node values " << endl;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder traversal:" << endl;
    inorder(root);
    cout << endl;

    cout << "Preorder traversal:" << endl;
    preorder(root);
    cout << endl;

    cout << "Postorder traversal:" << endl;
    postorder(root);
    cout << endl;

    int del;
   // cout << "Enter the value to delete " << endl;
    cin >> del;

    root = deleteNode(root, del);

    cout << "After deleting: " << del << endl;

    cout << "Inorder traversal:" << endl;
    inorder(root);
    cout << endl;

    cout << "Preorder traversal:" << endl;
    preorder(root);
    cout << endl;

    cout << "Postorder traversal:" << endl;
    postorder(root);
    cout << endl;

    // Free the allocated memory
    freeTree(root);

    return 0;
}
