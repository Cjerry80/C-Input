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
void Display(int r, PERSON array[]);

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
Readfile(records, array);
Display(records, array);

return 0;

}

void Readfile(int r, PERSON array[]){
ifstream infile;
string firstn;
string lastn;
float bal;
string temp;

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
void Display(int r, PERSON array[]){
cout << "Name" << "               " << "Balance" << endl;
cout << "----------------------------------" << endl;
for(int i = 0; i < r; i++){
cout << array[i].Name << "     " << array[i].Balance << endl;
}

}
