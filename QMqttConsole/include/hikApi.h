#ifndef HIKAPI_H
#define HIKAPI_H
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "HCNetSDK.h"
#include <time.h>
using namespace std;
/*
void CALLBACK g_ExceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
{
	char tempbuf[256] = {0};
    switch(dwType) 
    {
    case EXCEPTION_RECONNECT:    //预览时重连
        //printf("----------reconnect--------%d\n", time(NULL));
    break;
    default:
    break;
    }
}*/
//out：错误码 0没有错误  1用户名密码错误 2权限不足  3没有初始化  4通道号错误  5连接到DVR的客户端个数超过最大 7连接服务器失败  8向服务器发送失败 28DVR资源不足  29DVR操作失败
int pictureCapture(char* ip, int port, char* name, char* pwd, char* path);


#endif
