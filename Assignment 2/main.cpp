#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;
Node *tail = NULL;

void Insert (int position)
{
    int data;
    cout<< "Enter a value to insert";
    cin>> data;

    Node *temp = new Node;
    temp -> data = data;
    temp -> next = NULL;
    temp -> prev = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    if (position == 1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }

    Node *cur = head;
    int count = 1;

    while (count < position - 1 && cur->next != NULL)
    {
        cur = cur->next;
        count++;
    }

    if (cur->next == NULL)
    {
        cur->next = temp;
        temp->prev = cur;
        tail = temp;
    }
    else
    {
        temp->next = cur->next;
        temp->prev = cur;
        cur->next->prev = temp;
        cur->next = temp;
    }
    cout<< "New node inserted";


}

void search(int key)
{
    Node* cur = head;
    while (cur != NULL)
    {
        if (cur->data == key)
        {
            cout << "Found\n";
            return;
        }
        cur = cur->next;
    }
    cout << "Not Found\n";
}

void remove(int key)
{
    Node* temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Not Found\n";
        return;
    }

    if (temp == head)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
    }

    else if (temp == tail)
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Deleted successfully\n";
}

void middle()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data << endl;
}

void display()
{
    Node* temp = head;
    if (temp == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << " - ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    int choice, position, key;

    do
    {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Remove\n";
        cout << "4. Middle\n";
        cout << "5. Display\n";
        cout << "6. End\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter position: ";
            cin >> position;
            Insert(position);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            search(key);
            break;

        case 3:
            cout << "Enter key to remove: ";
            cin >> key;
            remove(key);
            break;

        case 4:
            middle();
            break;

        case 5:
            display();
            break;

        case 6:
            cout << "Program Ended\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}