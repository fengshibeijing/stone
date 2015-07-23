#include "../../include/sharpnow.h"
#include <iostream>
#include <Windows.h>

sharpnow::Proto_RetrieveFrame     RetrieveFrame;
sharpnow::Proto_GetFrameInfo      GetFrameInfo;
sharpnow::Proto_GetFinger         GetFinger;
sharpnow::Proto_GetFingerFocus    GetFingerFocus;
sharpnow::Proto_GetHand           GetHand;
sharpnow::Proto_GetHandFocus      GetHandFocus;

int main(int argc, char** argv)
{
    // ���ض�̬���ӿ�
    HMODULE dll = NULL;
#ifdef _DEBUG
    dll = LoadLibraryA("../../lib/sharpnowD.dll");
#else
    dll = LoadLibraryA("../../lib/sharpnow.dll");
#endif
    if (!dll) return -1;    

    // ���ؽӿں���
    RetrieveFrame  = (sharpnow::Proto_RetrieveFrame)GetProcAddress(dll, "RetrieveFrame");
    GetFrameInfo   = (sharpnow::Proto_GetFrameInfo)GetProcAddress(dll, "GetFrameInfo");
    GetHand        = (sharpnow::Proto_GetHand)GetProcAddress(dll, "GetHand");
    GetHandFocus   = (sharpnow::Proto_GetHandFocus)GetProcAddress(dll, "GetHandFocus");
    if (!RetrieveFrame || !GetFrameInfo || !GetHand || !GetHandFocus) return -1;

    std::cout << "�ȴ��豸���� ... " << std::endl;
    bool connected[] = { false, false };
    while (true)
    {
        for (int device = 0; device < 2; ++device)
        {
            if (RetrieveFrame(device))
            {
                // ����Ƿ�Ϊ�������豸
                if (!connected[device])
                {
                    std::cout << "��⵽΢�� " << device << " ����" << std::endl;
                    connected[device] = true;
                }

                // ȷ���յ���������
                const sharpnow::Frame* frame = GetFrameInfo();
                if (!frame->updated) continue;

                // ��鵱ǰ��������
                const sharpnow::Hand* hand = GetHandFocus();
                if (hand 
                    && hand->gesture != sharpnow::HS_Unknown
                    && hand->gesture != sharpnow::HG_Grip 
                    && hand->gesture_counter <= 25) 
                {
                    // ȷ����������
                    std::cout << "\r��ǰ������̬��";
                    switch (hand->gesture)
                    {
                    case sharpnow::HG_Point:    std::cout << "Point   "; break;
                    case sharpnow::HG_Gun:      std::cout << "Gun     "; break;
                    case sharpnow::HG_Victory:  std::cout << "Victory "; break;
                    case sharpnow::HG_Metal:    std::cout << "Metel   "; break;
                    case sharpnow::HG_Phone:    std::cout << "Phone   "; break;
                    case sharpnow::HG_Fork:     std::cout << "Fork    "; break;
                    case sharpnow::HG_Three:    std::cout << "Three   "; break;
                    case sharpnow::HG_Love:     std::cout << "Love    "; break;
                    case sharpnow::HG_Four:     std::cout << "Four    "; break;
                    case sharpnow::HG_Five:     std::cout << "Five    "; break;
                    }

                    for (int i = 0; i < 25; ++i) std::cout << (i < hand->gesture_counter ? "." : " ");
                    if (hand->gesture_counter == 25) std::cout << " OK\n";
                }
            }
            else
            {
                // ����豸�Ͽ�
                if (connected[device])
                {
                    std::cout << "��⵽΢�� " << device << " �Ͽ�" << std::endl;
                    connected[device] = false;
                }
                continue;
            }
        }
        ::Sleep(1);
    }

    return 0;
}

