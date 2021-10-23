#include <stdio.h>
#include <math.h>
#include "define.h"
/*  *ptr_e,ptr_D,ptr_C3分别代表指向三种类型的指针
	* *dens[]代表三种粒子的密度
	*char_dens代表电荷密度		*/
void grid_pic(particle* prt_e, particle* ptr_D, particle* ptr_C3, int* numb, double(*dens)[Nz_plas], double* char_dens)
{
	int i;

	pic(prt_e, numb[0], qe, dens[0]);
	pic(ptr_D, numb[1], qi, dens[1]);
	pic(ptr_C3, numb[2], q_C3, dens[2]);
	for (i = 0; i < Nz_plas; i++)
		char_dens[i] = dens[0][i] + dens[1][i] + dens[2][i];
	for (i = 0; i < Nz_plas; i++)
	{
		/* 网格点电荷密度->网格点数密度 */
		dens[0][i] /= qe; 
		dens[1][i] /= qi;
		dens[2][i] /= q_C3;
		/* 最后一个网格的电子数密度 */
		if (i == Nz_plas - 1)
			printf("最后一个网格的电子数密度=%10.6e  \n", dens[0][i]);
	}
	stime();
}

/* 云分室法求解电荷密度 */
void pic(particle* ptr, int numb, double q, double* dens)
{
	int i, ip;
	double l1, l2;
	double q_real, z;

	/* 每个网格点电荷密度重置为0 */
	for (i = 0; i < Nz_plas; i++)
		dens[i] = 0.0;

	/* 网格点电荷密度->网格点电荷量 */
	for (i = 0; i < numb; i++)//遍历每个粒子
	{
		q_real = ptr[i].weig * q;//电荷量权重变换
		z = ptr[i].z;
		ip = (int)(z / dz_plas);//第i个粒子的位置
		l2 = z / dz_plas - ip;  //左半网格
		l1 = 1.0 - l2;		    //右半网格
		dens[ip] += q_real * l1;     //权重分配
		dens[ip + 1] += q_real * l2;  //权重分配
	}

	/* 网格点电荷量->网格点电荷密度 */
	for (i = 1; i < Nz_plas - 1; i++)       //遍历2-Nz_plas个网格
		dens[i] /= dz_plas;					//将网格点的电荷量平均到左右半个网格上
	dens[0] /= (0.5 * dz_plas);				//首个网格点的电荷量平均到右半网格上
	dens[Nz_plas - 1] /= (0.5 * dz_plas);	//最后一个网格点的电荷量平均到左半网格上
}