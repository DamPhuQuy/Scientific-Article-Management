#include "articleform.h"
#include "ui_articleform.h"

ArticleForm::ArticleForm(RepositoryManager& repo, QWidget *parent)
    : QWidget(parent)
    , repo(repo)
    , ui(new Ui::ArticleForm)
{
    ui->setupUi(this);
}

ArticleForm::~ArticleForm()
{
    delete ui;
}

void ArticleForm::on_newArticleBtn_clicked()
{
    emit openArticleInputDialog();
}

void ArticleForm::on_statsBtn_clicked()
{
    emit openArtilceStatisticsDialog();
}


void ArticleForm::on_updateArtticleBtn_clicked()
{
    emit openArticleUpdateArticDialog();
}


void ArticleForm::on_RemoveArticleBtn_clicked()
{
    emit openArticleRemoveArticleDialog();
}


void ArticleForm::on_searchBtn_clicked()
{

}

