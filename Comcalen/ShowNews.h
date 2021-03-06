#pragma once

#include <QDialog>
#include "ui_ShowNews.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QTableWidget>
#include <vector>
#include "Employer.h"
using namespace std;
class ShowNews : public QDialog
{
	/**
	* @class ShowNews inheriting from QDialog
	*/
	Q_OBJECT

public:
	ShowNews(Employer* employer, int news_size, QDialog *parent = Q_NULLPTR);
	~ShowNews();

private:
	Employer* employer;
	Ui::ShowNews ui;
private slots:
	void remove_news(int row, int column); //! remove news with double clik
};
