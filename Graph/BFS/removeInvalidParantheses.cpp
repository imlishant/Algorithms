#include <bits/stdc++.h>
using namespace std;

class Solution{
    bool isBalanced(string s){
        int count = 0;
        for(char c : s){
            if(c == '(')
                count++;
            else if(c == ')')
                count--;
            if(count < 0) return 0;
        }
        return count == 0;
    }

public:
    unordered_map<string, bool> vis;
    vector<string> removeInvalidParantheses(string s){
        queue<string> Q;
        vector<string> ans;
        Q.push(s);
        int found = 0;
        while(Q.empty() == false){
            string u = Q.front();
            //cerr << u << "\n";
            Q.pop();
            if(vis[u] == 1) continue;
            vis[u] = 1;
            if(isBalanced(u)){
                found = 1;
                ans.push_back(u);
                //cerr << u << "\n";
            }
            if(found) continue;
            for(unsigned int i = 0; i < u.size(); i++){
                if(u[i] == ')' or u[i] == '('){
                    string v = u.substr(0, i) + u.substr(i+1, u.size());
                    Q.push(v);
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<string> result = s.removeInvalidParantheses("(a)())()");
    for(string curr : result)
        cout << curr << " ";
    return 0;
}