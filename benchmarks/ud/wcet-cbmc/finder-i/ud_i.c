/* This file contains inserted assert macro statements. It is given to CBMC. */
unsigned int timeElapsed = 0;
long int a [ 50 ] [ 50 ] , b [ 50 ] , x [ 50 ] ;
int ludcmp  (  int nmax , int n  )  ;
void main  (   )  
{
	int i , j , nmax 
#ifndef __INPVARS_EXE__
		=  50 
#endif
		, n 
#ifndef __INPVARS_EXE__
		=  5
#endif
		, chkerr ;
	long int w ;

	for ( i = 0 ; i <= n ; i ++ )  {  
		{
			w = 0.0 ;
			for ( j = 0 ; j <= n ; j ++ )  {  
				{
					a [ i ] [ j ] =  (  i + 1  )  +  (  j + 1  )  ;

					if ( i == j )

					{  a [ i ] [ j ] *= 2.0 ;

					}  w += a [ i ] [ j ] ;

				}
			}  b [ i ] = w ;

		}
	}  chkerr = ludcmp  (  nmax , n ) ;

}
void CBMCDriver1  (   )  
{
    unsigned int timeElapsedBefore = timeElapsed;
	long int nondet_long();
	int i , j , nmax =  50 , n =  5 , chkerr ;
	long int w ;

	for ( i = 0 ; i <= n ; i ++ )  {  
		{
			w = 0.0 ;
			for ( j = 0 ; j <= n ; j ++ )  {  
				{
					a [ i ] [ j ] = nondet_long();


					 w += a [ i ] [ j ] ;

				}
			}
		      	b [ i ] = w ;
		}
	}
      	ludcmp  (  nmax , n ) ;

__CPROVER_assume(timeElapsed > timeElapsedBefore);
__CPROVER_assume( (timeElapsed - timeElapsedBefore) <= 9223372036854775807);
assert( (timeElapsed - timeElapsedBefore) <= 1); 
assert( (timeElapsed - timeElapsedBefore) <= 127); 
assert( (timeElapsed - timeElapsedBefore) <= 16383); 
assert( (timeElapsed - timeElapsedBefore) <= 2097151); 
assert( (timeElapsed - timeElapsedBefore) <= 268435455); 
assert( (timeElapsed - timeElapsedBefore) <= 34359738367); 
assert( (timeElapsed - timeElapsedBefore) <= 4398046511103); 
assert( (timeElapsed - timeElapsedBefore) <= 562949953421306); 
assert( (timeElapsed - timeElapsedBefore) <= 72057594037927296); 
assert( (timeElapsed - timeElapsedBefore) <= 9223372036854703104); 
assert( (timeElapsed - timeElapsedBefore) <= 9223372036854775807); 
}

int ludcmp  (  int nmax , int n  )  
{
	int i , j , k ;
	long w , y [ 100 ] ;

	timeElapsed = timeElapsed + 43; /* Block num 1*/
	for ( i = 0 ; (timeElapsed = timeElapsed + (15)), /* Block num 2*/ i < n ; (timeElapsed = timeElapsed + 14), /* Block num 3*/  i ++ )  {  
		{
			(timeElapsed = timeElapsed + 10); /* Block num 19*/

			for ( j = i + 1 ; (timeElapsed = timeElapsed + (15)), /* Block num 5*/ j <= n ; (timeElapsed = timeElapsed + 50), /* Block num 7*/ j ++ )  {  
				{
					w = a [ j ] [ i ] ;

					timeElapsed = timeElapsed + 45; /* Block num 28*/

					if ( (timeElapsed = timeElapsed + (2)), /* Block num 11*/ /* Multiple basic blocks for this line */ 
							i != 0 )

					{   
						timeElapsed = timeElapsed + 6; /* Block num 12 */

						for ( k = 0 ; (timeElapsed = timeElapsed + (11)), /* Block num 17*/ k < i ; (timeElapsed = timeElapsed + 36), /* Block num 35*/ k ++ )  {  
							timeElapsed = timeElapsed + 76; /* Block num 24*/

							timeElapsed = timeElapsed + 82; /* Block num 29*/
							/* Multiple basic blocks for this line */ 
							w -= a [ j ] [ k ] * a [ k ] [ i ] ;
						}  
						timeElapsed = timeElapsed + 1;  /* Extra - Direct print */

					}  
					timeElapsed = timeElapsed + 1;  /* Extra - Direct print */

					timeElapsed = timeElapsed + 39; /* Block num 16*/

					timeElapsed = timeElapsed + 737; /* Block num 23*/
					/* Multiple basic blocks for this line */ 
					a [ j ] [ i ] = w / ( a [ i ] [ i ] ) ;


				}
			}  
			timeElapsed = timeElapsed + 1;  /* Extra - Direct print */
			timeElapsed = timeElapsed + 12; /* Block num 8*/
			for ( j = i + 1 ; (timeElapsed = timeElapsed + (15)), /* Block num 13*/ j <= n ; (timeElapsed = timeElapsed + 51), /* Block num 18*/ j ++ )  {  
				{
					w = a [ i + 1 ] [ j ] ;

					timeElapsed = timeElapsed + 54; /* Block num 31*/

					for ( k = 0 ; (timeElapsed = timeElapsed + (11)), /* Block num 25*/ k <= i ; (timeElapsed = timeElapsed + 78), /* Block num 30*/ k ++ )  {  
						timeElapsed = timeElapsed + 36; /* Block num 38*/

						timeElapsed = timeElapsed + 82; /* Block num 36*/
						/* Multiple basic blocks for this line */ 
						w -= a [ i + 1 ] [ k ] * a [ k ] [ j ] ;
					}  
					timeElapsed = timeElapsed + 1;  /* Extra - Direct print */
					a [ i + 1 ] [ j ] = w ;

				}
			}  
			timeElapsed = timeElapsed + 1;  /* Extra - Direct print */

		}
	}  
	timeElapsed = timeElapsed + 1;  /* Extra - Direct print */

	timeElapsed = timeElapsed + 24; /* Block num 4*/
	y [ 0 ] = b [ 0 ] ;
	for ( i = 1 ; (timeElapsed = timeElapsed + (15)), /* Block num 6*/ i <= n ; (timeElapsed = timeElapsed + 43), /* Block num 21*/ i ++ )  {  
		{

			timeElapsed = timeElapsed + 35; /* Block num 9*/
			w = b [ i ] ;
			for ( j = 0 ; (timeElapsed = timeElapsed + (11)), /* Block num 14*/ j < i ; (timeElapsed = timeElapsed + 36), /* Block num 32*/ j ++ )  {  
				timeElapsed = timeElapsed + 67; /* Block num 20*/

				timeElapsed = timeElapsed + 82; /* Block num 26*/
				/* Multiple basic blocks for this line */ 
				w -= a [ i ] [ j ] * y [ j ] ;
			}  
			timeElapsed = timeElapsed + 1;  /* Extra - Direct print */
			y [ i ] = w ;

		}
	}  
	timeElapsed = timeElapsed + 1;  /* Extra - Direct print */

	timeElapsed = timeElapsed + 41; /* Block num 22*/

	timeElapsed = timeElapsed + 63; /* Block num 10*/

	timeElapsed = timeElapsed + 737; /* Block num 15*/
	/* Multiple basic blocks for this line */ 
	x [ n ] = y [ n ] / ( a [ n ] [ n ] ) ;
	for ( i = n - 1 ; (timeElapsed = timeElapsed + (6)), /* Block num 27*/ i >= 0 ; (timeElapsed = timeElapsed + 31), /* Block num 44*/ i -- )  {  
		{

			timeElapsed = timeElapsed + 46; /* Block num 33*/
			w = y [ i ] ;
			for ( j = i + 1 ; (timeElapsed = timeElapsed + (15)), /* Block num 37*/ j <= n ; (timeElapsed = timeElapsed + 36), /* Block num 43*/ j ++ )  {  
				timeElapsed = timeElapsed + 62; /* Block num 39*/

				timeElapsed = timeElapsed + 82; /* Block num 41*/
				/* Multiple basic blocks for this line */ 
				w -= a [ i ] [ j ] * x [ j ] ;
			}  
			timeElapsed = timeElapsed + 1;  /* Extra - Direct print */

			timeElapsed = timeElapsed + 39; /* Block num 40*/

			timeElapsed = timeElapsed + 737; /* Block num 42*/
			/* Multiple basic blocks for this line */ 
			x [ i ] = w / ( a [ i ] [ i ] ) ;

		}
	}  
	timeElapsed = timeElapsed + 1;  /* Extra - Direct print */

	timeElapsed = timeElapsed + 25; /* Block num 34*/
	return   (  0  )  ;

}