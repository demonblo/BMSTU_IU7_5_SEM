#pragma once

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <algorithm>
#include <list>
#include <exception>

#define DEFAULT_SIZE 300

namespace course {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Diagnostics;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::IO;
	using namespace std;
	
	class PointXYZ
	{
	public:
		float x, y, z, _1;
		PointXYZ(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->_1 = 1.0;
		}
		PointXYZ(float x, float y, float z, float _1)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->_1 = _1;
		}
		PointXYZ()
		{
			this->x = 0.0;
			this->y = 0.0;
			this->z = 0.0;
			this->_1 = 0.0;
		}
	};
	struct Ygreater
	{
		bool operator()(PointXYZ l, PointXYZ r) const {
			return l.y < r.y;
		}
	};
	class CustomPair {
	public:
		int first;
		vector<PointXYZ>* second = new vector<PointXYZ>();
		CustomPair() {
		}
		CustomPair(int first, vector<PointXYZ>* second) {
			this->first = first;
			this->second = second;
		}
	};
	enum Direction { X, Y, Z };
	enum Fractal { CANTOR_SET, PYTHAGORAS_TREE, MENGER_SPONGE };

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Bitmap^ bm;
		int bmWidth;
		int bmHeight;
		BitmapData^ bm_data;
		unsigned char* scan0;
		int scan0_stride;
		int scan0_depth;
		Graphics^ gr_from_image;
		Graphics^ gr_create_graphics;

		// индекс выбранной фигуры
		int chosen_figure = -1;

		// угол вращения по оси X
		vector<double>* x_angle;
		// угол вращения по оси Y
		vector<double>* y_angle;
		// угол вращения по оси Z
		vector<double>* z_angle;
		// точка с отступами по осям X, Y, Z
		PointXYZ* offset_point = new PointXYZ(0, 0, 0);
		// дополнительные отступы по осям X, Y, Z
		vector<PointXYZ>* additional_offset_point;
		// z-буффер
		vector<vector<double>* >* z_buffer;
		// положение камеры
		PointXYZ* light_source = new PointXYZ(0, 0, 1);

		//масштаб по умолчанию
		vector<int>* size;

		// ось
		Direction direction;
		// фрактал
		Fractal fractal;
		// количество итераций
		int iteration_count;

		// удаление невидимых граней
		bool is_filled = false;
		// ... по каждой грани
		bool is_filled_slow_mo = false;
		bool is_flat_filling = false;


		// custom_figure
		vector<vector <CustomPair>>* custom_figure_edges;
		vector<vector <CustomPair>>* custom_figure_edges_copy;

		// pen для проекции custom_figure
		Pen^ pen_custom_figure;
		SolidBrush^ edge_solid_brush;
		SolidBrush^ fill_edge_solid_brush;
		SolidBrush^ background_solid_brush;

		Color backround_color;
		Color default_edge_color = Color::Red;
		vector<int>* edge_color;
		Color default_fill_edge_color = Color::Yellow;
		vector<int>* fill_edge_color;

		Graphics^ gr;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ rotation_label;

	private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TrackBar^ trackBar4;
	private: System::Windows::Forms::TrackBar^ trackBar5;
	private: System::Windows::Forms::TrackBar^ trackBar6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TrackBar^ trackBar7;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label10;



	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::ColorDialog^ colorDialog2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::ColorDialog^ colorDialog3;

	private: System::Windows::Forms::Label^ label19;

	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::TrackBar^ trackBar9;
	private: System::Windows::Forms::TrackBar^ trackBar10;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::TrackBar^ trackBar11;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::ComboBox^ comboBox3;
private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::Label^ label33;
private: System::Windows::Forms::Label^ label34;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
private: System::Windows::Forms::Label^ label35;
private: System::Windows::Forms::Button^ button1;



	private: System::Windows::Forms::TrackBar^ trackBar2;
	public:

		MyForm(void)
		{
			System::Threading::Thread::CurrentThread->CurrentCulture = gcnew System::Globalization::CultureInfo("en-US");
			InitializeComponent();

			bm = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = bm;

			gr_create_graphics = pictureBox1->CreateGraphics();
			gr_from_image = Graphics::FromImage(bm);
			gr = gr_create_graphics;

			bmHeight = bm->Height;
			bmWidth = bm->Width;

			backround_color = Color::White;
			edge_color = new vector<int>();
			fill_edge_color = new vector<int>();

			custom_figure_edges = new vector<vector<CustomPair>>();
			custom_figure_edges_copy = new vector<vector<CustomPair>>();

			// устанавливаем дефолтный цвет границ - красный
			pen_custom_figure = gcnew Pen(default_edge_color, 1);
			edge_solid_brush = gcnew SolidBrush(default_edge_color);
			button2->BackColor = default_edge_color;
			// устанавливаем дефолтный цвет фона
			background_solid_brush = gcnew SolidBrush(backround_color);
			button3->BackColor = backround_color;
			// устанавливаем дефолтный цвет граней - желтый
			fill_edge_solid_brush = gcnew SolidBrush(default_fill_edge_color);
			button6->BackColor = default_fill_edge_color;

			// зададим точку отсчета по середине
			offset_point->x = pictureBox1->Width / 2;
			offset_point->y = pictureBox1->Height / 2;

			additional_offset_point = new vector<PointXYZ>();

			z_buffer = new vector<vector<double>* >(pictureBox1->Height);

			x_angle = new vector<double>();
			y_angle = new vector<double>();
			z_angle = new vector<double>();

			size = new vector<int>();

			trackBar1->Value = 0;
			trackBar2->Value = 0;
			trackBar3->Value = 0;

			direction = Direction::X;
			comboBox1->SelectedIndex = 2;
			comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;

			fractal = Fractal::CANTOR_SET;
			comboBox2->SelectedIndex = 0;
			comboBox2->DropDownStyle = ComboBoxStyle::DropDownList;

			iteration_count = 1;
			textBox1->Text = "1";

			this->Name = L"MyForm";
			this->Text = L"Построение фрактальных поверхностей Блохин Дмитрий ИУ7-62Б";

			pictureBox1->Refresh();
		};

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->rotation_label = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar6 = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->trackBar7 = (gcnew System::Windows::Forms::TrackBar());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->colorDialog2 = (gcnew System::Windows::Forms::ColorDialog());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->colorDialog3 = (gcnew System::Windows::Forms::ColorDialog());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->trackBar9 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar10 = (gcnew System::Windows::Forms::TrackBar());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->trackBar11 = (gcnew System::Windows::Forms::TrackBar());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar11))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(1, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1257, 915);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->AutoSize = false;
			this->trackBar1->Location = System::Drawing::Point(1295, 66);
			this->trackBar1->Maximum = 360;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(136, 20);
			this->trackBar1->TabIndex = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// trackBar2
			// 
			this->trackBar2->AutoSize = false;
			this->trackBar2->Location = System::Drawing::Point(1297, 92);
			this->trackBar2->Maximum = 360;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(136, 20);
			this->trackBar2->TabIndex = 2;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// rotation_label
			// 
			this->rotation_label->AutoSize = true;
			this->rotation_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rotation_label->Location = System::Drawing::Point(1305, 39);
			this->rotation_label->Name = L"rotation_label";
			this->rotation_label->Size = System::Drawing::Size(100, 24);
			this->rotation_label->TabIndex = 3;
			this->rotation_label->Text = L"Вращение";
			// 
			// trackBar3
			// 
			this->trackBar3->AutoSize = false;
			this->trackBar3->Location = System::Drawing::Point(1297, 118);
			this->trackBar3->Maximum = 360;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(136, 20);
			this->trackBar3->TabIndex = 4;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar3_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(1271, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(1271, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(1272, 118);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Z";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(1319, 143);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 24);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Сдвиг";
			// 
			// trackBar4
			// 
			this->trackBar4->AutoSize = false;
			this->trackBar4->Location = System::Drawing::Point(1295, 170);
			this->trackBar4->Maximum = 500;
			this->trackBar4->Minimum = -500;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(136, 20);
			this->trackBar4->TabIndex = 9;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar4_Scroll);
			// 
			// trackBar5
			// 
			this->trackBar5->AutoSize = false;
			this->trackBar5->Location = System::Drawing::Point(1297, 196);
			this->trackBar5->Maximum = 500;
			this->trackBar5->Minimum = -500;
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(136, 20);
			this->trackBar5->TabIndex = 10;
			this->trackBar5->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar5_Scroll);
			// 
			// trackBar6
			// 
			this->trackBar6->AutoSize = false;
			this->trackBar6->Location = System::Drawing::Point(1297, 222);
			this->trackBar6->Maximum = 500;
			this->trackBar6->Minimum = -500;
			this->trackBar6->Name = L"trackBar6";
			this->trackBar6->Size = System::Drawing::Size(136, 20);
			this->trackBar6->TabIndex = 11;
			this->trackBar6->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar6_Scroll);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(1272, 170);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(20, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"X";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(1271, 196);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 20);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Y";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(1272, 222);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(19, 20);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Z";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(1311, 247);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(91, 24);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Масштаб";
			// 
			// trackBar7
			// 
			this->trackBar7->AutoSize = false;
			this->trackBar7->Location = System::Drawing::Point(1276, 274);
			this->trackBar7->Maximum = 600;
			this->trackBar7->Name = L"trackBar7";
			this->trackBar7->Size = System::Drawing::Size(155, 20);
			this->trackBar7->TabIndex = 16;
			this->trackBar7->Value = 300;
			this->trackBar7->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar7_Scroll);
			// 
			// comboBox1
			// 
			this->comboBox1->DisplayMember = L"0";
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"X", L"Y", L"Z" });
			this->comboBox1->Location = System::Drawing::Point(1315, 330);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(113, 24);
			this->comboBox1->TabIndex = 17;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(1305, 299);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(97, 24);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Проекция";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Канторово множество", L"Дерево Пифагора", L"Губка Менгера" });
			this->comboBox2->Location = System::Drawing::Point(1273, 386);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(155, 24);
			this->comboBox2->TabIndex = 20;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(1271, 334);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(38, 20);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Ось";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(1268, 480);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(141, 20);
			this->label11->TabIndex = 25;
			this->label11->Text = L"Удаление граней";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(1413, 484);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 26;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox2->Location = System::Drawing::Point(1413, 509);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(15, 14);
			this->checkBox2->TabIndex = 27;
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(1269, 505);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(138, 20);
			this->label12->TabIndex = 28;
			this->label12->Text = L"По каждой грани";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1413, 569);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(15, 15);
			this->button2->TabIndex = 29;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(1271, 565);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(104, 20);
			this->label13->TabIndex = 30;
			this->label13->Text = L"Цвет границ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(1271, 606);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(94, 20);
			this->label14->TabIndex = 31;
			this->label14->Text = L"Цвет фона";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1413, 611);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(15, 15);
			this->button3->TabIndex = 32;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(1321, 447);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(64, 24);
			this->label15->TabIndex = 33;
			this->label15->Text = L"Грани";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(1321, 530);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(64, 24);
			this->label16->TabIndex = 34;
			this->label16->Text = L"Цвета";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1272, 851);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(162, 23);
			this->button4->TabIndex = 35;
			this->button4->Text = L"Импортировать из файла";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1272, 822);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(162, 23);
			this->button5->TabIndex = 36;
			this->button5->Text = L"Удалить фигуру";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(1271, 585);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(104, 20);
			this->label17->TabIndex = 37;
			this->label17->Text = L"Цвет граней";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(1413, 590);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(15, 15);
			this->button6->TabIndex = 38;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->Location = System::Drawing::Point(1271, 655);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(140, 20);
			this->label19->TabIndex = 40;
			this->label19->Text = L"Плоская заливка";
			// 
			// label20
			// 
			this->label20->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label20->Location = System::Drawing::Point(1273, 141);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(158, 2);
			this->label20->TabIndex = 42;
			// 
			// label21
			// 
			this->label21->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label21->Location = System::Drawing::Point(1273, 245);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(158, 2);
			this->label21->TabIndex = 43;
			// 
			// label22
			// 
			this->label22->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label22->Location = System::Drawing::Point(1273, 297);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(158, 2);
			this->label22->TabIndex = 44;
			// 
			// label23
			// 
			this->label23->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label23->Location = System::Drawing::Point(1273, 445);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(158, 2);
			this->label23->TabIndex = 45;
			// 
			// label24
			// 
			this->label24->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label24->Location = System::Drawing::Point(1273, 528);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(158, 2);
			this->label24->TabIndex = 46;
			// 
			// label25
			// 
			this->label25->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label25->Location = System::Drawing::Point(1273, 629);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(158, 2);
			this->label25->TabIndex = 47;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox3->Location = System::Drawing::Point(1413, 659);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(15, 14);
			this->checkBox3->TabIndex = 48;
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// label26
			// 
			this->label26->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label26->Location = System::Drawing::Point(1271, 676);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(158, 2);
			this->label26->TabIndex = 49;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label27->Location = System::Drawing::Point(1276, 678);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(152, 24);
			this->label27->TabIndex = 50;
			this->label27->Text = L"Источник света";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label28->Location = System::Drawing::Point(1272, 714);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(20, 20);
			this->label28->TabIndex = 51;
			this->label28->Text = L"X";
			// 
			// trackBar9
			// 
			this->trackBar9->AutoSize = false;
			this->trackBar9->Location = System::Drawing::Point(1295, 714);
			this->trackBar9->Maximum = 100;
			this->trackBar9->Minimum = -100;
			this->trackBar9->Name = L"trackBar9";
			this->trackBar9->Size = System::Drawing::Size(136, 20);
			this->trackBar9->TabIndex = 52;
			this->trackBar9->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar9_Scroll);
			// 
			// trackBar10
			// 
			this->trackBar10->AutoSize = false;
			this->trackBar10->Location = System::Drawing::Point(1295, 740);
			this->trackBar10->Maximum = 100;
			this->trackBar10->Minimum = -100;
			this->trackBar10->Name = L"trackBar10";
			this->trackBar10->Size = System::Drawing::Size(136, 20);
			this->trackBar10->TabIndex = 53;
			this->trackBar10->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar10_Scroll);
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label29->Location = System::Drawing::Point(1272, 740);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(20, 20);
			this->label29->TabIndex = 54;
			this->label29->Text = L"Y";
			// 
			// trackBar11
			// 
			this->trackBar11->AutoSize = false;
			this->trackBar11->Location = System::Drawing::Point(1295, 766);
			this->trackBar11->Maximum = 100;
			this->trackBar11->Minimum = -100;
			this->trackBar11->Name = L"trackBar11";
			this->trackBar11->Size = System::Drawing::Size(136, 20);
			this->trackBar11->TabIndex = 55;
			this->trackBar11->Value = 1;
			this->trackBar11->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar11_Scroll);
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label30->Location = System::Drawing::Point(1272, 766);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(19, 20);
			this->label30->TabIndex = 56;
			this->label30->Text = L"Z";
			// 
			// label31
			// 
			this->label31->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label31->Location = System::Drawing::Point(1271, 39);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(158, 2);
			this->label31->TabIndex = 57;
			// 
			// comboBox3
			// 
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(1273, 12);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(155, 24);
			this->comboBox3->TabIndex = 58;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox3_SelectedIndexChanged);
			// 
			// label32
			// 
			this->label32->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label32->Location = System::Drawing::Point(1273, 357);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(158, 2);
			this->label32->TabIndex = 59;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label33->Location = System::Drawing::Point(1311, 359);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(86, 24);
			this->label33->TabIndex = 60;
			this->label33->Text = L"Фрактал";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label34->Location = System::Drawing::Point(1269, 422);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(83, 20);
			this->label34->TabIndex = 61;
			this->label34->Text = L"Итерации";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1358, 422);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(70, 20);
			this->textBox1->TabIndex = 62;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label35->Location = System::Drawing::Point(1313, 631);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(84, 24);
			this->label35->TabIndex = 39;
			this->label35->Text = L"Заливка";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1271, 880);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(162, 23);
			this->button1->TabIndex = 63;
			this->button1->Text = L"Экспортировать в файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1449, 915);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->trackBar11);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->trackBar10);
			this->Controls->Add(this->trackBar9);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->trackBar7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->trackBar6);
			this->Controls->Add(this->trackBar5);
			this->Controls->Add(this->trackBar4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->rotation_label);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar11))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		};
		// обработка точек в зависимости от типа проекции
		System::Void processDots(vector<vector<CustomPair>>* custom_figure_edges, vector<vector<CustomPair>>* custom_figure_edges_copy)
		{

			for (int i = 0; i < custom_figure_edges->size(); i++)
			{
				vector<CustomPair> current_custom_figure_edges = custom_figure_edges->at(i);
				vector<CustomPair> current_custom_figure_edges_copy = vector<CustomPair>();

				for (int l = 0; l < current_custom_figure_edges.size(); l++)
				{
					vector<PointXYZ>* custom_vector_copy = new vector<PointXYZ>();
					for (int j = 0; j < current_custom_figure_edges.at(l).second->size(); j++)
					{
						process(current_custom_figure_edges.at(l).second, custom_vector_copy, j, i);
					}
					current_custom_figure_edges_copy.push_back(CustomPair(i + 1, custom_vector_copy));
				}

				custom_figure_edges_copy->push_back(current_custom_figure_edges_copy);
			}
		};
		float interpolate(float min, float max, float gradient)
		{
			return min + (max - min) * Math::Max(0.0f, Math::Min(gradient, 1.0f));
		};
		// построчная обработка z-буффера
		System::Void scan_line(int y, PointXYZ pa, PointXYZ pb, PointXYZ pc, PointXYZ pd, double I_D, int figureIndex)
		{
			auto gradient1 = pa.y != pb.y ? (y - pa.y) / (pb.y - pa.y) : 1;
			auto gradient2 = pc.y != pd.y ? (y - pc.y) / (pd.y - pc.y) : 1;

			int sx = (int)interpolate(pa.x, pb.x, gradient1);
			int ex = (int)interpolate(pc.x, pd.x, gradient2);

			float z1 = interpolate(pa.z, pb.z, gradient1);
			float z2 = interpolate(pc.z, pd.z, gradient2);

			sx += offset_point->x;
			ex += offset_point->x;
			y += offset_point->y;
			for (int x = sx; x <= ex; x++)
			{
				float gradient = (x - sx) / (float)(ex - sx);
				auto z = interpolate(z1, z2, gradient);

				if (x >= 0 && y >= 0 && x < bmWidth && y < bmHeight)
				{
					if (z < z_buffer->at(y)->at(x))
					{
						z_buffer->at(y)->at(x) = z;
						if (x == sx || x == ex)
						{
							if (is_filled_slow_mo)
							{
								gr->FillRectangle(edge_solid_brush, (int)x, (int)y, 1, 1);
							}
							else
							{
								set_pixel((int)x, (int)y, Color::FromArgb(edge_color->at(figureIndex)), I_D);
							}
						}
						else
						{
							if (is_filled_slow_mo)
							{
								gr->FillRectangle(fill_edge_solid_brush, (int)x, (int)y, 1, 1);
							}
							else
							{
								set_pixel((int)x, (int)y, Color::FromArgb(fill_edge_color->at(figureIndex)), I_D);
							}
						}
					}

				}
			}
		}
		// устанавливаем цвет писеля для Bitmap
		System::Void set_pixel(int x, int y, Color col)
		{
			scan0[y * scan0_stride + x * scan0_depth] = col.B;
			scan0[y * scan0_stride + x * scan0_depth + 1] = col.G;
			scan0[y * scan0_stride + x * scan0_depth + 2] = col.R;
			scan0[y * scan0_stride + x * scan0_depth + 3] = col.A;
		}

		System::Void set_pixel(int x, int y, Color col, double I_D)
		{
			scan0[y * scan0_stride + x * scan0_depth] = col.B * I_D;
			scan0[y * scan0_stride + x * scan0_depth + 1] = col.G * I_D;
			scan0[y * scan0_stride + x * scan0_depth + 2] = col.R * I_D;
			scan0[y * scan0_stride + x * scan0_depth + 3] = col.A * I_D;
		}
		// заполнение фигуры
		System::Void fill(vector<vector<CustomPair>>* custom_figure_edges_copy)
		{
			if (z_buffer == nullptr) { return; }
			else {
				// fix memory leak
				for (int i = 0; i < z_buffer->size(); i++) {
					if (z_buffer->at(i) != nullptr) {
						z_buffer->at(i)->clear();
					}
				}
				z_buffer->clear(); 
			}

			if (custom_figure_edges_copy->size() <= 0)
				return;

			for (int i = 0; i < pictureBox1->Height; i++)
			{
				vector<double>* current = new vector<double>(pictureBox1->Width, 1.7976931348623158e+308);
				z_buffer->push_back(current);
			}

			for (int i = 0; i < custom_figure_edges_copy->size(); i++)
			{
				for (int ik = 0; ik < custom_figure_edges_copy->at(i).size(); ik++)
				{
					auto current_edges_copy = custom_figure_edges_copy->at(i).at(ik).second;

					auto p1 = current_edges_copy->at(0);
					auto p2 = current_edges_copy->at(1);
					auto p3 = current_edges_copy->at(2);

					if (direction == Direction::Z)
					{
						// ничего не меняем
					}
					else if (direction == Direction::Y)
					{
						auto tempP1x = p1.x;
						auto tempP1y = p1.y;
						auto tempP1z = p1.z;

						auto tempP2x = p2.x;
						auto tempP2y = p2.y;
						auto tempP2z = p2.z;

						auto tempP3x = p3.x;
						auto tempP3y = p3.y;
						auto tempP3z = p3.z;

						// x остается, y и z меняем

						p1.y = tempP1z;
						p1.z = tempP1y;

						p2.y = tempP2z;
						p2.z = tempP2y;

						p3.y = tempP3z;
						p3.z = tempP3y;
					}
					else if (direction == Direction::X)
					{
						auto tempP1x = p1.x;
						auto tempP1y = p1.y;
						auto tempP1z = p1.z;

						auto tempP2x = p2.x;
						auto tempP2y = p2.y;
						auto tempP2z = p2.z;

						auto tempP3x = p3.x;
						auto tempP3y = p3.y;
						auto tempP3z = p3.z;

						// x = y, y = z и z = x

						p1.x = tempP1y;
						p1.y = tempP1z;
						p1.z = tempP1x;

						p2.x = tempP2y;
						p2.y = tempP2z;
						p2.z = tempP2x;

						p3.x = tempP3y;
						p3.y = tempP3z;
						p3.z = tempP3x;
					}

					if (p1.y > p2.y)
					{
						auto temp = p2;
						p2 = p1;
						p1 = temp;
					}

					if (p2.y > p3.y)
					{
						auto temp = p2;
						p2 = p3;
						p3 = temp;
					}

					if (p1.y > p2.y)
					{
						auto temp = p2;
						p2 = p1;
						p1 = temp;
					}

					float dP1P2, dP1P3;

					if (p2.y - p1.y > 0)
					{
						dP1P2 = (p2.x - p1.x) / (p2.y - p1.y);

					}
					else
					{
						dP1P2 = 0;
					}


					if (p3.y - p1.y > 0)
					{
						dP1P3 = (p3.x - p1.x) / (p3.y - p1.y);
					}
					else
					{
						dP1P3 = 0;
					}


					// Направляющий вектор в прямой (x2 - x1, y2 - y1, z2 - z1)
					// Первая точка - 0 ,0 , 1
					// Вторая точка - центр треугольника - (x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3, (z1 + z2 + z3) / 3

					int dx = (p1.x + p2.x + p3.x) / 3;
					int dy = (p1.y + p2.y + p3.y) / 3;
					int dz = (p1.z + p2.z + p3.z) / 3;

					// Уравнение прямой
					// double vx = 0 - dx;
					// double vy = 0 - dy;
					// double vz = 1 - dz;

					int vx = light_source->x - dx;
					int vy = light_source->y - dy;
					int vz = light_source->z - dz;

					// Вектор нормали плоскости
					// i .. ((y2 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1))
					// j .. ((z2 - z1) * (x3 - x1) - (x2 - x1) * (z3 - z1))
					// k .. ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1))

					int ni = ((p2.y - p1.y) * (p3.z - p1.z) - (p2.z - p1.z) * (p3.y - p1.y));
					int nj = ((p2.z - p1.z) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.z - p1.z));
					int nk = ((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x));

					double I_ = (vx * ni + vy * nj + vz * nk) / (Math::Sqrt(dx * dx + dy * dy + dz * dz) * Math::Sqrt(ni * ni + nj * nj + nk * nk));

					// Результат
					double I_D = Math::Sqrt(1 - I_ * I_);

					if (dP1P2 > dP1P3)
					{
						for (auto y = (int)p1.y; y <= (int)p3.y; y++)
						{
							if (y < p2.y)
							{
								scan_line(y, p1, p3, p1, p2, is_flat_filling ? I_D : 1.0, i);
							}
							else
							{
								scan_line(y, p1, p3, p2, p3, is_flat_filling ? I_D : 1.0, i);
							}
						}
					}
					else
					{
						for (auto y = (int)p1.y; y <= (int)p3.y; y++)
						{
							if (y < p2.y)
							{
								scan_line(y, p1, p2, p1, p3, is_flat_filling ? I_D : 1.0, i);
							}
							else
							{
								scan_line(y, p2, p3, p1, p3, is_flat_filling ? I_D : 1.0, i);
							}
						}
					}
				}
			}

			custom_figure_edges_copy->clear();
			// custom_figure_edges_copy->erase(custom_figure_edges_copy->begin());
		};
		System::Double degreesToRadians(int angle)
		{
			return angle * Math::PI / 180;
		}
		// трансформация объекта
		System::Void process(vector<PointXYZ>* custom_figure, vector<PointXYZ>* custom_figure_copy, int index, int figureIndex)
		{
			if (x_angle->size() == 0 && y_angle->size() == 0 && z_angle->size() == 0)
			{
				return;
			}

			PointXYZ dot = custom_figure->at(index);
			// меняем размер
			float x = dot.x * size->at(figureIndex);
			float y = dot.y * size->at(figureIndex);
			float z = dot.z * size->at(figureIndex);
			// добавляем отступы
			x = x + additional_offset_point->at(figureIndex).x;
			y = y + additional_offset_point->at(figureIndex).y;
			z = z + additional_offset_point->at(figureIndex).z;
			// подсчет
			float newX, newY, newZ;
			float newX1 = x * Math::Cos(degreesToRadians(x_angle->at(figureIndex))) - y * Math::Sin(degreesToRadians(x_angle->at(figureIndex)));
			float newY1 = x * Math::Sin(degreesToRadians(x_angle->at(figureIndex))) + y * Math::Cos(degreesToRadians(x_angle->at(figureIndex)));
			float newZ1 = z;
			float newX2 = newX1 * Math::Cos(degreesToRadians(y_angle->at(figureIndex))) + newZ1 * Math::Sin(degreesToRadians(y_angle->at(figureIndex)));
			float newY2 = newY1;
			float newZ2 = -newX1 * Math::Sin(degreesToRadians(y_angle->at(figureIndex))) + newZ1 * Math::Cos(degreesToRadians(y_angle->at(figureIndex)));
			newX = newX2;
			newY = newY2 * Math::Cos(degreesToRadians(z_angle->at(figureIndex))) - newZ2 * Math::Sin(degreesToRadians(z_angle->at(figureIndex)));
			newZ = newY2 * Math::Sin(degreesToRadians(z_angle->at(figureIndex))) + newZ2 * Math::Cos(degreesToRadians(z_angle->at(figureIndex)));
			custom_figure_copy->push_back(PointXYZ(newX, newY, newZ));
		};
		// отрисовка
		System::Void draw(vector<vector<CustomPair>>* custom_figure_edges_copy)
		{
			if (custom_figure_edges_copy->size() <= 0)
				return;

			for (int i = 0; i < custom_figure_edges_copy->size(); i++)
			{
				for (int ik = 0; ik < custom_figure_edges_copy->at(i).size(); ik++)
				{
					vector<PointXYZ>* custom_vector_copy = custom_figure_edges_copy->at(i).at(ik).second;
					for (int j = 0; j < custom_vector_copy->size() - 1; j++)
					{
						float f1, s1, f2, s2;
						if (direction == Direction::Z)
						{
							f1 = custom_vector_copy->at(j).x;
							s1 = custom_vector_copy->at(j).y;
							f2 = custom_vector_copy->at(j + 1).x;
							s2 = custom_vector_copy->at(j + 1).y;
						}
						else if (direction == Direction::Y)
						{
							f1 = custom_vector_copy->at(j).x;
							s1 = custom_vector_copy->at(j).z;
							f2 = custom_vector_copy->at(j + 1).x;
							s2 = custom_vector_copy->at(j + 1).z;
						}
						else if (direction == Direction::X)
						{
							f1 = custom_vector_copy->at(j).y;
							s1 = custom_vector_copy->at(j).z;
							f2 = custom_vector_copy->at(j + 1).y;
							s2 = custom_vector_copy->at(j + 1).z;
						}

						f1 = (int)f1 + (int)offset_point->x;
						s1 = (int)s1 + (int)offset_point->y;
						f2 = (int)f2 + (int)offset_point->x;
						s2 = (int)s2 + (int)offset_point->y;

						if ((int)f1 >= (int)f2)
						{
							int a = (int)s2 - (int)s1;
							int b = (int)f1 - (int)f2;
							int c = (int)f2 * (int)s1 - (int)f1 * (int)s2;

							for (int l = (int)f2; l < (int)f1; l++)
							{
								int y = (-c - a * l) / b;
								if (l >= 0 && y >= 0 && l < bmWidth && y < bmHeight)
								{
									set_pixel((int)l, (int)y, Color::FromArgb(edge_color->at(i)));
								}
							}
						}
						else
						{
							int a = (int)s1 - (int)s2;
							int b = (int)f2 - (int)f1;
							int c = (int)f1 * (int)s2 - (int)f2 * (int)s1;

							for (int l = (int)f1; l < (int)f2; l++)
							{
								int y = (-c - a * l) / b;
								if (l >= 0 && y >= 0 && l < bmWidth && y < bmHeight)
								{
									set_pixel((int)l, (int)y, Color::FromArgb(edge_color->at(i)));
								}
							}
						}

					}

					// Рисуем последнюю часть
					float f1, s1, f2, s2;
					int first = 0, last = custom_vector_copy->size() - 1;
					if (direction == Direction::Z)
					{
						f1 = custom_vector_copy->at(first).x;
						s1 = custom_vector_copy->at(first).y;
						f2 = custom_vector_copy->at(last).x;
						s2 = custom_vector_copy->at(last).y;
					}
					else if (direction == Direction::Y)
					{
						f1 = custom_vector_copy->at(first).x;
						s1 = custom_vector_copy->at(first).z;
						f2 = custom_vector_copy->at(last).x;
						s2 = custom_vector_copy->at(last).z;
					}
					else if (direction == Direction::X)
					{
						f1 = custom_vector_copy->at(first).y;
						s1 = custom_vector_copy->at(first).z;
						f2 = custom_vector_copy->at(last).y;
						s2 = custom_vector_copy->at(last).z;
					}

					f1 = (int)f1 + (int)offset_point->x;
					s1 = (int)s1 + (int)offset_point->y;
					f2 = (int)f2 + (int)offset_point->x;
					s2 = (int)s2 + (int)offset_point->y;

					if ((int)f1 >= (int)f2)
					{
						int a = (int)s2 - (int)s1;
						int b = (int)f1 - (int)f2;
						int c = (int)f2 * (int)s1 - (int)f1 * (int)s2;

						for (int l = (int)f2; l < (int)f1; l++)
						{
							int y = (-c - a * l) / b;
							if (l >= 0 && y >= 0 && l < bmWidth && y < bmHeight)
							{
								set_pixel((int)l, (int)y, Color::FromArgb(edge_color->at(i)));
							}
						}
					}
					else
					{
						int a = (int)s1 - (int)s2;
						int b = (int)f2 - (int)f1;
						int c = (int)f1 * (int)s2 - (int)f2 * (int)s1;

						for (int l = (int)f1; l < (int)f2; l++)
						{
							int y = (-c - a * l) / b;
							if (l >= 0 && y >= 0 && l < bmWidth && y < bmHeight)
							{
								set_pixel((int)l, (int)y, Color::FromArgb(edge_color->at(i)));
							}
						}
					}
				}
			}

			for (int i = 0; i < custom_figure_edges_copy->size(); i++)
			{
				for (int j = 0; j < custom_figure_edges_copy->at(i).size(); j++)
				{
					custom_figure_edges_copy->at(i).at(j).second->clear();
				}
				custom_figure_edges_copy->at(i).clear();
			}
			custom_figure_edges_copy->clear();
		};
#pragma endregion
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		if (x_angle->size() > 0)
		{
			x_angle->at(chosen_figure) = trackBar1->Value;
			paintScene();
		}
	}
	private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
		if (y_angle->size() > 0)
		{
			y_angle->at(chosen_figure) = trackBar2->Value;
			paintScene();
		}
	}
	private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e) {
		if (z_angle->size() > 0)
		{
			z_angle->at(chosen_figure) = trackBar3->Value;
			paintScene();
		}
	}
	private: System::Void trackBar4_Scroll(System::Object^ sender, System::EventArgs^ e) {
		if (additional_offset_point->size() > 0)
		{
			additional_offset_point->at(chosen_figure).x = trackBar4->Value;
			paintScene();
		}
	}
	private: System::Void trackBar5_Scroll(System::Object^ sender, System::EventArgs^ e) {
		if (additional_offset_point->size() > 0)
		{
			additional_offset_point->at(chosen_figure).y = trackBar5->Value;
			paintScene();
		}
	}
	private: System::Void trackBar6_Scroll(System::Object^ sender, System::EventArgs^ e) {
		if (additional_offset_point->size() > 0)
		{
			additional_offset_point->at(chosen_figure).z = trackBar6->Value;
			paintScene();
		}
	}
	private: System::Void trackBar7_Scroll(System::Object^ sender, System::EventArgs^ e) {
		if (size->size() > 0)
		{
			size->at(chosen_figure) = trackBar7->Value;
			paintScene();
		}
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->SelectedIndex == 0)
		{
			direction = Direction::X;
		}
		else if (comboBox1->SelectedIndex == 1)
		{
			direction = Direction::Y;
		}
		else if (comboBox1->SelectedIndex == 2)
		{
			direction = Direction::Z;
		}
		paintScene();
	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox2->SelectedIndex == 0)
		{
			fractal = Fractal::CANTOR_SET;
		}
		else if (comboBox2->SelectedIndex == 1)
		{
			fractal = Fractal::PYTHAGORAS_TREE;
		}
		else if (comboBox2->SelectedIndex == 2)
		{
			fractal = Fractal::MENGER_SPONGE;
		}
	}
	private: System::Void cantorSetImport() {
		StreamWriter^ sw = gcnew StreamWriter("cantor.txt");
		// Cube vertices
		vector<PointXYZ>* vertices = new vector<PointXYZ>();
		vertices->push_back(PointXYZ(-2, 0.15, 1)); // 0 вершина
		vertices->push_back(PointXYZ(-2, 0.15, -1)); // 1 вершина
		vertices->push_back(PointXYZ(2, 0.15, -1)); // 2 вершина
		vertices->push_back(PointXYZ(2, 0.15, 1)); // 3 вершина
		vertices->push_back(PointXYZ(-2, -0.15, 1)); // 4 вершина
		vertices->push_back(PointXYZ(-2, -0.15, -1)); // 5 вершина
		vertices->push_back(PointXYZ(2, -0.15, -1)); // 6 вершина
		vertices->push_back(PointXYZ(2, -0.15, 1)); // 7 вершина
		double cons_z = 1;
		double y_add = 0.3;
		cantor_mn_to_file(vertices, sw);
		vertices->clear();
		vector<double>* line = new vector<double>();
		line->push_back(-2.0);
		line->push_back(2.0);
		cantor_mn_to_file(line, iteration_count, cons_z, y_add, sw);
		sw->Close();
	}
	private: System::Void cantor_mn_to_file(vector<double>*  line, int n, double cons_z, double y_add, StreamWriter^ sw) {
		if (n >= 1) {
			int cur_n = n - 1;
			double cur_y_add = y_add;
			vector<double>* cur_line = divide_section(line);
			vector<double>* left_s = new vector<double>();
			left_s->push_back(cur_line->at(0));
			left_s->push_back(cur_line->at(1));
			vector<double>* right_s = new vector<double>();
			right_s->push_back(cur_line->at(2));
			right_s->push_back(cur_line->at(3));
			vector<PointXYZ>* vertices = new vector<PointXYZ>();
			vertices->push_back(PointXYZ(left_s->at(0), 0.15 - cur_y_add, cons_z));
			vertices->push_back(PointXYZ(left_s->at(0), 0.15 - cur_y_add, 0 - cons_z));
			vertices->push_back(PointXYZ(left_s->at(1), 0.15 - cur_y_add, 0 - cons_z));
			vertices->push_back(PointXYZ(left_s->at(1), 0.15 - cur_y_add, cons_z));
			vertices->push_back(PointXYZ(left_s->at(0), -0.15 - cur_y_add, cons_z));
			vertices->push_back(PointXYZ(left_s->at(0), -0.15 - cur_y_add, 0 - cons_z));
			vertices->push_back(PointXYZ(left_s->at(1), -0.15 - cur_y_add, 0 - cons_z));
			vertices->push_back(PointXYZ(left_s->at(1), -0.15 - cur_y_add, cons_z));

			cantor_mn_to_file(vertices, sw);

			vertices->clear();

			vertices->push_back(PointXYZ(right_s->at(0), 0.15 - cur_y_add, cons_z));
			vertices->push_back(PointXYZ(right_s->at(0), 0.15 - cur_y_add, 0 - cons_z));
			vertices->push_back(PointXYZ(right_s->at(1), 0.15 - cur_y_add, 0 - cons_z));
			vertices->push_back(PointXYZ(right_s->at(1), 0.15 - cur_y_add, cons_z));
			vertices->push_back(PointXYZ(right_s->at(0), -0.15 - cur_y_add, cons_z));
			vertices->push_back(PointXYZ(right_s->at(0), -0.15 - cur_y_add, 0 - cons_z));
			vertices->push_back(PointXYZ(right_s->at(1), -0.15 - cur_y_add, 0 - cons_z));
			vertices->push_back(PointXYZ(right_s->at(1), -0.15 - cur_y_add, cons_z));

			cantor_mn_to_file(vertices, sw);

			vertices->clear();

			cur_y_add += 0.3;
			cantor_mn_to_file(left_s, cur_n, cons_z, cur_y_add, sw);
			cantor_mn_to_file(right_s, cur_n, cons_z, cur_y_add, sw);

			left_s->clear();
			right_s->clear();
		}

	}
	private: System::Void cantor_mn_to_file(vector<PointXYZ>* vertices, StreamWriter^ sw) {
		sw->WriteLine("First:");
		sw->WriteLine("vertex: " + vertices->at(0).x + " " + vertices->at(0).y * (-1) + " " + vertices->at(0).z);
		sw->WriteLine("vertex: " + vertices->at(3).x + " " + vertices->at(3).y * (-1) + " " + vertices->at(3).z);
		sw->WriteLine("vertex: " + vertices->at(2).x + " " + vertices->at(2).y * (-1) + " " + vertices->at(2).z);

		sw->WriteLine("Second:");
		sw->WriteLine("vertex: " + vertices->at(0).x + " " + vertices->at(0).y * (-1) + " " + vertices->at(0).z);
		sw->WriteLine("vertex: " + vertices->at(2).x + " " + vertices->at(2).y * (-1) + " " + vertices->at(2).z);
		sw->WriteLine("vertex: " + vertices->at(1).x + " " + vertices->at(1).y * (-1) + " " + vertices->at(1).z);

		sw->WriteLine("Third:");
		sw->WriteLine("vertex: " + vertices->at(3).x + " " + vertices->at(3).y * (-1) + " " + vertices->at(3).z);
		sw->WriteLine("vertex: " + vertices->at(7).x + " " + vertices->at(7).y * (-1) + " " + vertices->at(7).z);
		sw->WriteLine("vertex: " + vertices->at(6).x + " " + vertices->at(6).y * (-1) + " " + vertices->at(6).z);

		sw->WriteLine("Fourth:");
		sw->WriteLine("vertex: " + vertices->at(6).x + " " + vertices->at(6).y * (-1) + " " + vertices->at(6).z);
		sw->WriteLine("vertex: " + vertices->at(2).x + " " + vertices->at(2).y * (-1) + " " + vertices->at(2).z);
		sw->WriteLine("vertex: " + vertices->at(3).x + " " + vertices->at(3).y * (-1) + " " + vertices->at(3).z);

		sw->WriteLine("Fifth:");
		sw->WriteLine("vertex: " + vertices->at(6).x + " " + vertices->at(6).y * (-1) + " " + vertices->at(6).z);
		sw->WriteLine("vertex: " + vertices->at(4).x + " " + vertices->at(4).y * (-1) + " " + vertices->at(4).z);
		sw->WriteLine("vertex: " + vertices->at(5).x + " " + vertices->at(5).y * (-1) + " " + vertices->at(5).z);

		sw->WriteLine("Sixth:");
		sw->WriteLine("vertex: " + vertices->at(6).x + " " + vertices->at(6).y * (-1) + " " + vertices->at(6).z);
		sw->WriteLine("vertex: " + vertices->at(7).x + " " + vertices->at(7).y * (-1) + " " + vertices->at(7).z);
		sw->WriteLine("vertex: " + vertices->at(4).x + " " + vertices->at(4).y * (-1) + " " + vertices->at(4).z);

		sw->WriteLine("Seventh:");
		sw->WriteLine("vertex: " + vertices->at(0).x + " " + vertices->at(0).y * (-1) + " " + vertices->at(0).z);
		sw->WriteLine("vertex: " + vertices->at(4).x + " " + vertices->at(4).y * (-1) + " " + vertices->at(4).z);
		sw->WriteLine("vertex: " + vertices->at(5).x + " " + vertices->at(5).y * (-1) + " " + vertices->at(5).z);

		sw->WriteLine("Eighth:");
		sw->WriteLine("vertex: " + vertices->at(0).x + " " + vertices->at(0).y * (-1) + " " + vertices->at(0).z);
		sw->WriteLine("vertex: " + vertices->at(5).x + " " + vertices->at(5).y * (-1) + " " + vertices->at(5).z);
		sw->WriteLine("vertex: " + vertices->at(1).x + " " + vertices->at(1).y * (-1) + " " + vertices->at(1).z);

		sw->WriteLine("Nineth:");
		sw->WriteLine("vertex: " + vertices->at(3).x + " " + vertices->at(3).y * (-1) + " " + vertices->at(3).z);
		sw->WriteLine("vertex: " + vertices->at(4).x + " " + vertices->at(4).y * (-1) + " " + vertices->at(4).z);
		sw->WriteLine("vertex: " + vertices->at(0).x + " " + vertices->at(0).y * (-1) + " " + vertices->at(0).z);

		sw->WriteLine("Tenth:");
		sw->WriteLine("vertex: " + vertices->at(3).x + " " + vertices->at(3).y * (-1) + " " + vertices->at(3).z);
		sw->WriteLine("vertex: " + vertices->at(4).x + " " + vertices->at(4).y * (-1) + " " + vertices->at(4).z);
		sw->WriteLine("vertex: " + vertices->at(7).x + " " + vertices->at(7).y * (-1) + " " + vertices->at(7).z);

		sw->WriteLine("Eleventh:");
		sw->WriteLine("vertex: " + vertices->at(5).x + " " + vertices->at(5).y * (-1) + " " + vertices->at(5).z);
		sw->WriteLine("vertex: " + vertices->at(1).x + " " + vertices->at(1).y * (-1) + " " + vertices->at(1).z);
		sw->WriteLine("vertex: " + vertices->at(6).x + " " + vertices->at(6).y * (-1) + " " + vertices->at(6).z);

		sw->WriteLine("Twelwth:");
		sw->WriteLine("vertex: " + vertices->at(1).x + " " + vertices->at(1).y * (-1) + " " + vertices->at(1).z);
		sw->WriteLine("vertex: " + vertices->at(6).x + " " + vertices->at(6).y * (-1) + " " + vertices->at(6).z);
		sw->WriteLine("vertex: " + vertices->at(2).x + " " + vertices->at(2).y * (-1) + " " + vertices->at(2).z);
	}
	private: vector<double>* divide_section(vector<double>* section) {
		vector<double>* line = new vector<double>();
		double cur = Math::Abs((section->at(0) - section->at(1)) / 3);
		double third = section->at(0) + cur;
		double fourth = section->at(1) - cur;
		line->push_back(section->at(0));
		line->push_back(third);
		line->push_back(fourth);
		line->push_back(section->at(1));
		return line;
	}
	private: System::Void mengerSpongeImport() {
		StreamWriter^ sw = gcnew StreamWriter("menger.txt");
		// StreamWriter^ sw_time = gcnew StreamWriter("timenger.txt", true);
		// auto timer = gcnew System::Diagnostics::Stopwatch();
		// timer->Start();
		switch (iteration_count)
		{
		case 0:
			menger(0, 0, 0, 0.1, sw);
			break;
		case 1:
			menger_sponge(0, 0, 0, 0.1, sw);
			break;
		case 2:
			menger_sponge_3(0, 0, 0, 0.1, sw);
			break;
		case 3:
			menger_sponge_4(0, 0, 0, 0.1, sw);
			break;
		default:
			break;
		}
		sw->Close();
		// timer->Stop();
		// sw_time->WriteLine("import with " + iteration_count + " iterations takes " + timer->Elapsed.ToString("mm':'ss':'fff"));
		// sw_time->Close();
	}
	private: System::Void menger(double xs, double ys, double zs, double step, StreamWriter^ sw) {
		
		//front
		sw->WriteLine("vertex: " + xs + " " + ys * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + ys * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + xs + " " + (ys + step) * (-1) + " " + (-zs));

		sw->WriteLine("vertex: " + xs + " " + (ys + step) * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + ys * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + (ys + step) * (-1) + " " + (-zs));

		//back
		sw->WriteLine("vertex: " + xs + " " + ys * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + ys * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + xs + " " + (ys + step) * (-1) + " " + (-0.1 - zs));

		sw->WriteLine("vertex: " + xs + " " + (ys + step) * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + ys * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + (ys + step) * (-1) + " " + (-0.1 - zs));

		//left
		sw->WriteLine("vertex: " + xs + " " + ys * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + xs + " " + ys * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + xs + " " + (ys + step) * (-1) + " " + (-zs));

		sw->WriteLine("vertex: " + xs + " " + ys * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + xs + " " + (ys + step) * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + xs + " " + (ys + step) * (-1) + " " + (-zs));

		//rigth
		sw->WriteLine("vertex: " + (xs + step) + " " + ys * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + ys * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + (ys + step) * (-1) + " " + (-0.1 - zs));

		sw->WriteLine("vertex: " + (xs + step) + " " + ys * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + (ys + step) * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + (ys + step) * (-1) + " " + (-0.1 - zs));

		//up
		sw->WriteLine("vertex: " + xs + " " + (ys + step) * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + xs + " " + (ys + step) * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + (ys + step) * (-1) + " " + (-0.1 - zs));

		sw->WriteLine("vertex: " + (xs + step) + " " + (ys + step) * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + xs + " " + (ys + step) * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + (ys + step) * (-1) + " " + (-zs));

		//down
		sw->WriteLine("vertex: " + xs + " " + ys * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + xs + " " + ys * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + ys * (-1) + " " + (-0.1 - zs));

		sw->WriteLine("vertex: " + (xs + step) + " " + ys * (-1) + " " + (-0.1 - zs));
		sw->WriteLine("vertex: " + xs + " " + ys * (-1) + " " + (-zs));
		sw->WriteLine("vertex: " + (xs + step) + " " + ys * (-1) + " " + (-zs));
	}
	private: System::Void menger_sponge(double xs, double ys, double zs, double step, StreamWriter^ sw) {
		menger(xs, ys, zs, step, sw);
		menger(xs + step, ys, zs, step, sw);
		menger(xs + (step * 2), ys, zs, step, sw);

		menger(xs, ys + step, zs, step, sw);
		menger(xs + (step * 2), ys + step, zs, step, sw);

		menger(xs, ys + (step * 2), zs, step, sw);
		menger(xs + step, ys + (step * 2), zs, step, sw);
		menger(xs + (step * 2), ys + (step * 2), zs, step, sw);

		//inside
		menger(xs, ys, zs + step, step, sw);
		menger(xs + (step * 2), ys, zs + step, step, sw);

		menger(xs, ys + (step * 2), zs + step, step, sw);
		menger(xs + (step * 2), ys + (step * 2), zs + step, step, sw);

		//back
		menger(xs, ys, zs + (step * 2), step, sw);
		menger(xs + step, ys, zs + (step * 2), step, sw);
		menger(xs + (step * 2), ys, zs + (step * 2), step, sw);

		menger(xs, ys + step, zs + (step * 2), step, sw);
		menger(xs + (step * 2), ys + step, zs + (step * 2), step, sw);

		menger(xs, ys + (step * 2), zs + (step * 2), step, sw);
		menger(xs + step, ys + (step * 2), zs + (step * 2), step, sw);
		menger(xs + (step * 2), ys + (step * 2), zs + (step * 2), step, sw);
	}

	private: System::Void menger_sponge_3(double xs, double ys, double zs, double step, StreamWriter^ sw) {
		double cur_step = step * 3;
		menger_sponge(xs, ys, zs, step, sw);
		menger_sponge(xs + cur_step, ys, zs, step, sw);
		menger_sponge(xs + (cur_step * 2), ys, zs, step, sw);

		menger_sponge(xs, ys + cur_step, zs, step, sw);
		menger_sponge(xs + (cur_step * 2), ys + cur_step, zs, step, sw);

		menger_sponge(xs, ys + (cur_step * 2), zs, step, sw);
		menger_sponge(xs + cur_step, ys + (cur_step * 2), zs, step, sw);
		menger_sponge(xs + (cur_step * 2), ys + (cur_step * 2), zs, step, sw);

			//inside
		menger_sponge(xs, ys, zs + cur_step, step, sw);
		menger_sponge(xs + (cur_step * 2), ys, zs + cur_step, step, sw);

		menger_sponge(xs, ys + (cur_step * 2), zs + cur_step, step, sw);
		menger_sponge(xs + (cur_step * 2), ys + (cur_step * 2), zs + cur_step, step, sw);

		//back
		menger_sponge(xs, ys, zs + (cur_step * 2), step, sw);
		menger_sponge(xs + cur_step, ys, zs + (cur_step * 2), step, sw);
		menger_sponge(xs + (cur_step * 2), ys, zs + (cur_step * 2), step, sw);

		menger_sponge(xs, ys + cur_step, zs + (cur_step * 2), step, sw);
		menger_sponge(xs + (cur_step * 2), ys + cur_step, zs + (cur_step * 2), step, sw);

		menger_sponge(xs, ys + (cur_step * 2), zs + (cur_step * 2), step, sw);
		menger_sponge(xs + cur_step, ys + (cur_step * 2), zs + (cur_step * 2), step, sw);
		menger_sponge(xs + (cur_step * 2), ys + (cur_step * 2), zs + (cur_step * 2), step, sw);
	}
	private: System::Void menger_sponge_4(double xs, double ys, double zs, double step, StreamWriter^ sw) {
		//front
		double cur_step = step * 9;
		menger_sponge_3(xs, ys, zs, step, sw);
		menger_sponge_3(xs + cur_step, ys, zs, step, sw);
		menger_sponge_3(xs + (cur_step * 2), ys, zs, step, sw);

		menger_sponge_3(xs, ys + cur_step, zs, step, sw);
		menger_sponge_3(xs + (cur_step * 2), ys + cur_step, zs, step, sw);

		menger_sponge_3(xs, ys + (cur_step * 2), zs, step, sw);
		menger_sponge_3(xs + cur_step, ys + (cur_step * 2), zs, step, sw);
		menger_sponge_3(xs + (cur_step * 2), ys + (cur_step * 2), zs, step, sw);

		//inside
		menger_sponge_3(xs, ys, zs + cur_step, step, sw);
		menger_sponge_3(xs + (cur_step * 2), ys, zs + cur_step, step, sw);

		menger_sponge_3(xs, ys + (cur_step * 2), zs + cur_step, step, sw);
		menger_sponge_3(xs + (cur_step * 2), ys + (cur_step * 2), zs + cur_step, step, sw);

		//back
		menger_sponge_3(xs, ys, zs + (cur_step * 2), step, sw);
		menger_sponge_3(xs + cur_step, ys, zs + (cur_step * 2), step, sw);
		menger_sponge_3(xs + (cur_step * 2), ys, zs + (cur_step * 2), step, sw);

		menger_sponge_3(xs, ys + cur_step, zs + (cur_step * 2), step, sw);
		menger_sponge_3(xs + (cur_step * 2), ys + cur_step, zs + (cur_step * 2), step, sw);

		menger_sponge_3(xs, ys + (cur_step * 2), zs + (cur_step * 2), step, sw);
		menger_sponge_3(xs + cur_step, ys + (cur_step * 2), zs + (cur_step * 2), step, sw);
		menger_sponge_3(xs + (cur_step * 2), ys + (cur_step * 2), zs + (cur_step * 2), step, sw);
	}
	private: System::Void pythagorasTreeImport() {
		int m = 33000;
		vector<double>* knx = new vector<double>();
		vector<double>* kny = new vector<double>();
		for (int i = 0; i < m; i++) {
			knx->push_back(0);
			kny->push_back(0);
		}
		fract(knx, kny);
		polygons_to_file(knx, kny, m);
		knx->erase(knx->begin());
		kny->erase(kny->begin());
	}
	private: System::Void traf(double xA, double yA, double xB, double yB, int r, vector<double>* knx, vector<double>* kny) {
		knx->at(r + 4) = xA;
		knx->at(r + 3) = xB;
		kny->at(r + 4) = yA;
		kny->at(r + 3) = yB;
		double xC = xA + yA - yB;
		knx->at(r) = xC;
		double yC = yA + xB - xA;
		kny->at(r) = yC;
		double xD = xB + yA - yB;
		knx->at(r + 2) = xD;
		double yD = yB + xB - xA;
		kny->at(r + 2) = yD;
		knx->at(r + 1) = (xC + xD + yC - yD) / 2;
		kny->at(r + 1) = (yC + yD + xD - xC) / 2;
	}
	private: System::Void fract(vector<double>* knx, vector<double>* kny) {
		traf(-1.0, 0.0, 1.0, 0.0, 0.0, knx, kny);
		int r = 1;
		for (int i = 0; i < 5 * (Math::Pow(2, iteration_count) - 1); i += 5) {
			traf(knx->at(i), kny->at(i), knx->at(i + 1), kny->at(i + 1), r * 5, knx, kny);
			traf(knx->at(i + 1), kny->at(i + 1), knx->at(i + 2), kny->at(i + 2), (r + 1) * 5, knx, kny);
			r += 2;
		}
	}
	private: System::Void polygons_to_file(vector<double>* knx, vector<double>* kny, int m) {
		StreamWriter^ sw = gcnew StreamWriter("pyth.txt");
		for (int i = 0; i < m && (knx->at(i) != 0.0 || kny->at(i) != 0.0 || knx->at(i + 1) != 0.0 || kny->at(i + 1) != 0); i += 5)
		{
			sw->WriteLine("Polygon1");
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 1) + " " + kny->at(i + 1) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 1) + " " + kny->at(i + 1) * (-1) + " " + (-1));
			
			sw->WriteLine("Polygon2");
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 1) + " " + kny->at(i + 1) * (-1) + " " + (-1));
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + (-1));

			sw->WriteLine("Polygon3");
			sw->WriteLine("vertex: " + knx->at(i + 1) + " " + kny->at(i + 1) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 2) + " " + kny->at(i + 2) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 2) + " " + kny->at(i + 2) * (-1) + " " + (-1));

			sw->WriteLine("Polygon4");
			sw->WriteLine("vertex: " + knx->at(i + 1) + " " + kny->at(i + 1) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 2) + " " + kny->at(i + 2) * (-1) + " " + (-1));
			sw->WriteLine("vertex: " + knx->at(i + 1) + " " + kny->at(i + 1) * (-1) + " " + (-1) );

			sw->WriteLine("ExtraPolygon1");
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 1) + " " + kny->at(i + 1) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 2) + " " + kny->at(i + 2) * (-1) + " " + 1);

			sw->WriteLine("ExtraPolygon2");
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + (-1));
			sw->WriteLine("vertex: " + knx->at(i + 1) + " " + kny->at(i + 1) * (-1) + " " + (-1));
			sw->WriteLine("vertex: " + knx->at(i + 2) + " " + kny->at(i + 2) * (-1) + " " + (-1));

			sw->WriteLine("Polygon5");
			sw->WriteLine("vertex: " + knx->at(i + 2) + " " + kny->at(i + 2) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 3) + " " + kny->at(i + 3) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 3) + " " + kny->at(i + 3) * (-1) + " " + (-1));

			sw->WriteLine("Polygon6");
			sw->WriteLine("vertex: " + knx->at(i + 2) + " " + kny->at(i + 2) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 3) + " " + kny->at(i + 3) * (-1) + " " + (-1));
			sw->WriteLine("vertex: " + knx->at(i + 2) + " " + kny->at(i + 2) * (-1) + " " + (-1));

			sw->WriteLine("DownPolygon1");
			sw->WriteLine("vertex: " + knx->at(i + 3) + " " + kny->at(i + 3) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 4) + " " + kny->at(i + 4) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 4) + " " + kny->at(i + 4) * (-1) + " " + (-1));

			sw->WriteLine("DownPolygon2");
			sw->WriteLine("vertex: " + knx->at(i + 3) + " " + kny->at(i + 3) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 4) + " " + kny->at(i + 4) * (-1) + " " + (-1));
			sw->WriteLine("vertex: " + knx->at(i + 3) + " " + kny->at(i + 3) * (-1) + " " + (-1));

			sw->WriteLine("lastpolygon1");
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 4) + " " + kny->at(i + 4) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 4) + " " + kny->at(i + 4) * (-1) + " " + (-1));

			sw->WriteLine("LastPolygon2");
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 4) + " " + kny->at(i + 4) * (-1) + " " + (-1));
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + (-1));

			sw->WriteLine("FrontPolygon1");
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 2) + " " + kny->at(i + 2) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 3) + " " + kny->at(i + 3) * (-1) + " " + 1);

			sw->WriteLine("FrontPolygon2");
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 4) + " " + kny->at(i + 4) * (-1) + " " + 1);
			sw->WriteLine("vertex: " + knx->at(i + 3) + " " + kny->at(i + 3) * (-1) + " " + 1);

			sw->WriteLine("BackPolygon1");
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + (-1));
			sw->WriteLine("vertex: " + knx->at(i + 2) + " " + kny->at(i + 2) * (-1) + " " + (-1));
			sw->WriteLine("vertex: " + knx->at(i + 3) + " " + kny->at(i + 3) * (-1) + " " + (-1));

			sw->WriteLine("BackPolygon2");
			sw->WriteLine("vertex: " + knx->at(i) + " " + kny->at(i) * (-1) + " " + (-1));
			sw->WriteLine("vertex: " + knx->at(i + 4) + " " + kny->at(i + 4) * (-1) + " " + (-1));
			sw->WriteLine("vertex: " + knx->at(i + 3) + " " + kny->at(i + 3) * (-1) + " " + (-1));
		}
		sw->Close();
	}
	// отрисовка сцены
	private: System::Void paintScene() {
		// StreamWriter^ sw_time = gcnew StreamWriter("timenger.txt", true);
		// auto timer = gcnew System::Diagnostics::Stopwatch();
		// timer->Start();
		processDots(custom_figure_edges, custom_figure_edges_copy);
		if (is_filled)
		{
			if (is_filled_slow_mo)
			{
				gr = gr_create_graphics;
				gr->Clear(backround_color);
				fill(custom_figure_edges_copy);
			}
			else
			{

				gr = gr_from_image;
				gr->Clear(backround_color);
				bm_data = bm->LockBits(Rectangle(0, 0, bmWidth, bmHeight), ImageLockMode::ReadWrite, PixelFormat::Format24bppRgb);
				scan0 = (unsigned char*)bm_data->Scan0.ToPointer();
				scan0_stride = bm_data->Stride;
				scan0_depth = bm->GetPixelFormatSize(bm_data->PixelFormat) / 8;
				fill(custom_figure_edges_copy);
				bm->UnlockBits(bm_data);
				pictureBox1->Refresh();
			}
		}
		else
		{
			gr = gr_from_image;
			gr->Clear(backround_color);
			bm_data = bm->LockBits(Rectangle(0, 0, bmWidth, bmHeight), ImageLockMode::ReadWrite, PixelFormat::Format24bppRgb);
			scan0 = (unsigned char*)bm_data->Scan0.ToPointer();
			if (scan0 != nullptr)
			{
				scan0_stride = bm_data->Stride;
				scan0_depth = bm->GetPixelFormatSize(bm_data->PixelFormat) / 8;
				draw(custom_figure_edges_copy);
			}
			bm->UnlockBits(bm_data);
			pictureBox1->Refresh();
		}
		// fix memory leak
		for (int i = 0; i < custom_figure_edges_copy->size(); i++) {
			vector<CustomPair> first_level = custom_figure_edges_copy->at(0);
			for (int j = 0; j < first_level.size(); j++) {
				first_level.at(j).second->clear();
			}
			first_level.clear();
		}
		// timer->Stop();
		// sw_time->WriteLine("reconstruction with " + iteration_count + " iterations takes " + timer->Elapsed.ToString("mm':'ss':'fff"));
		// sw_time->Close();
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		is_filled = !is_filled;
		if (!is_filled)
		{
			checkBox2->Checked = false;
		}
		if (!is_flat_filling)
		{
			paintScene();
		}
	}
	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		is_filled_slow_mo = !is_filled_slow_mo;
		if (is_filled_slow_mo && !is_filled)
		{
			is_filled = true;
			checkBox1->Checked = true;
		}
		else if (!is_flat_filling)
		{
			paintScene();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		colorDialog1->ShowDialog();
		button2->BackColor = colorDialog1->Color;
		edge_color->at(chosen_figure) = colorDialog1->Color.ToArgb();
		pen_custom_figure = gcnew Pen(Color::FromArgb(edge_color->at(chosen_figure)), 1);
		edge_solid_brush = gcnew SolidBrush(Color::FromArgb(edge_color->at(chosen_figure)));
		paintScene();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		colorDialog2->ShowDialog();
		button3->BackColor = colorDialog2->Color;
		backround_color = colorDialog2->Color;
		background_solid_brush = gcnew SolidBrush(backround_color);
		paintScene();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->ShowDialog();
		try
		{
			String^ fileName = openFileDialog1->FileName;
			StreamReader^ din = File::OpenText(fileName);
			String^ str;
			int count = 0;
			int currInd = 1;
			PointXYZ p1;
			PointXYZ p2;
			PointXYZ p3;
			vector<CustomPair> current_figure = vector<CustomPair>();
			while ((str = din->ReadLine()) != nullptr)
			{
				str = str->Trim();
				if (str->Length == 0)
				{
					continue;
				}
				auto StringArray = str->Split(' ');
				if (StringArray->Length == 4 && StringArray[0] == "vertex:")
				{
					if (currInd == 1)
					{
						auto c = System::Globalization::CultureInfo::CurrentCulture->ToString();
						auto b = gcnew System::Globalization::CultureInfo("en-US");
						float x = float::Parse(StringArray[1]);
						float y = float::Parse(StringArray[2]);
						float z = float::Parse(StringArray[3]);
						currInd++;
						p1 = PointXYZ(x, y, z);
					}
					else if (currInd == 2)
					{
						float x = float::Parse(StringArray[1]);
						float y = float::Parse(StringArray[2]);
						float z = float::Parse(StringArray[3]);
						currInd++;
						p2 = PointXYZ(x, y, z);
					}
					else if (currInd == 3)
					{
						float x = float::Parse(StringArray[1]);
						float y = float::Parse(StringArray[2]);
						float z = float::Parse(StringArray[3]);
						currInd = 1;
						count++;
						p3 = PointXYZ(x, y, z);
						current_figure.push_back(CustomPair(count, new vector<PointXYZ>{ p1, p2, p3 }));
					}
				}
			}
			custom_figure_edges->push_back(current_figure);
			x_angle->push_back(0);
			trackBar1->Value = 0;
			y_angle->push_back(0);
			trackBar2->Value = 0;
			z_angle->push_back(0);
			trackBar3->Value = 0;
			additional_offset_point->push_back(PointXYZ(0, 0, 0));
			trackBar4->Value = 0;
			trackBar5->Value = 0;
			trackBar6->Value = 0;
			size->push_back(DEFAULT_SIZE);
			trackBar7->Value = DEFAULT_SIZE;
			edge_color->push_back(default_edge_color.ToArgb());
			fill_edge_color->push_back(default_fill_edge_color.ToArgb());
			comboBox3->Items->Add(custom_figure_edges->size());
			comboBox3->SelectedIndex = custom_figure_edges->size() - 1;
		}
		catch (Exception^ ex)
		{
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (chosen_figure >= 0)
		{
			for (int i = 0; i < custom_figure_edges->at(chosen_figure).size(); i++)
			{
				custom_figure_edges->at(chosen_figure).at(i).second->clear();
			}
			custom_figure_edges->at(chosen_figure).clear();
			int search_index;
			search_index = 0;
			for (auto iterator = custom_figure_edges->begin(); iterator != custom_figure_edges->end(); ++iterator, ++search_index) {
				if (search_index == chosen_figure)
				{
					custom_figure_edges->erase(iterator);
					break;
				}
			}

			x_angle->erase(x_angle->begin() + chosen_figure);
			y_angle->erase(y_angle->begin() + chosen_figure);
			z_angle->erase(z_angle->begin() + chosen_figure);

			search_index = 0;
			for (auto iterator = additional_offset_point->begin(); iterator != additional_offset_point->end(); ++iterator, ++search_index) {
				if (search_index == chosen_figure)
				{
					additional_offset_point->erase(iterator);
					break;
				}
			}

			size->erase(size->begin() + chosen_figure);
			edge_color->erase(edge_color->begin() + chosen_figure);
			fill_edge_color->erase(fill_edge_color->begin() + chosen_figure);

			comboBox3->Items->RemoveAt(chosen_figure);
			paintScene();
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		colorDialog3->ShowDialog();
		button6->BackColor = colorDialog3->Color;
		fill_edge_color->at(chosen_figure) = colorDialog3->Color.ToArgb();
		fill_edge_solid_brush = gcnew SolidBrush(Color::FromArgb(fill_edge_color->at(chosen_figure)));
		paintScene();
	}
	private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		is_flat_filling = !is_flat_filling;
		if (is_flat_filling && !is_filled)
		{
			checkBox1->Checked = true;
		}

		if (is_flat_filling && is_filled_slow_mo)
		{
			checkBox2->Checked = false;
		}

		if (is_flat_filling)
		{
			paintScene();
		}
	}
	private: System::Void trackBar9_Scroll(System::Object^ sender, System::EventArgs^ e) {
		light_source->x = trackBar9->Value;
		paintScene();
	}
	private: System::Void trackBar10_Scroll(System::Object^ sender, System::EventArgs^ e) {
		light_source->y = trackBar10->Value;
		paintScene();
	}
	private: System::Void trackBar11_Scroll(System::Object^ sender, System::EventArgs^ e) {
		light_source->z = trackBar11->Value;
		paintScene();
	}
	private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox3->SelectedIndex >= 0)
		{
			chosen_figure = comboBox3->SelectedIndex;
			trackBar1->Value = x_angle->at(chosen_figure);
			trackBar2->Value = y_angle->at(chosen_figure);
			trackBar3->Value = z_angle->at(chosen_figure);
			additional_offset_point->push_back(PointXYZ(0, 0, 0));
			trackBar4->Value = additional_offset_point->at(chosen_figure).x;
			trackBar5->Value = additional_offset_point->at(chosen_figure).y;
			trackBar6->Value = additional_offset_point->at(chosen_figure).z;
			trackBar7->Value = size->at(chosen_figure);
			button2->BackColor = Color::FromArgb(edge_color->at(chosen_figure));
			button6->BackColor = Color::FromArgb(fill_edge_color->at(chosen_figure));
		}
	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
		{
			e->Handled = true;
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text->Equals("")) 
		{
			iteration_count = 0;
		}
		else 
		{
			iteration_count = int::Parse(textBox1->Text);
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (fractal == Fractal::CANTOR_SET) 
		{
			cantorSetImport();
		}
		else if (fractal == Fractal::PYTHAGORAS_TREE) 
		{
			pythagorasTreeImport();
		} else if (fractal == Fractal::MENGER_SPONGE) 
		{
			mengerSpongeImport();
		}
	}
	/*
	class PointXYZ
	{
	public:
	   float x, y, z, _1;
	   PointXYZ(float x, float y, float z)
	   {
		   this->x = x;
		   this->y = y;
		   this->z = z;
		   this->_1 = 1.0;
	   }
	   PointXYZ(float x, float y, float z, float _1)
	   {
		   this->x = x;
		   this->y = y;
		   this->z = z;
		   this->_1 = _1;
	   }
	   PointXYZ()
	   {
		   this->x = 0.0;
		   this->y = 0.0;
		   this->z = 0.0;
		   this->_1 = 0.0;
	   }
	};
	struct Ygreater
	{
	   bool operator()(PointXYZ l, PointXYZ r) const {
		   return l.y < r.y;
	   }
	};
	class CustomPair {
	public:
	   int first;
	   vector<PointXYZ>* second = new vector<PointXYZ>();
	   CustomPair() {
	   }
	   CustomPair(int first, vector<PointXYZ>* second) {
		   this->first = first;
		   this->second = second;
	   }
	};
	enum Direction { X, Y, Z };
	enum Fractal { CANTOR_SET, PYTHAGORAS_TREE, MENGER_SPONGE };
	*/
};
}
