#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node *next;
    Node(string val)
    {
        data = val;
        next = nullptr;
    }
};

void insert(Node *&head, string val)
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

void print(Node *head)
{
    if (!head)
    {
        cout << "[]";
        return;
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

Node *reverse(Node *head, int left, int right)
{
    if (!head || left == right)
        return head;

    Node *dummy = new Node("dummy");
    dummy->next = head;
    Node *prev = dummy;

    for (int i = 1; i < left; i++)
    {
        prev = prev->next;
    }

    Node *curr = prev->next;
    for (int i = 0; i < right - left; i++)
    {
        Node *temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    head = dummy->next;
    delete dummy;
    return head;
}

int main()
{
    Node *head = nullptr;
    int n, left, right;
    string val;

    cout << "Enter number of items in shopping list: ";
    cin >> n;
    cout << "Enter the items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert(head, val);
    }

    cout << "Enter left and right positions to reverse: ";
    cin >> left >> right;

    Node *result = reverse(head, left, right);
    cout << "Modified Shopping List: ";
    print(result);

    return 0;
}
