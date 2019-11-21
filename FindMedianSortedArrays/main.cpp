#include <iostream>
#include <vector>

class Test
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
        else
        {
            return 0.0;
        }
    }
    void getLmaxRmin(const std::vector<int>& nums, double& Lmax, double& Rmin)
    {
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
            double media1 = getMedia(nums1);
            double media2 = getMedia(nums2);
        }
    }
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
    }
};

int main()
{
}