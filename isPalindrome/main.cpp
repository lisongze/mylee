#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(const std::string& s)
    {
        if (s.empty() == true)
        {
            return true;
        }
        if (s.size() == 1)
        {
            return true;
        }
        if (s[0] == s[s.size() - 1])
        {
            return isPalindrome(s.substr(1, s.size() - 2));
        }
        else
        {
            return false;
        }
    }
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);
        return isPalindrome(s);
    }
};

int main()
{
    Solution solution;
    std::cout << solution.isPalindrome(121) << std::endl;
    return 0;
}