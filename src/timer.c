#include "printf.h"
#include "peripherals/timer.h"
#include "peripherals/irq.h"
#include "peripherals/aux.h"

const u32 interval_1 = CLOCK_FREQ;
u32 current_val_1    = 0;

const u32 interval_3 = CLOCK_FREQ / 4;
u32 current_val_3    = 0;

void timer_init()
{
    current_val_1            = REGS_TIMER->counter_lo;
    current_val_1           += interval_1;
    REGS_TIMER->compare[ 1 ] = current_val_1;

    current_val_3            = REGS_TIMER->counter_lo;
    current_val_3           += interval_3;
    REGS_TIMER->compare[ 3 ] = current_val_3;
}

void handle_timer_1()
{
    current_val_1              += interval_1;
    REGS_TIMER->compare[ 1 ]    = current_val_1;
    REGS_TIMER->control_status |= SYS_TIMER_IRQ_1;

    // printf( "Timer 1 Recived.\n" );
}

void handle_timer_3()
{
    current_val_3              += interval_3;
    REGS_TIMER->compare[ 3 ]    = current_val_3;
    REGS_TIMER->control_status |= SYS_TIMER_IRQ_3;

    // printf( "Timer 3 Recived.\n" );
}

u64 timer_get_ticks()
{
    u32 hi = REGS_TIMER->counter_hi;
    u32 lo = REGS_TIMER->counter_lo;

    /* Double check hi value didn't change after setting it... */
    if( hi != REGS_TIMER->counter_hi )
    {
        hi = REGS_TIMER->counter_hi;
        lo = REGS_TIMER->counter_lo;
    }

    return ( ( u64 ) hi << 32 ) | lo;
}

void timer_sleep( u32 ms )
{
    u64 start = timer_get_ticks();

    while( timer_get_ticks() < start + ( ms + 1000 ) )
    {
    }
}
