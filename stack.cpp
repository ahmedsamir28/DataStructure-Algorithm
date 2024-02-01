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

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    bool IsEmpty()
    {
        if (top = NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Push(int item)
    {
        Node *newNode = new Node();
        newNode->data = item;
        if (IsEmpty())
        {
            newNode->next = NULL;
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    int Pop()
    {
        int value;
        Node* delPtr= top;
        value = top->data;
        top = top->next;
    }

    int Peek(){
        return top->data;
    }

    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "";
            temp = temp->next;
        }
        cout << endl;
    }

    int Count(){
        int Counter = 0;
        Node* temp = top;
        while (temp != NULL)
        {
            Counter++;
            temp = temp->next;
        }
        return Counter;
    }

    bool IsFound(int item){
        bool Found =false;
        Node* temp = top;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                Found = true;
                temp = temp->next;
            }
            return Found;
        }
        
    }

    bool IsEmpty(){
        if (top == NULL)
        {
            return true;
        } else{
            return false;
        }
    }

    bool IsFull(){
        Node* ptr= new Node();
        if (ptr == NULL)
        {
            cout << "the stack is full . cannot add more items \n";
        }
        
    }
};

int main()
{
    int item;
    Stack s;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Item to push \n";
        cin >> item;
        s.Push(item);
        s.display();
    }
    cout << s.Pop()<<"was deleted from stack \n";
    s.display();
    cout << "Enter item to search for \n";
    cin >> item;

    if (s.IsFound(item))
    {
        cout << "IS found \n";
    } else {
        cout << "Not found \n";
        cout << s.Count();
    }
    

    return 0;
}