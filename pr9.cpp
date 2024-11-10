#include <iostream>  
#include <string>  
#define MAX 10  
using namespace std;  
  
class Stack  
{  
private:  
 int top = -1;  
 string str = "rar rar";  
 char revStr[MAX] = " ";  
  
public:  
 void getData()  
 {  
  cout << "\nOriginal String : " << str << endl;  
  cout << "Reversed String : " << revStr << endl;  
 }  
  
 int isEmpty()  
 {  
  if (top == -1)  
   return 1;  
  else  
   return 0;  
 }  
  
 
 int isFull()  
 {  
  if (top == MAX - 1)  
   return 1;  
  else  
   return 0;  
 }  
  
 
 void push(char ch)  
 {  
  if (isFull())  
  
   cout << "Stack Overflow !!" << endl;  
  else  
  {  
   top++;  
   revStr[top] = ch;  
  }  
 }  
 
  
 void isPalindrome()  
 {  
  if (str == revStr)  
   cout << endl << "String is Palindrome" << endl;  
  else  
   cout << endl << "String is not palindrome" << endl;  
 }  
  
 void reverse()  
 {  
  for (int i = str.length() - 1; i >= 0; i--)  
  {  
   push(str[i]);  
  }  
 }  
};  
  
 
int main()  
{  
 Stack stk;  
  
 stk.getData();  
 stk.reverse();  
 stk.getData();  
 stk.isPalindrome();  
  
 return 0;  
} 
