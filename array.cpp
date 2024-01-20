#include <iostream>
using namespace std;

class Array
{
private:
    int size;
    int length;
    int *items;

public:
    Array(int arraySize)
    {
        size = arraySize;
        length = 0;
        items = new int[arraySize];
    }

    void Fill()
    {
        int no_of_items;
        cout << "How many items you want to fill ? \n";
        cin >> no_of_items;
        if (no_of_items > size)
        {
            cout << "You cannot exceed the array size \n";
            return;
        }

        else
        {
            for (int i = 0; i < no_of_items; i++)
            {
                cout << "Enter item no " << i << endl;
                cin >> items[i];
                length++;
            }
        }
    }

    void Display()
    {
        cout << "Display Array Content\n";
        for (int i = 0; i < length; i++)
        {
            cout << items[i] << "\t";
        }
        cout << endl;
    }

    int getSize()
    {
        return size;
    }
    int getLength()
    {
        return length;
    }

    int Search(int key)
    {
        int index = -1;
        for (int i = 0; i < length; i++)
        {
            if (items[i] == key)
            {
                index = i;
                break;
            }
        }
        return index;
    }

    void Append(int newItem)
    {
        if (length < size)
        {
            items[length] = newItem;
            length++;
        }
        else
        {
            cout << "Array is full \n";
        }
    }

    void Insert(int index, int newItem)
    {
        if (index >= 0 && index < size)
        {
            for (int i = length; i > index; i--)
            {
                items[i] = items[i - 1];
            }
            items[index] = newItem;
            length++;
        }
        else
        {
            cout << "Error - index  out of range \n";
        }
    }

    void Delete(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < length - 1; i++)
            {
                items[i] = items[i + 1];
                length--;
            }
        }
        else
        {
            cout << "Index out of array Range \n";
        }
    }
};

int main()
{
    cout << "Hello, this is Array ADT demo\n";
    int arraySize;
    cout << "Enter the Array Size \n";
    cin >> arraySize;
    Array myArray(arraySize);
    myArray.Fill();
    cout << "Array size = " << myArray.getSize() << " while length = " << myArray.getLength() << "\n";
    myArray.Display();
    cout << "Enter the value to search for \n";
    int key;
    cin >> key;
    int index = myArray.Search(key);
    if (index == -1)
    {
        cout << "Item not found \n";
    }
    else
    {
        cout << "Item found at position " << index << endl;
    }

    int newItem;
    cout << "Enter new item to add to the array\n";
    cin >> newItem;
    myArray.Append(newItem);
    myArray.Display();

    cout << "Enter index and item\n";
    cin >> index;
    cin >> newItem;
    myArray.Insert(index, newItem);
    myArray.Display();
    cout << "Array size = " << myArray.getSize() << " while length = " << myArray.getLength() << "\n";

    cout << "Enter index delete its item\n";
    cin >> index;
    myArray.Delete(index);
    myArray.Display();
    cout << "Array size = " << myArray.getSize() << " while length = " << myArray.getLength() << "\n";




    return 0;
}
