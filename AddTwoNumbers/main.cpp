
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

struct ListNode
{
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* l1_iter    = l1;
        ListNode* l2_iter    = l2;
        ListNode* pre_node   = NULL;
        ListNode* start_node = NULL;
        int       sum        = 0;
        while (l1_iter != NULL || l2_iter != NULL || sum > 0)
        {
            if (l1_iter != NULL)
            {
                sum += l1_iter->val;
                l1_iter = l1_iter->next;
            }

            if (l2_iter != NULL)
            {
                sum += l2_iter->val;
                l2_iter = l2_iter->next;
            }

            ListNode* node = new ListNode(sum % 10);

            if (start_node == NULL)
            {
                start_node = node;
            }

            if (pre_node != NULL)
            {
                pre_node->next = node;
            }

            pre_node = node;
            sum      = sum / 10;
        }

        return start_node;
    }
};

void PrintListNode(ListNode* node)
{
    ListNode* tmp_node = node;
    while (tmp_node != NULL)
    {
        std::cout << tmp_node->val << " ";
        tmp_node = tmp_node->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode l10(2);
    ListNode l11(4);
    ListNode l12(3);

    ListNode l20(5);
    ListNode l21(6);
    ListNode l22(4);

    l10.next = &l11;
    l11.next = &l12;

    l20.next = &l21;
    l21.next = &l22;

    Solution  s;
    ListNode* rst = s.addTwoNumbers(&l10, &l20);
    PrintListNode(rst);

    return 0;
}