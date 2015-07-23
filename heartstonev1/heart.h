#pragma once
#include <windows.h>
#include "include/sharpnow.hpp"
#pragma comment(lib, "User32.lib") 
#include <iostream>
#include <string.h>
#include<strstream>
#include "shade_Form.h"
namespace heartstonev1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace sharpnow;
	using namespace System::Threading;
	using namespace std;
	using namespace heartstonev1;
	
	
	/// <summary>
	/// heart 摘要
	/// </summary>
	public ref class heart : public System::Windows::Forms::Form
	{
	public:
		heart(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~heart()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Label^  label4;

		private: System::Windows::Forms::Panel^  panel1;
		private: System::Windows::Forms::Panel^  panel2;
		private: System::Windows::Forms::Label^  label5;
		private: System::Windows::Forms::Label^  label6;
		private: System::Windows::Forms::Label^  label7;

		private: System::ComponentModel::IContainer^  components;
	protected: 

	protected: 

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(heart::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(409, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(924, 652);
			this->label1->TabIndex = 0;
			this->label1->Click += gcnew System::EventHandler(this, &heart::label1_Click);
			// 
			// label2
			// 
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"label2.Image")));
			this->label2->Location = System::Drawing::Point(1449, 485);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 115);
			this->label2->TabIndex = 1;
			this->label2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &heart::label2_MouseClick);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Black;
			this->label3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"label3.Image")));
			this->label3->Location = System::Drawing::Point(666, 202);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(347, 194);
			this->label3->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Black;
			this->label4->Font = (gcnew System::Drawing::Font(L"黑体", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(73, 202);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(587, 194);
			this->label4->TabIndex = 1;
			this->label4->Text = L"炉石传说提示栏";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label6);
			this->panel1->Location = System::Drawing::Point(1395, 421);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 195);
			this->panel1->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"label6.Image")));
			this->label6->Location = System::Drawing::Point(45, 43);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(107, 112);
			this->label6->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label7);
			this->panel2->Location = System::Drawing::Point(1358, 106);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 169);
			this->panel2->TabIndex = 2;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &heart::panel2_Paint);
			// 
			// label7
			// 
			this->label7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"label7.Image")));
			this->label7->Location = System::Drawing::Point(3, 33);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(108, 113);
			this->label7->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"label5.Image")));
			this->label5->Location = System::Drawing::Point(145, 65);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 36);
			this->label5->TabIndex = 3;
			// 
			// heart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(129)), static_cast<System::Int32>(static_cast<System::Byte>(129)), 
				static_cast<System::Int32>(static_cast<System::Byte>(129)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1724, 685);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"heart";
			this->ShowInTaskbar = false;
			this->Text = L"heart";
			this->TopMost = true;
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(129)), static_cast<System::Int32>(static_cast<System::Byte>(129)), 
				static_cast<System::Int32>(static_cast<System::Byte>(129)));
			this->Load += gcnew System::EventHandler(this, &heart::heart_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void heart_Load(System::Object^  sender, System::EventArgs^  e) {
			Control::CheckForIllegalCrossThreadCalls = false;
				// this->DoubleBuffered=true;
			HWND hWnd1=::FindWindow(NULL,L"heart");
			DWORD   dwNewLong =   GetWindowLong(hWnd1,   GWL_EXSTYLE); 
			dwNewLong   |=   WS_EX_TRANSPARENT  ; 
			SetWindowLong(hWnd1,   GWL_EXSTYLE,   dwNewLong);
			this->Visible=false;

			ThreadStart^ ThreadWork3=gcnew ThreadStart(this,&heart::createThread);
			Thread^ thread3=gcnew Thread(ThreadWork3);
			thread3->Start();
			this->label1->BackColor=TransparencyKey;
			

		}


	public:
		void createThread()

		{

			Graphics ^g1=this->CreateGraphics();
			Image ^out1 =  Image::FromFile("2.jpg");
			//Image ^net=Image::FromFile("20150623055653280_easyicon_net_512.png");
		//	Bitmap net2=Bitmap(net,128,128);
		//	Bitmap ^net2=gcnew Bitmap(net,128,128);
			//g1->DrawImage(net2,1000,1000);
			int flag_show=1;
			int hold_flag=0;
			int a,b;
			int flag=0;
			String ^s1 ;
		    int n=1;//图片的下标

		    int chos=0;
		    sharpnow::SDK sdk;
		    int flag_blind=0;

		    HWND hWnd=::FindWindow(NULL,L"炉石传说");
		    RECT rect;    
		    if(sdk.LoadInPath("lib"))this->Visible=true;

		    std::cout << "等待设备连接 ... " << std::endl;
		    bool connected[] = { false, false };
		    
		    shade_Form ^shf=gcnew shade_Form();
		    
			
		    rect.left=0;
		    rect.top=0;
		    rect.bottom=::GetSystemMetrics(SM_CYSCREEN);
		    rect.right=::GetSystemMetrics(SM_CXSCREEN);
		    this->label5->Visible=false;

		    this->label1->Visible=false;
		    this->label3->Visible=false;
		    this->label4->Visible=false;
		    this->label6->Visible=false;
		    this->label7->Visible=false;
		    int w=rect.right-rect.left,h=rect.bottom-rect.top; 


		    while (true)
		    {			

		    	this->TopMost=true;
				this->Location=Point(rect.left,rect.top);
		    	this->Width=w;
		    	this->Height=h;
		    	this->Location=Point(rect.left,rect.top);
		    	this->Location=Point(rect.left,rect.top);
		    	int device = 0;
		    	if (sdk.RetrieveFrame(0))
		    	{
		    		const sharpnow::Frame* frame = sdk.GetFrameInfo();
		    		const sharpnow::Finger* finger = sdk.GetFingerFocus();
		    		const sharpnow::Hand* hand = sdk.GetHandFocus();
		    		this->label1->Location=Point((w-label1->Width)/2,h*147/1080);
		    		this->label2->Location=Point(w-150,10);
		    		this->label3->Location=Point(this->label1->Location.X+label1->Width-this->label3->Width,label1->Location.Y+label1->Height);
		    		this->label4->Location=Point(this->label1->Location.X,label1->Location.Y+label1->Height);
		    		if (finger)
		    		{
		    			a= int(finger->cursor.x * ::GetSystemMetrics(SM_CXSCREEN));
		    			b=int(finger->cursor.y * ::GetSystemMetrics(SM_CYSCREEN));
		    			//cout<<flag_show<<endl;
		    		}
		    		
					// 检测是否为新连接设备
		    		if (!connected[device])
		    		{
		    			std::cout << "检测到微动 " << device << " 连接" << std::endl;
		    			connected[device] = true;
		    		}

					// 确认收到最新数据和两个手指的定义
		    		if (frame&&frame->updated)
		    		{
		    			if(flag_show){
		    				this->label1->Location=Point((w-label1->Width)/2,h*147/1080);
		    				this->label2->Location=Point(w-150,10);
		    				this->label3->Location=Point(this->label1->Location.X+label1->Width-this->label3->Width,label1->Location.Y+label1->Height);
		    				this->label4->Location=Point(this->label1->Location.X,label1->Location.Y+label1->Height);
		    				this->panel1->Location=Point(rect.left-20,label1->Location.Y);
		    				panel1->Width=this->label1->Location.X-rect.left+20;
		    				panel1->Height=label1->Height;
		    				panel2->Location=Point(this->label1->Location.X+this->label1->Width,label1->Location.Y);
		    				this->panel2->Width=this->panel1->Width+20;
		    				this->panel2->Height=this->panel1->Height;
		    				this->label1->Visible=false;
		    				this->label3->Visible=false;
		    				this->label4->Visible=false;
		    				label6->Location=Point(panel1->Width-label6->Width-20,panel1->Height/2-label6->Height/2);
		    				label7->Location=Point(20,panel2->Height/2-label7->Height/2);
		    				

		    			}
		    			if (frame->active_number>=0&&flag_show==1)

		    			{

		    				if (frame->active_number<=2&&finger)
		    				{
		    					flag=0;
								//单手指模式下，手指控制鼠标的移动；
		    					SetCursorPos(
		    						int(finger->cursor.x * ::GetSystemMetrics(SM_CXSCREEN)),
		    						int(finger->cursor.y * ::GetSystemMetrics(SM_CYSCREEN)));
								//g1->DrawImage(net2,1000,1000);
		    					int x1=int(::GetSystemMetrics(SM_CXSCREEN))*448/1879;
		    					int x2=int(::GetSystemMetrics(SM_CXSCREEN))*1443/1879;
		    					int y1=int(::GetSystemMetrics(SM_CYSCREEN))*109/1057;
		    					int y2=int(::GetSystemMetrics(SM_CYSCREEN))*709/1057;
								int x3=int(::GetSystemMetrics(SM_CXSCREEN))*790/1704;
								int x4=int(::GetSystemMetrics(SM_CXSCREEN))*940/1704;
								int y3=int(::GetSystemMetrics(SM_CYSCREEN))*645/959;
								int y4=int(::GetSystemMetrics(SM_CYSCREEN))*813/959;
		    					if((a>x1&&a<x2&&b>y1&&b<y2)||(a>x3&&a<x4&&b>y3&&b<y4)){
		    						int x,y;

		    						if (finger->stop>=20&&chos==0){
		    							
		    							x=a;
		    							y=b;
		    							chos=1;

		    							this->label5->Location=Point(x-50,y-50);
		    							this->label5->Visible=true;
		    						}
		    						if (chos&&((a-x>100)||(x-a>100)||(y-b>100)||(b-y>100)))
		    						{
		    							this->label5->Visible=false;
		    							chos=0;
		    						}
		    						if (finger->tap&&chos)	{
		    							SetCursorPos(x,y);
		    							mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,x, y,0,0);
		    							this->label5->Visible=false;
		    							chos=0;				

		    						}
		    					}


		    					if(frame->active_number==2)
		    					{
		    						
		    						if (finger->tap)
		    						{
										//设置此时鼠标位置在技能释放点的位置，并且调用方法在此位置点击，完成释放技能的功能；
		    							SetCursorPos(::GetSystemMetrics(SM_CXSCREEN)*1107/1879,::GetSystemMetrics(SM_CYSCREEN)*789/1020);
		    							mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,SM_CXSCREEN*1200/1492,SM_CYSCREEN*390/880,0,0);
		    							this->label5->Visible=false;
		    						}

		    					}

		    					if (!(a>w-150&&a<w&&b>rect.top&&b<rect.top+150)&&frame->active_number==1&&finger->tap){
		    						mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,
		    							int(finger->cursor.x * ::GetSystemMetrics(SM_CXSCREEN)), 
		    							int(finger->cursor.y * ::GetSystemMetrics(SM_CYSCREEN)),0,0);
		    					}
		    					if (a>::GetSystemMetrics(SM_CXSCREEN)-150&&a<::GetSystemMetrics(SM_CXSCREEN)&&b>0&&b<150)
		    					{
									//g1->DrawImage(out1,1500,10,311,121);
		    						if (flag_show&&finger->tap)
		    						{				this->label1->Visible=true;
		    							this->label4->Visible=true;
		    							this->label5->Visible=false;
		    							this->label3->Visible=true;
		    							shf->Show();

		    							this->TopMost=true;
										this->label2->Location=Point(w-150,10);
		    							this->label2->Location=Point(w-150,rect.top+150);
		    							this->label3->Location=Point(this->label1->Location.X+label1->Width-this->label3->Width,label1->Location.Y+label1->Height);
										flag_show=0;
		    							Sleep(2);


		    						}
		    					}

		    				}

		    				

		    				if (frame->active_number==5&&finger)
		    				{
		    					if (!flag)
		    					{
		    						this->label5->Visible=false;
		    						mouse_event(MOUSEEVENTF_RIGHTDOWN|MOUSEEVENTF_RIGHTUP, 
		    							int(finger->cursor.x * ::GetSystemMetrics(SM_CXSCREEN)), 
		    							int(finger->cursor.y * ::GetSystemMetrics(SM_CYSCREEN)),0,0);
		    					}
		    					flag=1;

		    				}




		    				if(frame->active_number>=7&&finger)
		    				{
		    					if(flag!=2)
		    					{
		    						 						
		    						keybd_event(VK_ESCAPE,0,0,0);
		    						keybd_event(VK_ESCAPE,0,KEYEVENTF_KEYUP,0);
		    						Sleep(150);
									SetCursorPos(::GetSystemMetrics(SM_CXSCREEN)*933/1879,::GetSystemMetrics(SM_CYSCREEN)*400/1020);
		    						mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,SM_CXSCREEN*933/1879,SM_CYSCREEN*400/1020,0,0);
		    						flag=2;

		    					}

		    				}

		    				if (frame->blindfold==0)
		    				{
		    					flag_blind=0;
		    				}

		    				if(frame->blindfold&&flag_show==1&&flag_blind==0)
		    				{
		    					
 									//设置鼠标位置在结束回合按钮中心点，并且调用方法在此位置点击，完成结束回合的功能；
		    				//	SetCursorPos(::GetSystemMetrics(SM_CXSCREEN)*986/1879,::GetSystemMetrics(SM_CYSCREEN)*847/1057);
		    				//	mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,SM_CXSCREEN*986/1879,SM_CYSCREEN*847/1057,0,0);
		    					Sleep(10);
		    					SetCursorPos(::GetSystemMetrics(SM_CXSCREEN)*1200/1492,::GetSystemMetrics(SM_CYSCREEN)*390/880);
		    					mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,SM_CXSCREEN*1200/1492,SM_CYSCREEN*390/880,0,0);
		    					if (frame->blindfold>2)
		    					{
		    						flag_blind=1;
		    					}
		    					
		    				}



		    			}

		    			if(frame->blindfold&&flag_show==0&&flag_blind==0)
		    			{
		    				this->label4->Visible=false;
		    				this->label3->Visible=false;			
		    				this->label1->Visible=false;
		    				shf->Hide();
		    				flag_show=1;
		    				if (frame->blindfold>2)
		    				{
		    					flag_blind=1;
		    				}


		    			}
		    			if (frame->active_number>=3&&flag_show==0)
		    			{
		    				if (frame->updated&&finger)
		    				{
		    					
		    					if (finger->velocity.x>0.01&&finger->position.x>0&&n<8)	{
		    						this->label6->Visible=true;
		    						for (int i=0;i<label1->Width/20;i++)
		    						{

		    							this->label1->Location = System::Drawing::Point(label1->Location.X-20, h*147/1080);
										
		    						}
		    						n=n+1;
		    						
		    						s1 = (n).Int32::ToString() ;
		    						Image ^myBitmap =  Image::FromFile(s1+".jpg");

		    						this->label1->Image=myBitmap;
		    						this->label1->Location=Point((w-label1->Width)/2+label1->Width,h*147/1080);
		    						for (int i=0;i<label1->Width/20;i++)
		    						{

		    							this->label1->Location = System::Drawing::Point(label1->Location.X-20, h*147/1080);
		    						}
		    						this->label6->Visible=false;
		    						switch (n)
		    						{
		    							case 1:
		    							label4->Text="遮住设备，退出控制提示";
		    							break;
		    							case 2:
		    							label4->Text="选定要攻击的对象后，tap攻击";
		    							break;
		    							case 3:
		    							label4->Text="出牌选择时，使用tap做选择";
		    							break;
		    							case 4:
		    							label4->Text="首先tap选定攻击方，然后移动到被攻击方，做停顿选定目标";
		    							break;
		    							case 5:
		    							label4->Text="两只手指做tap触发英雄技能";
		    							break;
		    							case 6:
		    							label4->Text="将手指个数变为五指，取消之前做的选定随从和技能的操作";
		    							break;
		    							case 7:
		    							label4->Text="伸出两手，向对方认输";
		    							break;
		    							case 8:
		    							label4->Text="选定随从后，移到要放置的位置，做tap手势将随从放下";
		    							break;
										default:
											break;
		    						}
									
		    					}
		    					if (finger->velocity.x<-0.01&&finger->position.x<0&&n>1)	{
		    						this->label7->Visible=true;
		    						for (int i=0;i<label1->Width/20;i++)
		    						{

		    							this->label1->Location = System::Drawing::Point(label1->Location.X+20, h*147/1080);


		    						}
		    						n=n-1;
		    						
		    						s1 = (n).Int32::ToString() ;
		    						Image ^myBitmap =  Image::FromFile(s1+".jpg");

		    						this->label1->Image=myBitmap;
		    						this->label1->Location=Point((w-label1->Width)/2-label1->Width,h*147/1080);
		    						for (int i=0;i<label1->Width/20;i++)
		    						{

		    							this->label1->Location = System::Drawing::Point(label1->Location.X+20, h*147/1080);
		    							
		    						}
		    						this->label7->Visible=false;
		    						switch (n)
		    						{
		    							case 1:
		    							label4->Text="遮住设备，结束自己当前的回合"+"/n"+"滑动翻页";
		    							break;
		    							case 2:
		    							label4->Text="选定要攻击的对象后，tap攻击";
		    							break;
		    							case 3:	
		    							label4->Text="出牌选择时，使用tap做选择";
		    							break;
		    							case 4:
		    							label4->Text="首先tap选定攻击方，然后移动到被攻击方，做停顿选定目标";
		    							break;
		    							case 5:
		    							label4->Text="两只手指做tap触发英雄技能";
		    							break;
		    							case 6:
		    							label4->Text="将手指个数变为五指，取消之前做的选定随从和技能的操作";
		    							break;
		    							case 7:
		    							label4->Text="伸出两手，向对方认输";
		    							break;
		    							case 8:
		    							label4->Text="选定随从后，移到要放置的位置，做tap手势将随从放下";
		    							break;
										default:
											break;
		    						}
		    					}
		    					
		    					


		    				}
		    				

		    			}

		    		}


		    	}

		    	else
		    	{
					// 检测设备断开
		    		if (connected[device])
		    		{
		    			std::cout << "检测到微动 " << device << " 断开" << std::endl;
		    			connected[device] = false;
		    		}
		    		continue;
		    	}

		    	::Sleep(2);
		    }



		}

		private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			label1->Location=Point((::GetSystemMetrics(SM_CXSCREEN)-label1->Width)/2,
				(::GetSystemMetrics(SM_CYSCREEN)-label1->Height)/2);
		}
		private: System::Void label2_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		}
		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		}
		private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		}
	};
}
