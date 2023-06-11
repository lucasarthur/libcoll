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

#include <comparators.h>
#include <list.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node_t* mknode(void* data) {
  node_t* node = malloc(sizeof(node_t));

  if (node == NULL) {
    fprintf(stderr, "could not allocate memory for a new node\n");
    return NULL;
  }

  node->data = data;
  node->next = NULL;
  return node;
}

void ndestroy(node_t* node) {
  free(node->data);
  free(node);
}

list_t* mklist(comparator_t cmp) {
  list_t* list = malloc(sizeof(list_t));

  if (list == NULL) {
    fprintf(stderr, "could not allocate memory for a new list\n");
    return NULL;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  list->comparator = cmp;
  return list;
}

list_t* mki8list() {
  return mklist(i8cmp);
}

list_t* mki16list() {
  return mklist(i16cmp);
}

list_t* mki32list() {
  return mklist(i32cmp);
}

list_t* mki64list() {
  return mklist(i64cmp);
}

list_t* mku8list() {
  return mklist(u8cmp);
}

list_t* mku16list() {
  return mklist(u16cmp);
}

list_t* mku32list() {
  return mklist(u32cmp);
}

list_t* mku64list() {
  return mklist(u64cmp);
}

list_t* mkf32list() {
  return mklist(f32cmp);
}

list_t* mkf64list() {
  return mklist(f64cmp);
}

list_t* mkslist() {
  return mklist(scmp);
}

list_t* mkblist() {
  return mklist(bcmp);
}

list_t* mkclist() {
  return mklist(ccmp);
}

void ldestroy(list_t* list) {
  lclr(list);
  free(list);
}

list_t* arrtol(void* arr, size_t size, size_t elem_size, comparator_t cmp) {
  list_t* list = mklist(cmp);

  if (list == NULL)
    return NULL;

  for (size_t i = 0; i < size; i++) {
    void* elem = malloc(elem_size);

    if (elem == NULL) {
      fprintf(stderr, "could not allocate memory for new list element\n");
      ldestroy(list);
      return NULL;
    }

    memcpy(elem, (char*)arr + i * elem_size, elem_size);
    ladd(list, elem);
  }

  return list;
}

list_t* i8arrtol(i8* arr, size_t size) {
  return arrtol(arr, size, sizeof(i8), i8cmp);
}

list_t* i16arrtol(i16* arr, size_t size) {
  return arrtol(arr, size, sizeof(i16), i16cmp);
}

list_t* i32arrtol(i32* arr, size_t size) {
  return arrtol(arr, size, sizeof(i32), i32cmp);
}

list_t* i64arrtol(i64* arr, size_t size) {
  return arrtol(arr, size, sizeof(i64), i64cmp);
}

list_t* u8arrtol(u8* arr, size_t size) {
  return arrtol(arr, size, sizeof(u8), u8cmp);
}

list_t* u16arrtol(u16* arr, size_t size) {
  return arrtol(arr, size, sizeof(u16), u16cmp);
}

list_t* u32arrtol(u32* arr, size_t size) {
  return arrtol(arr, size, sizeof(u32), u32cmp);
}

list_t* u64arrtol(u64* arr, size_t size) {
  return arrtol(arr, size, sizeof(u64), u64cmp);
}

list_t* f32arrtol(f32* arr, size_t size) {
  return arrtol(arr, size, sizeof(f32), f32cmp);
}

list_t* f64arrtol(f64* arr, size_t size) {
  return arrtol(arr, size, sizeof(f64), f64cmp);
}

list_t* sarrtol(string* arr, size_t size) {
  list_t* list = mklist(scmp);

  if (list == NULL)
    return NULL;

  for (size_t i = 0; i < size; i++) {
    char* elem = malloc(strlen(arr[i]) + 1);

    if (elem == NULL) {
      fprintf(stderr, "could not allocate memory for new list element\n");
      ldestroy(list);
      return NULL;
    }

    strcpy(elem, arr[i]);
    ladd(list, elem);
  }

  return list;
}

list_t* barrtol(bool* arr, size_t size) {
  return arrtol(arr, size, sizeof(bool), bcmp);
}

list_t* carrtol(char* arr, size_t size) {
  return arrtol(arr, size, sizeof(char), ccmp);
}

size_t lsize(list_t* list) {
  return list->size;
}

void lclr(list_t* list) {
  node_t* current = list->head;

  while (current != NULL) {
    node_t* next = current->next;
    ndestroy(current);
    current = next;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

bool islempty(list_t* list) {
  return list->size == 0;
}

void* lget(list_t* list, size_t index) {
  if (index >= list->size) {
    fprintf(stderr, "index out of bounds: %ld out of %ld!\n", index, list->size);
    return NULL;
  }

  node_t* current = list->head;

  for (size_t i = 0; i < index; i++)
    current = current->next;

  return current->data;
}

i8 lgeti8(list_t* list, size_t index) {
  return *(i8*)lget(list, index);
}

i16 lgeti16(list_t* list, size_t index) {
  return *(i16*)lget(list, index);
}

i32 lgeti32(list_t* list, size_t index) {
  return *(i32*)lget(list, index);
}

i64 lgeti64(list_t* list, size_t index) {
  return *(i64*)lget(list, index);
}

u8 lgetu8(list_t* list, size_t index) {
  return *(u8*)lget(list, index);
}

u16 lgetu16(list_t* list, size_t index) {
  return *(u16*)lget(list, index);
}

u32 lgetu32(list_t* list, size_t index) {
  return *(u32*)lget(list, index);
}

u64 lgetu64(list_t* list, size_t index) {
  return *(u64*)lget(list, index);
}

f32 lgetf32(list_t* list, size_t index) {
  return *(f32*)lget(list, index);
}

f64 lgetf64(list_t* list, size_t index) {
  return *(f64*)lget(list, index);
}

string lgets(list_t* list, size_t index) {
  return (string)lget(list, index);
}

bool lgetb(list_t* list, size_t index) {
  return *(bool*)lget(list, index);
}

char lgetc(list_t* list, size_t index) {
  return *(char*)lget(list, index);
}

bool ladd(list_t* list, void* data) {
  node_t* node = mknode(data);

  if (node == NULL)
    return false;

  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }

  list->size++;
  return true;
}

bool laddi8(list_t* list, i8 data) {
  i8* data_ptr = malloc(sizeof(i8));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool laddi16(list_t* list, i16 data) {
  i16* data_ptr = malloc(sizeof(i16));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool laddi32(list_t* list, i32 data) {
  i32* data_ptr = malloc(sizeof(i32));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool laddi64(list_t* list, i64 data) {
  i64* data_ptr = malloc(sizeof(i64));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool laddu8(list_t* list, u8 data) {
  u8* data_ptr = malloc(sizeof(u8));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool laddu16(list_t* list, u16 data) {
  u16* data_ptr = malloc(sizeof(u16));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool laddu32(list_t* list, u32 data) {
  u32* data_ptr = malloc(sizeof(u32));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool laddu64(list_t* list, u64 data) {
  u64* data_ptr = malloc(sizeof(u64));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool laddf32(list_t* list, f32 data) {
  f32* data_ptr = malloc(sizeof(f32));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool laddf64(list_t* list, f64 data) {
  f64* data_ptr = malloc(sizeof(f64));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool ladds(list_t* list, string data) {
  char* s = malloc(strlen(data) + 1);

  if (s == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  strcpy(s, data);
  return ladd(list, (void*)s);
}

bool laddb(list_t* list, bool data) {
  bool* data_ptr = malloc(sizeof(bool));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool laddc(list_t* list, char data) {
  char* data_ptr = malloc(sizeof(char));

  if (data_ptr == NULL) {
    fprintf(stderr, "could not allocate memory for new data\n");
    return false;
  }

  *data_ptr = data;
  return ladd(list, (void*)data_ptr);
}

bool laddall(list_t* to, list_t* from) {
  if (from == NULL || from->size == 0)
    return false;

  if (to->head == NULL) {
    to->head = from->head;
    to->tail = from->tail;
  } else {
    to->tail->next = from->head;
    to->tail = from->tail;
  }

  to->size += from->size;
  return true;
}

bool lrm(list_t* list, void* data, comparator_t cmp) {
  if (list->size == 0)
    return false;

  cmp = cmp == NULL ? list->comparator : cmp;
  node_t* current = list->head;
  node_t* previous = NULL;

  while (current != NULL) {
    if (cmp(current->data, data) == 0) {
      if (previous == NULL)
        list->head = current->next;
      else
        previous->next = current->next;

      if (current == list->tail)
        list->tail = previous;

      ndestroy(current);
      list->size--;
      return true;
    }

    previous = current;
    current = current->next;
  }

  return false;
}

bool lrmi8(list_t* list, i8 data) {
  return lrm(list, (void*)&data, i8cmp);
}

bool lrmi16(list_t* list, i16 data) {
  return lrm(list, (void*)&data, i16cmp);
}

bool lrmi32(list_t* list, i32 data) {
  return lrm(list, (void*)&data, i32cmp);
}

bool lrmi64(list_t* list, i64 data) {
  return lrm(list, (void*)&data, i64cmp);
}

bool lrmu8(list_t* list, u8 data) {
  return lrm(list, (void*)&data, u8cmp);
}

bool lrmu16(list_t* list, u16 data) {
  return lrm(list, (void*)&data, u16cmp);
}

bool lrmu32(list_t* list, u32 data) {
  return lrm(list, (void*)&data, u32cmp);
}

bool lrmu64(list_t* list, u64 data) {
  return lrm(list, (void*)&data, u64cmp);
}

bool lrmf32(list_t* list, f32 data) {
  return lrm(list, (void*)&data, f32cmp);
}

bool lrmf64(list_t* list, f64 data) {
  return lrm(list, (void*)&data, f64cmp);
}

bool lrms(list_t* list, string data) {
  return lrm(list, (void*)data, scmp);
}

bool lrmb(list_t* list, bool data) {
  return lrm(list, (void*)&data, bcmp);
}

bool lrmc(list_t* list, char data) {
  return lrm(list, (void*)&data, ccmp);
}

bool lrmall(list_t* list, list_t* other, comparator_t cmp) {
  if (other == NULL || other->size == 0)
    return false;

  cmp = cmp == NULL ? list->comparator : cmp;
  node_t* current = other->head;
  bool removed = false;

  while (current != NULL) {
    node_t* next = current->next;
    if (lrm(list, current->data, cmp)) removed = true;
    current = next;
  }

  return removed;
}

bool lrmif(list_t* list, predicate_t pred) {
  if (list->size == 0)
    return false;

  node_t* current = list->head;
  node_t* previous = NULL;
  bool removed = false;

  while (current != NULL) {
    if (pred(current->data)) {
      node_t* to_remove = current;

      if (previous == NULL)
        list->head = current->next;
      else
        previous->next = current->next;

      if (current == list->tail) {
        list->tail = previous;
        current = NULL;
      } else current = current->next;

      ndestroy(to_remove);
      list->size--;
      removed = true;
    } else {
      previous = current;
      current = current->next;
    }
  }

  return removed;
}

size_t lidxof(list_t* list, void* data, comparator_t cmp) {
  if (list->size == 0)
    return -1;

  cmp = cmp == NULL ? list->comparator : cmp;
  node_t* current = list->head;
  size_t index = 0;

  while (current != NULL) {
    if (cmp(current->data, data) == 0)
      return index;

    current = current->next;
    index++;
  }

  return -1;
}

size_t lidxofi8(list_t* list, i8 data) {
  return lidxof(list, (void*)&data, i8cmp);
}

size_t lidxofi16(list_t* list, i16 data) {
  return lidxof(list, (void*)&data, i16cmp);
}

size_t lidxofi32(list_t* list, i32 data) {
  return lidxof(list, (void*)&data, i32cmp);
}

size_t lidxofi64(list_t* list, i64 data) {
  return lidxof(list, (void*)&data, i64cmp);
}

size_t lidxofu8(list_t* list, u8 data) {
  return lidxof(list, (void*)&data, u8cmp);
}

size_t lidxofu16(list_t* list, u16 data) {
  return lidxof(list, (void*)&data, u16cmp);
}

size_t lidxofu32(list_t* list, u32 data) {
  return lidxof(list, (void*)&data, u32cmp);
}

size_t lidxofu64(list_t* list, u64 data) {
  return lidxof(list, (void*)&data, u64cmp);
}

size_t lidxoff32(list_t* list, f32 data) {
  return lidxof(list, (void*)&data, f32cmp);
}

size_t lidxoff64(list_t* list, f64 data) {
  return lidxof(list, (void*)&data, f64cmp);
}

size_t lidxofs(list_t* list, string data) {
  return lidxof(list, (void*)data, scmp);
}

size_t lidxofb(list_t* list, bool data) {
  return lidxof(list, (void*)&data, bcmp);
}

size_t lidxofc(list_t* list, char data) {
  return lidxof(list, (void*)&data, ccmp);
}

size_t llidxof(list_t* list, void* data, comparator_t cmp) {
  if (list->size == 0)
    return -1;

  cmp = cmp == NULL ? list->comparator : cmp;
  node_t* current = list->head;
  size_t index = 0;
  size_t last_index = -1;

  while (current != NULL) {
    if (cmp(current->data, data) == 0)
      last_index = index;

    current = current->next;
    index++;
  }

  return last_index;
}

size_t llidxofi8(list_t* list, i8 data) {
  return llidxof(list, (void*)&data, i8cmp);
}

size_t llidxofi16(list_t* list, i16 data) {
  return llidxof(list, (void*)&data, i16cmp);
}

size_t llidxofi32(list_t* list, i32 data) {
  return llidxof(list, (void*)&data, i32cmp);
}

size_t llidxofi64(list_t* list, i64 data) {
  return llidxof(list, (void*)&data, i64cmp);
}

size_t llidxofu8(list_t* list, u8 data) {
  return llidxof(list, (void*)&data, u8cmp);
}

size_t llidxofu16(list_t* list, u16 data) {
  return llidxof(list, (void*)&data, u16cmp);
}

size_t llidxofu32(list_t* list, u32 data) {
  return llidxof(list, (void*)&data, u32cmp);
}

size_t llidxofu64(list_t* list, u64 data) {
  return llidxof(list, (void*)&data, u64cmp);
}

size_t llidxoff32(list_t* list, f32 data) {
  return llidxof(list, (void*)&data, f32cmp);
}

size_t llidxoff64(list_t* list, f64 data) {
  return llidxof(list, (void*)&data, f64cmp);
}

size_t llidxofs(list_t* list, string data) {
  return llidxof(list, (void*)data, scmp);
}

size_t llidxofb(list_t* list, bool data) {
  return llidxof(list, (void*)&data, bcmp);
}

size_t llidxofc(list_t* list, char data) {
  return llidxof(list, (void*)&data, ccmp);
}

bool lcnts(list_t* list, void* data, comparator_t cmp) {
  if (list->size == 0)
    return false;

  cmp = cmp == NULL ? list->comparator : cmp;
  node_t* current = list->head;

  while (current != NULL) {
    if (cmp(current->data, data) == 0)
      return true;

    current = current->next;
  }

  return false;
}

bool lcntsi8(list_t* list, i8 data) {
  return lcnts(list, (void*)&data, i8cmp);
}

bool lcntsi16(list_t* list, i16 data) {
  return lcnts(list, (void*)&data, i16cmp);
}

bool lcntsi32(list_t* list, i32 data) {
  return lcnts(list, (void*)&data, i32cmp);
}

bool lcntsi64(list_t* list, i64 data) {
  return lcnts(list, (void*)&data, i64cmp);
}

bool lcntsu8(list_t* list, u8 data) {
  return lcnts(list, (void*)&data, u8cmp);
}

bool lcntsu16(list_t* list, u16 data) {
  return lcnts(list, (void*)&data, u16cmp);
}

bool lcntsu32(list_t* list, u32 data) {
  return lcnts(list, (void*)&data, u32cmp);
}

bool lcntsu64(list_t* list, u64 data) {
  return lcnts(list, (void*)&data, u64cmp);
}

bool lcntsf32(list_t* list, f32 data) {
  return lcnts(list, (void*)&data, f32cmp);
}

bool lcntsf64(list_t* list, f64 data) {
  return lcnts(list, (void*)&data, f64cmp);
}

bool lcntss(list_t* list, string data) {
  return lcnts(list, (void*)data, scmp);
}

bool lcntsb(list_t* list, bool data) {
  return lcnts(list, (void*)&data, bcmp);
}

bool lcntsc(list_t* list, char data) {
  return lcnts(list, (void*)&data, ccmp);
}

bool lcntsall(list_t* list, list_t* other, comparator_t cmp) {
  if (other == NULL || list->size == 0 || other->size == 0)
    return false;

  cmp = cmp == NULL ? list->comparator : cmp;
  node_t* current = other->head;

  while (current != NULL) {
    if (!lcnts(list, current->data, cmp))
      return false;

    current = current->next;
  }

  return true;
}

bool lcntsany(list_t* list, list_t* other, comparator_t cmp) {
  if (other == NULL || list->size == 0 || other->size == 0)
    return false;

  cmp = cmp == NULL ? list->comparator : cmp;
  node_t* current = other->head;

  while (current != NULL) {
    if (lcnts(list, current->data, cmp))
      return true;

    current = current->next;
  }

  return false;
}

void sortl(list_t* list, comparator_t cmp) {
  if (list->size == 0)
    return;

  cmp = cmp == NULL ? list->comparator : cmp;
  node_t* current = list->head;
  node_t* index = NULL;
  void* temp = NULL;

  while (current != NULL) {
    index = current->next;

    while (index != NULL) {
      if (cmp(current->data, index->data) > 0) {
        temp = current->data;
        current->data = index->data;
        index->data = temp;
      }

      index = index->next;
    }

    current = current->next;
  }
}

void lforeach(list_t* list, consumer_t action) {
  node_t* current = list->head;

  while (current != NULL) {
    action(current->data);
    current = current->next;
  }
}

iterator_t* lit(list_t* list) {
  iterator_t* iterator = malloc(sizeof(iterator_t));

  if (iterator == NULL) {
    fprintf(stderr, "could not allocate memory for an iterator\n");
    return NULL;
  }

  iterator->current = list->head;
  return iterator;
}

bool ithasn(iterator_t* iterator) {
  return iterator->current != NULL;
}

void* itnext(iterator_t* iterator) {
  if (iterator->current == NULL)
    return NULL;

  void* data = iterator->current->data;
  iterator->current = iterator->current->next;
  return data;
}

i8 itnexti8(iterator_t* it) {
  return *(i8*)itnext(it);
}

i16 itnexti16(iterator_t* it) {
  return *(i16*)itnext(it);
}

i32 itnexti32(iterator_t* it) {
  return *(i32*)itnext(it);
}

i64 itnexti64(iterator_t* it) {
  return *(i64*)itnext(it);
}

u8 itnextu8(iterator_t* it) {
  return *(u8*)itnext(it);
}

u16 itnextu16(iterator_t* it) {
  return *(u16*)itnext(it);
}

u32 itnextu32(iterator_t* it) {
  return *(u32*)itnext(it);
}

u64 itnextu64(iterator_t* it) {
  return *(u64*)itnext(it);
}

f32 itnextf32(iterator_t* it) {
  return *(f32*)itnext(it);
}

f64 itnextf64(iterator_t* it) {
  return *(f64*)itnext(it);
}

string itnexts(iterator_t* it) {
  return (string)itnext(it);
}

bool itnextb(iterator_t* it) {
  return *(bool*)itnext(it);
}

char itnextc(iterator_t* it) {
  return *(char*)itnext(it);
}

void itforeachr(iterator_t* iterator, consumer_t action) {
  while (ithasn(iterator))
    action(itnext(iterator));
}
