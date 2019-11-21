#include <cstring>
#include <iostream>
#include <string>

class Solution
{
public:
    std::string longestPalindrome(const std::string& s)
    {
        if (s.empty() == true)
        {
            return "";
        }

        if (s.size() == 1)
        {
            return s;
        }

        int   longest = 1;
        int   start   = 0;
        int   len     = s.size();
        char* dp      = new char[len * len];
        std::memset(dp, 0, len * len * sizeof(char));

        // for length 1
        for (int i = 0; i < len; ++i)
        {
            dp[i * len + i] = 1;
        }

        // for length 2
        for (int i = 0; i < len - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                dp[i * len + i + 1] = 1;
                start               = i;
                longest             = 2;
            }
        }

        // for length >= 3
        for (int l = 3; l <= len; ++l)
        {
            // std::cout << "l: " << l << std::endl;
            for (int i = 0; i <= len - l; ++i)
            {
                int s_start = i;
                int s_end   = i + l - 1;
                // std::cout << "start: " << s_start << ", end: " << s_end << std::endl;
                if (s[s_start] == s[s_end] && dp[(s_start + 1) * len + s_end - 1] == 1)
                {
                    dp[s_start * len + s_end] = 1;
                    start                     = s_start;
                    longest                   = l;
                    // std::cout << s.substr(s_start, l) << std::endl;
                }
            }
        }

        return s.substr(start, longest);
    }
};

int main()
{
    Solution    solution;
    std::string s = "ababdcbabc";
    std::cout << solution.longestPalindrome(s) << std::endl;
    return 0;
}