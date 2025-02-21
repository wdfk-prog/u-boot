// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2015
 * Kamil Lulko, <kamil.lulko@gmail.com>
 */

#include "acpi/acpi_device.h"
#include <status_led.h>
#include <asm-generic/gpio.h>
#include <stdio.h>

#define BULE_LED	(('I'-'A') * 16 + 8)
#define RED_LED		(('C'-'A') * 16 + 15)

void coloured_LED_init(void)
{
	gpio_request(RED_LED, "led-red");
	gpio_direction_output(RED_LED, 1);
	gpio_request(BULE_LED, "led-bule");
	gpio_direction_output(BULE_LED, 1);
}

void red_led_off(void)
{
	gpio_direction_output(RED_LED, 1);
}

void bule_led_off(void)
{
	gpio_direction_output(BULE_LED, 1);
}

void red_led_on(void)
{
	gpio_direction_output(RED_LED, 0);
}

void bule_led_on(void)
{
	gpio_direction_output(BULE_LED, 0);
}
