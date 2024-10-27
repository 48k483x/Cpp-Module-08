# pragma once

# include <stack>
# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <deque>
# include <set>

template <typename T>
class MutantStack: public std::stack<T> {
  public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
//     │             │               │              │        └─ New name
//     │             │               │              └─ Iterator type from container
//     │             │               └─ Type of container inside stack
//     │             └─ Our template parameter
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