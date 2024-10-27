#include "Span.hpp"

int main( void ) {
  Span Manza(5);

  Manza.addNumber(1);
  Manza.addNumber(2);
  Manza.addNumber(3);
  Manza.addNumber(4);
  Manza.addNumber(5);

  Span Manza2(10000);
  std::vector<int> vec;
  for (int i = 0; i < 10000; i++)
    vec.push_back(i);
  Manza2.addNumbers(vec.begin(), vec.end());

  std::cout << "Manza: " << std::endl;
  std::cout << "Shortest span: " << Manza.shortestSpan() << std::endl;
  std::cout << "Longest span: " << Manza.longestSpan() << std::endl;
  std::cout << "Manza2: " << std::endl;
  std::cout << "Shortest span: " << Manza2.shortestSpan() << std::endl;
  std::cout << "Longest span: " << Manza2.longestSpan() << std::endl;
}