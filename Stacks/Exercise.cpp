#include <iostream>
#include <stack>
#include <string.h>
class StringReverser{

  public:

  std::string reverse(std::string input){

    if(input == std::string("null"))
     throw std::invalid_argument("you give me a bad argument");
     std::stack<char> stack;

     for(char ch : input)
        stack.push(ch);
    
    
    std::string reversed = "";
     while(!stack.empty())
     {
       reversed += stack.top();
       stack.pop();
     }

     return reversed;
  }

};

class Expression{
  public:
   bool isBalanced(std::string input){
    std::stack<char> stack;

    for(char ch : input)
    {
      if(ch == '(' || ch == '[' || ch == '<' || ch == '{')
        stack.push(ch);
      
      if(ch == ')'  || ch == ']' || ch == '>' || ch =='}'){
        if (stack.empty()) return false;
        char top = stack.top();
        if(
          (ch == ')' && top != '(') ||
           (ch == '>' && top != '<') ||
           (ch == ']' && top != '[') ||
           (ch == '}' && top != '{')
        ) return false;
        stack.pop();
      }
    }
    return stack.empty();
   }
};
int main()
{
    std::string str = "abcd"; 
    StringReverser *reverser = new StringReverser();
    std::cout<<reverser->reverse(str);

    std::cout<<std::endl;
    Expression *exp = new Expression();
    std::string str2 = "(1+2)";
    std::cout<<exp->isBalanced(str2);
    return 0;
}