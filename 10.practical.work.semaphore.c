
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include<semaphore.h>
#define BUFFER_SIZE 10


sem_t sem;
int sem_init(sem_t *sem, int pshared, unsigned int value);
int sem_wait(sem_t *sem);
int sem_post(sem_t *sem);
int sem_destroy(sem_t *sem);

typedef struct {
  char type; // 0=fried chicken, 1=French fries
  int amount; // pieces or weight
  char unit; // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
  while ((first + 1) % BUFFER_SIZE == last) {
   
  }
  memcpy(&buffer[first], i, sizeof(item));
  first = (first + 1) % BUFFER_SIZE;
     printf(" First: %d Last %d \n", first, last);
}

item *consume() {
  item *i = malloc(sizeof(item));
  while (first == last) {

  }
  memcpy(i, &buffer[last], sizeof(item));
  last = (last + 1) % BUFFER_SIZE;
  return i;
}
void *producer(void *para) {
    item fc, Ff1, Ff2;
    
    fc.type = 0;
    fc.amount = 1;
    fc.unit = 0;
    
    Ff1.type = 1;
    Ff1.amount = 2;
    Ff1.unit = 1;
    
    Ff2.type = 1;
    Ff2.amount = 3;
    Ff2.unit = 1;
    
    produce(&fc);
    produce(&Ff1);
    produce(&Ff2);
    
    return NULL;
}


void display(item* i) {
	printf("Type: %c Amount(s): %d Unit: %c\n",i->type,i->amount,i->unit);
} 

void *consumer(void *para) {
	display(consume());
    display(consume());
    return NULL;
}

int main() {
	pthread_t tid1,tid2;
  sem_init(&sem, 0, 1);
	pthread_create(&tid1, NULL, producer, NULL);
 	pthread_create(&tid2, NULL, consumer, NULL);
  sem_destroy(&sem);
  printf("After produce: First: %d Last %d \n", first, last);
  consume();
  printf("After consume: First: %d Last %d \n", first, last);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
	return 0;
}

