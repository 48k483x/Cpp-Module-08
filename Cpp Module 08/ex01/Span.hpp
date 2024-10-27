# pragma once

# include <cstddef>
# include <vector>
# include <algorithm>
# include <iostream>
# include <stdexcept>
# include <climits>
# include <cstdlib>
# include <ctime>
# include <set>

class Span {
  private:
    unsigned int N;  // This is the MAXIMUM size allowed
    std::vector<int> vec;   // This vector will store our numbers

  public:
    // Constructors
    Span();  // Default
    Span(unsigned int N);  // Parametric
    Span(const Span &src);  // Copy
    ~Span();  // Destructor

    // operator
    Span &operator=(const Span &src);  // Assignation

    // Member functions
    void addNumber(int n);  // Add a number to the vector
    int shortestSpan(); // Return the shortest span
    int longestSpan();  // Return the longest span

    // Mystery function
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
      // First check: Do we have enough space?
      unsigned int n = std::distance(begin, end);

      if (vec.size() + n > N)
        throw std::overflow_error("Not enough space to add n numbers");

      // Add the numbers to the vector
      vec.insert(vec.end(), begin, end);
    }

};