#pragma once

#include <QDialog>
#include "ui_ShowNews.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <vector>
#include "Employer.h"
using namespace std;
class ShowNews : public QDialog
{
	Q_OBJECT

public:
	ShowNews(Employer* employer, int news_size, QDialog *parent = Q_NULLPTR);
	~ShowNews();

private:
	Employer* employer;
	Ui::ShowNews ui;
	QTableWidget* table;

	void news_list();
};
