#include <linux/delay.h> 
#include <linux/interrupt.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 
 
/* DECLARE_TASKLET_OLD present for compatibility. 
 */ 
#ifndef DECLARE_TASKLET_OLD 
#define DECLARE_TASKLET_OLD(arg1, arg2) DECLARE_TASKLET(arg1, arg2, 0L) 
#endif 
 
/*
The tasklet callback is executed in an atomic context inside a program interrupt
*/

static void tasklet_fn(unsigned long data) 
{ 
    pr_info("Example tasklet starts\n"); 
    mdelay(5000); 
    pr_info("Example tasklet ends\n"); 
} 
 
static DECLARE_TASKLET_OLD(mytask, tasklet_fn); 
 
/*Callback runs in atomic context, inside a software interrupt,
*/

static int example_tasklet_init(void) 
{ 
    pr_info("tasklet example init\n"); 
    tasklet_schedule(&mytask); 
    mdelay(200); 
    pr_info("Example tasklet init continues...\n"); 
    return 0; 
} 
 
/* Also, multiple different tasklet callbacks can run in parallel.
*/

static void example_tasklet_exit(void) 
{ 
    pr_info("tasklet example exit\n"); 
    tasklet_kill(&mytask); 
} 
 
module_init(example_tasklet_init); 
module_exit(example_tasklet_exit); 
 
MODULE_DESCRIPTION("Tasklet example"); 
MODULE_LICENSE("GPL");

