/*
 * This file is part of the coreboot project.
 *
 * Copyright 2018 Google LLC
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 */

#include <baseboard/gpio.h>
#include <baseboard/variants.h>
#include <boardid.h>
#include <gpio.h>
#include <soc/gpio.h>

static const struct pad_config default_override_table[] = {
	PAD_NC(GPIO_50, UP_20K), /* PCH_I2C_PEN_SDA -- unused */
	PAD_NC(GPIO_51, UP_20K), /* PCH_I2C_PEN_SCL -- unused */
	PAD_NC(GPIO_52, UP_20K), /* PCH_I2C_P_SENSOR_SDA -- unused */
	PAD_NC(GPIO_53, UP_20K), /* PCH_I2C_P_SENSOR_SCL -- unused */

	PAD_NC(GPIO_67, UP_20K), /* EN_PP3300_DX_LTE_SOC -- unused */

	PAD_NC(GPIO_105, DN_20K), /* TOUCHSCREEN_RST -- unused */
	PAD_NC(GPIO_108, NONE), /* PMU_SUSCLK -- unused */

	PAD_NC(GPIO_114, DN_20K), /* I2C7 Touchscreen -- unused */
	PAD_NC(GPIO_115, DN_20K), /* I2C7 Touchscreen -- unused */

	PAD_NC(GPIO_117, UP_20K), /* PCIE_WAKE1_B - No LTE*/
	PAD_NC(GPIO_119, UP_20K), /* PCIE_WAKE3_B - only use CNVI */

	/* PCIE_CLKREQ3_B -- unused */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_122, UP_20K, DEEP, NF1, HIZCRx1, ENPU),
	/* CAM_SOC_EC_SYNC */
	PAD_CFG_GPI_APIC_IOS(GPIO_134, NONE, DEEP, EDGE_SINGLE, INVERT, TxDRxE,
			     DISPUPD),

	PAD_NC(GPIO_138, UP_20K), /* PEN_PDCT_ODL -- unused */
	PAD_NC(GPIO_139, UP_20K), /* PEN_INT_ODL -- unused */
	PAD_NC(GPIO_140, UP_20K), /* PEN_RESET -- unused */

	PAD_NC(GPIO_143, UP_20K), /* LTE_SAR_ODL -- unused */
	PAD_NC(GPIO_144, UP_20K), /* PEN_EJECT(wake) -- unused */
	PAD_NC(GPIO_145, UP_20K), /* PEN_EJECT(notification) -- unused */

	PAD_NC(GPIO_161, UP_20K), /* LTE_OFF_ODL -- unused */
	PAD_NC(GPIO_164, UP_20K), /* WLAN_PE_RST -- unused */

	PAD_NC(GPIO_212, UP_20K), /* TOUCHSCREEN_INT_ODL -- unused */
	PAD_NC(GPIO_213, UP_20K), /* EN_PP3300_TOUCHSCREEN -- unused */
	PAD_NC(GPIO_214, UP_20K), /* P_SENSOR_INT_L -- unused */
};

const struct pad_config *variant_override_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(default_override_table);
	return default_override_table;
}
