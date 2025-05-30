#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *next;
    node(int data)
    {
        val = data;
        next = nullptr;
    }
};

void insert(node *&head, int val)
{
    if (!head)
    {
        head = new node(val);
        return;
    }
    node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new node(val);
}

node *add(node *l1, node *l2)
{
    node *dummy = new node(0);
    node *curr = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr)
    {
        int sum = carry;
        if (l1)
            sum += l1->val;
        if (l2)
            sum += l2->val;

        curr->next = new node(sum % 10);
        carry = sum / 10;
        curr = curr->next;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }

    if (carry)
        curr->next = new node(carry);

    return dummy->next;
}

void printList(node *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *l1 = nullptr;
    node *l2 = nullptr;
    int n1, n2, val;

    cout << "Enter number of nodes in l1: ";
    cin >> n1;
    cout << "Enter values for l1 in reverse order:\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> val;
        insert(l1, val);
    }

    cout << "Enter number of nodes in l2: ";
    cin >> n2;
    cout << "Enter values for l2 in reverse order:\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> val;
        insert(l2, val);
    }

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    node *result = add(l1, l2);
    cout << "Sum List: ";
    printList(result);

    return 0;
}
