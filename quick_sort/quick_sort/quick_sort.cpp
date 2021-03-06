// quick_sort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <vector>

using namespace std;

vector<int>& quickSort(vector<int>& unsorted) {;

	for (int i = 1; i < unsorted.size(); i++) {
		int elem = unsorted[i];
		int j = i;
		while (j >= 1 && elem < unsorted[j-1]) {
			int tmp = unsorted[j-1];
			unsorted[j-1] = elem;
			unsorted[j] = tmp;
			--j;
		}
	}
	return unsorted;
}

int main()
{
	vector<int> unsorted(20);
	for (auto& i : unsorted) {
		i = rand() % 20;
	}
	vector<int> sorted;

	cout << "unsorted: \n";
	cout << "<";
	for (auto& i : unsorted) {
		cout << " " << i;
	}
	cout <<" >\n\n";

	sorted = quickSort(unsorted);

	cout << "sorted: \n";
	cout << "< ";
	for (auto& i : sorted) {
		cout << " " << i;
	}
	cout << ">"<<endl;

	return 0;
}
