#include <stdio.h>

int main()
{
    int n;
    printf("Input: ");
    scanf("%d", &n);
    if(n==1){
      printf("0");
    }
    if(n==2){
      printf("01");
    }
    if(n==3){
      printf("0110");
    }
    char a[]="0110";
    char b[]="1001";
    
    printf("Output: ")
    int cnvrt=0;
    if(n>3){
      for(int i=0;i<n;i++){
        if(cnvrt==0){
          printf("0110");
          cnvrt=1;
        }
        else{
          for(int j=0;j<2;j++){
            printf("1001");
            cnvrt=0;
          }
          i++;
          
        }
      }
    }
    return 0;
}