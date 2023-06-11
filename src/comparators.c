#include <comparators.h>
#include <string.h>
#include <math.h>

i8 i8cmp(void* a, void* b) {
  i8 va = *(i8*)a;
  i8 vb = *(i8*)b;

  if (va < vb) return -1;
  if (va == vb) return 0;
  return 1;
}

i8 i16cmp(void* a, void* b) {
  i16 va = *(i16*)a;
  i16 vb = *(i16*)b;

  if (va < vb) return -1;
  if (va == vb) return 0;
  return 1;
}

i8 i32cmp(void* a, void* b) {
  i32 va = *(i32*)a;
  i32 vb = *(i32*)b;

  if (va < vb) return -1;
  if (va == vb) return 0;
  return 1;
}

i8 i64cmp(void* a, void* b) {
  i64 va = *(i64*)a;
  i64 vb = *(i64*)b;

  if (va < vb) return -1;
  if (va == vb) return 0;
  return 1;
}

i8 u8cmp(void* a, void* b) {
  u8 va = *(u8*)a;
  u8 vb = *(u8*)b;

  if (va < vb) return -1;
  if (va == vb) return 0;
  return 1;
}

i8 u16cmp(void* a, void* b) {
  u16 va = *(u16*)a;
  u16 vb = *(u16*)b;

  if (va < vb) return -1;
  if (va == vb) return 0;
  return 1;
}

i8 u32cmp(void* a, void* b) {
  u32 va = *(u32*)a;
  u32 vb = *(u32*)b;

  if (va < vb) return -1;
  if (va == vb) return 0;
  return 1;
}

i8 u64cmp(void* a, void* b) {
  u64 va = *(u64*)a;
  u64 vb = *(u64*)b;

  if (va < vb) return -1;
  if (va == vb) return 0;
  return 1;
}

i8 f32cmp(void* a, void* b) {
  f32 diff = *(f32*)a - *(f32*)b;

  if (fabs(diff) < 1e-6) return 0;
  if (diff < 0) return -1;
  return 1;
}

i8 f64cmp(void* a, void* b) {
  f64 diff = *(f64*)a - *(f64*)b;

  if (fabs(diff) < 1e-6) return 0;
  if (diff < 0) return -1;
  return 1;
}

i8 scmp(void* a, void* b) {
  return strcmp((string)a, (string)b);
}

i8 bcmp(void* a, void* b) {
  return *(bool*)a - *(bool*)b;
}

i8 ccmp(void* a, void* b) {
  return *(char*)a - *(char*)b;
}
