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
ifstream infile;
string firstn;
string lastn;
float bal;

infile.open("data.txt");
for (int i = 0; i < r; i++){
infile >> firstn;
infile >> lastn;
infile >> bal;
string name = firstn + " " + lastn;
strcpy (array[i].Name, name.c_str());
array[i].Balance = bal;
}
infile.close();

}
