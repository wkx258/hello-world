#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
	double a,b=0,r1=0,r2=0,r3=0,r4=0,i=0;
	double c = 0, d = 0, e = 0, f = 0,r0=0;
	cout << "��ѡ��ͼ1����ͼ2" << endl;
	cin >> a;
	cout << "�������ѹ���ĸ��������ֵ" << endl;
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
	cout << "��ѹΪ" <<fixed<<setprecision(3)<<b <<"V"<< endl;
	cout << "����R1Ϊ" << fixed << setprecision(3) << r1<<"��"<< endl;
	cout << "����R2Ϊ" << fixed << setprecision(3) << r2 << "��" << endl;
	cout << "����R3Ϊ" << fixed << setprecision(3) << r3<< "��" << endl;
	cout << "����R4Ϊ" << fixed << setprecision(3) << r4<< "��" << endl;
	cout << "����Ϊ" << fixed << setprecision(3) << i<< "A" << endl;
	
	return 0;
}
