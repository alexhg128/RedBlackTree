#include <iostream>

#include "Structures/RedBlackTree.h"

int main() {
    auto tree = new RedBlackTree<int>();

    tree->Insert(5);
    std::cout << std::endl;
    tree->Print(INORDER);
    std::cout << std::endl;
    std::cout << tree->root->value;

    tree->Insert(4);
    std::cout << std::endl;
    tree->Print(INORDER);
    std::cout << std::endl;
    std::cout << tree->root->value;

    tree->Insert(55);
    std::cout << std::endl;
    tree->Print(INORDER);
    std::cout << std::endl;
    std::cout << tree->root->value;

    tree->Insert(8);
    std::cout << std::endl;
    tree->Print(INORDER);
    std::cout << std::endl;
    std::cout << tree->root->value;

    tree->Insert(2);
    std::cout << std::endl;
    tree->Print(INORDER);
    std::cout << std::endl;
    std::cout << tree->root->value;

    tree->Insert(6);
    std::cout << std::endl;
    tree->Print(INORDER);
    std::cout << std::endl;
    std::cout << tree->root->value;

    tree->Delete(2);
    std::cout << std::endl;
    tree->Print(INORDER);
    std::cout << std::endl;
    std::cout << tree->root->value;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    tree->print2D(tree->root);


    return 0;
}