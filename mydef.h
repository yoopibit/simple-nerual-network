//
// Created by yura on 8/28/16.
//

#ifndef PROJECT_CONSTANTS_H
#define PROJECT_CONSTANTS_H

#define FOR_EACH_WEIGHT(row, column) 	for (int row = 0; row < ROW_WEIGHT; ++row) \
										for (int column = 0; column < COLUMN_WEIGHT; ++column)

#define RC_OK (0)
#define RC_ERROR (-1)
#define RC_SMALL_COUNT_NEURON (-2)
#define RC_BIG_NAME_LENGHT (-3)

#define check_ptr(ptr)  if ((void*)ptr == NULL) \
						return RC_ERROR;

#define check_three_ptrs(ptr1, ptr2, ptr3)  if ((void*)ptr1 == NULL || (void*)ptr2 == NULL || (void*)ptr3 == NULL ) \
												return RC_ERROR;


#endif //PROJECT_CONSTANTS_H
