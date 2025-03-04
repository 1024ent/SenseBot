/**
 * @file input_config.h
 * @brief Line Following Mechanism
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

#ifndef __LINE_FOLLOWING_H__
#define __LINE_FOLLOWING_H__

// Speed and Delay Duration Declaration
#define     MID_SPEED           125    
#define     HIGH_SPEED          255    
#define     LOW_SPEED           90
#define     LONG_DELAY_TIME     110 
#define     DELAY_TIME          80 
#define     SHORT_DELAY_TIME    70 
#define     OFFSET_1            0.6
#define     OFFSET_2            0.4

void line_following_std();
void line_following_mecanum();

#endif

