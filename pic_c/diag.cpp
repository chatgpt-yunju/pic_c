#include "define.h"
#include <stdio.h>
#include <math.h>
void diag(void)
{
	double vD;                     //氘离子热速度
	double lamd_e, lamd_D;
	double w_pe, peri_e;
	double wpe_dt, vdt_dz;
	
	//离子温度Ti=20,离子电荷qi=1.6021865314e-19;氘质量m_D=3.348e-27;
	vD = sqrt(2.0 * Ti * qi / m_D);	//氘离子热速度,离子温度Ti=20,离子电荷qi=1.6021865314e-19;
	//printf("%lf \n", vD); stime();

	//电子质量me=9.1093897e-31;	 ve=sqrt(-2.0*qe*Te/me);sqrt(2.0*qe*Te/me);  电子电荷qe=-1.6021865314e-19;  磁场B0=5.3;
	lamd_e = me * ve / fabs(qe * B0);//电子回旋半径

	lamd_D = m_D * vD / fabs(qi * B0);//氘离子回旋半径
	
	//Ne=1e19;电子数密度  //真空介电常数eps0=8.854187817e-12;
	w_pe = sqrt(Ne * qe * qe / (eps0 * me));//电子震荡频率
	//printf("电子回旋半径%lf \n", lamd_e); 
	//printf("氘离子回旋半径%lf \n", lamd_D); 
	//printf("电子震荡频率%lf \n", w_pe); stime();

	//dt=1.0e-12;时间步长  //dz_plas=lz_plas/double(Nz_plas-1);z方向空间步长
	peri_e = 2.0 * pi / w_pe; //电子震荡周期周期T=2π/ω
	wpe_dt = w_pe * dt;    
	vdt_dz = ve * dt / dz_plas;
	printf("ne=%10.6e,Te=%10.6f\n", Ne, Te);
	printf("ve=%10.6e,v_D=%10.6e\n", ve, vD);
	printf("德拜长度=%10.6e,空间步长=%10.6e\n", deby_leng, dz_plas);
	printf("电子振荡周期=%10.6e,时间步长=%10.6e\n", peri_e, dt);
	printf("wpe*dt=%10.6f,v*dt/dz=%10.6f\n", wpe_dt, vdt_dz);

}
