#include<iostream>
using namespace std;
class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isterminal;
    Trienode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};
class trie{
    public:
    Trienode* root;
    trie(){
        root=new Trienode('\0');
    }
    void insertutil(Trienode* root,string word){
        if(word.length()==0){
            root->isterminal=true;
            return;
        }
        int index=word[0]-'A';
        Trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new Trienode(word[0]);
            root->children[index]=child;
        }
        insertutil(child,word.substr(1));
    }
    void insertword(string word){
        insertutil(root,word);
    }
    bool searchutil(Trienode* root,string word){
        if(word.length()==0){
            return root->isterminal;
        }
        int index=word[0]-'A';
        Trienode* child;
        if(root->children[index] !=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchutil(child,word.substr(1));
    }
    bool search(string word){
        return searchutil(root,word);
    }
};
int main(){
    trie* t = new trie();
    t->insertword("ABCD");
    cout<<"IMPLEMENTATION SUCCESSFUL";
    cout<<"present orr not"<<t->search("ABCD");
    return 0;
}