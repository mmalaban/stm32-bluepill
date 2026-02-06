# STM32 Blue Pill

This is a repo that hosts STM32 Blue pill with Zephyr RTOS.
This project can be used a template project.

## Build command when using Zephyr - West

`west build -b stm32_min_dev`

You may use the pristine flag as well.

`west build -b stm32_min_dev -p always`

## Note

### Zephyr Shell

Keep in mind, Zephyr shell takes up a lot of flash (both shell and console/UART enabled):

| Memory region | Used Size | Region Size | %age Used |
| --- | --- | --- | --- |
| FLASH | 43968 B | 64 KB | 67.09% |
| RAM | 9936 B | 20 KB | 48.52% |
| SRAM0 | 0 GB | 20 KB | 0.00 |
| IDT_LIST | 0 GB | 32 KB | 0.00% |

When Zephyr shell is disabled (both shell and console/UART disabled):

| Memory region | Used Size | Region Size | %age Used |
| --- | --- | --- | --- |
| FLASH | 15864 B | 64 KB | 24.21% |
| RAM | 4768 B | 20 KB | 23.28% |
| SRAM0 | 0 GB | 20 KB | 0.00 |
| IDT_LIST | 0 GB | 32 KB | 0.00% |
