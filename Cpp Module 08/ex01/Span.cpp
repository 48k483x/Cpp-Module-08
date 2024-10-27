# include "Span.hpp"

// Constructors
Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &src) : N(src.N), vec(src.vec) {}

Span::~Span() {}

// operator
Span &Span::operator=(const Span &src) {
  if (this == &src)
    return *this;
  N = src.N;
  vec = src.vec;
  return *this;
}

// Member functions
void Span::addNumber(int n) {
  // First check: Is there space left?
  if (N <= vec.size()) // If current size equals or exceeds N
    throw std::out_of_range("Span is full");

  // If we get here, there is space, so add the number
  vec.push_back(n);
}


// Current implementation issue:
// ┌───────────────────────────────────────────────────────────────┐
// │ Sorted array: [2, 10, 11, 25]                                 │
// │ Only checks: 10 - 2 = 8 ❌ Wrong result!                      │
// └───────────────────────────────────────────────────────────────┘
//
// Correct approach:
// ┌───────────────────────────────────────────────────────────────┐
// │ Should check all adjacent pairs:                              │
// │                                                               │
// │ 10 - 2  = 8                                                   │
// │ 11 - 10 = 1  <- This is actually the shortest!                │
// │ 25 - 11 = 14                                                  │
// └───────────────────────────────────────────────────────────────┘

int Span::shortestSpan() {
  // No span if fewer than 2 elements
if (vec.size() <= 1)
    throw std::runtime_error("Error: Need at least 2 numbers to find a span.");
  // Sort the vector
  std::vector<int> sortedVec = vec;
  std::sort(sortedVec.begin(), sortedVec.end());

  int minSpan = INT_MAX; // Start with maximum possible value

  for (size_t i = 1; i < sortedVec.size(); i++) {
    int currentSpan = sortedVec[i] - sortedVec[i - 1];
    if (currentSpan < minSpan)
      minSpan = currentSpan;
  }
  // Return the smallest span
  return minSpan;
}

int Span::longestSpan() {
  // No span if fewer than 2 elements
if (vec.size() <= 1)
    throw std::runtime_error("Error: Need at least 2 numbers to find a span.");
  // Sort the vector
  std::vector<int> sortedVec = vec;
  std::sort(sortedVec.begin(), sortedVec.end());

  // The largest span is the difference between the last and first elements
  int maxSpan = sortedVec[sortedVec.size() - 1] - sortedVec[0];
  // Return the largest span
  return maxSpan;
}










// void Span::addNumbers(unsigned int n) {
//   // Let's say:
//   // N = 10 (max capacity of Span)
//   // vec.size() = 3 (current numbers in Span)
//   // count = 5 (we want to add 5 new random numbers)

//   // First check: Do we have enough space?
//   if (vec.size() + n > N) // If current size plus n exceeds N
//     throw std::out_of_range("Not enough space to add n numbers");

//   // seed the random number generator
//   srand(time(0));

//   // init a set to store the random numbers
//   std::set<int> randomNumbers;

//   // generate n random numbers
//   while (randomNumbers.size() < n) {
//     // Generate a random number between 0 and INT_MAX
//     int random = rand();
//     // Add the random number to the set
//     randomNumbers.insert(random);
//   }

//   // Add the random numbers to the vector
//   for (std::set<int>::iterator it = randomNumbers.begin(); it != randomNumbers.end(); it++) {
//     vec.push_back(*it);
//   }
// }