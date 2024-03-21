/* 206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
#include<iostream>
#include<stack>
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
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode* temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
            
        }

        ListNode* res=new ListNode(-1);
        ListNode* t1=res;
        while(!st.empty()){
            t1->next=new ListNode(st.top());
            t1=t1->next;
            st.pop();
        }
        return res->next;

    }
};

 