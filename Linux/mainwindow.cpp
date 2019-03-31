#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QColorDialog>
#include <QComboBox>
#include <QFontComboBox>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDatabase>
#include <QMenu>
#include <QMenuBar>
#include <QTextCodec>
#include <QTextEdit>
#include <QStatusBar>
#include <QToolBar>
#include <QTextCursor>
#include <QTextDocumentWriter>
#include <QTextList>
#include <QtDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QMimeData>
#include <QTextEdit>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif
#include <QPrinter>
#if QT_CONFIG(printpreviewdialog)
#include <QPrintPreviewDialog>
#endif
#endif
#endif

#include <QWizardPage>
#include "highlighter.h"
#include "dialog.h"

#ifdef Q_OS_MAC
const QString rsrcPath = ":/images/mac";
#else
const QString rsrcPath = ":/images/win";
#endif
#include <QtWidgets>

#include "mainwindow.h"

#ifdef Q_OS_MACOS
  // Use dark text on light background on macOS, also in dark mode.
  QPalette pal = textEdit->palette();
  pal.setColor(QPalette::Base, QColor(Qt::white));
  pal.setColor(QPalette::Text, QColor(Qt::black));
  textEdit->setPalette(pal);
#endif
#ifdef Q_OS_WIN
  // Use dark text on light background on macOS, also in dark mode.
  QPalette pal = textEdit->palette();
  pal.setColor(QPalette::Base, QColor(Qt::white));
  pal.setColor(QPalette::Text, QColor(Qt::black));
  textEdit->setPalette(pal);
#endif

  MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(editor);
    setWindowTitle(tr("Rings CE - Rings Community Edition"));


    setToolButtonStyle(Qt::ToolButtonFollowStyle);

  #ifdef Q_OS_OSX
    setUnifiedTitleAndToolBarOnMac(true);
#endif
    setWindowTitle(QCoreApplication::applicationName());

   /*editor = new QTextEdit(this);
    connect(textEdit, &QTextEdit::currentCharFormatChanged,
            this, &editor::currentCharFormatChanged);
    connect(textEdit, &QTextEdit::cursorPositionChanged,
            this, &editor::cursorPositionChanged);
    setCentralWidget(editor);
*/
    setToolButtonStyle(Qt::ToolButtonFollowStyle);
    {
        QMenu *settingsMenu = menuBar() -> addMenu(tr("Settings"));
        settingsMenu->addAction(tr("Settings"), this, &MainWindow::about);
        //settingsMenu->addAction(tr("Settings")), this, &QApplication::);
        settingsMenu -> addAction(tr("Update"), this, &MainWindow::about);
        QMenu *buildMenu = menuBar() -> addMenu(tr("Build"));
        buildMenu->addAction(tr("Build"), this, &MainWindow::about);
        buildMenu->addAction(tr("Build All"), this, &QApplication::aboutQt);
        QMenu *analyzeMenu = menuBar() -> addMenu(tr("Analyze"));
        analyzeMenu->addAction(tr("Analyze"), this, &MainWindow::about);
        //analyzeMenu->addAction(tr("Profiling"), this, &QApplication::aboutQt);
        QMenu *toolsMenu = menuBar() -> addMenu(tr("Tools"));
        toolsMenu->addAction(tr("Tools"), this, &MainWindow::about);
        toolsMenu->addAction(tr("Plugins"), this, &QApplication::aboutQt);
        QMenu *helpMenu = menuBar()->addMenu(tr("Help"));
        helpMenu->addAction(tr("About Tools"), this, &MainWindow::about);
        helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);


    }

    QFont textFont("Helvetica");
    textFont.setStyleHint(QFont::SansSerif);
    editor->setFont(textFont);
    fontChanged(editor->font());
    colorChanged(editor->textColor());
    alignmentChanged(editor->alignment());

    connect(editor->document(), &QTextDocument::modificationChanged,
            actionSave, &QAction::setEnabled);
    connect(editor->document(), &QTextDocument::modificationChanged,
            this, &QWidget::setWindowModified);
    connect(editor->document(), &QTextDocument::undoAvailable,
            actionUndo, &QAction::setEnabled);
    connect(editor->document(), &QTextDocument::redoAvailable,
            actionRedo, &QAction::setEnabled);

    setWindowModified(editor->document()->isModified());
    actionSave->setEnabled(editor->document()->isModified());
    actionUndo->setEnabled(editor->document()->isUndoAvailable());
    actionRedo->setEnabled(editor->document()->isRedoAvailable());

#ifdef Q_OS_MACOS
    // Use dark text on light background on macOS, also in dark mode.
    QPalette pal = textEdit->palette();
    pal.setColor(QPalette::Base, QColor(Qt::white));
    pal.setColor(QPalette::Text, QColor(Qt::black));
    textEdit->setPalette(pal);
#endif
#ifdef Q_OS_WIN
    // Use dark text on light background on macOS, also in dark mode.
    QPalette pal = textEdit->palette();
    pal.setColor(QPalette::Base, QColor(Qt::white));
    pal.setColor(QPalette::Text, QColor(Qt::black));
    textEdit->setPalette(pal);
#endif
#ifdef Q_OS_LINUX
    // Use dark text on light background on macOS, also in dark mode.
    QPalette pal = editor->palette();
    pal.setColor(QPalette::Base, QColor(Qt::white));
    pal.setColor(QPalette::Text, QColor(Qt::black));
    editor->setPalette(pal);
#endif


}

void MainWindow::closeEvent(QCloseEvent *e)
{
      if (maybeSave())
          e->accept();
      else
          e->ignore();
}


void MainWindow::about()
{
    QMessageBox::about(this, tr("About Syntax Highlighter"),
                tr("<p>The <b>Syntax Highlighter</b> example shows how " \
                   "to perform simple syntax highlighting by subclassing " \
                   "the QSyntaxHighlighter class and describing " \
                   "highlighting rules using regular expressions.</p>"));
}

void MainWindow::LunarAbout()
{
    QMessageBox::about(this, tr("About Lunar CE - Lunar Community Edition"),
                tr("<p>The <b>Lunar CE</b> shows how " \
                   "to perform IDE for projects " \
                   "</p>"));
}

void MainWindow::newFile()
{
    editor->clear();
}

void MainWindow::openFile(const QString &path)
{
    QString fileName = path;

    if (fileName.isNull())
        fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "C++ Files (*.cpp *.h)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text))
            editor->setPlainText(file.readAll());
    }
}

// View Mode


void MainWindow::setupFileMenu()
{
    QMenu *fileMenu = new QMenu(tr("&File"), this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(tr("&New"), this, SLOT(newFile()), QKeySequence::New);
    fileMenu->addAction(tr("&Open..."), this, SLOT(openFile()), QKeySequence::Open);
    fileMenu->addAction(tr("E&xit"), qApp, SLOT(quit()), QKeySequence::Quit);
}




bool MainWindow::maybeSave()
{
if (!editor->document()->isModified())
    return true;

const QMessageBox::StandardButton ret =
    QMessageBox::warning(this, QCoreApplication::applicationName(),
                         tr("The document has been modified.\n"
                            "Do you want to save your changes?"),
                         QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
if (ret == QMessageBox::Save)
    return fileSave();
else if (ret == QMessageBox::Cancel)
    return false;
return true;
}

/*void MainWindow::fileOpen()
{
QFileDialog fileDialog(this, tr("Open File..."));
fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
fileDialog.setFileMode(QFileDialog::ExistingFile);
fileDialog.setMimeTypeFilters(QStringList() << "text/html" << "text/plain" << "text/css" << "text/c");
if (fileDialog.exec() != QDialog::Accepted)
    return;
const QString fn = fileDialog.selectedFiles().first();
if (load(fn))
    statusBar()->showMessage(tr("Opened \"%1\"").arg(QDir::toNativeSeparators(fn)));
else
    statusBar()->showMessage(tr("Could not open \"%1\"").arg(QDir::toNativeSeparators(fn)));
}*/

/*bool MainWindow::fileSave()
{
if (fileName.isEmpty())
    return fileSaveAs();
if (fileName.startsWith(QStringLiteral(":/")))
    return fileSaveAs();

QTextDocumentWriter writer(fileName);
//bool success = writer.write(textEdit->document());
bool success = writer.write(editor->document());
if (success) {
    editor->document()->setModified(false);
    statusBar()->showMessage(tr("Wrote \"%1\"").arg(QDir::toNativeSeparators(fileName)));
} else {
    statusBar()->showMessage(tr("Could not write to file \"%1\"")
                             .arg(QDir::toNativeSeparators(fileName)));
}
return success;
}*/

/*bool MainWindow::fileSaveAs()
{
QFileDialog fileDialog(this, tr("Save as..."));
fileDialog.setAcceptMode(QFileDialog::AcceptSave);
QStringList mimeTypes;
mimeTypes << "application/vnd.oasis.opendocument.text" << "text/html" << "text/plain"
          << "text/c" << "text/cpp" << "text/py" << "text/h" << "text/pas" << "text/hpp" << "text/cxx" <<
             "text/php" << "text/js" << "text/bas" << "text/css" << "text/cs" << "text/ws" << "text/ada"
          << "text/forth" << "text/vs" << "text/perl";
fileDialog.setMimeTypeFilters(mimeTypes);
fileDialog.setDefaultSuffix("odt");
if (fileDialog.exec() != QDialog::Accepted)
    return false;
const QString fn = fileDialog.selectedFiles().first();
setCurrentFileName(fn);
return fileSave();
}*/

void MainWindow::filePrint()
{
#if QT_CONFIG(printdialog)
QPrinter printer(QPrinter::HighResolution);
QPrintDialog *dlg = new QPrintDialog(&printer, this);
if (editor->textCursor().hasSelection())
    dlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
dlg->setWindowTitle(tr("Print Document"));
if (dlg->exec() == QDialog::Accepted)
    editor->print(&printer);
delete dlg;
#endif
}

void MainWindow::filePrintPreview()
{
#if QT_CONFIG(printpreviewdialog)
QPrinter printer(QPrinter::HighResolution);
QPrintPreviewDialog preview(&printer, this);
connect(&preview, &QPrintPreviewDialog::paintRequested, this, &MainWindow::printPreview);
preview.exec();
#endif
}

void MainWindow::printPreview(QPrinter *printer)
{
#ifdef QT_NO_PRINTER
Q_UNUSED(printer);
#else
editor->print(printer);
#endif
}

void MainWindow::filePrintPdf()
{
#ifndef QT_NO_PRINTER
QFileDialog fileDialog(this, tr("Export PDF"));
fileDialog.setAcceptMode(QFileDialog::AcceptSave);
fileDialog.setMimeTypeFilters(QStringList("application/pdf"));
fileDialog.setDefaultSuffix("pdf");
if (fileDialog.exec() != QDialog::Accepted)
    return;
QString fileName = fileDialog.selectedFiles().first();
QPrinter printer(QPrinter::HighResolution);
printer.setOutputFormat(QPrinter::PdfFormat);
printer.setOutputFileName(fileName);
editor->document()->print(&printer);
statusBar()->showMessage(tr("Exported \"%1\"")
                         .arg(QDir::toNativeSeparators(fileName)));
#endif
}

void MainWindow::textBold()
{
QTextCharFormat fmt;
fmt.setFontWeight(actionTextBold->isChecked() ? QFont::Bold : QFont::Normal);
mergeFormatOnWordOrSelection(fmt);
}

void MainWindow::textUnderline()
{
QTextCharFormat fmt;
fmt.setFontUnderline(actionTextUnderline->isChecked());
mergeFormatOnWordOrSelection(fmt);
}

void MainWindow::textItalic()
{
QTextCharFormat fmt;
fmt.setFontItalic(actionTextItalic->isChecked());
mergeFormatOnWordOrSelection(fmt);
}

void MainWindow::textFamily(const QString &f)
{
QTextCharFormat fmt;
fmt.setFontFamily(f);
mergeFormatOnWordOrSelection(fmt);
}

void MainWindow::textSize(const QString &p)
{
qreal pointSize = p.toFloat();
if (p.toFloat() > 0) {
    QTextCharFormat fmt;
    fmt.setFontPointSize(pointSize);
    mergeFormatOnWordOrSelection(fmt);
}
}

void MainWindow::textStyle(int styleIndex)
{
QTextCursor cursor = editor->textCursor();
QTextListFormat::Style style = QTextListFormat::ListStyleUndefined;

switch (styleIndex) {
case 1:
    style = QTextListFormat::ListDisc;
    break;
case 2:
    style = QTextListFormat::ListCircle;
    break;
case 3:
    style = QTextListFormat::ListSquare;
    break;
case 4:
    style = QTextListFormat::ListDecimal;
    break;
case 5:
    style = QTextListFormat::ListLowerAlpha;
    break;
case 6:
    style = QTextListFormat::ListUpperAlpha;
    break;
case 7:
    style = QTextListFormat::ListLowerRoman;
    break;
case 8:
    style = QTextListFormat::ListUpperRoman;
    break;
default:
    break;
}

cursor.beginEditBlock();

QTextBlockFormat blockFmt = cursor.blockFormat();

if (style == QTextListFormat::ListStyleUndefined) {
    blockFmt.setObjectIndex(-1);
    int headingLevel = styleIndex >= 9 ? styleIndex - 9 + 1 : 0; // H1 to H6, or Standard
    //blockFmt.setHeadingLevel(headingLevel);
    cursor.setBlockFormat(blockFmt);

    int sizeAdjustment = headingLevel ? 4 - headingLevel : 0; // H1 to H6: +3 to -2
    QTextCharFormat fmt;
    fmt.setFontWeight(headingLevel ? QFont::Bold : QFont::Normal);
    fmt.setProperty(QTextFormat::FontSizeAdjustment, sizeAdjustment);
    cursor.select(QTextCursor::LineUnderCursor);
    cursor.mergeCharFormat(fmt);
    editor->mergeCurrentCharFormat(fmt);
} else {
    QTextListFormat listFmt;
    if (cursor.currentList()) {
        listFmt = cursor.currentList()->format();
    } else {
        listFmt.setIndent(blockFmt.indent() + 1);
        blockFmt.setIndent(0);
        cursor.setBlockFormat(blockFmt);
    }
    listFmt.setStyle(style);
    cursor.createList(listFmt);
}

cursor.endEditBlock();
}

void MainWindow::textColor()
{
QColor col = QColorDialog::getColor(editor->textColor(), this);
if (!col.isValid())
    return;
QTextCharFormat fmt;
fmt.setForeground(col);
mergeFormatOnWordOrSelection(fmt);
colorChanged(col);
}

void MainWindow::textAlign(QAction *a)
{
if (a == actionAlignLeft)
    editor->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
else if (a == actionAlignCenter)
    editor->setAlignment(Qt::AlignHCenter);
else if (a == actionAlignRight)
    editor->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
else if (a == actionAlignJustify)
    editor->setAlignment(Qt::AlignJustify);
}

void MainWindow::currentCharFormatChanged(const QTextCharFormat &format)
{
fontChanged(format.font());
colorChanged(format.foreground().color());
}

void MainWindow::cursorPositionChanged()
{
alignmentChanged(editor->alignment());
QTextList *list = editor->textCursor().currentList();
if (list) {
    switch (list->format().style()) {
    case QTextListFormat::ListDisc:
        comboStyle->setCurrentIndex(1);
        break;
    case QTextListFormat::ListCircle:
        comboStyle->setCurrentIndex(2);
        break;
    case QTextListFormat::ListSquare:
        comboStyle->setCurrentIndex(3);
        break;
    case QTextListFormat::ListDecimal:
        comboStyle->setCurrentIndex(4);
        break;
    case QTextListFormat::ListLowerAlpha:
        comboStyle->setCurrentIndex(5);
        break;
    case QTextListFormat::ListUpperAlpha:
        comboStyle->setCurrentIndex(6);
        break;
    case QTextListFormat::ListLowerRoman:
        comboStyle->setCurrentIndex(7);
        break;
    case QTextListFormat::ListUpperRoman:
        comboStyle->setCurrentIndex(8);
        break;
    default:
        comboStyle->setCurrentIndex(-1);
        break;
        }
    }

}

/*void MainWindow::clipboardDataChanged()
{
#ifndef QT_NO_CLIPBOARD
if (const QMimeData *md = QMainWindow::clipboard()->mimeData())
    actionPaste->setEnabled(md->hasText());
#endif
}*/

void MainWindow::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
QTextCursor cursor = editor->textCursor();
if (!cursor.hasSelection())
    cursor.select(QTextCursor::WordUnderCursor);
cursor.mergeCharFormat(format);
editor->mergeCurrentCharFormat(format);
}

void MainWindow::fontChanged(const QFont &f)
{
comboFont->setCurrentIndex(comboFont->findText(QFontInfo(f).family()));
comboSize->setCurrentIndex(comboSize->findText(QString::number(f.pointSize())));
actionTextBold->setChecked(f.bold());
actionTextItalic->setChecked(f.italic());
actionTextUnderline->setChecked(f.underline());
}

void MainWindow::colorChanged(const QColor &c)
{
QPixmap pix(16, 16);
pix.fill(c);
actionTextColor->setIcon(pix);
}

void MainWindow::alignmentChanged(Qt::Alignment a)
{
if (a & Qt::AlignLeft)
    actionAlignLeft->setChecked(true);
else if (a & Qt::AlignHCenter)
    actionAlignCenter->setChecked(true);
else if (a & Qt::AlignRight)
    actionAlignRight->setChecked(true);
else if (a & Qt::AlignJustify)
    actionAlignJustify->setChecked(true);
}
