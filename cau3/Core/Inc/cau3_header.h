/*
 * cau3_header.h
 *
 *  Created on: Oct 4, 2022
 *      Author: ASUS
 */

#ifndef INC_CAU3_HEADER_H_
#define INC_CAU3_HEADER_H_

extern int timer1_flag;
extern int timer2_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void timeRun();

#endif /* INC_CAU3_HEADER_H_ */
