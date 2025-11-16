#ifndef IMPORTDIALOG_H
#define IMPORTDIALOG_H

#include <QDialog>
#include <QString>

// Forward declaration của lớp UI
namespace Ui {
class ImportDialog;
}

class ImportDialog : public QDialog
{
    Q_OBJECT // Bắt buộc cho các lớp có signals/slots

public:
    explicit ImportDialog(QWidget *parent = nullptr);
    ~ImportDialog();

signals:
    // Tín hiệu này được phát ra khi người dùng chọn "Import from JSON"
    // Nó mang theo đường dẫn 2 file đã chọn
    void importFromJsonRequested(const QString &articleFile, const QString &authorFile);

    // Tín hiệu này được phát ra khi người dùng chọn "Import Auto"
    void importAutoRequested();

private slots:
    // Slot nội bộ để xử lý khi nút "Import JSON" được nhấn
    void onImportJsonClicked();

    // Slot nội bộ để xử lý khi nút "Import Auto" được nhấn
    void onImportAutoClicked();

private:
    Ui::ImportDialog *ui; // Con trỏ tới các thành phần UI
};

#endif // IMPORTDIALOG_H