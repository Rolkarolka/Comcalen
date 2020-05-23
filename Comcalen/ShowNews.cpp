#include "ShowNews.h"

ShowNews::ShowNews(Employer *current_employer, int news_size, QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    employer = current_employer;
	connect(ui.return_mw, SIGNAL(released()), this, SLOT(reject()));
    QVBoxLayout* layout = new QVBoxLayout(this);
    string news = employer->show_news(0);
    int index = 0;
    while (news != "") {
        QPushButton* button = new QPushButton();
        button->setText(QString::fromStdString(news));
        layout->addWidget(button);
        index++;
        news = employer->show_news(index);
    }
    ui.scrollContents->setLayout(layout);
}

ShowNews::~ShowNews()
{
}
