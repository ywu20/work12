#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>



int print_files(char open_dir[100], char dir_str[100], char fil_str[100]){
  DIR * d = opendir(open_dir);
  if (errno != 0) {
      printf("%s\n", strerror(errno));
      return -1;
  }
  //printf("%p\n", d);
  //if(d )
  struct dirent * dir;
  int size = 0;

  while((dir = readdir(d)) != NULL){
    struct stat file;
    stat(dir->d_name, &file);
    if(dir->d_type == 4){
      strcat(dir_str, "\n");
      strcat(dir_str, dir->d_name);

    }else{
      strcat(fil_str,"\n");
      strcat(fil_str, dir->d_name);
    }
    size += file.st_size;
    //printf("%s, %d\n",dir->d_name, dir ->d_type);
  }

  return size;

}
int main(int argc, char * argv[]){
  char dir_str[100] = "";
  char fil_str[100] = "";
  char buffer[100];
  if(argc <=1){
    printf("Enter a directory:\n ");
    fgets(buffer,sizeof(buffer),stdin);
    //read(STDIN_FILENO, buffer, sizeof(buffer));
    buffer[strlen(buffer)-1] = 0;
    //printf("str:%s\n", buffer);
    //printf("strcmp %d\n", strcmp(buffer, "./"));

  }else{
    strcpy(buffer, argv[1]);
  }

  int a = print_files(buffer, dir_str, fil_str);
  printf("Total Diectory Size: %ul Bytes\n", a);
  printf("Directories: %s\n", dir_str);
  printf("Regular Files: %s\n", fil_str);
  return 0;
}
