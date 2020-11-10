#ifndef __LIST_H
#define __LIST_H

#include <iostream>
#include <initializer_list>
#include <memory>


namespace details
{
    template<class T> 
    struct Node
    {
        T value;
        std::shared_ptr<Node> next;
    };
}


template<class T>
class ArbitraryList
{
    std::shared_ptr<details::Node<T>> root;

    public:
    /* Constructors */
    ArbitraryList() : root(nullptr)
    {} 

    ArbitraryList(std::initializer_list<T> l) : root(nullptr)
    {
        for (T f : l)
        {
            insert_front(f);
        }
    }

    /* Warum kopieren zulassen?
        Damit es möglich ist, Kopien von der Liste zu erstellen,
        die unabhängig von der originalen Liste verändert werden
        können, ohne das erstere selbst sowie alle ihrer Nodes verändert werden.
     */

    /* Copy constructor */
    ArbitraryList(const ArbitraryList &originList)
    {
        /* 
        Copy node by node from origin-list and
        add it directly to the new list 
        */
        root = nullptr;
        std::shared_ptr<details::Node<T>> nextNode = originList.root; 
        std::shared_ptr<details::Node<T>> tmpPtr = nullptr;            // neccessary to hold a pointer to the prior node

        while (nextNode != nullptr) {
            std::shared_ptr<details::Node<T>> newNode = std::make_shared<details::Node<T>>();    // create a new Node

            if (tmpPtr != nullptr) {                // This is not neccessary in the first run
                tmpPtr->next = newNode;  
            }
           
            newNode->value = nextNode->value;       // Copy value of node
            newNode->next = nullptr;                // Actually redundant, but helps with understanding

            nextNode = nextNode->next;              // Get pointer to next Node in origin-list
            tmpPtr = newNode;                       // Hold a pointer to the current Node for addressing it in the next node
                                
            if(root == nullptr)                     // This is only neccessary in the first run
                root = newNode;                     // (link root to first node of list)
        }
    }

    /* Copy operator */
    ArbitraryList &operator=(const ArbitraryList &originList)
    {
         /* 
        Copy node by node from origin-list and
        add it directly to the new list 
        */
        if (&originList != this) {
            root = nullptr;
            std::shared_ptr<details::Node<T>> nextNode = originList.root; 
            std::shared_ptr<details::Node<T>> tmpPtr = nullptr;            // neccessary to hold a pointer to the prior node

            while (nextNode != nullptr) {
                std::shared_ptr<details::Node<T>> newNode = std::make_shared<details::Node<T>>();    // create a new Node

                if (tmpPtr != nullptr) {                // This is not neccessary in the first run
                    tmpPtr->next = newNode;  
                }
           
                newNode->value = nextNode->value;       // Copy value of node
                newNode->next = nullptr;                // Actually redundant, but helps with understanding

                nextNode = nextNode->next;              // Get pointer to next Node in origin-list
                tmpPtr = newNode;                       // Hold a pointer to the current Node for addressing it in the next node
                                
                if(root == nullptr)                     // This is only neccessary in the first run
                    root = newNode;                     // (link root to first node of list)
            }
        }
        return *this;
    }

    /* Destructor */
    ~ArbitraryList()
    {
        while (root != nullptr)
        {
            std::shared_ptr<details::Node<T>> nextroot = root->next;
            root = nextroot;
        }
    }

    /* Insert a new node at front of the list */
    void insert_front(T x)
    {
        std::shared_ptr<details::Node<T>> newElement = std::make_shared<details::Node<T>>();
        newElement->value = x;
        newElement->next = root;
        root = newElement;
    }

    /* Print all nodes of the list */
    void print_all()
    {
        std::shared_ptr<details::Node<T>> p = root;
        while (p != nullptr)
        {
            std::cout << p->value << " ";
            p = p->next;
        }
        std::cout << "\n";
    }
};

#endif
