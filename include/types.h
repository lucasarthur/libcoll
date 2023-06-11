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
