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

Node *removeduplicates(Node *head)
{
    Node *temp = head;

    while (temp && temp->next)
    {
        Node *temp1 = temp->next;
        if (temp->data == temp1->data)
        {
            temp->next = temp1->next;
            delete temp1;
        }
        else
        {
            temp = temp->next;
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

    cout << "Enter number of elements : ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert(head, val);
    }

    cout << "Original list:\n";
    print(head);

    head = removeduplicates(head);

    cout << "After removing duplicates:\n";
    print(head);

    return 0;
}
