#include <ctype.h>
#include <stdio.h>
#include <string.h>

void wis(char s[]) {
  char st[strlen(s)];
  for (int i = 0; i < strlen(s); i++) {
    if ((s[i] >= 'a' && s[i] <= 'z') || isspace(s[i])) {
      char c = s[i];
      strncat(st, &c, 1);
    }
  }
  strcpy(s, st);
}

int main() {
  char str[] = "8àd'a7!+. -)4h&!e9)b*( )àjé'(àe)ç!è4\n8g|'9è2o!43e5d/.' 2 "
               "3g*(e('d22a'(a25né'(";

  wis(str);
  puts(str);
  return 0;
}