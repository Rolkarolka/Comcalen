#include "ShowCompany.h"

ShowCompany::ShowCompany(Company* ncompany, QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    company = ncompany;
    connect(ui.return_mw, SIGNAL(released()), this, SLOT(reject()));
    QVBoxLayout* layout = new QVBoxLayout;
    connect(ui.save_file, SIGNAL(clicked()), this, SLOT(save_button_pressed()));
    vector<tuple<string, string>> log_info = company->get_log_info();
    company_members = company->get_number_of_staff() + company->get_number_of_managment();
    if (company_members != 0)
    {
        for (const auto& i : log_info)
        {
            string text = get<1>(i) + "\t" + get<0>(i);
            QPushButton* button = new QPushButton();
            button->setText(QString::fromStdString(text));
            layout->addWidget(button);
        }
    }
    ui.scrollContents->setLayout(layout);
#ifdef _DEBUG
    qDebug() << "ShowCompany class created.\n";
#endif
}

void ShowCompany::save_button_pressed()
{
    fstream file;
    file.open("ID.txt", ios::out);
    vector<tuple<string, string>> log_info = company->get_log_info();
    if (company_members != 0)
    {
        for (const auto& i : log_info)
        {
            string text = get<1>(i) + "\t" + get<0>(i) + "\n";
            file << text;
        }
    }
    file.close();
    ui.save_file->setText(QString::fromStdString("Saved!"));
}


ShowCompany::~ShowCompany()
{
#ifdef _DEBUG
    qDebug() << "ShowCompany class removed.\n";
#endif
}
