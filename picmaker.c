#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd;
  char line[20];
  char pix[20];

  fd = open("img.ppm", O_CREAT | O_TRUNC | O_WRONLY, 666);
  snprintf(line, sizeof(line), "P3 500 500 255\n");
  write(fd, line, strlen(line));

  for(int i = 0; i < 500; i++){
    for(int j = 0; j < 500; j++){
      snprintf(pix, sizeof(pix), "%d %d %d ", 255, i / 2, j / 2);
		  write(fd, pix, strlen(pix));
    }
  }

  close(fd);
  return 0;
}
