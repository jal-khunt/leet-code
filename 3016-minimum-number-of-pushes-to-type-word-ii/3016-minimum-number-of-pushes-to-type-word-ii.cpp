class Solution {
public:

    static bool cmp(const pair<char,int> &a, const pair<char,int> &b){
         return a.second > b.second;
    }

    int minimumPushes(string word) {
        int n = word.length();

        map<char, int> mp;

        for(auto &c : word){
            mp[c]++;
        }
        vector<pair<char,int>> tmp;

        for(auto &it : mp){
            tmp.push_back(it);
        }

        sort(tmp.begin(), tmp.end(), cmp);

        vector<int> pushes(26, 0);

        for(int i = 1; i <= tmp.size(); i++){
            if(i <= 8)
                pushes[tmp[i-1].first - 'a'] = 1;
            else if(i <= 16)
                pushes[tmp[i-1].first - 'a'] = 2;
            else if(i <= 24)
                pushes[tmp[i-1].first - 'a'] = 3;
            else
                pushes[tmp[i-1].first - 'a'] = 4;
        }

        int ans = 0;
        for(auto &c : word){
            ans += pushes[c - 'a'];
        }

        return ans;

    }
};