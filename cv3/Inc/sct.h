/*
 * sct.h
 *
 *  Created on: Oct 12, 2022
 *      Author: xsedla1m
 */

#ifndef SCT_H_
#define SCT_H_

#define sct_nla(x) do { if (x) GPIOB->BSRR = (1 << 5); else GPIOB->BRR = (1 << 5); } while (0)


#endif /* SCT_H_ */
