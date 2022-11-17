#include <stdio.h>

void my_toupper(char *s, size_t len) {
  for (int i = 0; i < len; i++) {
    if ((s[i]) >= 'A' && (s[i]) <= 'Z')
      s[i] = s[i] - ('A' - 'a');
  }

  if (*s >= 'a' && *s <= 'z')
    *s = *s + ('A' - 'a');
}

int main() {
  char str[] = "snEEuwwITJE<3!!";
  my_toupper(str, sizeof(str)/sizeof(char));
  puts(str);
  return 0;
}