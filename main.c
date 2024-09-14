#include <stdio.h>
#include <ctype.h>

typedef unsigned long long ullint;

ullint vowels_amount(const char *str) {
  const char *vowels = "aeiou";
  ullint amount = 0;

  for (ullint i = 0; str[i] != '\0'; i++) {
    const char ch = tolower(str[i]);
    for (ullint j = 0; vowels[j] != '\0'; j++) {
      const char vowel = vowels[j];
      if (ch == vowel)
        amount++;
    }
  }

  return amount;
}

int main(int argc, const char **argv) {
  for (int i = 1; i < argc; i++) {
    const char *str = argv[i];
    ullint amount = vowels_amount(str);
    switch (amount) {
    case 0:
      printf("'%s' doesn't contains vowels\n", str);
      break;

    case 1:
      printf("'%s' contains %llu vowel\n", str, amount);
      break;

    default:
      printf("'%s' contains %llu vowels\n", str, amount);
    }
  }

  return 0;
}
