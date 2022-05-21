/*
 * motor.h
 *
 *  Created on: Apr 14, 2022
 *      Author: vienchau
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include <stdint.h>

typedef struct
{
    float dAccelMax;
    float dVelMax;
    float dPosMax;
    float dA1;
    float dA2, dB2;
    float dA3, dB3, dC3;
    float dMidStep1;
    float dMidStep2;
    float dMidStep3;
    float nTime;
} PROFILE_t;

extern void MotorSetDir(int8_t nDir);
extern void MotorSetDuty(uint16_t nDuty);
extern void MotorInit(void);
extern uint16_t ConvertDegToPulse(uint16_t nDeg);
extern uint16_t ConvertPulseToDeg(uint16_t nPulse);
extern void MotorGetPulse(uint32_t *nPulse);
extern void MotorMovePos();
extern void MotorTuning(uint16_t nPos);

#endif /* INC_MOTOR_H_ */
