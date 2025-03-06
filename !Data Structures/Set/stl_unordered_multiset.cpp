#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
  // us.insert(value);    // Inserts 'value' into the unordered multiset O(1) average, O(n) worst-case
  // us.erase(value);     // Removes all occurrences of 'value' O(1) average, O(n) worst-case
  // us.erase(iter);      // Removes the element at the iterator's position O(1)
  // us.clear();          // Clears all elements from the unordered multiset O(n)
  // us.find(value);      // Returns an iterator to 'value' or us.end() if not found O(1) average, O(n) worst-case
  // us.count(value);     // Returns the number of occurrences of 'value' O(1) average, O(n) worst-case
  // us.contains(value);  // (C++20) Returns true if 'value' exists O(1) average, O(n) worst-case
  // us.begin();          // Returns an iterator to the first element O(1)
  // us.end();            // Returns an iterator to the past-the-last element O(1)
  // us.lower_bound(value); // Returns iterator to the first element >= value O(1) average, O(n) worst-case
  // us.upper_bound(value); // Returns iterator to the first element > value O(1) average, O(n) worst-case
  // us.equal_range(value); // Returns {lower_bound, upper_bound} O(1) average, O(n) worst-case
}
