//
// Created by yura on 8/28/16.
//

#include <stdbool.h>
#include "neural_network.h"

int network_init(struct neural_network **self, size_t count, int neuron_minimum) {
	struct neural_network *network = (struct neural_network *)malloc(sizeof(struct neuron) * count
	                                                                 + sizeof(struct neural_network));

	check_ptr(network);

	network->number_learned = 0;
	network->count = count;

	for (size_t i = 0; i < count; ++i) {
		neuron_init(&network->neuron[i], neuron_minimum);
	}

	*self = network;
	return RC_OK;
}

int network_handle_hard(struct neural_network *self, u_int8_t input[][COLUMN_WEIGHT], int *output) {
	check_three_ptrs(self, input, output);

	for (int i = 0; i < self->count; ++i) {
		output[i] = neuron_transfer_hard(&self->neuron[i], input);
	}
	return  RC_OK;
}


int network_handle(struct neural_network *self, u_int8_t input[][COLUMN_WEIGHT], int *output) {
	check_three_ptrs(self, input, output);

	for(size_t i = 0; i < self->count; ++i) {
		output[i] = neuron_transfer(&self->neuron[i], input);
	}

	return RC_OK;
}

int network_get_answer(struct neural_network *self, u_int8_t input[][COLUMN_WEIGHT], int *max_index) {
	check_ptr(max_index);

	int output[self->count];
	int ret = network_handle(self, input, output);

	if (ret != RC_OK)
		return RC_ERROR;

	*max_index = 0;
	for (int i = 1; i < self->count; ++i) {
		if (output[i] < output[*max_index])
			*max_index = i;
	}

	return RC_OK;
}

int network_study(struct neural_network *self, u_int8_t input[][COLUMN_WEIGHT], char* name) {
	check_three_ptrs(name, self, input);

	if (self->number_learned >= self->count) {
		return RC_SMALL_COUNT_NEURON;
	}

	if (strlen(name) >= LENGHT_NAME)
		return RC_BIG_NAME_LENGHT;

	int corrected_output[self->count];
	const size_t size_array = self->count * sizeof(int);
	memset(corrected_output, 0, size_array);

	memcpy(self->neuron[self->number_learned].name, name, LENGHT_NAME);

	corrected_output[self->number_learned++] = 1;

	int output[self->count];
	int ret = network_handle_hard(self, input, output);
	if (ret != RC_OK) {
		return RC_ERROR;
	}
	int learned = 0;
	while (memcmp(corrected_output, output, size_array)) {
		for (int i = 0; i < self->count && !learned; ++i) {
			int diff = corrected_output[i] - output[i];
			if (!self->neuron[i].learned)
				neuron_change_weights(&self->neuron[i], input, diff);
			if (diff == 1 && !self->neuron[i].learned)
				learned = self->neuron[i].learned = 1;

		}
		network_handle_hard(self, input, output);
	}
	return RC_OK;
}

//void network_prepare_serialization(struct neural_network *self) {
//	for (size_t i = 0; i < self->count; ++i)
//		neuron_prepare_serialization(&self->neuron[i]);
//}
//
//void network_on_deserialize(struct neural_network *self) {
//	for (size_t i = 0; i < self->count; ++i)
//		neuron_on_deseralize(&self->neuron[i]);
//}

int network_destroy(struct neural_network *self) {
	check_ptr(self);
	free(self);
	return RC_OK;
}
