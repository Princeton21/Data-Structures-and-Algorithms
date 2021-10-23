"""
Title: 4. Median of Two Sorted Arrays
Difficulty: Hard
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Examples:

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000

Constraints:
- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -106 <= nums1[i], nums2[i] <= 106
"""


def findMedianSortedArrays(self, nums1, nums2) -> float:
    i, j = 0, 0
    total_len = len(nums1) + len(nums2)
    middle_index = total_len // 2
    prev, curr = 0, 0
    counter = 0
    while counter <= middle_index:
        prev = curr
        if i < len(nums1) and (j >= len(nums2) or nums1[i] < nums2[j]):
            curr = nums1[i]
            i += 1
        else:
            curr = nums2[j]
            j += 1
        counter += 1
    if total_len % 2 == 0:
        return (prev + curr) / 2
    return curr