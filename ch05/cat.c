#include <stdio.h>
#include <stdlib.h>

static void do_cat(FILE *f);
static void die(const char *s);

int
main(int argc, char *argv[])
{
  int i;

  //パラメータがなければstdinから読み込む
  if(argc == 1){
    do_cat(stdin);
  }else{
    for(i = 1; i < argc; i++){
      FILE *f;
      f = fopen(argv[i], "r");
      if(!f){
	die(argv[i]);
      }
      do_cat(f);
      fclose(f);
    }
  }
  
  exit(0);
}

static void
do_cat(FILE *f)
{
  int c;

  while((c = fgetc(f)) != EOF){
    if(putchar(c) < 0) exit(1);
  }
}

static void
die(const char *s)
{
  perror(s);
  exit(1);
}
