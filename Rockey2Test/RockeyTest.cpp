// RockeyTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Inc/Rockey2.h"

#ifdef _DEBUG
#pragma comment(lib,"../Lib/Rockey2D.lib")
#else
#pragma comment(lib,"../Lib/Rockey2.lib")
#endif

int main(int argc, char* argv[])
{
	int DogCnt = RY2_Find();
	printf("DogCnt = %d\n",DogCnt);

	DWORD dwHID = 0 ;
	int handle = -1;
	int ret = -1 ;
	
	//�Զ�ģʽ����
	handle = RY2_Open(AUTO_MODE,0,&dwHID);
	
	//HIDģʽ����
	//dwHID = 0x289574B4 ;
	//handle = RY2_Open(HID_MODE,0,&dwHID);

	//UIDģʽ����
	//handle = RY2_Open(1, 0x7CA2A77D,&dwHID);

	printf("handle = 0x%X\n",handle);
	
	if (handle < 0)
	{
		printf("Open Dongle Failed.\n");
		return 0 ;
	}
	
	char Buffer[512 ] = {0};

	//����д�룬����д�뵱ǰʱ�䴮
	SYSTEMTIME st;
	GetLocalTime(&st);
	sprintf(Buffer,"Time is %04d-%02d-%02d %02d:%02d:%02d.%03d",
		st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond,st.wMilliseconds);
	
	//����д��
	ret = RY2_Write(handle,0,Buffer);
	printf("Write ret = 0x%X\n",ret);

	//���Զ�ȡ
	ret = RY2_Read(handle,0,Buffer);
	printf("Read ret = 0x%X\n",ret);
	printf("Content : [%s]\n",Buffer);
	
	if (handle >=0 )
		RY2_Close(handle);

	return 0;
}

