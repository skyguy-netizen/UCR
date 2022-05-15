#include <iostream>
#include <string>

using namespace std;

void flipString(string &s);

// string flipped = "";

int main()
{
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

// Implement the flipString function here
void flipString(string &s)
{
   string temp = "";
   // int len = s.length();
   if (s.size() == 1 || s.size() == 0)
   {
      return;
   }
   else if (s.size() == 2)
   {
      char one = s.front();
      s.front() = s.back();
      s.back() = one;
      //    s = s.back() + s.front();
      // }
   }
   else
   {
      // flipped = flipped + s.back();
      // cout << flipped << endl;
      // string f = s.substr(1)
      temp = s.substr(1, s.length() - 2);
      // cout << temp << endl;
      char one = s.front();
      s.front() = s.back();
      s.back() = one;
      flipString(temp);
      // s = s.back() + temp + s.front();
      s = s.front() + temp + s.back();
   }
   // s = flipped;
}
