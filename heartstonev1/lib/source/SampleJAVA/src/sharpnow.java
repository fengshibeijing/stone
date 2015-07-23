
import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;

class Sharpnow
{
	public interface SDK extends Library
	{
		SDK sdk = (SDK)Native.loadLibrary("sharpnow.dll",SDK.class);
		/***DLL ��������***/
		boolean EmulateHID(HIDEvent event, int data);
		boolean RetrieveFrame(int device);
		com.sun.jna.Pointer GetFrameInfo();  //return Frame*
		com.sun.jna.Pointer GetFinger(int finger);	//return Finger*
		com.sun.jna.Pointer GetFingerFocus();	//return Finger*
		com.sun.jna.Pointer GetHand(int hand);	//return Hand*
		com.sun.jna.Pointer GetHandFocus();		//return Hand*
		
		/***��DLL���ص�ָ������JAVA�Ľṹ�������***/
		static Frame createFrameFromPointer(Pointer pointer,int offset)
		{
			
			Frame frame = new Frame();
			frame.nick_name = new char[17];
			Byte contactByte = pointer.getByte(offset);
			if((int)contactByte == 0)
				frame.updated = false;
			else
				frame.updated = true;
			offset += 1;
			int modeIndex = pointer.getInt(offset);
			if(modeIndex == 0)
			{
				frame.mode = DeviceMode.DM_Air;
			}
			else if(modeIndex == 1)
			{
				frame.mode = DeviceMode.DM_Touch;
			}
			offset += 4;
			frame.counter = pointer.getInt(offset);
			offset += 4;
			frame.time = pointer.getInt(offset);
			offset += 4;
			frame.blindfold = pointer.getInt(offset);
			offset += 4;
			frame.hand_number = pointer.getInt(offset);
			offset += 4;
			frame.finger_number = pointer.getInt(offset);
			offset += 4;
			Vector2 cursorVector = new Vector2();
			cursorVector.x = pointer.getFloat(offset);
			offset += 4;
			cursorVector.y = pointer.getFloat(offset);
			frame.relax_cursor = cursorVector;
			offset += 4;
			frame.nick_name = pointer.getCharArray(offset, 17);
			return frame;
		}
		static Finger createFingerFromPointer(Pointer pointer,int offset)
		{
			Finger finger = new Finger();
			finger.order_id = pointer.getInt(offset);
			offset += 4;
			finger.track_id = pointer.getInt(offset);
			offset += 4;
			finger.hand = pointer.getInt(offset);
			offset += 4;
			Byte contactByte = pointer.getByte(offset);
			if((int)contactByte == 0)
				finger.contact = false;
			else
				finger.contact = true;
			offset += 1;
			Byte pokeByte = pointer.getByte(offset);
			if((int)pokeByte == 0)
				finger.poke = false;
			else
				finger.poke = true;
			offset += 1;
			Byte tapByte = pointer.getByte(offset);
			if((int)tapByte == 0)
				finger.tap = false;
			else
				finger.tap = true;
			offset += 1;
			offset += 1;
			finger.stop = pointer.getInt(offset);
			offset += 4;
			Vector3 positionVector = new Vector3();
			positionVector.x = pointer.getFloat(offset);
			offset += 4;
			positionVector.y = pointer.getFloat(offset);
			offset += 4;
			positionVector.z = pointer.getFloat(offset);
			offset += 4;
			finger.position = positionVector;
			Vector3 velocityVector = new Vector3();
			velocityVector.x = pointer.getFloat(offset);
			offset += 4;
			velocityVector.y = pointer.getFloat(offset);
			offset += 4;
			velocityVector.z = pointer.getFloat(offset);
			offset += 4;
			finger.velocity = velocityVector;
			Vector3 directionVector = new Vector3();
			directionVector.x = pointer.getFloat(offset);
			offset += 4;
			directionVector.y = pointer.getFloat(offset);
			offset += 4;
			directionVector.z = pointer.getFloat(offset);
			offset += 4;
			finger.direction = directionVector;
			Vector2 cursorVector = new Vector2();
			cursorVector.x = pointer.getFloat(offset);
			offset += 4;
			cursorVector.y = pointer.getFloat(offset);
			offset += 4;
			finger.cursor = cursorVector;
			Vector2 slideVector = new Vector2();
			slideVector.x = pointer.getFloat(offset);
			offset += 4;
			slideVector.y = pointer.getFloat(offset);
			offset += 4;
			finger.slide = slideVector;
			return finger;
		}
		static Hand createHandFromPointer(Pointer pointer, int offset)
		{
			Hand hand = new Hand();
			hand.order_id = pointer.getInt(offset);
			offset += 4;
			hand.track_id = pointer.getInt(offset);
			offset += 4;
			int sideIndex = pointer.getInt(offset);
			if(sideIndex == 0)
			{
				hand.side = HandSide.HS_Unknown;
			}
			else if(sideIndex == 1)
			{
				hand.side = HandSide.HS_Left;
			}
			else if(sideIndex == 2)
			{
				hand.side = HandSide.HS_Right;
			}
			offset += 4;
			int gestureIndex = pointer.getInt(offset);
			if(gestureIndex == 0)
				hand.gesture = HandGesture.HG_Unknown;
			else if(gestureIndex == 1)
				hand.gesture = HandGesture.HG_Grip;
			else if(gestureIndex == 2)
				hand.gesture = HandGesture.HG_Point;
			else if(gestureIndex == 3)
				hand.gesture = HandGesture.HG_Gun;
			else if(gestureIndex == 4)
				hand.gesture = HandGesture.HG_Victory;
			else if(gestureIndex == 5)
				hand.gesture = HandGesture.HG_Metal;
			else if(gestureIndex == 6)
				hand.gesture = HandGesture.HG_Phone;
			else if(gestureIndex == 7)
				hand.gesture = HandGesture.HG_Fork;
			else if(gestureIndex == 8)
				hand.gesture = HandGesture.HG_Three;
			else if(gestureIndex == 9)
				hand.gesture = HandGesture.HG_Love;
			else if(gestureIndex == 10)
				hand.gesture = HandGesture.HG_Four;
			else if(gestureIndex == 11)
				hand.gesture = HandGesture.HG_Five;
			offset += 4;
			hand.gesture_counter = pointer.getInt(offset);
			offset += 4;
			Vector3 positionVector = new Vector3();
			positionVector.x = pointer.getFloat(offset);
			offset += 4;
			positionVector.y = pointer.getFloat(offset);
			offset += 4;
			positionVector.z = pointer.getFloat(offset);
			offset += 4;
			hand.position = positionVector;
			Vector3 velocityVector = new Vector3();
			velocityVector.x = pointer.getFloat(offset);
			offset += 4;
			velocityVector.y = pointer.getFloat(offset);
			offset += 4;
			velocityVector.z = pointer.getFloat(offset);
			offset += 4;
			hand.velocity = velocityVector;
			Vector3 axixXVector = new Vector3();
			axixXVector.x = pointer.getFloat(offset);
			offset += 4;
			axixXVector.y = pointer.getFloat(offset);
			offset += 4;
			axixXVector.z = pointer.getFloat(offset);
			offset += 4;
			hand.axis_x = axixXVector;
			Vector3 axixYVector = new Vector3();
			axixYVector.x = pointer.getFloat(offset);
			offset += 4;
			axixYVector.y = pointer.getFloat(offset);
			offset += 4;
			axixYVector.z = pointer.getFloat(offset);
			offset += 4;
			hand.axis_y = axixYVector;
			Vector3 axixZVector = new Vector3();
			axixZVector.x = pointer.getFloat(offset);
			offset += 4;
			axixZVector.y = pointer.getFloat(offset);
			offset += 4;
			axixZVector.z = pointer.getFloat(offset);
			offset += 4;
			hand.axis_z = axixZVector;
			Vector2 cursorVector = new Vector2();
			cursorVector.x = pointer.getFloat(offset);
			offset += 4;
			cursorVector.y = pointer.getFloat(offset);
			offset += 4;
			hand.cursor = cursorVector;
			hand.finger_number = pointer.getInt(offset);
			offset += 4;
			hand.finger_first = pointer.getInt(offset);
			offset += 4;
			hand.finger_last = pointer.getInt(offset);
			//offset += 4;
			return hand;
		}
	}
		/****�ṹ���ಿ��****/
		public static class Frame
		{
			public boolean 			   updated;
	        public DeviceMode          mode;               //!< �豸��ǰģʽ
	        public int                 counter;            //!< ֡����
	        public int                 time;               //!< ֡ʱ��
	        public int                 blindfold;          //!< �ڸǼ���
	
	        public int                 hand_number;        //!< �ֲ�����
	        public int                 finger_number;      //!< ��ָ����
	
	        public Vector2             relax_cursor;       //!< ΢���׼�����λ��
	        public char           	   nick_name[];
		}
	    // -----------------------------------------------------------------
	    //! �ࣺ��ָĿ��
		public static class Finger
	    {
	        public int                 order_id;       //!< ���ID
	        public int                 track_id;       //!< ����ID
	        public int                 hand;           //!< ��Ӧ�ֲ������
	
	        public boolean             contact;        //!< �Ƿ�Ӵ�
	        public boolean             poke;           //!< �Ƿ���ָ������
	        public boolean		       tap;           //!< �Ƿ������µ������
	        public int                 stop;           //!< ��ֹ������
	
	        public Vector3             position;       //!< ָ��λ��
	        public Vector3             velocity;       //!< ָ���ٶ�
	        public Vector3             direction;      //!< ָ�ⷽ��
	        public Vector2             cursor;         //!< ��׼�����λ��
	        public Vector2             slide;
	    }
	    // -----------------------------------------------------------------
	    //! �ࣺ�ֲ�Ŀ��
		public static class Hand
	    {
			public int          	   order_id;       //!< ���ID
			public int                 track_id;       //!< ����ID
			public HandSide            side;           //!< ������
			public HandGesture         gesture;        //!< �ֲ���̬
			public int				   gesture_counter;
			public Vector3             position;       //!< ����λ��
			public Vector3             velocity;       //!< �����ٶ�
			public Vector3             axis_x;         //!< �ֲ�x��
			public Vector3             axis_y;         //!< �ֲ�y��
			public Vector3             axis_z;         //!< �ֲ�z��
			public Vector2             cursor;         //!< ���ı�׼�����λ��
	
			public int                 finger_number;  //!< ���ڵ�ǰ�ֵ���ָ����
			public int                 finger_first;   //!< ���ڵ�ǰ�ֵ�����ָ
			public int                 finger_last;    //!< ���ڵ�ǰ�ֵ�ĩ��ָ
	    } 
		public static class Vector2
		{
			public float   x;  //!< x�����
			public float   y;  //!< y�����
		}
		
		public static class Vector3
		{
			public float   x;  //!< x�����
			public float   y;  //!< y�����
			public float   z;  //!< z�����
		}
	    // -----------------------------------------------------------------
	    //! ö�٣��ֲ���ɫ
	    public enum HandSide
	    {
	        HS_Unknown, //!< δ֪
	        HS_Left,    //!< ����
	        HS_Right    //!< ����
	    };
	    // -----------------------------------------------------------------
	    //! ö�٣��豸ģʽ
	    public enum DeviceMode
	    {
	        DM_Air,     //!< �ռ�ģʽ
	        DM_Touch,   //!< ����ģʽ
	    };
		 // ----------------------------------------------------------------
	    //! ö�٣���������
	    public enum HandGesture
	    {
	        HG_Unknown, //!< δ֪
	        HG_Grip,    //!< ��ȭ
	        HG_Point,   //!< ����ָ
	        HG_Gun,     //!< ��ǹ
	        HG_Victory, //!< ʤ��
	        HG_Metal,   //!< ����
	        HG_Phone,   //!< �绰
	        HG_Fork,    //!< ����
	        HG_Three,   //!< ������
	        HG_Love,    //!< ��LOVE
	        HG_Four,    //!< ������
	        HG_Five,    //!< ������
	    };
	    // -----------------------------------------------------------------
	    //! ö�٣�HID�¼�
	    public enum HIDEvent
	    {
	        // ����¼�
	        Mouse_MoveX,        //!< Xλ��
	        Mouse_MoveY,        //!< Yλ��
	        Mouse_Wheel,        //!< ����
	        Mouse_ButtonDown,   //!< ��������
	        Mouse_ButtonUp,     //!< ����̧��
	        Mouse_Flush,        //!< ˢ��
	
	        // �����¼�
	        Keyboard_Down,      //!< ���°������ɼ��ַ���
	        Keyboard_Up,        //!< ̧�𰴼����ɼ��ַ���
	        Keyboard_DownEx,    //!< ���°��������⹦�ܣ�
	        Keyboard_UpEx,      //!< ̧�𰴼������⹦�ܣ�
	        Keyboard_Flush,     //!< ˢ��
	
	        // ��Ϸ���¼�
	        Joystick_X,         //!< X��
	        Joystick_Y,         //!< Y��
	        Joystick_Z,         //!< Z��
	        Joystick_RX,        //!< X����
	        Joystick_RY,        //!< Y����
	        Joystick_RZ,        //!< Z����
	        Joystick_Slider,    //!< ����
	        Joystick_Dial,      //!< ����
	        Joystick_Hat,       //!< ��׼
	        Joystick_ButtonDown,//!< ��������
	        Joystick_ButtonUp,  //!< ����̧��
	        Joystick_Flush,     //!< ˢ��
	
	        // ��Ϸ��2�¼�
	        Joystick2_X,        //!< X��
	        Joystick2_Y,        //!< Y��
	        Joystick2_Z,        //!< Z��
	        Joystick2_RX,       //!< X����
	        Joystick2_RY,       //!< Y����
	        Joystick2_RZ,       //!< Z����
	        Joystick2_Slider,   //!< ����
	        Joystick2_Dial,     //!< ����
	        Joystick2_Hat,      //!< ��׼
	        Joystick2_ButtonDown,//!< ��������
	        Joystick2_ButtonUp, //!< ����̧��
	        Joystick2_Flush,    //!< ˢ��
	
	        // ��㴥�����¼�
	        Touch_ContactID,    //!< �Ӵ���ID
	        Touch_Status,       //!< ״̬
	        Touch_X,            //!< Xλ��
	        Touch_Y,            //!< Yλ��
	        Touch_Height,       //!< �߶�
	        Touch_Flush,        //!< ˢ��
	    };
	    // -----------------------------------------------------------------
	    //! ö�٣����ⰴ��
	    public enum KeyEx
	    {
	        KeyEx_CtrL,
	        KeyEx_ShiftL,
	        KeyEx_AltL,
	        KeyEx_WinL,
	        KeyEx_CtrR,
	        KeyEx_ShiftR,
	        KeyEx_AltR,
	        KeyEx_WinR,
	
	        KeyEx_Left,
	        KeyEx_Right,
	        KeyEx_Up,
	        KeyEx_Down,
	        KeyEx_Home,
	        KeyEx_End,
	        KeyEx_PageUp,
	        KeyEx_PageDown,
	        KeyEx_Insert,
	        KeyEx_Delete,
	        KeyEx_Esc,
	        KeyEx_Backspace,
	        KeyEx_Enter,
	        KeyEx_Tab,
	        KeyEx_Space,
	
	        KeyEx_F1,
	        KeyEx_F2,
	        KeyEx_F3,
	        KeyEx_F4,
	        KeyEx_F5,
	        KeyEx_F6,
	        KeyEx_F7,
	        KeyEx_F8,
	        KeyEx_F9,
	        KeyEx_F10,
	        KeyEx_F11,
	        KeyEx_F12,
	
	        KeyEx_Pad0,
	        KeyEx_Pad1,
	        KeyEx_Pad2,
	        KeyEx_Pad3,
	        KeyEx_Pad4,
	        KeyEx_Pad5,
	        KeyEx_Pad6,
	        KeyEx_Pad7,
	        KeyEx_Pad8,
	        KeyEx_Pad9,
	        KeyEx_PadDot,
	        KeyEx_PadAdd,
	        KeyEx_PadSub,
	        KeyEx_PadMul,
	        KeyEx_PadDiv,
	        KeyEx_PadEnter,
	    };
}

