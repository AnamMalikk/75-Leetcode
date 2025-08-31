class Solution {
public:
    bool ispalindrome(const string& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (ispalindrome(s.substr(i, j - i + 1))) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};