//
//  HW2.cpp
//  ECE309
//
//  Created by Christian Burke on 9/5/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include <stdio.h>


class Node
{
public:
    const char* name;
    Node* nextNode;
    
    Node(const char* nameStr = nullptr)
    {
        name = nameStr;
        nextNode = nullptr;

        if(nameStr != nullptr)
        {
            //printf("Created Node: %s\n", nameStr);
        }
    }
};

class List
{
public:
    Node* Head;
    Node* Tail;
    
    List()
    {
        Head = new Node();
        Tail = new Node();
    }

    ~List()
    {
        Node* currentNode = Head;
        Node* nextNode = Head;
        while (nextNode != nullptr)
        {
            nextNode = currentNode->nextNode;
            delete currentNode;
            currentNode = nextNode;
        }
        Head = new Node();
        Tail = new Node();
        printf("Cleared List\n\n");
    }
    
    void push_back(const char* string)
    {
        if(Head->name == nullptr)    //List is totally Empty
        {
            Head->name = string;
            printf("Pushed Back: %s\n",string);
            return;
        }
        
        if(Tail->name == nullptr)    //Tail is null
        {
            Tail->name = string;
            Head->nextNode = Tail;
            printf("Pushed Back: %s\n", string);
            return;
        }
        
        Node* newTail = new Node(string);
        Tail->nextNode = newTail;
        Tail = newTail;
        
        
        printf("Pushed Back: %s\n", string);
    }
    
    Node get(int n)
    {
        Node* currentNode = Head;
        int nodeCounter = 1;
        while ((currentNode->nextNode != nullptr) && nodeCounter != n)
        {
            currentNode = currentNode->nextNode;
            nodeCounter++;
        }
        if(nodeCounter < n)
        {
            printf("ERROR: Node Doesn't Exist\n");
            return *Head;
        }
        printf("Node: %d = %s\n", n, currentNode->name);
        return *currentNode;
    }

    int length()
    {
        Node* currentNode = Head;
        int nodeCounter = 1;
        while (currentNode->nextNode != nullptr)
        {
            currentNode = currentNode->nextNode;
            nodeCounter++;
        }
        printf("List length = %d\n", nodeCounter);
        return nodeCounter;
    }

    Node remove_front()
    {
        Node oldHeadNode = *Head;
        Node* oldHead = Head;
        Head = Head->nextNode;
        delete oldHead;
        printf("Deleted Head: %s\n", oldHeadNode.name);
        return oldHeadNode;
    }
};

/*
List mainList = List();

int main()
{
    mainList.push_back("Pizza");
    mainList.push_back("shoes");
    mainList.push_back("Pants");
    mainList.push_back("Spices");
    mainList.get(3);
    mainList.length();
    mainList.remove_front();
    return 0;
}
*/

