#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/sys_io.h>
#include <zephyr/devicetree.h>
#include <errno.h>

static int pinmux_cornix_init(void) {
#if (CONFIG_BOARD_CORNIX_LEFT || CONFIG_BOARD_CORNIX_RIGHT)
    const struct device *p0 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
    int err;

    if (!device_is_ready(p0)) {
        return -ENODEV;
    }

#if CONFIG_BOARD_CORNIX_CHARGER
    err = gpio_pin_configure(p0, 5, GPIO_OUTPUT_INACTIVE);
#else
    err = gpio_pin_configure(p0, 5, GPIO_INPUT);
#endif
    if (err) {
        return err;
    }
#endif
    return 0;
}

SYS_INIT(pinmux_cornix_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
