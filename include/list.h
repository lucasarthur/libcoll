#pragma once
#include <types.h>

typedef struct node_t {
  void* data;
  struct node_t* next;
} node_t;

typedef struct list_t {
  node_t* head;
  node_t* tail;
  size_t size;
  comparator_t comparator;
} list_t;

typedef struct iterator_t {
  node_t* current;
} iterator_t;

list_t* mklist(comparator_t cmp);
list_t* mki8list();
list_t* mki16list();
list_t* mki32list();
list_t* mki64list();
list_t* mku8list();
list_t* mku16list();
list_t* mku32list();
list_t* mku64list();
list_t* mkf32list();
list_t* mkf64list();
list_t* mkslist();
list_t* mkblist();
list_t* mkclist();

list_t* arrtol(void* arr, size_t size, size_t elem_size, comparator_t cmp);
list_t* i8arrtol(i8* arr, size_t size);
list_t* i16arrtol(i16* arr, size_t size);
list_t* i32arrtol(i32* arr, size_t size);
list_t* i64arrtol(i64* arr, size_t size);
list_t* u8arrtol(u8* arr, size_t size);
list_t* u16arrtol(u16* arr, size_t size);
list_t* u32arrtol(u32* arr, size_t size);
list_t* u64arrtol(u64* arr, size_t size);
list_t* f32arrtol(f32* arr, size_t size);
list_t* f64arrtol(f64* arr, size_t size);
list_t* sarrtol(string* arr, size_t size);
list_t* barrtol(bool* arr, size_t size);
list_t* carrtol(char* arr, size_t size);

void ldestroy(list_t* list);

void* lget(list_t* list, size_t index);
i8 lgeti8(list_t* list, size_t index);
i16 lgeti16(list_t* list, size_t index);
i32 lgeti32(list_t* list, size_t index);
i64 lgeti64(list_t* list, size_t index);
u8 lgetu8(list_t* list, size_t index);
u16 lgetu16(list_t* list, size_t index);
u32 lgetu32(list_t* list, size_t index);
u64 lgetu64(list_t* list, size_t index);
f32 lgetf32(list_t* list, size_t index);
f64 lgetf64(list_t* list, size_t index);
string lgets(list_t* list, size_t index);
bool lgetb(list_t* list, size_t index);
char lgetc(list_t* list, size_t index);

bool ladd(list_t* list, void* data);
bool laddi8(list_t* list, i8 data);
bool laddi16(list_t* list, i16 data);
bool laddi32(list_t* list, i32 data);
bool laddi64(list_t* list, i64 data);
bool laddu8(list_t* list, u8 data);
bool laddu16(list_t* list, u16 data);
bool laddu32(list_t* list, u32 data);
bool laddu64(list_t* list, u64 data);
bool laddf32(list_t* list, f32 data);
bool laddf64(list_t* list, f64 data);
bool ladds(list_t* list, string data);
bool laddb(list_t* list, bool data);
bool laddc(list_t* list, char data);
bool laddall(list_t* to, list_t* from);

bool lrm(list_t* list, void* data, comparator_t cmp);
bool lrmi8(list_t* list, i8 data);
bool lrmi16(list_t* list, i16 data);
bool lrmi32(list_t* list, i32 data);
bool lrmi64(list_t* list, i64 data);
bool lrmu8(list_t* list, u8 data);
bool lrmu16(list_t* list, u16 data);
bool lrmu32(list_t* list, u32 data);
bool lrmu64(list_t* list, u64 data);
bool lrmf32(list_t* list, f32 data);
bool lrmf64(list_t* list, f64 data);
bool lrms(list_t* list, string data);
bool lrmb(list_t* list, bool data);
bool lrmc(list_t* list, char data);
bool lrmall(list_t* list, list_t* other, comparator_t cmp);
bool lrmif(list_t* list, predicate_t pred);

size_t lidxof(list_t* list, void* data, comparator_t cmp);
size_t lidxofi8(list_t* list, i8 data);
size_t lidxofi16(list_t* list, i16 data);
size_t lidxofi32(list_t* list, i32 data);
size_t lidxofi64(list_t* list, i64 data);
size_t lidxofu8(list_t* list, u8 data);
size_t lidxofu16(list_t* list, u16 data);
size_t lidxofu32(list_t* list, u32 data);
size_t lidxofu64(list_t* list, u64 data);
size_t lidxoff32(list_t* list, f32 data);
size_t lidxoff64(list_t* list, f64 data);
size_t lidxofs(list_t* list, string data);
size_t lidxofb(list_t* list, bool data);
size_t lidxofc(list_t* list, char data);

size_t llidxof(list_t* list, void* data, comparator_t cmp);
size_t llidxofi8(list_t* list, i8 data);
size_t llidxofi16(list_t* list, i16 data);
size_t llidxofi32(list_t* list, i32 data);
size_t llidxofi64(list_t* list, i64 data);
size_t llidxofu8(list_t* list, u8 data);
size_t llidxofu16(list_t* list, u16 data);
size_t llidxofu32(list_t* list, u32 data);
size_t llidxofu64(list_t* list, u64 data);
size_t llidxoff32(list_t* list, f32 data);
size_t llidxoff64(list_t* list, f64 data);
size_t llidxofs(list_t* list, string data);
size_t llidxofb(list_t* list, bool data);
size_t llidxofc(list_t* list, char data);

bool lcnts(list_t* list, void* data, comparator_t cmp);
bool lcntsi8(list_t* list, i8 data);
bool lcntsi16(list_t* list, i16 data);
bool lcntsi32(list_t* list, i32 data);
bool lcntsi64(list_t* list, i64 data);
bool lcntsu8(list_t* list, u8 data);
bool lcntsu16(list_t* list, u16 data);
bool lcntsu32(list_t* list, u32 data);
bool lcntsu64(list_t* list, u64 data);
bool lcntsf32(list_t* list, f32 data);
bool lcntsf64(list_t* list, f64 data);
bool lcntss(list_t* list, string data);
bool lcntsb(list_t* list, bool data);
bool lcntsc(list_t* list, char data);
bool lcntsall(list_t* list, list_t* other, comparator_t cmp);
bool lcntsany(list_t* list, list_t* other, comparator_t cmp);

void sortl(list_t* list, comparator_t cmp);

size_t lsize(list_t* list);
void lclr(list_t* list);
bool islempty(list_t* list);

void lforeach(list_t* list, consumer_t action);
iterator_t* lit(list_t* list);
bool ithasn(iterator_t* it);
void* itnext(iterator_t* it);
i8 itnexti8(iterator_t* it);
i16 itnexti16(iterator_t* it);
i32 itnexti32(iterator_t* it);
i64 itnexti64(iterator_t* it);
u8 itnextu8(iterator_t* it);
u16 itnextu16(iterator_t* it);
u32 itnextu32(iterator_t* it);
u64 itnextu64(iterator_t* it);
f32 itnextf32(iterator_t* it);
f64 itnextf64(iterator_t* it);
string itnexts(iterator_t* it);
bool itnextb(iterator_t* it);
char itnextc(iterator_t* it);
void itforeachr(iterator_t* it, consumer_t action);
