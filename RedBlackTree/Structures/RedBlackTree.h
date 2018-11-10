//
// Created by Alejandro on 09/11/2018.
//

#ifndef REDBLACKTREE_REDBLACKTREE_H
#define REDBLACKTREE_REDBLACKTREE_H

#include <assert.h>
#include <vector>
#include <iostream>
#include <iomanip>

//Color enumeration
enum Color { RED, BLACK };
enum WalkOrder { PREORDER, INORDER, POSTORDER };

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

    RedBlackNode<T>* Search(T key) {
        auto current = root;
        while (current) {
            if(key == current->value) {
                return current;
            } else if (key < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return nullptr;
    }

    void Insert(T value) {
        RedBlackNode<T>* x = new RedBlackNode<T>();
        x->value = value;
        InsertNode(x);
        root->color = BLACK;
    }

    void Delete(RedBlackNode<T>* x) {
        DeleteNode(x);
    }

    void Delete(T value) {
        RedBlackNode<T>* x = Search(value);
        if(x) {
            DeleteNode(x);
        }
    }

    int Size() {
        if(root == nullptr) {
            return 0;
        } else {
            return (SizeRecursive(root->left) + 1 + SizeRecursive(root->right));
        }
    }

    int Height() {
        return HeightRecursive(root);
    }

    std::vector<RedBlackNode<T>*> ToList(WalkOrder x = PREORDER) {
        std::vector<RedBlackNode<T>*> list;
        if(x == PREORDER) {
            ToListPreOrder(root, &list);
        } else if (x == INORDER) {
            ToListInOrder(root, &list);
        } else {
            ToListPostOrder(root, &list);
        }
        return list;
    }

    void Print(WalkOrder x = PREORDER) {
        if(x == PREORDER) {
            PrintPreOrder(root);
        } else if (x == INORDER) {
            PrintInOrder(root);
        } else {
            PrintPostOrder(root);
        }
    }

    void PrintAsTree() {
        int height = Height() * 2;
        for(int i = 0; i < height; i++) {
            PrintRow(root, height, i);
        }
    }

private:

    void PrintRow(RedBlackNode<T>* p, int h, int d) {
        std::vector<T> v;
        GetLine(p, d, v);
        std::cout << std::setw((h - d) * 2);
        bool t = true;
        if(v.size() > 1) {
            for(T i: v) {
                if(i != T()) {
                    if(t) {
                        std::cout << "/" << "  ";
                    } else {
                        std::cout << "\\" << "  ";
                    }
                }
                t = !t;
            }
            std::cout << std::endl;
            std::cout << std::setw((h - d) * 2);
        }
        for(T i : v) {
            if(i != T()) {
                std::cout << i << "  ";
            }
        }
        std::cout << std::endl;
    }

    void GetLine(RedBlackNode<T>* r, int d, std::vector<T>& v) {
        if(d <=0 && r != nullptr) {
            v.push_back(root->value);
            return;
        }
        if(root->left != nullptr) {
            GetLine(r->left, d-1, v);
        } else if (d-1 <= 0) {
            v.push_back(T());
        }
        if(r->right != nullptr) {
            GetLine(r->right, d-1, v);
        } else if(d-1 <= 0) {
            v.push_back(T());
        }
    }

    int HeightRecursive(RedBlackNode<T>* x) {
        if(!x) {
            return 0;
        } else {
            int l = HeightRecursive(x->left);
            int r = HeightRecursive(x->right);

            if (l > r) {
                return (l + 1);
            } else {
                return (r + 1);
            }
        }
    }

    void ToListPreOrder(RedBlackNode<T>* n, std::vector<RedBlackNode<T>*>* list) {
        if(!n) {
            return;
        }
        list->push_back(n);
        ToListPreOrder(n->left, list);
        ToListPreOrder(n->right, list);
    }

    void ToListInOrder(RedBlackNode<T>* n, std::vector<RedBlackNode<T>*>* list) {
        if(!n) {
            return;
        }
        ToListInOrder(n->left, list);
        list->push_back(n);
        ToListInOrder(n->right, list);
    }

    void ToListPostOrder(RedBlackNode<T>* n, std::vector<RedBlackNode<T>*>* list) {
        if(!n) {
            return;
        }
        ToListPostOrder(n->left, list);
        ToListPostOrder(n->right, list);
        list->push_back(n);
    }

    void PrintPreOrder(RedBlackNode<T>* n) {
        if(!n) {
            return;
        }
        std::cout << n->value << " ";
        PrintPreOrder(n->left);
        PrintPreOrder(n->right);
    }

    void PrintInOrder(RedBlackNode<T>* n) {
        if(!n) {
            return;
        }
        PrintInOrder(n->left);
        std::cout << n->value << "(" << (n->color == BLACK ? "Black" : "Red") << ")" << " ";
        PrintInOrder(n->right);
    }

    void PrintPostOrder(RedBlackNode<T>* n) {
        if(!n) {
            return;
        }
        PrintPostOrder(n->left);
        PrintPostOrder(n->right);
        std::cout << n->value << " ";
    }

    int SizeRecursive(RedBlackNode<T>* n) {
        if(n == nullptr) {
            return 0;
        } else {
            return (SizeRecursive(n->left) + 1 + SizeRecursive(n->right));
        }
    }

    void InsertRepair(RedBlackNode<T>* z) {
        if(!(z->parent) || !(z->parent->parent)) {
            return;
        }
        RedBlackNode<T>* y;
        while (z->parent != nullptr && z->parent->color == RED) {
            if(z->parent == z->parent->parent->left) {
                y = z->parent->parent->right;
                if(y && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else if(z->parent && z == z->parent->right) {
                    z = z->parent;
                    RedBlackNode<T>::RotateLeft(this, z);
                } else {
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    RedBlackNode<T>::RotateRight(this, z->parent->parent);
                }
            } else {
                y = z->parent->parent->left;
                if(y && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else if(z->parent && z == z->parent->left) {
                    z = z->parent;
                    RedBlackNode<T>::RotateRight(this, z);
                } else {
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    RedBlackNode<T>::RotateLeft(this, z->parent->parent);
                }
            }
            root->color = BLACK;
        }
        root->color = BLACK;

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

    void Swap(RedBlackNode<T>* x, RedBlackNode<T>* y) {
        if(x->parent == nullptr) {
            root = y;
        } else if(x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        if(y && x) {
            y->parent = x->parent;
        }
    }

    void DeleteRepair(RedBlackNode<T>* x) {
        while (x != root && x->color == BLACK) {
            if(x == x->parent->left) {
                auto w = x->parent->right;
                if(w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    RedBlackNode<T>::RotateLeft(this, x->parent);
                    w = x->parent->right;
                }
                if(w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    RedBlackNode<T>::RotateRight(this, w);
                    w = x->parent->right;
                } else {
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    RedBlackNode<T>::RotateLeft(this, x->parent);
                    x = root;
                }
            } else {
                auto w = x->parent->left;
                if(w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    RedBlackNode<T>::RotateRight(this, x->parent);
                    w = x->parent->left;
                }
                if(w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    RedBlackNode<T>::RotateLeft(this, w);
                    w = x->parent->left;
                } else {
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    RedBlackNode<T>::RotateRight(this, x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    RedBlackNode<T>* Minimum(RedBlackNode<T>* x) {
        while (x->left != nullptr) {
            x = x->left;
        }
        return x;
    }

    void DeleteNode(RedBlackNode<T>* z) {
        auto y = z;
        auto yOriginalColor = y->color;
        RedBlackNode<T>* x;
        if(z->left == nullptr) {
            x = z->right;
            Swap(z, z->right);
        } else if(z->right == nullptr) {
            x = z->left;
            Swap(z, z->left);
        } else {
            y = Minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if(y->parent == z) {
                x->parent = y;
            } else {
                Swap(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            Swap(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if(yOriginalColor == BLACK) {
            DeleteRepair(x);
        }
    }

};


#endif //REDBLACKTREE_REDBLACKTREE_H
