#include <iostream>
using namespace std;

struct node
{
    int data;
    node*left,*right;
    node(int value)
    {
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

void display(node* root) 
{
    if (root == nullptr)
        return;

    cout << root->data << " "; 
    display(root->left);
    display(root->right);
}


node* insert(node* root, int value)
{
    if (root == nullptr)
    {
        return new node(value);
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(node* root)
{
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int findMin(node* root)
{
    if (root == nullptr)
    {
        cout << "Tree is empty!" << endl;
        return -1;
    }

    node* current = root;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current->data;
}

 bool search(node* root, int key)
{
    if (root == nullptr)
        return false;

    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int longestPath(node* root)
{
    if (root == nullptr)
        return 0;

    int leftDepth = longestPath(root->left);
    int rightDepth = longestPath(root->right);

    return max(leftDepth, rightDepth) + 1;
}

int main()
{
    int arr[] = {60, 40, 30, 50, 70, 65, 80}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    node* root = nullptr;

    
    cout << "Tree structure: ";
    display(root);


    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Minimum value in the BST: " << findMin(root) << endl;

    int newValue;
    cout << "Enter a new element to insert into the BST: ";
    cin >> newValue;

    root = insert(root, newValue);

    cout << "Tree after insertion (inorder): ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter a value to search in the BST: ";
    cin >> key;

    if (search(root, key))
    cout << key << " is found in the BST." << endl;
    else
    cout << key << " is NOT found in the BST." << endl;

    cout << "Longest path (number of nodes): " << longestPath(root) << endl;
   
    return 0;
}
