#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERRNOATTR "\nError con los argumentos, es todo lo que sabemos.\n"
#define HINTUSAGE "\nUso: ./p1 lenguaje1 lenguaje2 ... lenguajen operación\n"
struct Lang
{
   char  ** items;
   int   noItems;
};
void initStr(char * stro, int lim){
  int x;
  for(x=0;x<lim;x++){
    stro[x]='\0';
   }
}
void header(void){
  system("clear");
  printf("\nCode: Javier Mejia Perez");
  printf("\nPráctica 1\n");
  printf("Operaciones entre lenguajes\n\n");
}
void nlines(int n){
  int x;
  for(x=0;x<n;x++){
    printf("\n");
  }
}

char ** stripLang(char * cad,int noItems){
  printf("\nStripping [%s], [%d] items\n",cad, noItems-1);
  char aux[50];
  initStr(aux,50);

  int a,b,c;
  int space=0;
  int l,k, itemss=0;
  //puts(cad);
  char ** final= (char **)malloc( noItems* sizeof(char *));
  for(c=0;c<noItems;c++){
    final[c] = (char *)malloc(50 * sizeof(char));
  }
  int len=0, lena=0;
  while(len!=strlen(cad)){
    if(cad[len]!=','&& cad[len]!=' ' ){
      aux[lena]=cad[len];
      lena++;
    }else{
      lena=0;
      strcpy(final[itemss],aux);
      itemss++;
      initStr(aux, 50);    }
    len++;

  }
   return final;
}

void printLang(int argc, char ** argv){
  int x;
  nlines(1);
  for(x=1; x<argc-1; x++){
    printf("L_%d={%s}\n",x,argv[x]);
  }
  nlines(1);
}
int langLen(char * lang){
  int len=0,c;
  for(c=0;c<strlen(lang);c++){
    if(lang[c]==','){
      len++;
    }
  }
  return len+1;
}

char ** concatenate(struct Lang * cad1,struct Lang * cad2){
 int x,y,z=0;
 int l,m,n,c;
 char aux[50];
 char ** final= (char **)malloc((cad2->noItems-1)*(cad1->noItems-1) * sizeof(char *));
 for(c=0;c<(cad2->noItems-1)*(cad1->noItems-1);c++){
   final[c] = (char *)malloc(50 * sizeof(char));
 }
 printf("L_1L_2 = {");
 for(x=0;x<cad2->noItems-1;x++){
   for(y=0;y<cad1->noItems-1;y++){
     for(l=0;l<strlen(cad1->items[y]);l++){
       aux[l]=cad1->items[y][l];
     }
    // strcpy(aux,cad1->items[y]);
     strcat(aux,cad2->items[x]);
     strcpy(final[y], aux);
     printf("%s,", aux);
     z++;
     initStr(aux, 50);
   }
   }
   printf("}");
   return final;
}

void printLan(struct Lang * cad1){
  int i;
  for(i=0;i<cad1->noItems;i++){
    printf("%s,",cad1->items[i]);

  }

}
// void powL(struct Lang * cad1,int power){
//   int x,c,i;
//   if(power==2){
//     concatenate(cad1,cad1);
//   }
//   else{
//     powL(concatenate(cad1,cad1),power-1);
//   }
// }
char * reverseItem(char * lang){
  int x,y=strlen(lang);
  char aux[50];
  char *aux2;
  initStr(aux,50);
  for(x=0;x<strlen(lang);x++){
    aux[x]=lang[x];
  }
  strcpy(aux2,aux);
  return aux2;
}
void reverseLang(struct Lang * cad1){
 int x,y,z=0;
 int l,m,n,c;
 // char ** concat= (char **)malloc( (cad2->noItems-1)*(cad1->noItems-1)* sizeof(char *));
 // for(c=0;c<noItems;c++){
 //   final[c] = (char *)malloc(50 * sizeof(char));
 // }
 char aux[50];
 printf("1/L_1 = {");
 for(x=0;x<cad1->noItems-1;x++){
   printf("%s", reverseItem(cad1->items[x]));
 }

   printf("}");
}
int main(int argc, char ** argv){
  system("clear");
  header();
  if(argc < 3){
    puts(ERRNOATTR);
    puts(HINTUSAGE);
    exit(0);
  }

  int noLang = argc - 2;
  struct Lang *langs[noLang];
  printf("Número de lenguajes: [%d]", noLang);
  nlines(1);
  int a,b,z;
  char aux[50];
  char aux2[50];
  for(b=0;b<noLang;b++){
    langs[b] =    malloc(sizeof(struct Lang));
    langs[b]->noItems = langLen(argv[b+1]);
    langs[b]->items =  stripLang(argv[b+1], langs[b]->noItems);
   }
  if(noLang==1){
  printf("Lenguaje:");}
  else
  {printf("Lenguajes:");}
  printLang(argc, argv);
  nlines(1);
  int opc=-1;
  if(strcmp(argv[argc-1], "UNION")==0 || strcmp(argv[argc-1], "union")==0){
    opc = 0;
  }
  else if(strcmp(argv[argc-1], "CONCATENACION")==0
  || strcmp(argv[argc-1], "concatenacion")==0){
    opc = 1;
  }
  else if(strcmp(argv[argc-1], "POTENCIA" )==0
  || strcmp(argv[argc-1], "potencia")==0){
    opc = 2;
  }
  else if(strcmp(argv[argc-1], "INVERSA" )==0
  || strcmp(argv[argc-1], "inversa")==0){
    opc = 3;
  }
  else if(strcmp(argv[argc-1], "MUESTRA LENGUAJES" )==0
  || strcmp(argv[argc-1], "muestra lenguajes")==0){
    opc = 4;
  }
  switch(opc){
    //UNION
    case 0:
      nlines(2);
      printf("Operación a realizar: [%s]\n\n", argv[argc-1]);
      nlines(2);
      break;
    //CONCATENACION
    case 1:
      nlines(2);
      printf("Operación a realizar: [%s]\n\n", argv[argc-1]);
      nlines(2);
      concatenate(langs[0],langs[1]);
      break;
    //POTENCIA
    case 2:
      nlines(2);
      printf("Operación a realizar: [%s]\n\n", argv[argc-1]);
      nlines(2);
      if(noLang>2){
        puts(ERRNOATTR);
        exit(1);
      }
    //  powL(langs[0], 1);
      break;
    //INVERSA
    case 3:
      nlines(2);
      printf("Operación a realizar: [%s]\n\n", argv[argc-1]);
      nlines(2);
      if(noLang>2){
        puts(ERRNOATTR);
        exit(1);
      }
      reverseLang(langs[0]);

      break;
    //MUESTRA LENGUAJES
    case 4:
      nlines(2);
      printf("Operación a realizar: [%s]\n\n", argv[argc-1]);
      printf(">> Ejecutando...\n");
      nlines(2);
      printLang(argc, argv);
      break;
    default:
      printf("%s",HINTUSAGE);
    break;
  }

  return 0;
}
