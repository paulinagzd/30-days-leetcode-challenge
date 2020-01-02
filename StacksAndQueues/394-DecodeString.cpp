class Solution {
public:
    string decodeString(string s) {
        string word = "";
        stack<string> str;
        stack<int> numb;
        int num = 0;
        for(char c : s) {
            if(isdigit(c)) {
                num = num*10 + (c-'0');
            } else if(isalpha(c)) {
                word += c;
            } else if(c == '[') {
                str.push(word);
                numb.push(num);
                word = "";
                num = 0;
            } else {
                string now = word;
                while(numb.top() > 1) {
                    --numb.top();
                    word += now;
                }
                word = str.top() + word;
                str.pop();
                numb.pop();
            }
        }
        return word;
    }
};