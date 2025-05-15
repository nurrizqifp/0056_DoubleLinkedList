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
    }
};