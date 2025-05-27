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

Node *sort(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *prev = head;
    Node *curr = head->next;

    while (curr)
    {
        if (curr->data < 0)
        {
            prev->next = curr->next;

            curr->next = head;
            head = curr;

            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
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

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert(head, val);
    }

    cout << "Original List:\n";
    print(head);

    head = sort(head);

    cout << "Sorted by Actual Values:\n";
    print(head);

    return 0;
}
