#pragma once

namespace LabWork6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
    private: System::Windows::Forms::Label^  scalarProductLabel;
    protected: 

    private: System::Windows::Forms::Label^  collinearLabel;
    private: System::Windows::Forms::Label^  orthogonalLabel;
    private: System::Windows::Forms::Button^  cancelButton;




    protected: 

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
            this->scalarProductLabel = (gcnew System::Windows::Forms::Label());
            this->collinearLabel = (gcnew System::Windows::Forms::Label());
            this->orthogonalLabel = (gcnew System::Windows::Forms::Label());
            this->cancelButton = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel1->SuspendLayout();
            this->SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->ColumnCount = 1;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
                100)));
            this->tableLayoutPanel1->Controls->Add(this->scalarProductLabel, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->collinearLabel, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->orthogonalLabel, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->cancelButton, 0, 3);
            this->tableLayoutPanel1->Location = System::Drawing::Point(3, 0);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 4;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(282, 129);
            this->tableLayoutPanel1->TabIndex = 0;
            // 
            // scalarProductLabel
            // 
            this->scalarProductLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
            this->scalarProductLabel->AutoSize = true;
            this->scalarProductLabel->Location = System::Drawing::Point(10, 8);
            this->scalarProductLabel->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
            this->scalarProductLabel->Name = L"scalarProductLabel";
            this->scalarProductLabel->Size = System::Drawing::Size(0, 13);
            this->scalarProductLabel->TabIndex = 0;
            // 
            // collinearLabel
            // 
            this->collinearLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
            this->collinearLabel->AutoSize = true;
            this->collinearLabel->Location = System::Drawing::Point(10, 38);
            this->collinearLabel->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
            this->collinearLabel->Name = L"collinearLabel";
            this->collinearLabel->Size = System::Drawing::Size(0, 13);
            this->collinearLabel->TabIndex = 1;
            // 
            // orthogonalLabel
            // 
            this->orthogonalLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
            this->orthogonalLabel->AutoSize = true;
            this->orthogonalLabel->Location = System::Drawing::Point(10, 68);
            this->orthogonalLabel->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
            this->orthogonalLabel->Name = L"orthogonalLabel";
            this->orthogonalLabel->Size = System::Drawing::Size(0, 13);
            this->orthogonalLabel->TabIndex = 2;
            // 
            // cancelButton
            // 
            this->cancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->cancelButton->Location = System::Drawing::Point(104, 102);
            this->cancelButton->Name = L"cancelButton";
            this->cancelButton->Size = System::Drawing::Size(73, 25);
            this->cancelButton->TabIndex = 3;
            this->cancelButton->Text = L"Close";
            this->cancelButton->UseVisualStyleBackColor = true;
            this->cancelButton->Click += gcnew System::EventHandler(this, &Form2::closeButtonClick);
            // 
            // Form2
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(290, 141);
            this->Controls->Add(this->tableLayoutPanel1);
            this->MaximumSize = System::Drawing::Size(306, 179);
            this->MinimumSize = System::Drawing::Size(306, 179);
            this->Name = L"Form2";
            this->Text = L"Form2";
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
        public: void setScalarProduct(int product)
                {
                    scalarProductLabel->Text = "Scalar product: " + product;
                }
                void setCollinear(bool collinear)
                {
                    if(collinear)
                        collinearLabel->Text = "Vectors are collinear";
                    else
                        collinearLabel->Text = "Vectors are not collinear";
                }
                void setOrthogonal(bool orthogonal)
                {
                    if(orthogonal)
                        orthogonalLabel->Text = "Vectors are orthogonal";
                    else
                        orthogonalLabel->Text = "Vectors are not orthogonal";
                }
private: System::Void closeButtonClick(System::Object^  sender, System::EventArgs^  e) {
             this -> Close();
         }
};
}
