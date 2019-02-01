#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd;
  char line[20];
  char pix[3];

  fd = open("img.ppm", O_CREAT | O_TRUNC | O_WRONLY, 666);
  snprintf(line, sizeof(line), "P3 500 500 255\n");
  write(fd, line, strlen(line));

  for(int i = 0; i < 500; i++){
    for(int j = 0; j < 500; j++){
      pix[0] = i % 100;
      pix[1] = j % 100;
      pix[2] = 100;
      snprintf(line, sizeof(line), "%d %d %d ", pix[0], pix[1], pix[2]);
      write(fd, line, strlen(line));
    }
  }
  
  close(fd);
  return 0;
}
