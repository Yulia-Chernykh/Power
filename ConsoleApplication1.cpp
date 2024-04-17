
#include <iostream>
#include <math.h>
using namespace std;

int main()
{ 
	setlocale(LC_ALL, "RU");
	float t, k, Hq, Hs, D, L, d, V, H, hl, hm, U;
	cout << "Введите данные о насосе: длину, диаметр, суточное потребление " << endl;
	cin >> L >> d >> V;
	cout << "Обозначьте время работы насоса в сутки" << endl;
	cin >> t;
	cout << "Введите следующие данные для рассчета: геодезическую высоту, свободный напор" << endl;
	cin >> Hq >> Hs;
	cout << "Введите значения коэффициентов: КПД, коэффициент Дарси" << endl;
	cin >> k >> D;

	float Q = V / (3600 * t);
	U = 1.27 * (Q / pow(d, 2));
	hl = D * (L / d) * (pow(U, 2) / 19.6);
	hm = 0.1 * hl;
	H = Hq + hl + hm + Hs;

	float N = (9.81 * Q * H) / k;
		cout << "Мощность насоса: " << N << endl;
}
