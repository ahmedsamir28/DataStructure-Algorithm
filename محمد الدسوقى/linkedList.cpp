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

    void InsertBefor(int item, int newValue)
    {

        if (IsEmpty())
        {
            InsertFirst(newValue);
        }

        if (IsFound(item))
        {
            Node *newNode = new Node();
            newNode->data = newValue;
            Node *temp = head;
            while (temp != NULL && temp->next->data != item)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "Sorry , item Not Found \n";
        }
    }

    void Append(int newValue)
    {
        if (IsEmpty())
        {
            InsertFirst(newValue);
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            Node *newNode = new Node();
            newNode->data = newValue;
            temp->next = newNode;
            newNode->next = NULL;
        }
    }

    void Delete(int item)
    {
        int deleValue;
        if (IsEmpty())
        {
            cout << "List empty , no items to delete \n";
        }

        Node* delePtr = head;
        if (head->data == item)
        {
            head = head->next;
            deleValue = delePtr->data;
            delete delePtr;
        } else {
            Node *prev = NULL;
            delePtr = head;
            while (delePtr->data != item)
            {
                prev = delePtr;
                delePtr=delePtr->next;
            }
            prev->next = delePtr->next;
            delete delePtr;
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

        cout << "Enter item to search for\n";
        cin >> item;
        if (Lst.IsFound(item))
        {
            cout << "Item Found\n";
        }
        else
        {
            cout << "Item not Found\n";
        }

        int newValue;
        cout << "Enter item and new value to insert\n";
        cin >> item;
        cin >> newValue;
        Lst.InsertBefor(item, newValue);
        Lst.display();

        int newValue;
        cout << "Enter new value to append\n";
        cin >> newValue;
        Lst.Append(newValue);
        Lst.display();

        cout << "Enter item to delete\n";
        cin >> item;
        Lst.Delete(item);
        Lst.display();


    }

    return 0;
}