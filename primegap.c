#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

unsigned long primeGap(const mpz_t a, const mpz_t b)
{
	int ans;
	mpz_t back,max,next,temp;
	mpz_init(back);
	mpz_init(temp);
	mpz_init(max);
	mpz_init(next);

	if (mpz_probab_prime_p(a,15) == 0)
	{
		mpz_nextprime(back,a);
	}
	mpz_nextprime(next,back);

	while (mpz_cmp(next,b) <=0)
	{
		mpz_sub(temp,next,back);
		if (mpz_cmp(temp,max) > 0)
		{
			mpz_set(max,temp);
		}
		mpz_set(back,next);
		mpz_nextprime(next,next);
	}
ans = mpz_get_ui(max);
return ans;
}

/*Output for ./primegap 2 1000000000:
Largest prime gap in [2, 1000000000] is 282
computed in 7.1e+02 seconds*/
