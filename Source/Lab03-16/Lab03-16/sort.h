#pragma once
#include<iostream>

using namespace std;

void selectionSort(int* a, int n, long long& count_comp);
void insertionSort(int* a, int n);
void bubbleSort(int* a, int n);
void shakerSort(int* a, int n);
void shellSort(int* a, int n);
// Heap sort
void heapify(int* a, int n, int i);
void heapSort(int* a, int n);
// Merge sort
void merge(int a[], int left, int mid, int right);
void mergeSort(int* a, int left, int right);
// Quick sort
int partition(int* a, int low, int high);
void quickSort(int* a, int low, int high);
void countingSort(int* a, int n);
// Radix sort
int getMax(int* a, int n);
void countSort(int* a, int n, int exp);
void radixSort(int* a, int n);
void flashSort(int* a, int n);