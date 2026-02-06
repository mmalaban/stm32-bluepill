#include <zephyr/kernel.h>
#include <zephyr/drivers/can.h>

#include "messages.h"

#define CAN_BITRATE 500000

static const struct device *const can_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_canbus));

int messages_init(void)
{
	int ret;

	if (!device_is_ready(can_dev)) {
		printk("Error: CAN device not ready\n");
		return -ENODEV;
	}

	ret = can_set_bitrate(can_dev, CAN_BITRATE);
	if (ret < 0) {
		printk("Error: failed to set CAN bitrate (%d)\n", ret);
		return ret;
	}

	ret = can_start(can_dev);
	if (ret < 0) {
		printk("Error: failed to start CAN controller (%d)\n", ret);
		return ret;
	}

	printk("CAN bus initialized at %d bps\n", CAN_BITRATE);
	return 0;
}
