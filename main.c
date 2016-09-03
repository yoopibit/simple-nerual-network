#include <stdio.h>
#include "neural_network.h"
#include "test.h"

void print_picture(char *about, char picure[][COLUMN_WEIGHT]);

int main()
{
	struct neural_network *network = NULL;
	size_t num_neurons = 10;
	int boundary_of_searching = 100; // less is better result in searching

	network_init(&network, num_neurons, boundary_of_searching);


	print_picture("k letter:", K_letter);
	network_study(network, K_letter, "k letter");

	print_picture("number 1:", first_num);
	network_study(network, first_num, "number 1");

	print_picture("number 2:", second_num);
	network_study(network, second_num, "number 2");

	print_picture("number 3:", third_num);
	network_study(network, third_num, "number 3");

	int answer;
	print_picture("not corected first number:", first_num_test);
	network_get_answer(network, first_num_test, &answer);
	printf("the answer is %s\n", network->neuron[answer].name);

	print_picture("not corected K letter:", K_letter_test);
	network_get_answer(network, K_letter_test, &answer);
	printf("the answer is %s\n\n", network->neuron[answer].name);

	print_picture("not corected second number: ", second_num_test);
	network_get_answer(network, second_num_test, &answer);
	printf("the answer is %s \n\n", network->neuron[answer].name);

	network_destroy(network);
}

void print_picture(char * about, char picure[][COLUMN_WEIGHT]) {
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\nPrinted %s\n", about);
	for (int i = 0; i < ROW_WEIGHT; ++i) {
		for (int j = 0; j < COLUMN_WEIGHT; ++j) {
			printf("%c", picure[i][j]);
		}
		printf("\n");
	}

}
