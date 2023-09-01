#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;

    Node() :data(0), next(NULL) {}

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void DisplayLinkedList(Node* head)
{
    Node* temp = head;
    if (head == NULL)
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

bool hasCycle(Node* head)
{
    if (!head || !head->next)
    {
        // If the list is empty or has only one node, there can't be a loop.
        return false;
    }
    
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next)
    {
        if (slow == fast)
        {
            // The fast pointer caught up to the slow pointer, indicating a loop.
            return true;
        }
        slow = slow->next;         // Move slow pointer one step
        fast = fast->next->next;   // Move fast pointer two steps
    }   
    //  1   2   3   4   2
    //  s = 1 f = 2
    //  s = 2 f = 4
    //  s = 3 f = 3
    return false;
}

int main()
{
    //For checking loop
    Node* temphead = new Node(1);                       // 1 
    temphead->next = new Node(2);                       // 1 -> 2
    temphead->next->next = new Node(3);                 // 1 -> 2 -> 3
    temphead->next->next->next = new Node(4);           // 1 -> 2 -> 3 -> 4
    temphead->next->next->next->next = temphead->next;  // 1 -> 2 -> 3 -> 4 -
                                                        //      |             |
                                                        //       <------------
    if (hasCycle(temphead))
    {
        // DisplayLinkedList(temphead);
        cout << "The linked list has a loop." << endl;
    }
    else
    {
        cout << "The linked list does not have a loop." << endl;
    }
    
  /*Node* temp = temphead;
    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }*/
    return 0;
}
