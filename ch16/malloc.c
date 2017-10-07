#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HTTPRequest{
  int protocol_minor_version;
  char *method;
  char *path;
};

static void
read_request_line(struct HTTPRequest *req, char *str);

int
main(int argc, char *argv[])
{

  char *p;
  char data[] = "GET /path/to/file HTTP/1.0\0";

  struct HTTPRequest *req;

  req = malloc(sizeof(struct HTTPRequest));
  read_request_line(req, data);

  free(req->method);
  free(req->path);
  free(req);
  

  exit(0);
}

static void
read_request_line(struct HTTPRequest *req, char *str)
{
  char *path, *p;


  p = strchr(str, ' ');
  if(!p){
    fprintf(stderr, "parse error on request line (1): %s", str);
    exit(1);
  }

  *p++ = '\0'; //strcpyの終端用に設定する!ほっとくとはみ出すよ
  req->method = malloc(p - str);
  strcpy(req->method, str);
  printf("req->method = %s\n", req->method);
  printf("str = %s\n", str);

  path = p;
  p = strchr(path, ' ');
  if(!p){
    fprintf(stderr, "parse error on request line (2): %s", str);
    exit(1);
  }
  *p++ = '\0';
  req->path = malloc(p - path);
  strcpy(req->path, path);
  printf("req->path = %s\n", req->path);
  printf("str = %s\n", str);
  printf("path = %s\n", path);
}
