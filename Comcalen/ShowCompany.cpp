#include "ShowCompany.h"

ShowCompany::ShowCompany(Company* company, QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    connect(ui.return_mw, SIGNAL(released()), this, SLOT(reject()));
    QVBoxLayout* layout = new QVBoxLayout(this);
    vector<tuple<string, string>> log_info = company->get_log_info();
    int company_members = company->get_number_of_staff() + company->get_number_of_managment();
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

ShowCompany::~ShowCompany()
{
#ifdef _DEBUG
    qDebug() << "ShowCompany class removed.\n";
#endif
}
