#include <iostream>
#include <cstdlib>
using namespace std;
class BinarySearchTree
{
private:
    struct tree_node
    {
        tree_node *left;
        tree_node *right;
        int data;
    };

public:
    tree_node *root;
    BinarySearchTree()
    {
        root = nullptr;
    }
    bool isEmpty() const { return root == NULL; }
    void print_inorder();
    void inorder(tree_node *);
    void print_preorder();
    void preorder(tree_node *);
    void print_postorder();
    void postorder(tree_node *);
    void insert(int);
    tree_node *remove(int d, tree_node *node)
    {
        if (node == nullptr)
            return node;
        if (d < node->data)
            node->left = remove(d, node->left);
        else if (d > node->data)
            node->right = remove(d, node->right);
        else
        {
            // Node to be deleted is found
            // Node with only one child or no child
            if (node->left == nullptr)
            {
                tree_node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                tree_node *temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            tree_node *temp = minValueNode(node->right);
            // Copy the inorder successor's content to this node
            node->data = temp->data;
            // Delete the inorder successor
            node->right = remove(temp->data, node->right);
        }
        return node;
    }
    tree_node *minValueNode(tree_node *node)
    {
        tree_node *current = node;
        // Find the leftmost leaf
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
};
void BinarySearchTree::insert(int d)
{
    // Create a new node and set its data
    tree_node *newNode = new tree_node;
    newNode->data = d;
    newNode->left = nullptr;
    newNode->right = nullptr;
    // If the tree is empty, make this node the root
    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    // Traverse the tree to find the correct position to insert
    tree_node *current = root;
    while (true)
    {
        if (d < current->data)
        {
            if (current->left == nullptr)
            {
                current->left = newNode;
                break;
            }
            current = current->left;
        }
        else
        {
            if (current->right == nullptr)
            {
                current->right = newNode;
                break;
            }
            current = current->right;
        }
    }
}
void BinarySearchTree::print_inorder()
{
    inorder(root);
    cout << endl;
}
void BinarySearchTree::inorder(tree_node *p)
{
    if (p != nullptr)
    {
        inorder(p->left);
        cout << p->data << "\t";
        inorder(p->right);
    }
}
void BinarySearchTree::print_preorder()
{
    preorder(root);
    cout << endl;
}
void BinarySearchTree::preorder(tree_node *p)
{
    if (p != nullptr)
    {
        cout << p->data << "\t";
        preorder(p->left);
        preorder(p->right);
    }
}
void BinarySearchTree::print_postorder()
{
    postorder(root);
    cout << endl;
}
void BinarySearchTree::postorder(tree_node *p)
{
    if (p != nullptr)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << "\t";
    }
}
void insertIntoTree(BinarySearchTree *b)
{
    cout << "How many elements do you want to insert?" << endl;
    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element # " << i << ":"
             << "\t";
        cin >> val;
        b->insert(val);
    }
}
int main()
{
    BinarySearchTree b;
    while (true)
    {
        int menuOption = 0;
        while (menuOption > 6 || menuOption < 1) // This loop can exit program
        {
            cout << "\t-----------------------------------------" << endl;
            cout << "\t\tBinary Search Tree Menu" << endl;
            cout << "\t-----------------------------------------" << endl;
            cout << "\t1. Insert New Element" << endl;
            cout << "\t2. In-Order Traversal" << endl;
            cout << "\t3. Pre-Order Traversal" << endl;
            cout << "\t4. Post-Order Traversal" << endl;
            cout << "\t5. Delete an Element" << endl;
            cout << "\t6. Exit" << endl;
            cout << "\t-----------------------------------------" << endl;
            cout << "Enter your choice (1-6): ";
            cin >> menuOption;
            if (menuOption == 6)
            {
                return 0; // Exiting
            }
            switch (menuOption)
            {
            case 1:
            {
                insertIntoTree(&b);
                break;
            }
            case 2:
            {
                b.print_inorder();
                break;
            }
            case 3:
            {
                b.print_preorder();
                break;
            }
            case 4:
            {
                b.print_postorder();
                break;
            }
            case 5:
            {
                cout << "Enter element to remove:" << endl;
                int elem;
                cin >> elem;
                b.remove(elem, b.root);
            }
            }
        }
    }
    getchar();
}