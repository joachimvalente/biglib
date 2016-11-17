#include <iostream>

#include "data_structures/vector.h"

using namespace std;

int main(int argc, char** argv) {
  big::vector<int> v(5);

  cout << v.size() << endl;
  cout << v.capacity() << endl;
  cout << v.empty() << endl;

  v.push_back(6);

  cout << v[3] << endl;
  cout << v[5] << endl;

  v.clear();

  cout << v.size() << endl;
  cout << v.capacity() << endl;
  cout << v.empty() << endl;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  cout << v[0] << v[1] << v[2] << v[3] << endl;

  v.pop_back();
  v.pop_back();

  cout << v[0] << v[1] << endl;

  v.clear();

  v.insert(0, 666);

  cout << v[0] << endl;

  v.insert(1, 777);

  cout << v[0] << v[1] << endl;

  v.resize(70, 3);

  cout << v[66] << endl;

  return 0;
}
