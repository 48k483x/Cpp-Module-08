# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other): std::stack<T>(other) {};

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
  if (this != &other)
    std::stack<T>::operator=(other);
  return *this;
};

template <typename T>
MutantStack<T>::~MutantStack() {};

template <typename T>
typename MutantStack<T>::container_type::iterator begin() {
  return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::container_type::iterator end() {
  return std::stack<T>::c.end();
}



#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>
#include <iomanip>

// Utility function to print headers for test sections
void printTestHeader(const std::string& title) {
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << std::setw(25 + title.length()/2) << title << "\n";
    std::cout << std::string(50, '=') << "\n";
}

int main()
{
    // Test 1: Basic Stack Operations
    printTestHeader("Basic Stack Operations");
    {
        MutantStack<int> mstack;
        std::list<int> lst;    // For comparison

        // Push some values
        std::cout << "Pushing values: 5, 17, 3, 5, 737, 0\n";
        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        lst.push_back(5);
        lst.push_back(17);
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);

        std::cout << "Stack size: " << mstack.size() << std::endl;
        std::cout << "Top element: " << mstack.top() << std::endl;

        // Test iterator functionality
        std::cout << "\nMutantStack contents using iterator: ";
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        while (it != ite) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

        // Compare with list
        std::cout << "List contents for comparison: ";
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    // Test 2: Copy Constructor and Assignment
    printTestHeader("Copy Operations");
    {
        MutantStack<int> mstack1;
        mstack1.push(42);
        mstack1.push(21);
        mstack1.push(84);

        // Test copy constructor
        MutantStack<int> mstack2(mstack1);
        std::cout << "Original stack contents: ";
        for (MutantStack<int>::iterator it = mstack1.begin(); it != mstack1.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\nCopied stack contents: ";
        for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        // Test assignment operator
        MutantStack<int> mstack3;
        mstack3 = mstack1;
        std::cout << "Assigned stack contents: ";
        for (MutantStack<int>::iterator it = mstack3.begin(); it != mstack3.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    // Test 3: Different Data Type (strings)
    printTestHeader("String Stack Test");
    {
        MutantStack<std::string> strStack;
        strStack.push("Hello");
        strStack.push("42");
        strStack.push("World");

        std::cout << "String stack contents: ";
        for (MutantStack<std::string>::iterator it = strStack.begin();
             it != strStack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}