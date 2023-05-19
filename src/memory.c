#include "memory.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

memory_t memory[TYPE_NUM];

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
        for(int cnt = 0;cnt < memory[i].memory_count;cnt++)
        {
            memory_node_t* node = (memory_node_t *)malloc(sizeof(memory_node_t));
            node->addr = malloc(memory[i].memory_size);
            node->using_flag = 0;
            pos->next = node;
            pos = node;
        }
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