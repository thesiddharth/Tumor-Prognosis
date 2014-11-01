#include "fann.h"
#include "floatfann.h"
#include "math.h"
#include"stdlib.h"
#include"stdio.h"
#include"string.h"

int main()
{
	const unsigned int num_input = 10;
    	
	const unsigned int num_output = 1;
    	
	const unsigned int num_init_layers = 2;
	
    	const float desired_error = (const float) 0.001;
    	
	const unsigned int max_neurons = 40;

    	const unsigned int neurons_between_reports=5;

    	struct fann *ann = fann_create_shortcut(num_init_layers, num_input, num_output);

    	fann_cascadetrain_on_file(ann, "prediction.data", max_neurons, neurons_between_reports, desired_error);

    	fann_save(ann, "prediction.net");

    	fann_destroy(ann);

    	return 0;
}
