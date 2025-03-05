#include "llrec.h"
//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if (head == nullptr)
    {
        //basecase
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node *current = head;
    llpivot(head->next, smaller, larger, pivot);
    current->next = nullptr;

    if (current->val <= pivot)
    {
        current->next = smaller;
        smaller = current;
    }
    else
    {
        current->next = larger;
        larger = current;
    }

    head = nullptr;
}