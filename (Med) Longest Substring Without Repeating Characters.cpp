class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> str;
        int mx = 0;
        for(int i=0, j=0; j<s.size(); j++){
            if(str.find(s[j]) != str.end()){
                i = max(str[s[j]], i);
            }
            mx = max(mx, j-i+1);
            str[s[j]] = j+1;
        }
        return mx;
    }
};
