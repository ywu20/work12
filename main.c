#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>



int print_files(char open_dir[100], char dir_str[100], char fil_str[100]){
  DIR * d = opendir(open_dir);
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
int main(){
  char dir_str[100] = "";
  char fil_str[100] = "";

  int a = print_files("./", dir_str, fil_str);
  printf("Total Diectory Size: %d Bytes\n", a);
  printf("Directories: %s\n", dir_str);
  printf("Regular Files: %s\n", fil_str);
  return 0;
}
