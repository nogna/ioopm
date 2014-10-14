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

/*char reformatLine(char line[128]){
  for(int i=0;i<=128;i++){
  if( line[i]==","){
  line[i]="\0";
  line[i++];
  }
  }
  }
*/
void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n')
    dest[len-1] = '\0';
}

int Inlist(Stop Stops, char key[128]){
  int found = 0;
  while(Stops && found==0){
    if(strcmp(key,Stops->name)==0){
      found++;
    }
    else
      Stops=Stops->next;
  }
  return found;
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
  }
}


int main(int argc, char *argv[]){
  if (argc < 2){
    puts("Usage: rp [FILE]");
    return -1;
  }
  char *filename = argv[1];
  // createLists(filename);
  char buffer[128];
  FILE *buschart = fopen(filename, "r");
  Stop Stops=NULL;
  Edge Edges =NULL;
  char newstartname[128], newstopname[128];
  printf("Loading database: %s\n",filename);

  while(!(feof(buschart))){
    readline(buffer, 128, buschart);
    if(strcmp(buffer,"")!=0){
      Stop newStop=malloc(sizeof(struct stop));
      Edge newEdge=malloc(sizeof(struct edge));
      char *copy = malloc(strlen(buffer)+1);
      char *loc;
 
      //line
      strcpy(copy,buffer);  
      strtok (buffer,",");
      char *line =  malloc(strlen(buffer)+1);
      strcpy(line,buffer);
      loc = strchr(copy,',');
      strcpy(copy,loc+2);

      newEdge->line=malloc(strlen(buffer)+1);
      strcpy(newEdge->line,line);

      //start
      strcpy(buffer,copy);
      strtok (buffer,",");
      char *start =  malloc(strlen(buffer)+1);
      strcpy(start,buffer);
      loc = strchr(copy,',');
      strcpy(copy,loc+2);

      newStop->name = malloc(strlen(buffer)+1);
      newEdge->start = malloc(strlen(buffer)+1);
      strcpy(newstartname, start);
      newEdge->start->name=newstartname;
  
      //stop
      strcpy(buffer,copy);
      strtok (buffer,",");
      char *stop =  malloc(strlen(buffer)+1);
      strcpy(stop,buffer);
      loc = strchr(copy,',');
      strcpy(copy,loc+2);

      strcpy(newStop->name, buffer);
      newEdge->stop = malloc(strlen(buffer)+1);
      strcpy(newstopname, stop);
      newEdge->stop->name=newstopname;

      //time
      char *time =  malloc(strlen(buffer)+1);
      strcpy(time,copy);
      newEdge->time=malloc(strlen(buffer)+1);
      strcpy(newEdge->time,time);

      strcpy(buffer,"");
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
  puts("Database loaded!\n-----------");
  int choice = -1;
  while(choice != 0){
    
    puts("1. Print Stations");
    puts("2. Get shortest route\n");
    puts("---Travel---");
    puts("3. Arrival time ");
    puts("4. Depature time");
    puts("-----------");
    puts("0. Exit MENU\n");
    puts("Please choose an option!\n");
    printf("? ");
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear stdin
    switch(choice){
    case 1:
      printStops(Stops);
      break;
    case 2:
      puts("TO BE IMPLEMENTED\n");
      break;
    case 3:
      puts("TO BE IMPLEMENTED\n");
      break;
    case 4:
      puts("TO BE IMPLEMENTED\n");
      break;
    case 0:
      puts("BYE!\n");
      break;
    default:
      puts("Invalid option, please try again!\n");
      break;
    }
  }
  return 0;
}
