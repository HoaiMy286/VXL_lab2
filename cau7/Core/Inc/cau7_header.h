/*
 * cau7_header.h
 *
 *  Created on: Oct 24, 2022
 *      Author: ASUS
 */

#ifndef INC_CAU7_HEADER_H_
#define INC_CAU7_HEADER_H_

extern int timer0_flag;
extern int timer1_flag;

void setTimer1(int duration);
void setTimer0(int duration);

void timer_run();

#endif /* INC_CAU7_HEADER_H_ */
