//��ʾ����dp512.c
#include  <stdio.h>
struct  STUDENT                     //�����ṹ������STUDENT
{
	int   num;                      //���ͣ�4�ֽڣ�
	char  name[14];                 //�ַ������飨16�ֽڣ�
	int   score;                    //���ͣ�4�ֽڣ�
	char  grade;                    //�ַ��ͣ�4�ֽڣ�
};
/*struct  STUDENT                     //�����ṹ������STUDENT
{
	int   num;                      //���ͣ�4�ֽڣ�
	char  grade;                    //
	char  name[14];                 //�ַ������飨16�ֽڣ�
	int   score;                    //���ͣ�4�ֽڣ�
	            
};*/
char  cf513(struct  STUDENT  stux); //��������ԭ��
char  cf514(struct  STUDENT  *pp);  //��������ԭ��
									//                                  //����ȫ�ֽṹ�����zhang
struct  STUDENT  zhang = { 103,"ZHANG",88,'3' };
//struct  STUDENT  zhang = { 103,'3',"ZHANG",88 };
//
int  main()
{
	struct  STUDENT  stu;           //����ṹ�����
	char  g1, g2;                   //�����ַ��ͱ���
	stu = zhang;                    //�ṹ�������ֵ
	stu.num = 108;                  //�ṹ���Ա��ֵ
	stu.name[2] = 'E';              //�ṹ���Ա��Ԫ�ظ�ֵ
	printf("%s=%d\n", stu.name, stu.num);
	g1 = cf513(stu);                //ʵ���ǽṹ�����
	g2 = cf514(&stu);               //ʵ���ǽṹ������ĵ�ַ
	printf("g1=%c,g2=%c\n", g1, g2);
	return  0;
}
//ʾ������cf513
char  cf513(struct  STUDENT  stux)
{
	if (stux.score >= 80)
		stux.grade += 1;
	return  stux.grade;
}
//ʾ������cf514
char  cf514(struct  STUDENT  *pp)
{
	if (pp->score >= 80)
		pp->grade += 1;
	return  pp->grade;
}