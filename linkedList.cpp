#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    // bool IsEmpty()
    // {
    //     if (head == NULL)
    //     {
    //         if (head == NULL)
    //         {
    //             return true;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }
    // }

    bool IsEmpty()
    {
        return (head == NULL);
    }

    void InsertFirst(int newValue)
    {
        Node *newNode;
        newNode->data = newValue;
        if (IsEmpty())
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "";
            temp = temp->next;
        }
    }

    int count()
    {
        int Counter;
        Node *temp = head;
        while (temp != NULL)
        {
            Counter++;
            temp = temp->next;
        }
        return Counter;
    }

    bool IsFound(int Key)
    {
        bool Found = false;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == Key)
            {
                Found = true;
            }
            return Found;
        }
    }
};

int main()
{
    LinkedList Lst;
    if (Lst.IsEmpty())
    {
        cout << "The List is Empty\n";
    }
    else
    {
        cout << "The List contains" << Lst.count() << endl;
        int item;
        cout << "Enter item to insert in the list\n";
        cin >> item;
        Lst.InsertFirst(item);
        Lst.display();
        cout << "Enter item to insert in the List\n";
        cin >> item;
        Lst.InsertFirst(item);
        Lst.display();
        cout << "The List contains\n"<< Lst.count() << endl;
        cin >> item;
        Lst.InsertFirst(item);
        Lst.display();
        cout << "Enter item to insert in the List\n";
        cin >> item;
        Lst.InsertFirst(item);
        Lst.display();
    }

    return 0;
}