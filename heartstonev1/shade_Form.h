#pragma once
#include <windows.h>
#include "include/sharpnow.hpp"
#pragma comment(lib, "User32.lib") 
#include <iostream>
#include <string.h>
namespace heartstonev1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// shade_Form ժҪ
	/// </summary>
	public ref class shade_Form : public System::Windows::Forms::Form
	{
	public:
		shade_Form(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~shade_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// shade_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1498, 638);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->ImeMode = System::Windows::Forms::ImeMode::Hiragana;
			this->Name = L"shade_Form";
			this->Opacity = 0.95;
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"shade_Form";
			this->TopMost = true;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &shade_Form::shade_Form_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void shade_Form_Load(System::Object^  sender, System::EventArgs^  e) {
				  Control::CheckForIllegalCrossThreadCalls = false;
				 HWND hWnd1=::FindWindow(NULL,L"shade_Form");
				 DWORD   dwNewLong =   GetWindowLong(hWnd1,   GWL_EXSTYLE); 
				 dwNewLong   |=   WS_EX_TRANSPARENT  ; 
				 SetWindowLong(hWnd1,   GWL_EXSTYLE,   dwNewLong);
// 				 Graphics ^g1=this->CreateGraphics();
// 				 Image ^out1 =  Image::FromFile("1.jpg");
// 				 g1->DrawImage(out1,500,500,20,20);
			 }
	};
}
