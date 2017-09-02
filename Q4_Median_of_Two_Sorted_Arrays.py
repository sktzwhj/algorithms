'''
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
'''
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        len_nums1 = len(nums1)
        len_nums2 = len(nums2)
        shorter_nums = nums1
        longer_nums = nums2
        len_shorter = len_nums1
        len_longer = len_nums2
        if len_nums1 > len_nums2:
            shorter_nums = nums2
            longer_nums = nums1
            len_shorter = len_nums2
            len_longer = len_nums1
        imin = 0
        imax = len_shorter
        half_len = (len_shorter + len_longer + 1) / 2
        while imin <= imax:
            i = (imin + imax)/2
            j = half_len - i
            if  i > 0 and shorter_nums[i-1] > longer_nums[j]:
                #i is too large, need to reduce
                imax = imax - 1
            elif  i < len_shorter and longer_nums[j-1] > shorter_nums[i]:
                #i is too small, need to increase
                imin = imin + 1
            else:
                odd = False
                if (len_shorter + len_longer)%2 == 1:
                    odd = True
                max_left = 0
                min_right = 0

                #for max_left, when we do not need to find max, i == 0, or j == 0
                if i == 0: max_left = longer_nums[j-1]
                elif j == 0: max_left = shorter_nums[i-1]
                #otherwise we need to consider max
                else:max_left = max(longer_nums[j-1],shorter_nums[i-1])

                if odd:
                    return max_left
                #for min_right, when we do not need to find min, i == len_shorter or j == len_longer
                if i == len_shorter: min_right = longer_nums[j]
                elif j == len_longer: min_right = shorter_nums[i]
                else:min_right = min(longer_nums[j],shorter_nums[i])

                return (max_left+min_right)/2.0



s = Solution()
print s.findMedianSortedArrays([1,2],[3,4])