#include "src/numeral-conversion.h"

#include <assert.h>
#include <string.h>

typedef struct {
  char *key;
  int value;
} Numeral;

static Numeral numerals[] = {
  {"I", 1},
  {"II", 2},
  {"III", 3},
  {"IV", 4},
  {"V", 5},
  {"IX", 9},
  {"X", 10}
};

static size_t numeral_count = sizeof numerals / sizeof numerals[0];

int roman_to_arabic(const char *roman) {
  assert(roman != NULL);

  int arabic = 0;

  for (size_t i = 0; i < numeral_count; i += 1) {
    if (strcmp(roman, numerals[i].key) == 0) {
      arabic = numerals[i].value;
    }
  }

  return arabic;
}

char *arabic_to_roman(char *roman, int arabic) {
  assert(roman != NULL);

  Numeral numerals[] = {
    {"X", 10},
    {"IX", 9},
    {"V", 5},
    {"IV", 4},
    {"I", 1}
  };

  size_t numeral_count = sizeof numerals / sizeof numerals[0];

  strcpy(roman, "");

  for (size_t i = 0; i < numeral_count; i += 1) {
    while (arabic >= numerals[i].value) {
      strcat(roman, numerals[i].key);
      arabic -= numerals[i].value;
    }
  }

  return roman;
}
