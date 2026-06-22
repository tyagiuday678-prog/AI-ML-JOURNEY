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
    void insert(string word) {
        insertutil(root,word);
    }
    void printsuggestions(Trienode* curr,vector<string>& temp,string prefix){
        if(curr->isterminal){
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++){
            Trienode* next=curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printsuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>>getsuggestions(string str){
        Trienode* prev=root;
        vector<vector<string>>output;
        string prefix="";
        for(int i=0;i<str.length();i++){
            char lastch=str[i];
            prefix.push_back(lastch);
            Trienode* curr=prev->children[lastch-'a'];
            if(curr==NULL){
                break;
            }
            vector<string>temp;
            printsuggestions(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie* t=new Trie();
    for(int i=0;i<contactList.size();i++){
        string str=contactList[i];
        t->insert(str);
    }
    return t->getsuggestions(queryStr);

}