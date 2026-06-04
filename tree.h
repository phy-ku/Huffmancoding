#ifndef _TREE_H_
#define _TREE_H_
#include <cstdio>
#include <iostream>
#include <unordered_map>
class tree
{
private:
    tree* left;
    tree* right;
    char letter;
    int weight;
public:
    tree();
    tree(const tree &a,const tree &b);
    tree(const char a);
    tree(const tree& a);
    tree& operator=(const tree& a);
    bool operator<(const tree& a) const;
    bool operator>(const tree& a) const;
    bool searchchar(const char a);
    void weightplus();
    friend void writedict(tree& a,std::unordered_map<char,std::string>& dict,std::string nowmm);
    void exshape(std::string& now,std::string& leaf) const;
    ~tree();
};
class huffmantree:public tree
{
public:
    huffmantree();
    huffmantree(const tree& a);
    huffmantree(const huffmantree& a);
    huffmantree& operator=(const huffmantree& a);
    std::string encoding(const char* a);
    std::string encoding(const std::string a);
    ~huffmantree();
};
class forest
{
private:
    int number;
    tree* trees;
public:
    forest();
    forest(const char* a);
    forest(const std::string a);
    forest(const forest& a);
    forest& operator=(const forest& a);
    void sort();
    int searchchar(const char a);
    ~forest();
    huffmantree manage();
};
#endif