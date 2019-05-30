
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10


typedef struct {
  char type; // 0=fried chicken, 1=French fries
  int amount; // pieces or weight
  char unit; // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void Log(){
  printf("the first item is= %d\t the last item is = %d\n", first, last);
  return;
}

void produce(item *i){
  while ((first + 1) % BUFFER_SIZE == last){
  }
  memcpy(&buffer[first], i, sizeof(item));
  first = (first + 1) % BUFFER_SIZE;
  Log();
}

item* consume(){
  item* i = malloc(sizeof(item));
  while (first == last){
  
  }
  memcpy(i, &buffer[last], sizeof(item));
  last = (last + 1) % BUFFER_SIZE;
  Log();
  return i;
}

int main()
{ item cake;
    cake.type = 'c';
    cake.amount = 5;
    cake.unit = 'g';
    item candy;
    candy.type = 's';
    candy.amount = 8;
    candy.unit = 'g';
       produce(&cake);
       produce(&candy);
    item*pointer= consume();
    free(pointer);
  return 0;
}

