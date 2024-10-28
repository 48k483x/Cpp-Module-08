#pragma once

# include <iostream>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <list>
# include <set>

/*
 * Abstraction:
 * Iterators abstract the concept of a pointer. They provide a way to 
 * traverse elements in a container without exposing the underlying 
 * representation of the container.
 *
 * Types of Iterators:
 * - Input Iterators: Read from a sequence.
 * - Output Iterators: Write to a sequence.
 * - Forward Iterators: Read and write, can move forward.
 * - Bidirectional Iterators: Forward iterators that can also move backward.
 * - Random Access Iterators: Bidirectional iterators that can jump to 
 *   any element in constant time.
 *
 * Operations:
 * - Dereferencing: Access the value pointed to by the iterator.
 * - Increment/Decrement: Move the iterator to the next/previous element.
 * - Comparison: Check if two iterators are equal or not.
 */



template <typename T>
typename T::iterator easyfind(T& container, int value);