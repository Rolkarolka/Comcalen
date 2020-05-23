#pragma once

#include <QDialog>
#include "ui_ShowNews.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QList>
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
	void news_list();
};
