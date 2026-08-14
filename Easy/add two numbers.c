#include <stdio.h>
#include <stdlib.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry){
        int sum = carry;
        if(l1) { sum += l1->val; l1 = l1->next; }
        if(l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10;
        temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = sum % 10;
        temp->next = NULL;
    }
    return dummy->next;

    
}
int main()
{
    struct ListNode a = {2, NULL};
    struct ListNode b = {4, NULL};
    struct ListNode c = {3, NULL};

    a.next = &b;
    b.next = &c;

    struct ListNode x = {5, NULL};
    struct ListNode y = {6, NULL};
    struct ListNode z = {4, NULL};

    x.next = &y;
    y.next = &z;

    struct ListNode *result = addTwoNumbers(&a, &x);

    while (result != NULL)
    {
        printf("%d ", result->val);
        result = result->next;
    }

    return 0;
}
    