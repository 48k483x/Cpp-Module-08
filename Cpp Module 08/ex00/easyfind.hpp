#pragma once

# include <iostream>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <list>
# include <set>

/*****************************************************************************
 * C++ CONTAINERS & ITERATORS GUIDE
 *
 * CONTAINERS: Template classes that store & manage collections of objects
 *  - Automatic memory management
 *  - Type-safe element access
 *  - Standardized interface across different types
 *
 * TYPES & USAGE:
 *  Sequence    -> vector[]/deque<>/list{} : Direct element access
 *  Associative -> map{k:v}/set{x}        : Ordered key-based access
 *  Adapters    -> stack[]/queue->        : Restricted access patterns
 *  Unordered   -> unordered_map/set      : Hash-based access (O(1))
 *
 * ITERATORS: Objects that navigate container elements
 *  begin() → → → → → → → → → end()
 *  |First valid|         |Past last|
 *
 * ITERATOR TYPES:
 *  Input    →  Read only, forward
 *  Output   →  Write only, forward
 *  Forward  →  Read/Write, forward
 *  Bidir    ←  Read/Write, both ways  →
 *  Random   ↔  Read/Write, jump anywhere
 *
 * Each container provides appropriate iterator types for its data structure
 *****************************************************************************/

template <typename T>
typename T::iterator easyfind(T& container, int value);