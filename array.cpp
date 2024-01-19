#include <iostream>
using namespace std;

class Array{
private:
    int size;
    int length;
    int *items;
public:
    Array(int arraySize){
        size = arraySize;
        length = 0;
        items = new int[arraySize];
    }    

    void Fill(){
        int no_of_items;
        cout <<"How many items you want to fill ? \n";
        cin >> no_of_items;
        if (no_of_items > size){
            cout << "You cannot exceed the array size \n";
            return;
        }

        else {
            for (int i = 0; i < no_of_items; i++){
                cout <<"Enter item no "<<i<< endl;
                cin>>items[i];
                length++;
            }
            
        }
    }

    void Display (){
        cout<< "Display Array Content\n";
        for (int i = 0; i < length; i++){
            cout<<items[i]<<"\t";
        }
        cout<<endl;
    }

    int getSize(){
        return size;
    }
    int getLength(){
        return length;
    }

};

int main()
{
    cout << "Hello this is Array ADt demon\n";
    int arraySize;
    cout <<"Enter the Array Size \n";
    cin>>arraySize;
    Array myArray(arraySize);
    myArray.Fill();
    cout<< "Array size = "<<myArray.getSize()<<" while length = "<<myArray.getLength()<<"\n";
    myArray.Display();

    return 0;
}
