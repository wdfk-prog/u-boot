// SPDX-License-Identifier: GPL-2.0-or-later OR BSD-3-Clause
/*
 * Copyright (C) 2022, STMicroelectronics - All Rights Reserved
 */

 #include <config.h>
 #include <debug_uart.h>
 #include <asm/io.h>
 #include <asm/arch/stm32.h>
 #include <linux/bitops.h>
 
 #define STM32_UART4_BASE 0x40004c00
 #define STM32_RCC_BASE  0x58024400
 #define RCC_APB1LENR (STM32_RCC_BASE + 0x00E8)
 #define RCC_AHB4ENR (STM32_RCC_BASE + 0x00E0)
 #define GPIOA_BASE 0x58020000 
 
 void board_debug_uart_init(void)
 {
	 if (CONFIG_DEBUG_UART_BASE == STM32_UART4_BASE) {
		 /* UART4 clock enable */
		 setbits_le32(RCC_APB1LENR, BIT(19));
 
		 /* GPIOG clock enable */
		 writel(BIT(0), RCC_AHB4ENR);
		 /* GPIO configuration for boards: Uart4 TX = A0 */
		 writel(0xABFFFFFF, GPIOA_BASE + 0x00);
		 writel(0x00000008, GPIOA_BASE + 0x20);
	 }
 }
 