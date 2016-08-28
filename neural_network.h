//
// Created by yura on 8/28/16.
//

#ifndef PROJECT_NEURAL_NETWORK_H
#define PROJECT_NEURAL_NETWORK_H

#include "neuron.h"
#include "mydef.h"
#include "string.h"

struct neural_network
{
	size_t number_learned;
	size_t count;
	struct neuron neuron[0];
};

int network_init(struct neural_network **self, size_t count, int neuron_minimum);

/**
 * @ brief using for teaching
 * @ param input - input array
 * @ param answer - answer from neuron (array of 0 and 1)
 */
int network_handle_hard(struct neural_network *self, u_int8_t input[][COLUMN_WEIGHT], int *output);

/**
 * @brief function character recognition, is used for the final response
 *
 */
int network_handle(struct neural_network *self, u_int8_t input[][COLUMN_WEIGHT], int *output);

int network_get_answer(struct neural_network *self, u_int8_t input[][COLUMN_WEIGHT], int *max_index);

int network_study(struct neural_network *self, u_int8_t input[][COLUMN_WEIGHT], char* name);

//void network_prepare_serialization(struct neural_network *self);
//
//void network_on_deserialize(struct neural_network *self);

int network_destroy(struct neural_network *self);




#endif //PROJECT_NEURAL_NETWORK_H
