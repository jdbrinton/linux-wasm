# arch/wasm32/Makefile

CORE_ARCHS := wasm32
ARCH := wasm32
KBUILD_DEFCONFIG := wasm32_defconfig

# Compiler and linker settings
CROSS_COMPILE := 
CC := clang
LD := wasm-ld
AS :=

# Compiler flags
CFLAGS += -O0 -target wasm32-hardwarejs -DWASM32_NO_INLINE_ASM

# Linker flags
LDFLAGS += --allow-undefined --no-entry

# Additional build settings
head-y     := arch/wasm32/kernel/entry.o
core-y     += arch/wasm32/

# Ensure that LD is used for linking vmlinux with our flags
LDFLAGS_KERNEL := $(LDFLAGS) -T arch/wasm32/kernel/vmlinux.lds.S
LDFLAGS_vmlinux := $(LDFLAGS) -T arch/wasm32/kernel/vmlinux.lds.S

