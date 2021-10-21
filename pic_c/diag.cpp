#include "define.h"
#include <stdio.h>
#include <math.h>
void diag(void)
{
	double vD;                     //��������ٶ�
	double lamd_e, lamd_D;
	double w_pe, peri_e;
	double wpe_dt, vdt_dz;
	
	//�����¶�Ti=20,���ӵ��qi=1.6021865314e-19;�����m_D=3.348e-27;
	vD = sqrt(2.0 * Ti * qi / m_D);	//��������ٶ�,�����¶�Ti=20,���ӵ��qi=1.6021865314e-19;
	//printf("%lf \n", vD); stime();

	//��������me=9.1093897e-31;	 ve=sqrt(-2.0*qe*Te/me);sqrt(2.0*qe*Te/me);  ���ӵ��qe=-1.6021865314e-19;  �ų�B0=5.3;
	lamd_e = me * ve / fabs(qe * B0);//���ӻ����뾶

	lamd_D = m_D * vD / fabs(qi * B0);//����ӻ����뾶
	
	//Ne=1e19;�������ܶ�  //��ս�糣��eps0=8.854187817e-12;
	w_pe = sqrt(Ne * qe * qe / (eps0 * me));//������Ƶ��
	//printf("���ӻ����뾶%lf \n", lamd_e); 
	//printf("����ӻ����뾶%lf \n", lamd_D); 
	//printf("������Ƶ��%lf \n", w_pe); stime();

	//dt=1.0e-12;ʱ�䲽��  //dz_plas=lz_plas/double(Nz_plas-1);z����ռ䲽��
	peri_e = 2.0 * pi / w_pe; //��������������T=2��/��
	wpe_dt = w_pe * dt;    
	vdt_dz = ve * dt / dz_plas;
	printf("ne=%10.6e,Te=%10.6f\n", Ne, Te);
	printf("ve=%10.6e,v_D=%10.6e\n", ve, vD);
	printf("�°ݳ���=%10.6e,�ռ䲽��=%10.6e\n", deby_leng, dz_plas);
	printf("����������=%10.6e,ʱ�䲽��=%10.6e\n", peri_e, dt);
	printf("wpe*dt=%10.6f,v*dt/dz=%10.6f\n", wpe_dt, vdt_dz);

}
