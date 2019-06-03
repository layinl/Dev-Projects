#include <iostream>
#include <fstream>

using namespace std;

main(){

  char text[200];

  fstream file;
  file.open ("s.txt", ios::out | ios::in );

  cout << "Write text to be written on file." << endl;
  cin.getline(text, sizeof(text));

  // Writing on file
  file << text << endl;

  // Reading from file
  file >> text;
  cout << text << endl;
}
