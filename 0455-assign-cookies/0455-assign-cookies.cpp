class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int children = g.size();
        int cookies  = s.size();

        if(children == 0 || cookies == 0)
            return 0;

        int i = 0, j = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(i < cookies && j < children){
            if(s[i] >= g[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return j;
    }
};