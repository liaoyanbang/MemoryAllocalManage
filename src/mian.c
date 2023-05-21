#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#include "memory.h"

void INT_handler(int arg)
{
  int status;
  Memory_Allocal_Manage_Deinit();
  exit(status);
  printf("%d\n",status);
}

int main() 
{
  Memory_Allocal_Manage_Init();
  signal(SIGINT,INT_handler);

  int* addr = (int*)Memory_Allocal_Get(TYPE_SMALL);
  Memory_Allocal_Release(&addr);
  Memory_Allocal_Get(TYPE_HUGE);


  for (;;) {
  }
}