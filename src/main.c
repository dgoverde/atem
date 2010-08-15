#include "util.h"
#include "util.cpp"

#include <stdio.h>
#include <string.h>
#include <limits.h>



extern int
rudi_printf_fp ( char * ccc, void *args );


int compare2()
{
	float f_start = 0.0000001f;
	unsigned int start = *( (unsigned int*)  &(f_start));
	unsigned int end = INT_MAX;
	unsigned int i;
	for( i = start; i <= end; i +=1 ) {
		char s1[512];
		char s2[512];
		
		double f = *( (float*) (&i) );
		f = +f;
		
// 		int l = ftoa( f, s1 );
		rudi_printf_fp( s1, &f);
// 		sprintf( s1, "%.5f", f );
		sprintf( s2, "%.6g", f );
		
		if( strcmp(s1, s2/*, l - 1*/) ) {
			fprintf( stdout, "error(%d): %.18g  %s != %s\n", (i - start), f, s1, s2 );
// 			return 1;
		}
		if( (i % 10000000) == 0 ) {
			fprintf( stdout, "%s, %s\n", s1, s2 );
		}
	}
	return 0;
}







// int compare1()
// {
// 	long start = 9999999999;
// 	long count = INT_MAX;	
// 	long end = start + count;
// 	
// 	for( long i = start; i<end; i++ ) {
// 		char s1[32];
// 		char s2[32];
// 		
// 		itoa( i, s1 );
// 		sprintf( s2, "%ld", i );
// 		
// 		if( strcmp(s1, s2) ) {
// 			fprintf( stdout, "error: %s != %s\n", s1, s2 );
// 			return 1;
// 		}
// 		if( i % 0xfffff == 0) {
// 			fprintf( stdout, "%lX, %s\n", i, s1 );
// 		}
// 	}
// 	return 0;
// }



int main(int argc, char *argv[])
{
	return compare2();
// 	double  f = 1121212212.12;
// 	char ccc[512];
// 	rudi_printf_fp( ccc, &f);
// 	fprintf( stdout, "HUHU %s \n", ccc );
}