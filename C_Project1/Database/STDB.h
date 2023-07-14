#ifndef STDB_H
#define STDB_H
#include "../types.h"

#define SDBMaxSize 5

typedef struct STDB {  

	uint32_t Student_ID[SDBMaxSize];
	uint32_t Student_year[SDBMaxSize];
	uint32_t Course1_ID[SDBMaxSize];
	uint32_t Course1_grade[SDBMaxSize];
	uint32_t Course2_ID[SDBMaxSize];
	uint32_t Course2_grade[SDBMaxSize];
	uint32_t Course3_ID[SDBMaxSize];
	uint32_t Course3_grade[SDBMaxSize];

} student;

bool_t SDB_IsFull(void);
uint8_t SDB_GetUsedSize(student* ptr);
bool_t SDB_AddEntry(student* ptr);
void SDB_DeletEntry(uint32_t id, student* ptr);
bool_t SDB_ReadEntry(uint32_t id, student* ptr);
void SDB_GetList(uint8_t count, uint32_t* list);
bool_t SDB_IsIdExist(uint32_t id, student* ptr);
void SDB_action(uint8_t UserIn);

#endif