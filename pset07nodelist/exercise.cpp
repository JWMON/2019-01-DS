#include <iostream>
#include <string>

using namespace std;


void recursiveFunction(int num);

int main(){

  recursiveFunction(0);
  return 0;

}
void	recursiveFunction(int num) {

  if (num < 10)
    recursiveFunction(num + 1);
  cout << num << endl;
}
