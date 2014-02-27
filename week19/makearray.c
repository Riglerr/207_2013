int main(int argc, char *argv[])
{
  int count=0;
  int i;
  int* a=(int*) malloc(20*sizeof(int));
  for(i=0;i<=20;i++){
    count=(count+1)%3;
    a[i]=0;
    if(a[i]=0){
      printf("BING!\n");
    }
  }
  return 0;
}
