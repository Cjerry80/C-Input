#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main(){

string line;
int number_of_records = 0;
ifstream inData;
inData.open("data.txt");
cout << "Hi" << endl;
   while (getline(inData, line))
       ++number_of_records;
   cout << "Number of lines in text file: " << number_of_records << endl;
   inData.close();
return 0;
}

struct  PERSON {
    char  Name[20];
    float Balance;
  };
