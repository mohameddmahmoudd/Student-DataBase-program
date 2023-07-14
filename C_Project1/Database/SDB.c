#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "../types.h"
#include "STDB.h"

uint8_t usedplaces_flag;
uint8_t deletion_flag=_false;

bool_t SDB_AddEntry(student* ptr) {
	
	uint8_t check_flag = 0;
	static array_flag = 0;

	if (deletion_flag == _true) {
		array_flag--; 
		deletion_flag = _false;
	}
	
	printf("Enter ID: ");
	scanf_s("%d", &(ptr->Student_ID[array_flag]));
	check_flag++;
	printf("Enter Year: ");
	scanf_s("%d", &(ptr->Student_year[array_flag]));
	check_flag++;
	printf("Enter Course 1 ID: ");
	scanf_s("%d", &(ptr->Course1_ID[array_flag]));
	check_flag++;
	printf("Enter Course 1 Grade: ");
	scanf_s("%d", &(ptr->Course1_grade[array_flag]));
	check_flag++;
	printf("Enter Course 2 ID: ");
	scanf_s("%d", &(ptr->Course2_ID[array_flag]));
	check_flag++;
	printf("Enter Course 2 Grade: ");
	scanf_s("%d", &(ptr->Course2_grade[array_flag]));
	check_flag++;
	printf("Enter Course 3 ID: ");
	scanf_s("%d", &(ptr->Course3_ID[array_flag]));
	check_flag++;
	printf("Enter Course 3 Grade: ");
	scanf_s("%d", &(ptr->Course3_grade[array_flag]));
	check_flag++;

	
		array_flag++;
	
	usedplaces_flag++;

	if (check_flag == 8) return _true;
	else return _false;
}

uint8_t SDB_GetUsedSize(student* ptr) {

	return usedplaces_flag;

}

bool_t SDB_ReadEntry(uint32_t id, student* ptr) {
	
	bool_t fflag=0;
	for (int i = 0; i < SDBMaxSize; i++) {
		
		if(id == ptr->Student_ID[i]){

			printf("ID : %d\n", ptr->Student_ID[i]);
			printf("Year : %d\n", ptr->Student_year[i]);
			printf("Course 1 ID : %d\n", ptr->Course1_ID[i]);
			printf("Course 1 Grade : %d\n", ptr->Course1_grade[i]);
			printf("Course 1 ID : %d\n", ptr->Course2_ID[i]);
			printf("Course 1 Grade : %d\n", ptr->Course2_grade[i]);
			printf("Course 1 ID : %d\n", ptr->Course3_ID[i]);
			printf("Course 1 Grade : %d\n", ptr->Course3_grade[i]);

			fflag++;
	}

	}

		return fflag;
}

	bool_t SDB_IsFull(void){
		if (usedplaces_flag == SDBMaxSize) return _true;
		else return _false;

	}

	void SDB_GetList(uint8_t count, uint32_t* list) {
		for (int i = 0; i < count; i++) {
			printf("The IDs are: %d- %d\n",(i+1),list[i]);
		}
	}

	bool_t SDB_IsIdExist(uint32_t id, student* ptr) {

		bool_t fflag = 0;
		for (int i = 0; i < SDBMaxSize; i++) {

			if (id == ptr->Student_ID[i]) {
				fflag++;
			}
			
	     }  
		return fflag;
	}

	void SDB_DeletEntry(uint32_t id, student* ptr) {
		
		int index=0;
		bool_t function_flag=_false;
		for (int i = 0; i < SDBMaxSize; i++) {

			if (id == ptr->Student_ID[i]) {

				
				ptr->Student_ID[i] = 0;
				ptr->Student_year[i] = 0;	
				 ptr->Course1_ID[i] = 0;
				 ptr->Course1_grade[i] = 0;
				ptr->Course2_ID[i] = 0;
				 ptr->Course2_grade[i] = 0;
				ptr->Course3_ID[i] = 0;
				ptr->Course3_grade[i] = 0;

				index = i;

				usedplaces_flag--;
				function_flag = _true;
				deletion_flag = _true;
				
			}

		}

		if(function_flag==_true)
		{ 
		for (int i = index; i <SDBMaxSize; i++) {

			ptr->Student_ID[i] = ptr->Student_ID[i+1];
			ptr->Student_year[i] = ptr->Student_year[i+1];
			ptr->Course1_ID[i] = ptr->Course1_ID[i+1];
			ptr->Course1_grade[i] = ptr->Course1_grade[i+1];
			ptr->Course2_ID[i] = ptr->Course2_ID[i+1];
			ptr->Course2_grade[i] = ptr->Course2_grade[i+1];
			ptr->Course3_ID[i] = ptr->Course3_ID[i + 1];
			ptr->Course3_grade[i] = ptr->Course3_grade[i + 1];
		}

		}
		}



