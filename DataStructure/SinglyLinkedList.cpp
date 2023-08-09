// DataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
     
    Node():data(0),next(NULL) {}

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* createNode()
{
    int data;
    cout << "Enter data to store : ";
    cin >> data;

    Node* node = new Node(data);

    return node;
}


Node* AddNodeAtStart(Node* head)
{
    Node* node = createNode();

    if (head == NULL)
    {
        head = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
    return head;
}

Node* AddNodeAtEnd(Node* head)
{
    Node* node = createNode();
    Node* temp = head;

    if (head == NULL)
        head = node;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = node;
    }

    return head;
}

Node* AddNodeAtMiddle(Node* head)
{
    Node* temp = head;
    if (head == NULL)
    {
        cout << "Linked List is Empty.\nAdd First Node...!"<<endl;
        head= createNode();
    }
    else
    {
        int key;
        cout << "\n Enter element after which you want to add data :"<<endl;
        cin >> key;

        Node* newnode = createNode();
        if (head->next == NULL)
        {
            if (head->data == key)
            {
                head->next = newnode;
            }
            else
            {
                cout << "Node with " << key << " data not found." << endl;
            }
        }
        else
        {
            while (temp!=NULL)
            {
                if (temp->data == key)
                {
                    newnode->next = temp->next;
                    temp->next = newnode;
                    break;
                }
                else
                    temp = temp->next;
            }
            if(temp==NULL)
                cout << "Node with " << key << " data not found." << endl;
        }
    }
    return head;
}
                                    
Node* DeleteFromStart(Node *head)
{
    Node* temp = head;
    if (head == NULL)
        cout << "LinkedList is empty";
    else
    {
        head = head->next;
        delete(temp);
    }
    return head;
}
                                    
Node* DeleteFromEnd(Node *head)
{
    Node* temp = head;
    if (head == NULL)
        cout << "LinkedList is empty";
    else if (head->next == NULL)
    {
        delete(temp);
        temp = NULL;
        head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
            temp = temp->next;

        delete(temp->next);
        temp->next = NULL;
    }
    return head;
}

Node* DeleteFromMiddle(Node* head)
{
    Node* temp = head;
    if (head == NULL)
    {
        cout << "Linked List is Empty." << endl;
    }
    else
    {
        int key;
        cout << "\n Enter data which you want to delete :" << endl;
        cin >> key;
        if (head->next == NULL)
        {
            if (head->data == key)
            {
                delete(temp);
                temp = NULL;
                head = NULL;
            }
            else
            {
                cout << "Node with " << key << " data not found." << endl;
            }
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->next->data == key)
                {
                    Node *a = temp->next;
                    temp->next = temp->next->next;
                    delete(a);
                    break;
                }
                else
                    temp = temp->next;
            }
            if (temp == NULL)
                cout << "Node with " << key << " data not found." << endl;
        }
    }
    return head;
}

void DisplayLinkedList(Node *head)
{
    Node* temp =  head;
    if(head == NULL)
    {
        cout << "Linked List Is Empty.!" << endl;
    }
    else
    {
        cout << "--------------------------------------------" << endl;
        while (temp != NULL)
        {
            cout << " " << temp->data << " ->";
            temp = temp->next;
        }
        cout << "\n--------------------------------------------" << endl;
    }
}

int main()
{
    Node *head=NULL;
    while(1)
    {
        cout << "\n----------- Singly Linked List -----------" << endl;
        cout << "   1. Create First Node" << endl;
        cout << "   2. Add Node At The Start" << endl;
        cout << "   3. Add Node At The Middle" << endl;
        cout << "   4. Add Node At The End"<<endl;
        cout << "   5. Display List" << endl;
        cout << "   6. Delete From Start" << endl;
        cout << "   7. Delete From End" << endl;
        cout << "   8. Delete From Middle" << endl;
        cout << "-----------------------------------------" << endl;

        int choice;
        cout << "Enter Your Choice :- " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            head = createNode();
            break;
        case 2:
            head = AddNodeAtStart(head);
            break;
        case 3:
            head = AddNodeAtMiddle(head);
                break;
        case 4:
            head = AddNodeAtEnd(head);
            break;
        case 5:
                   DisplayLinkedList(head);
            break;
        case 6:
            head = DeleteFromStart(head);
            break;
        case 7:
            head = DeleteFromEnd(head);
            break;
        case 8:
            head = DeleteFromMiddle(head);
            break;
        default:
            break;
        }
    }

    Node* temp = head;
    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    return 0;
}
