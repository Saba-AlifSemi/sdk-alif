/* Copyright (C) 2026 Alif Semiconductor - All Rights Reserved.
 * Use, distribution and modification of this code is permitted under the
 * terms stated in the Alif Semiconductor Software License Agreement
 *
 * You should have received a copy of the Alif Semiconductor Software
 * License Agreement with this file. If not, please write to:
 * contact@alifsemi.com, or visit: https://alifsemi.com/license
 *
 * SPDX-License-Identifier: LicenseRef-Alif-Proprietary
 */

#include "test_dac.h"

LOG_MODULE_REGISTER(dac_test, LOG_LEVEL_INF);

/* Global device pointer */
const struct device *dac_dev;

/* Default channel configuration: 12-bit, channel 0, unbuffered */
const struct dac_channel_cfg dac_ch_cfg = {
	.channel_id = DAC_CHANNEL_ID,
	.resolution = DAC_RESOLUTION,
	.buffered = 0
};

const struct device *init_dac_device(void)
{
	int ret;
	const struct device *dev = DEVICE_DT_GET(DAC_NODE);

	zassert_not_null(dev, "DAC device handle is NULL");
	zassert_true(device_is_ready(dev), "DAC device is not ready");

	ret = dac_channel_setup(dev, &dac_ch_cfg);
	zassert_equal(ret, 0, "DAC channel setup failed [%d]", ret);

	return dev;
}
