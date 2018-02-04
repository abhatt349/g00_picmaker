#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void gen_image(char * file_name){
  int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  
  char * heading = "P3 500 500 255 ";
  
  //char * body = calloc(1, 5000000);
  
  int i;
  int k;

  int r;
  int g;
  int b;
  char * pixeln;

  write(fd, heading, strlen(heading));

  for(i = 0; i < 500; i++){
    for(k = 0; k < 500; k++){
      r = i % 128;
      g = 255;
      b = k % 128;
      sprintf(pixeln, "%d %d %d ", r, g, b);
      write(fd, pixeln, strlen(pixeln));
    }
  }


  //write(fd, heading, 30);
  //write(fd, body, 8000000);
  //free(body);
}

int main(){
  char * name = "basic.ppm";
  gen_image(name);
  return 1;
}




