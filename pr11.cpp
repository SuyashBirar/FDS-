#include <iostream>  
using namespace std;  
const int MAX_SIZE = 5;  
  
class Queue  
{  
private:  
 int arr[MAX_SIZE];  
 int front, rear;  
  
public:  
 Queue() : front(-1), rear(-1) {}  
  
 void enqueue(int value)  
 {  
  if (rear == MAX_SIZE - 1)  
  {  
   std::cout << "Queue is full. Cannot enqueue." << std::endl;  
   return;  
  }  
  
  if (front == -1)  
   front = 0;  
  
  arr[++rear] = value;  
  cout << "Enqueued Job : " << value << std::endl;  
 }  
  
 void dequeue()  
 {  
  if (front == -1)  
  {  
   std::cout << "Queue is empty. Cannot dequeue." << std::endl;  
   return;  
  }  
  
  int frontValue = arr[front];  
  if (front == rear)  
  {  
  
   front = rear = -1;  
  }  
  else  
  {  
   front++;  
  }  
  std::cout << "Dequeued Job : " << frontValue << std::endl;  
 }   

 void display()  
 {  
  if (front == -1)  
  {  
   std::cout << "Queue is empty." << std::endl;  
   return;  
  }  
  
  std::cout << "Jobs in Queue : ";  
  for (int i = front; i <= rear; ++i)  
  {  
   std::cout << arr[i] << " ";  
  }  
  std::cout << std::endl;  
 }  
};  
  
int main()  
{  
 Queue queue;  
  
 int data;  
 int choice;  
  
 cout << "MENU\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit";  
  
 while (true)  
 {  
  cout << "\n\nEnter Your Input Here -->";  
  cin >> choice;  
  switch (choice)  
  {  
  case 0:  
   cout << "Exit !" << endl;  
   return 0;  
  case 1:  
   cout << "Enter the data to be inserted : ";  
   cin >> data;  
   queue.enqueue(data);  
   break;  
  case 2:  
   queue.dequeue();  
   break;  
  case 3:  
   queue.display();  
   break;  
  default:  
   cout << "Invalid Case";  
   break;  
  }  }  
 return 0;  
}