#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node()
    {
        data = 0;
        next = NULL;
    }
};
class queue
{
public:
    node* front;
    node* rear;
    int counter;
    queue()
    {
        front = NULL;
        rear = NULL;
        counter = 0;
    }
    bool isfull()
    {
        if (counter >100)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isempty()
    {
        if ((front == NULL) && (rear == NULL))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Enqueue(int key)
    {
        node* temp = new node;
        temp = front;
        if (rear == NULL)
        {
            rear = new node;
            rear->next = NULL;
            rear->data = key;
            front = rear;
        }
        else
        {
            temp = new node;
            rear->next = temp;
            temp->data = key;
            rear = temp;
        }
        counter++;
    }
    void Dequeue()
    {
        node* temp = new node;
        temp = front;
        if (isempty()==true)
        {
            cout << endl;
            cout << "Queue is Empty" << endl;
            cout << endl;
            return;
        }
        else
            if (temp->next != NULL) {
                temp = temp->next;
                cout << "Following Element is Deleted  " << endl;
                cout<< front->data << endl;
                delete front;
                front = temp;
            }
            else {
                cout << "Following Element is Deleted " << endl;
                cout << front->data << endl;
                delete front;
                front = NULL;
                rear = NULL;
            }
    }
    void Output()
    {
        node* temp = new node;
        temp = front;
        if (isempty() == true)
        {
            cout << endl;
            cout << "Queue is Empty" << endl;
            cout << endl;
            return;
        }
        cout << endl;
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                cout << temp->data;
                temp = temp->next;
                continue;
            }
            cout << temp->data << ",";
            temp = temp->next;
        }
        cout << endl;
    }


};


int main() {
    int input;
    queue q1;
    while (1)
    {
        cout << "Press 1 to Enqueue" << endl;
        cout << "Press 2 to Dequeue" << endl;
        cout << "Press 3 to check if the Queue is Full" << endl;
        cout << "Press 4 to check if the Queue is Empty" << endl;
        cout << "Press 5 to display queue" << endl;
        cout << "Press 6 to end" << endl;
        cin >> input;
        if (input == 1)
        {
            int key;
            cout << "Enter element to Enqueue = ";
            cin >> key;
            q1.Enqueue(key);
        }
        else if (input == 2)
        {
            q1.Dequeue();
        }
        else if (input == 3)
        {
            if (q1.isfull() == true)
            {
                cout << endl;
                cout << "Queue is Full" << endl;
                cout << endl;
            }
            else
            {
                cout << endl;
                cout << "Queue is not full" << endl;
                cout << endl;
            }
        }
        else if (input == 4)
        {
            if (q1.isempty() == true)
            {
                cout << endl;
                cout << "Queue is Empty" << endl;
                cout << endl;
            }
            else
            {
                cout << endl;
                cout << "Queue is Not Empty" << endl;
                cout << endl;
            }
        }
        else if (input == 5)
        {
            q1.Output();
        }
        else if (input == 6)
        {
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

