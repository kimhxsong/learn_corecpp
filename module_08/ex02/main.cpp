
#include <iostream>
#include <list>
#include "MutantStack.h"
int main() {
  MutantStack<int> mstack;
  mstack.push(5); mstack.push(17);

  std::cout << mstack.top() << std::endl; mstack.pop();
  std::cout << mstack.size() << std::endl;

  mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;

  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  MutantStack<int> s(mstack);

  for (it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << std::endl;
  }
  return 0;
}
