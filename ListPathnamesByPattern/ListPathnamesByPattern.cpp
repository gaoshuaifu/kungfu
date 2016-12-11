/*
  pattern is a unix file system pathname with wildcats, e.g., "/a/*/b/*/c"

  Two util functions available
  vector<string> listPath(const string& path);
  bool exists(const string& path);
 */

vector<string> listPattern(const string& pattern) {
  vector<string> res;
  int pos = pattern.find_first_of('*');
  if (pos == string::npos) {
    if (exists(pattern)) {
      res.push_back(pattern);
    }
    return res;
  }
  string prefix = pattern.substr(0, pos);
  string suffix = pattern.substr(pos + 1);
  vector<string> children = listPath(prefix);
  for (for int i = 0; i < children.size(); i++) {
    string child = children[i];
    auto r = listPattern(child + suffix);
    res.insert(res.size(), r.begin(), r.end());
  }
  return res;
}
