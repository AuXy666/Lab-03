#include <iostream>
using namespace std;
class node
{
public:
    int priority;
    int data;
    node* next;
    node()
    {
        priority = 0;
        data = 0;
        next = NULL;
    }
};
class priorityQueue
{
public:
    node* front;
    priorityQueue()
    {
        front = NULL;
    }
    bool isEmpty()
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
    void enqueue(int key, int p)
    {
        node* temp;
        node* back;
        temp = new node;
        temp->data = key;
        temp->priority = p;
        if (front == NULL || p < front->priority)
        {
            temp->next = front;
            front = temp;
        }
        else {
            back = front;
            while (back->next != NULL && back->next->priority <= p)
                back = back->next;
            temp->next = back->next;
            back->next = temp;
        }
    }
    void dequeue()
    {
        if (isEmpty() == true)
            cout << "Queue is Empty" << endl;
        else {
            cout << "Following Item is being deleted" << endl;
            cout << front->data << endl;
            front = front->next;
        }
    }
    void display()
    {
        node* ptr;
        ptr = front;
        if (front == NULL)
            cout << "Queue is empty" << endl;
        else {
            cout << endl;
            while (ptr != NULL) {
                cout << "Priority = " << ptr->priority << endl;
                cout << "Value = " << " " << ptr->data << endl;
                ptr = ptr->next;
            }
        }
    }
};
int main() {
    int loopInput;
    priorityQueue p1;
    while (1)
    {
        cout << "Press 1 to Insert " << endl;
        cout << "Press 2 to Delete " << endl;
        cout << "Press 3 to check if empty " << endl;
        cout << "Press 4 to display " << endl;
        cout << "Press 5 to end " << endl;
        cin >> loopInput;
        if (loopInput == 1)
        {
            int input, pt;
            cout << "Enter the value = ";
            cin >> input;
            cout << "Enter its Priority =";
            cin >> pt;
            p1.enqueue(input, pt);
        }
        else if (loopInput == 2)
        {
            p1.dequeue();
        }
        else if (loopInput == 3)
        {
            if (p1.isEmpty() == true)
            {
                cout << endl;
                cout << "Queue is Empty" << endl;
                cout << endl;
            }
            else
            {
                cout << endl;
                cout << "Queue is not Empty" << endl;
                cout << endl;
            }
        }
        else if (loopInput == 4)
        {
            p1.display();
        }
        else if (loopInput == 5)
        {
            break;
        }
        system("pause");
        system("cls");
    }
}
