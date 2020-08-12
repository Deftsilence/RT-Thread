
/* RT-Thread内核头文件 */
#include <rthw.h>
#include <rtthread.h>


/* 硬件配置头文件*/
#include "board.h" 


#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
#define RT_HEAP_SIZE 1024
/* RT-Thread堆配置-4KB */
static uint32_t rt_heap[RT_HEAP_SIZE];
RT_WEAK void *rt_heap_begin_get(void)
{
    return rt_heap;
}

RT_WEAK void *rt_heap_end_get(void)
{
    return rt_heap + RT_HEAP_SIZE;
}
#endif

/**
  * @brief  硬件初始化
  * @param  无
  * @retval 无
  *
  * @attention
  * RTT�ѿ�������صĳ�ʼ������ͳһ�ŵ�board.c�ļ���ʵ�֣�
  * ��Ȼ���������Щ����ͳһ�ŵ�main.c�ļ�Ҳ�ǿ��Եġ�
  */
void rt_hw_board_init()
{
  /* 系统定时器初始化 */
  SysTick_Config( SystemCoreClock / RT_TICK_PER_SECOND );	
    
  /* 硬件相关的初始化全部放在此处 */

  /* LED初始化 */
  LED_GPIO_Config();
    

/* 调用组件初始化函数 (use INIT_BOARD_EXPORT()) */
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif
/*控制台设置函数*/    
#if defined(RT_USING_CONSOLE) && defined(RT_USING_DEVICE)
	rt_console_set_device(RT_CONSOLE_DEVICE_NAME);
#endif
/* 内存初始化函数 */    
#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
    rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get());
#endif
}

/**
  * @brief  SysTick中断服务函数
  * @param  无
  * @retval 无
  *
  * @attention
  */
void SysTick_Handler(void)
{
    /* 进入中断 */
    rt_interrupt_enter();

    /* 更新时基 */
    rt_tick_increase();

    /* 退出中断 */
    rt_interrupt_leave();
}



