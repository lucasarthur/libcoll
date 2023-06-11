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
#include <types.h>

i8 i8cmp(void* a, void* b);
i8 i16cmp(void* a, void* b);
i8 i32cmp(void* a, void* b);
i8 i64cmp(void* a, void* b);
i8 u8cmp(void* a, void* b);
i8 u16cmp(void* a, void* b);
i8 u32cmp(void* a, void* b);
i8 u64cmp(void* a, void* b);
i8 f32cmp(void* a, void* b);
i8 f64cmp(void* a, void* b);
i8 scmp(void* a, void* b);
i8 bcmp(void* a, void* b);
i8 ccmp(void* a, void* b);
