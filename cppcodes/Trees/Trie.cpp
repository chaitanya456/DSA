#include<bits/stdc++.h>
using namespace std;
class Trie
{
    public:
    Trie* children[26];
    bool isWord;
    Trie()
    {
        int i;
        for(i=0;i<26;i++)
        children[i]=NULL;
        isWord=false;
    }
};
void insert(Trie* root, string &s)
{
    Trie* cur=root;
    for(char c: s)
    {
        if(!cur->children[c-'a'])
        cur->children[c-'a']=new Trie();
        cur=cur->children[c-'a'];
    }
    cur->isWord=true;
}
bool search(Trie* root, string &s)
{
    Trie* cur=root;
    for(char c: s)
    {
        if(!cur->children[c-'a'])
        return 0;
        cur=cur->children[c-'a'];
    }
    return cur->isWord;
}
bool isPrefix(Trie* root, string &s)
{
    Trie* cur=root;
    for(char c: s)
    {
        if(!cur->children[c-'a'])
        return 0;
        cur=cur->children[c-'a'];
    }
    return true;
}
bool isEmpty(Trie* root)
{
    int i;
    for(i=0;i<26;i++)
    if(root->children[i])
    return 0;
    return 1;
}
Trie* remove(Trie* root, string &s, int depth)
{
    if(!root)
    return NULL;
    if(depth==s.size())
    {
        if(root->isWord)
        root->isWord=false;
        if(isEmpty(root))
        {
            delete root;
            root=NULL;
        }
        return root;
    }
    int index=s[depth]-'a';
    root->children[index]=remove(root->children[index],s,depth+1);
    if(isEmpty(root) && !root->isWord)
    {
        delete root;
        root=NULL;
    }
    return root;
}
Trie* removeRoot(Trie* root, string s)
{
    int depth=0;
    return remove(root,s,depth);
}
int main()
{
    Trie* root=new Trie();
    vector<string>a={"and", "ant", "do", "dad"};
    for(auto &x: a)
    insert(root,x);
    vector<string> searchKeys = {"do", "gee", "bat","ant"};
    for(auto &x: searchKeys)
    {
        if(search(root,x))
        cout<<x<<"->Yes, It exists"<<endl;
        else cout<<"No, It doesn't exists"<<endl;
    }
    removeRoot(root,"ant");
    cout<<"\nChecking for the word ant:\t";
    string searchingWord="ant";
    if(search(root,searchingWord))
    cout<<"It exists";
    else cout<<"It doesn't exists";
    return 0;
}