#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int ALPHABETS_SIZE = 26;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

struct trieNode{
    bool isEnd;
    trieNode* children[ALPHABETS_SIZE];
    trieNode() {
        isEnd = false;
        for (int i = 0; i < ALPHABETS_SIZE; i++) {
            children[i] = NULL;
        }
        return;
    }
};

struct trieTree {
    trieNode* root;
    trieTree() {
        root = new trieNode();
    }
    void insert(string word) {
        trieNode *cur = root;
        for (int i = 0; i < word.size(); i++) {
            int letter = (int)(word[i] - 'a');
            if (cur->children[letter] == NULL) {
                cur->children[letter] = new trieNode();
            }
            cur = cur->children[letter];
        }
        cur->isEnd = true;
        return;
    }
};

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    trieTree *tree;
    vector<string> results;
    void wordSearchIIHelper(int x, int y, string &cur, trieNode *curNode, vector<vector<char> > &board, vector<vector<bool> > &isVisited) {
        int letter = (int)(board[x][y] - 'a');
        if (curNode != NULL && curNode->children[letter] != NULL) {
            if (curNode->children[letter]->isEnd == true) {
                results.push_back(cur);
            }
            for (int i = 0; i < 4; i++) {
                int fx = x + dx[i];
                int fy = y + dy[i];
                if (fx >= 0 && fx < board.size() && fy >= 0 && fy < board[0].size() && isVisited[fx][fy] == false) {
                    cur.insert(cur.end(), board[fx][fy]);
                    isVisited[fx][fy] = true;
                    wordSearchIIHelper(fx, fy, cur, curNode->children[letter], board, isVisited);
                    isVisited[fx][fy] = false;
                    cur.erase(cur.size() - 1, 1);
                }
            }
        }
        return;
    }
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        results.clear();
        tree = new trieTree();
        for (int i = 0; i < words.size(); i++) {
            tree->insert(words[i]);
        }
        if (board.size() > 0 && board[0].size() > 0) {
            vector<vector<bool> > isVisited(board.size(), vector<bool>(board.size(), false));
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    trieNode *curNode = tree->root;
                    string cur = "";
                    cur.insert(cur.end(), board[i][j]);
                    isVisited[i][j] = true;
                    wordSearchIIHelper(i, j, cur, curNode, board, isVisited);
                    isVisited[i][j] = false;
                    cur.erase(cur.size() - 1, 1);
                }
            }
        }
        set<string> sst;
        sst.insert(results.begin(), results.end());
        results.clear();
        results.assign(sst.begin(), sst.end());
        return results;
    }
};

int main() {
    Solution sol;
    vector<vector<char> > board;
    vector<char> b1;
    string bb1 = "abce";
    for (int i = 0; i < bb1.size(); i++) {
        b1.push_back(bb1[i]);
    }
    board.push_back(b1);

    vector<char> b2;
    string bb2 = "sfcs";
    for (int i = 0; i < bb2.size(); i++) {
        b2.push_back(bb2[i]);
    }
    board.push_back(b2);

    vector<char> b3;
    string bb3 = "adee";
    for (int i = 0; i < bb3.size(); i++) {
        b3.push_back(bb3[i]);
    }
    board.push_back(b3);


    vector<string> words;
    words.push_back("abcb");
    words.push_back("ninechapter");
    words.push_back("lintcode");
    //words.push_back("can");
    //words.push_back("again");

    vector<string> results = sol.wordSearchII(board, words);
    for (int i = 0; i < results.size(); i++) {
        cout<<results[i]<<endl;
    }
    return 0;
}
