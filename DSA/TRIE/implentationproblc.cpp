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
class Trie {
    public:
    Trienode* root;
    Trie(){
        root=new Trienode('\0');
    }
    void insertutil(Trienode* root,string word){
        if(word.length()==0){
            root->isterminal=true;
            return;
        }
        int index=word[0]-'a';
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
    bool searchutil(Trienode* root,string word){
        if(word.length()==0){
            return root->isterminal;
        }
        int index=word[0]-'a';
        Trienode* child;
        if(root->children[index] !=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchutil(child,word.substr(1));
    }
    void insert(string word) {
        insertutil(root,word);
    } 
    bool search(string word) {
        return searchutil(root,word);    
    }
    bool startutil(Trienode* root,string word){
        if(word.length()==0){
            return true;
        }
        int index=word[0]-'a';
        Trienode* child;
        if(root->children[index] !=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return startutil(child,word.substr(1));
    }
    bool startsWith(string prefix) {
        return startutil(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */