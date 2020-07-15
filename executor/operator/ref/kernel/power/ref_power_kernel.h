/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * License); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * AS IS BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Copyright (c) 2019, Open AI Lab
 * Author: bingzhang@openailab.com
 */

#ifndef __REF_POWER_KERNEL_H__
#define __REF_POWER _KERNEL_H__

#include <stdint.h>
#include <math.h>
#include "compiler_fp16.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ref_power_param
{
    float q_scale[2];
    int zero_point[2];
    float shift;
    float scale;
    float power;
    int iDataN;
    int iDataH;
    int iDataW;
    int iDataC;
};


typedef int (*ref_power_t)(void* in_data, void* data,ref_power_param* param);

#ifdef CONFIG_KERNEL_FP32
#include "ref_power_fp32.c"
#endif

#ifdef CONFIG_KERNEL_FP16
#include "ref_power_fp16.c"
#endif

#ifdef CONFIG_KERNEL_INT8
#include "ref_power_int8.c"
#endif

#ifdef CONFIG_KERNEL_UINT8
#include "ref_power_uint8.c"
#endif

#ifdef __cplusplus
}
#endif

#endif