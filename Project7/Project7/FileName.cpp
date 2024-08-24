#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <map>
using namespace std;

std::map<std::string, void (*)(std::string&)> available_functions;

void print_hello(std::string& output) {
	std::cout << "Hello, " << output << std::endl;
}

void add_function(const std::string& name, void (*func)(std::string&)) {
	available_functions[name] = func;
}

void call_function(const std::string& name, std::string& input) {
	if (available_functions.find(name) != available_functions.end()) {
		available_functions[name](input);
	}
	else {
		std::cout << "Function not found: " << name << std::endl;
	}
}
int main()
{


	double a, b = 0, r1 = 0, r2 = 0, r3 = 0, r4 = 0, i = 0;
	double c = 0, d = 0, e = 0, f = 0, r0 = 0;
	cout << "请选择图1或者图2" << endl;
	cin >> a;

	if (a == 1)
	{
		cout << "请输入电压和四个电阻的阻值" << endl;
		cin >> b >> r1 >> r2 >> r3 >> r4;
		c = (1 / r1) * (1 / r2) / ((1 / r1) + (1 / r2) + (1 / r3));
		d = (1 / r1) * (1 / r3) / ((1 / r1) + (1 / r2) + (1 / r3));
		e = (1 / r2) * (1 / r3) / ((1 / r1) + (1 / r2) + (1 / r3));
		f = d + e * r4 / (e + r4);
		r0 = c * f / (c + f);
		i = b / r0;
		if (b > 0 && r1 > 0 && r2 > 0 && r3 > 0 && r4 > 0)
		{
			cout << "电压为" << fixed << setprecision(3) << b << "V" << endl;
			cout << "电阻R1为" << fixed << setprecision(3) << r1 << "Ω" << endl;
			cout << "电阻R2为" << fixed << setprecision(3) << r2 << "Ω" << endl;
			cout << "电阻R3为" << fixed << setprecision(3) << r3 << "Ω" << endl;
			cout << "电阻R4为" << fixed << setprecision(3) << r4 << "Ω" << endl;
			cout << "电流为" << fixed << setprecision(3) << i << "A" << endl;
		}
		else
		{
			cout << "您输入了无法识别的数" << endl;
		}

	}

	else if (a == 2)
	{
		cout << "请输入电压和四个电阻的阻值" << endl;
		cin >> b >> r1 >> r2 >> r3 >> r4;
		c = r1 * r2 / (r1 + r2 + r3);
		d = r1 * r3 / (r1 + r2 + r3);
		e = r2 * r3 / (r1 + r2 + r3);
		f = (e + r4) * c / (e + r4 + c);
		r0 = d + f;
		i = b / r0;
		if (b > 0 && r1 > 0 && r2 > 0 && r3 > 0 && r4 > 0)
		{
			cout << "电压为" << fixed << setprecision(3) << b << "V" << endl;
			cout << "电阻R1为" << fixed << setprecision(3) << r1 << "Ω" << endl;
			cout << "电阻R2为" << fixed << setprecision(3) << r2 << "Ω" << endl;
			cout << "电阻R3为" << fixed << setprecision(3) << r3 << "Ω" << endl;
			cout << "电阻R4为" << fixed << setprecision(3) << r4 << "Ω" << endl;
			cout << "电流为" << fixed << setprecision(3) << i << "A" << endl;
		}
		else
		{
			cout << "您输入了无法识别的数" << endl;
		}
	}
	else
	{
		cout << "您选择了未定义的模型，请重新输入数字 1 或 2" << endl;
	}
	add_function("print_hello", print_hello);

	std::string input;
	std::cout << "输入附加功能的名称 ";
	std::cin >> input;

	call_function(input, input);
	return 0;
}