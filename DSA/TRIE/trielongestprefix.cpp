class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isterminal;
    int childcount;
    Trienode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childcount=0;
        isterminal=false;
    }
};
class Trie {
    public:
    Trienode* root;
    Trie(char ch){
        root=new Trienode(ch);
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
            root->childcount++;
            root->children[index]=child;
        }
        insertutil(child,word.substr(1));

    }
    void insertword(string word){
        insertutil(root,word);
    }
    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->childcount==1){
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isterminal){
                break;
            }

        }

    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t = new Trie('\0');
    for(int i = 0; i < n; i++) {
        t->insertword(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);

    return ans;
}


