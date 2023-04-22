#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LogIn.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ANDDMSCLIENT::LogIn^ form;
	CClient* c1;
	Pachet^ p;
	c1 = new CClient("172.16.7.81");

	if (!(c1->Start()))
	{
		MessageBox::Show("Serverul nu este online!");
		exit(1);
	}
	p = gcnew Pachet(c1->get_server(), c1->get_stare(), c1);
	form = gcnew ANDDMSCLIENT::LogIn(p);
	Thread^ t = gcnew Thread(gcnew ThreadStart(p, &Pachet::AscThr));
	t->Start();
	form->parsare_client(p);
	form->ShowDialog();
	form->Close();
	c1->Stop();
}