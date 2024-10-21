#ifndef _ASM_WASM32_IO_H
#define _ASM_WASM32_IO_H

#define PCI_IOBASE 0  // No PCI in WASM

/* Define IO_SPACE_LIMIT for wasm32 architecture */
#define IO_SPACE_LIMIT 0

// Stub out IO operations
static inline void __raw_writeb(u8 value, volatile void __iomem *addr) {}
static inline void __raw_writew(u16 value, volatile void __iomem *addr) {}
static inline void __raw_writel(u32 value, volatile void __iomem *addr) {}
static inline void readsb(volatile void __iomem *addr, void *buffer, int count) {}
static inline void readsw(volatile void __iomem *addr, void *buffer, int count) {}
static inline void readsl(volatile void __iomem *addr, void *buffer, int count) {}
static inline void writesb(volatile void __iomem *addr, const void *buffer, int count) {}
static inline void writesw(volatile void __iomem *addr, const void *buffer, int count) {}
static inline void writesl(volatile void __iomem *addr, const void *buffer, int count) {}

static inline void writel(u32 value, volatile void __iomem *addr) {}
static inline u32 readl(volatile void __iomem *addr) { return 0; }

#include <linux/types.h>
#include <linux/ioport.h>

static inline void __iomem *ioremap(phys_addr_t addr, size_t size)
{
    return NULL;
}

static inline void __iomem *ioremap_nocache(phys_addr_t addr, size_t size)
{
    return NULL;
}

static inline void __iomem *ioremap_wc(phys_addr_t addr, size_t size)
{
    return NULL;
}

static inline void __iomem *ioremap_wt(phys_addr_t addr, size_t size)
{
    return NULL;
}

static inline void iounmap(void __iomem *addr)
{
    /* No operation needed */
}


#endif /* _ASM_WASM32_IO_H */
