/* This file contains inserted assert macro statements. It is given to CBMC. */
unsigned int timeElapsed = 0;
typedef unsigned char bool ;
typedef unsigned int uint32_t ;
typedef uint32_t uint ;
bool divides ( uint n , uint m ) ;
bool even ( uint n ) ;
bool prime ( uint n ) ;
void swap ( uint * a , uint * b ) ;
bool divides ( uint n , uint m )
{
    
    timeElapsed = timeElapsed + 53; /* Block num 1*/
	
    timeElapsed = timeElapsed + 665; /* Block num 1*/
    
    timeElapsed = timeElapsed + 0; /* Block num 2*/
    
    timeElapsed = timeElapsed + 8; /* Block num 3*/
    
    timeElapsed = timeElapsed + 1; /* Block num 4*/

    timeElapsed = timeElapsed + 16; /* Block num 5*/
    /* Multiple basic blocks for this line */
    return  ( m % ( n ) == 0 ) ;

}
bool even ( uint n )
{

	timeElapsed = timeElapsed + 40; /* Block num 1*/

	timeElapsed = timeElapsed + 0; /* Block num 2*/
	/* Multiple basic blocks for this line */
	timeElapsed = timeElapsed + 16; /* Block num 3*/
	return  ( divides ( 2 , n ) ) ;


}
bool prime ( uint n )
{
	uint i ;

	timeElapsed = timeElapsed + 37; /* Block num 1*/

	if ( (timeElapsed = timeElapsed + (0)), /* Block num 2*/ (timeElapsed = timeElapsed + (2)), /* Block num 3*/ /* Multiple basic blocks for this line */
			even ( n ) )

	{
		timeElapsed = timeElapsed + 14; /* Block num 4*/

		timeElapsed = timeElapsed + 1; /* Block num 6*/

		timeElapsed = timeElapsed + 3; /* Block num 7*/
		/* Multiple basic blocks for this line */
		/* Prasad - Even though there is a comparator block, this instru
		 * is ok. The timings for true and false will always be same */
		return  ( n == 2 ) ;

	}
	timeElapsed = timeElapsed + 1; /* Extra - Direct print */
	timeElapsed = timeElapsed + 14; /* Block num 5*/

	for ( i = 3 ; (((timeElapsed = timeElapsed + 24 /* Block num 8*/),(timeElapsed = timeElapsed + 77 /* Block num 10*/),(timeElapsed = timeElapsed + 15), /* Block num 11*/ ( i * i <= n )) && ((timeElapsed = timeElapsed + 14 + 1 /* Block num 12 - plus one for false of 11*/),( i <= 65535 ))) ; (timeElapsed = timeElapsed + 20), /* Block num 20*/ i += 2 ) {
		{
			(timeElapsed = timeElapsed + (24 + 1)); /* Block num 14 plus one true of block num 12*/ 

			if ( (timeElapsed = timeElapsed + (0)), /* Block num 17*/ (timeElapsed = timeElapsed + (2)), /* Block num 18*/  /* Multiple basic blocks for this line */
					divides ( i , n ) )

			{
				timeElapsed = timeElapsed + 3; /* Block num 19*/
				return 0 ;

			}
			timeElapsed = timeElapsed + 1; /* Extra - Direct print */

		}
	}
	timeElapsed = timeElapsed + 1; /* Extra - Direct print */

	timeElapsed = timeElapsed + 1; /* Block num 15*/

	timeElapsed = timeElapsed + 1; /* Block num 16*/

	timeElapsed = timeElapsed + 14; /* Block num 13*/
	timeElapsed = timeElapsed + 15; /* Block num 9*/
	/* Multiple basic blocks for this line */
	return  ( n > 1 ) ;


}
void swap ( uint * a , uint * b )
{
	uint tmp
#ifndef __INPVARS_EXE__
		= * a
#endif
		;
	* a = * b ;
	* b = tmp ;

}
int main (  )
{
	uint x
		;
	uint y
		;
	int i;
	swap ( & x , & y ) ;
	i = ( ! ( prime ( x ) && prime ( y ) )  ) ;
	return i;
}

int CBMCDriver(void)
{
	uint x;
	prime(x);
__CPROVER_assume(timeElapsed <= 9223372036854775807);
assert(timeElapsed <= 72057594037927296); 
assert(timeElapsed <= 1); 
assert(timeElapsed <= 2097151); 
assert(timeElapsed <= 9223372036854703104); 
assert(timeElapsed <= 268435455); 
assert(timeElapsed <= 127); 
assert(timeElapsed <= 4398046511103); 
assert(timeElapsed <= 9223372036854775807); 
assert(timeElapsed <= 562949953421306); 
assert(timeElapsed <= 16383); 
assert(timeElapsed <= 34359738367); 	return 0;
}
