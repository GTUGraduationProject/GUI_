#include "Gui.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	BitirmeGui::Gui gui;
	Application::Run(%gui);
}
