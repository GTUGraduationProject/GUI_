#pragma once

namespace BitirmeGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm i�in �zet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(int rotation[][2])
		{
			
			InitializeComponent();
			//
			//TODO: Olu�turucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullan�lan t�m kaynaklar� temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		///Gerekli tasar�mc� de�i�keni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasar�mc� deste�i i�in gerekli metot - bu metodun 
		///i�eri�ini kod d�zenleyici ile de�i�tirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::Graphic;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 600);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		// Create pen.
		int i = 0;
		int rotation[1000][2];
		
		while (rotation[i][0] != -1) {
			// Create points that define line.

		}

	}
	};
}
