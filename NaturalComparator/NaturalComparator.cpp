/*

["photo1", "photo2", "photo11", "photo10"] should naturally sort to ["photo1", "photo2", "photo10", "photo11"]
and NOT the default lexicographical order ["photo1", "photo10", "photo11", "photo2"].

*/

 int natcmp(const char* a, const char* b) {
     while (*a && *b) {
         if (isdigit(*a) && isdigit(*b)) {
             if(int d = strtol(a, &a, 10) - strtol(b, &b, 10)) {
                 return d;
             }
         } else if (int d = *a++ - *b++)) {
             return d;
         }
     }
     return *a - *b;
 }
