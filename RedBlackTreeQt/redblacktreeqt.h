/*
 *
 * Red-Black Tree Project
 * Data Structures Course
 * 10/NOV/2018
 *
 * Alejandro Hahn Gallegos (A01561774)
 * Yessica Janeth Hernandez Rosales (A01561794)
 * Hugo Alberto Valencia Corral (A01561688)
 *
 */

#ifndef REDBLACKTREEQT_H
#define REDBLACKTREEQT_H

#endif // REDBLACKTREEQT_H

#include <redblacktree.h>
#include <string>
#include <iostream>
#include <sstream>
#include <QString>

/*
 * ---------------------------------------------------------
 * Red-Black Tree, QT Specific Implementation
 * ---------------------------------------------------------
 */

template <typename T>
class QRedBlackTree : public RedBlackTree<T> {

public:

    /*
     * ---------------------------------------------------------
     * QT Specific Printing Methods
     * ---------------------------------------------------------
     */

    QString QPrint(WalkOrder x = PREORDER, bool c = false) {
        output = "";
        if(x == PREORDER) {
            QPrintPreOrder(this->root, c);
        } else if (x == INORDER) {
            QPrintInOrder(this->root, c);
        } else {
            QPrintPostOrder(this->root, c);
        }
        return QString::fromStdString(output);
    }

    QString QPrint2D(RedBlackNode<T>* root, bool c) {
        output = "";
        QPrint2DUtil(root, 0, c);
        return QString::fromStdString(output);
    }

    QString QPrint2D(bool c = false) {
        return QPrint2D(this->root, c);
    }

private:

    /*
     * ---------------------------------------------------------
     * QT Specific Printing Utilities
     * ---------------------------------------------------------
     */

    std::string output = "";

    void QPrintInOrder(RedBlackNode<T>* n, bool c) {
        if(!n) {
            return;
        }
        QPrintInOrder(n->left, c);
        output = output + static_cast<std::ostringstream*>( &(std::ostringstream() << n->value) )->str();;
        if(c) {
            std::string color = n->color == BLACK ? "(B)" : "(R)";
            output += " " + color + " ";
        }
        output+= " ";
        QPrintInOrder(n->right, c);
    }

    void QPrintPostOrder(RedBlackNode<T>* n, bool c) {
        if(!n) {
            return;
        }
        QPrintPostOrder(n->left, c);
        QPrintPostOrder(n->right, c);
        output = output + static_cast<std::ostringstream*>( &(std::ostringstream() << n->value) )->str();;
        if(c) {
            std::string color = n->color == BLACK ? "(B)" : "(R)";
            output += " " + color + " ";
        }
        output += " ";
    }

    void QPrintPreOrder(RedBlackNode<T>* n, bool c) {
        if(!n) {
            return;
        }
        output = output + static_cast<std::ostringstream*>( &(std::ostringstream() << n->value) )->str();;
        if(c) {
            std::string color = n->color == BLACK ? "(B)" : "(R)";
            output += " " + color + " ";
        }
        output += " ";
        QPrintPreOrder(n->left, c);
        QPrintPreOrder(n->right, c);
    }

    void QPrint2DUtil(RedBlackNode<T>* root, int space, bool c)
    {
        if (root == NULL) {
            return;
        }
        space += 10;
        QPrint2DUtil(root->right, space, c);
        output += "\n";
        for (int i = 10; i < space; i++) {
            output += " ";
        }        
        output += static_cast<std::ostringstream*>( &(std::ostringstream() << root->value) )->str();
        if(c) {
            std::string color = root->color == BLACK ? "(B)" : "(R)";
            output += " " + color + " ";
        }
        output += "\n";
        QPrint2DUtil(root->left, space, c);
    }

};
