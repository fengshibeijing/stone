/********************************************************************/
/* ��Ȩ���������ļ��ṩ��SharpNow SDK�İ�Ȩ��������ʱ�����Ƽ����޹�˾�� */
/* ���ļ��ṩ��SDKԴ����ܻᷢ���������޸ģ�����е�ʹ�ñ�SDK�ķ��ա�     */
/* ���˻�˾���Ը��ƺ�ʹ�ô�Դ������΢��(ViD)Ӧ�ó��򿪷���             */
/* (C) 2011-2015 Tianjin SharpNow Technology. All rights reserved.  */
/********************************************************************/

//! @file
//! ΢����֪��Ϣ

#ifndef __SHARPNOW_VID_H__
#define __SHARPNOW_VID_H__

#include "mathtypes.h"

//! @namespace
namespace sharpnow
{
    //! @enum HandSide
    //! @brief ö�ٳ������ֲ���ɫ
    //!
    //! �豸�ɸ����ֲ��������Զ��������ּ����жϡ�\n
    //! �����ǰ�����޷�ȷ���ֲ���ɫ����Ϊ���޷�ȷ�ϡ���
    enum HandSide
    {
        HS_Unknown, //!< �޷�ȷ��
        HS_Left,    //!< ����
        HS_Right    //!< ����
    };

    //! @enum DeviceMode
    //! @brief ö�ٳ������豸����ģʽ
    //!
    //! ΢���������ֹ���״̬�� \n
    //! �豸���Ը�������ļ��ټ�״̬�Զ��жϵ�ǰ����״̬�� \n
    //! �豸ƽ�����棬��Ұ���ϣ�Ϊ�ռ�ģʽ�� \n
    //! �豸�����������ϣ���Ұ��ǰ��Ϊ����ģʽ��
    enum DeviceMode
    {
        DM_Air,     //!< �ռ�ģʽ���豸��Ӧ�Ͽ�����
        DM_Touch,   //!< ����ģʽ���豸��Ӧǰ����������
    };

    //! @enum HandGesture
    //! @brief ö�ٳ�����������̬ 
    //!
    //! ΢�������Զ�ʶ��11�ֳ��þ�̬���ơ� \n
    //! �����ǰ�����޷�ȷ���������ͣ���Ϊ���޷�ȷ�ϡ���
    enum HandGesture
    {
        HG_Unknown, //!< �޷�ȷ��
        HG_Grip,    //!< ��ȭ����ָ��£����ն���
        HG_Point,   //!< ����ָ������ָ���
        HG_Gun,     //!< ��ǹ��ʳָ��Ĵָ���������ǹ״
        HG_Victory, //!< ʤ����ʳָ����ָ�������ĸV������
        HG_Metal,   //!< ������ʳָ��Сָ��������ֻ��ֳ���������
        HG_Phone,   //!< �绰��Ĵָ��Сָ���������绰״
        HG_Fork,    //!< ���ӣ�Ĵָ��ʳָ����ָ���
        HG_Three,   //!< ��������ʳָ����ָ������ָ���
        HG_Love,    //!< ��LOVE��Ĵָ��ʳָ��Сָ���
        HG_Four,    //!< �����ģ�ʳָ����ָ������ָ��Сָ���
        HG_Five,    //!< �����壬��ָ��ȫ�쿪

        HG_Good,    //!< �ã�Ĵָ���
        HG_Draw,    //!< �滭��ʳָ��ָ��£
        HG_OK,      //!< ȷ��OK����ָСָ����ָ���
        HG_Stop,    //!< ֹͣ�� ��ָ��£
        HG_Vertical,//!< ��ֱ�� Ĵָ���������ָ��£
    };

    //! �ֲ���̬�����ִ�
    const char gesture_name[][16] =
    {
        "Unknown",
        "Grip",
        "Point",
        "Gun",
        "Victory",
        "Metal",
        "Phone",
        "Fork",
        "Three",
        "Love",
        "Four",
        "Five",

        "Good",
        "Draw",
        "OK",
        "Stop",
        "Vertical"
    };

    //! @brief ö�ٳ������Թ켣����ʶ���ķ������ͣ���ֵΪ��Ӧ��Ascii��
    //!
    //! ΢��Ŀǰ��ʶ��10�����ַ���
    //! �޷�ʶ��켣������£�ʶ��������ΪTS_None
    struct TrajSymbol
    {
        static const unsigned int None      = 0x00000000;
        static const unsigned int Zero      = 0x00000030;
        static const unsigned int One       = 0x00000031;
        static const unsigned int Two       = 0x00000032;
        static const unsigned int Three     = 0x00000033;
        static const unsigned int Four      = 0x00000034;
        static const unsigned int Five      = 0x00000035;
        static const unsigned int Six       = 0x00000036;
        static const unsigned int Seven     = 0x00000037;
        static const unsigned int Eight     = 0x00000038;
        static const unsigned int Nine      = 0x00000039;
    };

    //! @brief �ṹ�壺��ָĿ��
    //! 
    //! ��������ָĿ��ĸ�֪��Ϣ��ʹ�ýӿ�GetFinger��GetFingerFocus�ɻ�ȡ���ṹ����Ϣ��
    typedef struct _Finger
    {
        //! @brief ���ID
        //!
        //! [ ȡֵ��Χ�� 0 ~ 9 ] \n
        //! һ֡�������������ָ����ţ���ʾ����ָ�Ĵ��˳��\n
        //! ͬһֻ�ֵ���ָΪ������ţ����������������ID��\n
        //! �ӿں���GetFingerʹ�ø���Ż�ȡָ����ָĿ�ꡣ
        int             order_id;

        //! @brief ����ID
        //!
        //! [ ȡֵ��Χ 0 ~ 9 ] \n
        //! ��ʾ��ָ�ĸ���״̬��ͬһ��ָ���豸��ⷶΧ���˶��Ĺ����У��ᱣ�ָ�����Ų��䡣
        int             track_id;

        //! @brief ��ָ��ɫ
        int             role;

        //! @brief �ֲ�ID
        //!
        //! ��Ӧ�ֲ���ţ�ʹ��GetHand�ɻ����Ӧ�ֲ���Ϣ��
        int             hand;   

        //! @brief �ֲ���Ծ
        //!
        //! ��ָ�Ƿ��Ծ����ָ��չʱ���ڻ�Ծ״̬
        bool            active;

        //! @brief �Ӵ�״̬
        //!
        //! TouchMode����Ч����ʾ��ָ�Ƿ������淢���Ӵ���
        bool            contact;

        //! @brief ָ������
        //!
        //! Airģʽ�У���ָ�ڶ�ʱ���ڽ���ǰ�������� \n
        //! �ñ���ֵ�ڼ�⵽������˲��Ϊtrue������Ϊfalse��
        bool            poke;

        //! @brief �û�����
        //!
        //! Airģʽ�У���ָ�ڶ�ʱ���������˶���Ȼ����� \n
        //! �ñ���ֵ�ڼ�⵽������˲��Ϊtrue������Ϊfalse��
        bool            tap;

        //! @brief ��ͣ������
        //!
        //! ��ǰ��ָ��ͣ���򼸺��������˶���ʱ����ͣ���������������ӡ�\n
        //! ����ָ�ٴη����ƶ����ü�����������λΪ0��
        int             stop;

        //! @brief ��ͣ������
        //
        int             circle_dir;

        //! @brief ָ��λ��
        //!
        //! ��ָָ�����άλ�á�
        Vector3         position; 

        //! @brief ָ���ٶ�
        //!
        //! ��ָָ�����ά�˶��ٶȡ�
        Vector3         velocity;

        //! @brief ָ�ⷽ��
        //!
        //! ������ָָ��ĩ�˷������ά������
        Vector3         direction; 

        //! @brief ���λ��
        //!
        //! [ ����ȡֵ��Χ 0.0 ~ 1.0 ] \n
        //! ����ָλ��ӳ��Ϊ��׼����ƽ��λ�ã���������Ļ�����ơ�\n
        //! Airģʽӳ��ƽ�������洹ֱ��Touchģʽӳ��ƽ��������ƽ�С�
        Vector2         cursor;

        //! @brief �������Ʒ���
        //!
        //! ��ӳ��ƽ�����ָ�������� \n
        //! Airģʽ����һ�νӴ��Ļ������� \n
        //! Touchģʽ����һ�ο����˶��ķ���
        Vector2         slide;

        //! @brief ��Ȧ����
        //!
        Vector3         circle_center;

        //! @brief ��ָ����
        //!
        float           length;

        float           angle_cmc_yaw;
        float           angle_mcp_yaw;
        float           angle_mcp_pitch;
        float           angle_pip;
        float           angle_dip;

        //! @brief ָ�ؽ�λ��0
        //!
        //! ��0��ָָ�ؽڵ���άλ�á�
        Vector3         joint0;

        //! @brief ָ�ؽ�λ��1
        //!
        //! ��1��ָָ�ؽڵ���άλ�á�
        Vector3         joint1;

        //! @brief ָ�ؽ�λ��2
        //!
        //! ��2��ָָ�ؽڵ���άλ�á�
        Vector3         joint2;

        //! @brief ָ�ؽ�λ��3
        //!
        //! ��3��ָָ�ؽڵ���άλ�á�
        Vector3         joint3;

    } Finger;

    //! @brief �ṹ�壺����Ŀ��
    //! 
    //! ����������Ŀ��ĸ�֪��Ϣ��ʹ�ýӿ�GetHand��GetHandFocus�ɻ�ȡ���ṹ����Ϣ��
    typedef struct _Hand
    {
        //! @brief ���ID
        //!
        //! [ ȡֵ��Χ�� 0 ~ 1 ] \n
        //! һ֡��������������Ƶ���ţ���ʾ�����ƵĴ��˳��\n
        //! �ӿں���GetHandʹ�ø���Ż�ȡָ����ָĿ�ꡣ
        int             order_id;

        //! @brief ����ID
        //!
        //! [ ȡֵ��Χ 0 ~ 1 ] \n
        //! ��ʾ���Ƶĸ���״̬��ͬһ�������豸��ⷶΧ���˶��Ĺ����У��ᱣ�ָ�����Ų��䡣
        int             track_id;

        //! @brief  ������ָ
        //!
        //! ����GetFinger��ȡ
        int             finger_focus; 

        //! @brief ��������
        //!
        //! ����ֱ����ǰ�������ͣ������� HS_Left �� HS_Right ��ʾ���ֻ����֡� \n
        //! ����豸û���㹻�����ֱ����ƣ��򷵻� HS_Unknown ��ʾ�����޷�ȷ�ϡ�
        HandSide        side;

        //! @brief �����Ƿ�����
        bool            outside;

        //! @brief ������̬
        //!
        //! ���ֱ����ǰ������̬����������Ӧö�ٳ����� \n
        //! ���豸û���㹻�����ֱ�������̬���򷵻� HG_Unknown ��ʾ�����޷�ȷ�ϡ�
        HandGesture     gesture;

        ////! @brief ���Ʊ��ּ�����
        ////!
        ////! �����Ʒ����ı䣬�������ḴλΪ0�������Ʋ��䣬������������ۼӡ�
        //int             gesture_counter;

        //! @brief ����λ��
        //!
        //! �������ĵ���άλ�á�
        Vector3         position;

        //! @brief �����ٶ�
        //!
        //! �������ĵ���ά�ٶȡ�
        Vector3         velocity;

        //! @brief ����X��
        //!
        //! ���ĵ�x������������ָ��ǰ���ֲ�ƽ�����豸�Ϸ�ʱ��x��Ϊ������
        Vector3         axis_x;

        //! @brief ����Y��
        //!
        //! ���ĵ�y������������ָ��ǰ���ֲ�ƽ�����豸�Ϸ�ʱ��y��Ϊָ���Լ��ķ���
        Vector3         axis_y;

        //! @brief ����Z��
        //!
        //! ���ĵ�z������������ָ��ǰ���ֲ�ƽ�����豸�Ϸ�ʱ��z��Ϊ���Ϸ���
        Vector3         axis_z;

        //! @brief Ĵָ����ο���
        //!
        //! �󲿲ο��㣬����Ĵָ��
        Vector3         wrist_thumb;

        //! @brief Сָ����ο���
        //!
        //! �󲿲ο��㣬����Сָ��
        Vector3         wrist_pinky;

        //! @brief �ֱ۷���
        //!
        //! �ֱ۷���ָ�����巽��
        Vector3         arm_direction;

        //! @brief ���λ��
        //!
        //! [ ����ȡֵ��Χ 0.0 ~ 1.0 ] \n
        //! ������λ��ӳ��Ϊ��׼����ƽ��λ�ã���������Ļ�����ơ�
        Vector2         cursor;

        ////! @brief ��Ծ��ָ����
        ////!
        ////! [ ȡֵ��Χ�� 0 ~ 5 ] \n
        ////! ��ǰ���������ָ������
        int             active_number;

        //! @brief ����ָ���
        //!
        //! [ ȡֵ��Χ�� 0 ~ 9 ] \n
        //! ���ڵ�ǰ�ֵĵ�һ����ָ�� \n
        //! ʹ��GetFinger�ӿڣ���ѯfinger_first ~ finger_last����ָ��Ϣ����ʵ�ֵ�ǰ�ֵ���ָ������
        int             finger_first;

        //! @brief ĩ��ָ���
        //!
        //! [ ȡֵ��Χ�� 0 ~ 9 ] \n
        //! ���ڵ�ǰ�ֵ����һ����ָ�� \n
        //! ʹ��GetFinger�ӿڣ���ѯfinger_first ~ finger_last����ָ��Ϣ����ʵ�ֵ�ǰ�ֵ���ָ������
        int             finger_last;

    } Hand;

    //! @brief �ṹ�壺֡����
    //! 
    //! ΢����֡Ϊ��λ����ȡ�豸��֪��Ϣ��֡�����а����˵�ǰ�豸����״̬��������
    //! ʹ�ýӿ� sharpnow::GetFrameInfo �ɻ�õ�ǰ�ṹ�塣
    typedef struct _Frame
    {
        //! @brief �豸�����Ƿ���й�����
        //!
        //! �豸�յ��µ�֡���ݺ��״ε��� sharpnow::RetrieveFrame(int)���ñ�־�ᱻ��Ϊtrue������Ϊfalse��
        bool            updated;

        //! @brief �豸����ģʽ
        //!
        //! �õ��豸����ģʽ��DM_Air �� DM_Touch��
        DeviceMode      mode;

        //! @brief ֡����
        //!
        //! �豸�յ��µ�֡���ݺ󣬻Ὣ�ü������ۼӡ����������ݣ���֡�������䡣
        int             counter;

        //! @brief ֡ʱ��
        //!
        //! ��ǰ֡���ݵĲ���ʱ�䡣
        int             time;

        //! @brief �ڸǼ���
        //!
        //! ʹ�������ڸ��豸��Ұ���ü��������������ӡ�ȡ���ڸǣ��ü���������λΪ0��
        int             blindfold;

        //! @brief ��������
        //!
        //! ��ǰ֡�а���������Ŀ��������
        int             hand_number;

        //! @brief ��ָ����
        //!
        //! ��ǰ֡�а�������ָĿ��������
        int             finger_number;

        //! @brief ��Ծ��ָ����
        //!
        //! [ ȡֵ��Χ�� 0 ~ 10 ] \n
        //! ���������ָ������
        int             active_number;

        //! @brief �豸�����Ƕ�
        float           device_pitch;

        //! @brief �豸����Ƕ�
        float           device_roll;

        //! @brief �豸�ǳ�
        //!
        //! �����豸���ǳƣ����16���ַ�
        char            nick_name[17];

        //! @brief �켣ʶ����
        //!
        //! ΢���Դ���ָ��ʼ�ƶ���ֹͣ�������Ĺ켣������ʶ��ʶ��ĺ�ѡ���������traj_symbol��
        //! ʶ����ȡֵΪTrajSymbol�еĳ���֮һ
        //! Ŀǰ֧�����5����ѡ���
        char            traj_symbol[6];

        //! @brief ����ǿͼ������
        char*           ar_image_left;
        //! @brief ����ǿͼ������
        char*           ar_image_right;
        //! @brief ��ǿͼ����
        int             ar_image_width;
        //! @brief ��ǿͼ��߶�
        int             ar_image_height;

        //! @brief ����ǿͼ�����Ͻ���������
        Vector2         tex_cood1_left;
        //! @brief ����ǿͼ�����½���������
        Vector2         tex_cood2_left;
        //! @brief ����ǿͼ�����Ͻ���������
        Vector2         tex_cood1_right;
        //! @brief ����ǿͼ�����½���������
        Vector2         tex_cood2_right;

    } Frame;

    //! VR��Ŀ����
    typedef struct _VREye
    {
        //! @brief ��Ⱦ�ֱ���
        Vector2     resolution;

        //! @brief ��ü�����
        float       clipping_left;
        //! @brief �Ҳü�����
        float       clipping_right;

        //! @brief �²ü�����
        float       clipping_bottom;
        //! @brief �ϲü�����
        float       clipping_top;

        //! @brief ���ü�����
        float       clipping_near;
        //! @brief Զ�ü�����
        float       clipping_far;

    } VREye;

    //! VR����
    typedef struct _VRConfig
    {
        //! @brief ���۲���
        VREye       eye_left;
        //! @brief ���۲���
        VREye       eye_right;
        //! @brief ˫�۾���
        float       eye_distance;       
        //! @brief ΢����ͶӰ��Ļ�ľ���
        float       vidoo_distance;     

    } VRConfig;


};

#endif
