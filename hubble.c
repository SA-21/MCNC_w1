#include <stdio.h>
#define theta0 0
#define n 0.1

double f_x(double theta1, double x);

double f_theta(double* ax, double* ay, double theta1);

int main()
{
	double ax[6] = { 90, 110, 95, 135, 150, 155 };
	double ay[6] = { 0.7, 0.69, 0.85, 1, 0.95, 1.1 };
	double theta1 = 0.01;
	double temp = 0;
	int i = 0;
	double sigma = 0;

	for (i = 0; i < 1000; i++)
	{
		temp = theta1 - n * f_theta(ax, ay, theta1);
		theta1 = temp;
		printf("%lf\n", theta1);
	}

	return 0;

}

double f_x(double x, double theta1) {
	return theta0 + theta1 * x;
}

double f_theta(double* ax, double* ay, double theta1) {
	double sum = 0;
	int i = 0;

	for (i = 0; i < 6; i++) {
		sum += (f_x(ax[i], theta1) - ay[i]) * ax[i];
	}
	return sum;
}
