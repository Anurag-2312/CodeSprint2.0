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

Node *doublenumber(Node *head)
{
    // Reverse the linked list
    Node *prev = nullptr, *curr = head;
    while (curr)
    {
        Node *front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    int carry = 0;
    curr = prev;
    Node *result = nullptr;
    while (curr)
    {
        int sum = curr->data * 2 + carry;
        carry = sum / 10;
        Node *newnode = new Node(sum % 10);
        newnode->next = result;
        result = newnode;
        curr = curr->next;
    }

    if (carry > 0)
    {
        Node *newnode = new Node(carry);
        newnode->next = result;
        result = newnode;
    }

    return result;
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

    cout << "Enter number of digits: ";
    cin >> n;

    cout << "Enter digits :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert(head, val);
    }

    Node *doubled = doublenumber(head);
    cout << "Output: ";
    print(doubled);

    return 0;
}