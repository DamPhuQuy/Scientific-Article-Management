#include "listofauthorsdialog.h"
#include "ui_listofauthorsdialog.h"
#include "src/components/dialogs/author/authordetailsdialog.h"

ListOfAuthorsDialog::ListOfAuthorsDialog(RepositoryManager& repo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ListOfAuthorsDialog)
    , repo(repo)
{
    ui->setupUi(this);

    // init model
    model = new QStandardItemModel(this);
    ui->listViewAuthors->setModel(model);

    ui->listViewAuthors->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listViewAuthors->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listViewAuthors->setSelectionBehavior(QAbstractItemView::SelectRows);

    // init data
    initData();
    loadAuthorsToView();
    loadCountriesToChoose();
    loadFieldsToChoose();

    connect(ui->lineEditSearch, &QLineEdit::textChanged,
            this, &ListOfAuthorsDialog::on_lineEditSearch_textChanged);

    connect(ui->comboCountry, &QComboBox::currentTextChanged,
            this, &ListOfAuthorsDialog::on_comboCountry_currentTextChanged);

    connect(ui->comboField,   &QComboBox::currentTextChanged,
            this, &ListOfAuthorsDialog::on_comboField_currentTextChanged);

    connect(ui->btnApplyFilter, &QPushButton::clicked,
            this, &ListOfAuthorsDialog::on_btnApplyFilter_clicked);

    connect(ui->lineEditSearch, &QLineEdit::returnPressed,
            ui->btnApplyFilter, &QPushButton::click); // search enter = filter click
}

ListOfAuthorsDialog::~ListOfAuthorsDialog()
{
    delete ui;
}

void ListOfAuthorsDialog::on_btnClose_clicked()
{
    reject();
}

void ListOfAuthorsDialog::on_okBtn_clicked()
{
    accept();
}

vector<string> ListOfAuthorsDialog::getSelectedAuthorIds() const {
    vector<string> selectedIds;
    auto selectedRows = ui->listViewAuthors->selectionModel()->selectedRows();

    for (const QModelIndex &index : selectedRows) {
        string id = index.data(Qt::UserRole).toString().toStdString();
        selectedIds.push_back(id);
    }
    return selectedIds;
}


void ListOfAuthorsDialog::initData() {
    authorList = repo.getAuthors().getCopyAsVector();
}

void ListOfAuthorsDialog::loadCountriesToChoose() {
    for (const auto& country : authorList) {
        ui->comboCountry->addItem(QString::fromStdString(country.getCountry()));
    }
}

void ListOfAuthorsDialog::loadFieldsToChoose() {
    for (const auto& field : authorList) {
        ui->comboField->addItem(QString::fromStdString(field.getFieldOfStudy()));
    }
}

void ListOfAuthorsDialog::loadAuthorsToView() {
    model->clear();

    for (const auto& author : authorList) {
        QStandardItem *item = new QStandardItem(QString::fromStdString(author.getFullName()));

        // SELECT BOX
        item->setCheckable(true); // Hiển thị checkbox bên cạnh text
        item->setCheckState(Qt::Unchecked); // Mặc định không chọn

        // Lưu ID vào UserRole để sau này lấy lại
        item->setData(QString::fromStdString(author.getId()), Qt::UserRole);

        model->appendRow(item);
    }

    if (!preselectedIds.empty()) {
        setCheckedAuthorIds({});
    }
}

void ListOfAuthorsDialog::on_listViewAuthors_doubleClicked(const QModelIndex &index)
{
    string authorId = index.data(Qt::UserRole).toString().toStdString();

    Author selectedAuthor;
    bool found = false;
    for(const auto& auth : authorList) {
        if(auth.getId() == authorId) {
            selectedAuthor = auth;
            found = true;
            break;
        }
    }

    if (!found) return;

    AuthorDetailsDialog detailDlg(repo, this);

    detailDlg.setAuthorInfo(
        QString::fromStdString(selectedAuthor.getId()),
        QString::fromStdString(selectedAuthor.getFullName()),
        QString::fromStdString(selectedAuthor.getCountry()),
        QString::fromStdString(selectedAuthor.getFieldOfStudy()),
        selectedAuthor.getTotalPublications()
    );

    detailDlg.exec();
}

void ListOfAuthorsDialog::setCheckedAuthorIds(const vector<Author> &authors)
{
    preselectedIds.clear();
    for (const auto& author : authors) {
        preselectedIds.insert(author.getId());
    }

    // Áp dụng lại trạng thái chọn nếu model đã load
    if (model->rowCount() > 0) {
        QItemSelectionModel *selModel = ui->listViewAuthors->selectionModel();
        for (int row = 0; row < model->rowCount(); ++row) {
            QModelIndex idx = model->index(row, 0);
            string id = idx.data(Qt::UserRole).toString().toStdString();
            if (preselectedIds.count(id)) {
                selModel->select(idx, QItemSelectionModel::Select | QItemSelectionModel::Rows);
            }
        }
    }
}

void ListOfAuthorsDialog::on_lineEditSearch_textChanged(const QString &text)
{
    filterText = text.trimmed();
    applyAllFilters();
}

void ListOfAuthorsDialog::on_comboCountry_currentTextChanged(const QString &text)
{
    filterCountry = (text == "All Countries") ? QString() : text;
    applyAllFilters();
}

void ListOfAuthorsDialog::on_comboField_currentTextChanged(const QString &text)
{
    filterField = (text == "All Fields") ? QString() : text;
    applyAllFilters();
}

bool ListOfAuthorsDialog::passesAllFilters(int row) const
{
    // fetch item and id
    QStandardItem *item = model->item(row, 0);
    if (item == nullptr) {
        return false; // no data
    }

    // fetch hidden id
    QString currentId = item->data(Qt::UserRole).toString();

    Author foundAuthor;
    bool isFound = false;

    for (const Author &a : authorList) {
        if (QString::fromStdString(a.getId()) == currentId) {
            foundAuthor = a;
            isFound = true;
            break;
        }
    }

    if (!isFound) {
        return false;
    }

    // data to filter
    QString name    = QString::fromStdString(foundAuthor.getFullName());
    QString country = QString::fromStdString(foundAuthor.getCountry());
    QString field   = QString::fromStdString(foundAuthor.getFieldOfStudy());

    // line search
    if (!filterText.isEmpty()) {
        if (!name.contains(filterText, Qt::CaseInsensitive)) {
            return false;
        }
    }

    // country
    if (!filterCountry.isEmpty() && filterCountry != "All Countries") {
        if (country != filterCountry) {
            return false;
        }
    }

    // field
    if (!filterField.isEmpty() && filterField != "All Fields") {
        if (field != filterField) {
            return false;
        }
    }

    return true;
}

void ListOfAuthorsDialog::applyAllFilters()
{
    // each row is each author
    // hide author which is not statisfied
    for (int row = 0; row < model->rowCount(); ++row) {
        bool visible = passesAllFilters(row);
        ui->listViewAuthors->setRowHidden(row, !visible);
    }
}


void ListOfAuthorsDialog::on_btnApplyFilter_clicked()
{
    applyAllFilters();
}

