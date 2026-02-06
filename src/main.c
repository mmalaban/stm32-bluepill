#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#include "messages.h"

#define HEARTBEAT_INTERVAL_MS 250
#define HEARTBEAT_STACK_SIZE  512
#define HEARTBEAT_PRIORITY    7  /* Preemptable priority (positive value) */

/* Onboard LED - uses the "on_board_led" alias from the DTS overlay */
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_ALIAS(on_board_led), gpios);

static void heartbeat_task(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p1);
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);

	while (1) {
		gpio_pin_toggle_dt(&led);
		k_msleep(HEARTBEAT_INTERVAL_MS);
	}
}

K_THREAD_DEFINE(heartbeat_tid, HEARTBEAT_STACK_SIZE,
		heartbeat_task, NULL, NULL, NULL,
		HEARTBEAT_PRIORITY, 0, 0);

int main(void)
{
	int ret;

	if (!gpio_is_ready_dt(&led)) {
		printk("Error: LED device not ready\n");
		return -1;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		printk("Error: Failed to configure LED pin\n");
		return -1;
	}

	printk("Heartbeat task started (250ms interval)\n");

	ret = messages_init();
	if (ret < 0) {
		printk("Warning: CAN init failed (%d)\n", ret);
	}

	while (1) {
		k_sleep(K_FOREVER);
	}

	return 0;
}
