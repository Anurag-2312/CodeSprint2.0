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
    if (!head)
    {
        head = new Node(val);
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new Node(val);
}

Node *findmiddle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void print(Node *head)
{
    if (!head)
    {
        cout << "[]";
    }
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

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert(head, val);
    }

    Node *middle = findmiddle(head);
    cout << "Output: ";
    print(middle);

    return 0;
}