# pragma once

# include <stack>
# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <deque>
# include <set>

template <typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
  public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    typedef typename Container::iterator iterator;
//     │             │          │        └─ New type we're defining
//     │             │          └─ Iterator type from container
//     │             └─ Type of container inside stack
//     └─ Tells compiler this is a type

    // -> inside the class, we can access 'c' using this->c
    // --> this->c.begin() is equivalent to std::stack<T>::c.begin()
    // ----> c is a protected member of std::stack
    iterator begin() {
      return this->c.begin(); //
    };
    iterator end() {
      return this->c.end(); //
    };
};

template <typename T, class Container>
MutantStack<T, Container>::MutantStack() {
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other): std::stack<T, Container>(other) {
}

template <typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other) {
  if (this != &other)
    std::stack<T, Container>::operator=(other);
  return *this;
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack() {
}