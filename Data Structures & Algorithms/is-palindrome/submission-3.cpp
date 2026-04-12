class Solution {
public:
    bool isPalindrome(string s) {
        int p1 = 0, p2 = s.size() - 1;
        while (p1 < p2) {
            while (p1 < p2 && !alphaNum(s[p1]))
                p1++;
            while (p1 < p2 && !alphaNum(s[p2]))
                p2--;
            if (tolower(s[p1]) != tolower(s[p2])) 
                return false;
            p1++;
            p2--;
        }
        return true;
    }
    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z') ||
               (c >= 'a' && c <= 'z') ||
               (c >= '0' && c <= '9');
    }
};
