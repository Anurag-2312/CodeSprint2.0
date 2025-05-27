#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void insert(Node *&head, int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        return;
    }

    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new Node(val);
}

Node *sortColors(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *temp0 = new Node(-1);
    Node *temp1 = new Node(-1);
    Node *temp2 = new Node(-1);

    Node *zero = temp0, *one = temp1, *two = temp2;
    Node *curr = head;

    while (curr)
    {
        if (curr->data == 0)
        {
            zero->next = curr;
            zero = zero->next;
        }
        else if (curr->data == 1)
        {
            one->next = curr;
            one = one->next;
        }
        else
        {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    // Connect the 0s -> 1s -> 2s
    zero->next = temp1->next ? temp1->next : temp2->next;
    one->next = temp2->next;
    two->next = nullptr;

    Node *newHead = temp0->next;

    delete temp0;
    delete temp1;
    delete temp2;

    return newHead;
}

void print(Node *head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    int n, val;

    cout << "Enter number of packages: ";
    cin >> n;

    cout << "Enter package color codes :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert(head, val);
    }

    cout << "Original List:\n";
    print(head);

    head = sortColors(head);

    cout << "Sorted by Package Colors:\n";
    print(head);

    return 0;
}
