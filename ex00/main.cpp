# include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
  typename T::iterator f = std::find(container.begin(), container.end(), value);
  if (f != container.end())
    return f;
  else
    throw std::runtime_error("Value not found");
}
int main( void )
{
  std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(8);

    std::list<int> li;
    li.push_back(1);
    li.push_back(2);
    li.push_back(3);
    li.push_back(4);
    li.push_back(5);
    li.push_back(1);
    li.push_back(8);

    std::set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(10);
    s.insert(5);

    // std::set<int>::iterator it = s.begin();
    // std::set<int>::iterator end = s.end();

    // for (; it != end; ++it)
    //   std::cout << *it << " ";

  // std::vector<int>::iterator it = vec.begin();
  // std::vector<int>::iterator end = vec.end();

  // std::cout << "Start of this vec <it> == <" << *it << ">" << std::endl;
  // std::cout << "end of this vec <end> == <" << *(end - 1) << ">" << std::endl;

  // for (; it != end; ++it)
  //   std::cout << *it << " ";

  try {
    // vector
    std::vector<int>::iterator f = easyfind(vec, 5);
    std::cout << "Value found: " << *f << std::endl;

    // list
    std::list<int>::iterator l = easyfind(li, 10);
    std::cout << "Value found: " << *l << std::endl;

    // set
    std::set<int>::iterator d = easyfind(s, 10);
    std::cout << "Value found: " << *d << std::endl;

  }
  catch(const std::runtime_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }
}
