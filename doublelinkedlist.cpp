#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }
    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // Step 1 : Allocate memory for new node
        Node *newNode = new Node();

        // Step 2 : Assign value to the data field
        newNode->noMhs = nim;

        // Step 3 : Insert at beginning if list is empty or nim is
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            // Step 4 : newNode.next = START;
            newNode->next = START;

            // Step 5 : START.prev = newNode (if START exicts)
            if (START != NULL)
                START->prev = newNode;
            // Step 6 : newNode.prev = NULL
            newNode->prev = NULL; // Step 7: START = newNode
            START = newNode;
            return;
        }

        //   insert in between node
        // Step 8: Locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        // Step 9: Insert between current and current->next
        newNode->next = current->next; // Step 9a
        newNode->prev = current;       // Step 9b

        //  insert last node
        if (current->next != NULL)
            current->next->prev = newNode;  //  Step 9c

        current->next = newNode;            //  Step 9d
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        cout << "\nEnter the roll Number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        //  Step 1: Traverse the list to find th enode
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;
        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        // Step 2: If node is at the beginning
        if (current == START)
        {
            START = current->next;     //   Step 2a
            if (START != NULL)
            {
                START->prev = NULL;     //  Step 2b
            }
            
        }
        else
        {
            // Step 3: link previous node to next of current
            current->prev->next = current->next;

            // Step 4: if current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // Step 5
        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Mark first node as currentNode
        Node *currentNode = START;

        // Step 2: Repeat until currentNode == NULL
        cout << "\nRecords in ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;
            
            // Step 3: Move to next node
            currentNode = currentNode->next;
            i++;
        } 
    }
};