#ifndef _ASM_IRQFLAGS_H
#define _ASM_IRQFLAGS_H

static __always_inline unsigned long arch_local_save_flags(void)
{
    return 0;
}

static __always_inline void native_local_irq_restore(unsigned long flags)
{
}

static __always_inline unsigned long arch_local_irq_save(void)
{
    return 0;
}

static __always_inline void arch_local_irq_restore(unsigned long flags)
{
}

static inline int arch_irqs_disabled(void)
{
    return 0;
}

static inline void arch_local_irq_disable(void)
{
}

static inline void arch_local_irq_enable(void)
{
}

#define raw_local_irq_disable() arch_local_irq_disable()
#define raw_local_irq_enable()  arch_local_irq_enable()

#endif /* _ASM_IRQFLAGS_H */