/* Test file for mpfr_ai.

Copyright 2010 Free Software Foundation, Inc.
Contributed by the Arenaire and Cacao projects, INRIA.

This file is part of the GNU MPFR Library.

The GNU MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MPFR Library; see the file COPYING.LESSER.  If not, see
http://www.gnu.org/licenses/ or write to the Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "mpfr-test.h"

#define TEST_FUNCTION mpfr_ai
#define TEST_RANDOM_EMIN -5
#define TEST_RANDOM_EMAX 5
#include "tgeneric.c"

static void
check_large (void)
{
  mpfr_t x, y, z;

  mpfr_init2 (x, 38);
  mpfr_init2 (y, 110);
  mpfr_init2 (z, 110);
  mpfr_set_str_binary (x, "-1E8");
  mpfr_ai (y, x, MPFR_RNDN);
  mpfr_set_str_binary (z, "-10001110100001011111110001100011101100011100010000110100100101011111011100000101110101010010000000101110011111E-112");
  if (mpfr_cmp (y, z) != 0)
    {
      printf ("Error in mpfr_ai for x=-2^8\n");
      exit (1);
    }
  mpfr_set_str_binary (x, "-1E26");
  mpfr_ai (y, x, MPFR_RNDN);
  mpfr_set_str_binary (z, "-110001111100000011001010010101001101001011001011101011001010100100001110001101101101000010000011001000001011E-118");
  if (mpfr_cmp (y, z) != 0)
    {
      printf ("Error in mpfr_ai for x=-2^26\n");
      exit (1);
    }
  mpfr_set_str_binary (x, "-0.11111111111111111111111111111111111111E1073741823");
  mpfr_ai (y, x, MPFR_RNDN);
  /* FIXME: compute the correctly rounded value we should get for Ai(x),
     and check we get this value */
  mpfr_clear (x);
  mpfr_clear (y);
  mpfr_clear (z);
}

int
main (int argc, char *argv[])
{
  tests_start_mpfr ();

  check_large ();

  test_generic (2, 100, 100);

  tests_end_mpfr ();
  return 0;
}