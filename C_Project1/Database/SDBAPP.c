#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "../types.h"
#include "STDB.h"

extern student studentt;
extern usedplaces_flag;


void SDB_APP(void) {

	uint8_t UserIn,exit_flag=1;
	
	

	while (exit_flag) {

		printf("Enter Action Number from 1-7 and for exiting press 0: ");
		scanf_s("%hhd", &UserIn);

		if (UserIn == 0) {

			exit_flag = 0;
		}

		else if (UserIn > 7) {
			printf("Incorrect Number try again\n");
		}

		else {
			SDB_action(UserIn);
		}

	}


}




void SDB_action(uint8_t UserIn) {

	static uint8_t max = 0;

	switch (UserIn) {

	case (1): {

		
		if (max < (SDBMaxSize)) {
			uint8_t retrn = SDB_AddEntry(&studentt);
			while (retrn == _false) {
				SDB_AddEntry(&studentt);
			}
			printf("Successful Entry\n");
		}
		else printf("Data Base is Full\n");

	}	max++;
		break;

	case (2): {
		uint8_t Size = SDB_GetUsedSize(&studentt);
		printf("Number of students in database is : %d \n", Size);
	}break;

	case (3): {
		uint32_t id;
		printf("Enter ID for the search: ");
		scanf_s("%d", &id);
		if (id == 0) {printf("Incorrect ID\n"); break;}
		uint8_t exist_flag=SDB_ReadEntry(id, &studentt);
		if (exist_flag == _false) printf("ID not found\n");
		
	}break;

	case (4): {
		uint32_t* ptr = studentt.Student_ID;
		SDB_GetList(usedplaces_flag, ptr);

	}break;

	case (5): {
		uint32_t id;

		printf("Enter ID to check for existence: ");
		scanf_s("%d", &id);
		uint8_t exist_flag=SDB_IsIdExist(id, &studentt);
		if (exist_flag == _false) printf("ID not found\n");
		else printf("ID Found\n");

	}break;

	case (6): {
		uint32_t id;

		printf("Enter ID to delete record: ");
		scanf_s("%d", &id);

		SDB_DeletEntry(id,&studentt);
		max--;

	}break;

	case (7): {

		uint8_t flag = SDB_IsFull();
		if (flag == _true) printf("SDB is full\n");
		else printf("SDB is not full\n");

	}break;




	}

}