struct TrieNode{
public:
    char val;
    bool isWordEnd;
    TrieNode* kids[26];

    TrieNode(char val){
        this->val = val;
        this->isWordEnd = false;
        for(int i = 0; i < 26; i++)
            kids[i] = NULL;
    }

    ~TrieNode(){
        for(int i = 0; i < 26; i++){
            if(kids[i])
                delete kids[i];
        }
    }

    TrieNode* getChild(char val){
        return kids[val - 'a'];
    }

    void setChild(char val){
        if(!kids[val - 'a'])
            kids[val - 'a'] = new TrieNode(val);
    }
};

class Trie{
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode(' ');
    }

    ~Trie(){
        delete root;
    }

    bool startsWith(string word){
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->getChild(word[i]))
                curr = curr->getChild(word[i]);
            else
                return false;
        }
        return true;
    }

    bool search(string word){
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->getChild(word[i]))
                curr = curr->getChild(word[i]);
            else
                return false;
        }
        return curr->isWordEnd;
    }

    void insert(string word){
        if(search(word))
            return;

        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->getChild(word[i]))
                curr = curr->getChild(word[i]);
            else{
                curr->setChild(word[i]);
                curr = curr->getChild(word[i]);
            }
        }
        curr->isWordEnd = true;
    }
};
