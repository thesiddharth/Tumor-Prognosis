4 folders have been provided -

A) Artificial Neural Network code - contains code for
	i) Creating and training the cancer prediction network (compile and build by "make -f make_pred", execute by ./EXE1).
	ii) Creating and training the malignancy and recurrence prediction module  (compile and build by "make -f make_mal", execute by ./EXE2).
	iii) Driver file (malignancy_test.c) will take in relevant user input and predict whether the tumour detected is benign or malignant and whether recurrence after a specific (assumed) amount of chemotherapy is possible. It generates a malignancy factor to be fed into the multi-agent modelling evironment (compile by "make", execute by ./EXE)
Comments: The Fast Artificial Neural Network Library (FANN) is included under the support software folder.
	  Prediction based on 10 characteristics is working perfectly.
	  However, recurrence, as should be expected, is less well defined in real life. With no clear cut parameters, it is much harder to predict. In addition, only 250 instances of data were available. The recurrence prediction therefore gives correct output with some limitations.


B) Multi Agent Modelling code - contains NetLogo code for simulation and limited swarm intelligence. Both the executable .nlogo file as well as a .txt file of the code have been included.

C) Support code and information - contains the original data and a helper function that was used to format the data in the necessary way.
   The data can be found here: ftp://ftp.cs.wisc.edu/math-prog/cpo-dataset/machine-learn/cancer/

D) Support Software - The FANN source code is included. For installation instructions: http://leenissen.dk/fann/wp/help/installing-fann/
   NetLogo can be downloaded here: http://ccl.northwestern.edu/netlogo/
