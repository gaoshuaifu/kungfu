#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct Contact {
  string name;
  vector<string> emails;
  Contact(string name){
    this->name = name;
  }
};

class Solution {
public:
  void deduplicateHelper(
    Contact& contact,
    map<string, vector<Contact> >& email2Contacts,
    set<string>& visited,
    vector<string>& group
  ) {
    if(visited.count(contact.name) > 0)
      return;

    visited.insert(contact.name);
    group.push_back(contact.name);

    for(int i = 0; i < contact.emails.size(); i++) {
      string email = contact.emails[i];
      vector<Contact> neighborContacts = email2Contacts[email];
      for(int j = 0; j < neighborContacts.size(); j++) {
        deduplicateHelper(neighborContacts[j], email2Contacts, visited, group);
      }
    }
  }


  vector<vector<string> > deduplicate(vector<Contact>& contacts) {
    map<string, vector<Contact> > email2Contacts;
    for(int i = 0; i < contacts.size(); i++) {
      vector<string> emails = contacts[i].emails;
      for(int j = 0; j < emails.size(); j++) {
        email2Contacts[emails[j]].push_back(contacts[i]);
      }
    }

    vector<vector<string> > res;
    set<string> visited;
    for(int i = 0; i < contacts.size(); i++) {
      vector<string> group;
      deduplicateHelper(contacts[i], email2Contacts, visited, group);
      if(!group.empty()) {
        res.push_back(group);
      }
    }
    return res;
  }
};

int main() {
  Contact c1("C1");
  c1.emails.push_back("yangw@facebook.com");
  c1.emails.push_back("yang@gmail.com");

  Contact c2("C2");
  c2.emails.push_back("bob@facebook.com");

  Contact c3("C3");
  c3.emails.push_back("yang@gmail.com");
  c3.emails.push_back("yangwang@yahoo.com");

  Contact c4("C4");
  c4.emails.push_back("yangwang@yahoo.com");

  Contact c5("C5");
  c5.emails.push_back("bob@facebook.com");

  Contact c6("C6");
  c6.emails.push_back("jamie@facebook.com");

  vector<Contact> contacts;
  contacts.push_back(c1);
  contacts.push_back(c2);
  contacts.push_back(c3);
  contacts.push_back(c4);
  contacts.push_back(c5);
  contacts.push_back(c6);

  Solution solution;
  vector<vector<string> > res = solution.deduplicate(contacts);
  for(int i = 0; i < res.size(); i++) {
    for(int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
