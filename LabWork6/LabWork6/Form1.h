#pragma once
#include "vectorutils.h"
#include "Form2.h"

namespace LabWork6 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// —водка дл€ Form1
    /// </summary>
    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
            //
            //TODO: добавьте код конструктора
            //
        }

    protected:
        /// <summary>
        /// ќсвободить все используемые ресурсы.
        /// </summary>
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
    protected: 
    private: System::Windows::Forms::TextBox^  vector1TextBox;
    private: System::Windows::Forms::Button^  okButton;

    private: System::Windows::Forms::TextBox^  vector2TextBox;

    private: Form2 ^resultForm;

    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Label^  label3;

    private:
        /// <summary>
        /// “ребуетс€ переменна€ конструктора.
        /// </summary>
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->vector1TextBox = (gcnew System::Windows::Forms::TextBox());
            this->vector2TextBox = (gcnew System::Windows::Forms::TextBox());
            this->okButton = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel1->SuspendLayout();
            this->SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
                | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel1->ColumnCount = 2;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
                50)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
                50)));
            this->tableLayoutPanel1->Controls->Add(this->vector1TextBox, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->vector2TextBox, 1, 1);
            this->tableLayoutPanel1->Controls->Add(this->okButton, 1, 2);
            this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->label3, 0, 2);
            this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel1->MaximumSize = System::Drawing::Size(450, 106);
            this->tableLayoutPanel1->MinimumSize = System::Drawing::Size(286, 106);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 3;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(286, 106);
            this->tableLayoutPanel1->TabIndex = 0;
            // 
            // vector1TextBox
            // 
            this->vector1TextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->vector1TextBox->Location = System::Drawing::Point(146, 7);
            this->vector1TextBox->Name = L"vector1TextBox";
            this->vector1TextBox->Size = System::Drawing::Size(137, 20);
            this->vector1TextBox->TabIndex = 0;
            this->vector1TextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::vectorTextBox_KeyPress);
            // 
            // vector2TextBox
            // 
            this->vector2TextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->vector2TextBox->Location = System::Drawing::Point(146, 42);
            this->vector2TextBox->Name = L"vector2TextBox";
            this->vector2TextBox->Size = System::Drawing::Size(137, 20);
            this->vector2TextBox->TabIndex = 2;
            this->vector2TextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::vectorTextBox_KeyPress);
            // 
            // okButton
            // 
            this->okButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->okButton->Location = System::Drawing::Point(208, 74);
            this->okButton->Margin = System::Windows::Forms::Padding(3, 3, 3, 10);
            this->okButton->Name = L"okButton";
            this->okButton->Size = System::Drawing::Size(75, 22);
            this->okButton->TabIndex = 1;
            this->okButton->Text = L"OK";
            this->okButton->UseVisualStyleBackColor = true;
            this->okButton->Click += gcnew System::EventHandler(this, &Form1::okButtonClick);
            // 
            // label1
            // 
            this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(86, 11);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(54, 13);
            this->label1->TabIndex = 3;
            this->label1->Text = L"1st vector";
            // 
            // label2
            // 
            this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(82, 46);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(58, 13);
            this->label2->TabIndex = 4;
            this->label2->Text = L"2nd vector";
            // 
            // label3
            // 
            this->label3->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->label3->AutoSize = true;
            this->label3->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->label3->Location = System::Drawing::Point(6, 70);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(131, 26);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Enter vectors coordinates delimeted by space";
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(294, 106);
            this->Controls->Add(this->tableLayoutPanel1);
            this->MaximumSize = System::Drawing::Size(460, 144);
            this->MinimumSize = System::Drawing::Size(310, 144);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System :: Void okButtonClick(System::Object^  sender, System::EventArgs^  e) {

                 if(vector1TextBox->Text->Length == 0 || vector2TextBox->Text->Length == 0)
                 {
                     MessageBox::Show("Incomplete data were entered!","Error",MessageBoxButtons::OK,MessageBoxIcon::Error);
                     return;
                 }

                 array<Char>^ space=gcnew array<Char> (1);
                 space[0]=' ';
                 array<String^>^ elements1 = vector1TextBox->Text->Trim()->Split(space);
                 array<String^>^ elements2 = vector2TextBox->Text->Trim()->Split(space);

                 if(elements1->Length != elements2->Length)
                 {
                     MessageBox::Show("Vector dimensions doesn't match!","Error",MessageBoxButtons::OK,MessageBoxIcon::Error);
                     return;
                 }

                 vector<int> vector1(elements1->Length), vector2(elements2->Length);
                 for(int i = 0; i < elements1->Length; i++)
                 {
                     vector1.push_back(Convert::ToInt32(elements1[i]));
                     vector2.push_back(Convert::ToInt32(elements2[i]));
                 }

                 if(!resultForm || resultForm -> IsDisposed)
                 {
                     resultForm = gcnew Form2();
                     resultForm -> Show();
                 }

                 resultForm -> setScalarProduct(scalarProduct(vector1,vector2));
                 resultForm -> setCollinear(areCollinear(vector1,vector2));
                 resultForm -> setOrthogonal(areOrthogonal(vector1,vector2));
             }
    private: System::Void vectorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

                 if( ((e->KeyChar>='0') && (e->KeyChar<='9')) || (e->KeyChar==' ') || (e->KeyChar=='-') || ( e->KeyChar == 8) ) 
                     return;
                 if(e->KeyChar == 13)
                     okButtonClick(sender,e);

                 e->Handled = true;

             }
    };
}

