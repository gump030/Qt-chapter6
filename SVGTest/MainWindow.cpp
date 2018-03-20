#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowTitle(tr("SVG Viewer"));
	setWindowIcon(QIcon(QStringLiteral("./image/favicon.ico")));
	resize(800, 600);
	createMenu();

	svgWindow = new SvgWindow;
	setCentralWidget(svgWindow);
}


void MainWindow::createMenu()
{
	QMenu *fileMenu = menuBar()->addMenu(tr("�ļ�"));

	QAction *openAct = new QAction(tr("��"), this);
	connect(openAct, SIGNAL(triggered()), this, SLOT(slotOpenFile()));
	fileMenu->addAction(openAct);
}

void MainWindow::slotOpenFile()
{
	QString name = QFileDialog::getOpenFileName(this, "��", "/", "svg files(*.svg)");
	svgWindow->setFile(name);
}
