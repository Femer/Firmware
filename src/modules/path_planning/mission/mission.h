/*
 * kt_cog_list.h
 *
 *  Created on: 25.05.2015
 *      Author: Jonas
 */

#ifndef MISSION_H_
#define MISSION_H_


/* @brief Set the configuration variables */
void mi_set_configuration(float dist, float o1x, float o1y, float rotation);


/* @brief Set the new competition task */
bool mi_set_new_task(uint8_t tasknum);


/* @brief Handler Function for the missions as called by the main-program loop */
bool mi_handler(void);




#endif /* MISSION_H_ */
