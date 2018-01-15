#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <sdkddkver.h>
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <cstring>
#include <msclr/marshal.h>
#include <Xinput.h>
#include <cctype>
#include "MyForm.h"
#include <math.h>
#define SCK_VERSION 0x0202
#define PI 3.14159265

namespace BitirmeGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Diagnostics;
	using namespace System::Runtime::InteropServices;

	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	char* message;
	int second = 0, second2 = 0;
	int sensorInf[1000][4], directionCounter = 0, sensorCounter=0;
	float directionInf[1000][2];
	bool drawMap = false;
	int mapCounter = 0;
	struct ServerMessage
	{
		//int command;
		int sensor1;
		int sensor2;
		int sensor3;
		int temperature;
		int gas;
		int flame;
		float dirDegree;
		float traveled;
	};

	struct ClientMessage
	{
		int command;
		int drivingMode;
		int demoType;
		int motorState;
		int speed;

	};
	struct ClientMessage clientMessage;
	struct ServerMessage serverMessage;
	/// <summary>
	/// Summary for Gui
	/// </summary>
	public ref class Gui : public System::Windows::Forms::Form
	{

	public:
		Gui(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		[DllImport("user32.dll")]
		static IntPtr SetParent(IntPtr hwc, IntPtr hwp);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Gui()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textbox_rpi_ip;
	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox_drivingMode;
	private: System::Windows::Forms::Button^  button_connect;
	private: System::Windows::Forms::Button^  button_get;
	private: System::Windows::Forms::Button^  button_update;
	private: System::Windows::Forms::Button^  button_livecam;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::GroupBox^  groupBox1;



	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ProgressBar^  progressBar_leftSensor;
	private: System::Windows::Forms::ProgressBar^  progressBar_rightSensor;
	private: System::Windows::Forms::ProgressBar^  progressBar_temperature;



	private: System::Windows::Forms::ProgressBar^  progressBar_frontSensor;
	private: System::Windows::Forms::CheckBox^  checkBox_flame;
	private: System::Windows::Forms::CheckBox^  checkBox_gas;
	private: System::Windows::Forms::TextBox^  textBox_debug;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::GroupBox^  groupBox3;


	private: System::Windows::Forms::PictureBox^  pictureBox_connection;


	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Button^  button_disconnect;
	private: System::Windows::Forms::PictureBox^  pictureBox_notConnected;
	private: System::Windows::Forms::PictureBox^  pictureBox_frontSensor;
	private: System::Windows::Forms::PictureBox^  pictureBox_leftSensor;


	private: System::Windows::Forms::PictureBox^  pictureBox_rightSensor;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Label^  label_tempSensor;


	private: System::Windows::Forms::Label^  label_rightSensor;

	private: System::Windows::Forms::Label^  label_leftSensor;

	private: System::Windows::Forms::Label^  label_frontSensor;

	private: System::Windows::Forms::CheckBox^  checkBox_demo3;
	private: System::Windows::Forms::CheckBox^  checkBox_demo2;
	private: System::Windows::Forms::CheckBox^  checkBox_demo1;
	private: System::Windows::Forms::Button^  button_stopCar;
	private: System::Windows::Forms::Button^  button_start;
	private: System::Windows::Forms::TrackBar^  speedBar;
	private: System::Windows::Forms::Label^  speedLabel;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::PrintDialog^  printDialog1;
	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TrackBar^  volumeBar;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label9;











	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		bool nonNumberEntered;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Gui::typeid));
			this->textbox_rpi_ip = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox_drivingMode = (gcnew System::Windows::Forms::ComboBox());
			this->button_connect = (gcnew System::Windows::Forms::Button());
			this->button_get = (gcnew System::Windows::Forms::Button());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->button_livecam = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_tempSensor = (gcnew System::Windows::Forms::Label());
			this->label_rightSensor = (gcnew System::Windows::Forms::Label());
			this->label_leftSensor = (gcnew System::Windows::Forms::Label());
			this->label_frontSensor = (gcnew System::Windows::Forms::Label());
			this->checkBox_flame = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_gas = (gcnew System::Windows::Forms::CheckBox());
			this->progressBar_leftSensor = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar_rightSensor = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar_temperature = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar_frontSensor = (gcnew System::Windows::Forms::ProgressBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->button_stopCar = (gcnew System::Windows::Forms::Button());
			this->checkBox_demo3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_demo2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_demo1 = (gcnew System::Windows::Forms::CheckBox());
			this->button_disconnect = (gcnew System::Windows::Forms::Button());
			this->pictureBox_notConnected = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_connection = (gcnew System::Windows::Forms::PictureBox());
			this->textBox_debug = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox_frontSensor = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_leftSensor = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_rightSensor = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->speedBar = (gcnew System::Windows::Forms::TrackBar());
			this->speedLabel = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->volumeBar = (gcnew System::Windows::Forms::TrackBar());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_notConnected))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_connection))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_frontSensor))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_leftSensor))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_rightSensor))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->speedBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// textbox_rpi_ip
			// 
			this->textbox_rpi_ip->Location = System::Drawing::Point(101, 25);
			this->textbox_rpi_ip->Name = L"textbox_rpi_ip";
			this->textbox_rpi_ip->Size = System::Drawing::Size(121, 20);
			this->textbox_rpi_ip->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"RPi IP:";
			this->label1->Click += gcnew System::EventHandler(this, &Gui::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Driving Mode:";
			this->label2->Click += gcnew System::EventHandler(this, &Gui::label2_Click);
			// 
			// comboBox_drivingMode
			// 
			this->comboBox_drivingMode->AllowDrop = true;
			this->comboBox_drivingMode->FormattingEnabled = true;
			this->comboBox_drivingMode->Location = System::Drawing::Point(101, 51);
			this->comboBox_drivingMode->Name = L"comboBox_drivingMode";
			this->comboBox_drivingMode->Size = System::Drawing::Size(121, 21);
			this->comboBox_drivingMode->TabIndex = 4;
			this->comboBox_drivingMode->SelectedIndexChanged += gcnew System::EventHandler(this, &Gui::comboBox_drivingMode_SelectedIndexChanged);
			// 
			// button_connect
			// 
			this->button_connect->Location = System::Drawing::Point(18, 113);
			this->button_connect->Name = L"button_connect";
			this->button_connect->Size = System::Drawing::Size(75, 23);
			this->button_connect->TabIndex = 5;
			this->button_connect->Text = L"Connect";
			this->button_connect->UseVisualStyleBackColor = true;
			this->button_connect->Click += gcnew System::EventHandler(this, &Gui::button_connect_Click);
			// 
			// button_get
			// 
			this->button_get->Location = System::Drawing::Point(18, 185);
			this->button_get->Name = L"button_get";
			this->button_get->Size = System::Drawing::Size(75, 23);
			this->button_get->TabIndex = 6;
			this->button_get->Text = L"Get";
			this->button_get->UseVisualStyleBackColor = true;
			this->button_get->Click += gcnew System::EventHandler(this, &Gui::button_get_Click);
			// 
			// button_update
			// 
			this->button_update->Location = System::Drawing::Point(147, 185);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(81, 23);
			this->button_update->TabIndex = 7;
			this->button_update->Text = L"Update";
			this->button_update->UseVisualStyleBackColor = true;
			// 
			// button_livecam
			// 
			this->button_livecam->Location = System::Drawing::Point(146, 147);
			this->button_livecam->Name = L"button_livecam";
			this->button_livecam->Size = System::Drawing::Size(82, 23);
			this->button_livecam->TabIndex = 8;
			this->button_livecam->Text = L"Live Cam";
			this->button_livecam->UseVisualStyleBackColor = true;
			this->button_livecam->Click += gcnew System::EventHandler(this, &Gui::button_livecam_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 30);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Front Sensor:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Right Sensor:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 59);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(64, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Left Sensor:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label_tempSensor);
			this->groupBox1->Controls->Add(this->label_rightSensor);
			this->groupBox1->Controls->Add(this->label_leftSensor);
			this->groupBox1->Controls->Add(this->label_frontSensor);
			this->groupBox1->Controls->Add(this->checkBox_flame);
			this->groupBox1->Controls->Add(this->checkBox_gas);
			this->groupBox1->Controls->Add(this->progressBar_leftSensor);
			this->groupBox1->Controls->Add(this->progressBar_rightSensor);
			this->groupBox1->Controls->Add(this->progressBar_temperature);
			this->groupBox1->Controls->Add(this->progressBar_frontSensor);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Location = System::Drawing::Point(288, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(229, 224);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sensors";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Gui::groupBox1_Enter);
			// 
			// label_tempSensor
			// 
			this->label_tempSensor->AutoSize = true;
			this->label_tempSensor->Location = System::Drawing::Point(187, 116);
			this->label_tempSensor->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_tempSensor->Name = L"label_tempSensor";
			this->label_tempSensor->Size = System::Drawing::Size(13, 13);
			this->label_tempSensor->TabIndex = 26;
			this->label_tempSensor->Text = L"0";
			// 
			// label_rightSensor
			// 
			this->label_rightSensor->AutoSize = true;
			this->label_rightSensor->Location = System::Drawing::Point(188, 87);
			this->label_rightSensor->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_rightSensor->Name = L"label_rightSensor";
			this->label_rightSensor->Size = System::Drawing::Size(13, 13);
			this->label_rightSensor->TabIndex = 25;
			this->label_rightSensor->Text = L"0";
			// 
			// label_leftSensor
			// 
			this->label_leftSensor->AutoSize = true;
			this->label_leftSensor->Location = System::Drawing::Point(188, 59);
			this->label_leftSensor->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_leftSensor->Name = L"label_leftSensor";
			this->label_leftSensor->Size = System::Drawing::Size(13, 13);
			this->label_leftSensor->TabIndex = 24;
			this->label_leftSensor->Text = L"0";
			// 
			// label_frontSensor
			// 
			this->label_frontSensor->AutoSize = true;
			this->label_frontSensor->Location = System::Drawing::Point(188, 28);
			this->label_frontSensor->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_frontSensor->Name = L"label_frontSensor";
			this->label_frontSensor->Size = System::Drawing::Size(13, 13);
			this->label_frontSensor->TabIndex = 23;
			this->label_frontSensor->Text = L"0";
			// 
			// checkBox_flame
			// 
			this->checkBox_flame->AutoSize = true;
			this->checkBox_flame->Location = System::Drawing::Point(9, 185);
			this->checkBox_flame->Name = L"checkBox_flame";
			this->checkBox_flame->Size = System::Drawing::Size(54, 17);
			this->checkBox_flame->TabIndex = 22;
			this->checkBox_flame->Text = L"Flame";
			this->checkBox_flame->UseVisualStyleBackColor = true;
			// 
			// checkBox_gas
			// 
			this->checkBox_gas->AutoSize = true;
			this->checkBox_gas->Location = System::Drawing::Point(9, 149);
			this->checkBox_gas->Name = L"checkBox_gas";
			this->checkBox_gas->Size = System::Drawing::Size(45, 17);
			this->checkBox_gas->TabIndex = 21;
			this->checkBox_gas->Text = L"Gas";
			this->checkBox_gas->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->checkBox_gas->UseVisualStyleBackColor = true;
			// 
			// progressBar_leftSensor
			// 
			this->progressBar_leftSensor->Location = System::Drawing::Point(82, 54);
			this->progressBar_leftSensor->Name = L"progressBar_leftSensor";
			this->progressBar_leftSensor->Size = System::Drawing::Size(100, 23);
			this->progressBar_leftSensor->TabIndex = 20;
			// 
			// progressBar_rightSensor
			// 
			this->progressBar_rightSensor->Location = System::Drawing::Point(82, 82);
			this->progressBar_rightSensor->Name = L"progressBar_rightSensor";
			this->progressBar_rightSensor->Size = System::Drawing::Size(100, 23);
			this->progressBar_rightSensor->TabIndex = 19;
			this->progressBar_rightSensor->Click += gcnew System::EventHandler(this, &Gui::progressBar3_Click);
			// 
			// progressBar_temperature
			// 
			this->progressBar_temperature->Location = System::Drawing::Point(82, 110);
			this->progressBar_temperature->Name = L"progressBar_temperature";
			this->progressBar_temperature->Size = System::Drawing::Size(100, 23);
			this->progressBar_temperature->TabIndex = 18;
			// 
			// progressBar_frontSensor
			// 
			this->progressBar_frontSensor->Location = System::Drawing::Point(82, 25);
			this->progressBar_frontSensor->Name = L"progressBar_frontSensor";
			this->progressBar_frontSensor->Size = System::Drawing::Size(100, 23);
			this->progressBar_frontSensor->TabIndex = 17;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 113);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Temperature:";
			this->label6->Click += gcnew System::EventHandler(this, &Gui::label6_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button_start);
			this->groupBox2->Controls->Add(this->button_stopCar);
			this->groupBox2->Controls->Add(this->checkBox_demo3);
			this->groupBox2->Controls->Add(this->checkBox_demo2);
			this->groupBox2->Controls->Add(this->checkBox_demo1);
			this->groupBox2->Controls->Add(this->button_disconnect);
			this->groupBox2->Controls->Add(this->pictureBox_notConnected);
			this->groupBox2->Controls->Add(this->pictureBox_connection);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->textbox_rpi_ip);
			this->groupBox2->Controls->Add(this->button_livecam);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->button_update);
			this->groupBox2->Controls->Add(this->comboBox_drivingMode);
			this->groupBox2->Controls->Add(this->button_get);
			this->groupBox2->Controls->Add(this->button_connect);
			this->groupBox2->Location = System::Drawing::Point(12, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(253, 224);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Configurations";
			// 
			// button_start
			// 
			this->button_start->Location = System::Drawing::Point(190, 115);
			this->button_start->Margin = System::Windows::Forms::Padding(2);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(38, 23);
			this->button_start->TabIndex = 24;
			this->button_start->Text = L"Start";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &Gui::button_start_Click);
			// 
			// button_stopCar
			// 
			this->button_stopCar->Location = System::Drawing::Point(147, 115);
			this->button_stopCar->Margin = System::Windows::Forms::Padding(2);
			this->button_stopCar->Name = L"button_stopCar";
			this->button_stopCar->Size = System::Drawing::Size(38, 23);
			this->button_stopCar->TabIndex = 23;
			this->button_stopCar->Text = L"Stop";
			this->button_stopCar->UseVisualStyleBackColor = true;
			this->button_stopCar->Click += gcnew System::EventHandler(this, &Gui::button1_Click);
			// 
			// checkBox_demo3
			// 
			this->checkBox_demo3->AutoSize = true;
			this->checkBox_demo3->Location = System::Drawing::Point(142, 84);
			this->checkBox_demo3->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_demo3->Name = L"checkBox_demo3";
			this->checkBox_demo3->Size = System::Drawing::Size(60, 17);
			this->checkBox_demo3->TabIndex = 22;
			this->checkBox_demo3->Text = L"Demo3";
			this->checkBox_demo3->UseVisualStyleBackColor = true;
			// 
			// checkBox_demo2
			// 
			this->checkBox_demo2->AutoSize = true;
			this->checkBox_demo2->Location = System::Drawing::Point(82, 83);
			this->checkBox_demo2->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_demo2->Name = L"checkBox_demo2";
			this->checkBox_demo2->Size = System::Drawing::Size(60, 17);
			this->checkBox_demo2->TabIndex = 21;
			this->checkBox_demo2->Text = L"Demo2";
			this->checkBox_demo2->UseVisualStyleBackColor = true;
			// 
			// checkBox_demo1
			// 
			this->checkBox_demo1->AutoSize = true;
			this->checkBox_demo1->Location = System::Drawing::Point(21, 82);
			this->checkBox_demo1->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_demo1->Name = L"checkBox_demo1";
			this->checkBox_demo1->Size = System::Drawing::Size(60, 17);
			this->checkBox_demo1->TabIndex = 20;
			this->checkBox_demo1->Text = L"Demo1";
			this->checkBox_demo1->UseVisualStyleBackColor = true;
			// 
			// button_disconnect
			// 
			this->button_disconnect->Location = System::Drawing::Point(18, 149);
			this->button_disconnect->Name = L"button_disconnect";
			this->button_disconnect->Size = System::Drawing::Size(75, 23);
			this->button_disconnect->TabIndex = 19;
			this->button_disconnect->Text = L"Disconnect";
			this->button_disconnect->UseVisualStyleBackColor = true;
			this->button_disconnect->Click += gcnew System::EventHandler(this, &Gui::button_disconnect_Click);
			// 
			// pictureBox_notConnected
			// 
			this->pictureBox_notConnected->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_notConnected.Image")));
			this->pictureBox_notConnected->Location = System::Drawing::Point(99, 154);
			this->pictureBox_notConnected->Name = L"pictureBox_notConnected";
			this->pictureBox_notConnected->Size = System::Drawing::Size(15, 16);
			this->pictureBox_notConnected->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_notConnected->TabIndex = 18;
			this->pictureBox_notConnected->TabStop = false;
			this->pictureBox_notConnected->Visible = false;
			// 
			// pictureBox_connection
			// 
			this->pictureBox_connection->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_connection.Image")));
			this->pictureBox_connection->Location = System::Drawing::Point(99, 115);
			this->pictureBox_connection->Name = L"pictureBox_connection";
			this->pictureBox_connection->Size = System::Drawing::Size(15, 16);
			this->pictureBox_connection->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_connection->TabIndex = 17;
			this->pictureBox_connection->TabStop = false;
			this->pictureBox_connection->Visible = false;
			// 
			// textBox_debug
			// 
			this->textBox_debug->Location = System::Drawing::Point(153, 254);
			this->textBox_debug->Name = L"textBox_debug";
			this->textBox_debug->Size = System::Drawing::Size(100, 20);
			this->textBox_debug->TabIndex = 14;
			this->textBox_debug->TextChanged += gcnew System::EventHandler(this, &Gui::textBox_debug_TextChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Gui::timer1_Tick);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->pictureBox_frontSensor);
			this->groupBox3->Controls->Add(this->pictureBox_leftSensor);
			this->groupBox3->Controls->Add(this->pictureBox_rightSensor);
			this->groupBox3->Controls->Add(this->pictureBox1);
			this->groupBox3->Location = System::Drawing::Point(12, 298);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(387, 262);
			this->groupBox3->TabIndex = 15;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"FireCar";
			// 
			// pictureBox_frontSensor
			// 
			this->pictureBox_frontSensor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_frontSensor.Image")));
			this->pictureBox_frontSensor->Location = System::Drawing::Point(141, 25);
			this->pictureBox_frontSensor->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox_frontSensor->Name = L"pictureBox_frontSensor";
			this->pictureBox_frontSensor->Size = System::Drawing::Size(80, 39);
			this->pictureBox_frontSensor->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_frontSensor->TabIndex = 3;
			this->pictureBox_frontSensor->TabStop = false;
			this->pictureBox_frontSensor->Visible = false;
			this->pictureBox_frontSensor->Click += gcnew System::EventHandler(this, &Gui::pictureBox_frontSensor_Click);
			// 
			// pictureBox_leftSensor
			// 
			this->pictureBox_leftSensor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_leftSensor.Image")));
			this->pictureBox_leftSensor->Location = System::Drawing::Point(88, 97);
			this->pictureBox_leftSensor->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox_leftSensor->Name = L"pictureBox_leftSensor";
			this->pictureBox_leftSensor->Size = System::Drawing::Size(36, 87);
			this->pictureBox_leftSensor->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_leftSensor->TabIndex = 2;
			this->pictureBox_leftSensor->TabStop = false;
			this->pictureBox_leftSensor->Visible = false;
			this->pictureBox_leftSensor->Click += gcnew System::EventHandler(this, &Gui::pictureBox_leftSensor_Click);
			// 
			// pictureBox_rightSensor
			// 
			this->pictureBox_rightSensor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_rightSensor.Image")));
			this->pictureBox_rightSensor->Location = System::Drawing::Point(242, 97);
			this->pictureBox_rightSensor->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox_rightSensor->Name = L"pictureBox_rightSensor";
			this->pictureBox_rightSensor->Size = System::Drawing::Size(36, 87);
			this->pictureBox_rightSensor->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_rightSensor->TabIndex = 1;
			this->pictureBox_rightSensor->TabStop = false;
			this->pictureBox_rightSensor->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(137, 77);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(88, 179);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &Gui::timer2_Tick);
			// 
			// speedBar
			// 
			this->speedBar->AccessibleRole = System::Windows::Forms::AccessibleRole::ScrollBar;
			this->speedBar->Location = System::Drawing::Point(425, 298);
			this->speedBar->Maximum = 5;
			this->speedBar->Name = L"speedBar";
			this->speedBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->speedBar->Size = System::Drawing::Size(45, 262);
			this->speedBar->TabIndex = 17;
			this->speedBar->Tag = L"23";
			this->speedBar->Value = 5;
			this->speedBar->Scroll += gcnew System::EventHandler(this, &Gui::speedBar_Scroll);
			// 
			// speedLabel
			// 
			this->speedLabel->AutoSize = true;
			this->speedLabel->Location = System::Drawing::Point(431, 290);
			this->speedLabel->Name = L"speedLabel";
			this->speedLabel->Size = System::Drawing::Size(13, 13);
			this->speedLabel->TabIndex = 18;
			this->speedLabel->Tag = L"label7";
			this->speedLabel->Text = L"5";
			this->speedLabel->Click += gcnew System::EventHandler(this, &Gui::label7_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(21, 254);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 19;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Gui::textBox1_TextChanged);
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(543, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(53, 21);
			this->button1->TabIndex = 21;
			this->button1->Text = L"2DMap";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Gui::button1_Click_1);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(496, 274);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 13);
			this->label7->TabIndex = 23;
			this->label7->Text = L"Up";
			this->label7->Click += gcnew System::EventHandler(this, &Gui::label7_Click_1);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(285, 274);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 24;
			this->label8->Text = L"Down";
			this->label8->Click += gcnew System::EventHandler(this, &Gui::label8_Click);
			// 
			// volumeBar
			// 
			this->volumeBar->LargeChange = 1;
			this->volumeBar->Location = System::Drawing::Point(288, 242);
			this->volumeBar->Maximum = 1;
			this->volumeBar->Name = L"volumeBar";
			this->volumeBar->Size = System::Drawing::Size(229, 45);
			this->volumeBar->TabIndex = 25;
			this->volumeBar->Tag = L"25";
			this->volumeBar->Value = 1;
			this->volumeBar->Scroll += gcnew System::EventHandler(this, &Gui::trackBar1_Scroll);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1218, 642);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 18);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 26;
			this->pictureBox2->TabStop = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(1317, 638);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(21, 13);
			this->label9->TabIndex = 27;
			this->label9->Text = L"cm";
			// 
			// Gui
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1334, 661);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->volumeBar);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->speedLabel);
			this->Controls->Add(this->speedBar);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->textBox_debug);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->KeyPreview = true;
			this->Name = L"Gui";
			this->Text = L"Gui";
			this->Load += gcnew System::EventHandler(this, &Gui::Gui_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Gui::Gui_Paint);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Gui::Gui_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Gui::Gui_KeyUp);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_notConnected))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_connection))->EndInit();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_frontSensor))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_leftSensor))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_rightSensor))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->speedBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void progressBar3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button_connect_Click(System::Object^  sender, System::EventArgs^  e) {
	
	std::cout << "Initialising Winsock..." << std::endl;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		std::cout << "Failed. Error Code " << WSAGetLastError() << std::endl;
		//return 1;
	}
	std::cout << "Initialised." << std::endl;

	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		std::cout << "Could not create socket " << WSAGetLastError() << std::endl;
	}

	std::cout << "Socket created." << std::endl;

	msclr::interop::marshal_context ctx;

	String^ rpi_ip = textbox_rpi_ip->Text;
	const char* rpi_ip2 = ctx.marshal_as<const char*>(rpi_ip);

	server.sin_addr.s_addr = inet_addr(rpi_ip2);
	server.sin_family = AF_INET;
	server.sin_port = htons(6163);

	if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		std::cerr << "Connection error." << std::endl;
		textBox_debug->Text = "Connection error.";
		pictureBox_notConnected->Visible = true;
		pictureBox_connection->Visible = false;
		//return 1;
	}
	else {

		textBox_debug->Text = "Connected";
		pictureBox_notConnected->Visible = false;
		pictureBox_connection->Visible = true;
	}


}
private: System::Void Gui_Load(System::Object^  sender, System::EventArgs^  e) {
	comboBox_drivingMode->Items->Add("Manual Mode");
	comboBox_drivingMode->Items->Add("Auto Mode");
	textbox_rpi_ip->Text = "192.168.1.42";
}

private: System::Void button_get_Click(System::Object^  sender, System::EventArgs^  e) {

	int recv_size;
	char* server_reply;
	
	clientMessage.command = 0;
	clientMessage.motorState = 1;
	if (comboBox_drivingMode->Text->Equals("Auto Mode")) {
		clientMessage.drivingMode = 1;
	}
	else if(comboBox_drivingMode->Text->Equals("Manual Mode")){
		clientMessage.drivingMode = 2;
	}
	if (checkBox_demo1->Checked) {
		clientMessage.demoType = 1;
	}
	else if (checkBox_demo2->Checked) {
		clientMessage.demoType = 2;
	}
	else if (checkBox_demo3->Checked) {
		clientMessage.demoType = 3;
	}

	if (send(s, (char*)&clientMessage, sizeof(ClientMessage), 0) < 0)
	{
		textBox_debug->Text = "Send Failed";
	}


	else if ((recv_size = recv(s, (char*)&serverMessage, sizeof(ServerMessage), 0)) == SOCKET_ERROR)
	{
		textBox_debug->Text = "Failed recv";
	}
	textBox_debug->Text = gcnew String(message);
	if(clientMessage.drivingMode == 1)
		timer1->Start();

	timer2->Start();
}
private: System::Void comboBox_drivingMode_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	int recv_size;
	++second;
	clientMessage.command = 61;
	//if(comboBox_drivingMode->Text->Equals(""))
	if (send(s, (char*)&clientMessage, sizeof(ClientMessage), 0) != SOCKET_ERROR) {
		clientMessage.drivingMode = 3;
	
		textBox_debug->Text = gcnew String(serverMessage.temperature.ToString());
		textBox1->Text = gcnew String(serverMessage.dirDegree.ToString());
		if (recv_size = recv(s, (char*)&serverMessage, sizeof(ServerMessage), 0) == SOCKET_ERROR)
		{
			textBox_debug->Text = " recv failed";
		}
		++mapCounter;
		if (mapCounter > 2){
			sensorInf[sensorCounter][0] = serverMessage.sensor1;
			sensorInf[sensorCounter][1] = serverMessage.sensor2;
			sensorInf[sensorCounter][2] = serverMessage.sensor3;
			sensorInf[sensorCounter][3] = serverMessage.temperature;
			directionInf[directionCounter][0] = serverMessage.dirDegree;
			directionInf[directionCounter][1] = serverMessage.traveled;
			++directionCounter;
			++sensorCounter;
			mapCounter = 0;
		}


		if (serverMessage.sensor1 < 1000 && serverMessage.sensor2 < 1000 && serverMessage.sensor3 < 1000) {
			//textBox_debug->Text = serverMessage.sensor1.ToString();
			
			progressBar_frontSensor->Value = serverMessage.sensor1;
			label_frontSensor->Text = serverMessage.sensor1.ToString();
			
			progressBar_leftSensor->Value = serverMessage.sensor3;
			label_leftSensor->Text = serverMessage.sensor3.ToString();
			
			progressBar_rightSensor->Value = serverMessage.sensor2;
			label_rightSensor->Text = serverMessage.sensor2.ToString();
			
			progressBar_temperature->Value = serverMessage.temperature;
			label_tempSensor->Text = serverMessage.temperature.ToString();
			
			if (serverMessage.gas == 1) {
				checkBox_gas->Checked = true;
			}
			else {
				checkBox_gas->Checked = false;
			}
			if (serverMessage.flame == 1) {
				checkBox_flame->Checked = true;
			}
			else {
				checkBox_flame->Checked = false;
			}
			second = 0;
		}
	}
	//second = 0;
}

private: System::Void button_livecam_Click(System::Object^  sender, System::EventArgs^  e) {
	Process^ process = Process::Start("test.bat");
}

private: System::Void Gui_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	int recv_size;
	clientMessage.drivingMode = 2;
	timer1->Stop();

	if (comboBox_drivingMode->Text->Equals("Manual Mode"))
	{
		timer1->Stop();
		if (e->KeyChar == 'w' || e->KeyChar == 'W')
		{
			clientMessage.command = 1;
			if (send(s, (char*)&clientMessage, sizeof(ClientMessage), 0) < 0)
			{
				textBox_debug->Text = "Send Failed";
			}
			if ((recv_size = recv(s, (char*)&serverMessage, sizeof(ServerMessage), 0)) == SOCKET_ERROR)
			{
				textBox_debug->Text = "Failed recv";
			}
		}
		else if (e->KeyChar == 's' || e->KeyChar == 'S')
		{
			clientMessage.command = 2;
			if (send(s, (char*)&clientMessage, sizeof(ClientMessage), 0) < 0)
			{
				textBox_debug->Text = "Send Failed";
			}
			if ((recv_size = recv(s, (char*)&serverMessage, sizeof(ServerMessage), 0)) == SOCKET_ERROR)
			{
				textBox_debug->Text = "Failed recv";
			}
		}
		else if (e->KeyChar == 'a' || e->KeyChar == 'A')
		{
			clientMessage.command = 3;
			if (send(s, (char*)&clientMessage, sizeof(ClientMessage), 0) < 0)
			{
				textBox_debug->Text = "Send Failed";
			}
			if ((recv_size = recv(s, (char*)&serverMessage, sizeof(ServerMessage), 0)) == SOCKET_ERROR)
			{
				textBox_debug->Text = "Failed recv";
			}
		}
		else if (e->KeyChar == 'd' || e->KeyChar == 'D')
		{
			clientMessage.command = 4;
			if (send(s, (char*)&clientMessage, sizeof(ClientMessage), 0) < 0)
			{
				textBox_debug->Text = "Send Failed";
			}
			if ((recv_size = recv(s, (char*)&serverMessage, sizeof(ServerMessage), 0)) == SOCKET_ERROR)
			{
				textBox_debug->Text = "Failed recv";
			}
		}
		else if (e->KeyChar.Equals(Keys::Space))
		{
			clientMessage.command = 5;
			if (send(s, (char*)&clientMessage, sizeof(ClientMessage), 0) < 0)
			{
				textBox_debug->Text = "Send Failed";
			}
			if ((recv_size = recv(s, (char*)&serverMessage, sizeof(ServerMessage), 0)) == SOCKET_ERROR)
			{
				textBox_debug->Text = "Failed recv";
			}
		}
		else {
			clientMessage.command = 5;
		}
		sensorInf[sensorCounter][0] = serverMessage.sensor1;
		sensorInf[sensorCounter][1] = serverMessage.sensor2;
		sensorInf[sensorCounter][2] = serverMessage.sensor3;
		sensorInf[sensorCounter][3] = serverMessage.temperature;
		directionInf[directionCounter][0] = serverMessage.dirDegree;
		directionInf[directionCounter][1] = serverMessage.traveled;
		++directionCounter;
		++sensorCounter;
		if (send(s, (char*)&clientMessage, sizeof(ClientMessage), 0) < 0)
		{
			textBox_debug->Text = "Send Failed";
		}
		if ((recv_size = recv(s, (char*)&serverMessage, sizeof(ServerMessage), 0)) == SOCKET_ERROR)
		{
			textBox_debug->Text = "Failed recv";
		}

	}

}
private: System::Void Gui_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	int recv_size;
	clientMessage.command = 5;
	if (send(s, (char*)&clientMessage, sizeof(ClientMessage), 0) < 0)
	{
		textBox_debug->Text = "Send Failed";
	}
	else if ((recv_size = recv(s, (char*)&serverMessage, sizeof(ServerMessage), 0)) == SOCKET_ERROR)
	{
		textBox_debug->Text = "Failed recv";
	}
	sensorInf[sensorCounter][0] = serverMessage.sensor1;
	sensorInf[sensorCounter][1] = serverMessage.sensor2;
	sensorInf[sensorCounter][2] = serverMessage.sensor3;
	sensorInf[sensorCounter][3] = serverMessage.temperature;
	directionInf[directionCounter][0] = serverMessage.dirDegree;
	directionInf[directionCounter][1] = serverMessage.traveled;
	++directionCounter;
	++sensorCounter;
}

private: System::Void button_disconnect_Click(System::Object^  sender, System::EventArgs^  e) {
	closesocket(s);
	WSACleanup();
	pictureBox_connection->Visible = false;
	pictureBox_notConnected->Visible = true;


}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {

	++second2;
	if (second2 == 1) {
		if (serverMessage.sensor1 < 15) {
			pictureBox_frontSensor->Visible = true;
		}
		else {
			pictureBox_frontSensor->Visible = false;
		}
		if (serverMessage.sensor3 < 15) {
			pictureBox_leftSensor->Visible = true;
		}
		else {
			pictureBox_leftSensor->Visible = false;
		}
		if (serverMessage.sensor2 < 15) {
			pictureBox_rightSensor->Visible = true;
		}
		else {
			pictureBox_rightSensor->Visible = false;
		}
		
	}
	second2 = 0;
	
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	clientMessage.motorState = 0;
}
private: System::Void button_start_Click(System::Object^  sender, System::EventArgs^  e) {
	clientMessage.motorState = 1;
	
}
private: System::Void speedBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	speedLabel->Text =  speedBar->Value.ToString();
	clientMessage.speed = speedBar->Value * 10;
}
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox_debug_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void Gui_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	
	int mult = 1;
	
	 {
		float startx = 925.0, starty = 650.0;
		Point point1 = Point(startx, starty);
		Point point2;
		Point leftWall = Point(startx, starty), endLeft;
		Point rightWall = Point(startx, starty), endRight;
//		Point frontWall = Point(start)
		float px=0.0, py=0.0;
		Pen^ wayPen;

		Pen^ rightPen = gcnew Pen(Color::Black, 3.0f);
		Pen^ leftPen = gcnew Pen(Color::Black, 3.0f);
		Pen^ frontPen = gcnew Pen(Color::Gray , 3.0f);
		/*for (int i=0; i < 100; ++i) {
			directionInf[i][0] = 150.0 - (float) i;
			directionInf[i][1] = 5.0;
			++directionCounter;
		}*/
		for (int i = 0; i < directionCounter ; ++i) {
			if (sensorInf[i][3] < 26) {
				//wayPen = nullptr;
				wayPen = gcnew Pen(Color::Blue, 1.0f);
			}
			else if (sensorInf[i][3] < 30) {
				//wayPen = nullptr;
				wayPen = gcnew Pen(Color::Yellow, 1.0f);
			}
			else if (sensorInf[i][3] < 34) {
				//wayPen = nullptr;
				wayPen = gcnew Pen(Color::Orange, 1.0f);
			}
			else if (sensorInf[i][3] < 40) {
				//wayPen = nullptr;
				wayPen = gcnew Pen(Color::Red, 1.0f);
			}
			if (directionInf[i][0] < 0.0) {
				directionInf[i][0] += 360.0;
			}else if (directionInf[i][0] > 360.0) {
				directionInf[i][0] -= 360.0;
			}
			px = (abs(directionInf[i][1]) * cos(directionInf[i][0] * PI / 180.0));
			py = (abs(directionInf[i][1]) * sin(directionInf[i][0] * PI / 180.0));

			startx += px;
			starty -= py;
			point2 = Point(startx, starty);
			if (directionInf[i][1] > 0) {
				e->Graphics->DrawLine(wayPen, point1, point2);
			}
			else
			{
				e->Graphics->DrawLine(wayPen, point2, point1);
			}
			/*if (sensorInf[i][0] < 100) {
				if (directionInf[i][0] == 0.0 || directionInf[i][0] == 360.0) {
					rightWall = Point(rightWall.X, rightWall.Y + sensorInf[i][1]);
					endRight = Point(startx, starty + sensorInf[i][1]);

				}
				else if (directionInf[i][0] < 90.0) {
					rightWall = Point(rightWall.X + sensorInf[i][1], rightWall.Y + sensorInf[i][1]);
					endRight = Point(startx + sensorInf[i][1], starty + sensorInf[i][1]);

				}
				else if (directionInf[i][0] == 90.0) {
					rightWall = Point(rightWall.X + sensorInf[i][1], rightWall.Y);
					endRight = Point(startx + sensorInf[i][1], starty);

				}
				else if (directionInf[i][0] < 180.0) {
					rightWall = Point(rightWall.X + sensorInf[i][1], rightWall.Y - sensorInf[i][1]);
					endRight = Point(startx + sensorInf[i][1], starty - sensorInf[i][1]);

				}
				else if (directionInf[i][0] == 180.0) {
					rightWall = Point(rightWall.X, rightWall.Y - sensorInf[i][1]);
					endRight = Point(startx, starty - sensorInf[i][1]);

				}
				else if (directionInf[i][0] < 270.0) {
					rightWall = Point(rightWall.X - sensorInf[i][1], rightWall.Y - sensorInf[i][1]);
					endRight = Point(startx - sensorInf[i][1], starty - sensorInf[i][1]);

				}
				else if (directionInf[i][0] == 270.0) {
					rightWall = Point(rightWall.X - sensorInf[i][1], rightWall.Y);
					endRight = Point(startx - sensorInf[i][1], starty);

				}
				else if (directionInf[i][0] < 360.0) {
					rightWall = Point(rightWall.X - sensorInf[i][1], rightWall.Y + sensorInf[i][1]);
					endRight = Point(startx - sensorInf[i][1], starty + sensorInf[i][1]);

				}

				e->Graphics->DrawLine(rightPen, rightWall, endRight);
			}*/
			if (sensorInf[i][1] < 100) {
				if (directionInf[i][0] == 0.0 || directionInf[i][0] == 360.0) {
					rightWall = Point(rightWall.X, rightWall.Y + sensorInf[i][1]);
					endRight = Point(startx , starty + sensorInf[i][1]);

				}else if (directionInf[i][0] < 90.0) {
					rightWall = Point(rightWall.X + sensorInf[i][1], rightWall.Y + sensorInf[i][1]);
					endRight = Point(startx + sensorInf[i][1], starty + sensorInf[i][1]);

				}else if (directionInf[i][0] == 90.0) {
					rightWall = Point(rightWall.X + sensorInf[i][1], rightWall.Y);
					endRight = Point(startx + sensorInf[i][1], starty);

				}else if (directionInf[i][0] < 180.0) {
					rightWall = Point(rightWall.X + sensorInf[i][1], rightWall.Y - sensorInf[i][1]);
					endRight = Point(startx + sensorInf[i][1], starty - sensorInf[i][1]);

				}else if (directionInf[i][0] == 180.0) {
					rightWall = Point(rightWall.X, rightWall.Y - sensorInf[i][1]);
					endRight = Point(startx, starty - sensorInf[i][1]);

				}else if (directionInf[i][0] < 270.0) {
					rightWall = Point(rightWall.X - sensorInf[i][1], rightWall.Y - sensorInf[i][1]);
					endRight = Point(startx - sensorInf[i][1], starty - sensorInf[i][1]);

				}else if (directionInf[i][0] == 270.0) {
					rightWall = Point(rightWall.X - sensorInf[i][1], rightWall.Y);
					endRight = Point(startx - sensorInf[i][1], starty );

				}else if (directionInf[i][0] < 360.0) {
					rightWall = Point(rightWall.X - sensorInf[i][1], rightWall.Y + sensorInf[i][1]);
					endRight = Point(startx - sensorInf[i][1], starty + sensorInf[i][1]);

				}

				e->Graphics->DrawLine(rightPen, rightWall, endRight);
			}
			if (sensorInf[i][2] < 100) {
				if (directionInf[i][0] == 0.0 || directionInf[i][0] == 360.0) {

					leftWall = Point(leftWall.X, leftWall.Y - sensorInf[i][2]);
					endLeft = Point(startx, starty - sensorInf[i][2]);
				}
				else if (directionInf[i][0] < 90.0) {

					leftWall = Point(leftWall.X - sensorInf[i][2], leftWall.Y - sensorInf[i][2]);
					endLeft = Point(startx - sensorInf[i][2], starty - sensorInf[i][2]);
				}
				else if (directionInf[i][0] == 90.0) {

					leftWall = Point(leftWall.X - sensorInf[i][2], leftWall.Y);
					endLeft = Point(startx - sensorInf[i][2], starty);
				}
				else if (directionInf[i][0] < 180.0) {

					leftWall = Point(leftWall.X - sensorInf[i][2], leftWall.Y + sensorInf[i][2]);
					endLeft = Point(startx - sensorInf[i][2], starty + sensorInf[i][2]);
				}
				else if (directionInf[i][0] == 180.0) {

					leftWall = Point(leftWall.X, leftWall.Y + sensorInf[i][2]);
					endLeft = Point(startx, starty + sensorInf[i][2]);
				}
				else if (directionInf[i][0] < 270.0) {

					leftWall = Point(leftWall.X + sensorInf[i][2], leftWall.Y + sensorInf[i][2]);
					endLeft = Point(startx + sensorInf[i][2], starty + sensorInf[i][2]);
				}
				else if (directionInf[i][0] == 270.0) {

					leftWall = Point(leftWall.X + sensorInf[i][2], leftWall.Y);
					endLeft = Point(startx + sensorInf[i][2], starty);
				}
				else if (directionInf[i][0] < 360.0) {

					leftWall = Point(leftWall.X + sensorInf[i][2], leftWall.Y - sensorInf[i][2]);
					endLeft = Point(startx + sensorInf[i][2], starty - sensorInf[i][2]);
				}

				e->Graphics->DrawLine(leftPen, leftWall, endLeft);
			}
			point1 = Point(startx, starty);
			rightWall = Point(startx, starty);
			leftWall = Point(startx, starty);
		}
	}
}
private: System::Void pictureBox_leftSensor_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Gui::Gui_Paint);
	this->Refresh();
}
private: System::Void pictureBox_frontSensor_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	if (volumeBar->Value == 1) {
		Process^ process = Process::Start("volumeup.bat");
	}
	else if (volumeBar->Value == 0) {
		Process^ process = Process::Start("volumedown.bat");
	}
}
private: System::Void label7_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
