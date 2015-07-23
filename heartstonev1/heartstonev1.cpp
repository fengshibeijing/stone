// heartstonev1.cpp: 主项目文件。

#include "stdafx.h"
#include <stdlib.h>
#include "heart.h"
#include "shade_Form.h"
using namespace System;
using namespace System::Threading;
using namespace System::Windows::Forms;
using namespace System;
using namespace heartstonev1;
public ref class ThreadWork
{
public:
	static void shadeform()
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false); 
		Application::Run(gcnew shade_Form()); 
	}
};
int main(array<System::String ^> ^args)
{
	ThreadStart^ ThreadWork1=gcnew ThreadStart(&ThreadWork::shadeform);
	Thread^ thread1=gcnew Thread(ThreadWork1);
	//thread1->Start();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	Application::Run(gcnew heart()); 
    //Console::WriteLine(L"Hello World");
	
    return 0;
}
