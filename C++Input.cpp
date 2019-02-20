#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main(){
string line;
int records;
fstream file ("data.txt");
if (file.is_open()){
  while (getline(file, line))
  {
  ++records;
  }
  cout << "The number of records is: " << records << endl;
  file.close();
}
return 0;
}

struct  PERSON {
    char  Name[20];
    float Balance;
  };
