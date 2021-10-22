#include <stdlib.h>
#include <math.h>
#include "define.h"
#include<stdio.h>
/* James Joseph Szabo.Fully Kinetic Numerical Modeling of a Plasma Thruster.2011,p149 */

void maxw(double* vx, double* vy, double* vz, double kt, double mass)
{
	double ran1, vt, v;
	double theta, psi;

	/* 粒子热速度 */
	vt = sqrt(2.0 * kt * qi / mass);//kt粒子温度，qi离子电荷，mass粒子质量
	//printf("电子热速度%f \n", vt); 

	ran1 = rand() / (double)RAND_MAX;//产生0-1之间的随机数
	v = vt * sqrt(-log(ran1));
	//ran1 = rand() / (double)RAND_MAX;
	//theta = 2.0 * pi * ran1;
	//ran1 = rand() / (double)RAND_MAX;
	//psi = 2.0 * pi * ran1;

	//*vx = v * sin(theta);
	//*vy = v * cos(theta);
	//*vz = v * sin(psi);
}