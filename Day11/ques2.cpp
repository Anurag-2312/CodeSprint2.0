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

void createCycle(Node *head, int pos)
{
    if (pos == 0)
        return;

    Node *cycleStart = nullptr, *temp = head;
    int index = 1;

    while (temp->next)
    {
        if (index == pos)
            cycleStart = temp;
        temp = temp->next;
        index++;
    }

    if (cycleStart)
        temp->next = cycleStart;
}

bool detectAndRemoveCycle(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {

            slow = head;
            if (slow == fast)
            {
                while (fast->next != slow)
                    fast = fast->next;
                fast->next = nullptr;
                return true;
            }
            else
            {
                while (slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                fast->next = nullptr;
                return true;
            }
        }
    }
    return true;
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
    int n, val, pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert(head, val);
    }

    cout << "Enter position to create cycle : ";
    cin >> pos;
    createCycle(head, pos);

    bool result = detectAndRemoveCycle(head);

    if (result)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }

    return 0;
}
