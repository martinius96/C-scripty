/* 2020-07-18, MD: Demo kod pre vypocet NTT
 * Number Theoretic Transform
 * based on
 * recursive implementation of Cooley-Tukey algorithm with 2-radix DFT
 */

#include "ntt.h"
#include "gf.h"


// vypocet suctu v konecnom poli (GF- Galois Field)
ff ff_add(ff a, ff b) {
     return (ff) ((a+b) % MODULE);
}

// vypocet odcitania v GF
ff ff_sub(ff a, ff b) {
     return (ff) ((a+(MODULE-b)) % MODULE);
}

// vypocet nasobenia v GF
ff ff_mul(ff a, ff b) {
     return (ff) ((a*b) % MODULE);
}

// tabulky moznin omega a inv_omega pouzite vo vypocte
static ff omega_table[MAX_NTT_SIZE];
static ff inv_omega_table[MAX_NTT_SIZE];

// inicializacia vyssie uvedenych tabuliek
int ntt_table_init( ff omega, uint16_t N, int inverse ) {
int k;
ff t=1;

    if (N > MAX_NTT_SIZE)
        return -1;
    for(k=0; k<N; k++) {   
        if(inverse)
            inv_omega_table[k] = t;   // t= (inv_omega^k) mod MODULE
        else
            omega_table[k] = t;       // t=(omega^k mod MODULE)
        t = ff_mul(t,omega);
    }
    if (t!=1)
        return -1;
    else
        return 0;
}

// algoritmus NTT a NTT^-1 vypoctu ekvivalentny DFT a DFT^-1 algoritmu. Zlozitost je O(N^2)
// (vznikol jednoduchou upravou refernecneho kodu DFT a DFT^-1 vypoctu, vid povodne komentare) 
void ntt_slow(ff* x, ff* X, uint16_t N, int inverse) {
uint16_t n, k;
ff tmp;

    for (k = 0; k < N; k++)   // musi vzdy zacinat s vynulovanym !!!
        X[k] = 0;

    // Iterate through, allowing X_K = sum_N of the complex frequencies.
    for (k = 0; k < N; k++) {
        for (n = 0; n < N; n++) {
//          X[k] += x[n] * cexp(-2 * PI * I * n * k / N);
            if( inverse)
                tmp = ff_mul(x[n], inv_omega_table[(n*k) % N]);
            else
                tmp = ff_mul(x[n], omega_table[(n*k) % N]);
            X[k] = ff_add(X[k], tmp);
        }
    }
    if( inverse ) {
        for (k = 0; k < N; k++) {
            X[k] = ff_mul(X[k], INV_NTT_SIZE);
        }
    }
}


// rychly algoritmus vypoctu NTT a NTT^-1 s vyuzitim rekurzivnej implementacie
// (vznikol jednoduchou upravou referencnej implementacie FFT, 
// pozri napr. 
// https://rosettacode.org/wiki/Fast_Fourier_transform#C
//
// alternativou by bolo upravit implementaciu FFT pre in_place vypocet, toto 
// ale pre zachovanie jednoduchosti kodu nebolo v tomto kode vyuzite

static void ntt_radix2(ff* x, ff* X, uint16_t N, uint16_t s, int inverse) {
uint16_t k;
ff t, tmp;

    // At the lowest level pass through (delta T=0 means no phase).
    if (N == 1) {
        X[0] = x[0];
        return;
    }

    // Cooley-Tukey: recursively split in two, then combine beneath.
    ntt_radix2(x, X, N/2, 2*s, inverse);
    ntt_radix2(x+s, X + N/2, N/2, 2*s, inverse);

    for (k = 0; k < N/2; k++) {
        t = X[k];
//      X[k] = t + cexp(-2 * PI * I * k / N) * X[k + N/2];
            if( inverse )
                tmp = ff_mul( X[k + N/2], inv_omega_table[k*s] );
        else
                tmp = ff_mul( X[k + N/2], omega_table[k*s] );
        X[k] = ff_add(t,tmp);
//      X[k + N/2] = t - cexp(-2 * PI * I * k / N) * X[k + N/2];
        X[k + N/2] = ff_sub(t,tmp);
    }
}

void ntt(ff* x, ff* X, uint16_t N, int inverse) {
uint16_t k;

    ntt_radix2(x, X, N, 1, inverse);
        if( inverse ) {
            for (k = 0; k < N; k++) {
                X[k] = ff_mul(X[k], INV_NTT_SIZE);
            }
        }
}


