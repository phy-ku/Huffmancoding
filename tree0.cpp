#include "tree.h"
#include <iostream>
tree::tree()
{
    left=nullptr;
    right=nullptr;
    letter='\0';
    weight=0;
}
tree::tree(const tree &a,const tree &b)
{
    left=new tree(a);
    right=new tree(b);
    letter='\0';
    weight=a.weight+b.weight;
}
tree::tree(const char a)
{
    letter=a;
    left=nullptr;
    right=nullptr;
    weight=1;
}
tree::tree(const tree& a)
{
    letter=a.letter;
    left=(a.left==nullptr)?nullptr:new tree(*(a.left));
    right=(a.right==nullptr)?nullptr:new tree(*(a.right));
    weight=a.weight;
}
tree& tree::operator=(const tree& a)
{
    if(this==&a)
    {
        return *this;
    }
    delete left;
    delete right;
    left=(a.left==nullptr)?nullptr:new tree(*(a.left));
    right=(a.right==nullptr)?nullptr:new tree(*(a.right));
    weight=a.weight;
    letter=a.letter;
    return *this;
}
bool tree::operator<(const tree& a) const
{
    if(weight<a.weight)
    {
        return true;
    }
    return false;
}
bool tree::operator>(const tree& a) const
{
    if(weight>a.weight)
    {
        return true;
    }
    return false;
}
bool tree::searchchar(const char a)
{
    bool leftf,rightf;
    if(left!=nullptr)
    {
        leftf=left->searchchar(a);
    }
    else
    {
        leftf=false;
    }
    if(right!=nullptr)
    {
        rightf=right->searchchar(a);
    }
    else
    {
        rightf=false;
    }
    if(letter==a or leftf or rightf)
    {
        return true;
    }
    return false;
}
void tree::weightplus()
{
    weight++;
}
tree::~tree()
{
    delete left;
    delete right;
}


huffmantree::huffmantree():tree(){}
huffmantree::huffmantree(const tree& a):tree(a){}
huffmantree::huffmantree(const huffmantree& a):tree(a){}
huffmantree& huffmantree::operator=(const huffmantree& a)
{
    if(this==&a)
    {
        return *this;
    }
    tree::operator=(a);
    return *this;
}
huffmantree::~huffmantree(){}


forest::forest()
{
    trees=nullptr;
    number=0;
}
forest::forest(const char* a)
{
    if(strlen(a)==0)
    {
        trees=nullptr;
        number=0;
    }
    else
    {
        trees=new tree[1];
        trees[0]=tree(a[0]);
        number=1;
        for(int i=1;i<strlen(a);i++)
        {
            if((*this).searchchar(a[i])!=-1)
            {
                trees[(*this).searchchar(a[i])].weightplus();
            }
            else
            {
                tree* temp=new tree[number+1];
                for(int j=0;j<number;j++)
                {
                    temp[j]=trees[j];
                }
                temp[number]=tree(a[i]);
                delete []trees;
                trees=new tree[number+1];
                for(int j=0;j<number+1;j++)
                {
                    trees[j]=temp[j];
                }
                delete []temp;
                number++;
            }
        }
    }
}
forest::forest(const std::string a)
{
    if(a.size()==0)
    {
        trees=nullptr;
        number=0;
    }
    else
    {
        trees=new tree[1];
        trees[0]=tree(a[0]);
        number=1;
        for(int i=1;i<a.size();i++)
        {
            if((*this).searchchar(a[i])!=-1)
            {
                trees[(*this).searchchar(a[i])].weightplus();
            }
            else
            {
                tree* temp=new tree[number+1];
                for(int j=0;j<number;j++)
                {
                    temp[j]=trees[j];
                }
                temp[number]=tree(a[i]);
                delete []trees;
                trees=new tree[number+1];
                for(int j=0;j<number+1;j++)
                {
                    trees[j]=temp[j];
                }
                delete []temp;
                number++;
            }
        }
    }
}
forest& forest::operator=(const forest& a)
{
    if(this==&a)
    {
        return *this;
    }
    delete []trees;
    if(a.number==0)
    {
        trees=nullptr;
        number=0;
        return *this;
    }
    trees=new tree[a.number];
    for(int i=0;i<a.number;i++)
    {
        trees[i]=a.trees[i];
    }
    number=a.number;
    return *this;
}
forest::forest(const forest& a)
{
    trees=new tree[a.number];
    for(int i=0;i<a.number;i++)
    {
        trees[i]=a.trees[i];
    }
    number=a.number;
}
void forest::sort()
{
    for(int i=0;i<number;i++)
    {
        for(int j=0;j<number-1;j++)
        {
            if(trees[j]<trees[j+1])
            {
                tree temp=trees[j];
                trees[j]=trees[j+1];
                trees[j+1]=temp;
            }
        }
    }
}
int forest::searchchar(const char a)
{
    for(int i=0;i<number;i++)
    {
        if(trees[i].searchchar(a))
        {
            return i;
        }
    }
    return -1;
}
forest::~forest()
{
    delete []trees;
}
huffmantree forest::manage()
{
    while(number>1)
    {
        (*this).sort();
        tree temp=tree(trees[number-2],trees[number-1]);
        trees[number-2]=temp;
        number=number-1;
    }
    tree temp=trees[0];
    delete []trees;
    trees=new tree[1];
    *trees=temp;
    number=1;
    return huffmantree(trees[0]);
}