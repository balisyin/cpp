/* *
 * balisyin 20190212
 * all binary tree algorithm
 * */
//#include<bits/stdc++.h>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct tNode{
    int data;
    tNode* left;
    tNode* right;
};
void printNode(tNode* p) {cout << p->data << endl; return;}

///BT1 Inorder/Preorder/Postorder
void inorderTraverse(tNode* root){
    if(root->left != nullptr)
        inorderTraverse(root->left);
    printNode(root);
    if(root->right != nullptr)
        inorderTraverse(root->right);
    return;
}
void preorderTraverse(tNode* root){
    if(root == nullptr)
        return;
    printNode(root);
    if(root->left != nullptr)
        preorderTraverse(root->left);
    if(root->right != nullptr){
        preorderTraverse(root->right);
    }

    return;
}
void postOrderTraverse(tNode* root){
    if(root == nullptr)
        return;
    if(root->left != nullptr)
        postOrderTraverse(root->left);
    if(root->right != nullptr){
        postOrderTraverse(root->right);
    }
    printNode(root);

    return;
}


///BT2 levelTraverse and zigzagTraverse
void levelTraverse(tNode* root){
    queue<tNode*> tmp_queue;
    tNode* node;
    int this_level_width = 1;
    int next_level_width = 0;
    tmp_queue.push(root);
    while(!tmp_queue.empty()){
        node = tmp_queue.front();
        tmp_queue.pop();
        printNode(node);
        this_level_width--;
        if(this_level_width == 0){
            cout << endl;
            this_level_width = next_level_width;
            next_level_width = 0;
        }
        if(node->left){
            tmp_queue.push(node->left);
            next_level_width++;
        } 
        if(node->right){
            tmp_queue.push(node->right);
            next_level_width++;
        }    
    }
    return;
}
void zigzagTraverse(tNode* root){
    if(root == nullptr)
        return;
    tNode* node;
    bool left_push_first = true;
    stack<tNode*> this_level;
    stack<tNode*> next_level;
    stack<tNode*> tmp_level;
    this_level.push(root);
    int this_level_width = 1;
    int next_level_width = 0;
    while(!this_level.empty()){
        node = this_level.top();
        this_level.pop();
        printNode(node);
        if(left_push_first){
            if(node->left){
                next_level.push(node->left);
                next_level_width++;
            }
            if(node->right){
                next_level.push(node->right);
                next_level_width++;
            }
        } else {
            if(node->right){
                next_level.push(node->right);
                next_level_width++;
            }
            if(node->left){
                next_level.push(node->left);
                next_level_width++;
            }
        }
        this_level_width--;
        if(this_level_width == 0){
            this_level_width = next_level_width;
            next_level_width = 0;
            left_push_first = !left_push_first;
            tmp_level = this_level;
            this_level = next_level;
            next_level = tmp_level;
        }
    }

    return;
}



///BT


int main(int arg, char* args[]){



    return 0;
}