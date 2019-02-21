#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

struct  PERSON {
    char  Name[20];
    float Balance;
};

void Readfile(int r, PERSON array[]);


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
PERSON array[records];

return 0;
}

void Readfile(int r, PERSON array[]){

}
