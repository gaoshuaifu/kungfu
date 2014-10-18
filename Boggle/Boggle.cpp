#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>
#define ALPHABET 26
using namespace std;

struct TrieNode{
public:
    char val;
    bool isWordEnd;
    TrieNode* kids[ALPHABET];

    TrieNode(char val){
        this->val = val;
        this->isWordEnd = false;
        for(int i = 0; i < ALPHABET; i++)
            kids[i] = NULL;
    }

    ~TrieNode(){
        for(int i = 0; i < ALPHABET; i++){
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

    bool prefixExist(string word){
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->getChild(word[i]))
                curr = curr->getChild(word[i]);
            else
                return false;
        }
        return true;
    }

    bool wordExist(string word){
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
        if(wordExist(word))
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


class Solution{
public:
    bool isInBound(vector<vector<char> >& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        return (i >= 0 && i <= m - 1) && (j >= 0 && j <= n - 1);
    }

    void searchHelper(vector<vector<char> >& board, map<int, map<int, bool> >& visited, int i, int j, Trie& dict, string& word, vector<string>& res){
        if(!isInBound(board, i, j) || visited[i][j])
            return;

        visited[i][j] = true;
        word.push_back(board[i][j]);

        if(!dict.prefixExist(word)){
            visited[i][j] = false;
            word.erase(word.end() - 1);
            return;
        }

        if(dict.wordExist(word))
            res.push_back(word);

        for(int di = -1; di <= 1; di++){
            for(int dj = -1; dj <= 1; dj++){
                if(di == 0 && dj == 0)
                    continue;
                searchHelper(board, visited, i + di, j + dj, dict, word, res);
            }
        }

        word.erase(word.end() - 1);
        visited[i][j] = false;
    }

    vector<string> search(vector<vector<char> >& board, Trie& dict){
        vector<string> res;

        int m = board.size();
        if(m == 0) return res;

        int n = board[0].size();
        if(n == 0) return res;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                map<int, map<int, bool> > visited;
                string word;
                searchHelper(board, visited, i, j, dict, word, res);
            }
        }
        return res;
    }
};

int main(){
    // initialize board
    int a[4][4] = {
        {'n', 'o', 'w', 'a'},
        {'e', 's', 'o', 'b'},
        {'d', 'h', 'e', 't'},
        {'y', 'd', 'r', 'u'}
    };

    vector<vector<char> > board;
    for(int i = 0; i < 4; i++){
        vector<char> row = vector<char>(a[i], a[i] + 4);
        board.push_back(row);
    }

    // initialize word list
    vector<string> words;

    // existing words
    words.push_back("reddens");
    words.push_back("desert");
    words.push_back("denser");
    words.push_back("shred");
    words.push_back("hens");
    words.push_back("toes");
    words.push_back("hen");
    words.push_back("toe");

    // unexisting words
    words.push_back("hello");
    words.push_back("world");
    words.push_back("java");
    words.push_back("python");
    words.push_back("perl");
    words.push_back("egg");
    words.push_back("cheese");
    words.push_back("toast");

    // initialize trie
    Trie dict;
    for(int i = 0; i < words.size(); i++)
        dict.insert(words[i]);

    Solution solution;
    vector<string> res = solution.search(board, dict);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << "\n";

    return 0;
}

