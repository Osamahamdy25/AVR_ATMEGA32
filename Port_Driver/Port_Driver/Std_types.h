 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: Std_types.h
 *
 * Description: types for AVR
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/



#ifndef _STD_TYPES_H
#define _STD_TYPES_H
/*      Unsigned Data Type                       */
typedef unsigned char u8;
typedef unsigned char* pu8;
typedef unsigned short int u16;
typedef unsigned short int* pu16;
typedef unsigned int u32;
typedef unsigned int* pu32;
typedef unsigned long long int u64;
typedef unsigned long long int* pu64;
/*       Signed  Data Type                         */
typedef signed char s8;
typedef signed char* ps8;
typedef signed short int s16;
typedef signed short int* ps16;
typedef signed int s32;
typedef signed int* ps32;
typedef signed long long int s64;
typedef signed long long int* s64;
/*       Floating Data Type                              */
typedef float f32;
typedef float* pf32;
typedef double f64;
typedef double* pf64;
typedef long double f128;
typedef long double* pf128;
#endif
