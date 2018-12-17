#include <iostream>
#include <vector>
#include <string>

using namespace std;


template<class T>
class Tree {
private:
    struct NodeTree {
    public:
        NodeTree *left;
        NodeTree *right;
        T data;
    };
    NodeTree *root = NULL;
    int sizeTree = 0;
    vector<T> el;
    NodeTree *GetNewNode(T data) {
        NodeTree *newNode = new NodeTree;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    void shower(NodeTree *&Tree){
        if (Tree != NULL){
            shower(Tree->left);
            el.push_back(root->data);
            cout<<Tree->data << endl;
            shower(Tree->right);
        }
    }
    NodeTree* ToAdder(NodeTree* root,T data) {
        if (root == NULL) {
            root = GetNewNode(data);
        } else if (data <= root->data) {
            root->left = ToAdder(root->left, data);
        } else {
            root->right = ToAdder(root->right, data);
        }
        return root;
    }
public:
    NodeTree* AddTo(T element) {
        if (root == NULL) {
            root = GetNewNode(element);
            sizeTree++;
        } else if (element <= root->data) {
            root->left = ToAdder(root->left, element);
        } else {
            root->right = ToAdder(root->right, element);
        }
        return root;
    }
    int Size(){
        return this->sizeTree;
    }

    void show() {
        if (this->root != NULL) {
            shower(root->left);
            el.push_back(root->data);
            cout<<root->data << endl;
            shower(root->right);
        }
    }
};


int main() {
    Tree<int> tree1;
    Tree<string> tree2;
    tree1.AddTo(92);
    tree1.AddTo(5);
    tree1.AddTo(17);
    tree1.AddTo(3);
    tree1.AddTo(2);
    tree1.AddTo(1);
    tree1.AddTo(323232);
    tree1.show();
    
    tree2.AddTo("Hello");
    tree2.AddTo("World");
    tree2.AddTo("!");
    tree2.show();

    return 0;
}
