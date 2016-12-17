#include <iostream>
using namespace std;

class ArbitraryIO {
public:
  ArbitraryIO(Read4k& read4k) :
    read4k_(read4k),
    bufferLength_(0),
    bufferOffset_(0) { }

  int read(int length, char* buf) {
    char* origBuf = buf;

    while (length > 0) {
      if (bufferLength_ == 0) {
        bufferLength_ = read4k_.read4k(buffer_);
        if (bufferLength_ == 0) {
          break;
        }
        bufferOffset_ = 0;
      }

      int lengthToCopy = std::min(length, bufferLength_);
      memcpy(buf, buffer_ + bufferOffset_, lengthToCopy);
      buf += lengthToCopy;
      bufferOffset_ += lengthToCopy;
      length -= lengthToCopy;
      bufferLength_ -= lengthToCopy;
    }

    return buf - origBuf;
  }

private:
  Read4k& read4k_;
  char buffer_[4096];
  int bufferOffset_;
  int bufferLength_;
};

class File {
 public:
  File(const string& filename);
  string readLine() {
    string retLine;
    while (true) {
      // Check to see if we need to read more characters.
      if (chunk4k_ == "") {
        chunk4k_ = this->read4k();
        if (chunk4k_ == "") {
          // Alternatively break and have return at end of method.
          return retLine; // We've reached the end of file.
        }
      }

      const auto pos = chunk4k_.find('\n');
      if (pos != string::npos) {
        retLine += chunk4k_.substr(0, pos+1);
        chunk4k_.erase(0, pos+1);
        return retLine; // We've found a \n character.
      }
      // Consume this chunk and keep looking in the next chunk.
      retLine += chunk4k_;
      chunk4k_.erase();
    }
  }

 private:
  string read4k();
  string chunk4k_;
};
