#include <stdio.h>
#include "neural_network.h"
#include "test.h"


int main()
{
	struct neural_network *network = NULL;
	network_init(&network, 10, 100);

	network_study(network, K_letter, "k letter");
	network_study(network, first_letter, "number 1");
	network_study(network, second_letter, "number 2");
	network_study(network, third_letter, "number 3");

	int answer;
	network_get_answer(network, first_letter_test, &answer);

	printf("the answer is %s", network->neuron[answer].name);


	network_destroy(network);
}
