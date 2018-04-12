#include "StdAfx.h"
#include "DbgPrint.h"

char Debug_szErrorMsg[1024]={0};
char Debug_szErrorInfo[1024]={0};

//************************************
// Method:    MyDbgPrint
// FullName:  MyDbgPrint
// Purpose:   ��ǿ���OutputDebugString��ʹ������������
// Returns:   void
// Parameter: const char * sz
// Parameter: ...
//************************************
void MyDbgPrint(const char * sz, ...)
{
#ifdef DBG
	char szData[512]={0};
	
	va_list args;
	va_start(args, sz);
	_vsnprintf(szData, sizeof(szData) - 1, sz, args);
	va_end(args);
	
	OutputDebugString(szData);
#endif
}

/********************************************************************
	Function Name: 	GetErrorMessage
	Function purpose:	��ȡ������״̬��������Ĵ�����
	Input Arguments :	
		ErrorMsgBuffer:�����������ص����ݷ�������
		ErrCode		:����״̬��
	ReturnValue:	��

*********************************************************************/
void GetErrorMessage( char *ErrorMsgBuffer, DWORD ErrCode )
{
    char *errMsg;
    FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,
		ErrCode,
		MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),
		( LPTSTR )&errMsg, 0, NULL );
	lstrcpy(ErrorMsgBuffer,errMsg);
    LocalFree( errMsg );
    return;
}