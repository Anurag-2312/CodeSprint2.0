#include <bits/stdc++.h>
using namespace std;

struct DNode
{
    int val;
    DNode *prev;
    DNode *next;
    DNode(int data)
    {
        val = data;
        prev = nullptr;
        next = nullptr;
    }
};

void insert(DNode *&head, int val)
{
    DNode *newNode = new DNode(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    DNode *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

DNode *del(DNode *head, int target)
{
    DNode *curr = head;
    while (curr)
    {
        if (curr->val == target)
        {
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next;
            if (curr->next)
                curr->next->prev = curr->prev;

            DNode *temp = curr;
            curr = curr->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

void printDList(DNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    DNode *head = nullptr;
    int n, val, target;

    cout << "Enter number of nodes in doubly linked list: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert(head, val);
    }

    cout << "Enter target value to remove: ";
    cin >> target;

    cout << "Original List:\n";
    printDList(head);

    head = del(head, target);

    cout << "Modified List:\n";
    printDList(head);

    return 0;
}
