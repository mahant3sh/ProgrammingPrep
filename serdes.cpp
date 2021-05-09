/* Program to serialize and deserialize a binary tree
 * Compile: g++ --std=c++11 serdes.cpp
 * Output:
 * CLI>$ ./a.out
 * Serialized output: 1 2 4 X X 5 X X 3 X 6 X X
 * TEST ######
 * Serialized output: 1 2 4 X X 5 X X 3 X 6 X X
 * CLI>$
 */

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    string value;

    TreeNode(string x) {
        left = NULL;
        right = NULL;
        value = x;
    }
};

string serialize(TreeNode* root) {
    if(root == NULL) {
        return "X "; // space is important (separator)
    }
    string leftSubtree = serialize(root->left);
    string rightSubtree = serialize(root->right);
    // space is used to separate tokens in stringstream
    return root->value + " " + leftSubtree + rightSubtree;
}

// Passing by reference helps deflating the same stringstream
TreeNode* deserialize(istringstream& iss) {
    string ournode;
    iss >> ournode; // Remove from stringstream to ournode
    if(ournode == "X") {
        return NULL;
    }
    TreeNode* newNode = new TreeNode(ournode);
    newNode->left = deserialize(iss);
    newNode->right = deserialize(iss);
    return newNode;
}

/* Let us serialize and deserialize the below binary tree.
 *                1
 *               / \
 *              2   3
 *             / \   \
 *            4   5   6           
 */
int main() {

    TreeNode *root = new TreeNode("1");
    root->left = new TreeNode("2");
    root->right = new TreeNode("3");
    root->left->left = new TreeNode("4");
    root->left->right = new TreeNode("5");
    root->right->right = new TreeNode("6");
    string ser = serialize(root);
    cout << "Serialized output: " << ser << endl;
    istringstream iss(ser);
    TreeNode *newroot = deserialize(iss);
    cout << "TEST ######" << endl;
    string ser1 = serialize(newroot);
    cout << "Serialized output: " << ser1 << endl;
}
