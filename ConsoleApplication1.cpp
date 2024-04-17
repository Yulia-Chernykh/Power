
#include <iostream>
#include <math.h>
using namespace std;

int main()
{ 
	setlocale(LC_ALL, "RU");
	float t, k, Hq, Hs, D, L, d, V, H, hl, hm, U,S,n,Vo,Vh;
	cout << "Введите данные о насосе: длину, диаметр" << endl;
	cin >> L >> d;
	cout << "Обозначьте время работы насоса в сутки" << endl;
	cin >> t;
	cout << "Введите следующие данные для рассчета: геодезическую высоту, свободный напор" << endl;
	cin >> Hq >> Hs;
	cout << "Введите значения коэффициентов: КПД" << endl;
	cin >> k;
	cout<< "Введите площадь использованного участка" << endl;
	cin >> S;
	cout << "Введите кол-во человек" << endl;
	cin >> n;

	Vo = 0.5 * S;
	Vh = 0.2 * n;
	V = Vo + Vh;
	float Re = (U * d) / 0.01;
	if (Re >= 2300) { cout << "Используется турбулентная система/n"; D = 0.3 / (pow(Re,1/4)); } 
		else { cout << "Используется ламинарная система/n"; D = 56 / Re; }
	float Q = V / (3600 * t);
	U = 1.27 * (Q / pow(d, 2));
	hl = D * (L / d) * (pow(U, 2) / 19.6);
	hm = 0.1 * hl;
	H = Hq + hl + hm + Hs;

	float N = (9.81 * Q * H) / k;
		cout << "Мощность насоса: " << N << endl;
}
