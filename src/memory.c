#include "memory.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

memory_t memory[TYPE_NUM];


void* Memory_Allocal_Get(type_memory_t type)
{
    memory_node_t* pos = memory[type].memory_list.memory_list_p->next;
    while(pos != NULL)
    {
        if(pos->using_flag == 0)
        {
            pos->using_flag = 1;
            printf("get memory %p\n",pos->addr);
            return pos->addr;
        }
        pos = pos->next;
    }
    printf("memory has no free\n");
    return NULL;
}

uint32_t Memory_Allocal_Release(void** addr)
{
    if(*addr == NULL)
    {
        printf("addr is null\n");
        return 0;
    }

    int32_t list_pos = -1;
    for(int i = 0;i<TYPE_NUM;i++)
    {
        if(*addr <= memory[i].memory_max_addr && *addr >= memory[i].memory_min_addr)
        {
            list_pos = i;
            printf("The addr is in memory %d\n",i);
            break;
        }
    }
    if(list_pos == -1)
    {
        printf("The addr is not in memory\n");
        return 0;
    }
    memory_node_t* pos = memory[list_pos].memory_list.memory_list_p->next;
    while(pos != NULL)
    {
        if(pos->using_flag == 1 && pos->addr == *addr)
        {
            pos->using_flag = 0;
            *addr = NULL;
            printf("find the addr and set null\n");
            return 1;
        }
        else if(pos->using_flag == 0 && pos->addr == *addr)
        {
            printf("find the addr but it is not using\n");
            return 0;
        }
        pos = pos->next;
    }
    printf("can not find the addr\n");
    return 0;
}

uint32_t Memory_Allocal_Manage_Init(void)
{
    {
        memory[0].memory_size = TYPE1_SIZE;
        memory[0].memory_count = TYPE1_COUNT;
        memory[1].memory_size = TYPE2_SIZE;
        memory[1].memory_count = TYPE2_COUNT;
        memory[2].memory_size = TYPE3_SIZE;
        memory[2].memory_count = TYPE3_COUNT;
    }
    for(int i = 0;i<TYPE_NUM;i++)
    {
        memory[i].memory_list.memory_list_p = (memory_node_t *)malloc(sizeof(memory_node_t));
        memory_node_t* pos = memory[i].memory_list.memory_list_p;
        memory[i].memory_min_addr = pos->addr;
        for(int cnt = 0;cnt < memory[i].memory_count;cnt++)
        {
            memory_node_t* node = (memory_node_t *)malloc(sizeof(memory_node_t));
            node->addr = malloc(memory[i].memory_size);
            node->using_flag = 0;
            pos->next = node;
            pos = node;
        }
        memory[i].memory_max_addr = pos->addr;
    }

    // memory_node_t* pos = memory[0].memory_list.memory_list_p->next;
    // int cur = 0;
    // while(pos != NULL)
    // {
    //     printf("pos%d = %p\n",cur,pos->addr);
    //     pos = pos->next;
    //     cur++;
    // }

    return 0;
}

uint32_t Memory_Allocal_Manage_Deinit(void)
{
    for(int i =0;i<TYPE_NUM;i++)
    {
        memory_node_t* pos = memory[i].memory_list.memory_list_p->next;
        int cur = 0;
        while(pos != NULL)
        {
            printf("pos%d = %p\n",cur,pos->addr);
            memory_node_t* temp = pos->next;
            free(pos->addr);
            pos = temp;
            cur++;
        }
    }
    return 0;
}