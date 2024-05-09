//Задача на использование адаптеров.На вход подаётся скобочная последовательность — строка, которая состоит из скобок()[] {}.
//Вам нужно определить, является ли она правильной.В правильной скобочной последовательности каждой открывающей скобке соответствует закрывающая
//и пары скобок корректно вложены друг в друга.

#include <iostream>
#include <stack>
#include <string>

bool valid_brackets(const std::string& sequence) {

    std::stack<char> st;

    for (char bracket : sequence) {

        if (bracket == '(' or bracket == '[' or bracket == '{')
            st.push(bracket);
        else if (bracket == ')' and !st.empty() and st.top() == '(')
            st.pop();
        else if (bracket == ']' and !st.empty() and st.top() == '[')
            st.pop();
        else if (bracket == '}' and !st.empty() and st.top() == '{')
            st.pop();
        else
            return false;

    }
    return st.empty();

}

int main() {

    std::string skobochki;
    std::cout << "Enter a bracket sequence: ";
    std::cin >> skobochki;

    if (valid_brackets(skobochki))
        std::cout << "Aga" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;

}