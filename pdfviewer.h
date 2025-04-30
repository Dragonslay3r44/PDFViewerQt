#ifndef PDFVIEWER_H
#define PDFVIEWER_H

#include <QMainWindow>
#include <poppler/qt6/poppler-qt6.h>
#include <QGraphicsScene>
#include <memory> //умные указатели. я не шарю от слова сооооовсем. ИИ в помощь

QT_BEGIN_NAMESPACE
namespace Ui {
class pdfviewer;
}
QT_END_NAMESPACE

class pdfviewer : public QMainWindow
{
    Q_OBJECT

public:
    pdfviewer(QWidget *parent = nullptr);
    ~pdfviewer();

private slots:
    void on_actionOpen_triggered();
    void on_actionExport_triggered();
    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::pdfviewer *ui;
    QGraphicsScene *m_scene;
    std::unique_ptr<Poppler::Document> m_pdfDocument;

    void loadPdfDocument(const QString &filePath);
    void displayPdfPage(int pageIndex);
    void cleanupDocument();
    void setupPdfView();
};
#endif // PDFVIEWER_H
