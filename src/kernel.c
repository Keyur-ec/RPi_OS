#include "common.h"
#include "mini_uart.h"
#include "printf.h"
#include "irq.h"
#include "timer.h"
#include "i2c.h"

u32 get_el();

void putc( void *ptr,
           char ch )
{
    if( ch == '\n' )
    {
        uart_send( '\r' );
    }

    uart_send( ch );
}

void kernel_main()
{
    uart_init();
    init_printf( 0, putc );
    printf( "Raspberry Pi Bare Metal OS Initializing...\n" );

    irq_init_vectors();
    enable_interrupt_controller();
    irq_enable();
    timer_init();

#if RPI_VERSION == 3
    printf( "\tBoard : Raspberry Pi 3\n" );
#endif

#if RPI_VERSION == 4
    printf( "\tBoard : Raspberry Pi 4\n" );
#endif

    printf( "\nCurrent Execption Level is : %d\n", get_el() );

    u16 sleep_time = 200;
    printf( "Sleeping for %d ms\n", sleep_time );
    timer_sleep( sleep_time );
    printf( "Sleeping for %d ms\n", sleep_time );
    timer_sleep( sleep_time );
    printf( "Sleeping for %d ms\n", sleep_time );
    timer_sleep( sleep_time );

    sleep_time = 2000;
    printf( "Sleeping for %d s\n", sleep_time / 1000 );
    timer_sleep( sleep_time );
    printf( "Sleeping for %d s\n", sleep_time / 1000 );
    timer_sleep( sleep_time );

    sleep_time = 5000;
    printf( "Sleeping for %d s\n", sleep_time / 1000 );
    timer_sleep( sleep_time );

    /* printf( "Initializing I2C...\n" ); */
    /* i2c_init(); */

    /* for( int i = 0; i < 10; i++ ) */
    /* { */
    /*     char buffer[ 10 ]; */
    /*     i2c_recv( 21, ( u8 * ) buffer, 9 ); */
    /*     buffer[ 9 ] = 0; */
    /*     printf( "Recived %s\n", buffer ); */
    /*     timer_sleep( 250 ); */
    /* } */

    /* for( int i = 0; i < 20; i++ ) */
    /* { */
    /*     i2c_send( 21, ( u8 * ) &i, 1 ); */
    /*     timer_sleep( 250 ); */
    /*     printf( "Send: %d\n", i ); */
    /* } */

    /* const char *msg = "Hello Slave Device"; */
    /* i2c_send( 21, ( u8 * ) msg, 18 ); */

    printf( "\n\nWe'r Done!\n" );

    while( 1 )
    {
        /* uart_send( uart_recv() ); */
    }
}
