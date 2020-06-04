#include "ShowNews.h"

ShowNews::ShowNews(Employer *current_employer, int news_size, QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    employer = current_employer;
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui.table->setRowCount(news_size);
    ui.table->setColumnCount(1);


    for (int row = 0; row < news_size; row++)
    {
        string news = current_employer->show_news(row);
        if (news != "")
        {
            QTableWidgetItem* newItem = new QTableWidgetItem(QString::fromStdString(news));
            ui.table->setItem(row, 0, newItem);
        }
    }
    connect(ui.table, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(remove_news(int, int)));
    ui.table->setHorizontalHeaderLabels(QStringList() << "News");
    ui.table->horizontalHeader()->setStretchLastSection(true);
    connect(ui.return_mw, SIGNAL(released()), this, SLOT(reject()));
#ifdef _DEBUG
    qDebug() << "ShowNews class created.\n";
#endif
}

void ShowNews::remove_news(int row, int column)
{
    ui.table->removeRow(row);
    employer->delete_news(row);
}


ShowNews::~ShowNews()
{
#ifdef _DEBUG
    qDebug() << "ShowNews class removed.\n";
#endif
}
