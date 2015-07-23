/********************************************************************/
/* 版权声明：本文件提供的SharpNow SDK的版权属于天津锋时互动科技有限公司。 */
/* 本文件提供的SDK源码可能会发生更新与修改，您需承担使用本SDK的风险。     */
/* 个人或公司可以复制和使用此源码用于微动(ViD)应用程序开发。             */
/* (C) 2011-2015 Tianjin SharpNow Technology. All rights reserved.  */
/********************************************************************/

//! @file
//! 微动感知信息

#ifndef __SHARPNOW_VID_H__
#define __SHARPNOW_VID_H__

#include "mathtypes.h"

//! @namespace
namespace sharpnow
{
    //! @enum HandSide
    //! @brief 枚举常量：手部角色
    //!
    //! 设备可根据手部特征，自动对左右手加以判断。\n
    //! 如果当前线索无法确认手部角色，则为“无法确认”。
    enum HandSide
    {
        HS_Unknown, //!< 无法确认
        HS_Left,    //!< 左手
        HS_Right    //!< 右手
    };

    //! @enum DeviceMode
    //! @brief 枚举常量：设备工作模式
    //!
    //! 微动具有两种工作状态。 \n
    //! 设备可以根据自身的加速计状态自动判断当前工作状态。 \n
    //! 设备平放桌面，视野向上，为空间模式。 \n
    //! 设备竖立至于桌上，视野向前，为触摸模式。
    enum DeviceMode
    {
        DM_Air,     //!< 空间模式，设备感应上空区域
        DM_Touch,   //!< 触摸模式，设备感应前方桌面区域
    };

    //! @enum HandGesture
    //! @brief 枚举常量：手势姿态 
    //!
    //! 微动可以自动识别11种常用静态手势。 \n
    //! 如果当前线索无法确认手势类型，则为“无法确认”。
    enum HandGesture
    {
        HG_Unknown, //!< 无法确认
        HG_Grip,    //!< 握拳，五指收拢或紧握都可
        HG_Point,   //!< 单手指，单手指伸出
        HG_Gun,     //!< 手枪，食指与拇指伸出，做手枪状
        HG_Victory, //!< 胜利，食指与中指伸出，字母V的造型
        HG_Metal,   //!< 金属，食指与小指伸出，音乐会现场常用手势
        HG_Phone,   //!< 电话，拇指与小指伸出，做打电话状
        HG_Fork,    //!< 叉子，拇指、食指、中指伸出
        HG_Three,   //!< 数字三，食指、中指、无名指伸出
        HG_Love,    //!< 爱LOVE，拇指、食指、小指伸出
        HG_Four,    //!< 数字四，食指、中指、无名指、小指伸出
        HG_Five,    //!< 数字五，五指完全伸开

        HG_Good,    //!< 好，拇指伸出
        HG_Draw,    //!< 绘画，食指中指并拢
        HG_OK,      //!< 确认OK，中指小指无名指伸出
        HG_Stop,    //!< 停止， 五指并拢
        HG_Vertical,//!< 垂直， 拇指伸出其余四指并拢
    };

    //! 手部姿态名称字串
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

    //! @brief 枚举常量：对轨迹进行识别后的符号类型，其值为相应的Ascii码
    //!
    //! 微动目前能识别10个数字符号
    //! 无法识别轨迹的情况下，识别结果返回为TS_None
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

    //! @brief 结构体：手指目标
    //! 
    //! 描述了手指目标的感知信息，使用接口GetFinger与GetFingerFocus可获取本结构体信息。
    typedef struct _Finger
    {
        //! @brief 序号ID
        //!
        //! [ 取值范围： 0 ~ 9 ] \n
        //! 一帧中用于区别各手指的序号，表示了手指的存放顺序。\n
        //! 同一只手的手指为连续存放，即具有连续的序号ID。\n
        //! 接口函数GetFinger使用该序号获取指定手指目标。
        int             order_id;

        //! @brief 跟踪ID
        //!
        //! [ 取值范围 0 ~ 9 ] \n
        //! 表示手指的跟踪状态，同一手指在设备检测范围内运动的过程中，会保持跟踪序号不变。
        int             track_id;

        //! @brief 手指角色
        int             role;

        //! @brief 手部ID
        //!
        //! 对应手部序号，使用GetHand可获得相应手部信息。
        int             hand;   

        //! @brief 手部活跃
        //!
        //! 手指是否活跃，手指伸展时处于活跃状态
        bool            active;

        //! @brief 接触状态
        //!
        //! TouchMode中有效，表示手指是否与桌面发生接触。
        bool            contact;

        //! @brief 指戳手势
        //!
        //! Air模式中，手指在短时间内进行前戳动作。 \n
        //! 该变量值在检测到动作的瞬间为true，否则为false。
        bool            poke;

        //! @brief 敲击手势
        //!
        //! Air模式中，手指在短时间内向下运动，然后上扬。 \n
        //! 该变量值在检测到动作的瞬间为true，否则为false。
        bool            tap;

        //! @brief 悬停计数器
        //!
        //! 当前手指悬停（或几乎不发生运动）时，悬停计数器将持续增加。\n
        //! 当手指再次发生移动，该计数器将被复位为0。
        int             stop;

        //! @brief 悬停计数器
        //
        int             circle_dir;

        //! @brief 指尖位置
        //!
        //! 手指指尖的三维位置。
        Vector3         position; 

        //! @brief 指尖速度
        //!
        //! 手指指尖的三维运动速度。
        Vector3         velocity;

        //! @brief 指尖方向
        //!
        //! 代表手指指尖末端方向的三维向量。
        Vector3         direction; 

        //! @brief 光标位置
        //!
        //! [ 两轴取值范围 0.0 ~ 1.0 ] \n
        //! 将手指位置映射为标准化的平面位置，可用于屏幕光标绘制。\n
        //! Air模式映射平面与桌面垂直，Touch模式映射平面与桌面平行。
        Vector2         cursor;

        //! @brief 划动手势方向
        //!
        //! 在映射平面的手指划动方向 \n
        //! Air模式返回一次接触的划动方向。 \n
        //! Touch模式返回一次快速运动的方向。
        Vector2         slide;

        //! @brief 绕圈中心
        //!
        Vector3         circle_center;

        //! @brief 手指长度
        //!
        float           length;

        float           angle_cmc_yaw;
        float           angle_mcp_yaw;
        float           angle_mcp_pitch;
        float           angle_pip;
        float           angle_dip;

        //! @brief 指关节位置0
        //!
        //! 第0手指指关节的三维位置。
        Vector3         joint0;

        //! @brief 指关节位置1
        //!
        //! 第1手指指关节的三维位置。
        Vector3         joint1;

        //! @brief 指关节位置2
        //!
        //! 第2手指指关节的三维位置。
        Vector3         joint2;

        //! @brief 指关节位置3
        //!
        //! 第3手指指关节的三维位置。
        Vector3         joint3;

    } Finger;

    //! @brief 结构体：手掌目标
    //! 
    //! 描述了手掌目标的感知信息，使用接口GetHand与GetHandFocus可获取本结构体信息。
    typedef struct _Hand
    {
        //! @brief 序号ID
        //!
        //! [ 取值范围： 0 ~ 1 ] \n
        //! 一帧中用于区别各手掌的序号，表示了手掌的存放顺序。\n
        //! 接口函数GetHand使用该序号获取指定手指目标。
        int             order_id;

        //! @brief 跟踪ID
        //!
        //! [ 取值范围 0 ~ 1 ] \n
        //! 表示手掌的跟踪状态，同一手掌在设备检测范围内运动的过程中，会保持跟踪序号不变。
        int             track_id;

        //! @brief  焦点手指
        //!
        //! 可用GetFinger获取
        int             finger_focus; 

        //! @brief 手掌类型
        //!
        //! 如果分辨出当前手掌类型，将返回 HS_Left 或 HS_Right 表示左手或右手。 \n
        //! 如果设备没有足够线索分辨手掌，则返回 HS_Unknown 表示尚且无法确认。
        HandSide        side;

        //! @brief 手掌是否向外
        bool            outside;

        //! @brief 手势姿态
        //!
        //! 若分辨出当前手势姿态，将返回相应枚举常量。 \n
        //! 若设备没有足够线索分辨手势姿态，则返回 HG_Unknown 表示尚且无法确认。
        HandGesture     gesture;

        ////! @brief 手势保持计数器
        ////!
        ////! 当手势发生改变，计数器会复位为0；若手势不变，计数器会持续累加。
        //int             gesture_counter;

        //! @brief 手心位置
        //!
        //! 手掌中心的三维位置。
        Vector3         position;

        //! @brief 手心速度
        //!
        //! 手掌中心的三维速度。
        Vector3         velocity;

        //! @brief 手心X轴
        //!
        //! 手心的x轴向量。当手指向前，手部平放于设备上方时。x轴为正左方向。
        Vector3         axis_x;

        //! @brief 手心Y轴
        //!
        //! 手心的y轴向量。当手指向前，手部平放于设备上方时。y轴为指向自己的方向。
        Vector3         axis_y;

        //! @brief 手心Z轴
        //!
        //! 手心的z轴向量。当手指向前，手部平放于设备上方时。z轴为正上方向。
        Vector3         axis_z;

        //! @brief 拇指侧腕参考点
        //!
        //! 腕部参考点，靠近拇指侧
        Vector3         wrist_thumb;

        //! @brief 小指侧腕参考点
        //!
        //! 腕部参考点，靠近小指侧
        Vector3         wrist_pinky;

        //! @brief 手臂方向
        //!
        //! 手臂方向，指向身体方向
        Vector3         arm_direction;

        //! @brief 光标位置
        //!
        //! [ 两轴取值范围 0.0 ~ 1.0 ] \n
        //! 将手心位置映射为标准化的平面位置，可用于屏幕光标绘制。
        Vector2         cursor;

        ////! @brief 活跃手指个数
        ////!
        ////! [ 取值范围： 0 ~ 5 ] \n
        ////! 当前手伸出的手指个数。
        int             active_number;

        //! @brief 首手指序号
        //!
        //! [ 取值范围： 0 ~ 9 ] \n
        //! 属于当前手的第一个手指。 \n
        //! 使用GetFinger接口，查询finger_first ~ finger_last的手指信息，可实现当前手的手指遍历。
        int             finger_first;

        //! @brief 末手指序号
        //!
        //! [ 取值范围： 0 ~ 9 ] \n
        //! 属于当前手的最后一个手指。 \n
        //! 使用GetFinger接口，查询finger_first ~ finger_last的手指信息，可实现当前手的手指遍历。
        int             finger_last;

    } Hand;

    //! @brief 结构体：帧描述
    //! 
    //! 微动以帧为单位，获取设备感知信息。帧描述中包含了当前设备运行状态的描述。
    //! 使用接口 sharpnow::GetFrameInfo 可获得当前结构体。
    typedef struct _Frame
    {
        //! @brief 设备数据是否进行过更新
        //!
        //! 设备收到新的帧数据后，首次调用 sharpnow::RetrieveFrame(int)，该标志会被置为true，否则为false。
        bool            updated;

        //! @brief 设备运行模式
        //!
        //! 得到设备运行模式，DM_Air 或 DM_Touch。
        DeviceMode      mode;

        //! @brief 帧计数
        //!
        //! 设备收到新的帧数据后，会将该计数器累加。若无新数据，则帧计数不变。
        int             counter;

        //! @brief 帧时间
        //!
        //! 当前帧数据的产生时间。
        int             time;

        //! @brief 遮盖计数
        //!
        //! 使用手掌遮盖设备视野，该计数器将持续增加。取消遮盖，该计数器将复位为0。
        int             blindfold;

        //! @brief 手掌数量
        //!
        //! 当前帧中包含的手掌目标数量。
        int             hand_number;

        //! @brief 手指数量
        //!
        //! 当前帧中包含的手指目标数量。
        int             finger_number;

        //! @brief 活跃手指个数
        //!
        //! [ 取值范围： 0 ~ 10 ] \n
        //! 伸出的总手指个数。
        int             active_number;

        //! @brief 设备俯仰角度
        float           device_pitch;

        //! @brief 设备横滚角度
        float           device_roll;

        //! @brief 设备昵称
        //!
        //! 返回设备的昵称，最多16个字符
        char            nick_name[17];

        //! @brief 轨迹识别结果
        //!
        //! 微动对从手指开始移动到停止所经过的轨迹，进行识别，识别的候选结果返回在traj_symbol里
        //! 识别结果取值为TrajSymbol中的常量之一
        //! 目前支持最多5个候选结果
        char            traj_symbol[6];

        //! @brief 左增强图像数据
        char*           ar_image_left;
        //! @brief 右增强图像数据
        char*           ar_image_right;
        //! @brief 增强图像宽度
        int             ar_image_width;
        //! @brief 增强图像高度
        int             ar_image_height;

        //! @brief 左增强图像，左上角纹理坐标
        Vector2         tex_cood1_left;
        //! @brief 左增强图像，右下角纹理坐标
        Vector2         tex_cood2_left;
        //! @brief 右增强图像，左上角纹理坐标
        Vector2         tex_cood1_right;
        //! @brief 右增强图像，右下角纹理坐标
        Vector2         tex_cood2_right;

    } Frame;

    //! VR单目参数
    typedef struct _VREye
    {
        //! @brief 渲染分辨率
        Vector2     resolution;

        //! @brief 左裁剪因子
        float       clipping_left;
        //! @brief 右裁剪因子
        float       clipping_right;

        //! @brief 下裁剪因子
        float       clipping_bottom;
        //! @brief 上裁剪因子
        float       clipping_top;

        //! @brief 近裁剪距离
        float       clipping_near;
        //! @brief 远裁剪距离
        float       clipping_far;

    } VREye;

    //! VR配置
    typedef struct _VRConfig
    {
        //! @brief 左眼参数
        VREye       eye_left;
        //! @brief 右眼参数
        VREye       eye_right;
        //! @brief 双眼距离
        float       eye_distance;       
        //! @brief 微动与投影屏幕的距离
        float       vidoo_distance;     

    } VRConfig;


};

#endif
