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
        // else
        // {
        //     return 0.0;
        // }
    }
    void getLmaxRmin(const std::vector<int>& nums, double& Lmax, double& Rmin)
    {
        if (nums.size() > 0)
        {
            if (nums.size() % 2 == 1)
            {
                Lmax = static_cast<double>(nums[nums.size() / 2 - 1]);
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
    double divideFind(const std::vector<int>& nums1, const std::vector<int>& nums2)
    {
        std::cout << "nums1: ";
        printVector(nums1);
        std::cout << "nums2: ";
        printVector(nums2);
        if (nums1.empty() == true && nums2.empty() == false)
        {
            return getMedia(nums2);
        }

        if (nums1.empty() == false && nums2.empty() == true)
        {
            return getMedia(nums1);
        }

        if (nums1.empty() == false && nums2.empty() == false)
        {
            int    whole_len    = nums1.size() + nums2.size();
            double media1       = getMedia(nums1);
            double media2       = getMedia(nums2);
            int    media_index1 = getMediaIndex(nums1);
            int    media_index2 = getMediaIndex(nums2);
            double Lmax1, Rmin1;
            double Lmax2, Rmin2;
            getLmaxRmin(nums1, Lmax1, Rmin1);
            getLmaxRmin(nums2, Lmax2, Rmin2);

            std::cout << "media1: " << media1 << ", media2: " << media2 << std::endl;
            std::cout << "media_index1: " << media_index1 << ", media_index2: " << media_index2 << std::endl;
            std::cout << "Lmax1: " << Lmax1 << ", Lmax2: " << Lmax2 << std::endl;
            std::cout << "Rmin1: " << Rmin1 << ", Rmin2: " << Rmin2 << std::endl;

            if (Lmax1 <= Rmin2 && Lmax2 <= Rmin1)
            {
                if (whole_len % 2 == 1)
                {
                    return std::min(nums1[media_index1], nums2[media_index2]);
                }
                else
                {
                    return static_cast<double>(std::min(nums1[media_index1], nums2[media_index2]) +
                                               std::max(nums1[media_index1 - 1], nums2[media_index2 - 1])) /
                           2.0;
                }
                // return std::max(media1, media2);
            }

            if (Lmax1 > Rmin2)
            {
                std::vector<int> left1(nums1.begin(), nums1.begin() + media_index1);
                std::vector<int> right2(nums2.begin() + media_index2 + 1, nums2.end());
                return divideFind(left1, right2);
            }

            if (Lmax2 > Rmin1)
            {
                std::vector<int> right1(nums1.begin() + media_index1, nums1.end());
                std::vector<int> left2(nums2.begin(), nums2.begin() + media_index2);
                return divideFind(right1, left2);
            }
        }
    }
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        divideFind(nums1, nums2);
    }
};

int main()
{
    std::vector<int> nums1 = {1, 2, 4, 5, 7, 9};
    std::vector<int> nums2 = {3, 3, 8};
    Solution         solution;
    double           media = solution.findMedianSortedArrays(nums1, nums2);
    std::cout << media << std::endl;
    return 0;
}