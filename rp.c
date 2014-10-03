#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct edge;
typedef struct stop{
  char *name;
  struct edge *route;
  struct stop *next;
} *Stop;

typedef struct edge{
  int *line;
  struct stop *start;
  struct stop *stop;
  int *time;
  struct edge *next;
}*Edge;

void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n'|| dest[len-1] == ',')
    dest[len-1] = '\0';
}

int Inlist(Stop List, char key){
  if(List){
    if(List->key==name)
      return 1;
    else
      Inlist(List->next,key);
  }
  else 
    return 0;
}

void InsertStop(Stop *Stops, Stop *newStop){
  if(!(*Stops)){
    *Stops=*newStop;
  }
  else{
    if(!Inlist(Stops,newStop->name)){
      (*newStop)->next=*Stops;
      *Stops=*newStop;
    }

    else
      puts("\nIndex already loaded.\n")


	}
}

void createLists(char *filename){
  char buffer[128];
  FILE *buschart = fopen(filename, "r");
  Stop Stops=NULL;
  Edge Edges =NULL;
  while(!(feof(buschart))){
    Stop newStop=malloc(sizeof(struct stop));
    Edge newEdge=malloc(sizeof(struct edge));

    readline(buffer, 128, buschart);
    newEdge->line=malloc(strlen(buffer)+1);
    strcpy(newEdge->route->line,buffer);

    readline(buffer, 128, buschart);
    newStop->name = malloc(strlen(buffer)+1);
    newEdge->start = malloc(strlen(buffer)+1);
    strcpy(newEdge->start, buffer);
    strcpy(newStop->name, buffer);

    readline(buffer, 128, buschart);
    newEdge->stop = malloc(strlen(buffer)+1);
    strcpy(newEdge->stop, buffer);
    
    readline(buffer, 128, buschart);
    newEdge->time=malloc(strlen(buffer)+1);
    strcpy(newEdge->time,buffer);
  
    newEdge->next=NULL;
    newStop->next=NULL;
    newStop->route=NULL;
    InsertStop(&Stops, &newStop);
    InsertEdge(&Edges, &newEdge)
      }
}

int main(){
  return 0;
}






/*
  void Insert(Map *map, Map *newStop){
  if(!(*map)){
  *map=*newStop;
  }
  else{
    
  }
  }

  Map createMap(char *filename){
  char buffer[128];
  FILE *buschart = fopen(filename, "r");
  Map map=NULL;
  while(!(feof(buschart))){
  Map newStop = malloc(sizeof(struct map));
  //Voyage newRoute = malloc(sizeof(struct voyage))
  readline(buffer, 128, buschart);
  newStop->route->line=malloc(strlen(buffer)+1);
  strcpy(newStop->route->line,buffer);

  readline(buffer, 128, buschart);
  newStop->stationname = malloc(strlen(buffer)+1);
  newStop->route->connection1 = malloc(strlen(buffer)+1);
  strcpy(newStop->route->connection1, buffer);
  strcpy(newStop->stationname, buffer);

  readline(buffer, 128, buschart);
  newStop->route->connection2 = malloc(strlen(buffer)+1);
  strcpy(newStop->route->connection2, buffer);
    
  readline(buffer, 1128, buschart);
  newStop->route->time=malloc(strlen(buffer)+1);
  strcpy(newStop->route->time,buffer)

  }

  }
*/
