#include <iostream>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 0)
        {
            return "";
        }
        if (numRows == 1)
        {
            return s;
        }
        std::string* sarray = new std::string[numRows];
        for (int i = 0; i < numRows; i++)
        {
            sarray[i] = "";
        }
        bool direction = true;  // true up, false down
        int array_index = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            sarray[array_index] += s[i];
            if (direction == true)
            {
                array_index++;
            }
            else
            {
                array_index--;
            }
            if (array_index >= numRows)
            {
                direction = false;
                array_index = numRows - 2;
            }
            if (array_index < 0)
            {
                direction = true;
                array_index = 0 + 1;
            }
        }
        std::string srst = "";
        for (int i = 0; i < numRows; ++i)
        {
            srst += sarray[i];
        }
        delete[] sarray;
        return srst;
    }

    std::string convert2(std::string s, int numRows) {
        if (numRows == 0)
        {
            return "";
        }
        if (numRows == 1)
        {
            return s;
        }

        std::string srst = "";
        int max_stride = numRows * 2 -1 -1;
        std::cout << "max_stride: " << max_stride << std::endl;
        
        for (int i = 0; i < numRows; ++i)
        {
            int index = i;
            bool direction = true;
            int stride = max_stride - i * 2;
            if (stride == 0)
            {
                stride = max_stride;
            }
            while (index < s.size())
            {
                if (direction)
                {
                    stride = max_stride - i * 2;
                    if (stride == 0)
                    {
                        stride = max_stride;
                    }
                    direction = !direction;
                }
                else
                {
                    stride = i * 2;
                    if (stride == 0)
                    {
                        stride = max_stride;
                    }
                    direction = !direction;
                }
                std::cout << "index: " << index << ", s: " << s[index] << std::endl;
                srst = srst + s[index];
                index += stride;
            }
        }

        return srst;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.convert2("PAYPALISHIRING", 4) << std::endl;
    return 0;
}