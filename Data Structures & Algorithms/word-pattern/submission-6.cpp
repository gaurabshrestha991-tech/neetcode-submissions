class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> words;
        stringstream ss(s);
        string word;

        while(ss >> word) {
            words.push_back(word);
        }
        if(pattern.length() != words.size())
        return false;

        unordered_map<char, string> patternToWord;
        unordered_map<string, char> wordToPattern;

        for(int i = 0; i < pattern.length(); i++) {
            char p = pattern[i];
            string w = words[i];

            if (patternToWord.count(p) && patternToWord[p] != w)
            return false;

            if (wordToPattern.count(w) && wordToPattern[w] != p)
            return false;

            patternToWord[p] = w;
            wordToPattern[w] = p;

        }
        return true;
    }
};