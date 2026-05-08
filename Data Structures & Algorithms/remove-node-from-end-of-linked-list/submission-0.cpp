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
        int l = 0;
        ListNode* temp = head;
        ListNode dummy = ListNode(0);
        ListNode* dummyPtr = &dummy;

        dummyPtr->next = head;
        while(temp!=nullptr){
            l++;
            temp = temp->next;
        }
        int ln = l-n;
        cout << ln << endl;
        while(ln > 0) {
            dummyPtr = dummyPtr->next;
            ln--;
        }


        dummyPtr->next = dummyPtr->next->next;

        return dummy.next;


    }
};
