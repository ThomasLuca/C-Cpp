#include <stdio.h>
#include <stdlib.h>

void plaats_ptr_op_string(char **sl, char c) {
  char **p_sl = sl;

  // TODO: check when NULL is reached
  while ((*p_sl)[0] != c /* || *p_sl != NULL */) {
    p_sl++;
  }

  *sl = *p_sl;
}

int main() {
  char *stringlist[8] = {
      "Tis but a scratch",
      "A scratch? Your arm's off!",
      "It's just a flesh wound",
      "I blow my nose at you",
      "I fart in your general direction!",
      "Your father smelt of elderberries!",
      "Ekki-ekki-ekki-pitang-zoom-boing!",
      NULL,
  };

  plaats_ptr_op_string(stringlist, 'Y');
  puts(stringlist[0]);
  return 0;
}
