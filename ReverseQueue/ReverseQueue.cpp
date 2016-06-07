// ReverseQueue.cpp : Defines the entry point for the console application.
//

#include <cstdlib>
#include <iostream>
#include <string>


template <class T>
struct Node
{
   // Data structure that will be used for Queue and Stack
   Node(T dat) :data(dat), pNext(NULL) {}
   Node<T>* pNext;
   T data;
};



template <class T>
class Stack
{
   // A FILO structure, like a stack of papers
private:
   // Top of the stack
   Node<T>* top;
public:
   Stack() :top(NULL) {}
   ~Stack() {}
   void push(T data);
   T pop();
   void printStack();
   bool isEmpty();
};

template <class T>
void Stack<T>::push(T data)
{
   // Create a new node, assigning the new top
   Node<T>* temp = top;
   top = new Node<T>(data);
   top->pNext = temp;
   std::cout << "Stack Push: " << data << std::endl;
}

template <class T>
T Stack<T>::pop()
{
   // Check for an empty stack
   if (top != NULL)
   {
      // Store the top Node, delete top, and return value
      Node<T>* temp = top;
      top = top->pNext;
      T retVal = temp->data;
      delete temp;
      std::cout << "Stack Pop: " << retVal << std::endl;
      return retVal;
   }
   std::cout << "Stack Empty" << std::endl;
   return NULL;
}

template <class T>
void Stack<T>::printStack()
{
   Node<T> *temp = top;
   std::cout << "Stack: ";
   while (temp != NULL)
   {
      std::cout << temp->data << " ";
      temp = temp->pNext;
   }
   std::cout << std::endl;
}

template <class T>
bool Stack<T>::isEmpty()
{
   return (top == NULL);
}



template <class T>
class Queue
{
   // FIFO structure, like a line of people
private:
   // Head and tail of the queue
   Node<T> *head;
   Node<T> *tail;
public:
   Queue():head(NULL),tail(NULL) {}
   ~Queue() {}
   void enqueue(T data);
   T dequeue();
   void printQueue();
   void reverseQueue();
};

template <class T>
void Queue<T>::enqueue(T data)
{
   if (head == NULL)
   {
      // Create the first node with head and tail the same
      head = new Node<T>(data);
      tail = head;
   }
   else
   {
      // Add a new node at the tail and fix next link
      Node<T>* temp = tail;
      tail = new Node<T>(data);
      temp->pNext = tail;
   }
   std::cout << "Queue Push: " << data << std::endl;
}

template <class T>
T Queue<T>::dequeue()
{
   // Check for an empty queue
   if (head != NULL)
   {
      // Move the head to the next node and return data
      Node<T>* temp = head;
      head = head->pNext;
      T retVal = temp->data;
      delete temp;
      std::cout << "Queue Pop: " << retVal << std::endl;
      return retVal;
   }
   std::cout << "Queue Empty" << std::endl;
   return NULL;
}

template <class T>
void Queue<T>::printQueue()
{
   Node<T>* temp = head;
   std::cout << "Queue: ";
   while (temp != NULL)
   {
      std::cout << temp->data << " ";
      temp = temp->pNext;
   }
   std::cout << std::endl;
}

template <class T>
void Queue<T>::reverseQueue()
{
   // Create a stack for performing the reverse
   Stack<T> tempStack;
   // Loop through the Queue and pop everything to the Stack
   while (head != NULL)
   {
      tempStack.push(dequeue());
   }
   // Loop through the Stack and pop everything to the Queue
   while (!tempStack.isEmpty())
   {
      enqueue(tempStack.pop());
   }
   std::cout << "Queue Reversed!" << std::endl;
}



int main()
{
   Stack<int> s;
   int retVal = 0;
   s.printStack();
   retVal = s.pop();
   s.push(7);
   s.push(3);
   s.push(1);
   s.printStack();
   retVal = s.pop();
   s.printStack();
   retVal = s.pop();
   s.printStack();

   Queue<float> q;
   float retFloat = 0.0f;
   q.printQueue();
   retFloat = q.dequeue();
   q.enqueue(7.0f);
   q.enqueue(3.0f);
   q.enqueue(1.0f);
   q.printQueue();
   retFloat = q.dequeue();
   q.printQueue();
   retFloat = q.dequeue();
   q.printQueue();

   q.enqueue(3.0f);
   q.enqueue(7.0f);
   q.printQueue();
   q.reverseQueue();
   q.printQueue();

   system("PAUSE");
   return 0;
}