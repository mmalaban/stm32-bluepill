# STM32 BluePill Zephyr Project

## Target
- MCU: STM32F103C8T6 (BluePill)
- Board config: `stm32_min_dev`
- RTOS: Zephyr

## Environment
- Zephyr toolchain runs in Docker (no git in container)
- `BUILD_VERSION` is set statically in CMakeLists.txt

## Build Commands
```bash
west build -b stm32_min_dev -p always
west flash
```

## Code Conventions
- Tasks should be preemptable threads (positive priority value), not while loops in main
- Use `K_THREAD_DEFINE` for static thread creation
- `main()` should end with `while (1) { k_sleep(K_FOREVER); }`
- Use devicetree aliases (e.g., `led0`) for hardware access

## Project Structure
```
stm32-bluepill/
├── CMakeLists.txt   # Zephyr build config, BUILD_VERSION defined here
├── prj.conf         # Kconfig options (shell, GPIO, binary name, etc.)
├── src/
│   └── main.c       # Application entry + task definitions
└── readme.md        # Project description
```

## Features Enabled
- Zephyr shell (UART)
- GPIO (for LED heartbeat)
- Console/serial output
