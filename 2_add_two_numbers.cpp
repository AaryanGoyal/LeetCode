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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (!l1 && !l2) return nullptr;
        else if (!l1) return l2;
        else if (!l2) return l1;
        else {
            int i = (l1->val+l2->val);
            return i/10 ? new ListNode(i%10,addThreeNumbers(i/10,l1->next,l2->next)) 
            : new ListNode(i%10,addTwoNumbers(l1->next,l2->next));
        }
    }

    ListNode* addThreeNumbers(int carry, ListNode* l1, ListNode* l2) {
        
        if (!l1 && !l2) return new ListNode(carry);
        else if (!l1) {
            int i = (l2->val+carry);
            return i/10 ? new ListNode(i%10,addThreeNumbers(i/10,l1,l2->next))
            : new ListNode(i%10,addTwoNumbers(l1,l2->next));
        }
        else if (!l2) {
            int i = (l1->val+carry);
            return i/10 ? new ListNode(i%10,addThreeNumbers(i/10,l1->next,l2))
            : new ListNode(i%10,addTwoNumbers(l1->next,l2));
        }
        int i = (l1->val+l2->val+carry);
        return i/10 ? new ListNode(i%10,addThreeNumbers(i/10,l1->next,l2->next))
            : new ListNode(i%10,addTwoNumbers(l1->next,l2->next));
        
    }
};