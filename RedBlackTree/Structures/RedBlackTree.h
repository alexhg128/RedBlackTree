//
// Created by Alejandro on 09/11/2018.
//

#ifndef REDBLACKTREE_REDBLACKTREE_H
#define REDBLACKTREE_REDBLACKTREE_H


#include <assert.h>;

//Color enumeration
enum Color { RED, BLACK };

//Structures declaration
template <typename T>
struct RedBlackNode;

template <typename T>
struct RedBlackTree;

/*
 * Structures implementation
 */

template <typename T>
struct RedBlackNode {

public:
    T value = {};
    Color color = BLACK;
    RedBlackNode<T>* left = nullptr;
    RedBlackNode<T>* right = nullptr;
    RedBlackNode<T>* parent = nullptr;

    static void RotateLeft(RedBlackTree<T>* t, RedBlackNode<T>* x) {
        auto y = x->right;
        x->right = y->left;
        if(y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if(x->parent == nullptr) {
            t->root = y;
        } else if(x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    static void RotateRight(RedBlackTree<T>* t, RedBlackNode<T>* x) {
        auto y = x->left;
        x->left = y->right;
        if(y->right != nullptr) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if(x->parent == nullptr) {
            t->root = y;
        } else if(x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

};

template <typename T>
struct RedBlackTree {

public:
    RedBlackNode<T>* root = nullptr;

    RedBlackNode<T>* nil = new RedBlackNode();

private:
    void InsertRepair(RedBlackNode<T>* z) {
        if(!(z->parent) || !(z->parent->parent)) {
            return;
        }
        RedBlackNode<T>* y;
        while (z->parent->color == RED) {
            if(z->parent == z->parent->parent->right) {
                y = z->parent->parent->right;
                if(y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else if(z == z->parent->right) {
                    z = z->parent;
                    RedBlackNode::RotateLeft(this, z);
                } else {
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    RedBlackNode::RotateRight(this, z->parent->parent);
                }
            } else {
                y = z->parent->parent->left;
                if(y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else if(z == z->parent->left) {
                    z = z->parent;
                    RedBlackNode::RotateRight(this, z);
                } else {
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    RedBlackNode::RotateLeft(this, z->parent->parent);
                }
            }
            root->color = BLACK;
        }

    }

    void InsertNode(RedBlackNode<T>* z) {
        RedBlackNode<T>* y = nullptr;
        auto x = root;
        while(x != nullptr) {
            y = x;
            if(z->value < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->parent = y;
        if(y == nullptr) {
            root = z;
        } else if(z->value < y->value) {
            y->left = z;
        } else {
            y->right = z;
        }
        z->left = nullptr;
        z->right = nullptr;
        z->color = RED;
        InsertRepair(z);
    }
};


#endif //REDBLACKTREE_REDBLACKTREE_H
