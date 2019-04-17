#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

struct  PERSON {
    char  Name[20];
    float Balance;
};

int getnumberofRecords();
void Readfile(int N, PERSON P[]);
void Display(int N, PERSON P[]);
void findRichest(int N, PERSON P[]);
void Newcopy(string file, int N, PERSON P[]);
PERSON * readData(int N);
void Deposit(Person P[], int N, string custName,float amount);

int main(){

PERSON * P = nullptr;
P = readData(N);
string custName;
float amount;

Readfile(N, P);
Display(N, P);
findRichest(N, P);

cout << "Enter name: " << endl;
cin.ignore();
getline(cin, custName);
cout << "Amount: " << endl;
cin >> amount;
Deposit(P, N, custName, amount);
Newcopy("data.txt", N, P);

return 0;

}

PERSON * readData(int N){
N = getnumberofRecords();
ifstream infile;
string firstn;
string lastn;
string line;
Person * P = null;
infile.open("data.txt");
A = new PERSON[N];


for (int i = 0; i < N; i++){
  infile >> firstn;
  infile >> lastn;
  infile >> A[i].balance;
  getline(infile, line);
  strncpy(A[i].Name, firstn.c_str(), 9);
  strcat(A[i].Name, " ");
  strncat(A[i].Name, lastn_c_str(),10);
  }
  infile.close();

return A;
}


int getnumberofRecords(){

  int records;

  fstream file ("data.txt");
  if (file.is_open()){
    while (getline(file, line))
    {
    ++records;
    }
    file.close();

  return records;
}

void Display(int N, PERSON P[]){
cout << "Display: " << endl;
for(int i = 0; i < N; i++){
cout << P[i].Name << " " << P[i].balance << endl;
}

}
void findRichest(int N, PERSON P[]){
  int temp = 0;
  int counter = 0;
  cout << "Find Richest: " << endl;
  for (int i = 0; i < r; i++){
    if (P[i].balance > temp ){
      temp = P[i].balance;
      counter = i;
    }
  }
  cout << "Highest Balance: " << P[counter].Name << endl;
}
void Deposit(Person P[], int N, string custName, float amount){
for (int i = 0; i < N; i++ ){
  if (custName == P[i].Name){
    P[i].balance = P[i].balance + amount
    cout << "New Balance: " << P[i].balance << endl;
  }
  else {
    cout << "Record not found. " << endl;
  }
}
}


void Newcopy(string file, int N, PERSON P[]){

ofstream outfile;
cout << "Newcopy: " << endl;
outfile.open("data.txt");
for (int i = 0; i < r; i++){
  outfile << P[i].Name << " " << P[i].balance << endl;
}
outfile.close();
cout << "File Updated.." << endl;

}
