/* This file contains inserted assert macro statements. It is given to CBMC. */
unsigned int timeElapsed = 0;
typedef unsigned char uchar ;
unsigned char lin [ 256 ]
#ifndef __INPVARS_EXE__
= "asdffeagewaHAFEFaeDsFEawFdsFaefaeerdjgp"
#endif
;
#ifdef CBMC
#define EXTRA_INSTRUCTION /* nada */
#else
#define EXTRA_INSTRUCTION asm("nop")
#endif
#define TINC(X) (timeElapsed = timeElapsed + (X); EXTRA_INSTRUCTION;)
unsigned short icrc1 ( unsigned short crc , unsigned char onech )
{
	int i ;
	unsigned short ans
#ifndef __INPVARS_EXE__
		=  ( crc ^ onech << 8 )
#endif
		;
	TINC( 42); /* Block num 1*/
	for ( i = 0 ; (TINC( (8)), /* Block num 2*/ i < 8 ); TINC(10), /* Block num 7*/ i ++ ) {
		{
			if ( (timeElapsed = timeElapsed + (6)), /* Block num 3*/ (ans & 0x8000) )
			{
				TINC( 24); /* Block num 5*/
				ans = ( ans <<= 1 ) ^ 4129 ;
			}
			else
			{
				TINC( 1); /* Extra - Direct print */
				TINC( 10); /* Block num 6*/
				ans <<= 1 ;
			}
		}
	}
	TINC(- 1); /* Extra - Direct print */
	TINC( 19); /* Block num 4*/
	return ans ;
}

unsigned short icrc ( unsigned short crc , unsigned long len , short jinit , int jrev )
{
	unsigned short icrc1 ( unsigned short crc , unsigned char onech ) ;
	static unsigned short icrctb [ 256 ] , init
#ifndef __INPVARS_EXE__
		= 0
#endif
		;
	static uchar rchr [ 256 ] ;
	unsigned short tmp1 , tmp2 , j , cword
#ifndef __INPVARS_EXE__
		= crc
#endif
		;
	static uchar it [ 16 ]
#ifndef __INPVARS_EXE__
		=
		{
			0 , 8 , 4 , 12 , 2 , 10 , 6 , 14 , 1 , 9 , 5 , 13 , 3 , 11 , 7 , 15
		}
#endif
	;
	TINC( 52); /* Block num 1*/
	if ( /* Multiple basic blocks for this line */
			! init )
	{
		(TINC( (1))); /* Extra - Direct print */
		TINC( 12); /* Block num 3*/
		init = 1 ;

		for ( j = 0 ; (TINC( 7+2), (j <= 255) ); /*(timeElapsed = timeElapsed + 1),  Block num 8*/ j ++ ) {
			{
				TINC( 0); /* Block num 12*/
				TINC( 70); /* Block num 14*/
				/* Multiple basic blocks for this line */
				icrctb [ j ] = icrc1 ( j << 8 , ( uchar ) 0 ) ;
				rchr [ j ] = ( uchar )  ( it [ j & 0xF ] << 4 | it [ j >> 4 ] ) ;
				(TINC( (13))); /* Block num 9*/
			}
		}
		//		TINC( 1); /* Extra - Direct print */
		//		icrc_glbVarsForExtra[2]++;		- Not needed
	}
	else{
		(TINC( (2))); /* Block num 2*/
	}
	if ( (timeElapsed = timeElapsed + (6)), /* Block num 4*/ /* Multiple basic blocks for this line */
			jinit >= 0 )
	{
		(TINC( (18))); /* Block num 6*/
		/* Multiple basic blocks for this line */
		cword = (  ( uchar ) jinit ) | (  (  ( uchar ) jinit ) << 8 ) ;
	}
	else
	{
		TINC( 1); /* Extra - Direct print */
		if ( (timeElapsed = timeElapsed + (6)), /* Block num 7 plus one for block num 8*/ jrev < 0 )
		{
			TINC( 34); /* Block num 11*/
			cword = rchr [ (  ( uchar )  (  ( cword ) >> 8 )  ) ] | rchr [ (  ( uchar )  (  ( cword ) & 0xFF )  ) ] << 8 ;
		}
		else
		{
			TINC( 1); /* Extra - Direct print */
		}
	}
	TINC( 8); /* Block num 10*/
	for ( j = 1 ; (TINC( (20)), /* Block num 13*/ j <= len ); (timeElapsed = timeElapsed + 8), /* Block num 15*/ j ++ ) {
		{
			TINC( 35); /* Block num 21*/
			if ( jrev < 0 )
			{
				TINC( 31); /* Block num 17*/
				tmp1 = rchr [ lin [ j ] ] ^ (  ( uchar )  (  ( cword ) >> 8 )  ) ;
			}
			else
			{
				TINC( 1); /* Extra - Direct print */
				{
					TINC( 22); /* Block num 18*/
					tmp1 = lin [ j ] ^ (  ( uchar )  (  ( cword ) >> 8 )  ) ;
				}
			} cword = icrctb [ tmp1 ] ^ (  ( uchar )  (  ( cword ) & 0xFF )  ) << 8 ;
		}
	}
	TINC( 1); /* Extra - Direct print */
	if ( (timeElapsed = timeElapsed + (6)), /* Block num 16*/ jrev >= 0 )
	{
		TINC( 10); /* Block num 19*/
		tmp2 = cword ;
	}
	else
	{
		TINC( 1); /* Extra - Direct print */
		{
			TINC( 34); /* Block num 20*/
			tmp2 = rchr [ (  ( uchar )  (  ( cword ) >> 8 )  ) ] | rchr [ (  ( uchar )  (  ( cword ) & 0xFF )  ) ] << 8 ;
		}
	}
	TINC( 23); /* Block num 22*/
	return  ( tmp2 ) ;
}

int CBMCDriver ()
{
	unsigned short nondet_ushort();
	unsigned long nondet_ulong();
	int nondet_int();
	short nondet_short();
	unsigned short i1 , i2 ;
	unsigned long n ;
	short jinit;
	int jrev;
	n = 40;
	lin [ n + 1 ] = 0 ;
	i1 =  nondet_ushort();
	jinit = nondet_short();
	jrev = nondet_int();
	icrc ( i1 , n+2 , jinit , jrev ) ;
	###WCET_TEST###
	return 0;
}
