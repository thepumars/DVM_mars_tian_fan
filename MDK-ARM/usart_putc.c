#include "main.h"


extern UART_HandleTypeDef huart1;
uint8_t ch;
uint8_t ch_r;

//重写这个函数,重定向printf函数到串口
/*fputc*/
int fputc(int c, FILE * F)
{
	ch=c;
	HAL_UART_Transmit(&huart1,&ch,1,1000); //发送串口，不同的单片机函数和串口命名不同，替换对于的函数串口名字即可实现不同库和不同单片机的重定向了
	return c;
}

 

//重定向scanf函数到串口 意思就是说接受串口发过来的数据
/*fgetc*/
int fgetc(FILE * F)
{
	HAL_UART_Receive(&huart1,&ch_r,1,0xffff);  //接收
	return ch_r;
}
