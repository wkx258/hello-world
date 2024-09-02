//
// pch.cpp
//

#include "pch.h"
#include "gtest/gtest.h"
#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>

double R0(double r1, double r2, double r3, double r4)
{double c = 0, d = 0, e = 0, f = 0, r0 = 0;
	
		c = (1 / r1) * (1 / r2) / ((1 / r1) + (1 / r2) + (1 / r3));
		d = (1 / r1) * (1 / r3) / ((1 / r1) + (1 / r2) + (1 / r3));
		e = (1 / r2) * (1 / r3) / ((1 / r1) + (1 / r2) + (1 / r3));
		f = d + e * r4 / (e + r4);
		return r0 = c * f / (c + f);

	}

	double R00(double r1, double r2, double r3, double r4)
	{
		double c = 0, d = 0, e = 0, f = 0, r0 = 0;
		c = r1 * r2 / (r1 + r2 + r3);
		d = r1 * r3 / (r1 + r2 + r3);
		e = r2 * r3 / (r1 + r2 + r3);
		f = (e + r4) * c / (e + r4 + c);
		return r0 = d + f;
	}
