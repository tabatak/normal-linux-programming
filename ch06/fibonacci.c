#include <stdio.h>
#include <stdlib.h>

static unsigned long int fib(int i);

int
main(int argc, char *argv[])
{
  if(argc != 2){
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    exit(1);
  }

  fprintf(stdout, "%ld\n", fib(atol(argv[1])));
  exit(0);
}

static unsigned long int
fib(int n)
{
  unsigned
    long int arr[n-1];
  arr[0] = 0;
  arr[1] = 1;

  int i;
  for(i = 2; i <= n; i++){
    arr[i] = arr[i-1] + arr[i-2];
  }

  return arr[n];
}
		  
			     
