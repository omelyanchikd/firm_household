#pragma once

#include "world.h"
#include "Result.h"
#include <msclr\marshal_cppstd.h>

namespace firm_household {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::CheckedListBox^  parameters;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckedListBox^  types;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;



































































































private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::TextBox^  firm_id;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::TextBox^  iterations;
private: System::Windows::Forms::TextBox^  salary_coefficient;





private: System::Windows::Forms::TextBox^  consumption_need;

private: System::Windows::Forms::TextBox^  number_household;


private: System::Windows::Forms::TextBox^  labor_productivity;

private: System::Windows::Forms::TextBox^  money;

private: System::Windows::Forms::TextBox^  number_firm;



private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label8;

private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label4;







	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->parameters = (gcnew System::Windows::Forms::CheckedListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->types = (gcnew System::Windows::Forms::CheckedListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->firm_id = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->iterations = (gcnew System::Windows::Forms::TextBox());
			this->salary_coefficient = (gcnew System::Windows::Forms::TextBox());
			this->consumption_need = (gcnew System::Windows::Forms::TextBox());
			this->number_household = (gcnew System::Windows::Forms::TextBox());
			this->labor_productivity = (gcnew System::Windows::Forms::TextBox());
			this->money = (gcnew System::Windows::Forms::TextBox());
			this->number_firm = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// parameters
			// 
			this->parameters->CheckOnClick = true;
			this->parameters->FormattingEnabled = true;
			this->parameters->Items->AddRange(gcnew cli::array< System::Object^  >(15) {L"price", L"salary", L"plan", L"storage", L"workers", 
				L"labor_capacity", L"capital_capacity", L"raw_capacity", L"capital_investments", L"raw_investments", L"sales", L"sold", L"profit", 
				L"money", L"production"});
			this->parameters->Location = System::Drawing::Point(658, 50);
			this->parameters->Name = L"parameters";
			this->parameters->Size = System::Drawing::Size(141, 229);
			this->parameters->TabIndex = 1;
			this->parameters->TabStop = false;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(619, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Output";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(505, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Firm types";
			// 
			// types
			// 
			this->types->CheckOnClick = true;
			this->types->FormattingEnabled = true;
			this->types->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"raw_firm", L"capital_firm", L"good_firm"});
			this->types->Location = System::Drawing::Point(508, 50);
			this->types->Name = L"types";
			this->types->Size = System::Drawing::Size(116, 49);
			this->types->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(655, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Parameters";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(499, 285);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(300, 68);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label39
			// 
			this->label39->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label39->Location = System::Drawing::Point(552, 118);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(31, 17);
			this->label39->TabIndex = 6;
			this->label39->Text = L"OR";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(505, 141);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(37, 13);
			this->label40->TabIndex = 25;
			this->label40->Text = L"Firm id";
			// 
			// firm_id
			// 
			this->firm_id->Location = System::Drawing::Point(508, 164);
			this->firm_id->Name = L"firm_id";
			this->firm_id->Size = System::Drawing::Size(116, 20);
			this->firm_id->TabIndex = 24;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label41->Location = System::Drawing::Point(531, 208);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(76, 17);
			this->label41->TabIndex = 27;
			this->label41->Text = L"Iterations";
			// 
			// iterations
			// 
			this->iterations->Location = System::Drawing::Point(534, 231);
			this->iterations->Name = L"iterations";
			this->iterations->Size = System::Drawing::Size(75, 20);
			this->iterations->TabIndex = 26;
			this->iterations->Text = L"150";
			// 
			// salary_coefficient
			// 
			this->salary_coefficient->Location = System::Drawing::Point(302, 42);
			this->salary_coefficient->Name = L"salary_coefficient";
			this->salary_coefficient->Size = System::Drawing::Size(143, 20);
			this->salary_coefficient->TabIndex = 40;
			this->salary_coefficient->Text = L"0,4";
			// 
			// consumption_need
			// 
			this->consumption_need->Location = System::Drawing::Point(73, 277);
			this->consumption_need->Name = L"consumption_need";
			this->consumption_need->Size = System::Drawing::Size(143, 20);
			this->consumption_need->TabIndex = 38;
			this->consumption_need->Text = L"0,1";
			// 
			// number_household
			// 
			this->number_household->Location = System::Drawing::Point(73, 229);
			this->number_household->Name = L"number_household";
			this->number_household->Size = System::Drawing::Size(143, 20);
			this->number_household->TabIndex = 36;
			this->number_household->Text = L"200";
			// 
			// labor_productivity
			// 
			this->labor_productivity->Location = System::Drawing::Point(72, 132);
			this->labor_productivity->Name = L"labor_productivity";
			this->labor_productivity->Size = System::Drawing::Size(143, 20);
			this->labor_productivity->TabIndex = 32;
			this->labor_productivity->Text = L"5";
			// 
			// money
			// 
			this->money->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->money->Location = System::Drawing::Point(73, 84);
			this->money->Name = L"money";
			this->money->Size = System::Drawing::Size(143, 20);
			this->money->TabIndex = 30;
			this->money->Text = L"1000";
			// 
			// number_firm
			// 
			this->number_firm->Location = System::Drawing::Point(77, 42);
			this->number_firm->Name = L"number_firm";
			this->number_firm->Size = System::Drawing::Size(143, 20);
			this->number_firm->TabIndex = 28;
			this->number_firm->Text = L"1";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(256, 26);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(88, 13);
			this->label11->TabIndex = 41;
			this->label11->Text = L"Salary coefficient";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(27, 261);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(95, 13);
			this->label9->TabIndex = 39;
			this->label9->Text = L"Consumption need";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(27, 213);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(63, 13);
			this->label8->TabIndex = 37;
			this->label8->Text = L"Households";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(26, 116);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 13);
			this->label6->TabIndex = 33;
			this->label6->Text = L"Labor productivity";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(27, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 31;
			this->label5->Text = L"Money";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 26);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 13);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Firms";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(805, 358);
			this->Controls->Add(this->salary_coefficient);
			this->Controls->Add(this->consumption_need);
			this->Controls->Add(this->number_household);
			this->Controls->Add(this->labor_productivity);
			this->Controls->Add(this->money);
			this->Controls->Add(this->number_firm);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label41);
			this->Controls->Add(this->iterations);
			this->Controls->Add(this->label40);
			this->Controls->Add(this->firm_id);
			this->Controls->Add(this->label39);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->parameters);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->types);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Name = L"Form1";
			this->Text = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 srand(1);
				 Result^ result = gcnew Result();				 
				 world *country = new world(int::Parse(number_firm->Text), int::Parse(number_household->Text), float::Parse(money->Text));
				 country->init(float::Parse(money->Text), float::Parse(labor_productivity->Text), float::Parse(salary_coefficient->Text));				 
				 vector<firm*> values;
				 if (!(String::IsNullOrWhiteSpace(firm_id->Text)))
				 {
					 values.push_back(country->get_firms()[int::Parse(firm_id->Text)]);
				 }
				 else
					 values = country->get_firms();
				 for (int i = 0; i < parameters->CheckedItems->Count; i++)
				 {
					for (int j = 0; j < values.size(); j++)
					{						
						
						result->chart->Series->Add(parameters->CheckedItems[i]->ToString() + "_firm_" + j);
						result->chart->Series[parameters->CheckedItems[i]->ToString() + "_firm_" + j]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
					}
				 }
				 for (int l = 0; l < int::Parse(iterations->Text); l++)
				 {
					 country->step();
					 for (int i = 0; i < parameters->CheckedItems->Count; i++)
					 {
						 for (int j = 0; j < values.size(); j++)
						 {
							 string value = msclr::interop::marshal_as<std::string>(parameters->CheckedItems[i]->ToString());
							 result->chart->Series[parameters->CheckedItems[i]->ToString() + "_firm_" + j]->Points->AddY(values[j]->get(value));
						 }
					 }
				 }
//				 Ukraine.change_tax(0.1);
/*				 for (int i = 0; i < 200; i++)
				 {
					 Ukraine.step();
				 }//*/
				 result->Show();
			 }

};
}

