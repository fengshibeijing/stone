/********************************************************************/
/* ��Ȩ���������ļ��ṩ��SharpNow SDK�İ�Ȩ��������ʱ�����Ƽ����޹�˾�� */
/* ���ļ��ṩ��SDKԴ����ܻᷢ���������޸ģ�����е�ʹ�ñ�SDK�ķ��ա�     */
/* ���˻�˾���Ը��ƺ�ʹ�ô�Դ������΢��(ViD)Ӧ�ó��򿪷���             */
/* (C) 2011-2015 Tianjin SharpNow Technology. All rights reserved.  */
/********************************************************************/

//! @file
//! ���������豸��ص�ö�ٱ���

#ifndef __SHARPNOW_HID_H__
#define __SHARPNOW_HID_H__

namespace sharpnow
{
    //! @enum HandSide
    //! @brief ö�ٳ�����HID�¼�
    enum HIDEvent
    {
        Mouse_MoveX,        //!< ��� Xλ�ã�ȡֵȡֵ��Χ 0~32767
        Mouse_MoveY,        //!< ��� Yλ�ã�ȡֵ��Χ 0~32767
        Mouse_Wheel,        //!< ��� ���֣�ȡֵ��Χ -127~127
        Mouse_ButtonDown,   //!< ��� �������£�ȡֵ��Χ 0~4
        Mouse_ButtonUp,     //!< ��� ����̧��ȡֵ��Χ 0~4
        Mouse_Flush,        //!< ��� ˢ��

        Keyboard_Down,      //!< ���� ���°������ɼ��ַ���
        Keyboard_Up,        //!< ���� ̧�𰴼����ɼ��ַ���
        Keyboard_DownEx,    //!< ���� ���°��������⹦�ܣ�
        Keyboard_UpEx,      //!< ���� ̧�𰴼������⹦�ܣ�
        Keyboard_Flush,     //!< ���� ˢ��

        Joystick_X,         //!< ��Ϸ��1 X�ᣬȡֵ��Χ -32767~32767
        Joystick_Y,         //!< ��Ϸ��1 Y�ᣬȡֵ��Χ -32767~32767
        Joystick_Z,         //!< ��Ϸ��1 Z�ᣬȡֵ��Χ -32767~32767
        Joystick_RX,        //!< ��Ϸ��1 X������ȡֵ��Χ -32767~32767
        Joystick_RY,        //!< ��Ϸ��1 Y������ȡֵ��Χ -32767~32767
        Joystick_RZ,        //!< ��Ϸ��1 Z������ȡֵ��Χ -32767~32767
        Joystick_Slider,    //!< ��Ϸ��1 ������ȡֵ��Χ -32767~32767
        Joystick_Dial,      //!< ��Ϸ��1 ���ţ�ȡֵ��Χ -32767~32767
        Joystick_Hat,       //!< ��Ϸ��1 ��׼����ȡֵ��Χ 0~8
        Joystick_ButtonDown,//!< ��Ϸ��1 �������£�ȡֵ��Χ 0~15
        Joystick_ButtonUp,  //!< ��Ϸ��1 ����̧��ȡֵ��Χ 0~15
        Joystick_Flush,     //!< ��Ϸ��1 ˢ��

        Joystick2_X,        //!< ��Ϸ��2 X�ᣬȡֵ��Χ -32767~32767
        Joystick2_Y,        //!< ��Ϸ��2 Y�ᣬȡֵ��Χ -32767~32767
        Joystick2_Z,        //!< ��Ϸ��2 Z�ᣬȡֵ��Χ -32767~32767
        Joystick2_RX,       //!< ��Ϸ��2 X������ȡֵ��Χ -32767~32767
        Joystick2_RY,       //!< ��Ϸ��2 Y������ȡֵ��Χ -32767~32767
        Joystick2_RZ,       //!< ��Ϸ��2 Z������ȡֵ��Χ -32767~32767
        Joystick2_Slider,   //!< ��Ϸ��2 ������ȡֵ��Χ -32767~32767
        Joystick2_Dial,     //!< ��Ϸ��2 ���ţ�ȡֵ��Χ -32767~32767
        Joystick2_Hat,      //!< ��Ϸ��2 ��׼����ȡֵ��Χ 0~8
        Joystick2_ButtonDown,//!< ��Ϸ��2 �������£�ȡֵ��Χ 0~15
        Joystick2_ButtonUp, //!< ��Ϸ��2 ����̧��ȡֵ��Χ 0~15
        Joystick2_Flush,    //!< ��Ϸ��2 ˢ��

        Touch_ContactID,    //!< ������ �Ӵ���ID��ȡֵ��Χ 0~9
        Touch_X,            //!< ������ Xλ�ã�ȡֵ��Χ 0~32767
        Touch_Y,            //!< ������ Yλ�ã�ȡֵ��Χ 0~32767
        Touch_Height,       //!< ������ �߶ȣ�ȡֵ��Χ 0~32767
        Touch_Flush,        //!< ������ ˢ��
    };

    //! @enum KeyEx
    //! @brief ö�ٳ��������ⰴ��
    enum KeyEx
    {
        KeyEx_CtrL,         //!< ��control
        KeyEx_ShiftL,       //!< ��shift
        KeyEx_AltL,         //!< ��alter
        KeyEx_WinL,         //!< ��win
        KeyEx_CtrR,         //!< ��control
        KeyEx_ShiftR,       //!< ��shift
        KeyEx_AltR,         //!< ��alter
        KeyEx_WinR,         //!< ��win

        KeyEx_Left,         //!< ����
        KeyEx_Right,        //!< ����
        KeyEx_Up,           //!< ����
        KeyEx_Down,         //!< ����
        KeyEx_Home,         //!< ����
        KeyEx_End,          //!< ��β
        KeyEx_PageUp,       //!< ��ǰ��ҳ
        KeyEx_PageDown,     //!< ���ҳ
        KeyEx_Insert,       //!< ����
        KeyEx_Delete,       //!< ɾ��
        KeyEx_Esc,          //!< �˳�
        KeyEx_Backspace,    //!< ����
        KeyEx_Enter,        //!< �س�
        KeyEx_Tab,          //!< �Ʊ��
        KeyEx_Space,        //!< �ո�

        KeyEx_F1,           //!< F1
        KeyEx_F2,           //!< F2
        KeyEx_F3,           //!< F3
        KeyEx_F4,           //!< F4
        KeyEx_F5,           //!< F5
        KeyEx_F6,           //!< F6
        KeyEx_F7,           //!< F7
        KeyEx_F8,           //!< F8
        KeyEx_F9,           //!< F9
        KeyEx_F10,          //!< F10
        KeyEx_F11,          //!< F11
        KeyEx_F12,          //!< F12

        KeyEx_Pad0,         //!< ���ּ��� 0
        KeyEx_Pad1,         //!< ���ּ��� 1
        KeyEx_Pad2,         //!< ���ּ��� 2
        KeyEx_Pad3,         //!< ���ּ��� 3
        KeyEx_Pad4,         //!< ���ּ��� 4
        KeyEx_Pad5,         //!< ���ּ��� 5
        KeyEx_Pad6,         //!< ���ּ��� 6
        KeyEx_Pad7,         //!< ���ּ��� 7
        KeyEx_Pad8,         //!< ���ּ��� 8
        KeyEx_Pad9,         //!< ���ּ��� 9
        KeyEx_PadDot,       //!< ���ּ��� С����
        KeyEx_PadAdd,       //!< ���ּ��� ��
        KeyEx_PadSub,       //!< ���ּ��� ��
        KeyEx_PadMul,       //!< ���ּ��� ��
        KeyEx_PadDiv,       //!< ���ּ��� ��
        KeyEx_PadEnter,     //!< ���ּ��� �س�
    };
}

#endif
