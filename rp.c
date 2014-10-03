#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct voyage;

typedef struct station{
  char *stationname;
  struct voyage *travel;
} *Station;

typedef struct voyage{
  int *time;
  int *line;
  struct station *connection1;
  struct station *connection2;
}*Voyage;

int main(){
  return 0;
}
