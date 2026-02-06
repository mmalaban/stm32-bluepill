# STM32 BluePill Zephyr Project

## Target
- MCU: STM32F103C8T6 (BluePill)
- Board config: `stm32_min_dev`
- RTOS: Zephyr

## Environment
- Zephyr toolchain runs in Docker — Claude cannot run builds directly; ask the user to build and report results
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
├── prj.conf         # Kconfig options (shell, GPIO, CAN, binary name, etc.)
├── boards/
│   └── stm32_min_dev.overlay  # DTS overlay (LED alias, CAN enable)
├── src/
│   ├── main.c       # Application entry + task definitions
│   ├── messages.c   # CAN bus init and messaging interface
│   └── messages.h   # Public API for messages module
└── readme.md        # Project description
```

## Features Enabled
- Zephyr shell (UART)
- GPIO (for LED heartbeat)
- CAN bus (500 kbps via Zephyr native bxCAN driver)
- Console/serial output
