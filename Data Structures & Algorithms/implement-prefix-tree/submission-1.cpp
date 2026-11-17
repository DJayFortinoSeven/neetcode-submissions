class TrieNode{
    public:
    unordered_map<char,TrieNode*> nodes;
    bool end;
};

class PrefixTree {
public:

    TrieNode* root;
    PrefixTree() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        
        TrieNode* head =root;
        int i =0;

        while(head->nodes[word[i]]!=nullptr){
            head = head->nodes[word[i]];
            i++;
        }

        while(i<word.size()){
            TrieNode *root = new TrieNode();
            head->nodes[word[i]]=root;
            head = head->nodes[word[i]];
            i++;
        }
        head->end = true;
    }
    
    bool search(string word) {
        TrieNode* head =root;
        for(auto &s:word){
            head = head->nodes[s];
            if(head == nullptr){
                return false;
            }

            if(s == word.back() and head->end){
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* head =root;

        for(char &s:prefix){
            head = head->nodes[s];
            if(head == nullptr){
                return false;
            }
        }
        return true;
    }
};
