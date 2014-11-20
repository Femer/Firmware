/****************************************************************************
 *
 *   Copyright (c) 2012, 2013 PX4 Development Team. All rights reserved.
 *   Author: Marco Tranzatto <marco.tranzatto@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/
/**
 * @file path_planning_data.h
 *
 * Store all optimal path planning data.
 *
 * @author Marco Tranzatto <marco.tranzatto@gmail.com>
 */

#ifndef PATH_PLANNING_DATA_H_
#define PATH_PLANNING_DATA_H_

#include <stdio.h>//bool type
//navigation module

#include "navigation.h"

#include "topics_handler.h"

#include "parameters.h"

#include <math.h>

// reference actions for the guidance_module
struct reference_actions_s{
    float alpha_star; ///optimal heading w.r.t. true wind direction
    bool should_tack; ///true if boat should tack as soon as possible
};

/** @brief Initialize the grid lines struct.*/
void init_grids(void);

/** @brief set number of grid lines*/
void set_grids_number(int16_t size);

/** @brief set the x coordinate of a grid line*/
void set_grid(int16_t index, float x_m);

/** @brief based on gps position decide reference actions*/
void path_planning(struct reference_actions_s *ref_act_p,
                   struct structs_topics_s *strs_p,
                   const struct parameters_qgc *params_p);

#endif /* PATH_PLANNING_DATA_H_ */
