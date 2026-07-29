/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /**
        Solution:
            - Calculate number of element k so the node to be removed is k - n + 1
            - Traversal and find the node to be deleted
        
        Example:
            1     2        4 , n = 2
            head
                              curr
                first
            numberOfNodes = 4
            nodeToRemove = 2
        **/

        int numberOfNodes = 0;
        auto curr = head;
        while (curr){
            numberOfNodes++;
            curr=curr->next;
        }
        auto nodeToRemove = numberOfNodes - n + 1;
        
        if (nodeToRemove == 1){
            return head->next;
        }

        auto first = head;
        while (first){
            nodeToRemove -= 1;
            if (nodeToRemove == 1){
                auto temp = first->next;
                first->next = first->next->next;
                // delete temp; // Optional: clean up memory
                return head;
            }
            first = first->next;
        }
        return head;
    }
};
