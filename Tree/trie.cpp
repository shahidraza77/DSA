#include <iostream>
using namespace std;
struct TrieNode{
    struct TrieNode* child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
           child[i]=NULL;
    }
};
TrieNode* root=new TrieNode();
void insert(string &key)
{
    TrieNode* curr=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(curr->child[index]==NULL)
           curr->child[index]=new TrieNode();
          curr=curr->child[index];
    }
    curr->isEnd=true;
}
bool search(string &key)
{
    TrieNode* curr=root;
    for(int i=0;i<key.length();i++)
       {
           int index=key[i]-'a';
           if(curr->child[index]==NULL)
             return false;
             curr=curr->child[index];
       }
       return curr->isEnd;
}
    
int main() {
  //code
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      string dict[n];
      for(int i=0;i<n;i++)
      {
          cin>>dict[i];
      }
      string str;
      cin>>str;
       for(int i=0;i<n;i++)
      {
          insert(dict[i]);
      }
     cout<<search(str)<<endl;
  }
  return 0;
}