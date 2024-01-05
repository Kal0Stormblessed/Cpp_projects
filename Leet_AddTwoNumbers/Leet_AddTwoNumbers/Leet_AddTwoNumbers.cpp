// Leet_AddTwoNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy->next;
    }

    void printList(ListNode* head) {
        while (head) {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
    ListNode* createList(const std::vector<int>& values) {
        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        for (size_t i = 1; i < values.size(); ++i) {
            current -> next = new ListNode(values[i]);
            current = current->next;
        }
        return head;
    }

    void testAddTwoNumbers(const std::vector<int>& values1,const std::vector<int>& values2) {
        ListNode* l1 = createList(values1);
        ListNode* l2 = createList(values2);

        std::cout << "Input 1: ";
        printList(l1);
        std::cout << "input 2: ";
        printList(l2);

        ListNode* result = addTwoNumbers(l1, l2);

        std::cout << "Output: ";
        printList(result);
        std::cout << "----------------------------------" << std::endl;
    }
};

int main()
{
    Solution solution;

    solution.testAddTwoNumbers({ 2,4,3 }, { 5,6,4 });
   
}

