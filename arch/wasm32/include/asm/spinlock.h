#ifndef _ASM_WASM32_SPINLOCK_H
#define _ASM_WASM32_SPINLOCK_H

#include <linux/types.h>

typedef struct { } spinlock_t;

#define spin_lock_init(lock)        do { } while (0)
#define spin_lock(lock)             do { } while (0)
#define spin_unlock(lock)           do { } while (0)

typedef struct { } raw_spinlock_t;

#define raw_spin_lock_init(lock)    do { } while (0)
#define raw_spin_lock(lock)         do { } while (0)
#define raw_spin_unlock(lock)       do { } while (0)

#endif /* _ASM_WASM32_SPINLOCK_H */