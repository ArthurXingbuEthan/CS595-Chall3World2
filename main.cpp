#include <iostream>
#include <fstream> // for ifstream
#include <string>
using namespace std;

string reverseString(string s)
{
  string out = "";
  for (int i = s.size() - 1; i >= 0; i--)
  {
    out += s[i];
  }
  return out;
}

char getCharacterFrom7Bits(string s)
{
  int backtodec = 0;

  if (s[6] == '1')
    backtodec += 64;
  if (s[5] == '1')
    backtodec += 32;
  if (s[4] == '1')
    backtodec += 16;
  if (s[3] == '1')
    backtodec += 8;
  if (s[2] == '1')
    backtodec += 4;
  if (s[1] == '1')
    backtodec += 2;
  if (s[0] == '1')
    backtodec += 1;
  int ascii = stoi(s);
  return (char)backtodec;
}

int main(int argc, char **argv)
{

  ofstream w;
  ifstream ifs;

  ifs.open("chall2.exe");
  w.open("output_1.txt");
  string stream;

  char c;
  while(ifs.get(c)){
    stream += std::bitset<8>(c).to_string();
    //w << c << endl;
  }

  int lineNum = 0;
  while(true){
    if(stream.length() < 7) break;
    string temp = stream.substr(0,7);
    //cout << getCharacterFrom7Bits(temp) << " , " << "temp: " << reverseString(temp) << endl;
    cout << lineNum << ": " << getCharacterFrom7Bits(reverseString(temp))  << endl;
    //cout << endl;
    lineNum++;
    w <<  reverseString(temp) << endl;
    //res += getCharacterFrom7Bits(temp);
    stream = stream.substr(7);
  }

  w << stream;
  
  ifs.close();
  w.close();

  return 0;
}
