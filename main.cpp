#include <iostream>
#include "psz_limits.h"
#include "psz_vec2.h"
using namespace std;
int main()
{
	psz::Vec2 v(-50, 20);

	psz::setClamp(v, 0, 10);

	cout << "x: " << v.x << ", y: " << v.y << endl;
}