//
// Created by yura on 8/28/16.
//

#include "neuron.h"
#include "mydef.h"

static void rand_weights(wsize weight[][COLUMN_WEIGHT]);

void neuron_init(struct neuron *neuron, int neuron_max) {
	neuron->max = neuron_max;
	memset(neuron->weight, 0, LENGHT_DATA);
	rand_weights(neuron->weight);
}

static void rand_weights(wsize weight[][COLUMN_WEIGHT]) {
	FOR_EACH_WEIGHT(r,c)
		weight[r][c] = (wsize)rand() & 7;
}

int neuron_transfer_hard(struct neuron *neuron, wsize input[][COLUMN_WEIGHT]) {
	int power = 0;

	FOR_EACH_WEIGHT(r,c)
			power += abs(neuron->weight[r][c] - input[r][c]);

	return power <= neuron->max ? 1 : 0;
}

int neuron_transfer(struct neuron *neuron, wsize input[][COLUMN_WEIGHT]) {
	int power = 0;

	FOR_EACH_WEIGHT(r,c)
			power += abs(neuron->weight[r][c] - input[r][c]);

	return power;
}

void neuron_change_weights(struct neuron *neuron, wsize input[][COLUMN_WEIGHT]) {
	FOR_EACH_WEIGHT(r,c)
			neuron->weight[r][c] = input[r][c];
}

//void neuron_prepare_serialization(struct neuron *neuron) {
//	memcpy(neuron->data, neuron->weight, LENGHT_DATA);
//}
//
//void neuron_on_deseralize(struct neuron *neuron) {
//	memcpy(neuron->weight, neuron->data, LENGHT_DATA);
//}
