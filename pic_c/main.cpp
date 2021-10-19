#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "define.h"
#define NUMBMAX 3000000					
#define WRITSPACSTEP 1			//空间每隔多少步写入
#define SIMUSTEP 25000			//模拟总步数
#define SHOWSTEP 500			//时间上每隔多少步求平均值
#define SHOWNUMB 13

#include <iostream>

int main()
{
    //std::cout << "Hello World!  \n";
    static particle part_e[NUMBMAX], part_D[NUMBMAX], part_C3[NUMBMAX];			//三种模拟粒子
    int numb_edc[3];															//存放三种粒子的粒子数
	double dens[3][Nz_plas];//Nz_plas = 1001; z方向网格数    					//存放三种粒子在各格点的密度
	double char_dens[Nz_plas], pote[Nz_plas], fiel[Nz_plas];					//存放各格点的电荷密度、电势、电场
	double flux[3][2], ener_flux[3][2], flux_aver[3][2], ener_flux_aver[3][2]; //3种粒子，2个边界  //统计入射到边界的粒子流及能流
	//fp_init=fopen("intial.dat","w");  判断文件是否存在，存在则删除新建
	//fp_aver=fopen("aver.dat","w");
	//fp_flux_aver=fopen("flux_aver.dat","w");
	//fp_ener_flux_aver=fopen("ener_flux_aver.dat","w");
	//	fp_dura=fopen("duration.dat","w");
	FILE* fp_init, * fp_aver, * fp_flux_aver, * fp_ener_flux_aver, * fp_dura;
	double dens_aver[3][Nz_plas], char_dens_aver[Nz_plas], pote_aver[Nz_plas], fiel_aver[Nz_plas]; //存放平均值
	int i, j, k;
	//fp_who[0] = fopen("1ns.dat", "w");
	//fp_who[1] = fopen("2ns.dat", "w");
	//fp_who[2] = fopen("3ns.dat", "w");
	//fp_who[3] = fopen("5ns.dat", "w");
	//fp_who[4] = fopen("7ns.dat", "w");
	//fp_who[5] = fopen("10ns.dat", "w");
	//fp_who[6] = fopen("15ns.dat", "w");
	//fp_who[7] = fopen("25ns.dat", "w");
	//fp_who[8] = fopen("35ns.dat", "w");
	//fp_who[9] = fopen("45ns.dat", "w");
	//fp_who[10] = fopen("60ns.dat", "w");
	//fp_who[11] = fopen("80ns.dat", "w");
	//fp_who[12] = fopen("100ns.dat", "w");
	FILE* fp_who[SHOWNUMB]; //文件数组
	int show_who[SHOWNUMB] = { 1000,2000,3000,5000,7000,10000,15000,25000,35000,45000,60000,80000,100000 };
	//clock() 计算函数的执行时间
	clock_t star, fini;
	int hour, minu;
	star = clock();
    //printf("%d \n",numb_edc[0]);
    //printf("%d \n",numb_edc[1]);
    //printf("%d \n",numb_edc[2]);



}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
