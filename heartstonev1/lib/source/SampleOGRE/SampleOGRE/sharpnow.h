/********************************************************************/
/* ��Ȩ���������ļ��ṩ��SharpNow SDK�İ�Ȩ��������ʱ�����Ƽ����޹�˾�� */
/* ���ļ��ṩ��SDKԴ����ܻᷢ���������޸ģ�����е�ʹ�ñ�SDK�ķ��ա�     */
/* ���˻�˾���Ը��ƺ�ʹ�ô�Դ������΢��(ViD)Ӧ�ó��򿪷���             */
/* (C) 2011-2014 Tianjin SharpNow Technology. All rights reserved.  */
/********************************************************************/

//! @file
//! ΢��C�ӿڷ�װ

#ifndef __SHARPNOW_H__
#define __SHARPNOW_H__

#include "hid.h"
#include "vid.h"

namespace sharpnow
{
    //! �ӿ�ԭ�ͣ�װ��ָ���豸������֡����
    typedef bool (*Proto_RetrieveFrame)(int device);

    //! �ӿ�ԭ�ͣ��õ���ǰ����֡��״̬��Ϣ
    typedef const Frame* (*Proto_GetFrameInfo)();

    //! �ӿ�ԭ�ͣ��õ�ָ����ָ��״̬��Ϣ
    typedef const Finger* (*Proto_GetFinger)(int finger);

    //! �ӿ�ԭ�ͣ��õ�������ָ��״̬��Ϣ
    typedef const Finger* (*Proto_GetFingerFocus)();

    //! �ӿ�ԭ�ͣ��õ�ָ�����Ƶ�״̬��Ϣ
    typedef const Hand* (*Proto_GetHand)(int hand);

    //! �ӿ�ԭ�ͣ��õ��������Ƶ�״̬��Ϣ
    typedef const Hand* (*Proto_GetHandFocus)();

    //! �ӿ�ԭ�ͣ�ģ���׼����豸
    typedef bool (*Proto_EmulateHID)(HIDEvent event, int data);
}

#endif
