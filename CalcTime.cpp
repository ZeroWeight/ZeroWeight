#include <cmath> //math.h
#include<iostream>
using namespace std;

static const double A_max = 5.0;//the max. acc. of the vehicle
static const double A_max_ = 3.0;//the max. dec. of the vehicle
static const double V_min = 10.0;//the min. vec. of the vehicle
static const double V_max = 20.0;//the max ....

inline double CalMaxTime(double pos, double vec) {
	//dec. to the min. vec.
	//keep the max vec till aim
	//
	//pos>0 vec>0
	double time;
	double pos_cri= (vec*vec - V_min*V_min) / (2 * A_max_);
	if (pos <= pos_cri)
	{
		double vec_ = sqrt(vec*vec - 2 * A_max_*pos);//vec at the terminal
		time = (vec - vec_) / A_max_;
	}
	else
	{
		double time1= (vec - V_min) / A_max_;
		double time2 = (pos - pos_cri) / V_min;
		time = time1 + time2;
	}
	return time;
}


inline double CalMinTime(double pos, double vec) {
	double time;
	double pos_cri = (V_max*V_max - vec*vec ) / (2 * A_max);
	if (pos <= pos_cri)
	{
		double vec_ = sqrt(vec*vec + 2 * A_max*pos);//vec at the terminal
		time = (vec_ - vec) / A_max;
	}
	else
	{
		double time1 = (V_max - vec) / A_max;
		double time2 = (pos-pos_cri) / V_max;
		time = time1 + time2;
	}
	return time;
}


int main()
{
	cout << CalMaxTime(10, 15) << endl;
	cout << CalMaxTime(30, 15) << endl;
	cout << CalMinTime(10, 15) << endl;
	cout << CalMinTime(30, 15) << endl;
	system("pause");
}

