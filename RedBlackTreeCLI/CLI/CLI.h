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

#ifndef REDBLACKTREECLI_CLI_H
#define REDBLACKTREECLI_CLI_H

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

#include "../Structures/RedBlackTree.h"

/*
 * ---------------------------------------------------------
 * CLI Handler
 * ---------------------------------------------------------
 */

class CLI {

    RedBlackTree<int>* tree = new RedBlackTree<int>();

public:
    void start() {
        Main();
    }

private:
    void Main() {
        while (true) {
            std::cout << ">_ ";
            std::string str = "";
            getline(std::cin, str);
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
            auto s = Split(str, ' ');
            /*for(std::string i : s) {
                std::cout << "~" << i << std::endl;
            }
            std::cout << "#" << s.size() << std::endl;*/
            if(s.size() > 0) {
                if(s[0].compare("exit") == 0) {
                    return;
                } else if(s[0] == "print") {
                    std::cout << std::endl;
                    if(s.size() > 1) {
                        if(s[1] == "inorder") {
                            if(s.size() > 2 && (s[2] == "c" || s[2] == "--c")) {
                                tree->Print(INORDER, true);
                            } else {
                                tree->Print(INORDER, false);
                            }
                        } else if(s[1] == "preorder") {
                            if(s.size() > 2 && (s[2] == "c" || s[2] == "--c")) {
                                tree->Print(PREORDER, true);
                            } else {
                                tree->Print(PREORDER, false);
                            }
                        } else if(s[1] == "postorder") {
                            if(s.size() > 2 && (s[2] == "c" || s[2] == "--c")) {
                                tree->Print(POSTORDER, true);
                            } else {
                                tree->Print(POSTORDER, false);
                            }
                        } else {
                            if(s.size() > 2 && (s[2] == "c" || s[2] == "--c")) {
                                tree->Print2D(true);
                            } else {
                                tree->Print2D(false);
                            }
                        }
                    } else {
                        if(s.size() > 2 && (s[2] == "c" || s[2] == "--c")) {
                            tree->Print2D(true);
                        } else {
                            tree->Print2D(false);
                        }
                    }
                    std::cout << std::endl;
                } else if(s[0] == "print2d") {
                    std::cout << std::endl;
                    if(s.size() > 1 && (s[1] == "c" || s[1] == "--c")) {
                        tree->Print2D(true);
                    } else {
                        tree->Print2D(false);
                    }
                    std::cout << std::endl;
                } else if(s[0] == "print1d") {
                    std::cout << std::endl;
                    if(s.size() > 1) {
                        if(s[1] == "preorder") {
                            if(s.size() > 2 && (s[2] == "c" || s[2] == "--c")) {
                                tree->Print(PREORDER, true);
                            } else {
                                tree->Print(PREORDER, false);
                            }
                        } else if(s[1] == "postorder") {
                            if(s.size() > 2 && (s[2] == "c" || s[2] == "--c")) {
                                tree->Print(POSTORDER, true);
                            } else {
                                tree->Print(POSTORDER, false);
                            }
                        } else {
                            if(s.size() > 2 && (s[2] == "c" || s[2] == "--c")) {
                                tree->Print(INORDER, true);
                            } else {
                                tree->Print(INORDER, false);
                            }
                        }
                    } else {
                        if(s.size() > 2 && (s[2] == "c" || s[2] == "--c")) {
                            tree->Print(INORDER, true);
                        } else {
                            tree->Print(INORDER, false);
                        }
                    }
                    std::cout << std::endl;
                } else if (s[0] == "insert" || s[0] == "add") {
                    if(s.size() > 1) {
                        for(std::string i: s) {
                            if(i == s[0]) {
                                continue;
                            }
                            if(isNumber(i)) {
                                int x = std::stoi(i);
                                tree->Insert(x);
                            }
                        }
                        std::cout << std::endl;
                        if(s.size() > 2 && (s[2] == "c" || s[2] == "--c")) {
                            tree->Print2D(true);
                        } else {
                            tree->Print2D(false);
                        }
                        std::cout << std::endl;
                    } else {
                        std::cout << "error" << std::endl;
                    }
                } else if (s[0] == "remove" || s[0] == "delete") {
                    if(s.size() > 1) {
                        for(std::string i: s) {
                            if(i == s[0]) {
                                continue;
                            }
                            if(isNumber(i)) {
                                int x = std::stoi(i);
                                tree->Delete(x);
                            }
                        }
                        std::cout << std::endl;
                        if(s.size() > 2 && (s[2] == "c" || s[2] == "--c")) {
                            tree->Print2D(true);
                        } else {
                            tree->Print2D(false);
                        }
                        std::cout << std::endl;
                    } else {
                        std::cout << "error" << std::endl;
                    }
                } else if(s[0] == "root") {
                    std::cout << std::endl;
                    std::cout << tree->root->value << std::endl;
                    std::cout << std::endl;
                } else if(s[0] == "clear") {
                    tree = new RedBlackTree<int>();
                } else if(s[0] == "height") {
                    std::cout << std::endl;
                    std::cout << tree->Height() << std::endl;
                    std::cout << std::endl;
                } else if(s[0] == "size") {
                    std::cout << std::endl;
                    std::cout << tree->Size() << std::endl;
                    std::cout << std::endl;
                } else {
                        std::cout << "** Red-Black Tree CLI Help **" << std::endl;
                        std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;
                        std::cout << "add [parameters] | Adds nodes to the tree | Parameters: numbers divided by spaces" << std::endl;
                        std::cout << "insert [parameters] | Adds nodes to the tree | Parameters: numbers divided by spaces" << std::endl;
                        std::cout << "delete [parameters] | Delete nodes from the tree | Parameters: numbers divided by spaces" << std::endl;
                        std::cout << "remove [parameters] | Delete nodes from the tree | Parameters: numbers divided by spaces" << std::endl;
                        std::cout << "print [options] | Prints a representation of a tree | 2d (default) / prorder / inorder / postorder" << std::endl;
                        std::cout << "print2d | Prints a 2D representation of a tree" << std::endl;
                        std::cout << "print1d [options] | Prints a list of the elements of a tree | inorder (default) / perorder / postorder" << std::endl;
                        std::cout << "height | Shows the height of the tree" << std::endl;
                        std::cout << "size | Shows the size of the tree" << std::endl;
                        std::cout << "root | Returns the root of the tree" << std::endl;
                        std::cout << "help | Show a list of commands" << std::endl;
                        std::cout << "exit | Closes the application" << std::endl;
                        std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;
                }
            }
        }

    }

    std::vector<std::string> Split(const std::string& s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    bool isNumber(const std::string& s)
    {
        return !s.empty() && s != "-" && s.find_first_not_of("-.0123456789") == std::string::npos;
    }

};


#endif //REDBLACKTREECLI_CLI_H
