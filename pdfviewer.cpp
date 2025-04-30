#include "pdfviewer.h"
#include "ui_pdfviewer.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>
#include <QDir>

pdfviewer::pdfviewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pdfviewer)
{
    ui->setupUi(this);

    //Сцена для PDF
    m_scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(m_scene);

    //слотики
    connect(ui->actionOpen, &QAction::triggered, this, &pdfviewer::on_actionOpen_triggered);
    connect(ui->actionExport, &QAction::triggered, this, &pdfviewer::on_actionExport_triggered);
    connect(ui->listWidget, &QListWidget::currentRowChanged, this, &pdfviewer::on_listWidget_currentRowChanged);

    setupPdfView();
}

pdfviewer::~pdfviewer() {
    cleanupDocument(); // очистка документа. нужна ли???
    delete ui;
}

void pdfviewer::on_actionOpen_triggered() {
    //ну тут всё ясно 5 класс 2 четверть
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Open PDF",
                                                    "",
                                                    "PDF Files (*.pdf)");
    if (!filePath.isEmpty()) {
        cleanupDocument();
        loadPdfDocument(filePath);
    }
}


void pdfviewer::on_actionExport_triggered() {
    //Потом, если нужен просмотр страницы. Чёт лень
}


void pdfviewer::on_listWidget_currentRowChanged(int currentRow) {
    displayPdfPage(currentRow);
}

void pdfviewer::loadPdfDocument(const QString &filePath) {
    // Poppler::Document::load возвращает unique_ptr<Poppler::Document> спасибо ИИ. Я с указателями умными не дружу.
    m_pdfDocument = Poppler::Document::load(filePath);

    // Проверка успеха загрузки документа
    if (!m_pdfDocument || m_pdfDocument->isLocked()) {
        QMessageBox::critical(this, "Error", "Failed to load PDF document.");
        m_pdfDocument.reset();
        return;
    }

    // Получаем количество страниц и заполняем список
    int pageCount = m_pdfDocument->numPages();
    for (int i = 0; i < pageCount; ++i) {
        ui->listWidget->addItem(QString("Page %1").arg(i + 1));
    }

    displayPdfPage(0); // показываем первую страницу
}

// Отображение конкретной страницы по её номеру
void pdfviewer::displayPdfPage(int pageIndex) {
    // Проверка правильные ли данные получается так
    if (!m_pdfDocument || pageIndex < 0 || pageIndex >= m_pdfDocument->numPages()) {
        return;
    }

    m_scene->clear();

    // Получаем нужную страницу через unique_ptr СПАСИБО ИИ ГОСПОДИ ХРАНИ ГОСПОДЬ Я НЕ ЗНАЮ УКАЗАТЕЛИ
    std::unique_ptr<Poppler::Page> page(m_pdfDocument->page(pageIndex));
    if (!page) {
        return;
    }

     // Рендерим страницу в QImage. Можно увеличить, будет лучше качество.
    QImage image = page->renderToImage(72, 72, -1, -1, Poppler::Page::Rotate0);
    QPixmap pixmap = QPixmap::fromImage(image);

    //ну тут всё ясно
    m_scene->addPixmap(pixmap);
    m_scene->update();

    // Получаем текст страницы и выводим в ТекстБрозер
    QString text = page->text(QRect()); //QRect() - весь текст на страничке
    ui->textBrowser->setPlainText(text);

    //Пожилой статус бар
    ui->statusbar->showMessage(QString("Page %1").arg(pageIndex + 1));
}

void pdfviewer::cleanupDocument() {
    m_pdfDocument.reset(); // автоматическое освобождение памяти. Господи храни ИИ
    m_scene->clear();
    ui->listWidget->clear();
    ui->textBrowser->clear();
}

void pdfviewer::setupPdfView() {
    //ДОП НАСТРОЙКИ???????
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag); // Можно мышкой тудунь тудунь
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate); // я хз без этого плохо работает. не трогать!!!

    //нагуглил сглаживание. НЕ ТРОГАТЬ!!!!!
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform);
}
