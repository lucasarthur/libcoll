/*
 * Copyright (c) 2023 Lucas Arthur
 *
 * This file is part of libcoll, an open-source library whose goal is to
 * provide easy to use collections in C.
 *
 * libcoll is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libcoll is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libcoll. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef char* string;

typedef void (*consumer_t)(void*);
typedef bool (*predicate_t)(void*);
typedef void* (*function_t)(void*);
typedef i8 (*comparator_t)(void*, void*);
typedef void* (*supplier_t)(void);
typedef void (*runnable_t)(void);
