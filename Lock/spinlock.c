#include <stdatomic.h>

typedef struct spinlock_t{
    atomic_flag flag;
} spinlock_t;

void spinlock_init(spinlock_t *lock) {
    atomic_flag_clear(&lock->flag);
}

void spinlock_lock(spinlock_t *lock) {
    while (atomic_flag_test_and_set(&lock->flag)) {
        // spin
    }
}

void spinlock_unlock(spinlock_t *lock) {
    atomic_flag_clear(&lock->flag);
}