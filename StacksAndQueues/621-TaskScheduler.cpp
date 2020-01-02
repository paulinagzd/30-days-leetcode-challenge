class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for(char c: tasks) {
            m[c] += 1;
        }
        
        priority_queue<int> q;
        for(auto a: m) {
            q.push(a.second);
        }
        
        int res = 0;
        while(!q.empty()) {
            int t = 0;
            vector<int> v;
            for(int i = 0; i < n + 1; ++i) {
                if(!q.empty()) {
                    v.push_back(q.top());
                    q.pop();
                    t++;
                }
            }
            
            for(int i : v) {
                if(--i) {
                    q.push(i);
                }
            }
            res += (!q.empty() ? n+1 : t);
        }
        return res;
    }
};