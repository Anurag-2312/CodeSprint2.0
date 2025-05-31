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

Node *merge(Node *list1, Node *list2)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list2->data >= list1->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    return dummy->next;
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
    Node *list1 = nullptr, *list2 = nullptr;
    int n1, n2, val;

    cout << "Enter number of nodes for list 1 : ";
    cin >> n1;

    cout << "Enter node values:\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> val;
        insert(list1, val);
    }

    cout << "Enter number of nodes for list 2 : ";
    cin >> n2;

    cout << "Enter node values:\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> val;
        insert(list2, val);
    }

    Node *merged = merge(list1, list2);
    cout << "Merged List: ";
    print(merged);

    return 0;
}