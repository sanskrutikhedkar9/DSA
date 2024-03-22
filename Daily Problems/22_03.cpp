/**234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a  palindrome or false otherwise.
 */
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast=head;
        ListNode* slow=head;
        stack<int> st;
        while(fast!=NULL and fast->next!=NULL){
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL){
            slow=slow->next;
        }
        while(slow!=NULL){
            
                if(st.top()!=slow->val){
                    return false;
                }
                st.pop();
            
            slow=slow->next;
        }
        return true;
    }
};