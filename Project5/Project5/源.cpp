#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
	double a,b=0,r1=0,r2=0,r3=0,r4=0,i=0;
	double c = 0, d = 0, e = 0, f = 0,r0=0;
	cout << "请选择图1或者图2" << endl;
	cin >> a;
	cout << "请输入电压和四个电阻的阻值" << endl;
	cin >> b>>r1>>r2>>r3>>r4;
	if (a == 1)
	{
		c = (1 / r1) * (1 / r2) / ((1 / r1) + (1 / r2) + (1 / r3));
		d= (1 / r1) * (1 / r3) / ((1 / r1) + (1 / r2) + (1 / r3));
		e=(1 / r2) * (1 / r3) / ((1 / r1) + (1 / r2) + (1 / r3));
		f = d + e * r4 / (e + r4);
		r0 = c * f / (c + f);
	}
	
	if (a == 2)
	{
		c = r1 * r2 / (r1 + r2 + r3);
		d = r1 * r3 / (r1 + r2 + r3);
		e = r2 * r3 / (r1 + r2 + r3);
		f = (e + r4) * c / (e + r4 + c);
		r0 = d + f;
	}
	i = b / r0;
	cout << "电压为" <<fixed<<setprecision(3)<<b <<"V"<< endl;
	cout << "电阻R1为" << fixed << setprecision(3) << r1<<"Ω"<< endl;
	cout << "电阻R2为" << fixed << setprecision(3) << r2 << "Ω" << endl;
	cout << "电阻R3为" << fixed << setprecision(3) << r3<< "Ω" << endl;
	cout << "电阻R4为" << fixed << setprecision(3) << r4<< "Ω" << endl;
	cout << "电流为" << fixed << setprecision(3) << i<< "A" << endl;
	
	return 0;
}
