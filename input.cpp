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
void findRichest(int r, PERSON array[]);
void Deposit(string custname, int r, PERSON array[]);
void Newcopy(string file, int r, PERSON array[]);
int main(){

string line;
int records;
string custname;

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
findRichest(records, array);

cout << "Enter your full name: ";
getline(cin, custname);
Deposit(custname, records, array);
Newcopy("data.txt", records, array);

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

void findRichest(int r, PERSON array[]){
int temp = 0;
int counter = 0;

for (int i = 0; i < r; i++){
  if (array[i].Balance > temp ){
    temp = array[i].Balance;
    counter = i;
  }
}
cout << "The customer with maximum balance is " << array[counter].Name << endl;

}

void Deposit(string custname, int r, PERSON array[]){

int depositmoney;

for (int i = 0; i < r; i++){
  if (custname != array[i].Name){

  }
  else{
    cout << custname << ", How much would you like to deposit? ";
    cin >> depositmoney;
    array[i].Balance = array[i].Balance + depositmoney;
    cout << "Now your new balance is " << array[i].Balance << endl;
  }
}
}
void Newcopy(string file, int r, PERSON array[]){

ofstream outfile;
outfile.open("data.txt");
for (int i = 0; i < r; i++){
  outfile << array[i].Name << " " << array[i].Balance << endl;
}
outfile.close();

}
