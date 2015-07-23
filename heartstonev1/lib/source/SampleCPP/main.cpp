#include "../../include/sharpnow.hpp"
#include <iostream>
#include <Windows.h>

sharpnow::SDK sdk;

int main(int argc, char** argv)
{
    // ���ض�̬���ӿ�
    if (!sdk.LoadInPath("../../lib")) return -1;

    std::cout << "�ȴ��豸���� ... " << std::endl;
    bool connected[] = { false, false };
    while (true)
    {
        for (int device = 0; device < 2; ++device)
        {
            if (sdk.RetrieveFrame(device))
            {
                // ����Ƿ�Ϊ�������豸
                if (!connected[device])
                {
                    std::cout << "��⵽΢�� " << device << " ����" << std::endl;
                    std::cout << "�����ָ�ɿ�����Ļ����ƶ�" << std::endl;
                    connected[device] = true;
                }

                // ȷ���յ���������
                const sharpnow::Frame* frame = sdk.GetFrameInfo();
                if (!frame->updated) continue;

                // ����ָʱ��������Ļ���
                const sharpnow::Finger* finger = sdk.GetFingerFocus();
                if (frame->finger_number == 1 && finger)
                {
                    std::cout << "\r" << finger->cursor.x << " " << finger->cursor.y;
                    SetCursorPos(
                        int(finger->cursor.x * ::GetSystemMetrics(SM_CXSCREEN)),
                        int(finger->cursor.y * ::GetSystemMetrics(SM_CYSCREEN)));
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

