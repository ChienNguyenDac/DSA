#include<bits/stdc++.h>
using namespace std;

class BinaryTree{
    public:
        class Node{
            private:
                int data;
                int key;
                Node *left, *right;
                friend class BinaryTree;
            public:
                Node(){}
                Node(int keyword, int value):    key(keyword), data(value), left(NULL), right(NULL)    {}
                ~Node(){}
        };
    private:
        Node* root;
    public:
        BinaryTree():   root(NULL)  {}
        //  delete all node of tree
        void deleteTreeRec(Node* node){
            if(node==NULL)  return;
            deleteTreeRec(node->left);
            deleteTreeRec(node->right);
            delete node;
        }

        //  add new node with select 
        void addNode(string posFromRoot, int key, int value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = (int)posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->left;
            if (posFromRoot[i] == 'R')
                walker = walker->right;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->left = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->right = new Node(key, value);
    }

        int getHeightRec(Node* node){
            if(node==NULL)
                return 0;
            return max(getHeightRec(node->left), getHeightRec(node->right))+1;
        }

        //  get height of binarytree
        int getHeight(){
            return getHeightRec(this->root);
        }

        //  get max distance 2 node in binarytree
        int getDiameter(){
            if(this->root==NULL)
                return 0;
            return 1+ getHeightRec(this->root->left) + getHeightRec(this->root->right);
        }

        //  Breath First Search -> print all node of tree
        void BFS(){
            queue<Node*> q;
            if(this->root!=NULL){
                q.push(this->root->left);
                q.push(this->root->right);
                cout<<this->root->data;
            }
            while(!q.empty()){
                Node* p = q.front();
                q.pop();
                if(p!=NULL){
                    cout<<" "<<p->data;
                    q.push(p->left);
                    q.push(p->right);
                }
            }
        }

        //  Count number node have 2 children
        int countTwoChildrenNodeRec(Node* node){
            if(node==NULL)  return 0;
            int count = 0;
            if(node->left!=NULL && node->right!=NULL)
                count++;
            return count + countTwoChildrenNodeRec(node->left) + countTwoChildrenNodeRec(node->right);
        }
        int countTwoChildrenNode(){
            return countTwoChildrenNodeRec(this->root);
        }

        //  check BST 
        /*
            - all left subtree <= node parent value
            - all right subtree > node parent value
            - each subtree is BST
        */
        bool isBSTRec(Node* node){
            if(node==NULL)
                return true;
            if(node->left!=NULL){
                if(node->left->data > node->data)
                    return false;
            }
            if(node->right!=NULL){
                if(node->right->data <= node->data)
                    return false;
            }
            return (isBSTRec(node->left) && isBSTRec(node->right));
        }
        bool isBST(){
            return isBSTRec(this->root);
        }  

        //  pre order  ||  in order  ||  post order
        string preOrderRec(Node* node){
            stringstream ss;
            if(node!=NULL){
                ss << node->data << " ";
                ss << preOrderRec(node->left);
                ss << preOrderRec(node->right);
            }
            return ss.str();
        }
        string preOrder(){
            return preOrderRec(this->root);
        }

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

        string postOrderRec(Node* node){
            stringstream ss;
            if(node!=NULL){
                ss << postOrderRec(node->left);
                ss << postOrderRec(node->right);
                ss << node->data << " ";
            }
            return ss.str();
        }
        string postOrder(){
            return postOrderRec(this->root);
        }

        //  calculate sum of leaf node in binary tree
        int calculateRec(Node* node){
            if(node==NULL)
                return false;
            if(node->left==NULL && node->right==NULL)
                return node->data;
            return calculateRec(node->left) + calculateRec(node->right);
        }  
        int sumOfLeafs(){
            return calculateRec(this->root);
        }


        ~BinaryTree(){
            deleteTreeRec(this->root);
        }
};


int main(){
   BinaryTree binaryTree;
binaryTree.addNode("", 2, 4);
cout << binaryTree.sumOfLeafs();
    return 0;
}