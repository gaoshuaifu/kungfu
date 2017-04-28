#include <iostream>
using namespace std;

class Solution {
public:
  string indent(int indentLevel) {
    string res;
    while(indentLevel--)
      res += "  ";
    return res;
  }

  string jsonPrettify(string json) {
    string res;
    int indentLevel = 0;
    bool inString = false;
    bool escaped = false;

    for(int i = 0; i < json.size(); i++) {
      char c = json[i];
      if(escaped) {
        res.push_back(c);
        escaped = false;
        continue;
      }

      if(c == '\\') {
        escaped = true;
        res.push_back(c);
        continue;
      }

      if(c == '"') {
        inString = !inString;
      }

      if(inString) {
        res.push_back(c);
      }
      else {
        switch (c) {
          case '{':
          case '[':
            res.push_back(c);
            res += "\n";
            res += indent(++indentLevel);
            break;
          case '}':
          case ']':
            res += "\n";
            res += indent(--indentLevel);
            res.push_back(c);
            break;
          case ',':
            res += ",\n";
            res += indent(indentLevel);
            break;
          case ':':
            res += ": ";
            break;
          case ' ':
          case '\n':
          case '\t':
            break;
          default:
            res.push_back(c);
        }
      }
    }
    return res;
  }
};



int main() {
  string json = "[1, 2, {\"a\": \"asdf\",\"b\": [5.6, 7.8]}]";
  cout << "Original JSON:\n" << json << endl;

  Solution solution;
  string pretty = solution.jsonPrettify(json);
  cout << "Pretty JSON:\n" << pretty << endl;
  return 0;
}
