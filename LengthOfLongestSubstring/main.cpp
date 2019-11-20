#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

class Test
{
public:
    int lengthOfLongestSubstring(const std::string& s)
    {
        std::unordered_map<char, int> m;
        size_t                        start_pos = 0;
        size_t                        len       = 0;
        size_t                        max_len   = len;
        for (size_t pos = 0; pos < s.size(); ++pos)
        {
            char                                    c    = s[pos];
            std::unordered_map<char, int>::iterator iter = m.find(c);
            if (iter == m.end())
            {
                m[c] = pos;
                len++;
            }
            else
            {
                size_t last_pos = m[c];
                max_len         = std::max(max_len, len);
                start_pos       = std::max(last_pos + 1, start_pos);
                len             = pos - start_pos + 1;
                m[c]            = pos;
            }
            std::cout << "pos: " << pos << ", char: " << std::string(1, c) << ", max_len: " << max_len
                      << ", len: " << len << std::endl;
        }

        max_len = std::max(max_len, len);
        return max_len;
    }
};

int main()
{
    std::string s = "abdaccehfg";
    // std::string s = "abcabcbb";
    // std::string s = "tmmzuxt";
    Test solution;
    std::cout << solution.lengthOfLongestSubstring(s) << std::endl;

    return 0;
}