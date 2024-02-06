#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;
    Queue()
    {
        front = rear = NULL;
    }

    bool IsEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Enqueue(int item)
    {
        Node *newNode = new Node();
        newNode->data = item;

        if (IsEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void display()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty no items to display \n";
        }
        else
        {
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int Count()
    {
        int counter = 0;
        Node *temp = front;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool IsFound(int item)
    {
        bool found = false;
        Node *temp = front;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                found = true;
                temp = temp->next;
            }
        }
        return found;
    }

    int Dequeue()
    {
        int delValue = -1;
        if (IsEmpty())
        {
            cout << "The queue is empty \n";
        }
        else if (front == rear)
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            Node *delPtr = front;
            front = front->next;
            delValue = delPtr->data;
            delete delPtr;
        }
        return delValue;
    }

    int getFront()
    {
        return front->data;
    }

    int getRear()
    {
        return front->data;
    }

    void Clear()
    {
        while (!IsEmpty())
        {
            Dequeue();
        }
    }
};

int main()
{
    Queue q;
    for (int i = 1; i <= 3; i++)
    {
        int item;
        cout << "Enter item to Enqueue \n";
        cin >> item;
        q.Enqueue(item);
    }
    q.display();

    q.Dequeue();
    cout << "After deque\n";

    q.display();
    q.Dequeue();
    q.display();

    cout << "Clear All items \n";
    q.Clear();
    cout << "Display after clear\n";
    q.display();

    return 0;
}