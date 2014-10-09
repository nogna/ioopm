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
  char *line;
  struct stop *start;
  struct stop *stop;
  char *time;
  struct edge *next;
}*Edge;



char reformatLine(char line[128]){
  for(int i=0;i<=128;i++){
    if( line[i]==","){
      line[i]="\0";
      line[i++];
    }
  }
}

void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(/*dest[len-1] == '\n' || */dest[len-1] == ',')
    dest[len-1] = '\0';
}

int Inlist(Stop List, char key[128]){

  if(List){
    if(strcmp(key,List->name)==0){
      return 1;
    }
    else{
      Inlist(List->next,key);
    }
  }
  return 0;
  
}

void InsertEdge(Edge *Edges, Edge *newEdge){
  if (!(*Edges)){
    *Edges=*newEdge;
  }
  else{
    (*newEdge)->next=*Edges;
    *Edges=*newEdge;
  }
}

/*char delim[2] = ",";
strtok(str, delim)

if (string[0] == 32)
  string = string + 1
*/

void printStops(Stop Stops){
  while(Stops){
    printf("%s\n", Stops->name);
    Stops=Stops->next;
  }
}


void InsertStop(Stop *Stops, Stop *newStop){
  if(!(*Stops)){
    *Stops=*newStop;
  }
  else{
    if(!Inlist(*Stops,(*newStop)->name)){
      (*newStop)->next=*Stops;
      *Stops=*newStop;
    }
    else
      puts("\nIndex already loaded.\n");
  }    
}

/*void createLists(char *filename){
  char buffer[128];
  FILE *buschart = fopen(filename, "r");
  Stop Stops=NULL;
  Edge Edges =NULL;
  char newstartname[128], newstopname[128];
  while(!(feof(buschart))){
    Stop newStop=malloc(sizeof(struct stop));
    Edge newEdge=malloc(sizeof(struct edge));

    readline(buffer, 128, buschart);
    newEdge->line=malloc(strlen(buffer)+1);
    strcpy(newEdge->line,buffer);

    readline(buffer, 128, buschart);
    newStop->name = malloc(strlen(buffer)+1);
    newEdge->start = malloc(strlen(buffer)+1);
    strcpy(newstartname, buffer);
    newEdge->start->name=newstartname;
    strcpy(newStop->name, buffer);

    readline(buffer, 128, buschart);
    newEdge->stop = malloc(strlen(buffer)+1);
    strcpy(newstopname, buffer);
    newEdge->stop->name=newstopname;


    readline(buffer, 128, buschart);
    newEdge->time=malloc(strlen(buffer)+1);
    strcpy(newEdge->time,buffer);


    newEdge->next=NULL;
    newEdge->start->route=NULL;
    newEdge->start->next=NULL;
    newEdge->stop->route=NULL;
    newEdge->stop->next=NULL;
    newStop->next=NULL;
    newStop->route=NULL;
    InsertStop(&Stops, &newStop);
    InsertEdge(&Edges, &newEdge);
  }
}
*/
int main(int argc, char *argv[]){
  if (argc < 2){
    puts("Usage: rp [FILE]");
    return -1;  
  }
  char *filename = argv[1];
  //  createLists(filename);
  char buffer[128];
  FILE *buschart = fopen(filename, "r");
  Stop Stops=NULL;
  Edge Edges =NULL;
  char newstartname[128], newstopname[128];
  while(!(feof(buschart))){
    Stop newStop=malloc(sizeof(struct stop));
    Edge newEdge=malloc(sizeof(struct edge));

    readline(buffer, 128, buschart);
    newEdge->line=malloc(strlen(buffer)+1);
    strcpy(newEdge->line,buffer);

    readline(buffer, 128, buschart);
    newStop->name = malloc(strlen(buffer)+1);
    newEdge->start = malloc(strlen(buffer)+1);
    strcpy(newstartname, buffer);
    newEdge->start->name=newstartname;
    strcpy(newStop->name, buffer);

    readline(buffer, 128, buschart);
    newEdge->stop = malloc(strlen(buffer)+1);
    strcpy(newstopname, buffer);
    newEdge->stop->name=newstopname;


    readline(buffer, 128, buschart);
    newEdge->time=malloc(strlen(buffer)+1);
    strcpy(newEdge->time,buffer);


    newEdge->next=NULL;
    newEdge->start->route=NULL;
    newEdge->start->next=NULL;
    newEdge->stop->route=NULL;
    newEdge->stop->next=NULL;
    newStop->next=NULL;
    newStop->route=NULL;
    InsertStop(&Stops, &newStop);
    InsertEdge(&Edges, &newEdge);
  }  
puts("Database loaded!\n");

  int choice = -1;
  while(choice != 0){
    puts("Please choose an option!\n");
    puts("1. Print Stations");    
    puts("2. Get shortest route");
    puts("--Travel--");   
    puts("3. Arrival time ");
    puts("4. Depature time");
    puts("0. Exit MENU");
    printf("? ");
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear stdin
    switch(choice){
    case 1:
      printStops(Stops);
    }
   
  }
 return 0;
}
