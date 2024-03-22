// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/
class Solution
{
    public:
        //Function to insert string into TRIE.
        //to create trienode for inserting the wors
        struct TrieNode* getNode(void){
            struct TrieNode* pnode=new TrieNode();
            pnode->isLeaf=false;
            for(int i=0;i<26;i++){
                pnode->children[i]=NULL;
            }
            
            return pnode;
        }
        // function to insert the word for ex when we need to add 'name' 
        void insert(struct TrieNode *root, string key)
        {
           int len=key.length();
           struct TrieNode* pcrawl= root;
           int ind;
           for(int i=0;i<len;i++){
               ind=key[i]-'a';
               if(pcrawl->children[ind]==NULL){
                   pcrawl->children[ind]=getNode();
                   
               }
               pcrawl=pcrawl->children[ind];
           }
           
           pcrawl->isLeaf=true;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            struct TrieNode* pcrawl=root;
          int len=key.length();
            int ind;
            for(int i=0;i<len;i++){
                ind=key[i]-'a';
                if(pcrawl->children[ind]==NULL){
                return false;
                }
                pcrawl=pcrawl->children[ind];
            }
            return (pcrawl->isLeaf);
        }
};
