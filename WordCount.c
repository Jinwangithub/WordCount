#include <stdio.h>
#include <stdlib.h>
int main()
{
  int count,start;
  FILE *fp;
  char c;
  fp=fopen("D:\\test.txt","r");
  if(fp==NULL)
  {
    printf("Open Failed!\n");
    exit(1);
  }
  fseek(fp,0,SEEK_SET);
  start=1;  //0-���ʿ�ʼ  1-���ǿ�ͷ
  count=0;
  while(feof(fp)==0)
  {
    fread(&c,1,1,fp);
    if(c==' ' && start==1)
    {
      start=1;
    }
    else if(c!=' ' && start==1)
    {
      start=0;
      count++;
    }
    else if(c==' ' && start==0)
    {
      start=1;
    }
  }
  printf("������Ϊ%d\n",count);
  return 1;
}
