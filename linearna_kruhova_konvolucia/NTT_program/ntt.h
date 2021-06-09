/* 2020-07-18, MD: Demo kod pre vypocet NTT
 * Number Theoretic Transform
 * based on
 * recursive implementation of Cooley-Tukey algorithm with 2-radix DFT
 */

#ifndef __NTT_H__
#define __NTT_H__

#include <stdint.h>

#define DIRECT          0
#define INVERSE         !DIRECT

#define MAX_NTT_SIZE    1024            // maximalny rozmer NTT, ktory moze byt pri vypocte pouzity

typedef uint32_t        ff;             // Finite Field element

extern ff ff_mul(ff a, ff b);
extern ff ff_add(ff a, ff b);
extern ff ff_sub(ff a, ff b);
 
extern int ntt_table_init( ff omega, uint16_t N, int inverse );
extern void ntt_slow(ff* x, ff* X, uint16_t N, int inverse);
extern void ntt(ff* x, ff* X, uint16_t N, int inverse);


#endif /* _ntt */
