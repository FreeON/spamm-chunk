/** @file
 *
 * The header file for chunk functions.
 *
 * @author Nicolas Bock <nicolas.bock@freeon.org>
 * @author Matt Challacombe <matt.challacombe@freeon.org>
 */

#ifndef __CHUNK_H
#define __CHUNK_H

#include <stdlib.h>

__BEGIN_DECLS

size_t
chunk_sizeof (const int N_chunk, const int N_basic);

void *
chunk_alloc (const int N_chunk,
    const int N_basic,
    const int N,
    const unsigned int i_lower,
    const unsigned int j_lower);

void
chunk_set (void *const chunk, const double *const A);

int
chunk_get_N_chunk (void *const chunk);

int
chunk_get_N_basic (void *const chunk);

double
chunk_get_norm_2 (const void *const chunk);

void
chunk_print (const void *const chunk,
    const char *const format, ...);

void
chunk_add (const double alpha, void *const A,
    const double beta, const void *const B);

void
chunk_multiply (const double tolerance,
    const void *const A,
    const void *const B,
    void *const C,
    const short symbolic_only);

double
chunk_trace (const void *const chunk);

void
chunk_scale (const double alpha, void *const chunk);

void
chunk_add_identity (const double alpha, void *const chunk);

double *
chunk_to_dense (const void *const chunk);

void
chunk_delete (void **const chunk);

size_t
chunk_get_complexity (const void *const chunk);

__END_DECLS

#endif
