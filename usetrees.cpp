#include "tree.h"
int main()
{
    using namespace std;
    string words;
    cin>>words;
    forest a=forest(words);
    huffmantree b;
    b=a.manage();
    string comprs=b.encoding(words);
    string shape="",letters="";
    b.exshape(shape,letters);
    cout<<comprs;
    return 0;
}