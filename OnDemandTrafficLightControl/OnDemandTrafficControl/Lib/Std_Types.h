/*
 * Std_Types.h
 *
 *  Created on: Dec 30, 2022
 *      Author: Esraa Abdelnaby
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#undef NULL
#define NULL (void *)(0)
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;

typedef float f32;
typedef double f64;

typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long long int s64;

typedef unsigned char* pu8;
typedef unsigned short int* pu16;
typedef unsigned int* pu32;
typedef unsigned long long int* pu64;

typedef float* pf32;
typedef double* pf64;

typedef signed char* ps8;
typedef signed short int* ps16;
typedef signed int* ps32;
typedef signed long long int* ps64;

/*defining a pointer to function */
typedef void (*pfCallBackFunc) (void);

#endif /* STD_TYPES_H_ */
