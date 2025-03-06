#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
int interpolation_search(const int& low, const int& high, const int& target, vector<T> arr){
  if(high < low || target < arr.at(low) || target > arr.at(high)) return -1;

  int pos = low + (target - arr.at(low)) * (high - low) / (arr.at(high) - arr.at(low));

  if(arr.at(pos) == target) return pos;
  else if(arr.at(pos) > target) return interpolation_search(low, pos - 1, target, arr);
  else return interpolation_search(pos + 1, high, target, arr);
}
int main(){

  ifstream fin("file.in");

  char target; fin >> target;

  vector<char> arr; char t;
  while(fin >> t) arr.push_back(t);

  int index = interpolation_search(0, arr.size() -1, target, arr);

  cout << index;
  fin.close();

  return 0;
}