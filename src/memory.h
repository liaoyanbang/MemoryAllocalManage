#ifndef _MEMORY_
#define _MEMORY_

#include <stdint.h>

#define TYPE_NUM (3)
#define TYPE1_SIZE (64)
#define TYPE1_COUNT (50)
#define TYPE2_SIZE (512)
#define TYPE2_COUNT (20)
#define TYPE3_SIZE (4096)
#define TYPE3_COUNT (10)


typedef struct memory_node
{
    void* addr;
    uint32_t using_flag;// 0 1
    struct memory_node* next;
} memory_node_t;

typedef struct memory_list
{
    memory_node_t* memory_list_p;
    uint32_t memory_type;
} memory_list_t;

typedef struct memory
{
    memory_list_t memory_list;
    uint32_t memory_size;
    uint32_t memory_count;
} memory_t;

uint32_t Memory_Allocal_Manage_Init(void);
uint32_t Memory_Allocal_Manage_Deinit(void);

#endif