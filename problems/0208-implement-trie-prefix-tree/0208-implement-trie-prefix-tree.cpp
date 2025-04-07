class Trie {
    struct TreeNode
    {
        vector<shared_ptr<TreeNode>> chldn;
        bool isEOW;
        TreeNode()
        {
            chldn.resize(26, nullptr);
            isEOW = false;
        }
    };
    shared_ptr<TreeNode> root;
public:
    Trie() {
        root = make_shared<TreeNode>();
    }
    
    void insert(string word) {
        shared_ptr<TreeNode> curr = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (!curr->chldn[idx])
                curr->chldn[idx] = make_shared<TreeNode>();
            curr = curr->chldn[idx];
        }
        curr->isEOW = true;
    }

    bool search(string word) {
        shared_ptr<TreeNode> curr = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (!curr->chldn[idx])
                return false;
            curr = curr->chldn[idx];
        }
        return curr->isEOW;
    }

    bool startsWith(string prefix) {
        shared_ptr<TreeNode> curr = root;
        for (char ch : prefix)
        {
            int idx = ch - 'a';
            if (!curr->chldn[idx])
                return false;
            curr = curr->chldn[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */