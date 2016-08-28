//
// Created by yura on 8/28/16.
//
#ifndef NERUAL_EXAMPLE_NEURON_H
#define NERUAL_EXAMPLE_NEURON_H

#include <stdlib.h> // rand
#include <string.h>

#define ROW_WEIGHT  (6)
#define COLUMN_WEIGHT (10)
#define LENGHT_DATA (ROW_WEIGHT * COLUMN_WEIGHT)
#define LENGHT_NAME (16)

struct neuron{
	char name[LENGHT_NAME];

	u_int8_t weight[ROW_WEIGHT][COLUMN_WEIGHT];

	int max;
	int learned;
};

/**
 * @ brief setup boundary 'minimum' in neuron and fill weight random value
 */
void neuron_init(struct neuron *neuron, int neuron_minimum);

/**
 * @ brief hard responses of neurons
 * @ param input - input array
 * @ return 0 or 1
 */
int neuron_transfer_hard(struct neuron *neuron, u_int8_t input[][COLUMN_WEIGHT]);

/**
 * @ brief responses of neurons
 * @ param input - input array
 * @ return 0 or 1
 */
int neuron_transfer(struct neuron *neuron, u_int8_t input[][COLUMN_WEIGHT]);

/**
 * @ brief change weights of neuron
 * @ param input - input array
 * @ param diff - difference between output of the neuron and the desired output
 */
void neuron_change_weights(struct neuron *neuron, u_int8_t input[][COLUMN_WEIGHT], __int8_t diff);

//void neuron_prepare_serialization(struct neuron *neuron);
//
//void neuron_on_deseralize(struct neuron *neuron);

#endif //NERUAL_EXAMPLE_NEURON_H
