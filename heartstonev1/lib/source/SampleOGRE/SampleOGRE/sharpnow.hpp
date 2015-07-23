/********************************************************************/
/* ��Ȩ���������ļ��ṩ��SharpNow SDK�İ�Ȩ��������ʱ�����Ƽ����޹�˾�� */
/* ���ļ��ṩ��SDKԴ����ܻᷢ���������޸ģ�����е�ʹ�ñ�SDK�ķ��ա�     */
/* ���˻�˾���Ը��ƺ�ʹ�ô�Դ������΢��(ViD)Ӧ�ó��򿪷���             */
/* (C) 2011-2014 Tianjin SharpNow Technology. All rights reserved.  */
/********************************************************************/

//! @file
//! ΢��C++�ӿڷ�װ

#ifndef __SHARPNOW_HPP__
#define __SHARPNOW_HPP__

#ifndef WIN32_LEAN_AND_MEAN
#   define WIN32_LEAN_AND_MEAN 1
#endif
#include <Windows.h>
#include "sharpnow.h"

namespace sharpnow
{
    //! @brief SDK��������װ
    //! 
    class SDK
    {
    public:
        SDK() { mIsValid = false; mDLL = NULL; }
        ~SDK() { if (mDLL) FreeLibrary(mDLL); }

        //! @brief װ��ָ���豸������֡����
        //! @param[in] device �豸���
        //! @return װ���Ƿ�ɹ�����ʧ�ܱ�ʾ�豸��δ���ӡ�
        //! @note Ŀǰ���������̨�豸������ͬ������device��ȡֵ����Ϊ 0 �� 1 ��
        //!
        //! ΢�������̨�豸������ͬһ̨�����ϡ� \n
        //! ʹ��device������ѡ��ָ����ŵ��豸�������ظ��豸��������֡�� \n
        inline bool RetrieveFrame(int device)       { return mIsValid && mRetrieveFrame(device);    }

        //! @brief �õ���ǰ����֡��״̬��Ϣ
        //! @return ����֡״̬��Ϣ�Ľṹ��ָ��
        //!
        //! ֡״̬��Ϣ�а����豸����״̬�ȣ���ο� Frame �ṹ�塣 \n
        inline const Frame*  GetFrameInfo()         { return mIsValid ? mGetFrameInfo() : NULL;     }

        //! @brief �õ�ָ����ָ��״̬��Ϣ
        //! @param[in] finger ָ����ָ����� ( order_id )
        //! @return ��ָ��Ϣ�Ľṹ��ָ��
        //!
        //! ��ָ״̬��Ϣ����ָ��Ķ�λ�����״̬����ο� Finger �ṹ�塣 \n
        inline const Finger* GetFinger(int finger)  { return mIsValid ? mGetFinger(finger) : NULL;  }

        //! @brief �õ�������ָ��״̬��Ϣ
        //! @return ������ָ��Ϣ�Ľṹ��ָ��
        //!
        //! ���ֲ������豸��Ұ�ڣ�һ������ָĿ�걻��⵽���豸�������ܱ��ֶ����� \n
        //! һ����ָ�����㣩�ĸ��٣�����Ŀ�귢���л�����Ŀ��ͨ�������ڹ����ơ� \n \n
        //! ��ָ״̬��Ϣ����ָ��Ķ�λ�����״̬����ο� Finger �ṹ�塣 \n
        inline const Finger* GetFingerFocus()       { return mIsValid ? mGetFingerFocus() : NULL;   }

        //! @brief �õ�ָ�����Ƶ�״̬��Ϣ
        //! @param[in] hand ָ�����Ƶ���� ( order_id )
        //! @return ������Ϣ�Ľṹ��ָ��
        //!
        //! ����״̬��Ϣ�������ĵĶ�λ����̬����ο� Hand �ṹ�塣 \n
        inline const Hand*   GetHand(int hand)      { return mIsValid ? mGetHand(hand) : NULL;      }

        //! @brief �õ��������Ƶ�״̬��Ϣ
        //! @return ����������Ϣ�Ľṹ��ָ��
        //!
        //! ���ֲ������豸��Ұ�ڣ�һ��������Ŀ�걻��⵽���豸�������ܱ��ֶ����� \n
        //! һ�����ƣ����㣩�ĸ��٣�����Ŀ�귢���л��� \n \n
        //! ����״̬��Ϣ�������ĵĶ�λ����̬����ο� Hand �ṹ�塣 \n
        inline const Hand*   GetHandFocus()         { return mIsValid ? mGetHandFocus() : NULL;     }

        //! @brief ģ���׼����豸
        //! @param event ģ���¼���ö������
        //! @param data ģ���¼���������Ϣ
        //! @return �Ƿ�ɹ�����ģ���¼�
        //!
        //! ΢�����ԶԼ��̡���ꡢ��Ϸ�����㴥��������������ģ�⡣ģ�⶯��ͨ�� \n
        //! �������ñ��ӿ�ʵ�֣����巽ʽ��ע��������ο�����ĵ��� \n \n
        inline bool EmulateHID(HIDEvent event, int data) { return mIsValid ? mEmulateHID(event, data) : false; }

        //! @brief ��ָ��·���м��ض�̬���ӿ�
        //! @param path ��̬���ӿ��·����
        //! @return �Ƿ�ɹ����ض�̬���ӿ�
        inline bool LoadInPath(const char* path)
        {
            if (mIsValid) return true;
            char name[MAX_PATH];
            strcpy_s(name, path);
            if (strlen(path) > 0) strcat_s(name, "/");
#ifdef _DEBUG
            strcat_s(name, "sharpnowD.dll");
#else
            strcat_s(name, "sharpnow.dll");
#endif
            mDLL = LoadLibraryA(name);
            if (!mDLL) return false;

            mRetrieveFrame   = (Proto_RetrieveFrame)GetProcAddress(mDLL, "RetrieveFrame");
            mGetFrameInfo   = (Proto_GetFrameInfo)GetProcAddress(mDLL, "GetFrameInfo");
            mGetFinger      = (Proto_GetFinger)GetProcAddress(mDLL, "GetFinger");
            mGetFingerFocus = (Proto_GetFingerFocus)GetProcAddress(mDLL, "GetFingerFocus");
            mGetHand        = (Proto_GetHand)GetProcAddress(mDLL, "GetHand");
            mGetHandFocus   = (Proto_GetHandFocus)GetProcAddress(mDLL, "GetHandFocus");
            mEmulateHID     = (Proto_EmulateHID)GetProcAddress(mDLL, "EmulateHID");
            mIsValid = mRetrieveFrame && mEmulateHID && mGetFinger && mGetFingerFocus && mGetHand && mGetHandFocus;
            return mIsValid;
        }
    private:
        bool                    mIsValid;           //!< DLL�Ƿ�ɹ�����
        HMODULE                 mDLL;               //!< ��̬���ӿ�
        Proto_EmulateHID        mEmulateHID;        //!< ģ���豸
        Proto_RetrieveFrame     mRetrieveFrame;     //!< ��������֡
        Proto_GetFrameInfo      mGetFrameInfo;      //!< ��ȡ֡��Ϣ
        Proto_GetFinger         mGetFinger;         //!< ��ȡ��ָ
        Proto_GetFingerFocus    mGetFingerFocus;    //!< ��ȡ��ָ����
        Proto_GetHand           mGetHand;           //!< ��ȡ�ֲ�
        Proto_GetHandFocus      mGetHandFocus;      //!< ��ȡ�ֲ�����
    };
};

#endif
