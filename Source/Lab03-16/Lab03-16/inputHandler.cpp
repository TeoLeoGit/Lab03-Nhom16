#include "inputHandler.h"


void runCommand(int argc, char* argv[]) {

	if (argc > 1) {
		if (argc > 4 && argc < 7) {

			if (strcmp(argv[1], "-a") == 0) {
				//cout << "ALGORITHM MODE" << endl;
			}
			else if (strcmp(argv[1], "-c") == 0)
				cout << "Compare mode";		
			//if argv[4] is a number --> command 2 or 3.
			long dataSize = strtol(argv[3], &argv[3], 10);

			if (dataSize > 0) {		
				//Case: command 3
				if (argc == 5) {
					execCommand3(argv[2], dataSize, argv[4]);
				} 
				//Command 2
				else {
					execCommand2(argv[2], dataSize, argv[4], argv[5]);
				}
			}
			//Command 1
			else {
				cout << "input file: " << argv[3] << endl;
				
			}

		}
		else {
			cout << "Cannot find prototype for your command." << endl;
		}	
	}
}

void execCommand2(char* algorithm, long size, char* order, char* outParameter) {
	if (size < 0 || size > 500000) {
		cout << "Invalid size" << endl;
		return;
	}
	int* data = new int[size];

	//generate data
	if (strcmp(order, "-rand") == 0) {
		GenerateData(data, size, 0);
	}
	else if (strcmp(order, "-nsorted") == 0) {
		GenerateData(data, size, 3);
	}
	else if (strcmp(order, "-sorted") == 0) {
		GenerateData(data, size, 1);
	}
	else if (strcmp(order, "-rev") == 0) {
		GenerateData(data, size, 2);
	}
	else {
		cout << "Invalid data order!" << endl;
		return;
	}

	//output set
	int doPrintTime = 0;
	int doPrintComp = 0;
	if (strcmp(outParameter, "-time") == 0) {
		doPrintTime++;
	}
	else if (strcmp(outParameter, "-comp") == 0) {
		doPrintComp++;
	}
	else if (strcmp(outParameter, "-both") == 0) {
		doPrintComp++;
		doPrintTime++;
	}

	//Printing arguments
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << algorithm << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: " << order << endl;
	cout << "--------------------------------------" << endl;

	//Writing generated data to output.txt
	ofstream outFile;
	outFile.open("input.txt");
	outFile << size << "\n";
	for (int i = 0; i < size; i++)
		outFile << data[i] << " ";
	outFile.close();

	//sort the array
	long long count_comp = 0;
	if (strcmp(algorithm, "selection-sort") == 0) {
		auto begin = clock();
		selectionSort(data, size, count_comp);
		double timeUsed = ((double)clock() - begin);
		if (doPrintTime)
			cout << "Running time: " << timeUsed << "ms" << endl;
		if (doPrintComp)
			cout << "Comparisons: " << count_comp << endl;
	}
	else if (strcmp(algorithm, "binary-insertion-sort") == 0) {
		auto begin = clock();
		insertionSort(data, size, count_comp);
		double timeUsed = ((double)clock() - begin);
		if (doPrintTime)
			cout << "Running time: " << timeUsed << "ms" << endl;
		if (doPrintComp)
			cout << "Comparisons: " << count_comp << endl;
	}
	else if (strcmp(algorithm, "bubble-sort") == 0) {
		auto begin = clock();
		bubbleSort(data, size, count_comp);
		double timeUsed = ((double)clock() - begin);
		if (doPrintTime)
			cout << "Running time: " << timeUsed << "ms" << endl;
		if (doPrintComp)
			cout << "Comparisons: " << count_comp << endl;
	}
	else if (strcmp(algorithm, "shaker-sort") == 0) {
		auto begin = clock();
		shakerSort(data, size, count_comp);
		double timeUsed = ((double)clock() - begin);
		if (doPrintTime)
			cout << "Running time: " << timeUsed << "ms" << endl;
		if (doPrintComp)
			cout << "Comparisons: " << count_comp << endl;
	}
	else if (strcmp(algorithm, "shell-sort") == 0) {
		auto begin = clock();
		shellSort(data, size, count_comp);
		double timeUsed = ((double)clock() - begin);
		if (doPrintTime)
			cout << "Running time: " << timeUsed << "ms" << endl;
		if (doPrintComp)
			cout << "Comparisons: " << count_comp << endl;
	}
	else if (strcmp(algorithm, "heap-sort") == 0) {
		auto begin = clock();
		heapSort(data, size, count_comp);
		double timeUsed = ((double)clock() - begin);
		if (doPrintTime)
			cout << "Running time: " << timeUsed << "ms" << endl;
		if (doPrintComp)
			cout << "Comparisons: " << count_comp << endl;
	}
	else if (strcmp(algorithm, "merge-sort") == 0) {
		auto begin = clock();
		mergeSort(data, 0, size - 1, count_comp);
		double timeUsed = ((double)clock() - begin);
		if (doPrintTime)
			cout << "Running time: " << timeUsed << "ms" << endl;
		if (doPrintComp)
			cout << "Comparisons: " << count_comp << endl;
	}
	else if (strcmp(algorithm, "quick-sort") == 0) {
		auto begin = clock();
		quickSort(data, 0, size - 1, count_comp);
		double timeUsed = ((double)clock() - begin);
		if (doPrintTime)
			cout << "Running time: " << timeUsed << "ms" << endl;
		if (doPrintComp)
			cout << "Comparisons: " << count_comp << endl;
	}
	else if (strcmp(algorithm, "counting-sort") == 0) {
		auto begin = clock();
		countingSort(data, size, count_comp);
		double timeUsed = ((double)clock() - begin);
		if (doPrintTime)
			cout << "Running time: " << timeUsed << "ms" << endl;
		if (doPrintComp)
			cout << "Comparisons: " << count_comp << endl;
	}
	else if (strcmp(algorithm, "radix-sort") == 0) {
		auto begin = clock();
		radixSort(data, size, count_comp);
		double timeUsed = ((double)clock() - begin);
		if (doPrintTime)
			cout << "Running time: " << timeUsed << "ms" << endl;
		if (doPrintComp)
			cout << "Comparisons: " << count_comp << endl;
	}
	else if (strcmp(algorithm, "flash-sort") == 0) {
		auto begin = clock();
		flashSort(data, size, count_comp);
		double timeUsed = ((double)clock() - begin);
		if (doPrintTime)
			cout << "Running time: " << timeUsed << "ms" << endl;
		if (doPrintComp)
			cout << "Comparisons: " << count_comp << endl;
	}

	//writing sorted array to input.txt
	ofstream sortedInputFile;
	sortedInputFile.open("output.txt");
	sortedInputFile << size << "\n";
	for (int i = 0; i < size; i++)
		sortedInputFile << data[i] << " ";
	sortedInputFile.close();
}


//Command 3
void execCommand3(char* algorithm, long size, char* outParameter) {
	if (size < 0 || size > 500000) {
		cout << "Invalid size" << endl;
		return;
	}


	// generate data
	int** data = new int* [4];
	for (int i = 0; i < 4; ++i) {
		data[i] = new int[size];
		GenerateData(data[i], size, i);
	}

	
	//output set
	int doPrintTime = 0;
	int doPrintComp = 0;
	if (strcmp(outParameter, "-time") == 0) {
		doPrintTime++;
	}
	else if (strcmp(outParameter, "-comp") == 0) {
		doPrintComp++;
	}
	else if (strcmp(outParameter, "-both") == 0) {
		doPrintComp++;
		doPrintTime++;
	}

	//Printing arguments
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << algorithm << endl;
	cout << "Input size: " << size;

	//Writing generated data to output.txt
	ofstream outputFile1;
	ofstream outputFile2;
	ofstream outputFile3;
	ofstream outputFile4;

	outputFile1.open("input_1.txt");
	outputFile2.open("input_2.txt");
	outputFile3.open("input_3.txt");
	outputFile4.open("input_4.txt");

	outputFile1 << size << "\n";
	outputFile2 << size << "\n";
	outputFile3 << size << "\n";
	outputFile4 << size << "\n";

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < size; j++) {
			outputFile1 << data[i][j] << " ";
			outputFile3 << data[i][j] << " ";
			outputFile4 << data[i][j] << " ";
			outputFile2 << data[i][j] << " ";
	}
	outputFile1.close();
	outputFile2.close();
	outputFile3.close();
	outputFile4.close();

	//sort the array
	for (int i = 0; i < 4; i++) {
		switch (i)
		{
		case 0:
			cout << endl << "Input order: Randomize" << endl;
			cout << "-------------------------" << endl;
			break;
		case 1:
			cout << endl << "Input order: Sorted" << endl;
			cout << "-------------------------" << endl;
			break;
		case 2:
			cout << endl << "Input order: Reversed" << endl;
			cout << "-------------------------" << endl;
			break;
		case 3:
			cout << endl << "Input order: Nearly Sorted" << endl;
			cout << "-------------------------" << endl;
			break;
		};

		long long count_comp = 0;
		if (strcmp(algorithm, "selection-sort") == 0) {
			auto begin = clock();
			selectionSort(data[i], size, count_comp);
			double timeUsed = ((double)clock() - begin);
			if (doPrintTime)
				cout << "Running time: " << timeUsed << "ms" << endl;
			if (doPrintComp)
				cout << "Comparisons: " << count_comp << endl;
		}
		else if (strcmp(algorithm, "binary-insertion-sort") == 0) {
			auto begin = clock();
			insertionSort(data[i], size, count_comp);
			double timeUsed = ((double)clock() - begin);
			if (doPrintTime)
				cout << "Running time: " << timeUsed << "ms" << endl;
			if (doPrintComp)
				cout << "Comparisons: " << count_comp << endl;
		}
		else if (strcmp(algorithm, "bubble-sort") == 0) {
			auto begin = clock();
			bubbleSort(data[i], size, count_comp);
			double timeUsed = ((double)clock() - begin);
			if (doPrintTime)
				cout << "Running time: " << timeUsed << "ms" << endl;
			if (doPrintComp)
				cout << "Comparisons: " << count_comp << endl;
		}
		else if (strcmp(algorithm, "shaker-sort") == 0) {
			auto begin = clock();
			shakerSort(data[i], size, count_comp);
			double timeUsed = ((double)clock() - begin);
			if (doPrintTime)
				cout << "Running time: " << timeUsed << "ms" << endl;
			if (doPrintComp)
				cout << "Comparisons: " << count_comp << endl;
		}
		else if (strcmp(algorithm, "shell-sort") == 0) {
			auto begin = clock();
			shellSort(data[i], size, count_comp);
			double timeUsed = ((double)clock() - begin);
			if (doPrintTime)
				cout << "Running time: " << timeUsed << "ms" << endl;
			if (doPrintComp)
				cout << "Comparisons: " << count_comp << endl;
		}
		else if (strcmp(algorithm, "heap-sort") == 0) {
			auto begin = clock();
			heapSort(data[i], size, count_comp);
			double timeUsed = ((double)clock() - begin);
			if (doPrintTime)
				cout << "Running time: " << timeUsed << "ms" << endl;
			if (doPrintComp)
				cout << "Comparisons: " << count_comp << endl;
		}
		else if (strcmp(algorithm, "merge-sort") == 0) {
			auto begin = clock();
			mergeSort(data[i], 0, size - 1, count_comp);
			double timeUsed = ((double)clock() - begin);
			if (doPrintTime)
				cout << "Running time: " << timeUsed << "ms" << endl;
			if (doPrintComp)
				cout << "Comparisons: " << count_comp << endl;
		}
		else if (strcmp(algorithm, "quick-sort") == 0) {
			auto begin = clock();
			quickSort(data[i], 0, size - 1, count_comp);
			double timeUsed = ((double)clock() - begin);
			if (doPrintTime)
				cout << "Running time: " << timeUsed << "ms" << endl;
			if (doPrintComp)
				cout << "Comparisons: " << count_comp << endl;
		}
		else if (strcmp(algorithm, "counting-sort") == 0) {
			auto begin = clock();
			countingSort(data[i], size, count_comp);
			double timeUsed = ((double)clock() - begin);
			if (doPrintTime)
				cout << "Running time: " << timeUsed << "ms" << endl;
			if (doPrintComp)
				cout << "Comparisons: " << count_comp << endl;
		}
		else if (strcmp(algorithm, "radix-sort") == 0) {
			auto begin = clock();
			radixSort(data[i], size, count_comp);
			double timeUsed = ((double)clock() - begin);
			if (doPrintTime)
				cout << "Running time: " << timeUsed << "ms" << endl;
			if (doPrintComp)
				cout << "Comparisons: " << count_comp << endl;
		}
		else if (strcmp(algorithm, "flash-sort") == 0) {
			auto begin = clock();
			flashSort(data[i], size, count_comp);
			double timeUsed = ((double)clock() - begin);
			if (doPrintTime)
				cout << "Running time: " << timeUsed << "ms" << endl;
			if (doPrintComp)
				cout << "Comparisons: " << count_comp << endl;
		}
	}

}

