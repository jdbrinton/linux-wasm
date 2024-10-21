#ifndef _ASM_CMPXCHG_H
#define _ASM_CMPXCHG_H

#define arch_xchg(ptr, new_value) ({ \
	typeof(*(ptr)) __old = *(ptr); \
	*(ptr) = (new_value); \
	__old; \
})

#define arch_cmpxchg(ptr, old_value, new_value) ({ \
	typeof(*(ptr)) __old = *(ptr); \
	if (__old == (old_value)) \
		*(ptr) = (new_value); \
	__old; \
})

#define arch_cmpxchg64(ptr, old_value, new_value) ({ \
	typeof(*(ptr)) __old = *(ptr); \
	if (__old == (old_value)) \
		*(ptr) = (new_value); \
	__old; \
})

#define arch_cmpxchg_local(ptr, old_value, new_value) \
	arch_cmpxchg((ptr), (old_value), (new_value))

#define arch_cmpxchg64_local(ptr, old_value, new_value) \
	arch_cmpxchg64((ptr), (old_value), (new_value))

#define arch_xchg_local(ptr, new_value) \
	arch_xchg((ptr), (new_value))

#define arch_try_cmpxchg(ptr, oldp, new_value) ({ \
	bool __result; \
	typeof(*(ptr)) __old = *(ptr); \
	if (__old == *(oldp)) { \
		*(ptr) = (new_value); \
		__result = true; \
	} else { \
		*(oldp) = __old; \
		__result = false; \
	} \
	__result; \
})

#define arch_try_cmpxchg64(ptr, oldp, new_value) ({ \
	bool __result; \
	typeof(*(ptr)) __old = *(ptr); \
	if (__old == *(oldp)) { \
		*(ptr) = (new_value); \
		__result = true; \
	} else { \
		*(oldp) = __old; \
		__result = false; \
	} \
	__result; \
})

#define arch_try_cmpxchg_local(ptr, oldp, new_value) \
	arch_try_cmpxchg((ptr), (oldp), (new_value))

#define arch_try_cmpxchg64_local(ptr, oldp, new_value) \
	arch_try_cmpxchg64((ptr), (oldp), (new_value))

#define arch_sync_cmpxchg(ptr, old_value, new_value) \
	arch_cmpxchg((ptr), (old_value), (new_value))

#define arch_sync_try_cmpxchg(ptr, oldp, new_value) \
	arch_try_cmpxchg((ptr), (oldp), (new_value))

#define arch_try_cmpxchg_acquire(ptr, oldp, newval) \
({ \
	bool __result; \
	typeof(*(ptr)) __old = *(ptr); \
	if (__old == *(oldp)) { \
		*(ptr) = (newval); \
		__result = true; \
	} else { \
		*(oldp) = __old; \
		__result = false; \
	} \
	__result; \
})

#define arch_try_cmpxchg_release(ptr, oldp, newval) \
({ \
	bool __result; \
	typeof(*(ptr)) __old = *(ptr); \
	if (__old == *(oldp)) { \
		*(ptr) = (newval); \
		__result = true; \
	} else { \
		*(oldp) = __old; \
		__result = false; \
	} \
	__result; \
})

#endif /* _ASM_CMPXCHG_H */