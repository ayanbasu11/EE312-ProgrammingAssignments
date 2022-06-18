// Interpreter A <ExpressionTree.h>
// EE 312 Project 8 submission by
// <Ayan Basu>
// <EID: ab73287>
// Slip days used: <0>
// Fall 2021

#ifndef EXPRESSION_TREE
#define EXPRESSION_TREE

#include "Project8.h"

class ET {
private: 
    class Node {
    public:
        Node* left;
        Node* right;

        int number;
        std::string op;

        Node(int value) {
            number = value;
            left = nullptr;
            right = nullptr;
        }

        Node(std::string opStr, Node* leftNode, Node* rightNode) {
            op = opStr;
            left = leftNode;
            right = rightNode;
        }
    };

Node* root;

Node* makeTree(std::vector<std::string> &expression) {
    if (expression.empty()) return nullptr;
    std::string current = expression[0];
    expression.erase(expression.begin());
    if (current == "+" || current == "-" || current == "*" || current == "/" || current == "%" 
    || current == "&&" || current == "||" || current == "<" || current == ">" || current == "==" 
    || current == "!=" || current == "<=" || current == ">=" || current == "!" || current == "~") {
        Node* left = makeTree(expression);
        Node* right = makeTree(expression);
        return new Node(current, left, right);
    } else {
        return new Node(std::stoi(current));
    }
}

public:
    ET(std::vector<std::string> expression) {
        root = makeTree(expression);
    }

    int computeTree(Node* root) {
        if (root == nullptr) return 0;
        else if (root->left == nullptr && root->right == nullptr) {
            return root->number;
        }

        else if (root->op == "+") return computeTree(root->left) + computeTree(root->right);
        else if (root->op == "-") return computeTree(root->left) - computeTree(root->right);
        else if (root->op == "*") return computeTree(root->left) * computeTree(root->right);
        else if (root->op == "/") return computeTree(root->left) / computeTree(root->right);
        else if (root->op == "%") return computeTree(root->left) % computeTree(root->right);
        else if (root->op == "&&") return computeTree(root->left) && computeTree(root->right);
        else if (root->op == "||") return computeTree(root->left) || computeTree(root->right);
        else if (root->op == "<") return computeTree(root->left) < computeTree(root->right);
        else if (root->op == ">") return computeTree(root->left) > computeTree(root->right);
        else if (root->op == "<=") return computeTree(root->left) <= computeTree(root->right);
        else if (root->op == ">=") return computeTree(root->left) >= computeTree(root->right);
        else if (root->op == "==") return computeTree(root->left) == computeTree(root->right);
        else if (root->op == "!=") return computeTree(root->left) != computeTree(root->right);
        else if (root->op == "!") return !(computeTree(root->left));
        else if (root->op == "~") return (-1 * computeTree(root->left));
        return 0;
    } 

    int compute() {
        int value = computeTree(root);
        return value;
    }

    void print2DUtil(Node *root, int space)  
    {  
        // Base case  
        if (root == NULL)  
            return;  
    
        // Increase distance between levels  
        space += 10;  
    
        // Process right child first  
        print2DUtil(root->right, space);  
    
        // Print current node after space  
        // count  
        std::cout<<std::endl;  
        for (int i = 10; i < space; i++)  
            std::cout<<" ";  
        std::cout<<root->number<<"\n";  
    
        // Process left child  
        print2DUtil(root->left, space);  
    }  
  
    // Wrapper over print2DUtil()  
    void print2D(Node *root)  
    {  
        // Pass initial space count as 0  
        print2DUtil(root, 0);  
    }  

    void printTree() {
        print2D(root);
    }
};

#endif