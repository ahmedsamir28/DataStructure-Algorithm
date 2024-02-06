#include <iostream>
using namespace std;

class Array
{
private:
    int size;   // Total size of the array
    int length; // Current number of elements in the array
    int *items; // Pointer to the array

public:
    // Constructor to initialize the array with a given size
    Array(int arraySize)
    {
        size = arraySize;
        length = 0;
        items = new int[arraySize]; // Dynamically allocate memory for the array
    }

    // Method to fill the array with user input
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

    // Method to display the contents of the array
    void Display()
    {
        cout << "Display Array Content\n";
        for (int i = 0; i < length; i++)
        {
            cout << items[i] << "\t";
        }
        cout << endl;
    }

    // Getter method to retrieve the size of the array
    int getSize()
    {
        return size;
    }

    // Getter method to retrieve the current number of elements in the array
    int getLength()
    {
        return length;
    }

    // Method to search for a key in the array
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

    // Method to append a new item to the array
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

    // Method to insert a new item at a specific index in the array
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
            cout << "Error - index out of range \n";
        }
    }

    // Method to delete an item at a specific index from the array
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

    // Method to enlarge the array to a new size
    void Enlarge(int newSize)
    {
        if (newSize <= size)
        {
            cout << "New size must be larger than the current size \n";
            return;
        }
        else
        {
            size = newSize;
            int *old = items;
            items = new int[newSize];
            for (int i = 0; i < length; i++)
            {
                items[i] = old[i];
            }
            delete[] old;
        }
    }

    // Method to merge the array with another array
    void Merge(Array other)
    {
        int newSize = size + other.getSize();
        size = newSize;
        int *old = items;
        items = new int[newSize];
        int i;
        for (int i = 0; i < length; i++) // This loop seems to be erroneous, as it's declared twice and doesn't perform any operations
        {
            items[i] = old[i];
        }
        delete[] old;
        int j = i;
        for (int i = 0; i < other.getLength(); i++)
        {
            items[j++] = other.items[i];
            length++;
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

    cout << "Enter index to delete its item\n";
    cin >> index;
    myArray.Delete(index);
    myArray.Display();
    cout << "Array size = " << myArray.getSize() << " while length = " << myArray.getLength() << "\n";

    int newSize;
    cout << "Enter New Size\n";
    cin >> newSize;
    myArray.Enlarge(newSize);
    cout << "Array size = " << myArray.getSize() << " while length = " << myArray.getLength() << "\n";
    myArray.Display();

    Array other(3);
    other.Fill();
    myArray.Merge(other);
    cout << "Array size = " << myArray.getSize() << " while length = " << myArray.getLength() << "\n";
    myArray.Display();

    return 0;
}
