#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /**
     * 1. 两数之和
     */
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> table;
        for (auto i = 0; i != nums.size(); ++i) {
            table[nums[i]] = i;
        }

        for (auto i = 0; i != nums.size(); ++i) {
            auto iter = table.find(target - nums[i]);
            if (iter != table.end() && iter->second != i) {
                return { i, iter->second };
            }
        }

        return { 0, 0 };
    }

    /**
     * 2. 两数相加
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        bool carry(false);
        int sum(0);
        ListNode* p(nullptr);
        ListNode* ret(nullptr);

        while (l1 && l2) {
            sum = l1->val + l2->val + (carry ? 1 : 0);
            if (carry = (sum >= 10)) {
                sum -= 10;
            }

            auto node = new ListNode(sum);
            if (p) {
                p->next = node;
            } else {
                // first
                ret = node;
            }
            p = node;

            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* left = l1 ? l1 : l2;
        while (left) {
            sum = left->val + (carry ? 1 : 0);
            if (carry = (sum >= 10)) {
                sum -= 10;
            }

            auto node = new ListNode(sum);
            if (p) {
                p->next = node;
            } else {
                // first
                ret = node;
            }
            p = node;

            left = left->next;
        }

        // 尾部进位
        if (carry) {
            p->next = new ListNode(1);
        }

        return ret;
    }

    /**
     * 3. 无重复字符的最长子串
     */
    int lengthOfLongestSubstring(string s)
    {
        int count(0);
        int max(0);
        std::map<char, std::string::iterator> table;

        for (auto start = s.begin(), iter = s.begin(); iter != s.end(); ++iter) {
            auto ch = table.find(*iter);

            if (ch != table.end() && ch->second >= start) {
                max = count > max ? count : max;
                start = ch->second + 1;
                count = iter - start + 1;
            } else {
                ++count;
            }

            table[*iter] = iter;
        }

        return count > max ? count : max;
    }

    /**
     * 4. 寻找两个有序数组的中位数
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        
    }
};

TEST(p1, twoSum)
{
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    auto ret = Solution().twoSum(nums, target);
    ASSERT_EQ(ret[0], 0);
    ASSERT_EQ(ret[1], 1);
}

TEST(p1, addTwoNumbers)
{
    // (2 -> 4 -> 3) + (5 -> 6 -> 4) = (7 -> 0 -> 8)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    auto ret = Solution().addTwoNumbers(l1, l2);
    ASSERT_EQ(ret->val, 7);
    ASSERT_EQ(ret->next->val, 0);
    ASSERT_EQ(ret->next->next->val, 8);
}

TEST(p1, lengthOfLongestSubstring)
{
    ASSERT_EQ(3, Solution().lengthOfLongestSubstring("abcabcbb"));
    ASSERT_EQ(1, Solution().lengthOfLongestSubstring("bbbbb"));
    ASSERT_EQ(3, Solution().lengthOfLongestSubstring("pwwkew"));
    ASSERT_EQ(3, Solution().lengthOfLongestSubstring("ohomm"));
}

TEST(p1, findMedianSortedArrays)
{

}
