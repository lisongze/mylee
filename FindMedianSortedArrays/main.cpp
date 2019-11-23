#include <iostream>
#include <vector>

void printVector(const std::vector<int>& vec)
{
    for (auto v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

class Solution
{
public:
    double getMedia(const std::vector<int>& nums)
    {
        if (nums.size() > 0)
        {
            if (nums.size() % 2 == 1)
            {
                return static_cast<double>(nums[nums.size() / 2]);
            }
            else
            {
                return static_cast<double>(nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0;
            }
        }
    }
    void getLmaxRmin(const std::vector<int>& nums, double& Lmax, double& Rmin)
    {
        if (nums.size() > 0)
        {
            if (nums.size() % 2 == 1)
            {
                Lmax = static_cast<double>(nums[nums.size() / 2]);
                Rmin = static_cast<double>(nums[nums.size() / 2]);
            }
            else
            {
                Lmax = static_cast<double>(nums[nums.size() / 2 - 1]);
                Rmin = static_cast<double>(nums[nums.size() / 2]);
            }
        }
    }
    int getMediaIndex(const std::vector<int>& nums)
    {
        if (nums.empty() == true)
        {
            return -1;
        }

        return nums.size() / 2;
    }
    double find(const std::vector<int>& nums1, const std::vector<int>& nums2, int index)
    {
        std::cout << "index: " << index << std::endl;
        std::cout << "nums1: ";
        printVector(nums1);
        std::cout << "nums2: ";
        printVector(nums2);


        if (nums1.empty() == true)
        {
            return nums2[index];
        }

        if (nums2.empty() == true)
        {
            return nums1[index];
        }

        if (nums1.size() == 1 && nums2.size() == 1)
        {
            return index ? std::max(nums1[0], nums2[0]) : std::min(nums1[0], nums2[0]);   
        }
        
        if (index == 0)
        {
            return std::min(nums1[0], nums2[0]);
        }
        else
        {
            int    whole_len    = nums1.size() + nums2.size();
            int    media_index1 = getMediaIndex(nums1);
            int    media_index2 = getMediaIndex(nums2);
            double Lmax1, Rmin1;
            double Lmax2, Rmin2;
            getLmaxRmin(nums1, Lmax1, Rmin1);
            getLmaxRmin(nums2, Lmax2, Rmin2);

            // std::cout << "media1: " << media1 << ", media2: " << media2 << std::endl;
            std::cout << "media_index1: " << media_index1 << ", media_index2: " << media_index2 << std::endl;
            std::cout << "Lmax1: " << Lmax1 << ", Lmax2: " << Lmax2 << std::endl;
            std::cout << "Rmin1: " << Rmin1 << ", Rmin2: " << Rmin2 << std::endl;

            if (Lmax1 <= Rmin2 && Lmax2 <= Rmin1)
            {
                if (index >= whole_len / 2)
                {
                    std::vector<int> new_nums1(nums1.begin() + nums1.size() / 2, nums1.end());
                    std::vector<int> new_nums2(nums2.begin() + nums2.size() / 2, nums2.end());
                    int new_index = index - nums1.size() / 2 - nums2.size() / 2;
                    return find(new_nums1, new_nums2, new_index);
                }
                else
                {
                    std::vector<int> new_nums1(nums1.begin(), nums1.begin() + nums1.size() / 2 + nums1.size() % 2);
                    std::vector<int> new_nums2(nums2.begin(), nums2.begin() + nums2.size() / 2 + nums2.size() % 2);
                    int new_index = index;
                    return find(new_nums1, new_nums2, new_index);
                }
            }

            if (Lmax1 > Rmin2)
            {
                std::vector<int> new_nums1;
                std::vector<int> new_nums2;

                if (index < whole_len / 2 + whole_len % 2)
                {
                    new_nums1.insert(new_nums1.begin(), nums1.begin(), nums1.begin() + nums1.size() / 2);
                    new_nums2.insert(new_nums2.begin(), nums2.begin(), nums2.end());
                    int new_index = index;
                    return find(new_nums1, new_nums2, new_index);
                }
                else
                {
                    new_nums1.insert(new_nums1.begin(), nums1.begin(), nums1.end());
                    new_nums2.insert(new_nums2.begin(), nums2.begin() + nums2.size() / 2 + nums2.size() % 2, nums2.end());
                    int new_index = index - nums2.size() / 2 - nums2.size() % 2;
                    return find(new_nums1, new_nums2, new_index);
                }
            }

            if (Lmax2 > Rmin1)
            {
                std::vector<int> new_nums1;
                std::vector<int> new_nums2;

                if (index < whole_len / 2 + whole_len % 2)
                {
                    new_nums2.insert(new_nums2.begin(), nums2.begin(), nums2.begin() + nums2.size() / 2);
                    new_nums1.insert(new_nums1.begin(), nums1.begin(), nums1.end());
                    int new_index = index;
                    return find(new_nums1, new_nums2, new_index);
                }
                else
                {
                    new_nums2.insert(new_nums2.begin(), nums2.begin(), nums2.end());
                    new_nums1.insert(new_nums1.begin(), nums1.begin() + nums1.size() / 2 + nums1.size() % 2, nums1.end());
                    int new_index = index - nums1.size() / 2 - nums1.size() % 2;
                    return find(new_nums1, new_nums2, new_index);
                }
            }
        }
    }
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int whole_len = nums1.size() + nums2.size();
        if (whole_len % 2 == 1)
        {
            return find(nums1, nums2, whole_len / 2);
        }
        else
        {
            double low = find(nums1, nums2, whole_len / 2 - 1);
            double high = find(nums1, nums2, whole_len / 2);
            return (low + high) / 2.0;
        }
    }
};

int main()
{
    std::vector<int> nums1 = {1, 2, 4, 5, 7, 9};
    std::vector<int> nums2 = {3, 3, 8};
    // std::vector<int> nums2 = {1, 2, 4, 5, 6};
    // std::vector<int> nums1 = {3};
    // std::vector<int> nums1 = {7, 8};
    // std::vector<int> nums2 = {1,2,3,4,5,6,9,10};
    // std::vector<int> nums1 = {1};
    // std::vector<int> nums2 = {2, 3, 4};
    // std::vector<int> nums1 = {5, 6};
    // std::vector<int> nums2 = {1, 2, 3, 4, 7, 8};
    Solution         solution;
    double           media = solution.findMedianSortedArrays(nums1, nums2);
    std::cout << media << std::endl;
    return 0;
}