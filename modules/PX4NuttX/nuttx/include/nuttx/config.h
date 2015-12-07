/* config.h -- Autogenerated! Do not edit. */

#ifndef __INCLUDE_NUTTX_CONFIG_H
#define __INCLUDE_NUTTX_CONFIG_H

/* Architecture-specific options *************************/

#define CONFIG_ARCH "arm"
#define CONFIG_ARCH_ARM 1
#define CONFIG_ARCH_CORTEXM3 1
#define CONFIG_ARCH_CHIP "stm32"
#define CONFIG_ARCH_CHIP_STM32F100C8 1
#define CONFIG_ARCH_BOARD "px4io-v2"
#define CONFIG_ARCH_BOARD_PX4IO_V2 1
#define CONFIG_BOARD_LOOPSPERMSEC 2000
#define CONFIG_DRAM_SIZE 0x00002000
#define CONFIG_DRAM_START 0x20000000
#undef CONFIG_ARCH_INTERRUPTSTACK
#define CONFIG_ARCH_STACKDUMP 1
#undef CONFIG_ARCH_BOOTLOADER
#undef CONFIG_ARCH_LEDS
#undef CONFIG_ARCH_BUTTONS
#undef CONFIG_ARCH_CALIBRATION
#define CONFIG_ARCH_DMA 1
#define CONFIG_ARCH_MATH_H 1
#define CONFIG_ARMV7M_CMNVECTOR 1
#undef CONFIG_ARMV7M_STACKCHECK
#undef CONFIG_STM32_DFU
#undef CONFIG_STM32_JTAG_FULL_ENABLE
#undef CONFIG_STM32_JTAG_NOJNTRST_ENABLE
#define CONFIG_STM32_JTAG_SW_ENABLE 1
#define CONFIG_STM32_DMA1 1
#undef CONFIG_STM32_DMA2
#undef CONFIG_STM32_CRC
#undef CONFIG_STM32_TIM2
#undef CONFIG_STM32_TIM3
#undef CONFIG_STM32_TIM4
#undef CONFIG_STM32_TIM5
#undef CONFIG_STM32_TIM6
#undef CONFIG_STM32_TIM7
#undef CONFIG_STM32_WWDG
#undef CONFIG_STM32_SPI2
#define CONFIG_STM32_USART2 1
#define CONFIG_STM32_USART3 1
#undef CONFIG_STM32_I2C1
#undef CONFIG_STM32_I2C2
#undef CONFIG_STM32_BKP
#undef CONFIG_STM32_PWR
#undef CONFIG_STM32_DAC
#define CONFIG_STM32_ADC1 1
#undef CONFIG_STM32_ADC2
#undef CONFIG_STM32_TIM1
#undef CONFIG_STM32_SPI1
#undef CONFIG_STM32_TIM8
#define CONFIG_STM32_USART1 1
#undef CONFIG_STM32_ADC3
#define CONFIG_SERIAL_TERMIOS 1
#define CONFIG_STANDARD_SERIAL 1
#define CONFIG_USART1_SERIAL_CONSOLE 1
#undef CONFIG_USART2_SERIAL_CONSOLE
#undef CONFIG_USART3_SERIAL_CONSOLE
#define CONFIG_USART1_TXBUFSIZE 64
#define CONFIG_USART2_TXBUFSIZE 64
#define CONFIG_USART3_TXBUFSIZE 64
#define CONFIG_USART1_RXBUFSIZE 64
#define CONFIG_USART2_RXBUFSIZE 64
#define CONFIG_USART3_RXBUFSIZE 64
#define CONFIG_USART1_BAUD 115200
#define CONFIG_USART2_BAUD 115200
#define CONFIG_USART3_BAUD 115200
#define CONFIG_USART1_BITS 8
#define CONFIG_USART2_BITS 8
#define CONFIG_USART3_BITS 8
#define CONFIG_USART1_PARITY 0
#define CONFIG_USART2_PARITY 0
#define CONFIG_USART3_PARITY 0
#define CONFIG_USART1_2STOP 0
#define CONFIG_USART2_2STOP 0
#define CONFIG_USART3_2STOP 0
#define CONFIG_USART1_RXDMA 1
#define SERIAL_HAVE_CONSOLE_DMA 1
#undef CONFIG_USART2_RXDMA
#define CONFIG_USART3_RXDMA 1
#define CONFIG_HRT_TIMER 1
#define CONFIG_HRT_PPM 1
#undef CONFIG_RRLOAD_BINARY
#undef CONFIG_INTELHEX_BINARY
#undef CONFIG_MOTOROLA_SREC
#define CONFIG_RAW_BINARY 1
#undef CONFIG_HAVE_LIBM
#define CONFIG_USER_ENTRYPOINT user_start
#undef CONFIG_DEBUG
#undef CONFIG_DEBUG_VERBOSE
#define CONFIG_DEBUG_SYMBOLS 1
#undef CONFIG_DEBUG_FS
#undef CONFIG_DEBUG_GRAPHICS
#undef CONFIG_DEBUG_LCD
#undef CONFIG_DEBUG_USB
#undef CONFIG_DEBUG_NET
#undef CONFIG_DEBUG_RTC
#undef CONFIG_DEBUG_ANALOG
#undef CONFIG_DEBUG_PWM
#undef CONFIG_DEBUG_CAN
#undef CONFIG_DEBUG_I2C
#undef CONFIG_DEBUG_INPUT
#define CONFIG_MSEC_PER_TICK 1
#define CONFIG_HAVE_CXX 1
#define CONFIG_HAVE_CXXINITIALIZE 1
#define CONFIG_MM_REGIONS 1
#define CONFIG_MM_SMALL 1
#define CONFIG_ARCH_LOWPUTC 1
#define CONFIG_RR_INTERVAL 0
#undef CONFIG_SCHED_INSTRUMENTATION
#define CONFIG_TASK_NAME_SIZE 8
#define CONFIG_START_YEAR 1970
#define CONFIG_START_MONTH 1
#define CONFIG_START_DAY 1
#undef CONFIG_GREGORIAN_TIME
#undef CONFIG_JULIAN_TIME
#define CONFIG_DEV_CONSOLE 1
#undef CONFIG_DEV_LOWCONSOLE
#undef CONFIG_MUTEX_TYPES
#undef CONFIG_PRIORITY_INHERITANCE
#define CONFIG_SEM_PREALLOCHOLDERS 0
#define CONFIG_SEM_NNESTPRIO 0
#define CONFIG_FDCLONE_DISABLE 1
#define CONFIG_FDCLONE_STDIO 1
#define CONFIG_SDCLONE_DISABLE 1
#undef CONFIG_SCHED_WORKQUEUE
#define CONFIG_SCHED_WORKPRIORITY 50
#define CONFIG_SCHED_WORKPERIOD 50000
#define CONFIG_SCHED_WORKSTACKSIZE 1024
#define CONFIG_SIG_SIGWORK 4
#undef CONFIG_SCHED_WAITPID
#undef CONFIG_SCHED_ATEXIT
#undef CONFIG_DISABLE_CLOCK
#define CONFIG_DISABLE_POSIX_TIMERS 1
#define CONFIG_DISABLE_PTHREAD 1
#define CONFIG_DISABLE_SIGNALS 1
#define CONFIG_DISABLE_MQUEUE 1
#define CONFIG_DISABLE_MOUNTPOINT 1
#define CONFIG_DISABLE_ENVIRON 1
#define CONFIG_DISABLE_POLL 1
#undef CONFIG_NOPRINTF_FIELDWIDTH
#undef CONFIG_ARCH_MEMCPY
#undef CONFIG_ARCH_MEMCMP
#undef CONFIG_ARCH_MEMMOVE
#undef CONFIG_ARCH_MEMSET
#undef CONFIG_ARCH_STRCMP
#undef CONFIG_ARCH_STRCPY
#undef CONFIG_ARCH_STRNCPY
#undef CONFIG_ARCH_STRLEN
#undef CONFIG_ARCH_STRNLEN
#undef CONFIG_ARCH_BZERO
#define CONFIG_MAX_TASKS 4
#define CONFIG_MAX_TASK_ARGS 4
#define CONFIG_NPTHREAD_KEYS 2
#define CONFIG_NFILE_DESCRIPTORS 8
#define CONFIG_NFILE_STREAMS 0
#define CONFIG_NAME_MAX 12
#define CONFIG_STDIO_BUFFER_SIZE 32
#undef CONFIG_STDIO_LINEBUFFER
#define CONFIG_NUNGET_CHARS 2
#define CONFIG_PREALLOC_MQ_MSGS 4
#define CONFIG_MQ_MAXMSGSIZE 32
#define CONFIG_MAX_WDOGPARMS 2
#define CONFIG_PREALLOC_WDOGS 4
#define CONFIG_PREALLOC_TIMERS 0
#undef CONFIG_NSH_CONSOLE
#undef CONFIG_BOOT_RUNFROMFLASH
#undef CONFIG_BOOT_COPYTORAM
#undef CONFIG_CUSTOM_STACK
#undef CONFIG_STACK_POINTER
#define CONFIG_IDLETHREAD_STACKSIZE 1024
#define CONFIG_USERMAIN_STACKSIZE 1200
#define CONFIG_PTHREAD_STACK_MIN 512
#define CONFIG_PTHREAD_STACK_DEFAULT 1024
#undef CONFIG_HEAP_BASE
#undef CONFIG_HEAP_SIZE
#define CONFIG_APPS_DIR "../apps"

/* Sanity Checks *****************************************/

/* If this is an NXFLAT, external build, then make sure that
 * NXFLAT support is enabled in the base code.
 */

#if defined(__NXFLAT__) && !defined(CONFIG_NXFLAT)
# error "NXFLAT support not enabled in this configuration"
#endif

/* NXFLAT requires PIC support in the TCBs. */

#if defined(CONFIG_NXFLAT)
# undef CONFIG_PIC
# define CONFIG_PIC 1
#endif

/* Binary format support is disabled if no binary formats are
 * configured (at present, NXFLAT is the only supported binary.
 * format).
 */

#if !defined(CONFIG_NXFLAT) && !defined(CONFIG_ELF) && !defined(CONFIG_BUILTIN)
# undef CONFIG_BINFMT_DISABLE
# define CONFIG_BINFMT_DISABLE 1
#endif

/* The correct way to disable RR scheduling is to set the
 * timeslice to zero.
 */

#ifndef CONFIG_RR_INTERVAL
# define CONFIG_RR_INTERVAL 0
#endif

/* The correct way to disable filesystem supuport is to set the number of
 * file descriptors to zero.
 */

#ifndef CONFIG_NFILE_DESCRIPTORS
# define CONFIG_NFILE_DESCRIPTORS 0
#endif

/* If a console is selected, then make sure that there are resources for
 * three file descriptors and, if any streams are selected, also for three
 * file streams.
 *
 * CONFIG_DEV_CONSOLE means that a builtin console device exists at /dev/console
 * and can be opened during boot-up.  Other consoles, such as USB consoles, may
 * not exist at boot-upand have to be handled in a different way.  Three file
 * descriptors and three file streams are still needed.
 */

#if defined(CONFIG_DEV_CONSOLE) || defined(CONFIG_CDCACM_CONSOLE) || \
    defined(CONFIG_PL2303_CONSOLE)
# if CONFIG_NFILE_DESCRIPTORS < 3
#   undef CONFIG_NFILE_DESCRIPTORS
#   define CONFIG_NFILE_DESCRIPTORS 3
# endif

# if CONFIG_NFILE_STREAMS > 0 && CONFIG_NFILE_STREAMS < 3
#  undef CONFIG_NFILE_STREAMS
#  define CONFIG_NFILE_STREAMS 3
# endif

/* If no console is selected, then disable all builtin console devices */

#else
#  undef CONFIG_DEV_LOWCONSOLE
#  undef CONFIG_RAMLOG_CONSOLE
#endif

/* If priority inheritance is disabled, then do not allocate any
 * associated resources.
 */

#if !defined(CONFIG_PRIORITY_INHERITANCE) || !defined(CONFIG_SEM_PREALLOCHOLDERS)
# undef CONFIG_SEM_PREALLOCHOLDERS
# define CONFIG_SEM_PREALLOCHOLDERS 0
#endif

#if !defined(CONFIG_PRIORITY_INHERITANCE) || !defined(CONFIG_SEM_NNESTPRIO)
# undef CONFIG_SEM_NNESTPRIO
# define CONFIG_SEM_NNESTPRIO 0
#endif

/* If no file descriptors are configured, then make certain no
 * streams are configured either.
 */

#if CONFIG_NFILE_DESCRIPTORS == 0
# undef CONFIG_NFILE_STREAMS
# define CONFIG_NFILE_STREAMS 0
#endif

/* There must be at least one memory region. */

#ifndef CONFIG_MM_REGIONS
# define CONFIG_MM_REGIONS 1
#endif

/* If the end of RAM is not specified then it is assumed to be the beginning
 * of RAM plus the RAM size.
 */

#ifndef CONFIG_DRAM_END
# define CONFIG_DRAM_END (CONFIG_DRAM_START+CONFIG_DRAM_SIZE)
#endif

/* If no file streams are configured, then make certain that buffered I/O
 * support is disabled
 */

#if CONFIG_NFILE_STREAMS == 0
# undef CONFIG_STDIO_BUFFER_SIZE
# define CONFIG_STDIO_BUFFER_SIZE 0
#endif

/* If no standard C buffered I/O is not supported, then line-oriented buffering
 * cannot be supported.
 */

#if CONFIG_STDIO_BUFFER_SIZE == 0
# undef CONFIG_STDIO_LINEBUFFER
#endif

/* If the maximum message size is zero, then we assume that message queues
 * support should be disabled
 */

#if CONFIG_MQ_MAXMSGSIZE <= 0 && !defined(CONFIG_DISABLE_MQUEUE)
# define CONFIG_DISABLE_MQUEUE 1
#endif

/* If mountpoint support in not included, then no filesystem can be supported */

#ifdef CONFIG_DISABLE_MOUNTPOINT
# undef CONFIG_FS_FAT
# undef CONFIG_FS_ROMFS
# undef CONFIG_FS_NXFFS
# undef CONFIG_FS_SMARTFS
# undef CONFIG_FS_BINFS
# undef CONFIG_NFS
#endif

/* Check if any readable and writable filesystem (OR USB storage) is supported */

#undef CONFIG_FS_READABLE
#undef CONFIG_FS_WRITABLE
#if defined(CONFIG_FS_FAT) || defined(CONFIG_FS_ROMFS) || defined(CONFIG_USBMSC) || \
    defined(CONFIG_FS_NXFFS) || defined(CONFIG_FS_SMARTFS) || defined(CONFIG_FS_BINFS) || \
    defined(CONFIG_NFS)
# define CONFIG_FS_READABLE 1
#endif

#if defined(CONFIG_FS_FAT) || defined(CONFIG_USBMSC) || defined(CONFIG_FS_NXFFS) || \
    defined(CONFIG_NFS)
# define CONFIG_FS_WRITABLE 1
#endif

/* There can be no network support with no socket descriptors */

#if CONFIG_NSOCKET_DESCRIPTORS <= 0
# undef CONFIG_NET
#endif

/* Conversely, if there is no network support, there is no need for
 * socket descriptors
 */

#ifndef CONFIG_NET
# undef CONFIG_NSOCKET_DESCRIPTORS
# define CONFIG_NSOCKET_DESCRIPTORS 0
#endif

/* Protocol support can only be provided on top of basic network support */

#ifndef CONFIG_NET
# undef CONFIG_NET_TCP
# undef CONFIG_NET_UDP
# undef CONFIG_NET_ICMP
#endif

/* NFS client can only be provided on top of UDP network support */

#if !defined(CONFIG_NET) || !defined(CONFIG_NET_UDP)
# undef CONFIG_NFS
#endif

/* Verbose debug and sub-system debug only make sense if debug is enabled */

#ifndef CONFIG_DEBUG
# undef CONFIG_DEBUG_VERBOSE
# undef CONFIG_DEBUG_SCHED
# undef CONFIG_DEBUG_MM
# undef CONFIG_DEBUG_PAGING
# undef CONFIG_DEBUG_DMA
# undef CONFIG_DEBUG_FS
# undef CONFIG_DEBUG_LIB
# undef CONFIG_DEBUG_BINFMT
# undef CONFIG_DEBUG_NET
# undef CONFIG_DEBUG_USB
# undef CONFIG_DEBUG_GRAPHICS
# undef CONFIG_DEBUG_GPIO
# undef CONFIG_DEBUG_SPI
# undef CONFIG_DEBUG_STACK
#endif

/* User entry point. This is provided as a fall-back to keep compatibility
 * with existing code, for builds which do not define CONFIG_USER_ENTRYPOINT.
 */

#ifndef CONFIG_USER_ENTRYPOINT
# define CONFIG_USER_ENTRYPOINT user_start
#endif

#endif /* __INCLUDE_NUTTX_CONFIG_H */