#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main(int argc,char *argv[])
{
     struct stat Odir;
     struct dirent *d_stat;

     long int inode,pinode;
     DIR *cur_dir;
     char nameofdir[225];

while(inode>2)
{
     lstat(".",&Odir);
     inode=Odir.st_ino;
     chdir("..");
     cur_dir = opendir(".");

    while ((d_stat = readdir(cur_dir)) != NULL)
    {
            pinode=d_stat->d_ino;
            if(pinode==inode){
                strcpy(nameofdir,d_stat->d_name);
                if(!strcmp(nameofdir,"."))
                    printf("home\n");
                else if(!strcmp(nameofdir,".."))
                    printf("root\n");
                else
                    printf("%s\n",nameofdir);
            }
    }
    closedir(cur_dir);
}
    return 0;

}
