#include <iostream>
using namespace std;

const int SIZE = 100;
class queue
{
public:
    int array[SIZE];
    int front;
    int rear;
    queue()
    {
        array[SIZE] = { 0 };
        front = -1;
        rear = -1;
    }
    bool isfull()
    {
        if (rear == SIZE - 1)
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
        if (front == -1 || front > rear)
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
        if (isfull() == false)
        {
            if (front == -1)
                front = 0;
            rear++;
            array[rear] = key;
        }
        else
        {
            cout << "Queue is full" << endl;
            cout << endl;
        }
    }
    void Dequeue() {
        if (isempty() == false)
        {
            cout << "Following Element is Deleted " << endl;
            cout << array[front] << endl;
            front++;;
        }
        else
        {
            cout << "Queue is Empty" << endl;
            cout << endl;
        }
    }
    void Output()
    {
        if (isempty() == true)
        {
            cout << "Queue is Empty" << endl;
            cout << endl;
        }
        else {
            cout << endl;
            for (int i = front; i <= rear; i++)
            {
                if (i == rear)
                {
                    cout << array[i];
                }
                else {
                    cout << array[i] << ",";
                }
            }
            cout << endl;
        }
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

