#include <stdio.h>

#include "memory.h"

int main() {
  Memory_Allocal_Manage_Init();
  int* addr = (int*)Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Release(&addr);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);

  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);
  Memory_Allocal_Get(TYPE_HUGE);


  Memory_Allocal_Manage_Deinit();

  for (;;) {
  }
}