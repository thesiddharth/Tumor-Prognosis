#include "fann.h"
#include "floatfann.h"
#include "math.h"
#include"stdlib.h"
#include"stdio.h"
#include"string.h"

float sigmoid(float num)
{
	if(num<0.0)
		return 0.0;
	else
		return num;
}

float sigmoid2(float num)
{
	if(num>0.0)
		return 0.0;
	else
		return num;
}



int main()
{
    	fann_type *calc_out, prediction;
	fann_type ttr = 0;
   	printf("--------------------------------------------------------------------------------\n");
    	printf("--------------------------------------------------------------------------------\n");

    	printf("\nEnter the values for the following features of the cell nucleus, separated by spaces: \n");
    	printf("a) Radius (mean of distances from center to points on the perimeter)\nb) Texture (standard deviation of gray-scale values)\nc) Perimeter\nd) Area\ne) Smoothness (local variation in radius lengths)\nf) Compactness (perimeter^2 / area - 1.0)\ng) Concavity (severity of concave portions of the contour)\nh) Concave points (number of concave portions of the contour)\ni) Symmetry\nj) Fractal dimension (\"coastline approximation\" - 1)\n");
	float rad, text, per, area, smooth, comp, conc, conc_p, sym, fd;
	scanf("%f %f %f %f %f %f %f %f %f %f", &rad, &text, &per, &area, &smooth, &comp, &conc, &conc_p, &sym, &fd);
	printf("\nFor checking recurrence, enter the following information: \na)Worst case area\nb)Worst case concavity\nc)Worst case fractal dimension\nd)Diameter of the excised tumor in centimeters\ne)Number of metastasized lymph nodes\n");
	float size,warea,wconc,wfd,lymph;
	scanf("%f %f %f %f %f",&warea,&wconc,&wfd,&size,&lymph);
	
	fann_type input1[10]={rad, text, per, area, smooth, comp, conc, conc_p, sym, fd};
	//fann_type input2[6]={text, warea, wconc, wfd, size, lymph};
	fann_type input2[4]={text, warea, wconc, wfd};

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Prediction	

    	 
    	struct fann *ann = fann_create_from_file("prediction.net");
    
    	calc_out = fann_run(ann, input1);
    
	if(calc_out[0]<0)
		calc_out[0]=-calc_out[0];

	prediction = calc_out[0];

	fann_destroy(ann);
    	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Malignancy
	if(prediction > 0.8)
	{

		struct fann *ann2 = fann_create_from_file("malignancy2.net");
    
    		calc_out = fann_run(ann2, input2);

		ttr = calc_out[0];
		
		fann_destroy(ann2);

	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Printing

	if(prediction > 0.8)
	{
		printf("\nTumour is malignant. (Probability of malignancy: %f)\n",prediction);
		
		if(ttr>0.7)
		{
			printf("\nThere is a possibility of recurrence after the specified chemotherapy course. (Probability: %f)\n",ttr);
		}
		else if(ttr <0.3)
		{
		 	printf("\nThere is a very low possibility of recurrence after the specified chemotherapy course.(Probability: %f)\n",ttr);
		}
		else
		{
			printf("Recurrence uncertain. (Probability: %f)\n",ttr);
		}
	}
	else if (prediction < 0.3)
	{
		printf("\nTumour is benign. (Probability of malignancy: %f)\n",prediction);
	}
	else
	{
		printf("\nOutcome uncertain. More tests required. (Probability of malignancy: %f)\n",prediction);
	}

		
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Calculating malignancy factor to put into simulation.
	if(prediction > 0.8)
	{
		float factor = (90 * pow(2.71828,sigmoid2(2*prediction+ttr-2.2))) + (1.2*pow(sigmoid(size-2.7),.5)) + (1.4* pow(sigmoid(lymph-3),.5));
		if(factor>100.0)
			factor=100.0;	
		printf("\n\nRun simulation with malignancy factor: %f\n",factor);
	}
	printf("\n--------------------------------------------------------------------------------\n");
    	printf("--------------------------------------------------------------------------------\n");

return 0;
}

