
#define CPU_CACHE_LINE_BSIZE 32
#define CPU_DCACHE_SIZE 16*1024
#define VM_EXEC 4

	.globl arm926_flush_cache_all

/* Flush D-Cache and I-Cache
 *
 *	arm926_flush_cache_all()
 *
 */
arm926_flush_cache_all:
	mov		r2, #VM_EXEC
	mov		ip, #0
__flush_whole_cache:
#ifdef CONFIG_DCACHE_WRITETHROUGH
	mcr		p15, 0, ip, c7, c6, 0		@ invalidate D cache
#else
1:	mrc		p15, 0, r15, c7, c14, 3 	@ test,clean,invalidate
	bne		1b
#endif
	tst		r2, #VM_EXEC
	mcrne	p15, 0, ip, c7, c5, 0		@ invalidate I cache
	mcrne	p15, 0, ip, c7, c10, 4		@ drain WB
	mov		pc, lr


	.globl arm926_flush_icache_all

/* Flush I-Cache
 *
 *	arm926_flush_icache_all()
 *
 */
arm926_flush_icache_all:
	mov		ip, #0
	mcrne	p15, 0, ip, c7, c5, 0		@ invalidate I cache
	mov		pc, lr
