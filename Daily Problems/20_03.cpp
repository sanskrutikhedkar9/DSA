/* 669. Merge In Between Linked Lists

You are given two linked lists: list1 and list2 of sizes n and m respectively.
Remove list1's nodes from the ath node to the bth node, and put list2 in their place.*/
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *nodeBeforeA = nullptr, *nodeAfterB = nullptr;
        ListNode* temp = list1;

        // Find the (a-1)th and (b+1)th nodes in list1
        int index = 0;
        while (temp != nullptr) {
            if (index == a - 1) {
                nodeBeforeA = temp;
            }
            if (index == b) {
                nodeAfterB = temp->next;
                break; // No need to continue once we find the (b+1)th node
            }
            temp = temp->next;
            ++index;
        }

        // Link the (a-1)th node to the start of list2
        if (nodeBeforeA != nullptr) {
            nodeBeforeA->next = list2;
        }

        // Find the last node of list2
        ListNode* temp2 = list2;
        while (temp2->next != nullptr) {
            temp2 = temp2->next;
        }

        // Link the last node of list2 to the (b+1)th node of list1
        temp2->next = nodeAfterB;

        return list1;
    }
};

