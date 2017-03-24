#pragma once //, comment(lib, "WS2_32.lib")
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include "Form2.h"

#include <msclr\marshal_cppstd.h>

using namespace std;

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Runtime::InteropServices;
	using namespace System::Threading;

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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  менюToolStripMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;

	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolStripMenuItem^  настройкиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  comboBox1;


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->менюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->настройкиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->менюToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(563, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// менюToolStripMenuItem
			// 
			this->менюToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->настройкиToolStripMenuItem,
					this->выходToolStripMenuItem
			});
			this->менюToolStripMenuItem->Name = L"менюToolStripMenuItem";
			this->менюToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->менюToolStripMenuItem->Text = L"Меню";
			// 
			// настройкиToolStripMenuItem
			// 
			this->настройкиToolStripMenuItem->Name = L"настройкиToolStripMenuItem";
			this->настройкиToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->настройкиToolStripMenuItem->Text = L"Настройки";
			this->настройкиToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::настройкиToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выходToolStripMenuItem_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.09225F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 74.90775F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 62)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(563, 330);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				73.63897F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				26.36103F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				251)));
			this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBox1, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->button1, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->label2, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->label5, 2, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30.50847F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 69.49152F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(557, 61);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label1->Location = System::Drawing::Point(3, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите ваш ник:";
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->textBox1->Location = System::Drawing::Point(10, 28);
			this->textBox1->Margin = System::Windows::Forms::Padding(10, 10, 7, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(208, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			this->button1->Location = System::Drawing::Point(228, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(74, 33);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Вход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Right;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::DarkGreen;
			this->label2->Location = System::Drawing::Point(529, 0);
			this->label2->Margin = System::Windows::Forms::Padding(3, 0, 15, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 18);
			this->label2->TabIndex = 3;
			this->label2->Text = L".";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Dock = System::Windows::Forms::DockStyle::Top;
			this->label5->Location = System::Drawing::Point(315, 28);
			this->label5->Margin = System::Windows::Forms::Padding(10, 10, 3, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(239, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Состояние: ";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->richTextBox1, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel5, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 70);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15.90909F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 84.09091F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(557, 194);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Location = System::Drawing::Point(10, 33);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(537, 158);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 3;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				54.67836F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				45.32164F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				262)));
			this->tableLayoutPanel5->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->label6, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->comboBox1, 2, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(551, 24);
			this->tableLayoutPanel5->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Location = System::Drawing::Point(3, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 24);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Чат:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Dock = System::Windows::Forms::DockStyle::Right;
			this->label6->Location = System::Drawing::Point(162, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(123, 24);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Выбрать собеседника: ";
			// 
			// comboBox1
			// 
			this->comboBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(293, 3);
			this->comboBox1->Margin = System::Windows::Forms::Padding(5, 3, 10, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(248, 21);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				81.32854F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				18.67145F)));
			this->tableLayoutPanel4->Controls->Add(this->label4, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->richTextBox2, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->button2, 1, 1);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 270);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.71428F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 74.28571F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(557, 57);
			this->tableLayoutPanel4->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Введите сообщение:";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox2->Location = System::Drawing::Point(10, 17);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(10, 3, 3, 3);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(440, 37);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			// 
			// button2
			// 
			this->button2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button2->Location = System::Drawing::Point(460, 17);
			this->button2->Margin = System::Windows::Forms::Padding(7, 3, 10, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(87, 37);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Отправить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(563, 354);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(2000, 2000);
			this->MinimumSize = System::Drawing::Size(579, 392);
			this->Name = L"Form1";
			this->Text = L"Client";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private:
		static SOCKET Client;
		string* ip;
		int port = 0;
		bool connectFlag = false;
		Thread ^ thread1;
		map<string, vector<string>> *UserChatsText = new map<string, vector<string>>();

	public:
		delegate void AddLineToRivhTextbox(String^ s);
		AddLineToRivhTextbox^ myDelegate1;
		delegate void AddItemToCombobox(String^ s);
		AddItemToCombobox^ myDelegate2;

	public: void AddMessageToRichTextbox(String^ s){
				string stmp = msclr::interop::marshal_as<std::string>(s);
				if (!connectFlag && stmp == "Соединение установлено"){
					label5->Text += s + Environment::NewLine;
					connectFlag = true;
				}
				else{
					pair<string, string> pNick = TakeNicksFromMessage(stmp);
					String ^ mes = s->Substring(0, s->Length - pNick.second.size() - 1);

					//Если мы отправили сообщение
					if (pNick.first == msclr::interop::marshal_as<std::string>(textBox1->Text)){
						if (pNick.second == msclr::interop::marshal_as<std::string>(comboBox1->Text)){
							richTextBox1->AppendText(mes + Environment::NewLine);
						}
						(*UserChatsText)[pNick.second].push_back(msclr::interop::marshal_as<std::string>(mes));
						return;
					}

					//Если кто-то нам отправил сообщение
					if (pNick.second == msclr::interop::marshal_as<std::string>(textBox1->Text)){
						if (pNick.first == msclr::interop::marshal_as<std::string>(comboBox1->Text)){
							richTextBox1->AppendText(mes + Environment::NewLine);
						}
						(*UserChatsText)[pNick.first].push_back(msclr::interop::marshal_as<std::string>(mes));
						return;
					}
				}
	}

	public: void AddNickToCombobox(String^ s){
				comboBox1->Items->Add(s);
	}

	private: pair<string, string> TakeNicksFromMessage(string message){
				 string nick1, nick2;

				 int num = 0;

				 for (int i = 0; i < (int)message.size(); ++i){
					 if (message[i] != ':')
						 nick1 += message[i];
					 else
						 break;
				 }

				 for (int i = message.size() - 1; i >= 0; --i){
					 if (message[i] != ':')
						 nick2 += message[i];

					 else
						 break;
				 }

				 reverse(nick2.begin(), nick2.end());

				 return make_pair(nick1, nick2);
	}

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

				 setlocale(LC_ALL, "Rus");
				 ifstream in("..\\..\\Server.txt");
				 string tmpip;
				 int tmpport;

				 myDelegate1 = gcnew AddLineToRivhTextbox(this, &Form1::AddMessageToRichTextbox);
				 myDelegate2 = gcnew AddItemToCombobox(this, &Form1::AddNickToCombobox);

				 richTextBox1->Enabled = false;
				 richTextBox2->Enabled = false;
				 button2->Enabled = false;
				 textBox1->ReadOnly = false;

				 try{
					 if (in.is_open()){
						 in >> tmpip;
						 in >> tmpport;

						 port = tmpport;
						 ip = new string(tmpip);

						 string infostr = "IP: " + tmpip + " Port: " + to_string(tmpport);

						 label2->Text = gcnew String(infostr.c_str());
						 in.close();
					 }
					 else{
						 MessageBox::Show("Ошибка чтения данных из файла! Перейдите в пункт меню \"Настройки\".");
					 }
				 }
				 catch (...){
					 in.close();
					 MessageBox::Show("Ошибка чтения данных из файла! Перейдите в пункт меню \"Настройки\".");
				 }


	}

	private:
		void Send_Message(string& message){
			if (message != ""){
				char *buff = new char[1024];
				strcpy(buff, message.c_str());
				// передаем строку клиента серверу
				send(Client, buff, strlen(buff), 0);
			}
		}

	private:
		void Recv_Message();

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 connectFlag = false;
				 label5->Text = "Состояние: ";

				 if (textBox1->Text != ""){
					 textBox1->ReadOnly = true;
					 richTextBox2->Enabled = true;
					 button2->Enabled = true;

					 WSAData data;
					 if (WSAStartup(MAKEWORD(2, 2), &data))
					 {
						 MessageBox::Show("Ошибка!");
					 }

					 if ((Client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
						 MessageBox::Show("Ошибка!");
						 WSACleanup(); // Деиницилизация библиотеки Winsock
					 }

					 // заполнение структуры sockaddr_in - указание адреса и порта сервера
					 sockaddr_in dest_addr;
					 dest_addr.sin_family = AF_INET;
					 dest_addr.sin_port = htons((u_short)port);
					 HOSTENT *hst;

					 // преобразование IP адреса из символьного в сетевой формат
					 if (inet_addr(ip->c_str()) != INADDR_NONE)
						 dest_addr.sin_addr.s_addr = inet_addr(ip->c_str());
					 else
					 {
						 // попытка получить IP адрес по доменному имени сервера
						 if (hst = gethostbyname(ip->c_str()))
							 // hst->h_addr_list содержит не массив адресов,
							 // а массив указателей на адреса
							 ((unsigned long *)&dest_addr.sin_addr)[0] =
							 ((unsigned long **)hst->h_addr_list)[0][0];
						 else
						 {
							 MessageBox::Show("Invalid IP-address");
							 closesocket(Client);
							 WSACleanup();
						 }
					 }

					 if (connect(Client, (sockaddr *)&dest_addr, sizeof(dest_addr)))
					 {
						 MessageBox::Show("Connect error! ");
						 closesocket(Client);
						 WSACleanup();
					 }

					 //Отправка ника пользователя серверу
					 char *buff = new char[1024];
					 string newnick = '@' + msclr::interop::marshal_as<std::string>(textBox1->Text) + '@';
					 strcpy(buff, newnick.c_str());
					 send(Client, buff, strlen(buff), 0);

					 //Запуск приема сообщений от пользователя
					 thread1 = gcnew Thread(gcnew ThreadStart(this, &Form1::Recv_Message));
					 thread1->Start();
				 }


	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 string mess = msclr::interop::marshal_as<std::string>(richTextBox2->Text);
				 string from = msclr::interop::marshal_as<std::string>(textBox1->Text);
				 string to = msclr::interop::marshal_as<std::string>(comboBox1->Text);
				 if (from != "" && to != "" && mess != ""){
					 Send_Message("|" + from + ": " + mess + ":" + to + "|");
					 richTextBox2->Clear();
				 }
	}

	private: System::Void настройкиToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Form2 ^ SettingForm = gcnew Form2();
				 SettingForm->ShowDialog();
	}

	private: System::Void выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Form1::Close();
	}


	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 richTextBox1->Clear();
				 vector<string> vtmp = (*UserChatsText)[msclr::interop::marshal_as<std::string>(comboBox1->Text)];
				 for (int i = 0; i < (int)vtmp.size(); ++i){
					 richTextBox1->Text += gcnew String(vtmp[i].c_str()) + Environment::NewLine;
				 }
	}

	};

	public ref class ThreadForRecvClass
	{
	private:
		Form1^ myFormControl1;

	public:
		ThreadForRecvClass(Form1^ myForm)
		{
			myFormControl1 = myForm;
		}

		void Run_richTextbox(String^ s)
		{
			String ^ st = s;
			array<Object^>^ strArray = { st };
			myFormControl1->Invoke(myFormControl1->myDelegate1, strArray);
		}

		void Run_Combobox(String^ s)
		{
			String ^ st = s;
			array<Object^>^ strArray = { st };
			myFormControl1->Invoke(myFormControl1->myDelegate2, strArray);
		}
	};

	void Form1::Recv_Message(){
		char buff[1025];

		bool startMessageFlag = false;
		bool startNickFlag = false;
		//bool newNickFlag = false;
		//bool newMessageFlag = false;
		string message = "";
		string nick = "";

		ZeroMemory(&buff, sizeof(buff));

		int nsize;
		while ((nsize = recv(Client, buff, sizeof(buff)-1, 0)) != SOCKET_ERROR){
			// ставим завершающий ноль в конце строки
			buff[nsize] = '\0';

			for (int i = 0; i < (int)strlen(buff); ++i){
				if (buff[i] == '|'){
					if (!startMessageFlag){
						startMessageFlag = true;
						//message += buff[i];
						continue;
					}
					else{
						//message += buff[i];
						startMessageFlag = false;
						//newMessageFlag = true;

						//Вывод сообщения на экран
						String^ Str = gcnew String(message.c_str());
						message = "";
						ThreadForRecvClass^ ThreadObject = gcnew ThreadForRecvClass(this);
						ThreadObject->Run_richTextbox(Str);
						message = "";
					}
				}

				if (buff[i] == '@'){
					if (!startNickFlag){
						startNickFlag = true;
						//nick += buff[i];
						continue;
					}
					else{
						//nick += buff[i];
						startNickFlag = false;
						//newNickFlag = true;

						//Добавление нового ника к списку
						String^ Str = gcnew String(nick.c_str());
						nick = "";
						ThreadForRecvClass^ ThreadObject = gcnew ThreadForRecvClass(this);
						ThreadObject->Run_Combobox(Str);

						nick = "";
					}
				}

				if (startMessageFlag){
					message += buff[i];
					continue;
				}

				if (startNickFlag){
					nick += buff[i];
					continue;
				}
			}

		}


		ZeroMemory(&buff, sizeof(buff));
	}

};