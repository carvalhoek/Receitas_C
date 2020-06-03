#ifndef DASKREUTZBANK_H_INCLUDED
#define DASKREUTZBANK_H_INCLUDED

#define typename(x) _Generic((x),                      \
        _Bool: 1,           unsigned char: 2,          \
         char: 3,           signed char: 4,            \
    short int: 5,           unsigned short int: 6,     \
          int: 7,           unsigned int: 8,           \
     long int: 9,           unsigned long int: 10,     \
long long int: 11,          unsigned long long int: 12,\
        float: 13,          double: 14,                \
  long double: 15,          char *: 16,                \
       void *: 17,          int *: 18,                 \
      default: "other")

FILE* neueDatenbank(char *name);

FILE* datebankOffnen(char*name);

void datenbankSchreiben(FILE*arq,int type, void*data);

void datebankLesen(FILE *arq);

#endif
