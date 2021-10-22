#include <stdio.h>
#include "define.h"
#include <stdlib.h>

/* 坐标变换 Michael Komm,Interakce plazmatu se stenou tokamaku,2007,pp49 */
void init(particle* ptr_e, particle* ptr_D, particle* ptr_C3)
{
	double dz_e, dz_D, dz_C3;
	double vx, vy, vz;
	double v_para, v_ver1, v_ver2;
	int i;

	vx = 0.0;
	vy = 0.0;
	vz = 0.0;

	/* 离子间距 */
	dz_e = lz_plas / (numb_e + 1);			//均匀放置粒子,不在边界放置粒子
	dz_D = lz_plas / (numb_D + 1);
	dz_C3 = lz_plas / (numb_C3 + 1);

	/* 初始化电子 */
	for (i = 0; i < numb_e; i++)
	{
		maxw(&vx, &vy, &vz, Te, me);
		//printf("电子震荡频率%lf \n", vt);

		//ptr_e[i].z = dz_e * (i + 1);
		//ptr_e[i].vx = vx;
		//ptr_e[i].vy = vy;
		//ptr_e[i].vz = vz;
		//ptr_e[i].ener = 0.5 * (vx * vx + vy * vy + vz * vz) * me / qi;
		//ptr_e[i].weig = weig_e;
		//if (i == numb_e - 1)
		//	printf("z_e=%10.6e,", ptr_e[i].z);
	}
	//printf("(double)RAND_MAX %lf \n", (double)RAND_MAX);
	//printf("rand() %lf \n", rand()); 
	//printf("rand()/(double)RAND_MAX %lf %lf \n", rand()/(double)RAND_MAX); stime();
	printf("rand()/(double)RAND_MAX %lf  \n", rand()/(double)RAND_MAX); 
	printf("log(ran1) %lf  \n", log(rand() / (double)RAND_MAX));
	printf("sqrt(-log(ran1)) %lf  \n", sqrt(-log(rand() / (double)RAND_MAX)));
	stime();
	

	///* 初始化氘离子 */
	//for (i = 0; i < numb_D; i++)
	//{

	//	/*   存在定向速度的情况
	//	maxw(&v_para,&v_ver1,&v_ver2,Ti,m_D);
	//	vx=(v_para-vb_D)*bx-(v_ver1*by+v_ver2*bx*bz)/sqrt(bx*bx+by*by);		//坐标系变换
	//	vy=(v_para-vb_D)*by+(v_ver1*bx-v_ver2*by*bz)/sqrt(bx*bx+by*by);
	//	vz=(v_para-vb_D)*bz+v_ver2*sqrt(bx*bx+by*by);  */
	//	maxw(&vx, &vy, &vz, Ti, m_D);
	//	ptr_D[i].z = dz_D * (i + 1);
	//	ptr_D[i].vx = vx;
	//	ptr_D[i].vy = vy;
	//	ptr_D[i].vz = vz;
	//	ptr_D[i].ener = 0.5 * (vx * vx + vy * vy + vz * vz) * m_D / qi;
	//	ptr_D[i].weig = weig_D;
	//	if (i == numb_D - 1)
	//		printf("z_D=%10.6e,", ptr_D[i].z);
	//}
	///* 初始化C3+离子 */
	//for (i = 0; i < numb_C3; i++)
	//{
	//	/*  存在磁场及定向速度
	//	maxw(&v_para,&v_ver1,&v_ver2,Tc,m_C);
	//	vx=(v_para-vb_C)*bx-(v_ver1*by+v_ver2*bx*bz)/sqrt(bx*bx+by*by);		//坐标系变换
	//	vy=(v_para-vb_C)*by+(v_ver1*bx-v_ver2*by*bz)/sqrt(bx*bx+by*by);
	//	vz=(v_para-vb_C)*bz+v_ver2*sqrt(bx*bx+by*by);  */
	//	maxw(&vx, &vy, &vz, Tc, m_C);
	//	ptr_C3[i].z = dz_C3 * (i + 1);
	//	ptr_C3[i].vx = vx;
	//	ptr_C3[i].vy = vy;
	//	ptr_C3[i].vz = vz;
	//	ptr_C3[i].ener = 0.5 * (vx * vx + vy * vy + vz * vz) * m_C / qi;
	//	ptr_C3[i].weig = weig_C3;
	//	if (i == numb_C3 - 1)
	//		printf("z_C3=%10.6e\n", ptr_C3[i].z);
	//}

}