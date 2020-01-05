class Solution {
public:
    void recurser(string &S, int i, vector<string> &v) {
        if(i == int(S.length())) {
            v.push_back(S);
            return;
        }
        
        char c = S[i];
        S[i] = (islower(S[i]) ? toupper(S[i]) : tolower(S[i]));
        recurser(S, i + 1, v);
        if(isalpha(S[i])) {
            S[i] = c;
            recurser(S, i+1, v);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> v;
        recurser(S, 0, v);
        return v;
    }
};