#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int read_file(double x[14]) {
	ifstream in("Sourse_data.txt");
	if (in.is_open())
	{

		//read matrix from file
		for (int i = 0; i < 14; i++)
			in >> x[i];

		for (int i = 0; i < 14; i++)
		{
			cout << x[i] << "\t";
		}
		cout << endl << endl;
		in.close();
		return *x;
	}
	else
	{
				cout << "File not found";
	}
}

int expect_large_factory(double x[14], int *i, double first_result[2]) {
	double expect_large_factory;
	expect_large_factory = (x[1] * x[12] + x[3] * x[13]) * 4 - x[0];
	first_result[*i] = expect_large_factory;
	cout << "Expectation and Large factory: \t" << first_result[*i] << endl;
	*i = *i + 1;
	return 0;
}

int expect_small_factory(double x[14], int *i, double first_result[2]) {
	double expect_small_factory;
	expect_small_factory = (x[6] * x[12] + x[8] * x[13]) * 4 - x[5];
	first_result[*i] = expect_small_factory;
	cout << "Expectation and small factory \t" << first_result[*i] << endl;
	*i = *i + 1;
	return 0;
}

int better_expect(double first_result[2], double *max) {
	if (first_result[0] >= first_result[1])
		*max = first_result[0];
	else
		*max = first_result[1];
	return 0;
}

int Large_factory(double x[14], int *j, double result[3]) {
	double Large_factory;
	Large_factory = (x[6] * x[2] + x[3] * x[4]) * 5 - x[5];
	result[*j] = Large_factory;
	cout << "Large Factory: \t\t\t" << result[*j] << endl;
	*j = *j + 1;
	return 0;
}

int small_factory(double x[14], int *j, double result[3]) {
	double small_factory;
	small_factory = (x[1] * x[2] + x[8] * x[4]) * 5 - x[0];
	result[*j] = small_factory;
	cout << "Small Factory: \t\t" << result[*j] << endl;
	*j = *j + 1;
	return 0;
}

int Expect(double x[14], int *j, double result[3], double max) {
	double expect;
	expect = max + (x[10] * 0 * 1 + x[11] * 0 * 1) - 0;
	result[*j] = expect;
	cout << "Expectation: \t" << result[*j] << endl;
	*j = *j + 1;
	return 0;
}

int better_all(double result[3]) {
	double max = 0;
	for (int i = 0; i < 3; i++) {
		if (max < result[i])
			max = result[i];
	}
	cout << max << endl << endl;
	return 0;
}

void main()
{
	setlocale(LC_ALL, "Ukrainian");
	double x[14], first_result[2], result[3], max = 0;
	int i = 0, j = 0;

	read_file(x);
	expect_large_factory(x, &i, first_result);
	expect_small_factory(x, &i, first_result);
	Large_factory(x, &j, result);
	small_factory(x, &j, result);
	better_expect(first_result, &max);
	Expect(x, &j, result, max);
	cout << endl << "The most optimal solution to this problem is: ";
	better_all(result);

	system("pause");
}
