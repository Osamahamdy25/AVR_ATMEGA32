 /******************************************************************************
 *
 * Module: Bit Utils
 *
 * File Name: Bit_utils.h
 *
 * Description: Commonly used Macros
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/


#ifndef _BIT_UTILS_H
#define _BIT_UTILS_H

#define REG_SIZE   8
#if REG_SIZE == 8

	#define BIT_SET_MASK      0xFF
	#define BIT_RESET_MASK    0x00
	#define SET_H_NIB_MASK    0xF0
	#define SET_L_NIB_MASK    0x0F
	#define RESET_H_NIB_MASK  0x0F
	#define RESET_L_NIB_MASK  0xF0

#elif REG_SIZE == 16
	#define BIT_SET_MASK      0xFFFF
	#define BIT_RESET_MASK    0x0000
	#define SET_H_NIB_MASK    0xFF00
	#define SET_L_NIB_MASK    0x00FF
	#define RESET_H_NIB_MASK  0x00FF
	#define RESET_L_NIB_MASK  0xFF00
#endif

#define SET_BIT(Reg,Bit)        (Reg)|=(1<<Bit)
#define CLR_BIT(Reg,Bit)        (Reg)&=~(1<<Bit)
#define GET_BIT(Reg,Bit)        ((Reg)>>Bit)&1
#define TGL_BIT(Reg,Bit)        (Reg)^=(1<<Bit)
#define RSHFT_REG(Reg,n)        (Reg)>>=n
#define LSHFT_REG(Reg,n)        (Reg)<<=n
#define CRSHFT_REG(Reg,n)       (Reg)=((Reg<<n)|(Reg>>(8*sizeof(Reg)-n)))
#define CLSHFT_REG(Reg,n)       (Reg)=((Reg>>n)|(Reg<<(8*sizeof(Reg)-n)))
#define ASSIGN_REG(Reg,Val)     (Reg)=Val
#define SET_REG(Reg)            (Reg)=~(0)
#define CLR_REG(Reg)            (Reg)=0
#define TGL_REG(Reg)            (Reg)^=~(0)
#define SET_H_NIP(Reg)          (Reg)|=0XF0
#define SET_L_NIP(Reg)          (Reg)|=0x0F
#define CLR_H_NIP(Reg)          (Reg)&=0x0F
#define CLR_L_NIP(Reg)          (Reg)&=~(0xF0)
#define GET_H_NIP(Reg)          (Reg)& (0xF0)
#define GET_L_NIP(Reg)          (Reg) & (0x0F)
#define ASSIGN_H_NIP(Reg,Val)   (Reg)=((Reg&0x0F)|(value<<4))
#define ASSIGN_L_NIP(Reg,Val)   (Reg)=((Reg&0xF0)|(value))
#define TGL_H_NIP(Reg)          (Reg)^=(0xF0)
#define TGL_L_NIP(Reg)          (Reg)^=(0X0F)
#define SWAP_NIP(Reg)           (Reg)=(reg>>4)|(reg<<4)

#endif
