/* This file contains inserted assert macro statements. It is given to CBMC. */
unsigned int timeElapsed = 0;
int fib  (  int n  )  
{
	int i , Fnew , Fold , temp , ans ;

	timeElapsed = timeElapsed + 35; /* Block num 1*/
	Fnew = 1 ;
	Fold = 0 ;
	for ( i = 2 ; ((timeElapsed = timeElapsed + 7),(i <= 30)) && 
			((timeElapsed = timeElapsed + 11),(i <= n)) ; i ++ )  {   
		{

			timeElapsed = timeElapsed + 40; /* Block num 5*/
			temp = Fnew ;
			Fnew = Fnew + Fold ;
			Fold = temp ;

			//	timeElapsed = timeElapsed + 7; /* Block num 2*/

			//	timeElapsed = timeElapsed + 11; /* Block num 3*/

		}
		timeElapsed = timeElapsed + 1; /* Extra - Direct */
	}  
	timeElapsed = timeElapsed + 27; /* Block num 4*/
	ans = Fnew ;
	return  ans ;

}
int CBMCDriver  (   )  
{
	int a ;
	a = 30 ;
	fib  (  a ) ;
__CPROVER_assume(timeElapsed <= 16383);
assert(timeElapsed <= 12770); 
assert(timeElapsed <= 9158); 
assert(timeElapsed <= 16383); 
assert(timeElapsed <= 5545); 
assert(timeElapsed <= 1933); 
assert(timeElapsed <= 14576); 
assert(timeElapsed <= 10964); 
assert(timeElapsed <= 7351); 
assert(timeElapsed <= 3739); 
assert(timeElapsed <= 127); 	return  0 ;
}

