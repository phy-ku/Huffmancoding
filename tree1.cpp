#include "tree.h"
void writedict(tree& a,std::unordered_map<char,std::string>& dict,std::string nowmm)
{
    if(a.letter!='\0')
    {
        dict.emplace(a.letter,nowmm);
    }
    else
    {
        if(a.left!=nullptr)
        {
            writedict(*(a.left),dict,nowmm+"0");
        }
        if(a.right!=nullptr)
        {
            writedict(*(a.right),dict,nowmm+"1");
        }
    }
}
std::string huffmantree::encoding(const char* a)
{
    using namespace std;
    unordered_map <char,string> dict;
    string nowmm="";
    writedict(*this,dict,nowmm);
    string result="";
    for(int i=0;i<strlen(a);i++)
    {
        result=result+dict[a[i]];
    }
    return result;
}
std::string huffmantree::encoding(const std::string a)
{
    using namespace std;
    unordered_map <char,string> dict;
    string nowmm="";
    writedict(*this,dict,nowmm);
    string result="";
    for(int i=0;i<a.size();i++)
    {
        result=result+dict[a[i]];
    }
    return result;
}
void tree::exshape(std::string& now,std::string& leaf) const
{
    if(letter!='\0')
    {
        now=now+"0";
        leaf+=letter;
    }
    else
    {
        now=now+"1";
        if(left!=nullptr)
        {
            (*left).exshape(now,leaf);
        }
        if(right!=nullptr)
        {
            (*right).exshape(now,leaf);
        }
    }
}