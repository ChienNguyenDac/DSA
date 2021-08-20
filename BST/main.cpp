#include<bits/stdc++.h>
using namespace std;


/*
    - When deleting a node which still have 2 children, find "smallest node of the right subtree" to replace.
    - When adding a node which has the same value as parent node, add it in the "left sub tree".
*/
class BinarySearchTree{
    public:
        class Node{
            private:
                int data;
                Node *left, *right;
                friend class BinarySearchTree;
            public:
                Node(){}
                Node(int value):    data(value), left(NULL), right(NULL)    {}
                ~Node(){}
        };
    private:
        Node* root;
    public:
        BinarySearchTree(): root(nullptr) {}
        //  delete all node of tree
        void deleteTreeRec(Node* node){
            if(node==NULL)  return;
            deleteTreeRec(node->left);
            deleteTreeRec(node->right);
            delete node;
        }
        //  add new node into BST. 
        void addRec(Node* &node, int value){
            if(node==NULL)
                node = new Node(value);
            else if(value <= node->data)
                addRec(node->left, value);
            else
                addRec(node->right, value);
        }
        void add(int value){
            addRec(this->root, value);
        }

        //  delete a node from BST
        bool removeRec(Node* &node, int value){
            if(node==NULL)  
                return false;
            if(value < node->data)
                return removeRec(node->left, value);
            else if(value > node->data)
                return removeRec(node->right, value);
            //   
            Node* p = node;
            if(node->left==NULL || node->right==NULL){
                if(node->left==NULL)
                    node = node->right;
                else
                    node = node->left;
                delete p;
                return true;
            }
            p = node->right;
            Node* maxNodeRight = p;
            while(p->left != NULL){
                maxNodeRight = p;
                p = p->left;
            }
            node->data = maxNodeRight->data;
            return removeRec(node->right, node->data);
        }        
        bool remove(int value){
            return removeRec(this->root, value);
        }

        //  find value in BST
        bool findRec(Node* node, int value){
            if(node==NULL)
                return false;
            if(node->data > value)
                return findRec(node->left, value);
            if(node->data < value)
                return findRec(node->right, value);
            return true;
        }
        bool find(int value){
            return findRec(this->root, value);
        }

        //  calculate sum all node in BST that have value in [l;r]
        int calculateRec(Node* node, int l, int r){
            if(node==NULL)
                return 0;
            int sum = 0;
            if(node->data >= l && node->data <=r)
                sum = node->data;
        
            return sum + calculateRec(node->left, l, r) + calculateRec(node->right, l, r);
        }
        int sum(int l, int r){
            return calculateRec(this->root, l, r);
        }

        //  getMin & getMax node in BST
        int getMin(){
            //  default root is not null;
            Node* p = this->root;
            while(p->left!=NULL)
                p = p->left;
            return p->data;
        }

        int getMax(){
            //  default root is not null
            Node* p = this->root;
            while(p->right!=NULL)
                p = p->right;
            return p->data;
        }

        //  print Inorder 
        string inOrderRec(Node* node){
            stringstream ss;
            if(node!=NULL){
                ss << inOrderRec(node->left);
                ss << node->data << " ";
                ss << inOrderRec(node->right);
            }
            return ss.str();
        }
        string inOrder(){
            return inOrderRec(this->root);
        }

        void print(){
            cout<<this->root->data;
        }

        void deleteTree(){
            deleteTreeRec(this->root);
        }

        ~BinarySearchTree(){ 
            deleteTreeRec(this->root);
        }
};


int main(){
   int values[] = { 32,19,23,33,76,1,37,53,18,89,28,1,77,52,17 };
    BinarySearchTree bst;
    for (int i = 0; i < 15; ++i) {
        bst.add(values[i]);
    }

    cout << bst.getMin() << endl;
    cout << bst.getMax() << endl;
    return 0;
}