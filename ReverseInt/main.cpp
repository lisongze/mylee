#include <iostream>
#include <string>
#include <cmath>
#include <limits>

class Solution {
public:
    int reverse(int x) {
        std::string s = std::to_string(x);
        if(s[0] == '-')
        {
            long rst = 0;
            for (int i = 1; i < s.size(); ++i)
            {
                rst += std::stoi(std::string(1, s[i])) * std::pow(10, i - 1);
                if (rst > std::numeric_limits<int>::max() || -rst < std::numeric_limits<int>::min())
                {
                    return 0;
                }
            }
            
            return -rst;
        }
        else
        {
            long rst = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                rst += std::stoi(std::string(1, s[i])) * std::pow(10, i);
                if (rst > std::numeric_limits<int>::max() || -rst < std::numeric_limits<int>::min())
                {
                    return 0;
                }
            }
            return rst;
        }
    }
};

int main()
{
    Solution solution;
    std::cout << solution.reverse(123) << std::endl;
    std::cout << solution.reverse(-123) << std::endl;
    std::cout << solution.reverse(120) << std::endl;
    std::cout << solution.reverse(-2147483648) << std::endl;
    return 0;
}