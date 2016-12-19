

void uniqChars(char* in, char* out) {
  uint8_t hash[256] = {0};
  char ch;
  if (!in || !out) {
    return;
  }
  while (ch = *in++) {
    if (!hash[(int)ch]) {
      *out++ = ch;
      hash[(int)ch] = 1;
    }
  }
  *out = '\0';
}
