// Cheng  No Chang
// 301 Section 3

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;

struct  PERSON {
    char  Name[20];
    float Balance;
};

int getnumberofRecords();
void Display(int N, PERSON P[]);
void findRichest(int N, PERSON P[]);
void Newcopy(string file, int N, PERSON P[]);
PERSON * readData(int & N);
void Deposit(PERSON P[], int N, string custName,float amount);
void Custinfo(int N, PERSON P[]);

void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}

int main()
{
  int choice;
  int N = 0;
  PERSON *P = nullptr;
  P = readData(N);
    do
    {
        printmenu();
        cout << "What would you like to do? ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                Display(N, P);
                break;

            case 2:
                Custinfo(N, P);

                break;

            case 3:
                findRichest(N, P);
                break;

            case 4:
                Newcopy("data.txt", N, P);
                break;

            case 5:
                Newcopy("data.txt", N, P);
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 5);
      return 0;
}


PERSON *readData(int & N){
N = getnumberofRecords();
ifstream infile;
string firstn = " ";
string lastn = " ";
string line = " ";
PERSON * P = nullptr;
P = new PERSON[N];
infile.open("data.txt");


for (int i = 0; i < N; i++){
  infile >> firstn;
  infile >> lastn;
  infile >> P[i].Balance;
  getline(infile, line);
  strncpy(P[i].Name, firstn.c_str(), 9);
  strcat(P[i].Name, " ");
  strncat(P[i].Name, lastn.c_str(), 10);
  }
  infile.close();

return P;
}


int getnumberofRecords(){
  string line = " ";
  int records = 0;
  ifstream infile;
  infile.open("data.txt");
    while (!infile.eof()){
    getline(infile, line);
    records++;
    }

    infile.close();
return records;
}

void Display(int N, PERSON P[]){
cout << "Display: " << endl;
for(int i = 0; i < N; i++){
cout << P[i].Name << " " << P[i].Balance << endl;
}

}
void findRichest(int N, PERSON P[]){
  int temp = 0;
  int counter = 0;
  cout << "Find Richest: " << endl;
  for (int i = 0; i < N; i++){
    if (P[i].Balance > temp ){
      temp = P[i].Balance;
      counter = i;
    }
  }
  cout << "Highest Balance: " << P[counter].Name << endl;
}

void Deposit(PERSON P[], int N, string custName, float amount){

  for (int i = 0; i < N; i++ ){
    if (custName == P[i].Name){
      P[i].Balance = P[i].Balance + amount;
      cout << "New Balance: " << P[i].Balance << endl;
    }
  }
}


void Newcopy(string file, int N, PERSON P[]){

ofstream outfile;
cout << "Newcopy: " << endl;
outfile.open("data.txt");
for (int i = 0; i < N; i++){
  outfile << P[i].Name << " " << P[i].Balance << endl;
}
outfile.close();
cout << "File Updated.." << endl;

}

void Custinfo(int N, PERSON P[]){
  int count = 1;
  float amount = 0;
  string customername = " ";
  cout << "Enter name: ";
  cin.ignore();
  getline(cin, customername);
  for (int i = 0; i < N; i++){
    if (customername == P[i].Name){
      cout << "Amount: ";
      cin >> amount;
      Deposit(P, N, customername, amount);
    }
    else
      count++;
  }
  if (count > N)
    cout << "Record not found. " << endl;
}
